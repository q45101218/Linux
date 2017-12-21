.PHONY:all
all:service client

service:service.c commom.c
	gcc $^ -o $@
client:client.c commom.c
	gcc $^ -o $@


.PHONY:clean
clean:
	rm -f service client | ipcrm -a


