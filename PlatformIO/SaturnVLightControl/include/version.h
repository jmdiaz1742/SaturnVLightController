#ifndef VERSION_H
#define VERSION_H

#define VERSION_MAJOR (0)
#define VERSION_MINOR (2)
#define VERSION_PATCH (0)

typedef struct
{
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
} version_t;

static const version_t Version = {VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH};

#endif // VERSION_H