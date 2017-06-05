#! /bin/sh
# source user_login.sh then the function is read from the file.
function user_login ( )
{
    if who | grep $1 >/dev/null
    then
        echo "User $1 is on."
    else
        echo "User $1 is off."
    fi
}