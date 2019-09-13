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
ms.openlocfilehash: 936b3ab63b454e8f7e0490c2d155356a7c3b240f
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459827"
---
# <a name="codecvt-class"></a>Classe codecvt

Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade. Ela pode controlar conversões entre uma sequência de valores usada para codificar caracteres dentro do programa e uma sequência de valores usada para codificar caracteres fora do programa.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class Byte, class StateType>
class codecvt : public locale::facet, codecvt_base;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres.

*Minuciosa*\
Um tipo usado para codificar caracteres fora de um programa.

*StateType*\
Um tipo que pode ser usado para representar estados intermediários de uma conversão entre tipos internos e externos das representações de caractere.

## <a name="remarks"></a>Comentários

A classe de modelo descreve um objeto que pode servir como uma [faceta de localidade](../standard-library/locale-class.md#facet_class), para controlar conversões entre uma sequência de valores do tipo *CharType* e uma sequência de valores do tipo *byte*. O *statetype* da classe caracteriza a transformação – e um objeto *de classbinding* armazena todas as informações de estado necessárias durante uma conversão.

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

Converte entre `char16_t` sequências codificadas como UTF-16 e sequências de **caracteres** codificadas como UTF-8.

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
|[do_encoding](#do_encoding)|Uma função virtual que testa se a codificação do fluxo `Byte` é dependente de estado, se a taxa entre os `Byte`s usados e os `CharType`s produzidos é constante e, em caso positivo, determina o valor dessa taxa.|
|[do_in](#do_in)|Uma função virtual chamada para converter uma sequência de `Byte`s internos em uma sequência de `CharType`s externos.|
|[do_length](#do_length)|Uma função virtual que determina quantos `Byte`s de uma determinada sequência de `Byte`s externos produzem não mais do que um determinado número de `CharType`s internos e retorna esse número de `Byte`s.|
|[do_max_length](#do_max_length)|Uma função virtual que retorna o número máximo de Bytes externos necessários para gerar um `CharType` interno.|
|[do_out](#do_out)|Uma função virtual chamada para converter uma sequência de `CharType`s internos em uma sequência de Bytes externos.|
|[do_unshift](#do_unshift)|Uma função virtual chamada para fornecer os `Byte`s necessários em uma conversão dependente de estado para completar o último caractere em uma sequência de `Byte`s.|
|[encoding](#encoding)|Testa se a codificação do fluxo `Byte` é dependente de estado, se a taxa entre os `Byte`s usados e os `CharType`s produzidos é constante e, em caso positivo, determina o valor dessa taxa.|
|[in](#in)|Converte uma representação externa de uma sequência de `Byte`s em uma representação interna de uma sequência de `CharType`s.|
|[length](#length)|Determina quantos `Byte`s de uma determinada sequência de `Byte`s externos produzem não mais do que um determinado número de `CharType`s internos e retorna esse número de `Byte`s.|
|[max_length](#max_length)|Retorna o número máximo de `Byte`s externos necessários para gerar um `CharType` interno.|
|[out](#out)|Converte uma sequência de `CharType`s internos em uma sequência de `Byte`s externos.|
|[unshift](#unshift)|Fornece os `Byte`s externos necessários em uma conversão dependente de estado para completar o último caractere da sequência de `Byte`s.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="always_noconv"></a>  codecvt::always_noconv

Testa se nenhuma conversão precisa ser feita.

```cpp
bool always_noconv() const throw();
```

### <a name="return-value"></a>Valor de retorno

Um valor booliano será **true** se nenhuma conversão precisar ser feita; é **false** se pelo menos uma precisar ser feita.

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
explicit codecvt(size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *_Refs* e seu significado são:

- 0: O tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: O tempo de vida do objeto deve ser gerenciado manualmente.

- 2: Esses valores não estão definidos.

O construtor inicializa seu `locale::facet` objeto base com **locale::** [faceta](../standard-library/locale-class.md#facet_class)(`_Refs`).

## <a name="do_always_noconv"></a>  codecvt::do_always_noconv

Uma função virtual chamada para testar se nenhuma conversão precisa ser feita.

```cpp
virtual bool do_always_noconv() const throw();
```

### <a name="return-value"></a>Valor de retorno

A função de membro virtual protegido retornará **true** somente se todas as chamadas para [do_in](#do_in) ou `noconv` [do_out](#do_out) retornarem.

A versão do modelo sempre retorna **true**.

### <a name="example"></a>Exemplo

Consulte o exemplo de [always_noconv](#always_noconv), que chama `do_always_noconv`.

## <a name="do_encoding"></a>  codecvt::do_encoding

Uma função virtual que testa se a codificação do `Byte` fluxo é dependente de estado, se a taxa entre os `Byte`s usados e os `CharType`s produzidos é constante e, em caso afirmativo, determina o valor dessa razão.

```cpp
virtual int do_encoding() const throw();
```

### <a name="return-value"></a>Valor de retorno

A função membro virtual protegido retornará:

- -1, se a codificação de sequências do `extern_type` tipo for dependente de estado.

- 0, se a codificação envolver sequências de comprimentos variáveis.

- *N*, se a codificação envolver somente sequências de comprimento *N*

### <a name="example"></a>Exemplo

Consulte o exemplo de [encoding](#encoding), que chama `do_encoding`.

## <a name="do_in"></a>  codecvt::do_in

Uma função virtual chamada para converter uma sequência de s `Byte`externos em uma sequência de s `CharType`internas.

```cpp
virtual result do_in(
    StateType& _State,
    const Byte* first1,
    const Byte* last1,
    const Byte*& next1,
    CharType* first2,
    CharType* last2,
    CharType*& next2,) const;
```

### <a name="parameters"></a>Parâmetros

*_State*\
O estado de conversão mantido entre as chamadas para a função membro.

*first1*\
Ponteiro para o início da sequência a ser convertida.

*last1*\
Ponteiro para o fim da sequência a ser convertida.

*next1*\
Ponteiro além do fim da sequência convertida para o primeiro caractere não convertido.

*first2*\
Ponteiro para o início da sequência convertida.

*last2*\
Ponteiro para o fim da sequência convertida.

*next2*\
Ponteiro para o `CharType` que vem após a última conversão `CharType`, para o primeiro caractere inalterado na sequência de destino.

### <a name="return-value"></a>Valor de retorno

Um retorno que indica o êxito, êxito parcial ou falha da operação. A função retornará:

- `codecvt_base::error`se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok`se a conversão for realizada com sucesso.

- `codecvt_base::partial`se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*_State* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado não é especificado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [in](#in), que chama `do_in`.

## <a name="do_length"></a>  codecvt::do_length

Uma função virtual que determina quantos `Byte`s de uma determinada sequência de `Byte`s externos produzem não mais do que um determinado número de `CharType`s internos e retorna esse número de `Byte`s.

```cpp
virtual int do_length(
    const StateType& _State,
    const Byte* first1,
    const Byte* last1,
    size_t _Len2) const;
```

### <a name="parameters"></a>Parâmetros

*_State*\
O estado de conversão mantido entre as chamadas para a função membro.

*first1*\
Ponteiro para o início da sequência externa.

*last1*\
Ponteiro para o fim da sequência externa.

*_Len2*\
O número máximo de `Byte`s que podem ser retornados pela função de membro.

### <a name="return-value"></a>Valor de retorno

Um inteiro que representa uma contagem do número máximo de conversões, não maior que *_Len2*, definido pela sequência de origem externa em [ `first1`, `last1`).

### <a name="remarks"></a>Comentários

A função de membro virtual protegida chama `do_in`efetivamente `_State`( `first1` `_Buf` `last1` ,,`next1`, ,,`next2`,)para _ `_Len2` `_Buf`  +   *Estado* (uma cópia do estado), algum buffer `_Buf`e ponteiros `next1`e `next2`.

Em seguida, `next2`retorna  -  `buf`. Portanto, ele conta o número máximo de conversões, não maior que *_Len2*, definido pela sequência de origem em [ `first1`, `last1`).

A versão do modelo sempre retorna o menor de *last1* - *first1* e *_Len2*.

### <a name="example"></a>Exemplo

Consulte o exemplo de [comprimento](#length), que chama `do_length`.

## <a name="do_max_length"></a>  codecvt::do_max_length

Uma função virtual que retorna o número máximo de s `Byte`externos necessários para produzir um interno `CharType`.

```cpp
virtual int do_max_length() const throw();
```

### <a name="return-value"></a>Valor de retorno

O número máximo de `Byte`s necessários para produzir um `CharType`.

### <a name="remarks"></a>Comentários

A função de membro virtual protegido retorna o maior valor permitido que pode ser retornado por [do_length](#do_length)(`first1`, `last1`, 1) para valores válidos arbitrários de *first1* e *last1*.

### <a name="example"></a>Exemplo

Consulte o exemplo de [max_length](#max_length), que chama `do_max_length`.

## <a name="do_out"></a>  codecvt::do_out

Uma função virtual chamada para converter uma sequência de `CharType`s internos em uma sequência de `Byte`s externos.

```cpp
virtual result do_out(
    StateType& _State,
    const CharType* first1,
    const CharType* last1,
    const CharType*& next1,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*_State*\
O estado de conversão mantido entre as chamadas para a função membro.

*first1*\
Ponteiro para o início da sequência a ser convertida.

*last1*\
Ponteiro para o fim da sequência a ser convertida.

*next1*\
Referência a um ponteiro para o primeiro não convertido `CharType`após a última `CharType` conversão.

*first2*\
Ponteiro para o início da sequência convertida.

*last2*\
Ponteiro para o fim da sequência convertida.

*next2*\
Referência a um ponteiro para o primeiro não convertido `Byte`após a última `Byte` conversão.

### <a name="return-value"></a>Valor de retorno

A função retornará:

- `codecvt_base::error`se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok`se a conversão for realizada com sucesso.

- `codecvt_base::partial`se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*_State* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Caso contrário, seu valor armazenado não é especificado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [out](#out), que chama `do_out`.

## <a name="do_unshift"></a>  codecvt::do_unshift

Uma função virtual chamada para fornecer os `Byte`s necessários em uma conversão dependente de estado para completar o último caractere em uma sequência de `Byte`s.

```cpp
virtual result do_unshift(
    StateType& _State,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*_State*\
O estado de conversão mantido entre as chamadas para a função membro.

*first2*\
Ponteiro para a primeira posição no intervalo de destino.

*last2*\
Ponteiro para a última posição no intervalo de destino.

*next2*\
Ponteiro para o primeiro elemento inalterado na sequência de destino.

### <a name="return-value"></a>Valor de retorno

A função retornará:

- `codecvt_base::error`Se _ *State* representa um estado inválido

- `codecvt_base::noconv` se a função não realizar nenhuma conversão

- `codecvt_base::ok`se a conversão for realizada com sucesso

- `codecvt_base::partial`Se o destino não for grande o suficiente para que a conversão tenha sucesso

### <a name="remarks"></a>Comentários

A função de membro virtual protegida tenta converter o `CharType`elemento de origem (0) em uma sequência de destino que ele armazena dentro de [ `first2`, `last2`), exceto para `Byte`o elemento de terminação (0). Ele sempre armazena no *Next2* um ponteiro para o primeiro elemento inalterado na sequência de destino.

_ *State* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado conforme necessário para refletir o estado atual de uma conversão bem-sucedida. Normalmente, a conversão do elemento `CharType`de origem (0) deixa o estado atual no estado de conversão inicial.

### <a name="example"></a>Exemplo

Consulte o exemplo de [unshift](#unshift), que chama `do_unshift`.

## <a name="encoding"></a>  codecvt::encoding

Testa se a codificação do fluxo `Byte` é dependente de estado, se a taxa entre os `Byte`s usados e os `CharType`s produzidos é constante e, em caso positivo, determina o valor dessa taxa.

```cpp
int encoding() const throw();
```

### <a name="return-value"></a>Valor de retorno

Se o valor de retorno for positivo, esse valor será o número constante `Byte` de caracteres necessários para produzir `CharType` o caractere.

A função membro virtual protegido retornará:

- -1, se a codificação de sequências do `extern_type` tipo for dependente de estado.

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

Converte uma representação externa de uma sequência de `Byte`s em uma representação interna de uma sequência de `CharType`s.

```cpp
result in(
    StateType& _State,
    const Byte* first1,
    const Byte* last1,
    const Byte*& next1,
    CharType* first2,
    CharType* last2,
    CharType*& next2,) const;
```

### <a name="parameters"></a>Parâmetros

*_State*\
O estado de conversão mantido entre as chamadas para a função membro.

*first1*\
Ponteiro para o início da sequência a ser convertida.

*last1*\
Ponteiro para o fim da sequência a ser convertida.

*next1*\
Ponteiro além do fim da sequência de convertida para o primeiro caractere não convertido.

*first2*\
Ponteiro para o início da sequência convertida.

*last2*\
Ponteiro para o fim da sequência convertida.

*next2*\
Ponteiro para o `CharType` que vem após a última conversão `Chartype` para o primeiro caractere inalterado na sequência de destino.

### <a name="return-value"></a>Valor de retorno

Um retorno que indica o êxito, êxito parcial ou falha da operação. A função retornará:

- `codecvt_base::error`se a sequência de origem estiver mal formada.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok`se a conversão for realizada com sucesso.

- `codecvt_base::partial`se a origem for insuficiente ou se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

*_State* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Após uma conversão parcial, *_State* deve ser definido para permitir que a conversão seja retomada quando novos caracteres chegarem.

A função membro retorna [do_in](#do_in)( `_State`, _ *First1,  last1,  next1, First2, _Llast2,  next2*).

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

Determina quantos `Byte`s de uma determinada sequência de `Byte`s externos produzem não mais do que um determinado número de `CharType`s internos e retorna esse número de `Byte`s.

```cpp
int length(
    const StateType& _State,
    const Byte* first1,
    const Byte* last1,
    size_t _Len2) const;
```

### <a name="parameters"></a>Parâmetros

*_State*\
O estado de conversão mantido entre as chamadas para a função membro.

*first1*\
Ponteiro para o início da sequência externa.

*last1*\
Ponteiro para o fim da sequência externa.

*_Len2*\
O número máximo de Bytes que podem ser retornados pela função membro.

### <a name="return-value"></a>Valor de retorno

Um inteiro que representa uma contagem do número máximo de conversões, não maior que *_Len2*, definido pela sequência de origem externa em [ `first1`, `last1`).

### <a name="remarks"></a>Comentários

A função membro retorna [do_length](#do_length)( *_State,  first1*, `last1`, `_Len2`).

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

Retorna o número máximo de `Byte`s externos necessários para gerar um `CharType` interno.

```cpp
int max_length() const throw();
```

### <a name="return-value"></a>Valor de retorno

O número máximo de `Byte`s necessários para produzir um `CharType`.

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

Converte uma sequência de `CharType`s internos em uma sequência de `Byte`s externos.

```cpp
result out(
    StateType& _State,
    const CharType* first1,
    const CharType* last1,
    const CharType*& next1,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*_State*\
O estado de conversão mantido entre as chamadas para a função membro.

*first1*\
Ponteiro para o início da sequência a ser convertida.

*last1*\
Ponteiro para o fim da sequência a ser convertida.

*next1*\
Referência a um ponteiro para o primeiro não convertido `CharType` após a última `CharType` conversão.

*first2*\
Ponteiro para o início da sequência convertida.

*last2*\
Ponteiro para o fim da sequência convertida.

*next2*\
Referência a um ponteiro para o primeiro não convertido `Byte` após a última conversão. `Byte`

### <a name="return-value"></a>Valor de retorno

A função membro retorna [do_out](#do_out)( `_State`, `first1`, `last1`, `next1`, `first2`, `last2`, `next2`).

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

Fornece os `Byte`s necessários em uma conversão dependente de estado para concluir o último caractere em uma sequência de `Byte`s.

```cpp
result unshift(
    StateType& _State,
    Byte* first2,
    Byte* last2,
    Byte*& next2) const;
```

### <a name="parameters"></a>Parâmetros

*_State*\
O estado de conversão mantido entre as chamadas para a função membro.

*first2*\
Ponteiro para a primeira posição no intervalo de destino.

*last2*\
Ponteiro para a última posição no intervalo de destino.

*next2*\
Ponteiro para o primeiro elemento inalterado na sequência de destino.

### <a name="return-value"></a>Valor de retorno

A função retornará:

- `codecvt_base::error`se State representa um estado inválido.

- `codecvt_base::noconv` se a função não realizar nenhuma conversão.

- `codecvt_base::ok`se a conversão for realizada com sucesso.

- `codecvt_base::partial`Se o destino não for grande o suficiente para que a conversão tenha sucesso.

### <a name="remarks"></a>Comentários

A função de membro virtual protegida tenta converter o `CharType`elemento de origem (0) em uma sequência de destino que ele armazena dentro de [ `first2`, `last2`), exceto para `Byte`o elemento de terminação (0). Ele sempre armazena no *Next2* um ponteiro para o primeiro elemento inalterado na sequência de destino.

*_State* deve representar o estado de conversão inicial no início de uma nova sequência de origem. A função altera seu valor armazenado, conforme necessário, para refletir o estado atual de uma conversão bem-sucedida. Normalmente, a conversão do elemento `CharType`de origem (0) deixa o estado atual no estado de conversão inicial.

A função membro retorna [do_unshift](#do_unshift)( `_State`, `first2`, `last2`, `next2` ).

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)\
[Páginas de código](../c-runtime-library/code-pages.md)\
[Nomes de localidade, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
