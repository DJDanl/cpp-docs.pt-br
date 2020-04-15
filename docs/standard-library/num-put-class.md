---
title: Classe num_put
ms.date: 11/04/2016
f1_keywords:
- xlocnum/std::num_put
- locale/std::num_put::char_type
- locale/std::num_put::iter_type
- locale/std::num_put::do_put
- locale/std::num_put::put
helpviewer_keywords:
- std::num_put [C++]
- std::num_put [C++], char_type
- std::num_put [C++], iter_type
- std::num_put [C++], do_put
- std::num_put [C++], put
ms.assetid: 36c5bffc-8283-4201-8ed4-78c4d81f8a17
ms.openlocfilehash: 3f65d7140bb5c691fa58ec9d74ceda5573280ddb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373639"
---
# <a name="num_put-class"></a>Classe num_put

Um modelo de classe que descreve um objeto que pode servir como uma faceta local `CharType`para controlar conversões de valores numéricos para seqüências de tipo .

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType,
    class OutputIterator = ostreambuf_iterator<CharType>>
class num_put : public locale::facet;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres em uma localidade.

*Iterator de saída*\
O tipo de iterador para o qual as funções put numéricas gravam sua saída.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[num_put](#num_put)|O construtor para objetos do tipo `num_put`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|
|[iter_type](#iter_type)|Um tipo que descreve um iterador de saída.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[do_put](#do_put)|Uma função virtual que é chamada para converter um número em uma sequência de `CharType`s que representa o número formatado para uma determinada localidade.|
|[Colocar](#put)|Converte um número em uma sequência de `CharType`s que representa o número formatado para uma determinada localidade.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="num_putchar_type"></a><a name="char_type"></a>num_put:char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `CharType`.

## <a name="num_putdo_put"></a><a name="do_put"></a>num_put::do_put

Uma função virtual que é chamada para converter um número em uma sequência de `CharType`s que representa o número formatado para uma determinada localidade.

```cpp
virtual iter_type do_put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    bool val) const;

virtual iter_type do_put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    long val) const;

virtual iter_type do_put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    unsigned long val) const;

virtual iter_type do_put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    double val) const;

virtual iter_type do_put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    long double val) const;

virtual iter_type do_put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    const void* val) const;

virtual iter_type do_put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    const long long val) const;

virtual iter_type do_put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    const unsigned long long val) const;
```

### <a name="parameters"></a>Parâmetros

*Próximo*\
Um iterador que trata o primeiro elemento na cadeia de caracteres inserida.

*_Iosbase*\
Foi especificado o fluxo que contém a localidade com a faceta numpunct usada para pontuar a saída e os sinalizadores para a formatação da saída.

*_Fill*\
Um caractere que é usado para espaçamento.

*Val*\
O número ou tipo booliano que será a saída.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda uma posição além do último elemento produzido.

### <a name="remarks"></a>Comentários

A primeira função de membro virtual protegido gera elementos seqüenciais a partir *de próximo* para produzir um campo de saída inteiro a partir do valor de *val*. A função retorna um iterador designando o próximo local para inserir um elemento além do campo de saída inteiro gerado.

O campo de saída inteiro é gerado pelas mesmas regras usadas pelas funções de impressão para gerar uma série de elementos de **char** a um arquivo. Cada elemento de char é assumido para `CharType` mapear para um elemento equivalente de tipo por um simples mapeamento de um para um. No entanto, quando uma função de impressão bloqueia `do_put` um `fill`campo com espaços ou o dígito 0, em vez disso, usa . A especificação de conversão de impressão equivalente é determinada da seguinte forma:

- Se **iosbase**. [bandeiras](../standard-library/ios-base-class.md#flags) & `ios_base::`[oct](../standard-library/ios-functions.md#oct) `lo`oct , a especificação de conversão é .`ios_base::basefield` == 

- Se **iosbase.flags** & **ios_base::hexde** == `ios_base::`[hex](../standard-library/ios-functions.md#hex)campo base, `lx`a especificação de conversão é .

- Caso contrário, a especificação de conversão é `ld`.

Se **iosbase**. [width](../standard-library/ios-base-class.md#width) é diferente de zero, uma largura de campo deste valor é anexado. Em seguida, a função chama **iosbase**. **width**(0) para redefinir a largura do campo como zero.

O preenchimento ocorre apenas se o número mínimo de elementos *N* necessários para especificar o campo de saída for menor que **iosbase**. [largura](../standard-library/ios-base-class.md#width). Esse preenchimento consiste em uma seqüência de cópias de**largura** *N* - de **preenchimento**. O preenchimento ocorre então da seguinte maneira:

- Se **iosbase**. **bandeiras** & `ios_base::`[left](../standard-library/ios-functions.md#left) **-** à esquerda, a bandeira é preparada.`ios_base::adjustfield` ==  (O preenchimento ocorre após o texto gerado.)

- Se **iosbase.flags** & **ios_base:adjustfield** == `ios_base::`[internal](../standard-library/ios-functions.md#internal), o sinalizador **0** será preparado. (Para um campo de saída numérico, o preenchimento ocorre quando as funções de impressão são preenchidas com 0.)

- Caso contrário, nenhum sinalizador adicional é anexado. (O preenchimento ocorre antes da sequência gerada.)

Por fim:

- Se **iosbase**. **sinalizadores** & `ios_base::`[showpos](../standard-library/ios-functions.md#showpos) não é **+** zero, a bandeira é preparada para a especificação de conversão.

- Se **iosbase**. **flags** & **ios_base::**[showbase](../standard-library/ios-functions.md#showbase) não é zero, a bandeira **#** é preparada para a especificação de conversão.

O formato de um campo de saída inteiro é determinado ainda pelo [locale facet](../standard-library/locale-class.md#facet_class)**fac** retornado pela chamada [use_facet](../standard-library/locale-functions.md#use_facet) < [numpunct](../standard-library/numpunct-class.md)\< **Elem**>( **iosbase**. [getloc](../standard-library/ios-base-class.md#getloc)). Especificamente:

- **fac**. [agrupamento](../standard-library/numpunct-class.md#grouping) determina como os dígitos são agrupados à esquerda de qualquer ponto decimal

- **fac**. [thousands_sep](../standard-library/numpunct-class.md#thousands_sep) determina a seqüência que separa grupos de dígitos à esquerda de qualquer ponto decimal

Se nenhuma restrição de agrupamento for imposta por **fac**. **grouping** (o primeiro elemento tem o valor CHAR_MAX), então não há instâncias de **fac**. `thousands_sep` são gerados no campo de saída. Caso contrário, os separadores são inseridos após a conversão de impressão.

A segunda função membro virtual protegida:

```cpp
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,
    CharType _Fill,
    unsigned long val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `lu`.

A terceira função membro virtual protegida:

```cpp
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,
    CharType _Fill,
    double val) const;
```

comporta-se da mesma maneira que a primeira, exceto que gera um campo de saída de ponto flutuante do valor de **val**. **fac**. [decimal_point](../standard-library/numpunct-class.md#decimal_point) determina a sequência que separa os dígitos de inteiros dos dígitos de fração. A especificação de conversão de impressão equivalente é determinada da seguinte forma:

- Se **iosbase**. **bandeiras** & `ios_base::floatfield` == `ios_base::`[fixas,](../standard-library/ios-functions.md#fixed)a `lf`especificação de conversão é .

- Se **iosbase**. **bandeiras** & **ios_base::floatfield** == `ios_base::`[científico,](../standard-library/ios-functions.md#scientific)a `le`especificação de conversão é . Se **iosbase**. **bandeiras** & `ios_base::`[maiúsculas](../standard-library/ios-functions.md#uppercase) não é zero, `e` é substituído por `E`.

- Caso contrário, a especificação de conversão é **Ig**. Se **iosbase**. **bandeiras** & **ios_base::maiúscula** não é zero, `g` é substituída por `G`.

Se **iosbase**. **bandeiras** & **ios_base::fixou** não é zero ou se **iosbase**. [precision](../standard-library/ios-base-class.md#precision) é maior que zero, uma precisão com o valor **iosbase**. **precision** é anexado à especificação de conversão. O preenchimento comporta-se da mesma maneira que um campo de saída inteiro. O caractere de preenchimento é **fill**. Por fim:

- Se **iosbase**. **sinalizadores** & `ios_base::`[showpos](../standard-library/ios-functions.md#showpos) não é **+** zero, a bandeira é preparada para a especificação de conversão.

- Se **iosbase**. **sinalizadores** & `ios_base::`[showpoint](../standard-library/ios-functions.md#showpoint) não é **#** zero, a bandeira é preparada para a especificação de conversão.

A quarta função membro virtual protegida:

```cpp
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,
    CharType _Fill,
    long double val) const;
```

comporta-se da mesma forma no `l` terceiro, exceto que o `L`qualificador na especificação de conversão é substituído por .

A quinta função membro virtual protegida:

```cpp
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,
    CharType _Fill,
    const void* val) const;
```

se comporta como o primeiro, exceto que a especificação de conversão é `p`**,** mais qualquer qualificador necessário para especificar o preenchimento.

A sexta função membro virtual protegida:

```cpp
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,
    CharType _Fill,
    bool val) const;
```

comporta-se da mesma forma que o primeiro, exceto que ele gera um campo de saída booleano de *val*.

Um campo de saída booliano adota um de dois formatos. Se `iosbase.flags & ios_base::` [boolalpha](../standard-library/ios-functions.md#boolalpha) for **falso,** `do_put(_Next, _Iosbase, _Fill, (long)val)`a função do membro retorna, que normalmente produz uma seqüência gerada de 0 (para **falso**) ou 1 (para **verdade**). Caso contrário, a seqüência gerada é *fac*. [nome falso](../standard-library/numpunct-class.md#falsename) (para **falso),** ou *fac*. [nome verdadeiro](../standard-library/numpunct-class.md#truename) (para **verdade**).

A sétima função membro virtual protegida:

```cpp
virtual iter_type do_put(iter_type next,
    ios_base& iosbase,
    Elem fill,
    long long val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `lld`.

A oitava função membro virtual protegida:

```cpp
virtual iter_type do_put(iter_type next,
    ios_base& iosbase,
    Elem fill,
    unsigned long long val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `llu`.

### <a name="example"></a>Exemplo

Consulte o exemplo de [put](#put), que chama `do_put`.

## <a name="num_putiter_type"></a><a name="iter_type"></a>num_put:iter_type

Um tipo que descreve um iterador de saída.

```cpp
typedef OutputIterator iter_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **OutputIterator.**

## <a name="num_putnum_put"></a><a name="num_put"></a>num_put:num_put

O construtor para objetos do tipo `num_put`.

```cpp
explicit num_put(size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o *parâmetro _Refs* e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \>1: Esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)(_ *Refs*).

## <a name="num_putput"></a><a name="put"></a>num_put::put

Converte um número em `CharType`uma seqüência de s que representa o número formatado para um determinado local.

```cpp
iter_type put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    bool val) const;

iter_type put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    long val) const;

iter_type put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    unsigned long val) const;

iter_type put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    Long long val) const;

iter_type put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    Unsigned long long val) const;

iter_type put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    double val) const;

iter_type put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    long double val) const;

iter_type put(
    iter_type dest,
    ios_base& _Iosbase,
    _Elem _Fill,
    const void* val) const;
```

### <a name="parameters"></a>Parâmetros

*Dest*\
Um iterador que trata o primeiro elemento na cadeia de caracteres inserida.

*_Iosbase*\
Foi especificado o fluxo que contém a localidade com a faceta numpunct usada para pontuar a saída e os sinalizadores para a formatação da saída.

*_Fill*\
Um caractere que é usado para espaçamento.

*Val*\
O número ou tipo booliano que será a saída.

### <a name="return-value"></a>Valor retornado

Um iterador de saída que aborda uma posição além do último elemento produzido.

### <a name="remarks"></a>Comentários

Todas as funções do `_Fill`membro `val`retornam [do_put](#do_put)( `next`, `_Iosbase`, , ).

### <a name="example"></a>Exemplo

```cpp
// num_put_put.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany" );
   basic_stringstream<char> psz2;
   ios_base::iostate st = 0;
   long double fVal;
   cout << "The thousands separator is: "
        << use_facet < numpunct <char> >(loc).thousands_sep( )
        << endl;

   psz2.imbue( loc );
   use_facet < num_put < char > >
      ( loc ).put(basic_ostream<char>::_Iter(psz2.rdbuf( ) ),
                    psz2, ' ', fVal=1000.67);

   if ( st & ios_base::failbit )
      cout << "num_put( ) FAILED" << endl;
   else
      cout << "num_put( ) = " << psz2.rdbuf( )->str( ) << endl;
}
```

```Output
The thousands separator is: .
num_put( ) = 1.000,67
```

## <a name="see-also"></a>Confira também

[\<local>](../standard-library/locale.md)\
[Classe faceta](../standard-library/locale-class.md#facet_class)\
[Segurança de threads na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
