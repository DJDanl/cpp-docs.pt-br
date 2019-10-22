---
title: Classe match_results
ms.date: 09/10/2018
f1_keywords:
- regex/std::match_results
helpviewer_keywords:
- match_results class
ms.assetid: b504fdca-e5dd-429d-9960-6e27c9167fa6
ms.openlocfilehash: c282791fb0ff85c0c8818c6905c51703614f4675
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689394"
---
# <a name="match_results-class"></a>Classe match_results

Contém uma sequência de subcorrespondências.

## <a name="syntax"></a>Sintaxe

```cpp
template <class BidIt, class Alloc>
class match_results
```

## <a name="parameters"></a>Parâmetros

@No__t_1 *bidirecional*
O tipo de iterador para subcorrespondências.

@No__t_1 de *alocação*
O tipo de um distribuidor para gerenciar o armazenamento.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que controla uma sequência não modificável de elementos do tipo `sub_match<BidIt>` gerados por uma pesquisa de expressão regular. Cada elemento aponta para a subsequência que corresponde ao grupo de captura correspondente a esse elemento.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[match_results](#match_results)|Constrói o objeto.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|O tipo de um distribuidor para gerenciar o armazenamento.|
|[char_type](#char_type)|O tipo de um elemento.|
|[const_iterator](#const_iterator)|O tipo de iterador const para subcorrespondências.|
|[const_reference](#const_reference)|O tipo de uma referência de elemento const.|
|[difference_type](#difference_type)|O tipo de uma diferença de iterador.|
|[iterator](#iterator)|O tipo de iterador para subcorrespondências.|
|[reference](#reference)|O tipo de uma referência de elemento.|
|[size_type](#size_type)|O tipo de uma contagem de subcorrespondência.|
|[string_type](#string_type)|O tipo de uma cadeia de caracteres.|
|[value_type](#value_type)|O tipo de uma subcorrespondência.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[begin](#begin)|Designa o início da sequência de subcorrespondência.|
|[empty](#empty)|Testa para não haver subcorrespondências.|
|[end](#end)|Designa o fim da sequência de subcorrespondências.|
|[format](#format)|Formata subcorrespondências.|
|[get_allocator](#get_allocator)|Retorna o alocador armazenado.|
|[length](#length)|Retorna o comprimento de uma subcorrespondência.|
|[max_size](#max_size)|Obtém o maior número de subcorrespondências.|
|[propostas](#position)|Iniciar o deslocamento de um subgrupo.|
|[prefixo](#prefix)|Obtém a sequência antes da primeira subcorrespondência.|
|[size](#size)|Número de contagens de subcorrespondências.|
|[str](#str)|Retorna uma subcorrespondência.|
|[sufixo](#suffix)|Obtém a sequência após a última subcorrespondência.|
|[swap](#swap)|Troca dois objetos match_results.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Copiar um objeto match_results.|
|[operator\[\]](#op_at)|Acessar um sub-objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<regex>

**Namespace:** std

## <a name="example"></a>Exemplo

```cpp
// std__regex__match_results.cpp
// compile with: /EHsc
#include <regex>
#include <iostream>

int main()
{
    std::regex rx("c(a*)|(b)");
    std::cmatch mr;

    std::regex_search("xcaaay", mr, rx);

    std::cout << "prefix: matched == " << std::boolalpha
        << mr.prefix().matched
        << ", value == " << mr.prefix() << std::endl;
    std::cout << "whole match: " << mr.length() << " chars, value == "
        << mr.str() << std::endl;
    std::cout << "suffix: matched == " << std::boolalpha
        << mr.suffix().matched
        << ", value == " << mr.suffix() << std::endl;
    std::cout << std::endl;

    std::string fmt("\"c(a*)|(b)\" matched \"$&\"\n"
        "\"(a*)\" matched \"$1\"\n"
        "\"(b)\" matched \"$2\"\n");
    std::cout << mr.format(fmt) << std::endl;
    std::cout << std::endl;

    // index through submatches
    for (size_t n = 0; n < mr.size(); ++n)
    {
        std::cout << "submatch[" << n << "]: matched == " << std::boolalpha
            << mr[n].matched <<
            " at position " << mr.position(n) << std::endl;
        std::cout << "  " << mr.length(n)
            << " chars, value == " << mr[n] << std::endl;
    }
    std::cout << std::endl;

    // iterate through submatches
    for (std::cmatch::iterator it = mr.begin(); it != mr.end(); ++it)
    {
        std::cout << "next submatch: matched == " << std::boolalpha
            << it->matched << std::endl;
        std::cout << "  " << it->length()
            << " chars, value == " << *it << std::endl;
    }
    std::cout << std::endl;

    // other members
    std::cout << "empty == " << std::boolalpha << mr.empty() << std::endl;

    std::cmatch::allocator_type al = mr.get_allocator();
    std::cmatch::string_type str = std::string("x");
    std::cmatch::size_type maxsiz = mr.max_size();
    std::cmatch::char_type ch = 'x';
    std::cmatch::difference_type dif = mr.begin() - mr.end();
    std::cmatch::const_iterator cit = mr.begin();
    std::cmatch::value_type val = *cit;
    std::cmatch::const_reference cref = val;
    std::cmatch::reference ref = val;

    maxsiz = maxsiz;  // to quiet "unused" warnings
    if (ref == cref)
        ch = ch;
    dif = dif;

    return (0);
}
```

```Output
prefix: matched == true, value == x
whole match: 4 chars, value == caaa
suffix: matched == true, value == y

"c(a*)|(b)" matched "caaa"
"(a*)" matched "aaa"
"(b)" matched ""

submatch[0]: matched == true at position 1
  4 chars, value == caaa
submatch[1]: matched == true at position 2
  3 chars, value == aaa
submatch[2]: matched == false at position 6
  0 chars, value ==

next submatch: matched == true
  4 chars, value == caaa
next submatch: matched == true
  3 chars, value == aaa
next submatch: matched == false
  0 chars, value ==

empty == false
```

## <a name="allocator_type"></a>  match_results::allocator_type

O tipo de um distribuidor para gerenciar o armazenamento.

```cpp
typedef Alloc allocator_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo para a *alocação*de argumento de modelo.

## <a name="begin"></a>  match_results::begin

Designa o início da sequência de subcorrespondência.

```cpp
const_iterator begin() const;
```

### <a name="remarks"></a>Comentários

A função de membro retorna um iterador de acesso aleatório que aponta para o primeiro elemento da sequência (ou um pouco além do final de uma sequência vazia).

## <a name="char_type"></a>  match_results::char_type

O tipo de um elemento.

```cpp
typedef typename iterator_traits<BidIt>::value_type char_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo para o tipo `iterator_traits<BidIt>::value_type`, que é o tipo de elemento da sequência de caracteres que foi pesquisada.

## <a name="const_iterator"></a>  match_results::const_iterator

O tipo de iterador const para subcorrespondências.

```cpp
typedef T0 const_iterator;
```

### <a name="remarks"></a>Comentários

O typedef descreve um objeto que pode servir como um iterador de acesso aleatório constante para a sequência controlada.

## <a name="const_reference"></a>  match_results::const_reference

O tipo de uma referência de elemento const.

```cpp
typedef const typename Alloc::const_reference const_reference;
```

### <a name="remarks"></a>Comentários

O typedef descreve um objeto que pode servir como uma referência constante para um elemento da sequência controlada.

## <a name="difference_type"></a>  match_results::difference_type

O tipo de uma diferença de iterador.

```cpp
typedef typename iterator_traits<BidIt>::difference_type difference_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo para o tipo `iterator_traits<BidIt>::difference_type`; ele descreve um objeto que pode representar a diferença entre quaisquer dois iteradores que apontem para os elementos da sequência controlada.

## <a name="empty"></a>  match_results::empty

Testa para não haver subcorrespondências.

```cpp
bool empty() const;
```

### <a name="remarks"></a>Comentários

A função de membro retornará true somente se a pesquisa de expressão regular falhar.

## <a name="end"></a>  match_results::end

Designa o fim da sequência de subcorrespondências.

```cpp
const_iterator end() const;
```

### <a name="remarks"></a>Comentários

A função de membro retorna um iterador que aponta para ou um pouco além do final da sequência.

## <a name="format"></a>  match_results::format

Formata subcorrespondências.

```cpp
template <class OutIt>
OutIt format(OutIt out,
    const string_type& fmt, match_flag_type flags = format_default) const;

string_type format(const string_type& fmt, match_flag_type flags = format_default) const;
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *OutIt*
O tipo de iterador de saída.

*out*\
O fluxo de saída no qual gravar.

\ *fmt*
A cadeia de caracteres de formato.

*sinalizadores* \
Os sinalizadores de formato.

### <a name="remarks"></a>Comentários

Cada função de membro gera texto formatado sob o controle do formato *fmt*. A primeira função de membro grava o texto formatado na sequência definida por *seu argumento e* *retorna.* A segunda função de membro retorna um objeto de cadeia de caracteres que contém uma cópia do texto formatado.

Para gerar texto formatado. o texto literal na cadeia de caracteres de formato é copiado normalmente para a sequência de destino. Cada sequência de escape na cadeia de caracteres de formato é substituída pelo texto que ela representa. Os detalhes da cópia e da substituição são controlados pelos sinalizadores de formato transmitidos à função.

## <a name="get_allocator"></a>  match_results::get_allocator

Retorna o alocador armazenado.

```cpp
allocator_type get_allocator() const;
```

### <a name="remarks"></a>Comentários

A função de membro retorna uma cópia do objeto alocador usado por `*this` para alocar seus objetos `sub_match`.

## <a name="iterator"></a>  match_results::iterator

O tipo de iterador para subcorrespondências.

```cpp
typedef const_iterator iterator;
```

### <a name="remarks"></a>Comentários

O tipo descreve um objeto que pode servir como um iterador de acesso aleatório para a sequência controlada.

## <a name="length"></a>  match_results::length

Retorna o comprimento de uma subcorrespondência.

```cpp
difference_type length(size_type sub = 0) const;
```

### <a name="parameters"></a>Parâmetros

*sub* \
O índice da subcorrespondência.

### <a name="remarks"></a>Comentários

A função membro retorna `(*this)[sub].length()`.

## <a name="match_results"></a>  match_results::match_results

Constrói o objeto.

```cpp
explicit match_results(const Alloc& alloc = Alloc());

match_results(const match_results& right);
```

### <a name="parameters"></a>Parâmetros

\ de *alocação*
O objeto de alocador a ser armazenado.

\ *à direita*
O objeto match_results a ser copiado.

### <a name="remarks"></a>Comentários

O primeiro construtor cria um objeto `match_results` que não mantém nenhuma subcorrespondência. O segundo construtor constrói um objeto `match_results` que é uma cópia do *lado direito*.

## <a name="max_size"></a>  match_results::max_size

Obtém o maior número de subcorrespondências.

```cpp
size_type max_size() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o comprimento da sequência mais longa que o objeto pode controlar.

## <a name="op_eq"></a>  match_results::operator=

Copiar um objeto match_results.

```cpp
match_results& operator=(const match_results& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O objeto match_results a ser copiado.

### <a name="remarks"></a>Comentários

O operador membro substitui a sequência controlada por `*this` com uma cópia da sequência controlada pela *direita*.

## <a name="op_at"></a>  match_results::operator[]

Acessar um sub-objeto.

```cpp
const_reference operator[](size_type n) const;
```

### <a name="parameters"></a>Parâmetros

*n*\
Índice da subcorrespondência.

### <a name="remarks"></a>Comentários

A função membro retorna uma referência ao elemento *n* da sequência controlada ou uma referência a um objeto `sub_match` vazio se `size() <= n` ou se o grupo de captura *n* não fizer parte da correspondência.

## <a name="position"></a>  match_results::position

Iniciar o deslocamento de um subgrupo.

```cpp
difference_type position(size_type sub = 0) const;
```

### <a name="parameters"></a>Parâmetros

*sub* \
Índice da subcorrespondência.

### <a name="remarks"></a>Comentários

A função de membro retorna `std::distance(prefix().first, (*this)[sub].first)`, ou seja, a distância entre o primeiro caractere na sequência de destino e o primeiro caractere da subcorrespondência apontada pelo elemento `n` da sequência controlada.

## <a name="prefix"></a>  match_results::prefix

Obtém a sequência antes da primeira subcorrespondência.

```cpp
const_reference prefix() const;
```

### <a name="remarks"></a>Comentários

A função de membro retorna uma referência a um objeto do tipo `sub_match<BidIt>` que aponta para a sequência de caracteres que começa no início da sequência de destino e termina em `(*this)[0].first`, ou seja, ela aponta para o texto que precede a subsequência correspondente.

## <a name="reference"></a>  match_results::reference

O tipo de uma referência de elemento.

```cpp
typedef const_reference reference;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o tipo `const_reference`.

## <a name="size"></a>  match_results::size

Número de contagens de subcorrespondências.

```cpp
size_type size() const;
```

### <a name="remarks"></a>Comentários

O membro da função retornará um número maior que o de grupos de captura na expressão regular que foi usada para a pesquisa ou zero, se nenhuma pesquisa tiver sido feita.

## <a name="size_type"></a>  match_results::size_type

O tipo de uma contagem de subcorrespondência.

```cpp
typedef typename Alloc::size_type size_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o tipo `Alloc::size_type`.

## <a name="str"></a>  match_results::str

Retorna uma subcorrespondência.

```cpp
string_type str(size_type sub = 0) const;
```

### <a name="parameters"></a>Parâmetros

*sub* \
Índice da subcorrespondência.

### <a name="remarks"></a>Comentários

A função membro retorna `string_type((*this)[sub])`.

## <a name="string_type"></a>  match_results::string_type

O tipo de uma cadeia de caracteres.

```cpp
typedef basic_string<char_type> string_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o tipo `basic_string<char_type>`.

## <a name="suffix"></a>  match_results::suffix

Obtém a sequência após a última subcorrespondência.

```cpp
const_reference suffix() const;
```

### <a name="remarks"></a>Comentários

A função de membro retorna uma referência a um objeto do tipo `sub_match<BidIt>`, que aponta para a sequência de caracteres que começa em `(*this)[size() - 1].second` e termina no final da sequência de destino, ou seja, ela aponta para o texto que segue a subsequência correspondente.

## <a name="swap"></a>  match_results::swap

Troca dois objetos match_results.

```cpp
void swap(const match_results& right) throw();
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O objeto match_results a ser trocado.

### <a name="remarks"></a>Comentários

A função membro troca o conteúdo de `*this` e *direita* em tempo constante e não gera exceções.

## <a name="value_type"></a>  match_results::value_type

O tipo de uma subcorrespondência.

```cpp
typedef sub_match<BidIt> value_type;
```

### <a name="remarks"></a>Comentários

O typedef é um sinônimo para o tipo `sub_match<BidIt>`.

## <a name="see-also"></a>Consulte também

[\<regex>](../standard-library/regex.md)
