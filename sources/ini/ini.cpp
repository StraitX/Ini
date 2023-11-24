#include "ini.hpp"

Ini::Ini(StringView filename):
	Super(std::string(filename.Data(), filename.Size()))
{}

Ini::Ini(const String& filename):
	Super(filename)
{}

Ini::Ini(const char* buffer, size_t buffer_size):
	Super(buffer, buffer_size)
{}

Ini::Ini(ConstSpan<char> buffer):
	Ini(buffer.Pointer(), buffer.Size())
{}

Ini::Ini(ConstSpan<byte> buffer):
	Ini((const char*)buffer.Pointer(), buffer.Size())
{}

int Ini::ParseError() const {
	return Super::ParseError();
}

String Ini::Get(const String& section, const String& name, const String& default_value) const {
	return String::FromStdString(Super::Get(section, name, default_value));
}

String Ini::GetString(const String& section, const String& name, const String& default_value) const {
	return Get(section, name, default_value);
}

s32 Ini::GetInt(const String& section, const String& name, s32 default_value) const {
	return Super::GetInteger(section, name, default_value);
}

s64 Ini::GetInt64(const String& section, const String& name, s64 default_value) const {
	return Super::GetInteger64(section, name, default_value);
}

u32 Ini::GetUint(const String& section, const String& name, u32 default_value) const {
	return Super::GetUnsigned(section, name, default_value);
}

u64 Ini::GetUint64(const String& section, const String& name, u64 default_value) const {
	return Super::GetUnsigned64(section, name, default_value);
}

double Ini::GetDouble(const String& section, const String& name, double default_value) const {
	return Super::GetReal(section, name, default_value);
}

float Ini::GetFloat(const String& section, const String& name, float default_value) const {
	return (float)GetDouble(section, name, (float)default_value);
}

bool Ini::GetBool(const String& section, const String& name, bool default_value) const {
	return Super::GetBoolean(section, name, default_value);
}

bool Ini::Has(const String& section) const {
	return Super::HasSection(section);
}

bool Ini::Has(const String& section, const String& name) const {
	return Super::HasValue(section, name);
}
