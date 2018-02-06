.PHONY:all
all:service client

service:poll_service.c
	gcc $^ -o $@

client:poll_client.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm -f poll*

.PHONY:rm
rm:
	rm -f a.out

