
#!/bin/sh

rm `find ./  -exec file {} \; | grep "ELF" | cut -d ':' -f 1` ;

