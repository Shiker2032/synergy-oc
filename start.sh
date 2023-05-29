mkdir attachments
cd ./attachments
for ((i=1; i <= 20; i++))
do
curl https://i.pravatar.cc/800/400 -L > photo$i.png
done