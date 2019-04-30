---
title: Classe de basic_string_view
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
ms.openlocfilehash: 0ac5e3d528881f7b1caa0a1dcdae0161a6777e57
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346934"
---
# <a name="basicstringview-class"></a>Classe de basic_string_view

O modelo de classe `basic_string_view<charT>` foi adicionada no C++ 17 para servir como uma maneira segura e eficiente para uma função aceitar vários não relacionado a tipos de cadeia de caracteres sem a necessidade de ser transformado em modelo nesses tipos de função. A classe mantém um ponteiro não possui uma sequência contígua de dados de caractere e um comprimento que especifica o número de caracteres na sequência. Nenhuma suposição é feita em relação ao que se a sequência é terminada em nulo.

A biblioteca padrão define várias especializações com base no tipo dos elementos:

-  `string_view`
-  `wstring_view`
-  `u16string_view`
-  `u32string_view`

Neste documento, o termo "string_view" geralmente se refere a qualquer um desses typedefs.

Um string_view descreve a interface comum mínima necessária para ler dados de cadeia de caracteres. Ele fornece acesso constante aos dados subjacentes; ele faz nenhuma cópias (exceto para o `copy` função). Os dados podem ou não podem conter valores nulos ('\0') em qualquer posição. Um string_view não tem controle sobre a vida útil de objeto. É responsabilidade do chamador para garantir que os dados de cadeia de caracteres subjacente são válidos.

Uma função que aceita um parâmetro de tipo string_view pode ser feita para trabalhar com qualquer tipo em forma de cadeia de caracteres, sem tornar a função em um modelo, ou restringindo a função a um determinado subconjunto de tipos de cadeia de caracteres. O único requisito é que existe uma conversão implícita do tipo de cadeia de caracteres para string_view. Todos os tipos de cadeia de caracteres padrão são implicitamente conversíveis para um string_view que contém o mesmo tipo de elemento. Em outras palavras, uma `std::string` pode ser convertido em um `string_view` , mas não para um `wstring_view`.

O exemplo a seguir mostra uma função de não template `f` que usa um parâmetro do tipo `wstring_view`. Ele pode ser chamado com argumentos de tipo `std::wstring`, `wchar_t*`, e `winrt::hstring`.

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

*CharType*<br/>
O tipo de caracteres que são armazenadas em do string_view. O C++ biblioteca padrão fornece os seguintes typedefs para especializações do modelo.
- [string_view](../standard-library/string-view-typedefs.md#string_view) para elementos do tipo **char**
- [wstring_view](../standard-library/string-view-typedefs.md#wstring_view), para **wchar_t**
- [u16string_view](../standard-library/string-view-typedefs.md#u16string_view) para **char16_t**
- [u32string_view](../standard-library/string-view-typedefs.md#u32string_view) para **char32_t**.

*Características*<br/>
O padrão é [char_traits](char-traits-struct.md)<*CharType*>.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_string_view](#basic_string_view)|Constrói um string_view que está vazio ou então pontos para todo ou parte de dados de alguma outra cadeia de caracteres do objeto, ou para uma matriz de caracteres de estilo C.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|**const_iterator**|Iterador de acesso aleatório que pode ler **const** elementos.|
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
|[operator=](#op_eq)|Atribui um objeto de cadeia de caracteres string_view ou que possa ser convertido para outro string_view.|
|[operator\[\]](#op_at)|Retorna o elemento no índice especificado.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[at](#at)|Retorna um const_reference para o elemento em um local especificado.|
|[back](#back)|Retorna um const_reference ao último elemento.|
|[begin](#begin)|Retorna um iterador const que trata o primeiro elemento. (string_views são imutáveis.)|
|[cbegin](#cbegin)|Mesmo que [começar](#begin).|
|[cend](#cend)|Retorna um iterador const que aponta para logo após o último elemento.|
|[copy](#copy)|Copia no máximo um número especificado de caracteres de uma posição indexada em uma fonte string_view para uma matriz de caracteres de destino. (Não recomendado. Use copy_s.)|
|[_Copy_s](#_copy_s)|Função de cópia do CRT segura.|
|[compare](#compare)|Compara um string_view com um string_view especificado para determinar se eles forem iguais ou se uma é lexicograficamente menor do que o outro.|
|[crbegin](#crbegin)|Mesmo que [rbegin](#rbegin).|
|[crend](#crend)|Mesmo que [rend](#rend).|
|[data](#data)|Retorna um ponteiro bruto não proprietário para a sequência de caracteres.|
|[empty](#empty)|Testa se o string_view contém caracteres.|
|[end](#end)|Mesmo que [cend](#cend).|
|[find](#find)|Pesquisa em uma direção progressiva para a primeira ocorrência de uma subcadeia de caracteres que corresponde a uma sequência de caracteres especificada.|
|[find_first_not_of](#find_first_not_of)|Pesquisa o primeiro caractere que não seja um elemento de um objeto de cadeia de caracteres conversíveis ou string_view especificado.|
|[find_first_of](#find_first_of)|Pesquisa o primeiro caractere que corresponde a qualquer elemento de um objeto de cadeia de caracteres conversíveis ou string_view especificado.|
|[find_last_not_of](#find_last_not_of)|Pesquisa o último caractere que não seja um elemento de um objeto de cadeia de caracteres conversíveis ou string_view especificado.|
|[find_last_of](#find_last_of)|Pesquisa o último caractere que é um elemento de um objeto de cadeia de caracteres conversíveis ou string_view especificado.|
|[front](#front)|Retorna um const_reference para o primeiro elemento.|
|[length](#length)|Retorna o número atual de elementos.|
|[max_size](#max_size)|Retorna o número máximo de caracteres de que um string_view pode conter.|
|[rbegin](#rbegin)|Retorna um iterador const que trata o primeiro elemento em um string_view invertido.|
|[remove_prefix](#remove_prefix)|Move o ponteiro para a frente pelo número especificado de elementos.|
|[remove_suffix](#remove_suffix)|Reduz o tamanho da exibição, o número especificado de elementos, começando na parte de trás.|
|[rend](#rend)|Retorna um iterador const que aponta para logo após o último elemento em um string_view invertido.|
|[rfind](#rfind)|Pesquisa um string_view em ordem inversa para a primeira ocorrência de uma subcadeia de caracteres que corresponde a uma sequência de caracteres especificada.|
|[size](#size)|Retorna o número atual de elementos.|
|[substr](#substr)|Retorna uma subcadeia de caracteres de um comprimento especificado, começando em um índice especificado.|
|[swap](#swap)|Troca o conteúdo das duas string_views.|

## <a name="remarks"></a>Comentários

Se for solicitado que uma função gere uma sequência mais longa que os elementos [max_size](#max_size), a função relatará um erro de comprimento, gerando um objeto do tipo [length_error](../standard-library/length-error-class.md).

## <a name="requirements"></a>Requisitos

[/std: c + + 17](../build/reference/std-specify-language-standard-version.md) ou posterior

**Cabeçalho:** \<string_view >

**Namespace:** std

## <a name="at"></a>  basic_string_view::at

Retorna um const_reference para o caractere no índice especificado com base em 0.

```cpp
constexpr const_reference at(size_type offset) const;
```

### <a name="parameters"></a>Parâmetros

*deslocamento*<br/>
O índice do elemento a ser referenciado.

### <a name="return-value"></a>Valor de retorno

Um const_reference para o caractere na posição especificada pelo índice de parâmetro.

### <a name="remarks"></a>Comentários

O primeiro elemento tem um índice igual a zero e os elementos seguintes são indexados consecutivamente pelos inteiros positivos, para que um string_view de comprimento *n* tem um *n*º elemento indexado pelo número *n -* 1. **no** lança uma exceção para índices inválidos, ao contrário [operador\[\]](#op_at). 

Em geral, é recomendável **na** para sequências como `std::vector` e string_view nunca deve ser usada. Um índice inválido passado para uma sequência é um erro de lógica que deve ser descoberto e corrigido durante o desenvolvimento. Se um programa não é absolutamente certo de que seus índices forem válidos, ele deverá testá-los, não chamar at() e dependem de exceções para proteção contra descuidada programação.

Ver [basic_string_view::operator\[ \] ](#op_at) para obter mais informações.

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

Retorna um const_reference ao último elemento.

```cpp
constexpr const_reference back() const;
```

### <a name="return-value"></a>Valor de retorno

Um const_reference para o último elemento na string_view.

### <a name="remarks"></a>Comentários

Gera uma exceção se a string_view está vazio.

Tenha em mente que, depois que um string_view é modificado, por exemplo, chamando `remove_suffix`, em seguida, o elemento retornado por essa função não é o último elemento nos dados subjacentes.

### <a name="example"></a>Exemplo

Um string_view que é construído com um literal de cadeia de C não inclui o nulo de terminação e, portanto, no exemplo a seguir `back` retorna 'p' e não '\0'.

```cpp
char c[] = "Help"; // char[5]
string_view sv{ c };
cout << sv.size(); // size() == 4
cout << sv.back() << endl; // p 
```

Nulls inseridos são tratados como qualquer outro caractere:

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

*str*<br/>
O ponteiro para os valores de caractere.

*len*<br/>
O número de caracteres a serem incluídas na exibição.

## <a name="remarks"></a>Comentários

Os construtores com um parâmetro de gráfico * pressupõem que a entrada é terminada em nulo, mas o nulo de terminação não está incluído na string_view.

Também é possível construir um string_view com um literal. Ver [operador "" sv](string-view-operators.md#op_sv).

## <a name="begin"></a>  basic_string_view::begin

Mesmo que [cbegin](#cbegin).

```cpp
constexpr const_iterator begin() const noexcept;
```

### <a name="return-value"></a>Valor de retorno
Retorna um const_iterator que trata o primeiro elemento.

## <a name="cbegin"></a>  basic_string_view::cbegin

Retorna um const_iterator que trata o primeiro elemento no intervalo.

```cpp
constexpr const_iterator cbegin() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um **const** iterador de acesso aleatório que aponta para o primeiro elemento do intervalo ou o local logo após o final de um intervalo vazio (para um intervalo vazio, `cbegin() == cend()`).

## <a name="cend"></a>  basic_string_view::cend

Retorna um const_iterator que trata o local logo após o último elemento em um intervalo.

```cpp
constexpr const_iterator cend() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um **const** iterador de acesso aleatório que aponta para além do final do intervalo.

### <a name="remarks"></a>Comentários

O valor retornado por `cend` não deve ser desreferenciado.

## <a name="compare"></a> basic_string_view::compare

Executa uma comparação diferencia maiusculas de minúsculas, com um string_view especificado (ou um tipo de cadeia de caracteres conversíveis) para determinar se os dois objetos forem iguais ou se uma é lexicograficamente menor do que o outro. O [ \<string_view > operadores](string-view-operators.md) usar essa função de membro para executar comparações.

```cpp
constexpr int compare(basic_string_view strv) const noexcept;
constexpr int compare(size_type pos, size_type num, basic_string_view strv) const;
constexpr int compare(size_type pos, size_type num, basic_string_view strv, size_type offset, size_type num2) const;
constexpr int compare(const charT* ptr) const;
constexpr int compare(size_type pos, size_type num, const charT* ptr) const;
constexpr int compare(size_type pos, size_type num, const charT* ptr, size_type num2) const;
```

### <a name="parameters"></a>Parâmetros

*strv*<br/>
O que deve ser comparado com essa string_view string_view.

*pos*<br/>
O índice desse string_view em que a comparação começa.

*num*<br/>
O número máximo de caracteres desse string_view a ser comparado.

*num2*<br/>
O número máximo de caracteres a partir *strv* a ser comparado.

*deslocamento*<br/>
O índice da *strv* no qual a comparação começa.

*ptr*<br/>
A cadeia de caracteres do C a ser comparado com este string_view.

### <a name="return-value"></a>Valor de retorno

Um valor negativo se essa string_view é menor que *strv* ou *ptr*; zero se as sequências de caracteres de dois são iguais ou um valor positivo se este string_view for maior que *strv*ou *ptr*.

### <a name="remarks"></a>Comentários

O `compare` funções de membro realiza uma comparação diferencia maiusculas de minúsculas de todo ou parte de cada sequência de caracteres. 

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

Copia no máximo um número especificado de caracteres de uma posição indexada em uma fonte string_view para uma matriz de caracteres de destino. É recomendável que você use a função segura [basic_string_view::_Copy_s](#_copy_s) em vez disso.

```cpp
size_type copy(charT* ptr, size_type count, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*ptr*<br/>
A matriz de caracteres de destino à qual os elementos devem ser copiados.

*count*<br/>
O número de caracteres a ser copiado, no máximo, de string_view o código-fonte.

*deslocamento*<br/>
A posição de início a string_view de origem do qual as cópias devem ser feitas.

### <a name="return-value"></a>Valor de retorno

O número de caracteres realmente copiados.

### <a name="remarks"></a>Comentários

Um caractere nulo não é acrescentado ao final da cópia.

## <a name="_copy_s"></a>  basic_string_view::_Copy_s

Proteger a função de cópia do CRT para ser usado em vez de [cópia](#copy).

```cpp
size_type _Copy_s(
    value_type* dest,
    size_type dest_size,
    size_type count,
    size_type _Off = 0) const;
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
A matriz de caracteres de destino à qual os elementos devem ser copiados.

*dest_size*<br/>
O tamanho de *dest*.

_ *Contagem* o número de caracteres a ser copiado, no máximo, da cadeia de caracteres de origem.

*_Off*<br/>
A posição inicial na cadeia de caracteres de origem da qual as cópias devem ser feitas.

### <a name="return-value"></a>Valor de retorno

O número de caracteres realmente copiados.

### <a name="remarks"></a>Comentários

Um caractere nulo não é acrescentado ao final da cópia.

 Para obter mais informações, consulte [c-runtime-library/security-features-in-the-crt](../c-runtime-library/security-features-in-the-crt.md).

## <a name="crbegin"></a>  basic_string_view::crbegin

Retorna um const_reverse_iterator que trata o primeiro elemento em um string_view invertido.

```cpp
constexpr const_reverse_iterator crbegin() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um const_reverse_iterator que trata o primeiro elemento em um string_view invertido. 

## <a name="crend"></a>  basic_string_view::crend

Mesmo que [rend](#rend). 

```cpp
constexpr const_reverse_iterator crend() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Retorna um const_reverse_iterator que aborda a posição logo após o final de um string_view invertido.

## <a name="data"></a>  basic_string_view::data

Retorna um ponteiro bruto não proprietário para a sequência de caracteres const do objeto que foi usado para construir a string_view.

```cpp
constexpr value_type *data() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Uma ponteiro-para-const para o primeiro elemento da sequência de caracteres.

### <a name="remarks"></a>Comentários

O ponteiro não é possível modificar os caracteres.

Uma sequência de caracteres de string_view não é necessariamente de terminação nula. O tipo de retorno para `data` não é uma cadeia de caracteres do C válida, porque nenhum caractere nulo é acrescentado. O caractere nulo '\0' não tem nenhum significado especial em um objeto do tipo string_view e pode ser uma parte do objeto string_view assim como qualquer outro caractere.

## <a name="empty"></a>  basic_string_view::empty

Testa se o string_view contém caracteres ou não.

```cpp
constexpr bool empty() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

**True** se o objeto string_view não contém nenhum caractere; **falsos** se ele tiver pelo menos um caractere.

### <a name="remarks"></a>Comentários

A função de membro é equivalente a [tamanho](#size)() = = 0.

## <a name="end"></a>  basic_string_view::end

Retorna um const_iterator de acesso aleatório que aponta para logo após o último elemento.

```cpp
constexpr const_iterator end() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Retorna um const_iterator de acesso aleatório que aponta para logo após o último elemento.

### <a name="remarks"></a>Comentários

`end` é usado para testar se um const_iterator alcançou o final de seu string_view. O valor retornado por `end` não deve ser desreferenciado.

## <a name="find"></a>  basic_string_view::find

Pesquisa um string_view em uma direção progressiva para a primeira ocorrência de um caractere ou subcadeia de caracteres que corresponde a uma sequência de caracteres especificada.

```cpp
constexpr size_type find(basic_string_view str, size_type offset = 0) const noexcept;
constexpr size_type find(charT chVal, size_type offset = 0) const noexcept;
constexpr size_type find(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find(const charT* ptr, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
A string_view para o qual a função de membro deve pesquisar.

*chVal*<br/>
O valor de caractere que a função membro deve pesquisar.

*deslocamento*<br/>
Índice no qual a pesquisa deve iniciar.

*ptr*<br/>
A cadeia de caracteres de C para o qual a função de membro deve pesquisar.

*count*<br/>
O número de caracteres em *ptr*, contando a partir do primeiro caractere.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.

## <a name="find_first_not_of"></a>  basic_string_view::find_first_not_of

Pesquisa o primeiro caractere que não é um elemento de um objeto de cadeia de caracteres conversíveis ou string_view especificado.

```cpp
constexpr size_type find_first_not_of(basic_string_view str, size_type offset = 0) const noexcept;
constexpr size_type find_first_not_of(charT chVal, size_type offset = 0) const noexcept;
constexpr size_type find_first_not_of(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find_first_not_of(const charT* ptr, size_type offset = 0) const;
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
A string_view para o qual a função de membro deve pesquisar.

*chVal*<br/>
O valor de caractere que a função membro deve pesquisar.

*deslocamento*<br/>
Índice no qual a pesquisa deve iniciar.

*ptr*<br/>
A cadeia de caracteres de C para o qual a função de membro deve pesquisar.

*count*<br/>
O número de caracteres, contando a partir do primeiro caractere na cadeia de caracteres C para o qual a função de membro deve pesquisar.

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

*chVal*<br/>
O valor de caractere que a função membro deve pesquisar.

*deslocamento*<br/>
Índice no qual a pesquisa deve iniciar.

*ptr*<br/>
A cadeia de caracteres de C para o qual a função de membro deve pesquisar.

*count*<br/>
O número de caracteres, contando a partir do primeiro caractere na cadeia de caracteres C para o qual a função de membro deve pesquisar.

*str*<br/>
A string_view para o qual a função de membro deve pesquisar.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro caractere da subsequência pesquisada quando for houver êxito, caso contrário, `npos`.

## <a name="find_last_not_of"></a>  basic_string_view::find_last_not_of

Pesquisa o último caractere que não seja um elemento de um string_view especificado.

```cpp
constexpr size_type find_last_not_of(basic_string_view str, size_type offset = npos) const noexcept;
constexpr size_type find_last_not_of(charT chVal, size_type offset = npos) const noexcept;
constexpr size_type find_last_not_of(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type find_last_not_of(const charT* ptr, size_type offset = npos) const;
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
A string_view para o qual a função de membro deve pesquisar.

*chVal*<br/>
O valor de caractere que a função membro deve pesquisar.

*deslocamento*<br/>
Índice no qual a pesquisa é para concluir.

*ptr*<br/>
A cadeia de caracteres de C para o qual a função de membro deve pesquisar.

*count*<br/>
O número de caracteres, contando a partir do primeiro caractere em *ptr*.

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

*str*<br/>
A string_view para o qual a função de membro deve pesquisar.

*chVal*<br/>
O valor de caractere que a função membro deve pesquisar.

*deslocamento*<br/>
Índice no qual a pesquisa é para concluir.

*ptr*<br/>
A cadeia de caracteres de C para o qual a função de membro deve pesquisar.

*count*<br/>
O número de caracteres, contando a partir do primeiro caractere na cadeia de caracteres C para o qual a função de membro deve pesquisar.

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

Gera uma exceção se a string_view está vazio.

## <a name="length"></a> basic_string_view::length

Retorna o número atual de elementos.

```cpp
constexpr size_type length() const noexcept;
```

### <a name="remarks"></a>Comentários

A função membro é igual a [size](#size).

## <a name="max_size"></a>  basic_string_view::max_size

Retorna o número máximo de caracteres de que um string_view pode conter.

```cpp
constexpr size_type max_size() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

O número máximo de caracteres de que um string_view pode conter.

### <a name="remarks"></a>Comentários

Uma exceção do tipo [length_error](../standard-library/length-error-class.md) é gerada quando uma operação produz um string_view com um comprimento maior que `max_size()`.

## <a name="op_eq"></a>  basic_string_view::operator=

Atribui um objeto de cadeia de caracteres string_view ou que possa ser convertido para outro string_view.

```cpp
constexpr basic_string_view& operator=(const basic_string_view&) noexcept = default;
```
### <a name="example"></a>Exemplo

```cpp
   string_view s = "Hello";
   string_view s2 = s;
```
## <a name="op_at"></a>  basic_string_view::operator[]

Fornece um const_reference ao caractere com um índice especificado.

```cpp
constexpr const_reference operator[](size_type offset) const;
```

### <a name="parameters"></a>Parâmetros

*deslocamento*<br/>
O índice do elemento a ser referenciado.

### <a name="return-value"></a>Valor de retorno

Um const_reference para o caractere na posição especificada pelo índice de parâmetro.

### <a name="remarks"></a>Comentários

O primeiro elemento tem um índice igual a zero, e os elementos seguintes são indexados consecutivamente pelos inteiros positivos, para que um string_view de comprimento *n* tem um *n*º elemento indexado pelo número *n* - 1.

`operator[]` é mais rápido que a função de membro [em](#at) para fornecer acesso de leitura para os elementos de um string_view.

`operator[]` não verifica se o índice passado como um argumento é válido. Um índice inválido passado para `operator[]` resulta em um comportamento indefinido.

A referência retornada pode ser invalidada se os dados de cadeia de caracteres subjacente são modificados ou excluídos pelo objeto proprietário.

Ao compilar com [ \_ITERADOR\_DEBUG\_nível](../standard-library/iterator-debug-level.md) definido como 1 ou 2, um erro de tempo de execução ocorrerá se você tentar acessar um elemento fora dos limites do string_view. Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

## <a name="rbegin"></a>  basic_string_view::rbegin

Retorna um iterador const para o primeiro elemento em um string_view invertido.

```cpp
constexpr const_reverse_iterator rbegin() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Retorna um iterador de acesso aleatório para o primeiro elemento em um string_view invertida, indicando qual seria o último elemento na string_view não invertida correspondente.

### <a name="remarks"></a>Comentários

`rbegin` é usado com um string_view invertido tão [começar](#begin) é usado com um string_view. `rbegin` pode ser usado para inicializar uma iteração com versões anteriores.

## <a name="remove_prefix"></a> basic_string_view::remove_prefix

Move o ponteiro para a frente pelo número especificado de elementos.

```cpp
constexpr void remove_prefix(size_type n);
```

### <a name="remarks"></a>Comentários

Deixa os dados subjacentes inalterados. Move o ponteiro de string_view para frente por n elementos e define a privada `size` membro de dados para o tamanho de-n.

## <a name="remove_suffix"></a> basic_string_view::remove_suffix

Reduz o tamanho da exibição, o número especificado de elementos, começando na parte de trás.

```cpp
constexpr void remove_suffix(size_type n);
```

### <a name="remarks"></a>Comentários

Deixa os dados subjacentes e o ponteiro para ele inalterado. Define a privada `size` membro de dados para o tamanho de-n.

## <a name="rend"></a>  basic_string_view::rend

Retorna um iterador const que aponta para logo após o último elemento em um string_view invertido.

```cpp
constexpr reverse_iterator rend() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um iterador inverso const acesso aleatório que aponta para logo após o último elemento em um string_view invertido.

### <a name="remarks"></a>Comentários

`rend` é usado com um string_view invertido tão [final](#end) é usado com um string_view. `rend` pode ser usado para testar se um iterador inverso alcançou o final de seu string_view. O valor retornado por `rend` não deve ser desreferenciado.

## <a name="rfind"></a>  basic_string_view::rfind

Pesquisa um string_view em ordem inversa para uma subcadeia de caracteres que corresponde a uma sequência de caracteres especificada.

```cpp
constexpr size_type rfind(basic_string_view str, size_type offset = npos) const noexcept;
constexpr size_type rfind(charT chVal, size_type offset = npos) const noexcept;
constexpr size_type rfind(const charT* ptr, size_type offset, size_type count) const;
constexpr size_type rfind(const charT* ptr, size_type offset = npos) const;
```

### <a name="parameters"></a>Parâmetros

*chVal*<br/>
O valor de caractere que a função membro deve pesquisar.

*deslocamento*<br/>
Índice no qual a pesquisa deve iniciar.

*ptr*<br/>
A cadeia de caracteres de C para o qual a função de membro deve pesquisar.

*count*<br/>
O número de caracteres, contando a partir do primeiro caractere na cadeia de caracteres C para o qual a função de membro deve pesquisar.

*str*<br/>
A string_view para o qual a função de membro deve pesquisar.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro caractere da subcadeia de caracteres quando for bem-sucedida; Caso contrário, `npos`.

## <a name="size"></a>  basic_string_view::size

Retorna o número de elementos na string_view.

```cpp
constexpr size_type size() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

O comprimento da string_view.

### <a name="remarks"></a>Comentários

Um string_view pode modificar seu comprimento, por exemplo, `remove_prefix` e `remove_suffix`. Como isso não modifica os dados subjacentes de cadeia de caracteres, o tamanho de um string_view não é necessariamente o tamanho dos dados subjacentes.

## <a name="substr"></a>  basic_string_view::substr

Retorna um string_view (no máximo) representando o número especificado de caracteres de uma posição especificada.

```cpp
constexpr basic_string_view substr(size_type offset = 0, size_type count = npos) const;
```

### <a name="parameters"></a>Parâmetros

*deslocamento*<br/>
Um índice que localiza o elemento na posição da qual a cópia é feita, com um valor padrão de 0.

*count*<br/>
O número de caracteres a ser incluído na subcadeia de caracteres, se eles estiverem presentes.

### <a name="return-value"></a>Valor de retorno

Um objeto string_view que representa a sequência de subpropriedades especificada de elementos.

## <a name="swap"></a>  basic_string_view::swap

Troca dois string_views, em outras palavras, os ponteiros para os dados de cadeia de caracteres subjacente e os valores de tamanho.

```cpp
constexpr void swap(basic_string_view& sv) noexcept;
```

### <a name="parameters"></a>Parâmetros

*sv*<br/>
A string_view de origem cujos valores de ponteiro e tamanho deverão ser trocados com o de string_view o destino.

## <a name="see-also"></a>Consulte também

[\<string_view>](../standard-library/string-view.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
