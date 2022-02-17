#!/usr/bin/perl

#USAGE perl myparser.perl cfile mainsub (treelevel)

#this perl script recursively descends down call trees in fortran programs


$ffile = @ARGV[0];
$mainsub = @ARGV[1];
$print = "";		#Holds tree depth information to be printed.			

if(@ARGV[2]) {					# 					
	for($i = @ARGV[2]; $i > 0; $i--) {	# Formatting the tree to be printed
		$print = $print . "    ";	# on screen if we're not at the 
	}					# root level.
	$print = $print . "\\---";		#
}						#


chomp($mainsub);        # removing the newline character

@maintext=returnsubtext($mainsub);
	
print "$print$mainsub\n";	#Prints the current routine preceeded by its level in the tree.
@ARGV[2] += 1;			#Increase tree depth.

    for($index=0;$index <=$#maintext;$index++){
	$text=@maintext[$index];
	    if($text =~ /.*\s*(CALL)\s+([A-Z0-9]+)\s*\(.*/){ 
		    system(sprintf("$0 $ffile $2 @ARGV[2]"));	#Recursively calls itself with each subroutine found.
		}
	}
	
sub returnsubtext
{
    my $target = pop(@_);

	$target="\U$target";

    my $index = 0;
    
    my $INTHEMAIN=0;

    @_=();

open(IN, "$ffile") || die "Could not open FORTRAN file $ffile\n";   


     while(<IN>){
	 
	 $text = "\U$_";

	if($INTHEMAIN){
	    
	    if($text =~ /\s*SUBROUTINE\s*.*\n/){
		 $INTHEMAIN=0; #we have fallen out of the subroutine		
	    }
	    else {
		unless($text=~/IMPLICIT/){
		    @_[$index++]=$text;
		}
	       
	    }
	}
	 if($text =~ /\s*SUBROUTINE\s+$target\s*\(.*/){
       
	     $INTHEMAIN = 1;
	     @_[$index++]=$text;
           
	 }

     }
    
    
    close(IN);
    
    return @_;
}
