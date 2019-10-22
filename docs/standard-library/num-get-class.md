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
ms.openlocfilehash: 5c6fec7002541b519d7cf7d043eed3e5c932bcb9
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689229"
---
# <a name="num_get-class"></a>Classe num_get

Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo `CharType` para valores numéricos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class InputIterator = istreambuf_iterator<CharType>>
class num_get : public locale::facet;
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *CharType*
O tipo usado em um programa para codificar caracteres em uma localidade.

@No__t_1 *InputIterator*
O tipo de iterador do qual as funções get numéricas leem sua entrada.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[num_get](#num_get)|O construtor para objetos do tipo `num_get` que são usados para extrair valores numéricos das sequências.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
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

## <a name="char_type"></a>  num_get::char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **CharType**.

## <a name="do_get"></a>  num_get::do_get

Uma função virtual que é chamada para extrair um valor numérico ou booliano de uma sequência de caracteres.

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned short& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned int& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned long& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long long& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned long long& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    float& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    double& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long double& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    void *& val) const;

virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    bool& val) const;
```

### <a name="parameters"></a>Parâmetros

*primeiro* \
O início do intervalo de caracteres do qual o número será lido.

*última* \
O fim do intervalo de caracteres do qual o número será lido.

@No__t_1 *_Iosbase*
O [ios_base](../standard-library/ios-base-class.md) cujos sinalizadores são usados pela conversão.

@No__t_1 *_State*
O estado para o qual failbit (consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate)) é adicionado após a falha.

*valor* \
O valor que foi lido.

### <a name="return-value"></a>Valor retornado

O iterador depois que o valor foi lido.

### <a name="remarks"></a>Comentários

A primeira função membro virtual protegida,

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long& val) const;
```

faz a correspondência de elementos sequenciais começando no *primeiro* na sequência `[first, last)` até que ele reconheceu um campo de entrada de inteiro completo e não vazio. Se for bem-sucedido, ele converterá esse campo em seu valor equivalente como de tipo **Long**e armazenará o resultado em *Val*. Ele retorna um iterador que designa o primeiro elemento além do campo de entrada numérico. Caso contrário, a função não armazena nada em *Val* e define `ios_base::failbit` em `state`. Ele retorna um iterador que designa o primeiro elemento além de qualquer prefixo de um campo de entrada de inteiro válido. Em ambos os casos, se o valor retornado for igual a `last`, a função definirá `ios_base::eofbit` em `state`.

O campo de entrada de inteiro é convertido pelas mesmas regras usadas pelas funções de verificação para corresponder e converter uma série de elementos **Char** de um arquivo. (Cada elemento **Char** é presumido para mapear para um elemento equivalente do tipo `Elem` por um mapeamento simples, um-para-um.) A especificação de conversão de verificação equivalente é determinada da seguinte maneira:

Se `iosbase.`[ios_base::flags](../standard-library/ios-base-class.md#flags)`() & ios_base::basefield == ios_base::`[oct](../standard-library/ios-functions.md#oct), a especificação de conversão é `lo`.

Se `iosbase.flags() & ios_base::basefield == ios_base::`[hex](../standard-library/ios-functions.md#hex), a especificação de conversão é `lx`.

Se `iosbase.flags() & ios_base::basefield == 0`, a especificação de conversão é `li`.

Caso contrário, a especificação de conversão é `ld`.

O formato de um campo de entrada inteiro é determinado pelo [locale facet](../standard-library/locale-class.md#facet_class)`fac` retornado pela chamada [use_facet](../standard-library/locale-functions.md#use_facet) `<`[numpunct](../standard-library/numpunct-class.md)`<Elem>(iosbase.` [ios_base::getloc](../standard-library/ios-base-class.md#getloc)`())`. Especificamente:

`fac.`[numpunct::grouping](../standard-library/numpunct-class.md#grouping)`()` determina como os dígitos são agrupados à esquerda de qualquer vírgula decimal

`fac.`[numpunct::thousands_sep](../standard-library/numpunct-class.md#thousands_sep)`()` determina a sequência que separa grupos de dígitos à esquerda de qualquer vírgula decimal.

Se nenhuma instância de `fac.thousands_sep()` ocorrer no campo de entrada numérico, nenhuma restrição de agrupamento é imposta. Caso contrário, qualquer restrição de agrupamento imposta pelo `fac.grouping()` será imposta e os separadores serão removidos antes que a verificação de conversão ocorra.

A quarta função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned long& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `lu`. Se for bem-sucedido, ele converterá o campo de entrada numérico em um valor de tipo **sem sinal** e armazenará esse valor em *Val*.

A quinta função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long long& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `lld`. Se for bem-sucedido, ele converterá o campo de entrada numérico em um valor de tipo **longo** e armazenará esse valor em *Val*.

A sexta função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned long long& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `llu`. Se for bem-sucedido, ele converterá o campo de entrada numérico em um valor de tipo **sem sinal longo** e armazenará esse valor em *Val*.

A sétima função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    float& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que esforça-se para corresponder a um campo de entrada de ponto flutuante completo e não vazio. `fac.`[numpunct::decimal_point](../standard-library/numpunct-class.md#decimal_point)`()` determina a sequência que separa os dígitos de inteiro dos dígitos de fração. O especificador de conversão de verificação equivalente é `lf`.

A oitava função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    double& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que esforça-se para corresponder a um campo de entrada de ponto flutuante completo e não vazio. `fac.`[numpunct::decimal_point](../standard-library/numpunct-class.md#decimal_point)`()` determina a sequência que separa os dígitos de inteiro dos dígitos de fração. O especificador de conversão de verificação equivalente é `lf`.

A nona função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long double& val) const;
```

comporta-se da mesma maneira que a oitava, exceto que o especificador de conversão de verificação equivalente é `Lf`.

A décima função membro protegido virtual:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    void *& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que o especificador de conversão de verificação equivalente é `p`.

A última (décima primeira) função membro virtual protegida:

```cpp
virtual iter_type do_get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    bool& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que esforça-se para corresponder a um campo de entrada booliano completo e não vazio. Se for bem-sucedido, ele converterá o campo de entrada booliano em um valor do tipo **bool** e armazenará esse valor em *Val*.

Um campo de entrada Booliano adota um de dois formatos. Se `iosbase.flags() & ios_base::`[boolalpha](../standard-library/ios-functions.md#boolalpha) for false, será o mesmo que um campo de entrada inteiro, exceto que o valor convertido deve ser 0 (para false) ou 1 (para true). Caso contrário, a sequência deve corresponder a `fac.`[numpunct::falsename](../standard-library/numpunct-class.md#falsename)`()` (para falso) ou `fac.`[numpunct::truename](../standard-library/numpunct-class.md#truename)`()` (para verdadeiro).

### <a name="example"></a>Exemplo

Veja o exemplo de [obter](#get), em que a função membro virtual é chamada por `do_get`.

## <a name="get"></a>  num_get::get

Extrai um valor numérico ou booliano de uma sequência de caracteres.

```cpp
iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    bool& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned short& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned int& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned long& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long long& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned long long& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    float& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    double& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long double& val) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    void *& val) const;
```

### <a name="parameters"></a>Parâmetros

*primeiro* \
O início do intervalo de caracteres do qual o número será lido.

*última* \
O fim do intervalo de caracteres do qual o número será lido.

@No__t_1 *_Iosbase*
O [ios_base](../standard-library/ios-base-class.md) cujos sinalizadores são usados pela conversão.

@No__t_1 *_State*
O estado para o qual failbit (consulte [ios_base::iostate](../standard-library/ios-base-class.md#iostate)) é adicionado após a falha.

*valor* \
O valor que foi lido.

### <a name="return-value"></a>Valor retornado

O iterador depois que o valor foi lido.

### <a name="remarks"></a>Comentários

Todas as funções membro retornam [do_get](#do_get)( `first`, `last`, `_Iosbase`, `_State`, `val`).

A primeira função membro virtual protegida virtual tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [ `first`, `last`) até ter reconhecido um campo de entrada inteiro completo e não vazio. Se for bem-sucedido, ele converterá esse campo em seu valor equivalente, conforme o tipo **Long** , e armazenará o resultado em *Val*. Ele retorna um iterador que designa o primeiro elemento além do campo de entrada numérico. Caso contrário, a função não armazena nada em *Val* e define `ios_base::failbit` no *estado*_. Ele retorna um iterador que designa o primeiro elemento além de qualquer prefixo de um campo de entrada de inteiro válido. Em ambos os casos, se o valor de retorno for igual a *Last*, a função definirá `ios_base::eofbit` em *_State*.

O campo de entrada de inteiro é convertido pelas mesmas regras usadas pelas funções de verificação para corresponder e converter uma série de elementos **Char** de um arquivo. Cada elemento **Char** é presumido para mapear para um elemento equivalente do tipo `CharType` por um mapeamento simples de um-para-um. A especificação de conversão de verificação equivalente é determinada da seguinte forma:

- Se `iosbase`. [flags](../standard-library/ios-base-class.md#flags)  &  `ios_base::basefield`  ==  `ios_base::`[Oct](../standard-library/ios-functions.md#oct), a especificação de conversão é `lo`.

- Se **iosbase. flags**  & **ios_base:: basefield**  ==  `ios_base::`[hex](../standard-library/ios-functions.md#hex), a especificação de conversão será `lx`.

- Se **iosbase.flags** & **ios_base::basefield** == 0, a especificação de conversão é `li`.

- Caso contrário, a especificação de conversão é `ld`.

O formato de um campo de entrada inteiro é determinado ainda pelo [locale facet](../standard-library/locale-class.md#facet_class)**fac** retornado pela chamada [use_facet](../standard-library/locale-functions.md#use_facet) < [numpunct](../standard-library/numpunct-class.md)\< **Elem**>( **iosbase**. [getloc](../standard-library/ios-base-class.md#getloc)). Especificamente:

- **fac**. [grouping](../standard-library/numpunct-class.md#grouping) determina como os dígitos são agrupados à esquerda da vírgula decimal.

- **fac**. [thousands_sep](../standard-library/numpunct-class.md#thousands_sep) determina a sequência que separa grupos de dígitos à esquerda da vírgula decimal.

Se nenhuma instância de **fac**. `thousands_sep` ocorre no campo de entrada numérico, nenhuma restrição de agrupamento é imposta. Caso contrário, qualquer restrição de agrupamento é imposta por **fac**. **grouping** é imposto e os separadores são removidos antes da conversão de verificação ocorrer.

A segunda função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    unsigned long& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `lu`. Se obtiver êxito, ele converterá o campo de entrada numérico em um valor de tipo **sem sinal** e armazenará esse valor em *Val*.

A terceira função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    double& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que esforça-se para corresponder a um campo de entrada de ponto flutuante completo e não vazio. **fac**. [decimal_point](../standard-library/numpunct-class.md#decimal_point) determina a sequência que separa os dígitos de inteiros dos dígitos de fração. O especificador de conversão de verificação equivalente é `lf`.

A quarta função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long double& val) const;
```

comporta-se a terceira, exceto que o especificador de conversão de verificação equivalente é `Lf`.

A quinta função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    void *& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que o especificador de conversão de verificação equivalente é `p`.

A sexta função membro virtual protegida:

```cpp
virtual iter_type do_get(iter_type first,
    iter_type last,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    bool& val) const;
```

comporta-se da mesma maneira que a primeira, exceto que tenta corresponder a um campo de entrada booliano completo e não vazio. Se for bem-sucedido, ele converterá o campo de entrada booliano em um valor do tipo **bool** e armazenará esse valor em *Val*.

Um campo de entrada booliano adota um de dois formatos. Se **iosbase**. Se **flags** & `ios_base::`[boolalpha](../standard-library/ios-functions.md#boolalpha) for **false**, será o mesmo que um campo de entrada inteiro, exceto que o valor convertido deve ser 0 (para **false**) ou 1 (para **true**). Caso contrário, a sequência deve corresponder a **fac**. [falsename](../standard-library/numpunct-class.md#falsename) (para **false**) ou **fac**. [truename](../standard-library/numpunct-class.md#truename) (para **true**).

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

## <a name="iter_type"></a>  num_get::iter_type

Um tipo que descreve um iterador de entrada.

```cpp
typedef InputIterator iter_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `InputIterator`.

## <a name="num_get"></a>  num_get::num_get

O construtor para objetos do tipo `num_get` que são usados para extrair valores numéricos das sequências.

```cpp
explicit num_get(size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *_Refs*
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *_Refs* e seu significado são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \> 1: esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **locale::** [facet](../standard-library/locale-class.md#facet_class)( `_Refs`).

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)\
[Classe facet](../standard-library/locale-class.md#facet_class)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
