#ifndef _H_INTERNALS_
#define _H_INTERNALS_

#include <limits.h>
#include <sys/types.h>

/** File type enumeration */
enum file_type {
    FT_REGULAR,         /**< Regular file */
    FT_DIRECTORY,       /**< Directory */
    FT_LINK,            /**< Symbolic link */
};

/** File data structure */
struct file {
    struct file *next;          /**< Next element */
    char name[NAME_MAX];        /**< File name */
    enum file_type type;        /**< File type */
    uid_t user_id;              /**< ID of the file owner */
    mode_t mode;                /**< File access */
    union {
        struct file *child;     /**< If \a type is FT_DIRECTORY,
                                 *   list of child entries */
        off_t size;             /**< If \a type is FT_REGULAR,
                                 *   file size */
        char target[NAME_MAX];  /**< If \a type is FT_LINK,
                                 *   link target name */
    } attribute;                /**< File attribute, depends on \a type */
};


void display_struct(struct file *parent);
/**
 * Fill a file data structure following the target metadata
 *
 * Only files which are regular, directory or link files should be captured.
 *
 * \param[in]       path        File path
 * \param[inout]    parent      Parent directory
 * \return                      0 on success,
 *                              1 on failure
 */
int capture_file(const char *path, struct file *parent);

/**
 * Browse a directory to capture its files
 *
 * If \a current is NULL, we need to allocate and initialize it.
 * It will be the caller responsability to free it.
 *
 * \param[in]       path        Directory path
 * \param[inout]    current     Directory data structure
 * \return                      0 on success,
 *                              1 on failure
 */
int browse_directory(const char *path, struct file **current);

/**
 * Create a 'phantom' regular file
 *
 * The contents of this file does not matter, but its size must match
 * the original.
 *
 * \param[in]       path        Directory path
 * \param[in]       regular     'Phantom' regular file
 * \return                      0 on success,
 *                              1 on failure
 */
int create_regular(const char *path, const struct file *regular);

/**
 * Create a 'phantom' directory
 *
 * \param[in]       path        Parent directory path
 * \param[in]       directory   'Phantom' directory
 * \return                      0 on success,
 *                              1 on failure
 */
int create_directory(const char *path, const struct file *directory);

/**
 * Create a 'phantom' link
 *
 * \param[in]       path        Directory path
 * \param[in]       link        'Phantom' link
 * \return                      0 on success,
 *                              1 on failure
 */
int create_link(const char *path, const struct file *link);

#endif
