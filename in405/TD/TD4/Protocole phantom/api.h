#ifndef _H_API_
#define _H_API_

#include "internals.h"

/**
 * Capture a tree hierarchy in a phantom data structure
 *
 * It will be the caller responsability to free \a phantom.
 *
 * \param[in]       path        Tree path
 * \param[in]       phantom     'Phantom' tree data structure
 * \return                      0 on success,
 *                              1 on failure
 */
int capture_tree(const char *path, struct file **phantom);

/**
 * Create a 'phantom' tree following metadata previously stored
 *
 * \a Phantom data structure will be freed during the process.
 *
 * \param[in]       path        'Phantom' tree path
 * \param[in]       phantom     'Phantom' tree data structure
 * \return                      0 on success,
 *                              1 on failure
 */
int create_phantom(const char *path, struct file *phantom);

#endif
