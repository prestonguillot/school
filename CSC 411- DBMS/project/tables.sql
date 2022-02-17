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
