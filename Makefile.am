SUBDIRS= src tests doc

#DOC_FILES= \
#    $(top_srcdir)/doc/attrtype.htm \
#    $(NULL)


EXTRA_DIST=autogen.sh autoclean.sh AUTHORS README.md ChangeLog \
    $(DOC_FILES) \
    $(NULL)

ChangeLog: .git
	if test -d $(srcdir)/.git; then                         \
	  if test -f $(srcdir)/.last-cl-gen; then               \
        git log --no-merges --date-order --date=short       \
          $$(cat $(srcdir)/.last-cl-gen)..                  \
          | sed -e  '/^commit.*$$/d'                        \
          | awk '/^Author/ {sub(/\\$$/,""); getline t; print $$0 t; next}; 1' \
          | sed -e 's/^Author: //g'                         \
          | sed -e 's/>Date:   \([0-9]*-[0-9]*-[0-9]*\)/>\t\1/g' \
          | sed -e 's/^\(.*\) \(\)\t\(.*\)/\3    \1    \2/g' \
          > ChangeLog.tmp;                                  \
      else                                                  \
        git log --no-merges --date-order --date=short       \
          | sed -e  '/^commit.*$$/d'                        \
          | awk '/^Author/ {sub(/\\$$/,""); getline t; print $$0 t; next}; 1' \
          | sed -e 's/^Author: //g'                         \
          | sed -e 's/>Date:   \([0-9]*-[0-9]*-[0-9]*\)/>\t\1/g' \
          | sed -e 's/^\(.*\) \(\)\t\(.*\)/\3    \1    \2/g' \
          > ChangeLog.tmp;                                  \
      fi;                                                   \
	  touch ChangeLog                                       \
	    && git rev-list -n 1 HEAD >.last-cl-gen.tmp         \
        && (echo; cat $(srcdir)/ChangeLog) >>ChangeLog.tmp  \
        && mv -f ChangeLog.tmp $(srcdir)/ChangeLog          \
        && mv -f .last-cl-gen.tmp $(srcdir)/.last-cl-gen    \
        && rm -f ChangeLog.tmp;                             \
    fi
	if test -d $(srcdir)/.hg; then                          \
        hg log --template changelog > ChangeLog;            \
        touch $(srcdir)/.last-cl-gen;                       \
    fi

