---
title: classe basic_string_view
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
ms.openlocfilehash: ac65dca931f821c717e9c081c8d3479fd0b3bb0e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364901"
---
# <a name="basic_string_view-class"></a>classe basic_string_view

O modelo `basic_string_view<charT>` de classe foi adicionado em C++17 para servir como uma maneira segura e eficiente para uma função aceitar vários tipos de strings não relacionados sem que a função tenha que ser templatizada nesses tipos. A classe possui um ponteiro que não possui uma seqüência contígua de dados de caracteres e um comprimento que especifica o número de caracteres na seqüência. Nenhuma suposição é feita em relação a se a seqüência é nula.

A biblioteca padrão define várias especializações com base no tipo dos elementos:

- `string_view`
- `wstring_view`
- `u16string_view`
- `u32string_view`

Neste documento, o termo "string_view" refere-se geralmente a qualquer um desses typedefs.

Um string_view descreve a interface comum mínima necessária para ler dados de seqüência. Ele fornece acesso const aos dados subjacentes; não faz cópias (exceto para a `copy` função). Os dados podem ou não conter valores nulos ('\0') em qualquer posição. Um string_view não tem controle sobre a vida do objeto. É responsabilidade do chamador garantir que os dados de seqüência subjacentes sejam válidos.

Uma função que aceita um parâmetro de tipo string_view pode ser feita para trabalhar com qualquer tipo de string, sem fazer a função em um modelo, ou restringir a função a um determinado subconjunto de tipos de strings. O único requisito é que exista uma conversão implícita do tipo string para string_view. Todos os tipos de stringpadrão são implicitamente conversíveis para um string_view que contém o mesmo tipo de elemento. Em outras `std::string` palavras, um `string_view` é conversível para um mas não para um `wstring_view`.

O exemplo a seguir mostra `f` uma função não-modelo que leva um parâmetro do tipo `wstring_view`. Pode ser chamado com argumentos `wchar_t*`do `winrt::hstring`tipo, `std::wstring`e .

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
O tipo de caracteres armazenados no string_view. A Biblioteca Padrão C++ fornece os seguintes tipos para especializações deste modelo.

- [string_view](../standard-library/string-view-typedefs.md#string_view) para elementos de **tipo char**
- [wstring_view,](../standard-library/string-view-typedefs.md#wstring_view)por **wchar_t**
- [u16string_view](../standard-library/string-view-typedefs.md#u16string_view) para **char16_t**
- [u32string_view](../standard-library/string-view-typedefs.md#u32string_view) para **char32_t.**

*Traços*\
Os padrões [para char_traits](char-traits-struct.md)<*charType*>.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_string_view](#basic_string_view)|Constrói uma string_view que está vazia ou então aponta para todos ou parte dos dados de algum outro objeto de seqüência, ou para uma matriz de caracteres estilo C.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|**const_iterator**|Um tempoterizador de acesso aleatório que pode ler elementos **const.**|
|**const_pointer**|`using const_pointer = const value_type*;`|
|**const_reference**|`using const_reference = const value_type&;`|
|**const_reverse_iterator**|`using const_reverse_iterator = std::reverse_iterator<const_iterator>;`|
|**difference_type**|`using difference_type = ptrdiff_t;`|
|**Iterador**|`using iterator = const_iterator;`|
|**npos**|`static constexpr size_type npos = size_type(-1);`|
|**ponteiro**|`using pointer = value_type*;`|
|**Referência**|`using reference = value_type&;`|
|**reverse_iterator**|`using reverse_iterator = const_reverse_iterator;`|
|**size_type**|`using size_type = size_t;`|
|**traits_type**|`using traits_type = Traits;`|
|**Value_type**|`using value_type = CharType;`|

### <a name="member-operators"></a>Operadores membros

|Operador|Descrição|
|-|-|
|[operador=](#op_eq)|Atribui um objeto de corda string_view ou conversível a outro string_view.|
|[Operador\[\]](#op_at)|Retorna o elemento no índice especificado.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Em](#at)|Retorna uma const_reference ao elemento em um local especificado.|
|[Voltar](#back)|Retorna um const_reference para o último elemento.|
|[Começar](#begin)|Retorna um temporterizador const abordando o primeiro elemento. (string_views são imutáveis.)|
|[cbegin](#cbegin)|O mesmo [que começar.](#begin)|
|[cend](#cend)|Retorna um temporterizador const que aponta para um passado o último elemento.|
|[Cópia](#copy)|Copia no máximo um número especificado de caracteres de uma posição indexada em uma fonte string_view para uma matriz de caracteres de destino. (Não recomendado. Use _Copy_s em vez disso.)|
|[_Copy_s](#_copy_s)|Fixar a função de cópia CRT.|
|[Comparar](#compare)|Compara um string_view com um string_view especificado para determinar se são iguais ou se um é lexicograficamente menor que o outro.|
|[crbegin](#crbegin)|O mesmo [que rbegin.](#rbegin)|
|[crend](#crend)|O mesmo [que rend.](#rend)|
|[dados](#data)|Retorna um ponteiro bruto que não possui para a seqüência de caracteres.|
|[Vazio](#empty)|Testa se o string_view contém caracteres.|
|[end](#end)|O mesmo [que cend.](#cend)|
|[Encontrar](#find)|Pesquisa em uma direção para a frente para a primeira ocorrência de uma substring que corresponde a uma seqüência especificada de caracteres.|
|[find_first_not_of](#find_first_not_of)|Procura o primeiro caractere que não seja qualquer elemento de um objeto de cadeia de cadeia string_view ou conversível especificado.|
|[find_first_of](#find_first_of)|Procura o primeiro caractere que corresponda a qualquer elemento de um objeto de cadeia string_view ou conversível especificado.|
|[find_last_not_of](#find_last_not_of)|Procura o último caractere que não seja qualquer elemento de um objeto de cadeia de cadeia string_view ou conversível especificado.|
|[find_last_of](#find_last_of)|Procura o último caractere que é um elemento de um objeto de cadeia de string_view ou conversível especificado.|
|[Frente](#front)|Retorna um const_reference ao primeiro elemento.|
|[length](#length)|Retorna o número atual de elementos.|
|[Max_size](#max_size)|Retorna o número máximo de caracteres que um string_view poderia conter.|
|[rbegin](#rbegin)|Retorna um iterator const que aborda o primeiro elemento em um string_view invertido.|
|[remove_prefix](#remove_prefix)|Move o ponteiro para a frente pelo número especificado de elementos.|
|[remove_suffix](#remove_suffix)|Reduz o tamanho da exibição pelo número especificado de elementos a partir da parte de trás.|
|[rend](#rend)|Retorna um temporterizador const que aponta para um passado o último elemento em um string_view invertido.|
|[rfind](#rfind)|Pesquisa um string_view ao contrário para a primeira ocorrência de uma substring que corresponde a uma seqüência especificada de caracteres.|
|[Tamanho](#size)|Retorna o número atual de elementos.|
|[substr](#substr)|Retorna uma substring de um comprimento especificado a partir de um índice especificado.|
|[Trocar](#swap)|Troque o conteúdo de dois string_views.|

## <a name="remarks"></a>Comentários

Se for solicitado que uma função gere uma sequência mais longa que os elementos [max_size](#max_size), a função relatará um erro de comprimento, gerando um objeto do tipo [length_error](../standard-library/length-error-class.md).

## <a name="requirements"></a>Requisitos

[dst:c++17](../build/reference/std-specify-language-standard-version.md) ou posterior

**Cabeçalho:** \<string_view>

**Namespace:** std

## <a name="basic_string_viewat"></a><a name="at"></a>basic_string_view::at

Retorna um const_reference ao caractere no índice baseado em 0 especificado.

```cpp
constexpr const_reference at(size_type offset) const;
```

### <a name="parameters"></a>Parâmetros

*Deslocamento*\
O índice do elemento a ser referenciado.

### <a name="return-value"></a>Valor retornado

Um const_reference ao caractere na posição especificada pelo índice de parâmetros.

### <a name="remarks"></a>Comentários

O primeiro elemento tem um índice de zero e os seguintes elementos são indexados consecutivamente pelos inteiros positivos, de modo que um string_view de comprimento *n* tem *um*n th elemento indexado pelo número n *-* 1. **em** lança uma exceção para índices inválidos, ao contrário do [operador\[](#op_at).

Em geral, recomendamos que **em** `std::vector` seqüências como e string_view nunca deve ser usado. Um índice inválido passado para uma seqüência é um erro lógico que deve ser descoberto e corrigido durante o desenvolvimento. Se um programa não está absolutamente certo de que seus índices são válidos, ele deve testá-los, não chamá-los e confiar em exceções para se defender contra a programação descuidada.

Consulte [basic_string_view::operador\[ ](#op_at) para obter mais informações.

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

## <a name="basic_string_viewback"></a><a name="back"></a>basic_string_view:de volta

Retorna um const_reference para o último elemento.

```cpp
constexpr const_reference back() const;
```

### <a name="return-value"></a>Valor retornado

Uma const_reference ao último elemento do string_view.

### <a name="remarks"></a>Comentários

Abre uma exceção se a string_view estiver vazia.

Tenha em mente que depois que uma `remove_suffix`string_view é modificada, por exemplo, chamando, então o elemento retornado por essa função não é mais o último elemento nos dados subjacentes.

### <a name="example"></a>Exemplo

Uma string_view que é construída com uma seqüência de strings C `back` literal não inclui o nulo final e, portanto, no exemplo seguinte retorna 'p' e não '\0'.

```cpp
char c[] = "Help"; // char[5]
string_view sv{ c };
cout << sv.size(); // size() == 4
cout << sv.back() << endl; // p
```

Os nulos incorporados são tratados como qualquer outro caractere:

```cpp
string_view e = "embedded\0nulls"sv;
cout << boolalpha << (e.back() == 's'); // true
```

## <a name="basic_string_viewbasic_string_view"></a><a name="basic_string_view"></a>basic_string_view:basic_string_view

Constrói uma string_view.

```cpp
constexpr basic_string_view() noexcept;
constexpr basic_string_view(const basic_string_view&) noexcept = default;
constexpr basic_string_view(const charT* str);
constexpr basic_string_view(const charT* str, size_type len);
```

### <a name="parameters"></a>Parâmetros

*Str*\
O ponteiro para os valores do caractere.

*Len*\
O número de caracteres a serem incluemos na exibição.

## <a name="remarks"></a>Comentários

Os construtores com um parâmetro charT* assumem que a entrada é nula, mas o nulo final não está incluído no string_view.

Você também pode construir um string_view com um literal. Consulte [o operador"sv](string-view-operators.md#op_sv).

## <a name="basic_string_viewbegin"></a><a name="begin"></a>basic_string_view:begin

O mesmo [que cbegin](#cbegin).

```cpp
constexpr const_iterator begin() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Retorna um const_iterator abordando o primeiro elemento.

## <a name="basic_string_viewcbegin"></a><a name="cbegin"></a>basic_string_view::cbegin

Retorna um const_iterator que aborda o primeiro elemento no intervalo.

```cpp
constexpr const_iterator cbegin() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um ativador de acesso aleatório **const** que aponta para o primeiro elemento da faixa, ou o local `cbegin() == cend()`logo após o fim de uma faixa vazia (para um intervalo vazio, ).

## <a name="basic_string_viewcend"></a><a name="cend"></a>basic_string_view:cend

Retorna um const_iterator que aborda o local logo após o último elemento em uma faixa.

```cpp
constexpr const_iterator cend() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um **ativador** de acesso aleatório que aponta para além do fim do intervalo.

### <a name="remarks"></a>Comentários

O valor retornado por `cend` não deve ser desreferenciado.

## <a name="basic_string_viewcompare"></a><a name="compare"></a>basic_string_view::compare

Realiza uma comparação sensível ao caso com um string_view especificado (ou um tipo de string conversível) para determinar se os dois objetos são iguais ou se um é lexicograficamente menor que o outro. O [ \<string_view> operadores](string-view-operators.md) usam essa função de membro para realizar comparações.

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
O string_view que deve ser comparado com este string_view.

*Pos*\
O índice deste string_view no qual começa a comparação.

*num*\
O número máximo de caracteres deste string_view a ser comparado.

*num2*\
O número máximo de caracteres do *strv* a ser comparado.

*Deslocamento*\
O índice de *strv* no qual a comparação começa.

*Ptr*\
A seqüência C a ser comparada a este string_view.

### <a name="return-value"></a>Valor retornado

Um valor negativo se este string_view for menor que *strv* ou *ptr;* zero se as duas seqüências de caracteres forem iguais; ou um valor positivo se este string_view for maior que *strv* ou *ptr*.

### <a name="remarks"></a>Comentários

As `compare` funções do membro realizam uma comparação sensível ao caso de toda ou parte de cada seqüência de caracteres.

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

## <a name="basic_string_viewcopy"></a><a name="copy"></a>basic_string_view::cópia

Copia no máximo um número especificado de caracteres de uma posição indexada em uma fonte string_view para uma matriz de caracteres de destino. Recomendamos que você use a função segura [basic_string_view:_Copy_s](#_copy_s) em vez disso.

```cpp
size_type copy(charT* ptr, size_type count, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*Ptr*\
A matriz de caracteres de destino à qual os elementos devem ser copiados.

*Contar*\
O número de caracteres a serem copiados, no máximo, da fonte string_view.

*Deslocamento*\
A posição inicial na fonte string_view a partir da qual as cópias devem ser feitas.

### <a name="return-value"></a>Valor retornado

O número de caracteres realmente copiados.

### <a name="remarks"></a>Comentários

Um caractere nulo não é acrescentado ao final da cópia.

## <a name="basic_string_view_copy_s"></a><a name="_copy_s"></a>basic_string_view:_Copy_s

A função de cópia CRT segura para ser usada em vez de [copiar](#copy).

```cpp
size_type _Copy_s(
    value_type* dest,
    size_type dest_size,
    size_type count,
    size_type _Off = 0) const;
```

### <a name="parameters"></a>Parâmetros

*Dest*\
A matriz de caracteres de destino à qual os elementos devem ser copiados.

*dest_size*\
O tamanho *do dest.*

_ *Conte* O número de caracteres a serem copiados, no máximo, da seqüência de caracteres de origem.

*_Off*\
A posição inicial na cadeia de caracteres de origem da qual as cópias devem ser feitas.

### <a name="return-value"></a>Valor retornado

O número de caracteres realmente copiados.

### <a name="remarks"></a>Comentários

Um caractere nulo não é acrescentado ao final da cópia.

Para obter mais informações, consulte [c-runtime-library/security-features-in-the-crt](../c-runtime-library/security-features-in-the-crt.md).

## <a name="basic_string_viewcrbegin"></a><a name="crbegin"></a>basic_string_view::crbegin

Retorna um const_reverse_iterator que aborda o primeiro elemento em um string_view invertido.

```cpp
constexpr const_reverse_iterator crbegin() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um const_reverse_iterator que aborda o primeiro elemento em um string_view invertido.

## <a name="basic_string_viewcrend"></a><a name="crend"></a>basic_string_view::crend

O mesmo [que rend.](#rend)

```cpp
constexpr const_reverse_iterator crend() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Retorna um const_reverse_iterator que aborda um após o fim de uma string_view invertida.

## <a name="basic_string_viewdata"></a><a name="data"></a>basic_string_view::data

Retorna um ponteiro bruto não-possuidor para a seqüência de caracteres const do objeto que foi usado para construir o string_view.

```cpp
constexpr value_type *data() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro-para-const para o primeiro elemento da seqüência de caracteres.

### <a name="remarks"></a>Comentários

O ponteiro não pode modificar os caracteres.

Uma sequência de string_view personagens não é necessariamente nula. O tipo `data` de retorno para não é uma seqüência C válida, porque nenhum caractere nulo é anexado. O caractere nulo '\0' não tem significado especial em um objeto de tipo string_view e pode ser parte do objeto string_view como qualquer outro personagem.

## <a name="basic_string_viewempty"></a><a name="empty"></a>basic_string_view::vazio

Teste se o string_view contém caracteres ou não.

```cpp
constexpr bool empty() const noexcept;
```

### <a name="return-value"></a>Valor retornado

**verdade** se o objeto string_view não contiver caracteres; **falso** se ele tem pelo menos um caractere.

### <a name="remarks"></a>Comentários

A função do membro é equivalente ao [tamanho](#size)() == 0.

## <a name="basic_string_viewend"></a><a name="end"></a>basic_string_view::fim

Retorna um const_iterator de acesso aleatório que aponta para um passado o último elemento.

```cpp
constexpr const_iterator end() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Retorna um const_iterator de acesso aleatório que aponta para um passado o último elemento.

### <a name="remarks"></a>Comentários

`end`é usado para testar se uma const_iterator chegou ao fim de sua string_view. O valor retornado por `end` não deve ser desreferenciado.

## <a name="basic_string_viewfind"></a><a name="find"></a>basic_string_view::encontrar

Pesquisa um string_view em direção à frente para a primeira ocorrência de um caractere ou substringque corresponda a uma seqüência especificada de caracteres( s).

```cpp
constexpr size_type find(basic_string_view str, size_type offset = 0) const noexcept;
constexpr size_type find(charT chVal, size_type offset = 0) const noexcept;
constexpr size_type find(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find(const charT* ptr, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*Str*\
A string_view para a qual a função do membro é pesquisar.

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*Deslocamento*\
Índice no qual a busca deve começar.

*Ptr*\
A seqüência C para a qual a função do membro é procurar.

*Contar*\
O número de caracteres em *ptr*, contando para a frente a partir do primeiro caractere.

### <a name="return-value"></a>Valor retornado

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.

## <a name="basic_string_viewfind_first_not_of"></a><a name="find_first_not_of"></a>basic_string_view:find_first_not_of

Procura o primeiro caractere que não seja um elemento de um objeto de seqüência de string_view ou conversível especificado.

```cpp
constexpr size_type find_first_not_of(basic_string_view str, size_type offset = 0) const noexcept;
constexpr size_type find_first_not_of(charT chVal, size_type offset = 0) const noexcept;
constexpr size_type find_first_not_of(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find_first_not_of(const charT* ptr, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*Str*\
A string_view para a qual a função do membro é pesquisar.

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*Deslocamento*\
Índice no qual a busca deve começar.

*Ptr*\
A seqüência C para a qual a função do membro é procurar.

*Contar*\
O número de caracteres, contando para a frente a partir do primeiro caractere, na seqüência C para a qual a função do membro é pesquisar.

### <a name="return-value"></a>Valor retornado

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.

## <a name="basic_string_viewfind_first_of"></a><a name="find_first_of"></a>basic_string_view:find_first_of

Procura o primeiro caractere que corresponda a qualquer elemento de um string_view especificado.

```cpp
constexpr size_type find_first_of(basic_string_view str, size_type offset = 0) const noexcept;
constexpr size_type find_first_of(charT chVal, size_type offset = 0) const noexcept;
constexpr size_type find_first_of(const charT* str, size_type offset, size_type count) const;
constexpr size_type find_first_of(const charT* str, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*Deslocamento*\
Índice no qual a busca deve começar.

*Ptr*\
A seqüência C para a qual a função do membro é procurar.

*Contar*\
O número de caracteres, contando para a frente a partir do primeiro caractere, na seqüência C para a qual a função do membro é pesquisar.

*Str*\
A string_view para a qual a função do membro é pesquisar.

### <a name="return-value"></a>Valor retornado

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.

## <a name="basic_string_viewfind_last_not_of"></a><a name="find_last_not_of"></a>basic_string_view:find_last_not_of

Procura o último caractere que não seja qualquer elemento de um string_view especificado.

```cpp
constexpr size_type find_last_not_of(basic_string_view str, size_type offset = npos) const noexcept;
constexpr size_type find_last_not_of(charT chVal, size_type offset = npos) const noexcept;
constexpr size_type find_last_not_of(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find_last_not_of(const charT* ptr, size_type offset = npos) const;
```

### <a name="parameters"></a>Parâmetros

*Str*\
A string_view para a qual a função do membro é pesquisar.

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*Deslocamento*\
Índice em que a busca deve terminar.

*Ptr*\
A seqüência C para a qual a função do membro é procurar.

*Contar*\
O número de caracteres, contando para a frente desde o primeiro personagem, em *ptr*.

### <a name="return-value"></a>Valor retornado

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `string_view::npos`.

## <a name="basic_string_viewfind_last_of"></a><a name="find_last_of"></a>basic_string_view::find_last_of

Procura o último caractere que corresponda a qualquer elemento de uma string_view especificada.

```cpp
constexpr size_type find_last_of(basic_string_view str, size_type offset = npos) const noexcept;
constexpr size_type find_last_of(charT chVal, size_type offset = npos) const noexcept;
constexpr size_type find_last_of(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find_last_of(const charT* ptr, size_type offset = npos) const;
```

### <a name="parameters"></a>Parâmetros

*Str*\
A string_view para a qual a função do membro é pesquisar.

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*Deslocamento*\
Índice em que a busca deve terminar.

*Ptr*\
A seqüência C para a qual a função do membro é procurar.

*Contar*\
O número de caracteres, contando para a frente a partir do primeiro caractere, na seqüência C para a qual a função do membro é pesquisar.

### <a name="return-value"></a>Valor retornado

O índice do último caractere da subsequência pesquisada quando houver êxito, caso contrário, `npos`.

## <a name="basic_string_viewfront"></a><a name="front"></a>basic_string_view::frente

Retorna um const_reference ao primeiro elemento.

```cpp
constexpr const_reference front() const;
```

### <a name="return-value"></a>Valor retornado

Uma const_reference ao primeiro elemento.

### <a name="remarks"></a>Comentários

Abre uma exceção se a string_view estiver vazia.

## <a name="basic_string_viewlength"></a><a name="length"></a>basic_string_view::comprimento

Retorna o número atual de elementos.

```cpp
constexpr size_type length() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro é igual a [size](#size).

## <a name="basic_string_viewmax_size"></a><a name="max_size"></a>basic_string_view:max_size

Retorna o número máximo de caracteres que um string_view pode conter.

```cpp
constexpr size_type max_size() const noexcept;
```

### <a name="return-value"></a>Valor retornado

O número máximo de caracteres que um string_view pode conter.

### <a name="remarks"></a>Comentários

Uma exceção do tipo [length_error](../standard-library/length-error-class.md) é lançada quando uma `max_size()`operação produz um string_view com um comprimento maior que .

## <a name="basic_string_viewoperator"></a><a name="op_eq"></a>basic_string_view:operador=

Atribui um objeto de corda string_view ou conversível a outro string_view.

```cpp
constexpr basic_string_view& operator=(const basic_string_view&) noexcept = default;
```

### <a name="example"></a>Exemplo

```cpp
   string_view s = "Hello";
   string_view s2 = s;
```

## <a name="basic_string_viewoperator"></a><a name="op_at"></a>basic_string_view:operador[]

Fornece um const_reference ao caractere com um índice especificado.

```cpp
constexpr const_reference operator[](size_type offset) const;
```

### <a name="parameters"></a>Parâmetros

*Deslocamento*\
O índice do elemento a ser referenciado.

### <a name="return-value"></a>Valor retornado

Um const_reference ao caractere na posição especificada pelo índice de parâmetros.

### <a name="remarks"></a>Comentários

O primeiro elemento tem um índice de zero, e os seguintes elementos são indexados consecutivamente pelos inteiros positivos, de modo que um string_view de comprimento *n* tem *um*n th elemento indexado pelo número *n* - 1.

`operator[]`é mais rápido do que a [função](#at) do membro para fornecer acesso à leitura aos elementos de um string_view.

`operator[]`não verifica se o índice aprovado como argumento é válido. Um índice inválido `operator[]` passou para resultados em comportamento indefinido.

A referência retornada pode ser invalidada se os dados de seqüência subjacentes forem modificados ou excluídos pelo objeto próprio.

Ao compilar com [ \_\_o\_Nível de DEPURAÇÃO do ITERATOR](../standard-library/iterator-debug-level.md) definido como 1 ou 2, ocorrerá um erro de tempo de execução se você tentar acessar um elemento fora dos limites do string_view. Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="basic_string_viewrbegin"></a><a name="rbegin"></a>basic_string_view:rbegin

Retorna um temporterizador const para o primeiro elemento em um string_view invertido.

```cpp
constexpr const_reverse_iterator rbegin() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Retorna um ativador de acesso aleatório ao primeiro elemento em um string_view invertido, abordando qual seria o último elemento no string_view não invertido correspondente.

### <a name="remarks"></a>Comentários

`rbegin`é usado com um string_view invertido assim como [começar](#begin) é usado com um string_view. `rbegin`pode ser usado para inicializar uma iteração ao contrário.

## <a name="basic_string_viewremove_prefix"></a><a name="remove_prefix"></a>basic_string_view:remove_prefix

Move o ponteiro para a frente pelo número especificado de elementos.

```cpp
constexpr void remove_prefix(size_type n);
```

### <a name="remarks"></a>Comentários

Deixa os dados subjacentes inalterados. Move o ponteiro string_view para a `size` frente por n elementos e define o membro de dados privado para tamanho - n.

## <a name="basic_string_viewremove_suffix"></a><a name="remove_suffix"></a>basic_string_view:remove_suffix

Reduz o tamanho da exibição pelo número especificado de elementos a partir da parte de trás.

```cpp
constexpr void remove_suffix(size_type n);
```

### <a name="remarks"></a>Comentários

Deixa os dados subjacentes e o ponteiro inalterados. Define o `size` membro de dados privados como tamanho - n.

## <a name="basic_string_viewrend"></a><a name="rend"></a>basic_string_view::rend

Retorna um temporterizador const que aponta para um passado o último elemento em um string_view invertido.

```cpp
constexpr reverse_iterator rend() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um ativador de acesso aleatório reverso que aponta para um passado o último elemento em uma string_view invertida.

### <a name="remarks"></a>Comentários

`rend`é usado com um string_view invertido assim como [o fim](#end) é usado com um string_view. `rend`pode ser usado para testar se um iterador reverso chegou ao fim de sua string_view. O valor retornado por `rend` não deve ser desreferenciado.

## <a name="basic_string_viewrfind"></a><a name="rfind"></a>basic_string_view:rfind

Pesquisa um string_view ao contrário para uma substring que corresponde a uma seqüência especificada de caracteres.

```cpp
constexpr size_type rfind(basic_string_view str, size_type offset = npos) const noexcept;
constexpr size_type rfind(charT chVal, size_type offset = npos) const noexcept;
constexpr size_type rfind(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type rfind(const charT* ptr, size_type offset = npos) const;
```

### <a name="parameters"></a>Parâmetros

*chVal*\
O valor de caractere que a função membro deve pesquisar.

*Deslocamento*\
Índice no qual a busca deve começar.

*Ptr*\
A seqüência C para a qual a função do membro é procurar.

*Contar*\
O número de caracteres, contando para a frente a partir do primeiro caractere, na seqüência C para a qual a função do membro é pesquisar.

*Str*\
A string_view para a qual a função do membro é pesquisar.

### <a name="return-value"></a>Valor retornado

O índice do primeiro caractere da substring quando bem sucedido; caso `npos`contrário .

## <a name="basic_string_viewsize"></a><a name="size"></a>basic_string_view::tamanho

Retorna o número de elementos no string_view.

```cpp
constexpr size_type size() const noexcept;
```

### <a name="return-value"></a>Valor retornado

O comprimento do string_view.

### <a name="remarks"></a>Comentários

Um string_view pode modificar seu `remove_prefix` comprimento, por exemplo, por e `remove_suffix`. Como isso não modifica os dados de seqüência subjacentes, o tamanho de um string_view não é necessariamente o tamanho dos dados subjacentes.

## <a name="basic_string_viewsubstr"></a><a name="substr"></a>basic_string_view::substr

Retorna um string_view que representa (no máximo) o número especificado de caracteres de uma posição especificada.

```cpp
constexpr basic_string_view substr(size_type offset = 0, size_type count = npos) const;
```

### <a name="parameters"></a>Parâmetros

*Deslocamento*\
Um índice localizando o elemento na posição a partir da qual a cópia é feita, com um valor padrão de 0.

*Contar*\
O número de caracteres a serem incluemos na substring, se estiverem presentes.

### <a name="return-value"></a>Valor retornado

Um string_view objeto que representa a subseqüência especificada de elementos.

## <a name="basic_string_viewswap"></a><a name="swap"></a>basic_string_view::swap

Troca dois string_views, ou seja, os ponteiros para os dados de seqüência subjacentes e os valores de tamanho.

```cpp
constexpr void swap(basic_string_view& sv) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Sv*\
A fonte string_view cujos valores de ponteiro e tamanho devem ser trocados com o do destino string_view.

## <a name="see-also"></a>Confira também

[\<string_view>](../standard-library/string-view.md)\
[Segurança de threads na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
