---
title: Classe `codecvt`
description: Descreve a API da classe Microsoft C Runtime `codecvt`
ms.date: 11/09/2020
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
ms.openlocfilehash: 8d2970297cca199c70c101dca93f453c512317c4
ms.sourcegitcommit: b38485bb3a9d479e0c5d64ffc3d841fa2c2b366f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2020
ms.locfileid: "94441275"
---
# <a name="codecvt-class"></a>Classe `codecvt`

Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade. Ele pode controlar conversões entre uma sequência de valores usados para codificar caracteres dentro do programa e uma sequência de valores usados para codificar caracteres fora do programa.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class Byte, class StateType>
class codecvt : public locale::facet, codecvt_base;
```

### <a name="parameters"></a>Parâmetros

*`CharType`*\
O tipo usado em um programa para codificar caracteres.

*`Byte`*\
Um tipo usado para codificar caracteres fora de um programa.

*`StateType`*\
Um tipo que pode ser usado para representar estados intermediários de uma conversão entre tipos internos e externos das representações de caractere.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que pode servir como uma [faceta de localidade](../standard-library/locale-class.md#facet_class), para controlar conversões entre uma sequência de valores do tipo *`CharType`* e uma sequência de valores do tipo *`Byte`* . A classe *`StateType`* caracteriza a transformação – e um objeto da classe *`StateType`* armazena todas as informações de estado necessárias durante uma conversão.

A codificação interna usa uma representação com um número fixo de bytes por caractere, geralmente tipo **`char`** ou tipo **`wchar_t`** .

Como qualquer faceta de localidade, a `id` de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em `id`.

As versões de modelo do [`do_in`](#do_in) e [`do_out`](#do_out) sempre retornam `codecvt_base::noconv` .

A Biblioteca Padrão C++ define várias especializações explícitas:

```cpp
template<>
codecvt<wchar_t, char, mbstate_t>
```

Converte entre **`wchar_t`** e **`char`** sequências.

```cpp
template<>
codecvt<char16_t, char, mbstate_t>
```

Converte entre **`char16_t`** sequências codificadas como UTF-16 e **`char`** sequências codificadas como UTF-8.

```cpp
template<>
codecvt<char32_t, char, mbstate_t>
```

Converte entre **`char32_t`** sequências codificadas como UTF-32 (UCS-4) e **`char`** sequências codificadas como UTF-8.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[`codecvt`](#codecvt)|O construtor para objetos da classe `codecvt` que serve como uma faceta de localidade para tratar conversões.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[`extern_type`](#extern_type)|Um tipo de caractere que é usado para representações externas.|
|[`intern_type`](#intern_type)|Um tipo de caractere que é usado para representações internas.|
|[`state_type`](#state_type)|Um tipo de caractere que é usado para representar estados intermediários durante conversões entre representações internas e externas.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[`always_noconv`](#always_noconv)|Testa se nenhuma conversão precisa ser feita.|
|[`do_always_noconv`](#do_always_noconv)|Uma função virtual chamada para testar se nenhuma conversão precisa ser feita.|
|[`do_encoding`](#do_encoding)|Uma função virtual que testa se a codificação do `Byte` fluxo é dependente de estado, se a taxa entre os `Byte` valores usados e os `CharType` valores produzidos é constante e, em caso afirmativo, determina o valor dessa razão.|
|[`do_in`](#do_in)|Uma função virtual chamada para converter uma sequência de `Byte` valores internos em uma sequência de `CharType` valores externos.|
|[`do_length`](#do_length)|Uma função virtual que determina quantos `Byte` valores de uma determinada sequência de valores externos `Byte` produzem não mais do que um determinado número de `CharType` valores internos e retorna esse número de `Byte` valores.|
|[`do_max_length`](#do_max_length)|Uma função virtual que retorna o número máximo de Bytes externos necessários para gerar um `CharType` interno.|
|[`do_out`](#do_out)|Uma função virtual chamada para converter uma sequência de `CharType` valores internos em uma sequência de bytes externos.|
|[`do_unshift`](#do_unshift)|Uma função virtual chamada para fornecer os `Byte` valores necessários em uma conversão dependente de estado para concluir o último caractere em uma sequência de `Byte` valores.|
|[`encoding`](#encoding)|Testa se a codificação do `Byte` fluxo é dependente de estado, se a taxa entre os `Byte` valores usados e os `CharType` valores produzidos é constante e, em caso afirmativo, determina o valor dessa razão.|
|[`in`](#in)|Converte uma representação externa de uma sequência de `Byte` valores em uma representação interna de uma sequência de `CharType` valores.|
|[`length`](#length)|Determina quantos `Byte` valores de uma determinada sequência de valores externos `Byte` produzem não mais do que um determinado número de `CharType` valores internos e retorna esse número de `Byte` valores.|
|[`max_length`](#max_length)|Retorna o número máximo de `Byte` valores externos necessários para produzir um interno `CharType` .|
|[`out`](#out)|Converte uma sequência de `CharType` valores internos em uma sequência de `Byte` valores externos.|
|[`unshift`](#unshift)|Fornece os `Byte` valores externos necessários em uma conversão dependente de estado para concluir o último caractere na sequência de `Byte` valores.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**`<locale>`

**Namespace:** `std`

## <a name="codecvtalways_noconv"></a><a name="always_noconv"></a> `codecvt::always_noconv`

Testa se nenhuma conversões precisa ser feita.

```cpp
bool always_noconv() const throw();
```

### <a name="return-value"></a>Valor Retornado

Um valor booliano que **`true`** se nenhuma conversões precisar ser feita; **`false`** se pelo menos uma delas precisar ser feita.

### <a name="remarks"></a>Comentários

A função membro retorna [`do_always_noconv`](#do_always_noconv) .

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
   bool result1 = use_facet<codecvt<char, char, mbstate_t>>
      ( loc ).always_noconv( );

   if ( result1 )
      cout << "No conversion is needed." << '\n';
   else
      cout << "At least one conversion is required." << '\n';

   bool result2 = use_facet<codecvt<wchar_t, char, mbstate_t>>
      ( loc ).always_noconv( );

   if ( result2 )
      cout << "No conversion is needed." << '\n';
   else
      cout << "At least one conversion is required." << '\n';
}
```

```Output
No conversion is needed.
At least one conversion is required.
```

## <a name="codecvtcodecvt"></a><a name="codecvt"></a> `codecvt::codecvt`

O construtor de objetos da classe codecvt que funciona como uma faceta de localidade para manipular conversões.

```cpp
explicit codecvt(size_t refs = 0);
```

### <a name="parameters"></a>Parâmetros

*`refs`*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o *`refs`* parâmetro e seu significado são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.


- 2: esses valores não estão definidos.

O construtor inicializa seu `locale::facet` objeto base com [`locale::facet`](../standard-library/locale-class.md#facet_class) `(refs)` .

## <a name="codecvtdo_always_noconv"></a><a name="do_always_noconv"></a> `codecvt::do_always_noconv`

Uma função virtual chamada para testar se nenhuma conversões precisa ser feita.

```cpp
virtual bool do_always_noconv() const throw();
```

### <a name="return-value"></a>Valor Retornado

A função de membro virtual protegido retorna **`true`** somente se cada chamada para [`do_in`](#do_in) ou [`do_out`](#do_out) retorna `noconv` .

A versão do modelo sempre retorna **`true`** .

### <a name="example"></a>Exemplo

Consulte o exemplo para [`always_noconv`](#always_noconv) , que chama `do_always_noconv` .

## <a name="codecvtdo_encoding"></a><a name="do_encoding"></a> `codecvt::do_encoding`

Uma função virtual que testa se a codificação do `Byte` fluxo é dependente de estado, se a taxa entre os `Byte` valores usados e os `CharType` valores produzidos é constante e, em caso afirmativo, determina o valor dessa razão.

```cpp
virtual int do_encoding() const throw();
```

### <a name="return-value"></a>Valor Retornado

A função membro virtual protegido retornará:

- -1, se a codificação de sequências do tipo `extern_type` for dependente de estado.

- 0, se a codificação envolver sequências de comprimentos variáveis.

- *`N`* , se a codificação envolver apenas sequências de comprimento *`N`*

### <a name="example"></a>Exemplo

Consulte o exemplo de [encoding](#encoding), que chama `do_encoding`.

## <a name="codecvtdo_in"></a><a name="do_in"></a> codecvt::d o_in

Uma função virtual chamada para converter uma sequência de `Byte` valores externos em uma sequência de `CharType` valores internos.

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

*`state`*\
O estado de conversão mantido entre as chamadas para a função membro.

*`first1`*\
Ponteiro para o início da sequência a ser convertida.

*`last1`*\
Ponteiro para o fim da sequência a ser convertida.

*`next1`*\
Ponteiro além do fim da sequência convertida para o primeiro caractere não convertido.

*`first2`*\
Ponteiro para o início da sequência convertida.

*`last2`*\
Ponteiro para o fim da sequência convertida.

*`next2`*\
Ponteiro para o `CharType` que vem após a última conversão `CharType` , para o primeiro caractere inalterado na sequência de destino.

### <a name="return-value"></a>Valor Retornado

Um retorno que indica o êxito, êxito parcial ou falha da operação. A função retornará:

- `codecvt_base::error` se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok` se a conversão for realizada com sucesso.

- `codecvt_base::partial` se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*`state`* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado não é especificado.

### <a name="example"></a>Exemplo

Consulte o exemplo para [`in`](#in) , que chama `do_in` .

## <a name="codecvtdo_length"></a><a name="do_length"></a> `codecvt::do_length`

Uma função virtual que determina quantos `Byte` valores de uma determinada sequência de valores externos `Byte` produzem não mais do que um determinado número de `CharType` valores internos e retorna esse número de `Byte` valores.

```cpp
virtual int do_length(
    const StateType& state,
    const Byte* first1,
    const Byte* last1,
    size_t len2) const;
```

### <a name="parameters"></a>Parâmetros

*`state`*\
O estado de conversão mantido entre as chamadas para a função membro.

*`first1`*\
Ponteiro para o início da sequência externa.

*`last1`*\
Ponteiro para o fim da sequência externa.

*`len2`*\
O número máximo de `Byte` valores que podem ser retornados pela função membro.

### <a name="return-value"></a>Valor Retornado

Um inteiro que representa uma contagem do número máximo de conversões, não maior que *len2* , definido pela sequência de origem externa em [ `first1` , `last1` ).

### <a name="remarks"></a>Comentários

A função de membro virtual protegida chama efetivamente o `do_in( state, first1, last1, next1, buf, buf + len2, next2)` *estado* (uma cópia do estado), um buffer e `buf` ponteiros `next1` e `next2` .

Em seguida, retorna `next2` - `buf`. Ele conta o número máximo de conversões, não maior que *len2* , definido pela sequência de origem em [ `first1` , `last1` ).

A versão do modelo sempre retorna o menor de *`last1`*  -  *`first1`* e *`len2`* .

### <a name="example"></a>Exemplo

Consulte o exemplo para [`length`](#length) , que chama `do_length` .

## <a name="codecvtdo_max_length"></a><a name="do_max_length"></a> `codecvt::do_max_length`

Uma função virtual que retorna o número máximo de `Byte` valores externos necessários para produzir um interno `CharType` .

```cpp
virtual int do_max_length() const throw();
```

### <a name="return-value"></a>Valor Retornado

O número máximo de `Byte` valores necessários para produzir um `CharType` .

### <a name="remarks"></a>Comentários

A função de membro virtual protegido retorna o maior valor permitido que pode ser retornado pelo [`do_length`](#do_length) `( first1, last1, 1)` para valores válidos arbitrários de *`first1`* e *`last1`* .

### <a name="example"></a>Exemplo

Consulte o exemplo para [`max_length`](#max_length) , que chama `do_max_length` .

## <a name="codecvtdo_out"></a><a name="do_out"></a> `codecvt::do_out`

Uma função virtual chamada para converter uma sequência de `CharType` valores internos em uma sequência de `Byte` valores externos.

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

*`state`*\
O estado de conversão mantido entre as chamadas para a função membro.

*`first1`*\
Ponteiro para o início da sequência a ser convertida.

*`last1`*\
Ponteiro para o fim da sequência a ser convertida.

*`next1`*\
Referência a um ponteiro para o primeiro não convertido `CharType` após a última `CharType` conversão.

*`first2`*\
Ponteiro para o início da sequência convertida.

*`last2`*\
Ponteiro para o fim da sequência convertida.

*`next2`*\
Referência a um ponteiro para o primeiro não convertido `Byte` após a última `Byte` conversão.

### <a name="return-value"></a>Valor Retornado

A função retornará:

- `codecvt_base::error` se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok` se a conversão for realizada com sucesso.

- `codecvt_base::partial` se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*`state`* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado não é especificado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [out](#out), que chama `do_out`.

## <a name="codecvtdo_unshift"></a><a name="do_unshift"></a> `codecvt::do_unshift`

Uma função virtual chamada para fornecer os `Byte` valores necessários em uma conversão dependente de estado para concluir o último caractere em uma sequência de `Byte` valores.

```cpp
virtual result do_unshift(
    StateType& state,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*`state`*\
O estado de conversão mantido entre as chamadas para a função membro.

*`first2`*\
Ponteiro para a primeira posição no intervalo de destino.

*`last2`*\
Ponteiro para a última posição no intervalo de destino.

*`next2`*\
Ponteiro para o primeiro elemento inalterado na sequência de destino.

### <a name="return-value"></a>Valor Retornado

A função retornará:

- `codecvt_base::error` Se o *estado* representa um estado inválido

- `codecvt_base::noconv` se a função não realizar nenhuma conversão

- `codecvt_base::ok` se a conversão for realizada com sucesso

- `codecvt_base::partial` Se o destino não for grande o suficiente para que a conversão tenha sucesso

### <a name="remarks"></a>Comentários

A função de membro virtual protegida tenta converter o elemento de origem `CharType` (0) em uma sequência de destino que ele armazena dentro de [ `first2` , `last2` ), exceto para o elemento de terminação `Byte` (0). Ele sempre armazena em *`next2`* um ponteiro para o primeiro elemento inalterado na sequência de destino.

*`State`* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Normalmente, a conversão do elemento de origem `CharType` (0) deixa o estado atual no estado de conversão inicial.

### <a name="example"></a>Exemplo

Consulte o exemplo para [`unshift`](#unshift) , que chama `do_unshift` .

## <a name="codecvtencoding"></a><a name="encoding"></a> `codecvt::encoding`

Testa se a codificação do `Byte` fluxo é dependente de estado, se a taxa entre os `Byte` valores usados e os `CharType` valores produzidos é constante e, em caso afirmativo, determina o valor dessa razão.

```cpp
int encoding() const throw();
```

### <a name="return-value"></a>Valor Retornado

Se o valor de retorno for positivo, esse valor será o número constante de `Byte` caracteres necessários para produzir o `CharType` caractere.

A função membro virtual protegido retornará:

- -1, se a codificação de sequências do tipo `extern_type` for dependente de estado.

- 0, se a codificação envolver sequências de comprimentos variáveis.

- *`N`* , se a codificação envolver apenas sequências de comprimento *`N`* .

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
   int result1 = use_facet<codecvt<char, char, mbstate_t>> ( loc ).encoding ( );
   cout << result1 << '\n';
   result1 = use_facet<codecvt<wchar_t, char, mbstate_t>> ( loc ).encoding( );
   cout << result1 << '\n';
   result1 = use_facet<codecvt<char, wchar_t, mbstate_t>> ( loc ).encoding( );
   cout << result1 << '\n';
}
```

```Output
1
1
1
```

## <a name="codecvtextern_type"></a><a name="extern_type"></a> `codecvt::extern_type`

Um tipo de caractere que é usado para representações externas.

```cpp
typedef Byte extern_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Byte`.

## <a name="codecvtin"></a><a name="in"></a> codecvt:: in

Converte uma representação externa de uma sequência de `Byte` valores em uma representação interna de uma sequência de `CharType` valores.

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

*`state`*\
O estado de conversão mantido entre as chamadas para a função membro.

*`first1`*\
Ponteiro para o início da sequência a ser convertida.

*`last1`*\
Ponteiro para o fim da sequência a ser convertida.

*`next1`*\
Ponteiro além do fim da sequência de convertida para o primeiro caractere não convertido.

*`first2`*\
Ponteiro para o início da sequência convertida.

*`last2`*\
Ponteiro para o fim da sequência convertida.

*`next2`*\
Ponteiro para o `CharType` que vem após a última conversão `Chartype` para o primeiro caractere inalterado na sequência de destino.

### <a name="return-value"></a>Valor Retornado

Um retorno que indica o êxito, êxito parcial ou falha da operação. A função retornará:

- `codecvt_base::error` se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok` se a conversão for realizada com sucesso.

- `codecvt_base::partial` se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*`state`* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Após uma conversão parcial, *`state`* deve ser definido para permitir que a conversão seja retomada quando novos caracteres chegarem.

A função membro retorna [`do_in`](#do_in) `( state, first1,  last1,  next1, first2, last2,  next2)` .

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
   const char* pszExt = "This is the string to be converted!";
   wchar_t pwszInt [LEN+1];
   memset(&pwszInt[0], 0, (sizeof(wchar_t))*(LEN+1));
   const char* pszNext;
   wchar_t* pwszNext;
   mbstate_t state = {0}; // zero-initialization represents the initial conversion state for mbstate_t
   locale loc("C");//English_Britain");//German_Germany
   int res = use_facet<codecvt<wchar_t, char, mbstate_t>>
     ( loc ).in( state,
          pszExt, &pszExt[strlen(pszExt)], pszNext,
          pwszInt, &pwszInt[strlen(pszExt)], pwszNext );
   pwszInt[strlen(pszExt)] = 0;
   wcout << ( res!=codecvt_base::error ?  L"It worked! " : L"It didn't work! " )
       << L"The converted string is:\n ["
       << &pwszInt[0]
       << L"]" << '\n';
   exit(-1);
}
```

```Output
It worked! The converted string is:
[This is the string to be converted!]
```

## <a name="codecvtintern_type"></a><a name="intern_type"></a> `codecvt::intern_type`

Um tipo de caractere que é usado para representações internas.

```cpp
typedef CharType intern_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `CharType`.

## <a name="codecvtlength"></a><a name="length"></a> codecvt:: comprimento

Determina quantos `Byte` valores de uma determinada sequência de valores externos `Byte` produzem não mais do que um determinado número de `CharType` valores internos e retorna esse número de `Byte` valores.

```cpp
int length(
    const StateType& state,
    const Byte* first1,
    const Byte* last1,
    size_t len2) const;
```

### <a name="parameters"></a>Parâmetros

*`state`*\
O estado de conversão mantido entre as chamadas para a função membro.

*`first1`*\
Ponteiro para o início da sequência externa.

*`last1`*\
Ponteiro para o fim da sequência externa.

*`len2`*\
O número máximo de Bytes que podem ser retornados pela função membro.

### <a name="return-value"></a>Valor Retornado

Um inteiro que representa uma contagem do número máximo de conversões, não maior que *`len2`* , definido pela sequência de origem externa em [ `first1` , `last1` ).

### <a name="remarks"></a>Comentários

A função membro retorna [`do_length`](#do_length) `( state, first1, last1, len2)` .

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
   const char* pszExt = "This is the string whose length is to be measured!";
   mbstate_t state = {0}; // zero-initialization represents the initial conversion state for mbstate_t
   locale loc("C"); // English_Britain"); //German_Germany
   int res = use_facet<codecvt<wchar_t, char, mbstate_t>>
     ( loc ).length( state,
          pszExt, &pszExt[strlen(pszExt)], LEN );
   cout << "The length of the string is: ";
   wcout << res;
   cout << "." << '\n';
   exit(-1);
}
```

```Output
The length of the string is: 50.
```

## <a name="codecvtmax_length"></a><a name="max_length"></a> `codecvt::max_length`

Retorna o número máximo de `Byte` valores externos necessários para produzir um interno `CharType` .

```cpp
int max_length() const throw();
```

### <a name="return-value"></a>Valor Retornado

O número máximo de `Byte` valores necessários para produzir um `CharType` .

### <a name="remarks"></a>Comentários

A função membro retorna [`do_max_length`](#do_max_length) .

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
   int res = use_facet<codecvt<char, char, mbstate_t>>
     ( loc ).max_length( );
   wcout << res << '\n';
}
```

```Output
1
```

## <a name="codecvtout"></a><a name="out"></a> `codecvt::out`

Converte uma sequência de `CharType` valores internos em uma sequência de `Byte` valores externos.

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

*`state`*\
O estado de conversão mantido entre as chamadas para a função membro.

*`first1`*\
Ponteiro para o início da sequência a ser convertida.

*`last1`*\
Ponteiro para o fim da sequência a ser convertida.

*`next1`*\
Referência a um ponteiro para o primeiro não convertido `CharType` após a última `CharType` conversão.

*`first2`*\
Ponteiro para o início da sequência convertida.

*`last2`*\
Ponteiro para o fim da sequência convertida.

*`next2`*\
Referência a um ponteiro para o primeiro não convertido `Byte` após a última conversão `Byte` .

### <a name="return-value"></a>Valor Retornado

A função membro retorna [`do_out`](#do_out) `( state, first1, last1, next1, first2, last2, next2)` .

### <a name="remarks"></a>Comentários

Para obter mais informações, confira [`codecvt::do_out`](#do_out).

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
    char pszExt[LEN + 1];
    const wchar_t* pwszInt = L"This is the wchar_t string to be converted.";
    memset(&pszExt[0], 0, (sizeof(char)) * (LEN + 1));
    char* pszNext;
    const wchar_t* pwszNext;
    mbstate_t state;
    locale loc("C");//English_Britain");//German_Germany
    int res = use_facet<codecvt<wchar_t, char, mbstate_t>>
        (loc).out(state,
            pwszInt, &pwszInt[wcslen(pwszInt)], pwszNext,
            pszExt, &pszExt[wcslen(pwszInt)], pszNext);
    pszExt[wcslen(pwszInt)] = 0;
    cout << (res != codecvt_base::error ? "It worked: " : "It didn't work: ")
        << "The converted string is:\n ["
        << &pszExt[0]
        << "]" << '\n';

}
```

```Output
It worked: The converted string is:
[This is the wchar_t string to be converted.]
```

## <a name="codecvtstate_type"></a><a name="state_type"></a> `codecvt::state_type`

Um tipo de caractere que é usado para representar estados intermediários durante conversões entre representações internas e externas.

```cpp
typedef StateType state_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `StateType`.

## <a name="codecvtunshift"></a><a name="unshift"></a> codecvt:: unshift

Fornece os `Byte` valores necessários em uma conversão dependente de estado para concluir o último caractere em uma sequência de `Byte` valores.

```cpp
result unshift(
    StateType& state,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*`state`*\
O estado de conversão mantido entre as chamadas para a função membro.

*`first2`*\
Ponteiro para a primeira posição no intervalo de destino.

*`last2`*\
Ponteiro para a última posição no intervalo de destino.

*`next2`*\
Ponteiro para o primeiro elemento inalterado na sequência de destino.

### <a name="return-value"></a>Valor Retornado

A função retornará:

- `codecvt_base::error` se State representa um estado inválido.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok` se a conversão for realizada com sucesso.

- `codecvt_base::partial` Se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

A função de membro virtual protegida tenta converter o elemento de origem `CharType` (0) em uma sequência de destino que ele armazena dentro de [ `first2` , `last2` ), exceto para o elemento de terminação `Byte` (0). Ele sempre armazena em *`next2`* um ponteiro para o primeiro elemento inalterado na sequência de destino.

*`state`* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Normalmente, a conversão do elemento de origem `CharType` (0) deixa o estado atual no estado de conversão inicial.

A função membro retorna [`do_unshift`](#do_unshift) `( state, first2, last2, next2 )` .

## <a name="see-also"></a>Confira também

[`<locale>`](../standard-library/locale.md)\
[Páginas de código](../c-runtime-library/code-pages.md)\
[Nomes de localidade, idiomas e cadeias de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
