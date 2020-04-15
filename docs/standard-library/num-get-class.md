---
title: Classe num_get
ms.date: 11/04/2016
f1_keywords:
- xlocnum/std::num_get
- locale/std::num_get::char_type
- locale/std::num_get::iter_type
- locale/std::num_get::do_get
- locale/std::num_get::get
helpviewer_keywords:
- std::num_get [C++]
- std::num_get [C++], char_type
- std::num_get [C++], iter_type
- std::num_get [C++], do_get
- std::num_get [C++], get
ms.assetid: 9933735d-3918-4b17-abad-5fca2adc62d7
ms.openlocfilehash: 76d2832141c65ca67c42f1994a3c8f5b532f0092
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373652"
---
# <a name="num_get-class"></a>Classe num_get

Um modelo de classe que descreve um objeto que pode servir como uma `CharType` faceta local para controlar conversões de seqüências de tipo para valores numéricos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class InputIterator = istreambuf_iterator<CharType>>
class num_get : public locale::facet;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres em uma localidade.

*Inseriterador*\
O tipo de iterador do qual as funções get numéricas leem sua entrada.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[num_get](#num_get)|O construtor para objetos do tipo `num_get` que são usados para extrair valores numéricos das sequências.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|
|[iter_type](#iter_type)|Um tipo que descreve um iterador de entrada.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[do_get](#do_get)|Uma função virtual que é chamada para extrair um valor numérico ou booliano de uma sequência de caracteres.|
|[get](#get)|Extrai um valor numérico ou booliano de uma sequência de caracteres.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="num_getchar_type"></a><a name="char_type"></a>num_get:char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo **CharType**.

## <a name="num_getdo_get"></a><a name="do_get"></a>num_get::do_get

Uma função virtual que é chamada para extrair um valor numérico ou booliano de uma sequência de caracteres.

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned short& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned int& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned long& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long long& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned long long& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    float& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    double& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long double& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    void *& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    bool& val) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
O início do intervalo de caracteres do qual o número será lido.

*Última*\
O fim do intervalo de caracteres do qual o número será lido.

*iosbase*\
O [ios_base](../standard-library/ios-base-class.md) cujos sinalizadores são usados pela conversão.

*Estado*\
O estado para o qual failbit (consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate)) é adicionado após a falha.

*Val*\
O valor que foi lido.

### <a name="return-value"></a>Valor retornado

O iterador depois que o valor foi lido.

### <a name="remarks"></a>Comentários

A primeira função membro virtual protegida,

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long& val) const;
```

corresponde aos elementos seqüenciais `[first, last)` que começam *inicialmente* na seqüência até que tenha reconhecido um campo de entrada inteiro completo e não vazio. Se for bem sucedido, converte este campo para seu valor equivalente como tipo **longo**, e armazena o resultado em *val*. Ele retorna um iterador que designa o primeiro elemento além do campo de entrada numérico. Caso contrário, a função não `ios_base::failbit` armazena `state`nada em *val* e se instala em . Ele retorna um iterador que designa o primeiro elemento além de qualquer prefixo de um campo de entrada de inteiro válido. Em ambos os casos, se o valor retornado for igual a `last`, a função definirá `ios_base::eofbit` em `state`.

O campo de entrada inteiro é convertido pelas mesmas regras usadas pelas funções de varredura para correspondência e conversão de uma série de elementos de **char** de um arquivo. (Cada elemento **de char** é assumido para `Elem` mapear para um elemento equivalente de tipo por um simples mapeamento,um-para-um.) A especificação de conversão de varredura equivalente é determinada da seguinte forma:

Se `iosbase.` [ios_base::flags](../standard-library/ios-base-class.md#flags)`() & ios_base::basefield == ios_base::`[oct](../standard-library/ios-functions.md#oct), a `lo`especificação de conversão é .

Se `iosbase.flags() & ios_base::basefield == ios_base::`[hex](../standard-library/ios-functions.md#hex), a especificação de conversão é `lx`.

Se `iosbase.flags() & ios_base::basefield == 0`, a especificação de conversão é `li`.

Caso contrário, a especificação de conversão é `ld`.

O formato de um campo de entrada inteiro é ainda mais determinado pela [faceta](../standard-library/locale-class.md#facet_class) `fac` local retornada pela chamada [use_facet](../standard-library/locale-functions.md#use_facet) `<` [numpunct](../standard-library/numpunct-class.md)`<Elem>(iosbase.`[ios_base::getloc](../standard-library/ios-base-class.md#getloc)`())`. Especificamente:

`fac.`[numpunct::o agrupamento](../standard-library/numpunct-class.md#grouping) `()` determina como os dígitos são agrupados à esquerda de qualquer ponto decimal

`fac.`[numpunct::thousands_sep](../standard-library/numpunct-class.md#thousands_sep) `()` determina a seqüência que separa grupos de dígitos à esquerda de qualquer ponto decimal.

Se nenhuma instância de `fac.thousands_sep()` ocorrer no campo de entrada numérico, nenhuma restrição de agrupamento é imposta. Caso contrário, qualquer restrição de agrupamento imposta pelo `fac.grouping()` será imposta e os separadores serão removidos antes que a verificação de conversão ocorra.

A quarta função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned long& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `lu`. Se for bem-sucedido, converte o campo de entrada numérico em um valor de tipo **longo não assinado** e armazena esse valor em *val*.

A quinta função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long long& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `lld`. Se for bem-sucedido, converte o campo de entrada numérico em um valor de tipo **longo** e armazena esse valor em *val*.

A sexta função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned long long& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `llu`. Se for bem-sucedido, converte o campo de entrada numérico em um valor de longo **prazo não assinado** e armazena esse valor em *val*.

A sétima função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    float& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que esforça-se para corresponder a um campo de entrada de ponto flutuante completo e não vazio. `fac.`[numpunct::decimal_point](../standard-library/numpunct-class.md#decimal_point) `()` determina a seqüência que separa os dígitos inteiros dos dígitos de fração. O especificador de conversão de verificação equivalente é `lf`.

A oitava função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    double& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que esforça-se para corresponder a um campo de entrada de ponto flutuante completo e não vazio. `fac.`[numpunct::decimal_point](../standard-library/numpunct-class.md#decimal_point) `()` determina a seqüência que separa os dígitos inteiros dos dígitos de fração. O especificador de conversão de verificação equivalente é `lf`.

A nona função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long double& val) const;
```

comporta-se da mesma maneira que a oitava, exceto que o especificador de conversão de verificação equivalente é `Lf`.

A décima função de membro virtual protegido:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    void *& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que o especificador de conversão de verificação equivalente é `p`.

A última (décima primeira) função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    bool& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que esforça-se para corresponder a um campo de entrada booliano completo e não vazio. Se for bem sucedido, converte o campo de entrada booleano em um valor de **tipo bool** e armazena esse valor em *val*.

Um campo de entrada Booliano adota um de dois formatos. Se `iosbase.flags() & ios_base::`[boolalpha](../standard-library/ios-functions.md#boolalpha) for false, será o mesmo que um campo de entrada inteiro, exceto que o valor convertido deve ser 0 (para false) ou 1 (para true). Caso contrário, a seqüência deve corresponder `fac.` [a numpunct::falsename](../standard-library/numpunct-class.md#falsename) `()` (para falso) ou `fac.` [numpunct::truename](../standard-library/numpunct-class.md#truename) `()` (para true).

### <a name="example"></a>Exemplo

Veja o exemplo de [obter](#get), em que a função membro virtual é chamada por `do_get`.

## <a name="num_getget"></a><a name="get"></a>num_get::get

Extrai um valor numérico ou booliano de uma sequência de caracteres.

```cpp
iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    bool& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned short& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned int& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned long& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long long& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned long long& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    float& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    double& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long double& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    void *& val) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
O início do intervalo de caracteres do qual o número será lido.

*Última*\
O fim do intervalo de caracteres do qual o número será lido.

*iosbase*\
O [ios_base](../standard-library/ios-base-class.md) cujos sinalizadores são usados pela conversão.

*Estado*\
O estado para o qual failbit (consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate)) é adicionado após a falha.

*Val*\
O valor que foi lido.

### <a name="return-value"></a>Valor retornado

O iterador depois que o valor foi lido.

### <a name="remarks"></a>Comentários

Todas as funções do membro retornam [do_get](#do_get)`( first, last, iosbase, state, val)`.

A primeira função membro virtual protegida virtual tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [ `first`, `last`) até ter reconhecido um campo de entrada inteiro completo e não vazio. Se for bem sucedido, converte este campo para seu valor equivalente como tipo **longo** e armazena o resultado em *val*. Ele retorna um iterador que designa o primeiro elemento além do campo de entrada numérico. Caso contrário, a função *val* não `ios_base::failbit` armazena nada em val e define no *estado.* Ele retorna um iterador que designa o primeiro elemento além de qualquer prefixo de um campo de entrada de inteiro válido. Em ambos os casos, se o valor `ios_base::eofbit` de retorno for igual ao *último,* a função se configura no *estado*.

O campo de entrada inteiro é convertido pelas mesmas regras usadas pelas funções de varredura para correspondência e conversão de uma série de elementos de **char** de um arquivo. Cada elemento **de char** é assumido para `CharType` mapear para um elemento equivalente de tipo por um simples mapeamento de um para um. A especificação de conversão de verificação equivalente é determinada da seguinte forma:

- Se `iosbase.` [sinalizadores](../standard-library/ios-base-class.md#flags)`& ios_base::basefield == ios_base::`[oct](../standard-library/ios-functions.md#oct), `lo`a especificação de conversão é .

- Se `iosbase.flags & ios_base::basefield == ios_base::`[hex](../standard-library/ios-functions.md#hex), a especificação de conversão é `lx`.

- Se `iosbase.flags & ios_base::basefield == 0`, a especificação de conversão é `li`.

- Caso contrário, a especificação de conversão é `ld`.

O formato de um campo de entrada inteiro é ainda mais determinado pela [faceta](../standard-library/locale-class.md#facet_class) `fac` local retornada pela chamada [use_facet](../standard-library/locale-functions.md#use_facet)`<`[`numpunct`](../standard-library/numpunct-class.md)`<Elem>(iosbase.`[getloc](../standard-library/ios-base-class.md#getloc)`())`. Especificamente:

- `fac.`[o agrupamento](../standard-library/numpunct-class.md#grouping) determina como os dígitos são agrupados à esquerda de qualquer ponto decimal.

- `fac.`[thousands_sep](../standard-library/numpunct-class.md#thousands_sep) determina a seqüência que separa grupos de dígitos à esquerda de qualquer ponto decimal.

Se nenhuma instância de `fac.thousands_sep` ocorrer no campo de entrada numérico, nenhuma restrição de agrupamento é imposta. Caso contrário, quaisquer restrições de `fac.grouping` agrupamento impostas por é aplicada e os separadores são removidos antes que a conversão de varredura ocorra.

A segunda função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    unsigned long& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `lu`. Se for bem-sucedido, converte o campo de entrada numérico em um valor de tipo **longo não assinado** e armazena esse valor em *val*.

A terceira função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    double& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que esforça-se para corresponder a um campo de entrada de ponto flutuante completo e não vazio. `fac.`[decimal_point](../standard-library/numpunct-class.md#decimal_point) determina a seqüência que separa os dígitos inteiros dos dígitos de fração. O especificador de conversão de verificação equivalente é `lf`.

A quarta função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    long double& val) const;
```

comporta-se da mesma forma no terceiro, exceto `Lf`que o especificador de conversão de varredura equivalente é .

A quinta função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    void *& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que o especificador de conversão de verificação equivalente é `p`.

A sexta função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    bool& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que tenta corresponder a um campo de entrada booliano completo e não vazio. Se for bem sucedido, converte o campo de entrada booleano em um valor de **tipo bool** e armazena esse valor em *val*.

Um campo de entrada booliano adota um de dois formatos. Se `iosbase.flags & ios_base::` [boolalpha](../standard-library/ios-functions.md#boolalpha) é **falso,** é o mesmo que um campo de entrada inteiro, exceto que o valor convertido deve ser 0 (para **falso**) ou 1 (para **verdadeiro**). Caso contrário, a seqüência deve coincidir `fac.`com nome [falso](../standard-library/numpunct-class.md#falsename) **(falso)** ou `fac.` [nome verdadeiro](../standard-library/numpunct-class.md#truename) (para **verdadeiro**).

### <a name="example"></a>Exemplo

```cpp
// num_get_get.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
using namespace std;
int main( )
{
   locale loc( "german_germany" );

   basic_stringstream<char> psz, psz2;
   psz << "-1000,56";

   ios_base::iostate st = 0;
   long double fVal;
   cout << use_facet <numpunct <char> >(loc).thousands_sep( ) << endl;

   psz.imbue( loc );
   use_facet <num_get <char> >
   (loc).get( basic_istream<char>::_Iter( psz.rdbuf( ) ),
           basic_istream<char>::_Iter(0), psz, st, fVal );

   if ( st & ios_base::failbit )
      cout << "money_get( ) FAILED" << endl;
   else
      cout << "money_get( ) = " << fVal << endl;
}
```

## <a name="num_getiter_type"></a><a name="iter_type"></a>num_get:iter_type

Um tipo que descreve um iterador de entrada.

```cpp
typedef InputIterator iter_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `InputIterator`.

## <a name="num_getnum_get"></a><a name="num_get"></a>num_get:num_get

O construtor para objetos do tipo `num_get` que são usados para extrair valores numéricos das sequências.

```cpp
explicit num_get(size_t refs = 0);
```

### <a name="parameters"></a>Parâmetros

*Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *dos árbitros* e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \>1: Esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto `locale::`base com [faceta](../standard-library/locale-class.md#facet_class)`(refs)`.

## <a name="see-also"></a>Confira também

[\<local>](../standard-library/locale.md)\
[Classe faceta](../standard-library/locale-class.md#facet_class)\
[Segurança de threads na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
