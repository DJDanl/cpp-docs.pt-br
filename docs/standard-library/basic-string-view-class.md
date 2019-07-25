---
title: Classe basic_string_view
ms.date: 04/20/2019
f1_keywords:
- xstring/std::basic_string_view
- xstring/std::basic_string_view::allocator_type
- xstring/std::basic_string_view::const_iterator
- xstring/std::basic_string_view::const_pointer
- xstring/std::basic_string_view::const_reference
- xstring/std::basic_string_view::const_reverse_iterator
- xstring/std::basic_string_view::difference_type
- xstring/std::basic_string_view::iterator
- xstring/std::basic_string_view::npos
- xstring/std::basic_string_view::pointer
- xstring/std::basic_string_view::reference
- xstring/std::basic_string_view::reverse_iterator
- xstring/std::basic_string_view::size_type
- xstring/std::basic_string_view::traits_type
- xstring/std::basic_string_view::value_type
- xstring/std::basic_string_view::append
- xstring/std::basic_string_view::assign
- xstring/std::basic_string_view::at
- xstring/std::basic_string_view::back
- xstring/std::basic_string_view::begin
- xstring/std::basic_string_view::c_str
- xstring/std::basic_string_view::capacity
- xstring/std::basic_string_view::cbegin
- xstring/std::basic_string_view::cend
- xstring/std::basic_string_view::clear
- xstring/std::basic_string_view::compare
- xstring/std::basic_string_view::copy
- xstring/std::basic_string_view::_Copy_s
- xstring/std::basic_string_view::crbegin
- xstring/std::basic_string_view::crend
- xstring/std::basic_string_view::data
- xstring/std::basic_string_view::empty
- xstring/std::basic_string_view::end
- xstring/std::basic_string_view::erase
- xstring/std::basic_string_view::find
- xstring/std::basic_string_view::find_first_not_of
- xstring/std::basic_string_view::find_first_of
- xstring/std::basic_string_view::find_last_not_of
- xstring/std::basic_string_view::find_last_of
- xstring/std::basic_string_view::front
- xstring/std::basic_string_view::get_allocator
- xstring/std::basic_string_view::insert
- xstring/std::basic_string_view::length
- xstring/std::basic_string_view::max_size
- xstring/std::basic_string_view::pop_back
- xstring/std::basic_string_view::push_back
- xstring/std::basic_string_view::rbegin
- xstring/std::basic_string_view::rend
- xstring/std::basic_string_view::remove_prefix
- xstring/std::basic_string_view::remove_suffix
- xstring/std::basic_string_view::replace
- xstring/std::basic_string_view::reserve
- xstring/std::basic_string_view::resize
- xstring/std::basic_string_view::rfind
- xstring/std::basic_string_view::shrink_to_fit
- xstring/std::basic_string_view::size
- xstring/std::basic_string_view::substr
- xstring/std::basic_string_view::swap
helpviewer_keywords:
- std::basic_string_view
- std::basic_string_view, allocator_type
- std::basic_string_view, const_iterator
- std::basic_string_view, const_pointer
- std::basic_string_view, const_reference
- std::basic_string_view, const_reverse_iterator
- std::basic_string_view, difference_type
- std::basic_string_view, iterator
- std::basic_string_view, npos
- std::basic_string_view, pointer
- std::basic_string_view, reference
- std::basic_string_view, reverse_iterator
- std::basic_string_view, size_type
- std::basic_string_view, traits_type
- std::basic_string_view, value_type
- std::basic_string_view, append
- std::basic_string_view, assign
- std::basic_string_view, at
- std::basic_string_view, back
- std::basic_string_view, begin
- std::basic_string_view, c_str
- std::basic_string_view, capacity
- std::basic_string_view, cbegin
- std::basic_string_view, cend
- std::basic_string_view, clear
- std::basic_string_view, compare
- std::basic_string_view, copy
- std::basic_string_view, crbegin
- std::basic_string_view, crend
- std::basic_string_view, data
- std::basic_string_view, empty
- std::basic_string_view, end
- std::basic_string_view, erase
- std::basic_string_view, find
- std::basic_string_view, find_first_not_of
- std::basic_string_view, find_first_of
- std::basic_string_view, find_last_not_of
- std::basic_string_view, find_last_of
- std::basic_string_view, front
- std::basic_string_view, get_allocator
- std::basic_string_view, insert
- std::basic_string_view, length
- std::basic_string_view, max_size
- std::basic_string_view, pop_back
- std::basic_string_view, push_back
- std::basic_string_view, rbegin
- std::basic_string_view, rend
- std::basic_string_view, remove_prefix
- std::basic_string_view, remove_suffix
- std::basic_string_view, replace
- std::basic_string_view, reserve
- std::basic_string_view, resize
- std::basic_string_view, rfind
- std::basic_string_view, shrink_to_fit
- std::basic_string_view, size
- std::basic_string_view, substr
- std::basic_string_view, swap
ms.assetid: a9c3e0a2-39bf-4c8a-b093-9abe30839591
ms.openlocfilehash: e5d89eeb9f663c8699ddad469a8189008671ed3b
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68447863"
---
# <a name="basicstringview-class"></a>Classe basic_string_view

O modelo `basic_string_view<charT>` de classe foi adicionado em c++ 17 para servir como uma maneira segura e eficiente para uma função aceitar vários tipos de cadeia de caracteres não relacionados sem que a função precise ser modelos nesses tipos. A classe mantém um ponteiro não proprietário para uma sequência contígua de dados de caractere e um comprimento que especifica o número de caracteres na sequência. Não é feita nenhuma suposição em relação a se a sequência é terminada em nulo.

A biblioteca padrão define várias especializações com base no tipo dos elementos:

-  `string_view`
-  `wstring_view`
-  `u16string_view`
-  `u32string_view`

Neste documento, o termo "string_view" refere-se geralmente a qualquer um desses TYPEDEFs.

Um string_view descreve a interface comum mínima necessária para ler dados de cadeia de caracteres. Ele fornece acesso const aos dados subjacentes; Ele não faz nenhuma cópia (exceto para `copy` a função). Os dados podem ou não conter valores nulos (' \ 0 ') em qualquer posição. Um string_view não tem controle sobre o tempo de vida do objeto. É responsabilidade do chamador garantir que os dados de cadeia de caracteres subjacentes sejam válidos.

Uma função que aceita um parâmetro do tipo string_view pode ser feita para funcionar com qualquer tipo de cadeia de caracteres, sem transformar a função em um modelo ou restringir a função a um subconjunto específico de tipos de cadeia de caracteres. O único requisito é que exista uma conversão implícita do tipo de cadeia de caracteres para string_view. Todos os tipos de cadeia de caracteres padrão são implicitamente conversíveis para um string_view que contém o mesmo tipo de elemento. Em outras palavras, um `std::string` é conversível para `string_view` um, mas não `wstring_view`para um.

O exemplo a seguir mostra uma função `f` que não é de modelo que usa um parâmetro do tipo. `wstring_view` Ele pode ser chamado com argumentos do tipo `std::wstring`, `wchar_t*`e `winrt::hstring`.

```cpp
// compile with: /std:c++17
// string_view that uses elements of wchar_t
void f(wstring_view);

// pass a std::wstring:
const std::wstring& s { L"Hello" };
f(s);

// pass a C-style null-terminated string (string_view is not null-terminated):
const wchar_t* ns = L"Hello";
f(ns);

// pass a C-style character array of len characters (excluding null terminator):
const wchar_t* cs { L"Hello" };
size_t len { 5 };
f({cs,len});

// pass a WinRT string
winrt::hstring hs { L"Hello" };
f(hs);
```

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class Traits = char_traits<CharType>>
class basic_string_view;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo dos caracteres que são armazenados no string_view. A C++ biblioteca padrão fornece os seguintes typedefs para especializações deste modelo.
- [string_view](../standard-library/string-view-typedefs.md#string_view) para elementos do tipo **Char**
- [wstring_view](../standard-library/string-view-typedefs.md#wstring_view), para **wchar_t**
- [u16string_view](../standard-library/string-view-typedefs.md#u16string_view) para **char16_t**
- [u32string_view](../standard-library/string-view-typedefs.md#u32string_view) para **char32_t**.

*Características*\
O padrão é [char_traits](char-traits-struct.md)<*CharType*>.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_string_view](#basic_string_view)|Constrói um string_view que está vazio ou aponta para todos ou para parte de outros dados do objeto de cadeia de caracteres ou para uma matriz de caracteres de estilo C.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|**const_iterator**|Iterador de acesso aleatório que pode ler elementos **const** .|
|**const_pointer**|`using const_pointer = const value_type*;`|
|**const_reference**|`using const_reference = const value_type&;`|
|**const_reverse_iterator**|`using const_reverse_iterator = std::reverse_iterator<const_iterator>;`|
|**difference_type**|`using difference_type = ptrdiff_t;`|
|**iterator**|`using iterator = const_iterator;`|
|**npos**|`static constexpr size_type npos = size_type(-1);`|
|**pointer**|`using pointer = value_type*;`|
|**reference**|`using reference = value_type&;`|
|**reverse_iterator**|`using reverse_iterator = const_reverse_iterator;`|
|**size_type**|`using size_type = size_t;`|
|**traits_type**|`using traits_type = Traits;`|
|**value_type**|`using value_type = CharType;`|

### <a name="member-operators"></a>Operadores de membro

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Atribui um objeto de cadeia de caracteres string_view ou conversível a outro string_view.|
|[operator\[\]](#op_at)|Retorna o elemento no índice especificado.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[at](#at)|Retorna um const_reference para o elemento em um local especificado.|
|[back](#back)|Retorna um const_reference para o último elemento.|
|[begin](#begin)|Retorna um iterador const que aborda o primeiro elemento. (string_views são imutáveis.)|
|[cbegin](#cbegin)|O mesmo que [começar](#begin).|
|[cend](#cend)|Retorna um iterador const que aponta para um passado para o último elemento.|
|[copy](#copy)|Copia no máximo um número especificado de caracteres de uma posição indexada em um string_view de origem para uma matriz de caracteres de destino. (Não recomendado. Em vez disso, use _Copy_s.)|
|[_Copy_s](#_copy_s)|Função de cópia de CRT segura.|
|[compare](#compare)|Compara um string_view com um string_view especificado para determinar se eles são iguais ou se um é modo lexicográfico menor do que o outro.|
|[crbegin](#crbegin)|O mesmo que [rbegin](#rbegin).|
|[crend](#crend)|O mesmo que [rend](#rend).|
|[data](#data)|Retorna um ponteiro não proprietário bruto para a sequência de caracteres.|
|[empty](#empty)|Testa se o string_view contém caracteres.|
|[end](#end)|O mesmo que [cend](#cend).|
|[find](#find)|Pesquisa na direção de encaminhamento da primeira ocorrência de uma subcadeia de caracteres que corresponde a uma sequência especificada.|
|[find_first_not_of](#find_first_not_of)|Pesquisa o primeiro caractere que não seja qualquer elemento de um objeto de cadeia de caracteres string_view ou conversível especificado.|
|[find_first_of](#find_first_of)|Pesquisa o primeiro caractere que corresponde a qualquer elemento de um objeto de cadeia de caracteres string_view ou conversível especificado.|
|[find_last_not_of](#find_last_not_of)|Procura o último caractere que não seja nenhum elemento de um objeto de cadeia de caracteres string_view ou conversível especificado.|
|[find_last_of](#find_last_of)|Pesquisa o último caractere que é um elemento de um objeto de cadeia de caracteres string_view ou conversível especificado.|
|[front](#front)|Retorna um const_reference para o primeiro elemento.|
|[length](#length)|Retorna o número atual de elementos.|
|[max_size](#max_size)|Retorna o número máximo de caracteres que um string_view pode conter.|
|[rbegin](#rbegin)|Retorna um iterador const que aborda o primeiro elemento em um string_view invertido.|
|[remove_prefix](#remove_prefix)|Move o ponteiro para frente pelo número especificado de elementos.|
|[remove_suffix](#remove_suffix)|Reduz o tamanho da exibição pelo número especificado de elementos, começando da parte posterior.|
|[rend](#rend)|Retorna um iterador const que aponta para um passado o último elemento em um string_view invertido.|
|[rfind](#rfind)|Pesquisa um string_view em um inverso para a primeira ocorrência de uma subcadeia de caracteres que corresponde a uma sequência especificada.|
|[size](#size)|Retorna o número atual de elementos.|
|[substr](#substr)|Retorna uma subcadeia de caracteres de um comprimento especificado a partir de um índice especificado.|
|[swap](#swap)|Troque o conteúdo de dois string_views.|

## <a name="remarks"></a>Comentários

Se for solicitado que uma função gere uma sequência mais longa que os elementos [max_size](#max_size), a função relatará um erro de comprimento, gerando um objeto do tipo [length_error](../standard-library/length-error-class.md).

## <a name="requirements"></a>Requisitos

[std: c++ 17](../build/reference/std-specify-language-standard-version.md) ou posterior

**Cabeçalho:** \<> string_view

**Namespace:** std

## <a name="at"></a>  basic_string_view::at

Retorna um const_reference para o caractere no índice baseado em 0 especificado.

```cpp
constexpr const_reference at(size_type offset) const;
```

### <a name="parameters"></a>Parâmetros

*desvio*\
O índice do elemento a ser referenciado.

### <a name="return-value"></a>Valor de retorno

Um const_reference para o caractere na posição especificada pelo índice de parâmetro.

### <a name="remarks"></a>Comentários

O primeiro elemento tem um índice de zero e os elementos a seguir são indexados consecutivamente pelos inteiros positivos, de modo que um string_view de comprimento *n* tenha um elemento *n*th indexado pelo número *n-* 1. **at** gera uma exceção para índices inválidos, ao contrário do [operador\[\]](#op_at). 

Em geral, é recomendável que **em** para sequências `std::vector` como e string_view nunca seja usado. Um índice inválido passado para uma sequência é um erro lógico que deve ser descoberto e corrigido durante o desenvolvimento. Se um programa não tiver certeza absoluta de que seus índices são válidos, ele deve testá-los, não chamar at () e contar com exceções para se defender contra programação com cuidado.

Consulte [basic_string_view:: Operator\[ \] ](#op_at) para obter mais informações.

### <a name="example"></a>Exemplo

```cpp
// basic_string_view_at.cpp
// compile with: /EHsc
#include <string_view>
#include <iostream>

int main()
{
    using namespace std;

    const string_view  str1("Hello world");
    string_view::const_reference refStr2 = str1.at(8); // 'r'
}
```

## <a name="back"></a>  basic_string_view::back

Retorna um const_reference para o último elemento.

```cpp
constexpr const_reference back() const;
```

### <a name="return-value"></a>Valor de retorno

Um const_reference para o último elemento no string_view.

### <a name="remarks"></a>Comentários

Gera uma exceção se o string_view estiver vazio.

Tenha em mente que, depois que um string_view é modificado, por exemplo `remove_suffix`chamando, o elemento retornado por essa função não é mais o último elemento nos dados subjacentes.

### <a name="example"></a>Exemplo

Um string_view que é construído com um literal de cadeia de caracteres C não inclui o nulo de terminação e, `back` portanto, no exemplo a seguir, retorna ' p ' e não ' \ 0 '.

```cpp
char c[] = "Help"; // char[5]
string_view sv{ c };
cout << sv.size(); // size() == 4
cout << sv.back() << endl; // p 
```

Os nulos inseridos são tratados como qualquer outro caractere:

```cpp
string_view e = "embedded\0nulls"sv;
cout << boolalpha << (e.back() == 's'); // true
```

## <a name="basic_string_view"></a>  basic_string_view::basic_string_view

Constrói um string_view.

```cpp
constexpr basic_string_view() noexcept;
constexpr basic_string_view(const basic_string_view&) noexcept = default;
constexpr basic_string_view(const charT* str);
constexpr basic_string_view(const charT* str, size_type len);
```

### <a name="parameters"></a>Parâmetros

*Str*\
O ponteiro para os valores de caracteres.

*Len*\
O número de caracteres a serem incluídos na exibição.

## <a name="remarks"></a>Comentários

Os construtores com um parâmetro charT * supõem que a entrada é terminada em nulo, mas o nulo de terminação não está incluído no string_view.

Você também pode construir um string_view com um literal. Consulte o [operador "" VA](string-view-operators.md#op_sv).

## <a name="begin"></a>  basic_string_view::begin

O mesmo que [cbegin](#cbegin).

```cpp
constexpr const_iterator begin() const noexcept;
```

### <a name="return-value"></a>Valor de retorno
Retorna um const_iterator que endereça o primeiro elemento.

## <a name="cbegin"></a>  basic_string_view::cbegin

Retorna um const_iterator que aborda o primeiro elemento no intervalo.

```cpp
constexpr const_iterator cbegin() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório **const** que aponta para o primeiro elemento do intervalo ou o local logo após o final de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).

## <a name="cend"></a>  basic_string_view::cend

Retorna um const_iterator que aborda o local logo após o último elemento em um intervalo.

```cpp
constexpr const_iterator cend() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório **const** que aponta muito além do fim do intervalo.

### <a name="remarks"></a>Comentários

O valor retornado por `cend` não deve ser desreferenciado.

## <a name="compare"></a> basic_string_view::compare

Executa uma comparação de maiúsculas e minúsculas com um string_view especificado (ou um tipo de cadeia de caracteres conversível) para determinar se os dois objetos são iguais ou se um deles é modo lexicográfico menor do que o outro. Os [ \<operadores de > string_view](string-view-operators.md) usam essa função de membro para executar comparações.

```cpp
constexpr int compare(basic_string_view strv) const noexcept;
constexpr int compare(size_type pos, size_type num, basic_string_view strv) const;
constexpr int compare(size_type pos, size_type num, basic_string_view strv, size_type offset, size_type num2) const;
constexpr int compare(const charT* ptr) const;
constexpr int compare(size_type pos, size_type num, const charT* ptr) const;
constexpr int compare(size_type pos, size_type num, const charT* ptr, size_type num2) const;
```

### <a name="parameters"></a>Parâmetros

*strv*\
O string_view que deve ser comparado a esse string_view.

*pos*\
O índice desse string_view no qual a comparação começa.

*teclas*\
O número máximo de caracteres deste string_view a ser comparado.

*num2*\
O número máximo de caracteres de *strv* a serem comparados.

*desvio*\
O índice de *strv* no qual a comparação começa.

*PTR*\
A cadeia de caracteres C a ser comparada a este string_view.

### <a name="return-value"></a>Valor de retorno

Um valor negativo se esse string_view for menor que *strv* ou *PTR*; zero se as duas sequências de caracteres forem iguais; ou um valor positivo se esse string_view for maior que *strv* ou *PTR*.

### <a name="remarks"></a>Comentários

As `compare` funções de membro executam uma comparação que diferencia maiúsculas de minúsculas de toda ou parte de cada sequência de caracteres. 

### <a name="example"></a>Exemplo

```cpp
// basic_string_view_compare.cpp
// compile with: /EHsc
#include <string_view>
#include <iostream>
#include <string>

using namespace std;

string to_alpha(int result)
{
   if (result < 0) return " less than ";
   else if (result == 0) return " equal to ";
   else return " greater than ";
}

int main()
{
   // The first member function compares
   // two string_views
   string_view sv_A("CAB");
   string_view sv_B("CAB");
   cout << "sv_A is " << sv_A << endl;
   cout << "sv_B is " << sv_B << endl;
   int comp1 = sv_A.compare(sv_B);
   cout << "sv_A is" << to_alpha(comp1) << "sv_B.\n";

   // The second member function compares part of
   // an operand string_view to another string_view
   string_view sv_C("AACAB");
   string_view sv_D("CAB");
   cout << "sv_C is: " << sv_C << endl;
   cout << "sv_D is: " << sv_D << endl;
   int comp2a = sv_C.compare(2, 3, sv_D);
   cout << "The last three characters of sv_C are" 
       << to_alpha(comp2a) << "sv_D.\n";

   int comp2b = sv_C.compare(0, 3, sv_D);
   cout << "The first three characters of sv_C are" 
       << to_alpha(comp2b) << "sv_D.\n";

   // The third member function compares part of
   // an operand string_view to part of another string_view
   string_view sv_E("AACAB");
   string_view sv_F("DCABD");
   cout << "sv_E: " << sv_E << endl;
   cout << "sv_F is: " << sv_F << endl;
   int comp3a = sv_E.compare(2, 3, sv_F, 1, 3);
   cout << "The three characters from position 2 of sv_E are"
       << to_alpha(comp3a) 
       << "the 3 characters of sv_F from position 1.\n";

   // The fourth member function compares
   // an operand string_view to a C string
   string_view sv_G("ABC");
   const char* cs_A = "DEF";
   cout << "sv_G is: " << sv_G << endl;
   cout << "cs_A is: " << cs_A << endl;
   int comp4a = sv_G.compare(cs_A);
   cout << "sv_G is" << to_alpha(comp4a) << "cs_A.\n";

   // The fifth member function compares part of
   // an operand string_view to a C string
   string_view sv_H("AACAB");
   const char* cs_B = "CAB";
   cout << "sv_H is: " << sv_H << endl;
   cout << "cs_B is: " << cs_B << endl;
   int comp5a = sv_H.compare(2, 3, cs_B);
   cout << "The last three characters of sv_H are"
      << to_alpha(comp5a) << "cs_B.\n";

   // The sixth member function compares part of
   // an operand string_view to part of an equal length of
   // a C string
   string_view sv_I("AACAB");
   const char* cs_C = "ACAB";
   cout << "sv_I is: " << sv_I << endl;
   cout << "cs_C: " << cs_C << endl;
   int comp6a = sv_I.compare(1, 3, cs_C, 3);
   cout << "The 3 characters from position 1 of sv_I are"
      << to_alpha(comp6a) << "the first 3 characters of cs_C.\n";
}
```

```Output
sv_A is CAB
sv_B is CAB
sv_A is equal to sv_B.
sv_C is: AACAB
sv_D is: CAB
The last three characters of sv_C are equal to sv_D.
The first three characters of sv_C are less than sv_D.
sv_E: AACAB
sv_F is: DCABD
The three characters from position 2 of sv_E are equal to the 3 characters of sv_F from position 1.
sv_G is: ABC
cs_A is: DEF
sv_G is less than cs_A.
sv_H is: AACAB
cs_B is: CAB
The last three characters of sv_H are equal to cs_B.
sv_I is: AACAB
cs_C: ACAB
The 3 characters from position 1 of sv_I are equal to the first 3 characters of cs_C.
```

## <a name="copy"></a>  basic_string_view::copy

Copia no máximo um número especificado de caracteres de uma posição indexada em um string_view de origem para uma matriz de caracteres de destino. É recomendável que você use a função segura [basic_string_view:: _Copy_s](#_copy_s) em vez disso.

```cpp
size_type copy(charT* ptr, size_type count, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*PTR*\
A matriz de caracteres de destino à qual os elementos devem ser copiados.

*contar*\
O número de caracteres a serem copiados, no máximo, do string_view de origem.

*desvio*\
A posição inicial no string_view de origem do qual as cópias devem ser feitas.

### <a name="return-value"></a>Valor de retorno

O número de caracteres realmente copiados.

### <a name="remarks"></a>Comentários

Um caractere nulo não é acrescentado ao final da cópia.

## <a name="_copy_s"></a>basic_string_view::_Copy_s

Proteger a função de cópia CRT a ser usada em vez da [cópia](#copy).

```cpp
size_type _Copy_s(
    value_type* dest,
    size_type dest_size,
    size_type count,
    size_type _Off = 0) const;
```

### <a name="parameters"></a>Parâmetros

*dest*\
A matriz de caracteres de destino à qual os elementos devem ser copiados.

*dest_size*\
O tamanho do *dest*.

_ *Conte* o número de caracteres a serem copiados, no máximo, da cadeia de caracteres de origem.

*_Off*\
A posição inicial na cadeia de caracteres de origem da qual as cópias devem ser feitas.

### <a name="return-value"></a>Valor de retorno

O número de caracteres realmente copiados.

### <a name="remarks"></a>Comentários

Um caractere nulo não é acrescentado ao final da cópia.

 Para obter mais informações, consulte [c-Runtime-Library/Security-Features-in-the-CRT](../c-runtime-library/security-features-in-the-crt.md).

## <a name="crbegin"></a>  basic_string_view::crbegin

Retorna um const_reverse_iterator que aborda o primeiro elemento em um string_view invertido.

```cpp
constexpr const_reverse_iterator crbegin() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um const_reverse_iterator que aborda o primeiro elemento em um string_view invertido. 

## <a name="crend"></a>  basic_string_view::crend

O mesmo que [rend](#rend). 

```cpp
constexpr const_reverse_iterator crend() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Retorna um const_reverse_iterator que aborda um após o final de um string_view invertido.

## <a name="data"></a>  basic_string_view::data

Retorna um ponteiro não proprietário bruto para a sequência de caracteres const do objeto que foi usado para construir o string_view.

```cpp
constexpr value_type *data() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para const para o primeiro elemento da sequência de caracteres.

### <a name="remarks"></a>Comentários

O ponteiro não pode modificar os caracteres.

Uma sequência de caracteres string_view não é necessariamente terminada em nulo. O tipo de retorno `data` para não é uma cadeia de caracteres C válida, pois nenhum caractere nulo é acrescentado. O caractere nulo ' \ 0 ' não tem um significado especial em um objeto do tipo string_view e pode ser parte do objeto string_view, assim como qualquer outro caractere.

## <a name="empty"></a>  basic_string_view::empty

Testa se o string_view contém caracteres ou não.

```cpp
constexpr bool empty() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

**true** se o objeto string_view não contiver nenhum caractere; **false** se tiver pelo menos um caractere.

### <a name="remarks"></a>Comentários

A função de membro é equivalente a [size](#size)() = = 0.

## <a name="end"></a>  basic_string_view::end

Retorna um const_iterator de acesso aleatório que aponta para um passado para o último elemento.

```cpp
constexpr const_iterator end() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Retorna um const_iterator de acesso aleatório que aponta para um passado para o último elemento.

### <a name="remarks"></a>Comentários

`end`é usado para testar se um const_iterator atingiu o fim de seu string_view. O valor retornado por `end` não deve ser desreferenciado.

## <a name="find"></a>  basic_string_view::find

Pesquisa um string_view em uma direção de encaminhamento para a primeira ocorrência de um caractere ou Subcadeia de caracteres que corresponde a uma sequência especificada de caractere (s).

```cpp
constexpr size_type find(basic_string_view str, size_type offset = 0) const noexcept;
constexpr size_type find(charT chVal, size_type offset = 0) const noexcept;
constexpr size_type find(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find(const charT* ptr, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*Str*\
O string_view para o qual a função de membro deve ser pesquisada.

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*desvio*\
Índice no qual a pesquisa deve começar.

*PTR*\
A cadeia de caracteres C para a qual a função de membro deve ser pesquisada.

*contar*\
O número de caracteres em *PTR*, contando a frente do primeiro caractere.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.

## <a name="find_first_not_of"></a>  basic_string_view::find_first_not_of

Pesquisa o primeiro caractere que não é um elemento de um objeto de cadeia de caracteres string_view ou conversível especificado.

```cpp
constexpr size_type find_first_not_of(basic_string_view str, size_type offset = 0) const noexcept;
constexpr size_type find_first_not_of(charT chVal, size_type offset = 0) const noexcept;
constexpr size_type find_first_not_of(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find_first_not_of(const charT* ptr, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*Str*\
O string_view para o qual a função de membro deve ser pesquisada.

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*desvio*\
Índice no qual a pesquisa deve começar.

*PTR*\
A cadeia de caracteres C para a qual a função de membro deve ser pesquisada.

*contar*\
O número de caracteres, contando a frente do primeiro caractere, na cadeia de caracteres C para a qual a função de membro deve pesquisar.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.

## <a name="find_first_of"></a>  basic_string_view::find_first_of

Pesquisa o primeiro caractere que corresponde a qualquer elemento de um string_view especificado.

```cpp
constexpr size_type find_first_of(basic_string_view str, size_type offset = 0) const noexcept;
constexpr size_type find_first_of(charT chVal, size_type offset = 0) const noexcept;
constexpr size_type find_first_of(const charT* str, size_type offset, size_type count) const;
constexpr size_type find_first_of(const charT* str, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*desvio*\
Índice no qual a pesquisa deve começar.

*PTR*\
A cadeia de caracteres C para a qual a função de membro deve ser pesquisada.

*contar*\
O número de caracteres, contando a frente do primeiro caractere, na cadeia de caracteres C para a qual a função de membro deve pesquisar.

*Str*\
O string_view para o qual a função de membro deve ser pesquisada.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.

## <a name="find_last_not_of"></a>  basic_string_view::find_last_not_of

Procura o último caractere que não seja qualquer elemento de um string_view especificado.

```cpp
constexpr size_type find_last_not_of(basic_string_view str, size_type offset = npos) const noexcept;
constexpr size_type find_last_not_of(charT chVal, size_type offset = npos) const noexcept;
constexpr size_type find_last_not_of(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find_last_not_of(const charT* ptr, size_type offset = npos) const;
```

### <a name="parameters"></a>Parâmetros

*Str*\
O string_view para o qual a função de membro deve ser pesquisada.

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*desvio*\
Índice no qual a pesquisa deve ser concluída.

*PTR*\
A cadeia de caracteres C para a qual a função de membro deve ser pesquisada.

*contar*\
O número de caracteres, contando a frente do primeiro caractere, em *PTR*.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `string_view::npos`.

## <a name="find_last_of"></a>  basic_string_view::find_last_of

Pesquisa o último caractere que corresponde a qualquer elemento de um string_view especificado.

```cpp
constexpr size_type find_last_of(basic_string_view str, size_type offset = npos) const noexcept;
constexpr size_type find_last_of(charT chVal, size_type offset = npos) const noexcept;
constexpr size_type find_last_of(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find_last_of(const charT* ptr, size_type offset = npos) const;
```

### <a name="parameters"></a>Parâmetros

*Str*\
O string_view para o qual a função de membro deve ser pesquisada.

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*desvio*\
Índice no qual a pesquisa deve ser concluída.

*PTR*\
A cadeia de caracteres C para a qual a função de membro deve ser pesquisada.

*contar*\
O número de caracteres, contando a frente do primeiro caractere, na cadeia de caracteres C para a qual a função de membro deve pesquisar.

### <a name="return-value"></a>Valor de retorno

O índice do último caractere da subsequência pesquisada quando houver êxito, caso contrário, `npos`.

## <a name="front"></a>  basic_string_view::front

Retorna um const_reference para o primeiro elemento.

```cpp
constexpr const_reference front() const;
```

### <a name="return-value"></a>Valor de retorno

Um const_reference para o primeiro elemento.

### <a name="remarks"></a>Comentários

Gera uma exceção se o string_view estiver vazio.

## <a name="length"></a>basic_string_view:: comprimento

Retorna o número atual de elementos.

```cpp
constexpr size_type length() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro é igual a [size](#size).

## <a name="max_size"></a>  basic_string_view::max_size

Retorna o número máximo de caracteres que um string_view pode conter.

```cpp
constexpr size_type max_size() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

O número máximo de caracteres que um string_view pode conter.

### <a name="remarks"></a>Comentários

Uma exceção do tipo [length_error](../standard-library/length-error-class.md) é gerada quando uma operação produz um string_view com um comprimento maior que `max_size()`.

## <a name="op_eq"></a>  basic_string_view::operator=

Atribui um objeto de cadeia de caracteres string_view ou conversível a outro string_view.

```cpp
constexpr basic_string_view& operator=(const basic_string_view&) noexcept = default;
```
### <a name="example"></a>Exemplo

```cpp
   string_view s = "Hello";
   string_view s2 = s;
```
## <a name="op_at"></a>  basic_string_view::operator[]

Fornece um const_reference para o caractere com um índice especificado.

```cpp
constexpr const_reference operator[](size_type offset) const;
```

### <a name="parameters"></a>Parâmetros

*desvio*\
O índice do elemento a ser referenciado.

### <a name="return-value"></a>Valor de retorno

Um const_reference para o caractere na posição especificada pelo índice de parâmetro.

### <a name="remarks"></a>Comentários

O primeiro elemento tem um índice de zero e os seguintes elementos são indexados consecutivamente pelos inteiros positivos, de modo que um string_view de comprimento *n* tenha um elemento *n*-ésimo indexado pelo número *n* -1.

`operator[]`é mais rápido do que a função de membro [em](#at) para fornecer acesso de leitura aos elementos de um string_view.

`operator[]`não verifica se o índice passado como um argumento é válido. Um índice inválido foi passado `operator[]` para resultados em um comportamento indefinido.

A referência retornada poderá ser invalidada se os dados de cadeia de caracteres subjacentes forem modificados ou excluídos pelo objeto proprietário.

Ao compilar com [ \_o\_nível\_de depuração](../standard-library/iterator-debug-level.md) do iterador definido como 1 ou 2, ocorrerá um erro de tempo de execução se você tentar acessar um elemento fora dos limites do string_view. Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="rbegin"></a>  basic_string_view::rbegin

Retorna um iterador const para o primeiro elemento em um string_view invertido.

```cpp
constexpr const_reverse_iterator rbegin() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Retorna um iterador de acesso aleatório para o primeiro elemento em um string_view invertido, abordando o que seria o último elemento no string_view não invertido correspondente.

### <a name="remarks"></a>Comentários

`rbegin`é usado com um string_view invertido da mesma forma que [begin](#begin) é usado com um string_view. `rbegin`pode ser usado para inicializar uma iteração retroativa.

## <a name="remove_prefix"></a> basic_string_view::remove_prefix

Move o ponteiro para frente pelo número especificado de elementos.

```cpp
constexpr void remove_prefix(size_type n);
```

### <a name="remarks"></a>Comentários

Deixa os dados subjacentes inalterados. Move o ponteiro string_view para frente por n elementos e define o `size` membro de dados privados para size-n.

## <a name="remove_suffix"></a> basic_string_view::remove_suffix

Reduz o tamanho da exibição pelo número especificado de elementos, começando da parte posterior.

```cpp
constexpr void remove_suffix(size_type n);
```

### <a name="remarks"></a>Comentários

Deixa os dados subjacentes e o ponteiro para ele não alterado. Define o membro `size` de dados privados como size-n.

## <a name="rend"></a>  basic_string_view::rend

Retorna um iterador const que aponta para um passado o último elemento em um string_view invertido.

```cpp
constexpr reverse_iterator rend() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um iterador de acesso aleatório inverso const que aponta para um passado o último elemento em um string_view invertido.

### <a name="remarks"></a>Comentários

`rend`é usado com uma string_view invertida da mesma forma que [end](#end) é usada com um string_view. `rend`pode ser usado para testar se um iterador reverso atingiu o final de seu string_view. O valor retornado por `rend` não deve ser desreferenciado.

## <a name="rfind"></a>  basic_string_view::rfind

Pesquisa um string_view em um inverso para uma subcadeia de caracteres que corresponde a uma sequência especificada de personagens.

```cpp
constexpr size_type rfind(basic_string_view str, size_type offset = npos) const noexcept;
constexpr size_type rfind(charT chVal, size_type offset = npos) const noexcept;
constexpr size_type rfind(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type rfind(const charT* ptr, size_type offset = npos) const;
```

### <a name="parameters"></a>Parâmetros

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*desvio*\
Índice no qual a pesquisa deve começar.

*PTR*\
A cadeia de caracteres C para a qual a função de membro deve ser pesquisada.

*contar*\
O número de caracteres, contando a frente do primeiro caractere, na cadeia de caracteres C para a qual a função de membro deve pesquisar.

*Str*\
O string_view para o qual a função de membro deve ser pesquisada.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro caractere da subcadeia de caracteres quando bem-sucedido; caso `npos`contrário.

## <a name="size"></a>  basic_string_view::size

Retorna o número de elementos no string_view.

```cpp
constexpr size_type size() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

O comprimento do string_view.

### <a name="remarks"></a>Comentários

Um string_view pode modificar seu comprimento, por exemplo, `remove_prefix` por `remove_suffix`e. Como isso não modifica os dados de cadeia de caracteres subjacentes, o tamanho de um string_view não é necessariamente o tamanho dos dados subjacentes.

## <a name="substr"></a>  basic_string_view::substr

Retorna um string_view que representa (no máximo) o número especificado de caracteres de uma posição especificada.

```cpp
constexpr basic_string_view substr(size_type offset = 0, size_type count = npos) const;
```

### <a name="parameters"></a>Parâmetros

*desvio*\
Um índice que localiza o elemento na posição a partir da qual a cópia é feita, com um valor padrão de 0.

*contar*\
O número de caracteres a serem incluídos na Subcadeia, se estiverem presentes.

### <a name="return-value"></a>Valor de retorno

Um objeto string_view que representa a subsequência especificada de elementos.

## <a name="swap"></a>  basic_string_view::swap

Troca duas string_views, em outras palavras, os ponteiros para os dados de cadeia de caracteres subjacentes e os valores de tamanho.

```cpp
constexpr void swap(basic_string_view& sv) noexcept;
```

### <a name="parameters"></a>Parâmetros

*SV*\
A origem string_view cujos valores de ponteiro e tamanho devem ser trocados com o do string_view de destino.

## <a name="see-also"></a>Consulte também

[\<> string_view](../standard-library/string-view.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
