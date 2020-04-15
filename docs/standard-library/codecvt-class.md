---
title: Classe codecvt
ms.date: 11/04/2016
f1_keywords:
- xlocale/std::codecvt
- xlocale/std::codecvt::extern_type
- xlocale/std::codecvt::intern_type
- xlocale/std::codecvt::state_type
- xlocale/std::codecvt::always_noconv
- xlocale/std::codecvt::do_always_noconv
- xlocale/std::codecvt::do_encoding
- xlocale/std::codecvt::do_in
- xlocale/std::codecvt::do_length
- xlocale/std::codecvt::do_max_length
- xlocale/std::codecvt::do_out
- xlocale/std::codecvt::do_unshift
- xlocale/std::codecvt::encoding
- xlocale/std::codecvt::in
- xlocale/std::codecvt::length
- xlocale/std::codecvt::max_length
- xlocale/std::codecvt::out
- xlocale/std::codecvt::unshift
helpviewer_keywords:
- std::codecvt [C++]
- std::codecvt [C++], extern_type
- std::codecvt [C++], intern_type
- std::codecvt [C++], state_type
- std::codecvt [C++], always_noconv
- std::codecvt [C++], do_always_noconv
- std::codecvt [C++], do_encoding
- std::codecvt [C++], do_in
- std::codecvt [C++], do_length
- std::codecvt [C++], do_max_length
- std::codecvt [C++], do_out
- std::codecvt [C++], do_unshift
- std::codecvt [C++], encoding
- std::codecvt [C++], in
- std::codecvt [C++], length
- std::codecvt [C++], max_length
- std::codecvt [C++], out
- std::codecvt [C++], unshift
ms.assetid: 37d3efa1-2b7f-42b6-b04f-7a972c8c2c86
ms.openlocfilehash: 3dba971b112c23325e0529e53746cbee827df5e9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371960"
---
# <a name="codecvt-class"></a>Classe codecvt

Um modelo de classe que descreve um objeto que pode servir como uma faceta local. Ela pode controlar conversões entre uma sequência de valores usada para codificar caracteres dentro do programa e uma sequência de valores usada para codificar caracteres fora do programa.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class Byte, class StateType>
class codecvt : public locale::facet, codecvt_base;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres.

*Byte*\
Um tipo usado para codificar caracteres fora de um programa.

*StateType*\
Um tipo que pode ser usado para representar estados intermediários de uma conversão entre tipos internos e externos das representações de caractere.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que pode servir como uma [faceta local,](../standard-library/locale-class.md#facet_class)para controlar conversões entre uma seqüência de valores do tipo *CharType* e uma seqüência de valores do tipo *Byte*. A classe *StateType* caracteriza a transformação -- e um objeto de classe *StateType* armazena todas as informações de estado necessárias durante uma conversão.

A codificação interna usa uma representação com um número fixo de bytes por caractere, geralmente tipo **char** ou tipo **wchar_t**.

Como qualquer faceta de localidade, a `id` de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em `id`.

As versões de modelo de [do_in](#do_in) and [do_out](#do_out) sempre retornam `codecvt_base::noconv`.

A Biblioteca Padrão C++ define várias especializações explícitas:

```cpp
template<>
codecvt<wchar_t, char, mbstate_t>
```

converte entre **wchar_t** e sequências **de char.**

```cpp
template<>
codecvt<char16_t, char, mbstate_t>
```

converte `char16_t` entre seqüências codificadas como UTF-16 e seqüências **de char** codificadas como UTF-8.

```cpp
template<>
codecvt<char32_t, char, mbstate_t>
```

converte `char32_t` entre seqüências codificadas como UTF-32 (UCS-4) e seqüências **de char** codificadas como UTF-8.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[codecvt](#codecvt)|O construtor para objetos da classe `codecvt` que serve como uma faceta de localidade para tratar conversões.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[extern_type](#extern_type)|Um tipo de caractere que é usado para representações externas.|
|[intern_type](#intern_type)|Um tipo de caractere que é usado para representações internas.|
|[state_type](#state_type)|Um tipo de caractere que é usado para representar estados intermediários durante conversões entre representações internas e externas.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[always_noconv](#always_noconv)|Testa se nenhuma conversão precisa ser feita.|
|[do_always_noconv](#do_always_noconv)|Uma função virtual chamada para testar se nenhuma conversão precisa ser feita.|
|[do_encoding](#do_encoding)|Uma função virtual que testa `Byte` se a codificação do fluxo `Byte` é dependente `CharType` do estado, se a razão entre os valores utilizados e os valores produzidos é constante, e, se assim for, determina o valor dessa razão.|
|[do_in](#do_in)|Uma função virtual chamada para `Byte` converter uma seqüência de valores internos em uma seqüência de valores externos. `CharType`|
|[do_length](#do_length)|Uma função virtual que `Byte` determina quantos valores `Byte` de uma determinada seqüência `CharType` de valores `Byte` externos produz não mais do que um determinado número de valores internos e retorna esse número de valores.|
|[do_max_length](#do_max_length)|Uma função virtual que retorna o número máximo de Bytes externos necessários para gerar um `CharType` interno.|
|[do_out](#do_out)|Uma função virtual chamada para `CharType` converter uma seqüência de valores internos para uma seqüência de Bytes externos.|
|[do_unshift](#do_unshift)|Uma função virtual chamada `Byte` para fornecer os valores necessários em uma `Byte` conversão dependente do estado para completar o último caractere em uma seqüência de valores.|
|[Codificação](#encoding)|Testa se a `Byte` codificação do fluxo é dependente `Byte` do estado, se a razão entre os valores utilizados e os `CharType` valores produzidos é constante e, se for o caso, determina o valor dessa razão.|
|[in](#in)|Converte uma representação externa `Byte` de uma seqüência `CharType` de valores em uma representação interna de uma seqüência de valores.|
|[length](#length)|Determina quantos `Byte` valores de uma `Byte` determinada seqüência de valores externos produzem não mais do que um determinado número de valores internos `CharType` e retorna esse número de `Byte` valores.|
|[Max_length](#max_length)|Retorna o número `Byte` máximo de valores `CharType`externos necessários para produzir um interno .|
|[fora](#out)|Converte uma seqüência de valores internos `CharType` em uma seqüência de valores externos. `Byte`|
|[unshift](#unshift)|Fornece os `Byte` valores externos necessários em uma conversão dependente `Byte` do estado para completar o último caractere na seqüência de valores.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="codecvtalways_noconv"></a><a name="always_noconv"></a>codecvt::always_noconv

Testa se não há conversões.

```cpp
bool always_noconv() const throw();
```

### <a name="return-value"></a>Valor retornado

Um valor booleano que é **verdadeiro** se não houver conversões; **falso** se pelo menos um precisa ser feito.

### <a name="remarks"></a>Comentários

A função membro retorna [do_always_noconv](#do_always_noconv).

### <a name="example"></a>Exemplo

```cpp
// codecvt_always_noconv.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   bool result1 = use_facet<codecvt<char, char, mbstate_t> >
      ( loc ).always_noconv( );

   if ( result1 )
      cout << "No conversion is needed." << endl;
   else
      cout << "At least one conversion is required." << endl;

   bool result2 = use_facet<codecvt<wchar_t, char, mbstate_t> >
      ( loc ).always_noconv( );

   if ( result2 )
      cout << "No conversion is needed." << endl;
   else
      cout << "At least one conversion is required." << endl;
}
```

```Output
No conversion is needed.
At least one conversion is required.
```

## <a name="codecvtcodecvt"></a><a name="codecvt"></a>codecvt::codecvt

O construtor de objetos da classe codecvt que funciona como uma faceta de localidade para manipular conversões.

```cpp
explicit codecvt(size_t refs = 0);
```

### <a name="parameters"></a>Parâmetros

*Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *dos árbitros* e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- 2: Esses valores não estão definidos.

O construtor inicializa `locale::facet` seu objeto base com [localidade::faceta](../standard-library/locale-class.md#facet_class)`(refs)`.

## <a name="codecvtdo_always_noconv"></a><a name="do_always_noconv"></a>codecvt::do_always_noconv

Uma função virtual chamada para testar se nenhuma conversão precisa ser feita.

```cpp
virtual bool do_always_noconv() const throw();
```

### <a name="return-value"></a>Valor retornado

A função de membro virtual protegido retorna **somente** `noconv`se cada chamada para [do_in](#do_in) ou [do_out](#do_out) retornar .

A versão do modelo sempre retorna **true**.

### <a name="example"></a>Exemplo

Consulte o exemplo de [always_noconv](#always_noconv), que chama `do_always_noconv`.

## <a name="codecvtdo_encoding"></a><a name="do_encoding"></a>codecvt::do_encoding

Uma função virtual que testa `Byte` se a codificação do fluxo `Byte` é dependente `CharType` do estado, se a razão entre os valores utilizados e os valores produzidos é constante e, se for o caso, determina o valor dessa razão.

```cpp
virtual int do_encoding() const throw();
```

### <a name="return-value"></a>Valor retornado

A função membro virtual protegido retornará:

- -1, se a codificação de `extern_type` seqüências do tipo for dependente do estado.

- 0, se a codificação envolver sequências de comprimentos variáveis.

- *N*, se a codificação envolver somente sequências de comprimento *N*

### <a name="example"></a>Exemplo

Consulte o exemplo de [encoding](#encoding), que chama `do_encoding`.

## <a name="codecvtdo_in"></a><a name="do_in"></a>codecvt::do_in

Uma função virtual chamada para `Byte` converter uma seqüência de valores externos em uma seqüência de valores internos. `CharType`

```cpp
virtual result do_in(
    StateType& state,
    const Byte* first1,
    const Byte* last1,
    const Byte*& next1,
    CharType* first2,
    CharType* last2,
    CharType*& next2,) const;
```

### <a name="parameters"></a>Parâmetros

*Estado*\
O estado de conversão mantido entre as chamadas para a função membro.

*primeiro1*\
Ponteiro para o início da sequência a ser convertida.

*último1*\
Ponteiro para o fim da sequência a ser convertida.

*next1*\
Ponteiro além do fim da sequência convertida para o primeiro caractere não convertido.

*primeiro2*\
Ponteiro para o início da sequência convertida.

*último2*\
Ponteiro para o fim da sequência convertida.

*next2*\
Ponteiro para `CharType` o que vem `CharType`após o último convertido, para o primeiro caractere inalterado na seqüência de destino.

### <a name="return-value"></a>Valor retornado

Um retorno que indica o êxito, êxito parcial ou falha da operação. A função retornará:

- `codecvt_base::error`se a seqüência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok`se a conversão for bem sucedida.

- `codecvt_base::partial`se a fonte é insuficiente ou se o destino não é grande o suficiente, para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*estado* deve representar o estado de conversão inicial no início de uma nova seqüência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado não é especificado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [in](#in), que chama `do_in`.

## <a name="codecvtdo_length"></a><a name="do_length"></a>codecvt::do_length

Uma função virtual que `Byte` determina quantos valores `Byte` de uma determinada seqüência `CharType` de valores `Byte` externos produz não mais do que um determinado número de valores internos e retorna esse número de valores.

```cpp
virtual int do_length(
    const StateType& state,
    const Byte* first1,
    const Byte* last1,
    size_t len2) const;
```

### <a name="parameters"></a>Parâmetros

*Estado*\
O estado de conversão mantido entre as chamadas para a função membro.

*primeiro1*\
Ponteiro para o início da sequência externa.

*último1*\
Ponteiro para o fim da sequência externa.

*len2*\
O número `Byte` máximo de valores que podem ser devolvidos pela função membro.

### <a name="return-value"></a>Valor retornado

Um inteiro que representa uma contagem do número máximo de conversões, não maior que *len2,* definido pela seqüência de fonte externa em [ `first1`, `last1`).

### <a name="remarks"></a>Comentários

A função de membro `do_in( state, first1, last1, next1, buf, buf + len2, next2)` virtual protegido efetivamente exige *estado* (uma `next1` cópia `next2`do estado), alguns buffers `buf`e ponteiros e .

Em seguida, retorna `next2` - `buf`. Assim, conta o número máximo de conversões, não maior que o `first1` `last1` *len2*, definido pela seqüência de origem em [ . .

A versão do modelo sempre retorna o menor de *last1* - *first1* e *len2*.

### <a name="example"></a>Exemplo

Veja o exemplo de `do_length` [comprimento,](#length)que chama .

## <a name="codecvtdo_max_length"></a><a name="do_max_length"></a>codecvt::do_max_length

Uma função virtual que retorna `Byte` o número máximo `CharType`de valores externos necessários para produzir um interno .

```cpp
virtual int do_max_length() const throw();
```

### <a name="return-value"></a>Valor retornado

O número `Byte` máximo de valores necessários para produzir um `CharType`.

### <a name="remarks"></a>Comentários

A função de membro virtual protegido retorna o maior valor admissível que pode ser devolvido por [do_length](#do_length) `( first1, last1, 1)` para valores válidos arbitrários de *primeiro* 1 e *último1*.

### <a name="example"></a>Exemplo

Consulte o exemplo de [max_length](#max_length), que chama `do_max_length`.

## <a name="codecvtdo_out"></a><a name="do_out"></a>codecvt::do_out

Uma função virtual chamada para `CharType` converter uma seqüência de valores internos em uma seqüência de valores externos. `Byte`

```cpp
virtual result do_out(
    StateType& state,
    const CharType* first1,
    const CharType* last1,
    const CharType*& next1,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*Estado*\
O estado de conversão mantido entre as chamadas para a função membro.

*primeiro1*\
Ponteiro para o início da sequência a ser convertida.

*último1*\
Ponteiro para o fim da sequência a ser convertida.

*next1*\
Referência a um ponteiro para `CharType`o primeiro `CharType` não convertido, após o último convertido.

*primeiro2*\
Ponteiro para o início da sequência convertida.

*último2*\
Ponteiro para o fim da sequência convertida.

*next2*\
Referência a um ponteiro para `Byte`o primeiro `Byte` não convertido, após o último convertido.

### <a name="return-value"></a>Valor retornado

A função retornará:

- `codecvt_base::error`se a seqüência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok`se a conversão for bem sucedida.

- `codecvt_base::partial`se a fonte é insuficiente ou se o destino não é grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*estado* deve representar o estado de conversão inicial no início de uma nova seqüência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado não é especificado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [out](#out), que chama `do_out`.

## <a name="codecvtdo_unshift"></a><a name="do_unshift"></a>codecvt::do_unshift

Uma função virtual chamada `Byte` para fornecer os valores necessários em uma `Byte` conversão dependente do estado para completar o último caractere em uma seqüência de valores.

```cpp
virtual result do_unshift(
    StateType& state,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*Estado*\
O estado de conversão mantido entre as chamadas para a função membro.

*primeiro2*\
Ponteiro para a primeira posição no intervalo de destino.

*último2*\
Ponteiro para a última posição no intervalo de destino.

*next2*\
Ponteiro para o primeiro elemento inalterado na sequência de destino.

### <a name="return-value"></a>Valor retornado

A função retornará:

- `codecvt_base::error`se *o estado* representa um estado inválido

- `codecvt_base::noconv` se a função não realizar nenhuma conversão

- `codecvt_base::ok`se a conversão for bem sucedida

- `codecvt_base::partial`se o destino não é grande o suficiente para a conversão para ter sucesso

### <a name="remarks"></a>Comentários

A função de membro virtual protegido `CharType`tenta converter o elemento de origem `first2` `last2`(0) para uma `Byte`seqüência de destino que ele armazena dentro de [ , ), exceto para o elemento de terminação (0). Ele sempre armazena no *next2* um ponteiro para o primeiro elemento inalterado na seqüência de destino.

_ *State* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Normalmente, a conversão `CharType`do elemento de origem (0) deixa o estado atual no estado inicial de conversão.

### <a name="example"></a>Exemplo

Consulte o exemplo de [unshift](#unshift), que chama `do_unshift`.

## <a name="codecvtencoding"></a><a name="encoding"></a>codecvt::codificação

Testa se a `Byte` codificação do fluxo é dependente `Byte` do estado, se a razão entre os valores utilizados e os `CharType` valores produzidos é constante e, se for o caso, determina o valor dessa razão.

```cpp
int encoding() const throw();
```

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for positivo, `Byte` esse valor `CharType` é o número constante de caracteres necessários para produzir o caractere.

A função membro virtual protegido retornará:

- -1, se a codificação de `extern_type` seqüências do tipo for dependente do estado.

- 0, se a codificação envolver sequências de comprimentos variáveis.

- *N*, se a codificação envolve apenas seqüências de comprimento *N.*

### <a name="remarks"></a>Comentários

A função membro retorna [do_encoding](#do_encoding).

### <a name="example"></a>Exemplo

```cpp
// codecvt_encoding.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc ( "German_Germany" );
   int result1 = use_facet<codecvt<char, char, mbstate_t> > ( loc ).encoding ( );
   cout << result1 << endl;
   result1 = use_facet<codecvt<wchar_t, char, mbstate_t> > ( loc ).encoding( );
   cout << result1 << endl;
   result1 = use_facet<codecvt<char, wchar_t, mbstate_t> > ( loc ).encoding( );
   cout << result1 << endl;
}
```

```Output
1
1
1
```

## <a name="codecvtextern_type"></a><a name="extern_type"></a>codecvt::extern_type

Um tipo de caractere que é usado para representações externas.

```cpp
typedef Byte extern_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Byte`.

## <a name="codecvtin"></a><a name="in"></a>codecvt::in

Converte uma representação externa `Byte` de uma seqüência `CharType` de valores em uma representação interna de uma seqüência de valores.

```cpp
result in(
    StateType& state,
    const Byte* first1,
    const Byte* last1,
    const Byte*& next1,
    CharType* first2,
    CharType* last2,
    CharType*& next2,) const;
```

### <a name="parameters"></a>Parâmetros

*Estado*\
O estado de conversão mantido entre as chamadas para a função membro.

*primeiro1*\
Ponteiro para o início da sequência a ser convertida.

*último1*\
Ponteiro para o fim da sequência a ser convertida.

*next1*\
Ponteiro além do fim da sequência de convertida para o primeiro caractere não convertido.

*primeiro2*\
Ponteiro para o início da sequência convertida.

*último2*\
Ponteiro para o fim da sequência convertida.

*next2*\
Ponteiro para `CharType` o que vem `Chartype` após o último convertido para o primeiro caractere inalterado na seqüência de destino.

### <a name="return-value"></a>Valor retornado

Um retorno que indica o êxito, êxito parcial ou falha da operação. A função retornará:

- `codecvt_base::error`se a seqüência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok`se a conversão for bem sucedida.

- `codecvt_base::partial`se a fonte é insuficiente ou se o destino não é grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*estado* deve representar o estado de conversão inicial no início de uma nova seqüência de origem. A função altera seu valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Após uma conversão parcial, *o estado* deve ser definido de modo a permitir que a conversão seja retomada quando novos caracteres chegarem.

A função membro retorna [do_in](#do_in)`( state, first1,  last1,  next1, first2, last2,  next2)`.

### <a name="example"></a>Exemplo

```cpp
// codecvt_in.cpp
// compile with: /EHsc
#define _INTL
#include <locale>
#include <iostream>
using namespace std;
#define LEN 90
int main( )
{
   char* pszExt = "This is the string to be converted!";
   wchar_t pwszInt [LEN+1];
   memset(&pwszInt[0], 0, (sizeof(wchar_t))*(LEN+1));
   const char* pszNext;
   wchar_t* pwszNext;
   mbstate_t state = {0};
   locale loc("C");//English_Britain");//German_Germany
   int res = use_facet<codecvt<wchar_t, char, mbstate_t> >
     ( loc ).in( state,
          pszExt, &pszExt[strlen(pszExt)], pszNext,
          pwszInt, &pwszInt[strlen(pszExt)], pwszNext );
   pwszInt[strlen(pszExt)] = 0;
   wcout << ( (res!=codecvt_base::error)  L"It worked! " : L"It didn't work! " )
   << L"The converted string is:\n ["
   << &pwszInt[0]
   << L"]" << endl;
   exit(-1);
}
```

```Output
It worked! The converted string is:
[This is the string to be converted!]
```

## <a name="codecvtintern_type"></a><a name="intern_type"></a>codecvt::intern_type

Um tipo de caractere que é usado para representações internas.

```cpp
typedef CharType intern_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `CharType`.

## <a name="codecvtlength"></a><a name="length"></a>codecvt::comprimento

Determina quantos `Byte` valores de uma `Byte` determinada seqüência de valores externos produzem não mais do que um determinado número de valores internos `CharType` e retorna esse número de `Byte` valores.

```cpp
int length(
    const StateType& state,
    const Byte* first1,
    const Byte* last1,
    size_t len2) const;
```

### <a name="parameters"></a>Parâmetros

*Estado*\
O estado de conversão mantido entre as chamadas para a função membro.

*primeiro1*\
Ponteiro para o início da sequência externa.

*último1*\
Ponteiro para o fim da sequência externa.

*len2*\
O número máximo de Bytes que podem ser retornados pela função membro.

### <a name="return-value"></a>Valor retornado

Um inteiro que representa uma contagem do número máximo de conversões, não maior que *len2,* definido pela seqüência de fonte externa em [ `first1`, `last1`).

### <a name="remarks"></a>Comentários

A função membro retorna [do_length](#do_length)`( state, first1, last1, len2)`.

### <a name="example"></a>Exemplo

```cpp
// codecvt_length.cpp
// compile with: /EHsc
#define _INTL
#include <locale>
#include <iostream>
using namespace std;
#define LEN 90
int main( )
{
   char* pszExt = "This is the string whose length is to be measured!";
   mbstate_t state = {0};
   locale loc("C");//English_Britain");//German_Germany
   int res = use_facet<codecvt<wchar_t, char, mbstate_t> >
     ( loc ).length( state,
          pszExt, &pszExt[strlen(pszExt)], LEN );
   cout << "The length of the string is: ";
   wcout << res;
   cout << "." << endl;
   exit(-1);
}
```

```Output
The length of the string is: 50.
```

## <a name="codecvtmax_length"></a><a name="max_length"></a>codecvt::max_length

Retorna o número `Byte` máximo de valores `CharType`externos necessários para produzir um interno .

```cpp
int max_length() const throw();
```

### <a name="return-value"></a>Valor retornado

O número `Byte` máximo de valores necessários para produzir um `CharType`.

### <a name="remarks"></a>Comentários

A função membro retorna [do_max_length](#do_max_length).

### <a name="example"></a>Exemplo

```cpp
// codecvt_max_length.cpp
// compile with: /EHsc
#define _INTL
#include <locale>
#include <iostream>
using namespace std;

int main( )
{
   locale loc( "C");//English_Britain" );//German_Germany
   int res = use_facet<codecvt<char, char, mbstate_t> >
     ( loc ).max_length( );
   wcout << res << endl;
}
```

```Output
1
```

## <a name="codecvtout"></a><a name="out"></a>codecvt::out

Converte uma seqüência de valores internos `CharType` em uma seqüência de valores externos. `Byte`

```cpp
result out(
    StateType& state,
    const CharType* first1,
    const CharType* last1,
    const CharType*& next1,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*Estado*\
O estado de conversão mantido entre as chamadas para a função membro.

*primeiro1*\
Ponteiro para o início da sequência a ser convertida.

*último1*\
Ponteiro para o fim da sequência a ser convertida.

*next1*\
Referência a um ponteiro para `CharType` o primeiro `CharType` não convertido após o último convertido.

*primeiro2*\
Ponteiro para o início da sequência convertida.

*último2*\
Ponteiro para o fim da sequência convertida.

*next2*\
Referência a um ponteiro para `Byte` o primeiro não `Byte`convertido após o último convertido .

### <a name="return-value"></a>Valor retornado

A função membro retorna [do_out](#do_out)`( state, first1, last1, next1, first2, last2, next2)`.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [codecvt::do_out](#do_out).

### <a name="example"></a>Exemplo

```cpp
// codecvt_out.cpp
// compile with: /EHsc
#define _INTL
#include <locale>
#include <iostream>
#include <wchar.h>
using namespace std;
#define LEN 90
int main( )
{
   char pszExt[LEN+1];
   wchar_t *pwszInt = L"This is the wchar_t string to be converted.";
   memset( &pszExt[0], 0, ( sizeof( char ) )*( LEN+1 ) );
   char* pszNext;
   const wchar_t* pwszNext;
   mbstate_t state;
   locale loc("C");//English_Britain");//German_Germany
   int res = use_facet<codecvt<wchar_t, char, mbstate_t> >
      ( loc ).out( state,
      pwszInt, &pwszInt[wcslen( pwszInt )], pwszNext ,
      pszExt, &pszExt[wcslen( pwszInt )], pszNext );
   pszExt[wcslen( pwszInt )] = 0;
   cout << ( ( res!=codecvt_base::error )  "It worked: " : "It didn't work: " )
   << "The converted string is:\n ["
   << &pszExt[0]
   << "]" << endl;
}
```

```Output
It worked: The converted string is:
[This is the wchar_t string to be converted.]
```

## <a name="codecvtstate_type"></a><a name="state_type"></a>codecvt::state_type

Um tipo de caractere que é usado para representar estados intermediários durante conversões entre representações internas e externas.

```cpp
typedef StateType state_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `StateType`.

## <a name="codecvtunshift"></a><a name="unshift"></a>codecvt::unshift

Fornece `Byte` os valores necessários em uma conversão dependente do `Byte` estado para completar o último caractere em uma seqüência de valores.

```cpp
result unshift(
    StateType& state,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*Estado*\
O estado de conversão mantido entre as chamadas para a função membro.

*primeiro2*\
Ponteiro para a primeira posição no intervalo de destino.

*último2*\
Ponteiro para a última posição no intervalo de destino.

*next2*\
Ponteiro para o primeiro elemento inalterado na sequência de destino.

### <a name="return-value"></a>Valor retornado

A função retornará:

- `codecvt_base::error`se o estado representa um estado inválido.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok`se a conversão for bem sucedida.

- `codecvt_base::partial`se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

A função de membro virtual protegido `CharType`tenta converter o elemento de origem `first2` `last2`(0) para uma `Byte`seqüência de destino que ele armazena dentro de [ , ), exceto para o elemento de terminação (0). Ele sempre armazena no *next2* um ponteiro para o primeiro elemento inalterado na seqüência de destino.

*estado* deve representar o estado de conversão inicial no início de uma nova seqüência de origem. A função altera seu valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Normalmente, a conversão `CharType`do elemento de origem (0) deixa o estado atual no estado inicial de conversão.

A função membro retorna [do_unshift](#do_unshift)`( state, first2, last2, next2 )`.

## <a name="see-also"></a>Confira também

[\<local>](../standard-library/locale.md)\
[Páginas de Código](../c-runtime-library/code-pages.md)\
[Nomes locais, idiomas e strings país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)\
[Segurança de threads na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
