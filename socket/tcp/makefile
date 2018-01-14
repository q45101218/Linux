.PHONY:all
all:tcp_service tcp_client

tcp_client:tcp_client.c
	gcc $^ -o $@
tcp_service:tcp_service.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm -f tcp_client tcp_service
