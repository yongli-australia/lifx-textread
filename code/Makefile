
all: tfread b_msg
install: install_list install_bins install_man i_msg



tfread: tfread.c tfread.h
	gcc -Wall -std=c99  -o tfread tfread.c



b_msg:
	@echo
	@echo "Binaries built."
	@echo "Now, \"make install\" as root."
	@echo


# As root, of course.

install_list:
	chmod 644 word.list
	cp word.list /usr/share/dict
	ln -s /usr/share/dict/word.list /usr/share/dict/word.lst
	@echo "word.list installed in /usr/share/dict and symlinked to word.lst."

install_bins:
	chmod 755 tfread
	cp tfread  /usr/local/bin



i_msg:
	@echo
	@echo "============================================================="
	@echo "The word list (word.list) is now in /usr/share/dict."
	@echo "The \"tfread" binaries are in /usr/local/bin."
	
	@echo "Installation complete."
	@echo "============================================================="
	@echo
