.PHONY:all
all:service client

service:service.c common.c
	gcc $^ -o $@
client:client.c common.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm -f service
