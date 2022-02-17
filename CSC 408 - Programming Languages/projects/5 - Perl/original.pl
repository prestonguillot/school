#!/usr/bin/perl

#USAGE perl myparser.perl cfile mainsub

#this perl script recursively descends down call trees in fortran programs


$ffile = @ARGV[0];
$mainsub=@ARGV[1];

chomp($mainsub);        # removing the newline character




@maintext=returnsubtext($mainsub);
	

print "parsing $ffile\n";
print "$mainsub\n";

    for($index=0;$index <=$#maintext;$index++){
	$text=@maintext[$index];
	#print $text;
	    if($text =~ /.*\s*(CALL)\s+([A-Z0-9]+)\s*\(.*/){ 
		print "         ->$2\n";
		}
	}
print "\nfinished\n";

sub returnsubtext
{
    my $target = pop(@_);

	$target="\U$target";

    my $index = 0;

    print "getting $target\n";
    
    my $INTHEMAIN=0;

    @_=();

open(IN, "$ffile") || die "Could not open FORTRAN file $mainsub\n";   


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

   #print @_;
    return @_;
}
