CREATE TABLE User(
	login VARCHAR(20),
	pwd VARCHAR(20) NOT NULL,
	PRIMARY KEY (login));

CREATE TABLE Federal(
	fid VARCHAR(20),
	PRIMARY KEY (fid),
	FOREIGN KEY (fid) REFERENCES User (login)
		ON DELETE CASCADE
		ON UPDATE CASCADE);

CREATE TABLE Regional(
	rid VARCHAR(20),
	state ENUM('AL', 'AK', 'AS', 'AZ', 'AR', 'CA', 'CO', 'CT',
		   'DE', 'DC', 'FM', 'FL', 'GA', 'GU', 'HI', 'ID',
		   'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'MH',
		   'MD', 'MA', 'MI', 'MN', 'MS', 'MO', 'MT', 'NE',
		   'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND', 'MP',
		   'OH', 'OK', 'OR', 'PW', 'PA', 'PR', 'RI', 'SC',
		   'SD', 'TN', 'TX', 'UT', 'VT', 'VI', 'VA', 'WA',
		   'WV', 'WI', 'WY') NOT NULL,
	region TINYINT UNSIGNED NOT NULL,
	fcontact VARCHAR(20) NOT NULL,
	PRIMARY KEY (rid),
	UNIQUE (state,region),
	FOREIGN KEY (rid) REFERENCES User (login)
		ON UPDATE CASCADE
		ON DELETE CASCADE,
	FOREIGN KEY (fcontact) REFERENCES Federal (fid)
		ON UPDATE CASCADE);

CREATE TABLE Messages(
	mid MEDIUMINT UNSIGNED AUTO_INCREMENT,
	sender VARCHAR(20) NOT NULL,
	receiver VARCHAR(20) NOT NULL,
	mtext TEXT NOT NULL,
	time TIMESTAMP NOT NULL,
	PRIMARY KEY (mid),
	FOREIGN KEY (sender) REFERENCES User (login)
		ON UPDATE CASCADE
		ON DELETE NO ACTION,
	FOREIGN KEY (receiver) REFERENCES User (login)
		ON UPDATE CASCADE
		ON DELETE NO ACTION);

CREATE TABLE Receiver(
	email VARCHAR(35),
	region TINYINT UNSIGNED NOT NULL,
	state ENUM('AL', 'AK', 'AS', 'AZ', 'AR', 'CA', 'CO', 'CT',
		   'DE', 'DC', 'FM', 'FL', 'GA', 'GU', 'HI', 'ID',
		   'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'MH',
		   'MD', 'MA', 'MI', 'MN', 'MS', 'MO', 'MT', 'NE',
		   'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND', 'MP',
		   'OH', 'OK', 'OR', 'PW', 'PA', 'PR', 'RI', 'SC',
		   'SD', 'TN', 'TX', 'UT', 'VT', 'VI', 'VA', 'WA',
		   'WV', 'WI', 'WY') NOT NULL,
	type ENUM('news', 'source', 'state') NOT NULL,
	info TEXT,
	PRIMARY KEY (email));

CREATE TABLE Supply(
	sid MEDIUMINT UNSIGNED AUTO_INCREMENT,
	name VARCHAR(50) NOT NULL UNIQUE,
	type ENUM('BldgSup', 'Food', 'Shelter', 'Clothing', 'Transport') NOT NULL,
	min MEDIUMINT NOT NULL,
	max MEDIUMINT NOT NULL,
	unit VARCHAR(50) NOT NULL,
	PRIMARY KEY (sid));

CREATE TABLE Has(
	source_id VARCHAR(35),
	supply_id MEDIUMINT UNSIGNED,
	PRIMARY KEY (source_id,supply_id),
	FOREIGN KEY (source_id) REFERENCES Receiver (email)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	FOREIGN KEY (supply_id) REFERENCES Supply (sid)
		ON DELETE CASCADE
		ON UPDATE CASCADE);

CREATE TABLE Requests(
	request_id MEDIUMINT UNSIGNED,
	regional_id VARCHAR(20) NOT NULL,
	federal_id VARCHAR(20) NOT NULL,
	supply_id MEDIUMINT UNSIGNED NOT NULL,
	quantity  MEDIUMINT UNSIGNED NOT NULL,
	address TEXT NOT NULL,
	time TIMESTAMP NOT NULL,
	regional_flag BOOLEAN DEFAULT FALSE NOT NULL,
	federal_flag TINYINT DEFAULT 0 NOT NULL,
	PRIMARY KEY (request_id,supply_id),
	FOREIGN KEY (regional_id) REFERENCES Regional (rid)
		ON UPDATE CASCADE
		ON DELETE NO ACTION,
	FOREIGN KEY (federal_id) REFERENCES Federal (fid)
		ON UPDATE CASCADE
		ON DELETE NO ACTION,
	FOREIGN KEY (supply_id) REFERENCES Supply (sid)
		ON UPDATE CASCADE
		ON DELETE CASCADE);
