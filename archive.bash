#!/bin/bash
DEST="testbackup"
TIME=`date +%b-%d-%y-%k-%M`
clear
echo 
ls -d */
echo "please enter in the desired folder to be backed up"
echo
read FILE

if [  -d "$FILE" ]
then
	echo "$FILE found"
	echo 
	echo "Backing up folder now your majesty"
	 tar cvpfz $DEST/backup-$TIME.tgz $FILE
	echo
	echo
	echo "$FILE has been backed up to the backup folder"
	echo
	cd $DEST
	ls -lh 
else
	echo "$FILE not found"
fi
