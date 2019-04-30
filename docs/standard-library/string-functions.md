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
ms.openlocfilehash: d10af9bc32acd730db1fe9da3775ac2aa84e5fff
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62412339"
---
# <a name="ltstringgt-functions"></a>Funções &lt;de cadeia de caracteres&gt;

||||
|-|-|-|
|[getline](#getline)|[stod](#stod)|[stof](#stof)|
|[stoi](#stoi)|[stol](#stol)|[stold](#stold)|
|[stoll](#stoll)|[stoul](#stoul)|[stoull](#stoull)|
|[swap](#swap)|[to_string](#to_string)|[to_wstring](#to_wstring)|

## <a name="getline"></a>  getline

Extrai cadeias de caracteres do fluxo de entrada linha por linha.

```cpp
// (1) delimiter as parameter
template <class CharType, class Traits, class Allocator>
basic_istream<CharType, Traits>& getline(
    basic_istream<CharType, Traits>& is,
    basic_string<CharType, Traits, Allocator>& str,
    CharType delim);

template <class CharType, class Traits, class Allocator>
basic_istream<CharType, Traits>& getline(
    basic_istream<CharType, Traits>&& is,
    basic_string<CharType, Traits, Allocator>& str,
    const CharType delim);

// (2) default delimiter used
template <class CharType, class Traits, class Allocator>
basic_istream<CharType, Traits>& getline(
    basic_istream<CharType, Traits>& is,
    basic_string<CharType, Traits, Allocator>& str);

template <class Allocator, class Traits, class Allocator>
basic_istream<Allocator, Traits>& getline(
    basic_istream<Allocator, Traits>&& is,
    basic_string<Allocator, Traits, Allocator>& str);
```

### <a name="parameters"></a>Parâmetros

*is*<br/>
O fluxo de entrada do qual uma cadeia de caracteres será extraída.

*str*<br/>
A cadeia de caracteres na qual são lidos os caracteres do fluxo de entrada.

*delim*<br/>
O delimitador de linha.

### <a name="return-value"></a>Valor de retorno

O fluxo de entrada *é*.

### <a name="remarks"></a>Comentários

O par de assinaturas de função marcado `(1)` extração de caracteres *é* até *delim* for encontrado, armazená-los em *str*.

O par de assinaturas de função marcado `(2)` usa a nova linha como delimitador de linha padrão e se comportam como **getline**(`is`, `str`, `is`. `widen`(' `\n`')).

A segunda função de cada par é equivalente à primeira para dar suporte a [referências de valor](../cpp/lvalues-and-rvalues-visual-cpp.md).

A extração é interrompida quando ocorre uma das seguintes situações:

- No final do arquivo, caso em que o estado interno do sinalizador de *está* é definido como `ios_base::eofbit`.

- Depois que a função extrai um elemento comparável a `delim`, caso em que o elemento não é recolocado nem acrescentado à sequência controlada.

- Depois que a função extrai `str.` [max_size](../standard-library/basic-string-class.md#max_size) elementos, no qual o sinalizador de estado interno de casos *está* é definido como `ios_base::failbit`.

- Algum outro erro diferente daqueles listados anteriormente, caso em que o estado interno do sinalizador de *é* é definido como `ios_base::badbit`

Para obter informações sobre os sinalizadores de estado interno, consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate).

Se a função não extrair nenhum elemento, o estado interno do sinalizador de *está* é definido como `ios_base::failbit`. Em qualquer caso, `getline` retorna *é*.

Se uma exceção for lançada, *está* e *str* são deixados em um estado válido.

### <a name="example"></a>Exemplo

O código a seguir demonstra `getline()` em dois modos: primeiro com o delimitador padrão (nova linha) e a segundo com um espaço em branco como delimitador. O caractere de final de arquivo (CTRL-Z no teclado) é usado para controlar a terminação de loops while. Isso define o sinalizador de estado interno de `cin` para `eofbit`, que deve ser limpo com [basic_ios::clear()](../standard-library/basic-ios-class.md#clear) antes que o segundo, enquanto o loop funcionará corretamente.

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

## <a name="stod"></a>  stod

Converte uma sequência de caracteres em uma **duplas**.

```cpp
double stod(
    const string& str,
    size_t* idx = 0);

double stod(
    const wstring& str,
    size_t* idx = 0
;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*str*|A sequência de caracteres a ser convertida.|
|*idx*|O valor de índice do primeiro caractere não convertido.|

### <a name="return-value"></a>Valor de retorno

O **duplas** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos na *str* com um valor `val` do tipo **double** como se fosse chamar `strtod( str.c_str(), _Eptr)`, onde `_Eptr` é um objeto interno para a função. Se ` str.c_str() == *_Eptr`, gerará um objeto do tipo `invalid_argument`. Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *idx* não é um ponteiro nulo, a função armazena `*_Eptr -  str.c_str()` na `*idx` e retorna `val`.

## <a name="stof"></a>  stof

Converte uma sequência de caracteres em um float.

```cpp
float stof(
    const string& str,
    size_t* idx = 0);

float stof(
    const wstring& str,
    size_t* idx = 0);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*str*|A sequência de caracteres a ser convertida.|
|*idx*|O valor de índice do primeiro caractere não convertido.|

### <a name="return-value"></a>Valor de retorno

O valor flutuante.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos na *str* com um valor `val` do tipo **float** como se fosse chamar `strtof( str.c_str(), _Eptr)`, onde `_Eptr` é um objeto interno para a função. Se ` str.c_str() == *_Eptr`, gerará um objeto do tipo `invalid_argument`. Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *idx* não é um ponteiro nulo, a função armazena `*_Eptr -  str.c_str()` na `*idx` e retorna `val`.

## <a name="stoi"></a>  stoi

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

### <a name="return-value"></a>Valor de retorno

O valor inteiro.

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*str*|A sequência de caracteres a ser convertida.|
|*idx*|Contém o índice do primeiro caractere não convertido em retorno.|
|*base*|O número base a usar.|

### <a name="remarks"></a>Comentários

A função `stoi` converte a sequência de caracteres em *str* em um valor do tipo **int** e retorna o valor. Por exemplo, quando foi passada uma sequência de caracteres "10", o valor retornado por `stoi` é o inteiro 10.

`stoi` comporta-se de forma semelhante à função `strtol` para caracteres de byte único quando é chamado na forma `strtol( str.c_str(), _Eptr, idx)`, em que `_Eptr` é um objeto interno à função; ou `wcstol` para caracteres largos, quando é chamado de maneira semelhante, `wcstol(Str.c_str(), _Eptr, idx)`. Para obter mais informações, consulte [strtol, wcstol, _strtol_l, _wcstol_l](../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md).

Se `str.c_str() == *_Eptr`, `stoi` gerará um objeto do tipo `invalid_argument`. Se tal chamada definir `errno`, ou se o valor retornado não pode ser representado como um objeto do tipo **int**, ele gerará um objeto do tipo `out_of_range`. Caso contrário, se *idx* não é um ponteiro nulo, a função armazena `*_Eptr - str.c_str()` em `*idx`.

## <a name="stol"></a>  stol

Converte uma sequência de caracteres em uma **longo**.

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

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*str*|A sequência de caracteres a ser convertida.|
|*idx*|O valor de índice do primeiro caractere não convertido.|
|*base*|O número base a usar.|

### <a name="return-value"></a>Valor de retorno

O valor de inteiro longo.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos na *str* com um valor `val` do tipo **longo** como se fosse chamar `strtol( str.c_str(), _Eptr, idx)`, onde `_Eptr` é um objeto interno para a função. Se ` str.c_str() == *_Eptr`, gerará um objeto do tipo `invalid_argument`. Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *idx* não é um ponteiro nulo, a função armazena `*_Eptr -  str.c_str()` na `*idx` e retorna `val`.

## <a name="stold"></a>  stold

Converte uma sequência de caracteres em uma **longo duplo**.

```cpp
double stold(
    const string& str,
    size_t* idx = 0);

double stold(
    const wstring& str,
    size_t* idx = 0);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*str*|A sequência de caracteres a ser convertida.|
|*idx*|O valor de índice do primeiro caractere não convertido.|

### <a name="return-value"></a>Valor de retorno

O **longo duplo** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos na *str* com um valor `val` do tipo **long double** como se fosse chamar `strtold( str.c_str(), _Eptr)`, onde `_Eptr` é um objeto interno para a função. Se ` str.c_str() == *_Eptr`, gerará um objeto do tipo `invalid_argument`. Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *idx* não é um ponteiro nulo, a função armazena `*_Eptr -  str.c_str()` na `*idx` e retorna `val`.

## <a name="stoll"></a>  stoll

Converte uma sequência de caracteres em uma **long long**.

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

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*str*|A sequência de caracteres a ser convertida.|
|*idx*|O valor de índice do primeiro caractere não convertido.|
|*base*|O número base a usar.|

### <a name="return-value"></a>Valor de retorno

O **long long** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos na *str* com um valor `val` do tipo **long long** como se fosse chamar `strtoll( str.c_str(), _Eptr, idx)`, onde `_Eptr` é um objeto interno para a função. Se ` str.c_str() == *_Eptr`, gerará um objeto do tipo `invalid_argument`. Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *idx* não é um ponteiro nulo, a função armazena `*_Eptr -  str.c_str()` na `*idx` e retorna `val`.

## <a name="stoul"></a>  stoul

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

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*str*|A sequência de caracteres a ser convertida.|
|*idx*|O valor de índice do primeiro caractere não convertido.|
|*base*|O número base a usar.|

### <a name="return-value"></a>Valor de retorno

O valor de inteiro longo não marcado.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos na *str* com um valor `val` do tipo **unsigned long** como se fosse chamar `strtoul( str.c_str(), _Eptr, idx)`, onde `_Eptr` é um objeto interno para a função . Se ` str.c_str() == *_Eptr`, gerará um objeto do tipo `invalid_argument`. Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *idx* não é um ponteiro nulo, a função armazena `*_Eptr -  str.c_str()` na `*idx` e retorna `val`.

## <a name="stoull"></a>  stoull

Converte uma sequência de caracteres em uma **longo longo sem sinal**.

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

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*str*|A sequência de caracteres a ser convertida.|
|*idx*|O valor de índice do primeiro caractere não convertido.|
|*base*|O número base a usar.|

### <a name="return-value"></a>Valor de retorno

O **longo longo sem sinal** valor.

### <a name="remarks"></a>Comentários

A função converte a sequência de elementos na *str* com um valor `val` do tipo **longo longo sem sinal** como se fosse chamar `strtoull( str.c_str(), _Eptr, idx)`, onde `_Eptr` é um objeto interno para o função. Se ` str.c_str() == *_Eptr`, gerará um objeto do tipo `invalid_argument`. Se tal chamada definir `errno`, gerará um objeto do tipo `out_of_range`. Caso contrário, se *idx* não é um ponteiro nulo, a função armazena `*_Eptr -  str.c_str()` na `*idx` e retorna `val`.

## <a name="swap"></a>  swap

Troca as matrizes de caracteres de duas cadeias de caracteres.

```cpp
template <class Traits, class Allocator>
void swap(basic_string<CharType, Traits, Allocator>& left, basic_string<CharType, Traits, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*left*<br/>
Uma cadeia de caracteres cujos elementos devem ser trocado pelos de outra cadeia de caracteres.

*right*<br/>
A outra sequência cujos elementos devem ser trocados pela primeira cadeia de caracteres.

### <a name="remarks"></a>Comentários

A função de modelo executa a função de membro especializado *esquerdo*.[ permuta](../standard-library/basic-string-class.md#swap)(*direito*) para cadeias de caracteres, que garante complexidade constante.

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

## <a name="to_string"></a>  to_string

Converte um valor em uma `string`.

```cpp
string to_string(int Val);
string to_string(unsigned int Val);
string to_string(long Val);
string to_string(unsigned long Val);
string to_string(long long Val);
string to_string(unsigned long long Val);
string to_string(float Val);
string to_string(double Val);
string to_string(long double Val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Val*|O valor a ser convertido.|

### <a name="return-value"></a>Valor de retorno

A `string` que representa o valor.

### <a name="remarks"></a>Comentários

A função converte *Val* em uma sequência de elementos armazenados em um objeto de matriz `Buf` interno para a função, como se fosse chamar `sprintf(Buf, Fmt, Val)`, onde `Fmt` é

- `"%d"` Se `Val` tem tipo **int**

- `"%u"` Se `Val` tem tipo **int sem sinal**

- `"%ld"` Se `Val` tem tipo **longo**

- `"%lu"` Se `Val` tem tipo **unsigned long**

- `"%lld"` Se `Val` tem tipo **long long**

- `"%llu"` Se `Val` tem tipo **longo longo sem sinal**

- `"%f"` Se `Val` tem o tipo **float** ou **duplo**

- `"%Lf"` Se `Val` tem tipo **longo duplo**

A função retorna `string(Buf)`.

## <a name="to_wstring"></a>  to_wstring

Converte um valor em uma cadeia de caracteres larga.

```cpp
wstring to_wstring(int Val);
wstring to_wstring(unsigned int Val);
wstring to_wstring(long Val);
wstring to_wstring(unsigned long Val);
wstring to_wstring(long long Val);
wstring to_wstring(unsigned long long Val);
wstring to_wstring(float Val);
wstring to_wstring(double Val);
wstring to_wstring(long double Val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`Val`|O valor a ser convertido.|

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres larga que representa o valor.

### <a name="remarks"></a>Comentários

A função converte `Val` em uma sequência de elementos armazenados em um objeto de matriz `Buf` interna para a função como na chamada de `swprintf(Buf, Len, Fmt, Val)`, em que `Fmt` será

- `L"%d"` Se `Val` tem tipo **int**

- `L"%u"` Se `Val` tem tipo **int sem sinal**

- `L"%ld"` Se `Val` tem tipo **longo**

- `L"%lu"` Se `Val` tem tipo **unsigned long**

- `L"%lld"` Se `Val` tem tipo **long long**

- `L"%llu"` Se `Val` tem tipo **longo longo sem sinal**

- `L"%f"` Se `Val` tem o tipo **float** ou **duplo**

- `L"%Lf"` Se `Val` tem tipo **longo duplo**

A função retorna `wstring(Buf)`.

## <a name="see-also"></a>Consulte também

[\<string>](../standard-library/string.md)<br/>
