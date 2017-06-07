#Append YEAR.MONTH.DAY and timestamp to log file
#This is the directory where backup logs are kept
working_dir=/home/caoqi/Desktop
alarmrate=500
# The max size file can reach
file_max_size=5
# This is the directory where fresh logs are originally written
log_ram_dir=/home/caoqi/Downloads

SLEEP_TIME=5
filenameConvert(){
    timestamp=$(date +%Y%m%d%H%M%S)
    timestamp=`echo $timestamp`
    RETVAL=$1.$timestamp
    echo $RETVAL
}
#search dir to fetch the oldest log
searchdir(){
    oldestlog=`ls -rt|head -n 1|awk '{print $1}'`
}

clear_old_log_under_working_dir(){
    cd $working_dir
    while true;
        do
        logsize=`du -ms $working_dir|awk '{print $1}'`
            if [ ${logsize} -gt ${alarmrate} ];
                then
            searchdir
                rm -rf $oldestlog
            else
                break;
            fi
        done
}


backuplog_process(){
    cd $log_ram_dir
    for i in * ;do
        file_size=`du -m $i | awk '{print $1}'`
        case $i in
            *)
            if [ ! -d ${working_dir} ]; then
                mkdir -p $working_dir
            fi
            if [ ${file_size} > ${file_max_size} ] ; then
                filenameConvert $i
                cp $log_ram_dir/$i $working_dir/$RETVAL
                echo "" > $log_ram_dir/$i
                clear_old_log_under_working_dir
            fi
            ;;
            *)
            if [ ${file_size} > ${file_max_size} ] ; then
                echo "" > $log_ram_dir/$i
            fi
        esac
        done
}

#while true ;do
backuplog_process
#    sleep $SLEEPTIME
#done