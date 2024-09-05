# This is the default standard .cshrc provided to csh users.
# They are expected to edit it to meet their own needs.


if ( -o /bin/su ) then
        unset path
else
        set path = ( $HOME/bin $HOME/bin/sgi )
endif 

set path=( $path /usr/bsd /usr/bin /usr/sbin /sbin /usr/bin/X11 \
          /usr/local/bin /usr/local/X11 /etc /usr/etc . )

#
# load in machine-specific settings
#

if ( -r /usr/site/etc/system.cshrc ) then
        source /usr/site/etc/system.cshrc
endif

if ($?prompt) then
        if ( -o /bin/su ) then
                set prompt = "`hostname | sed 's/\..*//'`[\!]# "
        else
                set prompt = "`hostname | sed 's/\..*//'`[\!]% "
        endif

        stty intr "^C" kill "^U" echoe
        setenv EDITOR /usr/local/bin/emacs
        umask 077
        set history = 100
        set filec
        alias h  history
        alias help apropos
        alias rm "rm -i"
        alias ls 'ls -C'
endif

source /afs/umbc.edu/software/cadence/etc/setup_2008/cshrc.cadence
