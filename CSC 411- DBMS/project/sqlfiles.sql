//*****TABLE CREATION*********//

CREATE TABLE Customer ( phone 		CHAR(10),
			name		CHAR(25),
			late		NUMBER(2),
			address		CHAR(60),
			cid		CHAR(5) PRIMARY KEY);

CREATE TABLE Movie (	year 		CHAR(4),
			title   	CHAR(40),
			actor		CHAR(25),
			director  	CHAR(25),
			mid		CHAR(5) PRIMARY KEY);

CREATE TABLE Returns ( 	due_date 	DATE NOT NULL,
			mid	 	CHAR(5) 
					CONSTRAINT returns_mid_fk REFERENCES Movie(mid),
			cid		CHAR(5)
					CONSTRAINT returns_cid_fk REFERENCES Customer(cid),
			return_date	DATE NOT NULL,	
			PRIMARY KEY(cid,mid,due_date));

CREATE TABLE Reserve (	exp_date 	DATE NOT NULL,
			mid		CHAR(5) 
					CONSTRAINT reserve_mid_fk REFERENCES Movie(mid),
			cid		CHAR(5) 
					CONSTRAINT reserve_cid_fk REFERENCES Customer(cid),
			PRIMARY KEY(cid,mid));

CREATE TABLE Check_Out ( cdate 		DATE NOT NULL,
			 mid		CHAR(5) UNIQUE 
					CONSTRAINT co_mid_fk REFERENCES Movie(mid),
			 cid		CHAR(5) 
					CONSTRAINT co_cid_fk REFERENCES Customer(cid),
			 PRIMARY KEY(cid,mid));

//*****POPULATING INITIAL CUSTOMER TALBE*******//

INSERT INTO customer
	VALUES(1234567890,'Jason Voorhees',0,'100 Camp Crystal Lake', 75318);

INSERT INTO customer
	VALUES(1234561111,'Eddie Walker',0,'247 Jackson Cannery Rd', 89742);

INSERT INTO customer
	VALUES(1234562222,'Rick James',0,'780 Hollywood Place', 52137);

INSERT INTO customer
	VALUES(1234563333,'Kurt Wagner',0,'546 Xaviers School Rd', 24768);

INSERT INTO customer
	VALUES(1234564444,'Billy Madison',0,'6589 Penguin Cove', 72157);

INSERT INTO customer
	VALUES(1234565555,'Bob Smith',0,'100 Generic Road', 36579);

INSERT INTO customer
	VALUES(1234566666,'Fred Jones',0,'424 Jackson Cannery Rd', 12348);

INSERT INTO customer
	VALUES(1234568777,'Mary White',0,'777 Fake Lane', 53347);

INSERT INTO customer
	VALUES(1234567354,'Kevin Smith',0,'114 Mooby Burger Way', 98853);

INSERT INTO customer
	VALUES(1234561589,'Joe Everyman',0,'789 Generic Road', 53566);

INSERT INTO customer
	VALUES(1234562542,'Raffi',0,'123 Bananaphone Way', 24188);

INSERT INTO customer
	VALUES(1234545455,'Billy Idol',0,'7885 Rebel Yell Place', 89981);

INSERT INTO customer
	VALUES(7882113547,'Uncle Moneybags',0,'178 Boardwalk', 36574);

INSERT INTO customer
	VALUES(1234564545,'Joe Blow',0,'789 Fake Lane', 78871);

INSERT INTO customer
	VALUES(1578521136,'Steve Dave',0,'561 Frat Row', 98422);

INSERT INTO customer
	VALUES(1234567890,'The Scorpians',0,'789 Like A Hurricane Parkway', 78541);

INSERT INTO customer
	VALUES(1234564524,'Hrothgar the Mighty',0,'785 Magestic Castle Road', 87511);

INSERT INTO customer
	VALUES(1234592929,'Betty Brown',0,'456 Generic Road', 82163);

INSERT INTO customer
	VALUES(1234545779,'Sven Glokenspiel',0,'555 Iceland', 64787);

INSERT INTO customer
	VALUES(1234567890,'Joe America',0,'789 Generic Road', 15788);

//*******POPULATING INITIAL MOVIE TABLE*********//

INSERT INTO movie
	VALUES ('1996','Independence Day','Will Smith','Roland Emmerich','56780');

INSERT INTO movie
	VALUES ('1996','Independence Day','Will Smith','Roland Emmerich','56781');

INSERT INTO movie
	VALUES ('2001','Amelie','Audry Tautou','Jean-Pierre Jeunet','78930');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65400');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65401');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65402');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65403');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65404');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65405');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65406');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65407');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65408');

INSERT INTO movie
	VALUES ('2005','Batman Begins','Christian Bale','Christopher Nolan','65409');

INSERT INTO movie
	VALUES ('1987','Full Metal Jacket','Matthew Modine','Stanley Kubrick','78120');

INSERT INTO movie
	VALUES ('1980','The Shining','Jack Nicholson','Stanley Kubrick','64580');

INSERT INTO movie
	VALUES ('1971','A Clockwork Orange','Malcolm McDowell','Stanley Kubrick','78910');

INSERT INTO movie
	VALUES ('1964', 'Dr. Strangelove','Peter Sellers','Stanley Kubrick','98540');

INSERT INTO movie 
	VALUES ('2000', 'American Psycho','Christian Bale','Mary Harron','46970');

INSERT INTO movie
	VALUES ('2002','Equilibrium','Christian Bale','Kurt Wimmer','48940');

INSERT INTO movie
	VALUES ('1927','Metropolis','Alfred Abel','Fritz land','78900');

INSERT INTO movie
	VALUES ('1978','Dawn of the Dead','David Emge','George Romero','79940');

INSERT INTO movie
	VALUES ('2004','Dawn of the Dead','Ving Rhames','Zack Snyder','79810');

INSERT INTO movie
	VALUES ('2004','Dawn of the Dead','Ving Rhames','Zack Snyder','79811');

INSERT INTO movie
	VALUES ('2004','Dawn of the Dead','Ving Rhames','Zack Snyder','79812');

INSERT INTO movie
	VALUES ('1968','Night of the Living Dead','Duane Jones','George Romero','68780');

INSERT INTO movie
	VALUES ('1985','Day of the Dead','Lori Cardille','George Romero','45610');

INSERT INTO movie
	VALUES ('2004','Land of the Dead','Simon Baker','George Romero','00220');

INSERT INTO movie
	VALUES ('2004','Land of the Dead','Simon Baker','George Romero','00221');

INSERT INTO movie
	VALUES ('2004','Land of the Dead','Simon Baker','George Romero','00222');

INSERT INTO movie
	VALUES ('2004','Land of the Dead','Simon Baker','George Romero','00223');

INSERT INTO movie
	VALUES ('2004','Land of the Dead','Simon Baker','George Romero','00224');

INSERT INTO movie
	VALUES ('2004','Land of the Dead','Simon Baker','George Romero','00225');

INSERT INTO movie
	VALUES ('1999','Office Space','Ron Livingston','Mike Judge','68870');

INSERT INTO movie
	VALUES ('1993','Ninja Scroll','Richard Barnes','Yoshiaki Kawajiri','87840');

INSERT INTO movie
	VALUES ('1995','Apollo 13','Tom Hanks','Ron Howard','78960');

INSERT INTO movie
	VALUES ('1989','Bill and Teds Excellent Adventure','Keanu Reeves','Stephen Herek','78940');

INSERT INTO movie
	VALUES ('1991','Bill and Teds Bogus Journey','Keanu Reeves','Peter Hewitt','56610')

//******POPULATING INITIAL RETURNS TABLE********//

INSERT INTO returns
	VALUES ('30-oct-05','79940','75318','30-oct-05');

INSERT INTO returns
	VALUES ('30-oct-05','79811','75318','30-oct-05');

INSERT INTO returns
	VALUES ('30-oct-05','45610','75318','30-oct-05');

INSERT INTO returns
	VALUES ('30-oct-05','00223','75318','30-oct-05');

INSERT INTO returns
	VALUES ('25-sep-05','56781','89742','25-oct-05');

INSERT INTO returns
	VALUES ('1-oct-05','64580','89742','1-sep-05');

INSERT INTO returns
	VALUES ('25-nov-05','65404','52137','25-nov-05');

INSERT INTO returns
	VALUES ('1-nov-05','87840','52137','1-nov-05');

INSERT INTO returns
	VALUES ('2-nov-05','78930','52137','2-nov-05');

INSERT INTO returns
	VALUES ('3-nov-05','46970','52137','3-nov-05');

INSERT INTO returns
	VALUES ('8-nov-05','46970','24768','8-nov-05');

