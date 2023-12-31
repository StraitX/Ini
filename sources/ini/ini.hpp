#pragma once


#include <INIReader.h>
#include <core/string.hpp>
#include <core/span.hpp>
#include <core/validable.hpp>

class Ini: private INIReader, public Validable{
    using Super = INIReader;
public:
    Ini(StringView buffer);

    Ini(const String& buffer);

    Ini(const char* buffer, size_t buffer_size);

    Ini(ConstSpan<char> buffer);

    Ini(ConstSpan<byte> buffer);

    int ParseError() const;

    bool IsValid()const override{
        return ParseError() == 0;
    }

    String Get(const String& section, const String& name, const String& default_value = String::Empty) const;

    String GetString(const String& section, const String& name, const String& default_value = String::Empty) const;

    s32 GetInt(const String& section, const String& name, s32 default_value) const;

    s64 GetInt64(const String& section, const String& name, s64 default_value) const;

    u32 GetUint(const String& section, const String& name, u32 default_value) const;

    u64 GetUint64(const String& section, const String& name, u64 default_value) const;

    double GetDouble(const String& section, const String& name, double default_value) const;

    float GetFloat(const String& section, const String& name, float default_value) const;

    bool GetBool(const String& section, const String& name, bool default_value) const;

    bool Has(const String& section) const;

    bool Has(const String& section, const String& name) const;
};