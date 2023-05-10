create(){
touch studDetails.txt
if [ "studDetails.txt" ]
then echo "db created"
else echo "db not created"
fi
}
insert(){
echo "Enter name "
read name
echo "Enter roll no"
read rollno
echo "$name $rollno">>studDetails.txt
echo "Inserted"
}
display(){
echo "Display record"
cat studDetails.txt
}
search(){
echo "Enter roll no to search"
read rollno
grep "$rollno" studDetails.txt
}
delete(){
  echo "Enter roll no to delete"
  read rollno
  grep -v "$rollno" studDetails.txt>temp.txt
  mv temp.txt studDetails.txt
  echo "deleted"
}
modify(){
  echo "Enter roll no to modify"
  read rollno
  grep -v "$rollno" studDetails.txt>temp.txt
  echo "Enter name "
  read name
  echo "$name $rollno">>temp.txt
    mv temp.txt studDetails.txt
    echo "updated"
}
ch=0;
while [ $ch -lt 10 ]
do
echo "1.create"
echo "2.insert"
echo "3.display"
echo "4.search"
echo "5.modify"
echo "6.delete"
echo "Enter your choice: "
read ch
case $ch in

1)create;;
2)insert;;
3)display;;
4)search;;
5)modify;;
6)delete;;
*)echo "Enter valid choice";;

esac

done
