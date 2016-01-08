#ifndef http_h
#define http_h

typedef enum
{
	http_action_normal,
	http_action_error
} http_action_t;

typedef struct
{
	unsigned int length;
	unsigned int size;
	char *string;
} http_buffer_t;

typedef struct
{
	const char *location;
	http_action_t (*handler)(const char *location, http_buffer_t *reply);
} http_handler_t;

http_action_t http_process_request(http_buffer_t request, http_buffer_t *reply);

#endif
