---
title: Funções &lt;de cadeia de caracteres&gt;
ms.date: 11/04/2016
f1_keywords:
- string/std::getline
- string/std::stod
- string/std::stof
- string/std::stoi
- string/std::stol
- string/std::stold
- string/std::stoll
- string/std::stoul
- string/std::stoull
- string/std::swap
- string/std::to_string
- string/std::to_wstring
ms.assetid: 1a4ffd11-dce5-4cc6-a043-b95de034c7c4
helpviewer_keywords:
- std::getline [C++]
- std::stod [C++]
- std::stof [C++]
- std::stoi [C++]
- std::stol [C++]
- std::stold [C++]
- std::stoll [C++]
- std::stoul [C++]
- std::stoull [C++]
- std::swap [C++]
- std::to_string [C++]
- std::to_wstring [C++]
ms.openlocfilehash: 350a66481c7061322f08a768ec1628598f4af68e
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88843177"
---
# <a name="ltstringgt-functions"></a>Funções &lt;de cadeia de caracteres&gt;

[getline](#getline)\
[stod](#stod)\
[stof](#stof)\
[stoi](#stoi)\
[stol](#stol)\
[stold](#stold)\
[stoll](#stoll)\
[stoul](#stoul)\
[stoull](#stoull)\
[permuta](#swap)\
[to_string](#to_string)\
[to_wstring](#to_wstring)

## <a name="getline"></a><a name="getline"></a> getline

Extrai cadeias de caracteres do fluxo de entrada linha por linha.

```cpp
// (1) delimiter as parameter
template <class CharType, class Traits, class Allocator>
basic_istream<CharType, Traits>& getline(
    basic_istream<CharType, Traits>& in_stream,
    basic_string<CharType, Traits, Allocator>& str,
    CharType delimiter);

template <class CharType, class Traits, class Allocator>
basic_istream<CharType, Traits>& getline(
    basic_istream<CharType, Traits>&& in_stream,
    basic_string<CharType, Traits, Allocator>& str,
    const CharType delimiter);

// (2) default delimiter used
template <class CharType, class Traits, class Allocator>
basic_istream<CharType, Traits>& getline(
    basic_istream<CharType, Traits>& in_stream,
    basic_string<CharType, Traits, Allocator>& str);

template <class Allocator, class Traits, class Allocator>
basic_istream<Allocator, Traits>& getline(
    basic_istream<Allocator, Traits>&& in_stream,
    basic_string<Allocator, Traits, Allocator>& str);
```

### <a name="parameters"></a>parâmetros

*in_stream*\
O fluxo de entrada do qual uma cadeia de caracteres será extraída.

*Str*\
A cadeia de caracteres na qual são lidos os caracteres do fluxo de entrada.

*delimitador*\
O delimitador de linha.

### <a name="return-value"></a>Valor Retornado

O fluxo de entrada *in_stream*.

### <a name="remarks"></a>Comentários

O par de assinaturas de função marcado `(1)` extrai caracteres de *in_stream* até que o *delimitador* seja encontrado, armazenando-os em *Str*.

O par de assinaturas de função marcado `(2)` usa nova linha como o delimitador de linhas padrão e se comporta como `getline(in_stream, str, in_stream. widen('\n'))` .

A segunda função de cada par é equivalente à primeira para dar suporte a [referências de valor](../cpp/lvalues-and-rvalues-visual-cpp.md).

A extração é interrompida quando ocorre uma das seguintes situações:

- No final do arquivo, nesse caso, o sinalizador de estado interno de *in_stream* é definido como `ios_base::eofbit` .

- Depois que a função extrai um elemento que compara igual ao *delimitador*. O elemento não é colocado de volta ou acrescentado à sequência controlada.

- Depois que a função extrai `str.` elementos de [max_size](../standard-library/basic-string-class.md#max_size) . O sinalizador de estado interno de *in_stream* é definido como `ios_base::failbit` .

- Outro erro além daqueles listados anteriormente; o sinalizador de estado interno de *in_stream* é definido como `ios_base::badbit` .

Para obter informações sobre os sinalizadores de estado interno, consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate).

Se a função extrair nenhum elemento, o sinalizador de estado interno de *in_stream* será definido como `ios_base::failbit` . Em qualquer caso, o `getline` retorna *in_stream*.

Se uma exceção for lançada, *in_stream* e *Str* serão deixados em um estado válido.

### <a name="example"></a>Exemplo

O código a seguir demonstra `getline()` em dois modos: primeiro com o delimitador padrão (nova linha) e a segundo com um espaço em branco como delimitador. O caractere de final de arquivo (CTRL-Z no teclado) é usado para controlar a terminação de loops while. Esse valor define o sinalizador de estado interno de `cin` para `eofbit` , que deve ser limpo com [basic_ios:: Clear ()](../standard-library/basic-ios-class.md#clear) antes que o segundo loop while funcione corretamente.

```cpp
// compile with: /EHsc /W4
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<string> v1;
    cout << "Enter a sentence, press ENTER between sentences. (Ctrl-Z to stop): " << endl;
    // Loop until end-of-file (Ctrl-Z) is input, store each sentence in a vector.
    // Default delimiter is the newline character.
    while (getline(cin, str)) {
        v1.push_back(str);
    }

    cout << "The following input was stored with newline delimiter:" << endl;
    for (const auto& p : v1) {
        cout << p << endl;
    }

    cin.clear();

    vector<string> v2;
    // Now try it with a whitespace delimiter
    while (getline(cin, str, ' ')) {
        v2.push_back(str);
    }

    cout << "The following input was stored with whitespace as delimiter:" << endl;
    for (const auto& p : v2) {
        cout << p << endl;
    }
}
```

## <a name="stod"></a><a name="stod"></a> stod

Converte uma sequência de caracteres em um **`double`** .

```cpp
double stod(
    const string& str,
    size_t* idx = 0);

double stod(
    const wstring& str,
    size_t* idx = 0
;
```

### <a name="parameters"></a>parâmetros

*Str*\
A sequência de caracteres a ser convertida.

*Índ*\
O valor de índice do primeiro caractere não convertido.

### <a name="return-value"></a>Valor Retornado

O **`double`** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos em *Str* em um valor de Type **`double`** como If chamando `strtod( str.c_str(), _Eptr)` , em que `_Eptr` é um objeto interno à função. Se `str.c_str() == *_Eptr` , ele gera um objeto do tipo `invalid_argument` . Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *IDX* não for um ponteiro nulo, a função armazenará `*_Eptr -  str.c_str()` no `*idx` e retornará o valor.

## <a name="stof"></a><a name="stof"></a> stof

Converte uma sequência de caracteres em um float.

```cpp
float stof(
    const string& str,
    size_t* idx = 0);

float stof(
    const wstring& str,
    size_t* idx = 0);
```

### <a name="parameters"></a>parâmetros

*Str*\
A sequência de caracteres a ser convertida.

*Índ*\
O valor de índice do primeiro caractere não convertido.

### <a name="return-value"></a>Valor Retornado

O **`float`** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos em *Str* em um valor de Type **`float`** como If chamando `strtof( str.c_str(), _Eptr)` , em que `_Eptr` é um objeto interno à função. Se `str.c_str() == *_Eptr` , ele gera um objeto do tipo `invalid_argument` . Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *IDX* não for um ponteiro nulo, a função armazenará `*_Eptr -  str.c_str()` no `*idx` e retornará o valor.

## <a name="stoi"></a><a name="stoi"></a> stoi

Converte uma sequência de caracteres em um número inteiro.

```cpp
int stoi(
    const string& str,
    size_t* idx = 0,
    int base = 10);

int stoi(
    const wstring& str,
    size_t* idx = 0,
    int base = 10);
```

### <a name="return-value"></a>Valor Retornado

O valor inteiro.

### <a name="parameters"></a>parâmetros

*Str*\
A sequência de caracteres a ser convertida.

*Índ*\
O valor de índice do primeiro caractere não convertido.

*polybase*\
O número base a usar.

### <a name="remarks"></a>Comentários

A função `stoi` converte a sequência de caracteres em *Str* em um valor do tipo **`int`** e retorna o valor. Por exemplo, quando foi passada uma sequência de caracteres "10", o valor retornado por `stoi` é o inteiro 10.

`stoi` comporta-se da mesma forma que a função `strtol` para caracteres de byte único quando é chamado da maneira `strtol( str.c_str(), _Eptr, idx)` , em que `_Eptr` é um objeto interno à função; ou `wcstol` para caracteres largos, quando é chamado de maneira semelhante, `wcstol(Str.c_str(), _Eptr, idx)` . Para obter mais informações, consulte [strtol, wcstol, _strtol_l, _wcstol_l](../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md).

Se `str.c_str() == *_Eptr` , `stoi` gera um objeto do tipo `invalid_argument` . Se tal chamada definisse `errno` ou se o valor retornado não puder ser representado como um objeto do tipo **`int`** , ele lançará um objeto do tipo `out_of_range` . Caso contrário, se *IDX* não for um ponteiro nulo, a função armazenará `*_Eptr - str.c_str()` in `*idx` .

## <a name="stol"></a><a name="stol"></a> stol

Converte uma sequência de caracteres em um **`long`** .

```cpp
long stol(
    const string& str,
    size_t* idx = 0,
    int base = 10);

long stol(
    const wstring& str,
    size_t* idx = 0,
    int base = 10);
```

### <a name="parameters"></a>parâmetros

*Str*\
A sequência de caracteres a ser convertida.

*Índ*\
O valor de índice do primeiro caractere não convertido.

*polybase*\
O número base a usar.

### <a name="return-value"></a>Valor Retornado

O valor de inteiro longo.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos em *Str* em um valor de Type **`long`** como If chamando `strtol( str.c_str(), _Eptr, idx)` , em que `_Eptr` é um objeto interno à função. Se `str.c_str() == *_Eptr` , ele gera um objeto do tipo `invalid_argument` . Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *IDX* não for um ponteiro nulo, a função armazenará `*_Eptr -  str.c_str()` no `*idx` e retornará o valor.

## <a name="stold"></a><a name="stold"></a> stold

Converte uma sequência de caracteres em um **`long double`** .

```cpp
double stold(
    const string& str,
    size_t* idx = 0);

double stold(
    const wstring& str,
    size_t* idx = 0);
```

### <a name="parameters"></a>parâmetros

*Str*\
A sequência de caracteres a ser convertida.

*Índ*\
O valor de índice do primeiro caractere não convertido.

### <a name="return-value"></a>Valor Retornado

O **`long double`** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos em *Str* em um valor de Type **`long double`** como If chamando `strtold( str.c_str(), _Eptr)` , em que `_Eptr` é um objeto interno à função. Se `str.c_str() == *_Eptr` , ele gera um objeto do tipo `invalid_argument` . Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *IDX* não for um ponteiro nulo, a função armazenará `*_Eptr -  str.c_str()` no `*idx` e retornará o valor.

## <a name="stoll"></a><a name="stoll"></a> stoll

Converte uma sequência de caracteres em um **`long long`** .

```cpp
long long stoll(
    const string& str,
    size_t* idx = 0,
    int base = 10);

long long stoll(
    const wstring& str,
    size_t* idx = 0,
    int base = 10);
```

### <a name="parameters"></a>parâmetros

*Str*\
A sequência de caracteres a ser convertida.

*Índ*\
O valor de índice do primeiro caractere não convertido.

*polybase*\
O número base a usar.

### <a name="return-value"></a>Valor Retornado

O **`long long`** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos em *Str* em um valor de Type **`long long`** como If chamando `strtoll( str.c_str(), _Eptr, idx)` , em que `_Eptr` é um objeto interno à função. Se `str.c_str() == *_Eptr` , ele gera um objeto do tipo `invalid_argument` . Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *IDX* não for um ponteiro nulo, a função armazenará `*_Eptr -  str.c_str()` no `*idx` e retornará o valor.

## <a name="stoul"></a><a name="stoul"></a> stoul

Converte uma sequência de caracteres em um unsigned long.

```cpp
unsigned long stoul(
    const string& str,
    size_t* idx = 0,
    int base = 10);

unsigned long stoul(
    const wstring& str,
    size_t* idx = 0,
    int base = 10);
```

### <a name="parameters"></a>parâmetros

*Str*\
A sequência de caracteres a ser convertida.

*Índ*\
O valor de índice do primeiro caractere não convertido.

*polybase*\
O número base a usar.

### <a name="return-value"></a>Valor Retornado

O valor de inteiro longo não marcado.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos em *Str* em um valor de Type **`unsigned long`** como If chamando `strtoul( str.c_str(), _Eptr, idx)` , em que `_Eptr` é um objeto interno à função. Se `str.c_str() == *_Eptr` , ele gera um objeto do tipo `invalid_argument` . Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *IDX* não for um ponteiro nulo, a função armazenará `*_Eptr -  str.c_str()` no `*idx` e retornará o valor.

## <a name="stoull"></a><a name="stoull"></a> stoull

Converte uma sequência de caracteres em um **`unsigned long long`** .

```cpp
unsigned long long stoull(
    const string& str,
    size_t* idx = 0,
    int base = 10);

unsigned long long stoull(
    const wstring& str,
    size_t* idx = 0,
    int base = 10);
```

### <a name="parameters"></a>parâmetros

*Str*\
A sequência de caracteres a ser convertida.

*Índ*\
O valor de índice do primeiro caractere não convertido.

*polybase*\
O número base a usar.

### <a name="return-value"></a>Valor Retornado

O **`unsigned long long`** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos em *Str* em um valor de Type **`unsigned long long`** como If chamando `strtoull( str.c_str(), _Eptr, idx)` , em que `_Eptr` é um objeto interno à função. Se `str.c_str() == *_Eptr` , ele gera um objeto do tipo `invalid_argument` . Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *IDX* não for um ponteiro nulo, a função armazenará `*_Eptr -  str.c_str()` no `*idx` e retornará o valor.

## <a name="swap"></a><a name="swap"></a> permuta

Troca as matrizes de caracteres de duas cadeias de caracteres.

```cpp
template <class Traits, class Allocator>
void swap(basic_string<CharType, Traits, Allocator>& left, basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>parâmetros

*mantida*\
Uma cadeia de caracteres cujos elementos devem ser trocados pelos elementos de outra cadeia de caracteres.

*Certo*\
A outra sequência cujos elementos devem ser trocados pela primeira cadeia de caracteres.

### <a name="remarks"></a>Comentários

A função de modelo executa a função de membro especializada *restante*. [troca](../standard-library/basic-string-class.md#swap)(*à direita*) para cadeias de caracteres, o que garante complexidade constante.

### <a name="example"></a>Exemplo

```cpp
// string_swap.cpp
// compile with: /EHsc
#include <string>
#include <iostream>

int main( )
{
   using namespace std;
   // Declaring an object of type basic_string<char>
   string s1 ( "Tweedledee" );
   string s2 ( "Tweedledum" );
   cout << "Before swapping string s1 and s2:" << endl;
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;

   swap ( s1 , s2 );
   cout << "\nAfter swapping string s1 and s2:" << endl;
   cout << "The basic_string s1 = " << s1 << "." << endl;
   cout << "The basic_string s2 = " << s2 << "." << endl;
}
```

```Output
Before swapping string s1 and s2:
The basic_string s1 = Tweedledee.
The basic_string s2 = Tweedledum.

After swapping string s1 and s2:
The basic_string s1 = Tweedledum.
The basic_string s2 = Tweedledee.
```

## <a name="to_string"></a><a name="to_string"></a> to_string

Converte um valor em uma `string`.

```cpp
string to_string(int value);
string to_string(unsigned int value);
string to_string(long value);
string to_string(unsigned long value);
string to_string(long long value);
string to_string(unsigned long long value);
string to_string(float value);
string to_string(double value);
string to_string(long double value);
```

### <a name="parameters"></a>parâmetros

*valor*\
O valor a ser convertido.

### <a name="return-value"></a>Valor Retornado

A `string` que representa o valor.

### <a name="remarks"></a>Comentários

A função converte o *valor* em uma sequência de elementos armazenados em um objeto de matriz `Buf` interno à função como se chamar `sprintf(Buf, Fmt, value)` , onde `Fmt` é

- `"%d"` Se o *valor* for do tipo **`int`**

- `"%u"` Se o *valor* for do tipo **`unsigned int`**

- `"%ld"` Se o *valor* for do tipo **`long`**

- `"%lu"` Se o *valor* for do tipo **`unsigned long`**

- `"%lld"` Se o *valor* for do tipo **`long long`**

- `"%llu"` Se o *valor* for do tipo **`unsigned long long`**

- `"%f"` Se *Value* for do tipo **`float`** ou **`double`**

- `"%Lf"` Se o *valor* for do tipo **`long double`**

A função retorna `string(Buf)`.

## <a name="to_wstring"></a><a name="to_wstring"></a> to_wstring

Converte um valor em uma cadeia de caracteres larga.

```cpp
wstring to_wstring(int value);
wstring to_wstring(unsigned int value);
wstring to_wstring(long value);
wstring to_wstring(unsigned long value);
wstring to_wstring(long long value);
wstring to_wstring(unsigned long long value);
wstring to_wstring(float value);
wstring to_wstring(double value);
wstring to_wstring(long double value);
```

### <a name="parameters"></a>parâmetros

*valor*\
O valor a ser convertido.

### <a name="return-value"></a>Valor Retornado

A cadeia de caracteres larga que representa o valor.

### <a name="remarks"></a>Comentários

A função converte o *valor* em uma sequência de elementos armazenados em um objeto de matriz `Buf` interno à função como se chamar `swprintf(Buf, Len, Fmt, value)` , onde `Fmt` é

- `L"%d"` Se o *valor* for do tipo **`int`**

- `L"%u"` Se o *valor* for do tipo **`unsigned int`**

- `L"%ld"` Se o *valor* for do tipo **`long`**

- `L"%lu"` Se o *valor* for do tipo **`unsigned long`**

- `L"%lld"` Se o *valor* for do tipo **`long long`**

- `L"%llu"` Se o *valor* for do tipo **`unsigned long long`**

- `L"%f"` Se *Value* for do tipo **`float`** ou **`double`**

- `L"%Lf"` Se o *valor* for do tipo **`long double`**

A função retorna `wstring(Buf)`.

## <a name="see-also"></a>Confira também

[\<string>](../standard-library/string.md)
