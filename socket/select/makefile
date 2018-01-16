.PHONY:all
all:select_service select_client

select_client:select_client.c
	gcc $^ -o $@
select_service:select_service.c
	gcc $^ -o $@
.PHONY:clean
clean:
	rm -f select_service
