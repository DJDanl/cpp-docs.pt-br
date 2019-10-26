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
ms.openlocfilehash: 631c3b88be5e2a03798ff6d8e3fb200ad257a8d7
ms.sourcegitcommit: 4b0928a1a497648d0d327579c8262f25ed20d02e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2019
ms.locfileid: "72890180"
---
# <a name="codecvt-class"></a>Classe codecvt

Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade. Ela pode controlar conversões entre uma sequência de valores usada para codificar caracteres dentro do programa e uma sequência de valores usada para codificar caracteres fora do programa.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class Byte, class StateType>
class codecvt : public locale::facet, codecvt_base;
```

### <a name="parameters"></a>Parâmetros

\ *CharType*
O tipo usado em um programa para codificar caracteres.

\ de *bytes*
Um tipo usado para codificar caracteres fora de um programa.

*Estado* \
Um tipo que pode ser usado para representar estados intermediários de uma conversão entre tipos internos e externos das representações de caractere.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que pode servir como uma [faceta de localidade](../standard-library/locale-class.md#facet_class), para controlar conversões entre uma sequência de valores do tipo *CharType* e uma sequência de valores do tipo *byte*. O *statetype* da classe caracteriza a transformação – e um objeto *de classbinding* armazena todas as informações de estado necessárias durante uma conversão.

A codificação interna usa uma representação com um número fixo de bytes por caractere, geralmente o tipo **Char** ou o tipo **wchar_t**.

Como qualquer faceta de localidade, a `id` de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em `id`.

As versões de modelo de [do_in](#do_in) and [do_out](#do_out) sempre retornam `codecvt_base::noconv`.

A Biblioteca Padrão C++ define várias especializações explícitas:

```cpp
template<>
codecvt<wchar_t, char, mbstate_t>
```

Converte entre combinações de **wchar_t** e **Char** .

```cpp
template<>
codecvt<char16_t, char, mbstate_t>
```

Converte entre `char16_t` sequências codificadas como UTF-16 e seqüências de **caracteres** codificadas como UTF-8.

```cpp
template<>
codecvt<char32_t, char, mbstate_t>
```

Converte entre `char32_t` sequências codificadas como UTF-32 (UCS-4) e seqüências de **caracteres** codificadas como UTF-8.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[codecvt](#codecvt)|O construtor para objetos da classe `codecvt` que serve como uma faceta de localidade para tratar conversões.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[extern_type](#extern_type)|Um tipo de caractere que é usado para representações externas.|
|[intern_type](#intern_type)|Um tipo de caractere que é usado para representações internas.|
|[state_type](#state_type)|Um tipo de caractere que é usado para representar estados intermediários durante conversões entre representações internas e externas.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[always_noconv](#always_noconv)|Testa se nenhuma conversão precisa ser feita.|
|[do_always_noconv](#do_always_noconv)|Uma função virtual chamada para testar se nenhuma conversão precisa ser feita.|
|[do_encoding](#do_encoding)|Uma função virtual que testa se a codificação do fluxo de `Byte` é dependente de estado, se a taxa entre os valores de `Byte` usados e os `CharType` valores produzidos é constante e, em caso afirmativo, determina o valor dessa razão.|
|[do_in](#do_in)|Uma função virtual chamada para converter uma sequência de valores de `Byte` internos em uma sequência de valores de `CharType` externos.|
|[do_length](#do_length)|Uma função virtual que determina quantos valores de `Byte` de uma determinada sequência de valores de `Byte` externos produzem não mais do que um determinado número de valores de `CharType` internos e retorna esse número de valores de `Byte`.|
|[do_max_length](#do_max_length)|Uma função virtual que retorna o número máximo de Bytes externos necessários para gerar um `CharType` interno.|
|[do_out](#do_out)|Uma função virtual chamada para converter uma sequência de valores de `CharType` internos em uma sequência de bytes externos.|
|[do_unshift](#do_unshift)|Uma função virtual chamada para fornecer os valores de `Byte` necessários em uma conversão dependente de estado para concluir o último caractere em uma sequência de valores de `Byte`.|
|[encoding](#encoding)|Testa se a codificação do fluxo de `Byte` é dependente de estado, se a taxa entre os valores de `Byte` usados e os `CharType` valores produzidos é constante e, em caso afirmativo, determina o valor dessa razão.|
|[in](#in)|Converte uma representação externa de uma sequência de valores de `Byte` em uma representação interna de uma sequência de valores de `CharType`.|
|[length](#length)|Determina quantos valores de `Byte` de uma determinada sequência de valores de `Byte` externos produzem não mais do que um determinado número de valores de `CharType` internos e retorna esse número de valores de `Byte`.|
|[max_length](#max_length)|Retorna o número máximo de valores de `Byte` externos necessários para produzir um `CharType`interno.|
|[out](#out)|Converte uma sequência de valores de `CharType` internos em uma sequência de valores de `Byte` externos.|
|[unshift](#unshift)|Fornece os valores de `Byte` externos necessários em uma conversão dependente de estado para concluir o último caractere na sequência de valores de `Byte`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="always_noconv"></a>  codecvt::always_noconv

Testa se nenhuma conversões precisa ser feita.

```cpp
bool always_noconv() const throw();
```

### <a name="return-value"></a>Valor retornado

Um valor booliano que será **verdadeiro** se nenhuma conversões precisar ser feita; **false** se pelo menos um precisar ser feito.

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

## <a name="codecvt"></a>  codecvt::codecvt

O construtor de objetos da classe codecvt que funciona como uma faceta de localidade para manipular conversões.

```cpp
explicit codecvt(size_t refs = 0);
```

### <a name="parameters"></a>Parâmetros

\ *refs*
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *refs* e seu significado são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- 2: esses valores não estão definidos.

O construtor inicializa seu `locale::facet` objeto base com [locale:: faceta](../standard-library/locale-class.md#facet_class)`(refs)`.

## <a name="do_always_noconv"></a>  codecvt::do_always_noconv

Uma função virtual chamada para testar se nenhuma conversões precisa ser feita.

```cpp
virtual bool do_always_noconv() const throw();
```

### <a name="return-value"></a>Valor retornado

A função de membro virtual protegido retornará **true** somente se todas as chamadas para [do_in](#do_in) ou [do_out](#do_out) retornarem `noconv`.

A versão do modelo sempre retorna **true**.

### <a name="example"></a>Exemplo

Consulte o exemplo de [always_noconv](#always_noconv), que chama `do_always_noconv`.

## <a name="do_encoding"></a>  codecvt::do_encoding

Uma função virtual que testa se a codificação do fluxo de `Byte` é dependente de estado, se a proporção entre os valores de `Byte` usados e os `CharType` valores produzidos é constante e, em caso afirmativo, determina o valor dessa razão.

```cpp
virtual int do_encoding() const throw();
```

### <a name="return-value"></a>Valor retornado

A função membro virtual protegido retornará:

- -1, se a codificação de sequências do tipo `extern_type` for dependente do estado.

- 0, se a codificação envolver sequências de comprimentos variáveis.

- *N*, se a codificação envolver somente sequências de comprimento *N*

### <a name="example"></a>Exemplo

Consulte o exemplo de [encoding](#encoding), que chama `do_encoding`.

## <a name="do_in"></a>  codecvt::do_in

Uma função virtual chamada para converter uma sequência de valores de `Byte` externos em uma sequência de valores de `CharType` internos.

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

*estado* \
O estado de conversão mantido entre as chamadas para a função membro.

\ *first1*
Ponteiro para o início da sequência a ser convertida.

\ *last1*
Ponteiro para o fim da sequência a ser convertida.

\ *next1*
Ponteiro além do fim da sequência convertida para o primeiro caractere não convertido.

\ *first2*
Ponteiro para o início da sequência convertida.

\ *last2*
Ponteiro para o fim da sequência convertida.

\ *Next2*
Ponteiro para a `CharType` que vem após o último `CharType` convertido, para o primeiro caractere inalterado na sequência de destino.

### <a name="return-value"></a>Valor retornado

Um retorno que indica o êxito, êxito parcial ou falha da operação. A função retornará:

- `codecvt_base::error` se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok` se a conversão for realizada com sucesso.

- `codecvt_base::partial` se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão seja realizada com sucesso.

### <a name="remarks"></a>Comentários

o *estado* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado não é especificado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [in](#in), que chama `do_in`.

## <a name="do_length"></a>  codecvt::do_length

Uma função virtual que determina quantos valores de `Byte` de uma determinada sequência de valores de `Byte` externos produzem não mais do que um determinado número de valores de `CharType` internos e retorna esse número de valores de `Byte`.

```cpp
virtual int do_length(
    const StateType& state,
    const Byte* first1,
    const Byte* last1,
    size_t len2) const;
```

### <a name="parameters"></a>Parâmetros

*estado* \
O estado de conversão mantido entre as chamadas para a função membro.

\ *first1*
Ponteiro para o início da sequência externa.

\ *last1*
Ponteiro para o fim da sequência externa.

\ *len2*
O número máximo de `Byte` valores que podem ser retornados pela função membro.

### <a name="return-value"></a>Valor retornado

Um inteiro que representa uma contagem do número máximo de conversões, não maior que *len2*, definido pela sequência de origem externa em [`first1`, `last1`).

### <a name="remarks"></a>Comentários

A função de membro virtual protegida chama efetivamente `do_in( state, first1, last1, next1, buf, buf + len2, next2)` para o *estado* (uma cópia do estado), alguns `buf`de buffer e ponteiros `next1` e `next2`.

Em seguida, ele retorna `next2`  -  `buf`. Portanto, ele conta o número máximo de conversões, não maior que *len2*, definido pela sequência de origem em [`first1`, `last1`).

A versão do modelo sempre retorna o menor de *last1* - *first1* e *len2*.

### <a name="example"></a>Exemplo

Consulte o exemplo de [comprimento](#length), que chama `do_length`.

## <a name="do_max_length"></a>  codecvt::do_max_length

Uma função virtual que retorna o número máximo de valores de `Byte` externos necessários para produzir um `CharType`interno.

```cpp
virtual int do_max_length() const throw();
```

### <a name="return-value"></a>Valor retornado

O número máximo de `Byte` valores necessários para produzir um `CharType`.

### <a name="remarks"></a>Comentários

A função de membro virtual protegido retorna o maior valor permitido que pode ser retornado por [do_length](#do_length)`( first1, last1, 1)` para valores válidos arbitrários de *first1* e *last1*.

### <a name="example"></a>Exemplo

Consulte o exemplo de [max_length](#max_length), que chama `do_max_length`.

## <a name="do_out"></a>  codecvt::do_out

Uma função virtual chamada para converter uma sequência de valores de `CharType` internos em uma sequência de valores de `Byte` externos.

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

*estado* \
O estado de conversão mantido entre as chamadas para a função membro.

\ *first1*
Ponteiro para o início da sequência a ser convertida.

\ *last1*
Ponteiro para o fim da sequência a ser convertida.

\ *next1*
Referência a um ponteiro para a primeira `CharType` não convertida, após a última `CharType` convertida.

\ *first2*
Ponteiro para o início da sequência convertida.

\ *last2*
Ponteiro para o fim da sequência convertida.

\ *Next2*
Referência a um ponteiro para a primeira `Byte` não convertida, após a última `Byte` convertida.

### <a name="return-value"></a>Valor retornado

A função retornará:

- `codecvt_base::error` se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok` se a conversão for realizada com sucesso.

- `codecvt_base::partial` se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

o *estado* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado não é especificado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [out](#out), que chama `do_out`.

## <a name="do_unshift"></a>  codecvt::do_unshift

Uma função virtual chamada para fornecer os valores de `Byte` necessários em uma conversão dependente de estado para concluir o último caractere em uma sequência de valores de `Byte`.

```cpp
virtual result do_unshift(
    StateType& state,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*estado* \
O estado de conversão mantido entre as chamadas para a função membro.

\ *first2*
Ponteiro para a primeira posição no intervalo de destino.

\ *last2*
Ponteiro para a última posição no intervalo de destino.

\ *Next2*
Ponteiro para o primeiro elemento inalterado na sequência de destino.

### <a name="return-value"></a>Valor retornado

A função retornará:

- `codecvt_base::error` se o *estado* representa um estado inválido

- `codecvt_base::noconv` se a função não realizar nenhuma conversão

- `codecvt_base::ok` se a conversão for realizada com sucesso

- `codecvt_base::partial` se o destino não for grande o suficiente para que a conversão tenha sucesso

### <a name="remarks"></a>Comentários

A função de membro virtual protegida tenta converter o elemento de origem `CharType`(0) em uma sequência de destino que ele armazena dentro de [`first2`, `last2`), exceto para o elemento de terminação `Byte`(0). Ele sempre armazena no *Next2* um ponteiro para o primeiro elemento inalterado na sequência de destino.

_ *State* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Normalmente, a conversão do elemento de origem `CharType` (0) deixa o estado atual no estado de conversão inicial.

### <a name="example"></a>Exemplo

Consulte o exemplo de [unshift](#unshift), que chama `do_unshift`.

## <a name="encoding"></a>  codecvt::encoding

Testa se a codificação do fluxo de `Byte` é dependente de estado, se a taxa entre os valores de `Byte` usados e os `CharType` valores produzidos é constante e, em caso afirmativo, determina o valor dessa razão.

```cpp
int encoding() const throw();
```

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for positivo, esse valor será o número constante de `Byte` caracteres necessários para produzir o caractere de `CharType`.

A função membro virtual protegido retornará:

- -1, se a codificação de sequências do tipo `extern_type` for dependente do estado.

- 0, se a codificação envolver sequências de comprimentos variáveis.

- *N*, se a codificação envolver somente sequências de comprimento *N.*

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

## <a name="extern_type"></a>  codecvt::extern_type

Um tipo de caractere que é usado para representações externas.

```cpp
typedef Byte extern_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Byte`.

## <a name="in"></a>  codecvt::in

Converte uma representação externa de uma sequência de valores de `Byte` em uma representação interna de uma sequência de valores de `CharType`.

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

*estado* \
O estado de conversão mantido entre as chamadas para a função membro.

\ *first1*
Ponteiro para o início da sequência a ser convertida.

\ *last1*
Ponteiro para o fim da sequência a ser convertida.

\ *next1*
Ponteiro além do fim da sequência de convertida para o primeiro caractere não convertido.

\ *first2*
Ponteiro para o início da sequência convertida.

\ *last2*
Ponteiro para o fim da sequência convertida.

\ *Next2*
Ponteiro para a `CharType` que vem após o último `Chartype` convertido para o primeiro caractere inalterado na sequência de destino.

### <a name="return-value"></a>Valor retornado

Um retorno que indica o êxito, êxito parcial ou falha da operação. A função retornará:

- `codecvt_base::error` se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok` se a conversão for realizada com sucesso.

- `codecvt_base::partial` se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

o *estado* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Após uma conversão parcial, o *estado* deve ser definido para permitir que a conversão seja retomada quando novos caracteres chegarem.

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

## <a name="intern_type"></a>  codecvt::intern_type

Um tipo de caractere que é usado para representações internas.

```cpp
typedef CharType intern_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `CharType`.

## <a name="length"></a>  codecvt::length

Determina quantos valores de `Byte` de uma determinada sequência de valores de `Byte` externos produzem não mais do que um determinado número de valores de `CharType` internos e retorna esse número de valores de `Byte`.

```cpp
int length(
    const StateType& state,
    const Byte* first1,
    const Byte* last1,
    size_t len2) const;
```

### <a name="parameters"></a>Parâmetros

*estado* \
O estado de conversão mantido entre as chamadas para a função membro.

\ *first1*
Ponteiro para o início da sequência externa.

\ *last1*
Ponteiro para o fim da sequência externa.

\ *len2*
O número máximo de Bytes que podem ser retornados pela função membro.

### <a name="return-value"></a>Valor retornado

Um inteiro que representa uma contagem do número máximo de conversões, não maior que *len2*, definido pela sequência de origem externa em [`first1`, `last1`).

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

## <a name="max_length"></a>  codecvt::max_length

Retorna o número máximo de valores de `Byte` externos necessários para produzir um `CharType`interno.

```cpp
int max_length() const throw();
```

### <a name="return-value"></a>Valor retornado

O número máximo de `Byte` valores necessários para produzir um `CharType`.

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

## <a name="out"></a>  codecvt::out

Converte uma sequência de valores de `CharType` internos em uma sequência de valores de `Byte` externos.

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

*estado* \
O estado de conversão mantido entre as chamadas para a função membro.

\ *first1*
Ponteiro para o início da sequência a ser convertida.

\ *last1*
Ponteiro para o fim da sequência a ser convertida.

\ *next1*
Referência a um ponteiro para a primeira `CharType` não convertida após a última `CharType` convertida.

\ *first2*
Ponteiro para o início da sequência convertida.

\ *last2*
Ponteiro para o fim da sequência convertida.

\ *Next2*
Referência a um ponteiro para a primeira `Byte` não convertida após o último `Byte` convertido.

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

## <a name="state_type"></a>  codecvt::state_type

Um tipo de caractere que é usado para representar estados intermediários durante conversões entre representações internas e externas.

```cpp
typedef StateType state_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `StateType`.

## <a name="unshift"></a>  codecvt::unshift

Fornece os valores de `Byte` necessários em uma conversão dependente de estado para concluir o último caractere em uma sequência de valores de `Byte`.

```cpp
result unshift(
    StateType& state,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*estado* \
O estado de conversão mantido entre as chamadas para a função membro.

\ *first2*
Ponteiro para a primeira posição no intervalo de destino.

\ *last2*
Ponteiro para a última posição no intervalo de destino.

\ *Next2*
Ponteiro para o primeiro elemento inalterado na sequência de destino.

### <a name="return-value"></a>Valor retornado

A função retornará:

- `codecvt_base::error` se o estado representa um estado inválido.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok` se a conversão for realizada com sucesso.

- `codecvt_base::partial` se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

A função de membro virtual protegida tenta converter o elemento de origem `CharType`(0) em uma sequência de destino que ele armazena dentro de [`first2`, `last2`), exceto para o elemento de terminação `Byte`(0). Ele sempre armazena no *Next2* um ponteiro para o primeiro elemento inalterado na sequência de destino.

o *estado* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Normalmente, a conversão do elemento de origem `CharType` (0) deixa o estado atual no estado de conversão inicial.

A função membro retorna [do_unshift](#do_unshift)`( state, first2, last2, next2 )`.

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)\
[Páginas de código](../c-runtime-library/code-pages.md)\
[Nomes de localidade, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
