---
title: Classe num_put | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- xlocnum/std::num_put
- locale/std::num_put::char_type
- locale/std::num_put::iter_type
- locale/std::num_put::do_put
- locale/std::num_put::put
dev_langs:
- C++
helpviewer_keywords:
- std::num_put [C++]
- std::num_put [C++], char_type
- std::num_put [C++], iter_type
- std::num_put [C++], do_put
- std::num_put [C++], put
ms.assetid: 36c5bffc-8283-4201-8ed4-78c4d81f8a17
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f25ebb3cc763947ca0ee88d95d0b7a1d284d157f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="numput-class"></a>Classe num_put
Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores numéricos em sequências do tipo `CharType`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType,  
    class OutputIterator = ostreambuf_iterator<CharType>>  
class num_put : public locale::facet;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres em uma localidade.  
  
 `OutputIterator`  
 O tipo de iterador para o qual as funções put numéricas gravam sua saída.  
  
## <a name="remarks"></a>Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[num_put](#num_put)|O construtor para objetos do tipo `num_put`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[iter_type](#iter_type)|Um tipo que descreve um iterador de saída.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[do_put](#do_put)|Uma função virtual que é chamada para converter um número em uma sequência de `CharType`s que representa o número formatado para uma determinada localidade.|  
|[put](#put)|Converte um número em uma sequência de `CharType`s que representa o número formatado para uma determinada localidade.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
##  <a name="char_type"></a>  num_put::char_type  
 Um tipo que é usado para descrever um caractere usado por uma localidade.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType**.  
  
##  <a name="do_put"></a>  num_put::do_put  
 Uma função virtual que é chamada para converter um número em uma sequência de **CharType**s que representa o número formatado para uma determinada localidade.  
  
```  
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
 `next`  
 Um iterador que trata o primeiro elemento na cadeia de caracteres inserida.  
  
 `_Iosbase`  
 Foi especificado o fluxo que contém a localidade com a faceta numpunct usada para pontuar a saída e os sinalizadores para a formatação da saída.  
  
 `_Fill`  
 Um caractere que é usado para espaçamento.  
  
 `val`  
 O número ou tipo booliano que será a saída.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída que aborda uma posição além do último elemento produzido.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro protegida virtual gera elementos sequenciais começando em `next` para produzir um campo de saída inteiro do valor de `val`. A função retorna um iterador designando o próximo local para inserir um elemento além do campo de saída inteiro gerado.  
  
 O campo de saída inteiro é gerado pelas mesmas regras usadas pelas funções de impressão para gerar uma série de elementos `char` para um arquivo. Cada elemento char é considerado mapeado para um elemento equivalente do tipo **CharType** por um mapeamento um para um simples. Quando uma função de impressão preenche um campo com espaços ou o dígito 0, no entanto, `do_put` usa **fill**. A especificação de conversão de impressão equivalente é determinada da seguinte forma:  
  
-   Se **iosbase**. [flags](../standard-library/ios-base-class.md#flags) & `ios_base::basefield` == `ios_base::`[oct](../standard-library/ios-functions.md#oct), a especificação de conversão é **lo**.  
  
-   Se **iosbase.flags** & **ios_base::basefield** == `ios_base::`[hex](../standard-library/ios-functions.md#hex), a especificação de conversão é **lx**.  
  
-   Caso contrário, a especificação de conversão é **Id**.  
  
 Se **iosbase**. [width](../standard-library/ios-base-class.md#width) é diferente de zero, uma largura de campo deste valor é anexado. Em seguida, a função chama **iosbase**. **width**(0) para redefinir a largura do campo como zero.  
  
 O preenchimento ocorre apenas se o número mínimo de elementos *N* necessários para especificar o campo de saída for menor que **iosbase**. [width](../standard-library/ios-base-class.md#width). Esse preenchimento consiste em uma sequência de *N* - **largura** copia de **preenchimento**. O preenchimento ocorre então da seguinte maneira:  
  
-   Se **iosbase**. **sinalizadores de** & `ios_base::adjustfield` == `ios_base::`[esquerdo](../standard-library/ios-functions.md#left), o sinalizador  **-**  é anexado. (O preenchimento ocorre após o texto gerado.)  
  
-   Se **iosbase.flags** & **ios_base::adjustfield** == `ios_base::`[internal](../standard-library/ios-functions.md#internal), o sinalizador **0** é anexado. (Para um campo de saída numérico, o preenchimento ocorre quando as funções de impressão são preenchidas com 0.)  
  
-   Caso contrário, nenhum sinalizador adicional é anexado. (O preenchimento ocorre antes da sequência gerada.)  
  
 Por fim:  
  
-   Se **iosbase**. **flags** & `ios_base::`[showpos](../standard-library/ios-functions.md#showpos) é diferente de zero, o sinalizador **+** é anexado à especificação de conversão.  
  
-   Se **iosbase**. **flags** & **ios_base::**[showbase](../standard-library/ios-functions.md#showbase) é diferente de zero, o sinalizador **#** é anexado à especificação de conversão.  
  
 O formato de um campo de saída inteiro é determinado ainda pelo [locale facet](../standard-library/locale-class.md#facet_class)**fac** retornado pela chamada [use_facet](../standard-library/locale-functions.md#use_facet) < [numpunct](../standard-library/numpunct-class.md)\< **Elem**>( **iosbase**. [getloc](../standard-library/ios-base-class.md#getloc)). Especificamente:  
  
- **fac**. [grouping](../standard-library/numpunct-class.md#grouping) determina como os dígitos são agrupados à esquerda da vírgula decimal  
  
- **fac**. [thousands_sep](../standard-library/numpunct-class.md#thousands_sep) determina a sequência que separa grupos de dígitos à esquerda da vírgula decimal  
  
 Se nenhuma restrição de agrupamento for imposta por **fac**. **grouping** (o primeiro elemento tem o valor CHAR_MAX), então não há instâncias de **fac**. `thousands_sep` são gerados no campo de saída. Caso contrário, os separadores são inseridos após a conversão de impressão.  
  
 A segunda função membro virtual protegida:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    unsigned long val) const;
```  
  
 comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de **Id** por **lu**.  
  
 A terceira função membro virtual protegida:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    double val) const;
```  
  
 comporta-se da mesma maneira que a primeira, exceto que gera um campo de saída de ponto flutuante do valor de **val**. **fac**. [decimal_point](../standard-library/numpunct-class.md#decimal_point) determina a sequência que separa os dígitos de inteiros dos dígitos de fração. A especificação de conversão de impressão equivalente é determinada da seguinte forma:  
  
-   Se **iosbase**. **flags** & `ios_base::floatfield` == `ios_base::`[fixed](../standard-library/ios-functions.md#fixed), a especificação de conversão é **lf**.  
  
-   Se **iosbase**. **flags** & **ios_base::floatfield** == `ios_base::`[scientific](../standard-library/ios-functions.md#scientific), a especificação de conversão é `le`. Se **iosbase**. **flags** & `ios_base::`[uppercase](../standard-library/ios-functions.md#uppercase) é diferente de zero **e** é substituído por **E**.  
  
-   Caso contrário, a especificação de conversão é **Ig**. Se **iosbase**. **flags** & **ios_base::uppercase** é diferente de zero, **g** é substituído por **G**.  
  
 Se **iosbase**. **flags** & **ios_base::fixed** se for diferente de zero ou se **iosbase**. [precision](../standard-library/ios-base-class.md#precision) é maior que zero, uma precisão com o valor **iosbase**. **precision** é anexado à especificação de conversão. O preenchimento comporta-se da mesma maneira que um campo de saída inteiro. O caractere de preenchimento é **fill**. Por fim:  
  
-   Se **iosbase**. **flags** & `ios_base::`[showpos](../standard-library/ios-functions.md#showpos) é diferente de zero, o sinalizador **+** é anexado à especificação de conversão.  
  
-   Se **iosbase**. **flags** & `ios_base::`[showpoint](../standard-library/ios-functions.md#showpoint) é diferente de zero, o sinalizador **#** é anexado à especificação de conversão.  
  
 A quarta função membro virtual protegida:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    long double val) const;
```  
  
 se comporta como o terceiro, exceto que o qualificador **l** na especificação de conversão é substituído por **L**.  
  
 A quinta função membro virtual protegida:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    const void* val) const;
```  
  
 se comporta como o primeiro, exceto que a especificação de conversão é `p`**,** mais qualquer qualificador necessário para especificar o preenchimento.  
  
 A sexta função membro virtual protegida:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    bool val) const;
```  
  
 comporta-se da mesma maneira que a primeira, exceto que gera um campo de saída booliano de `val`.  
  
 Um campo de saída booliano adota um de dois formatos. Se **iosbase**. **flags** & `ios_base::`[boolalpha](../standard-library/ios-functions.md#boolalpha) é **false**, a função membro retorna `do_put`(_ *Next*, \_ *Iosbase*, \_ *Fill*, ( **long**) `val`), que geralmente produz uma sequência gerada de 0 (para **false**) ou 1 (para **true**). Caso contrário, a sequência gerada é **fac**. [falsename](../standard-library/numpunct-class.md#falsename)`)` (para **false**) ou **fac**. [truename](../standard-library/numpunct-class.md#truename) (para **true**).  
  
 A sétima função membro virtual protegida:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& iosbase,  
    Elem fill,
    long long val) const;
```  
  
 comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de **Id** por **lld**.  
  
 A oitava função membro virtual protegida:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& iosbase,  
    Elem fill,
    unsigned long long val) const;
```  
  
 comporta-se da mesma maneira que a primeira, exceto que substitui uma especificação de conversão de `ld` por `llu`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [put](#put), que chama `do_put`.  
  
##  <a name="iter_type"></a>  num_put::iter_type  
 Um tipo que descreve um iterador de saída.  
  
```  
typedef OutputIterator iter_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **OutputIterator.**  
  
##  <a name="num_put"></a>  num_put::num_put  
 O construtor para objetos do tipo `num_put`.  
  
```  
explicit num_put(size_t _Refs = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Refs`  
 Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.  
  
### <a name="remarks"></a>Comentários  
 Os valores possíveis para o parâmetro `_Refs` e sua significância são:  
  
-   0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.  
  
-   1: o tempo de vida do objeto deve ser gerenciado manualmente.  
  
-   \> 1: esses valores não são definidos.  
  
 Nenhum exemplo direto é possível, pois o destruidor está protegido.  
  
 O construtor inicializa seu objeto base com **locale::**[facet](../standard-library/locale-class.md#facet_class)(_ *Refs*).  
  
##  <a name="put"></a>  num_put::put  
 Converte um número em uma sequência de **CharType**s que representa o número formatado para uma determinada localidade.  
  
```  
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
 `dest`  
 Um iterador que trata o primeiro elemento na cadeia de caracteres inserida.  
  
 `_Iosbase`  
 Foi especificado o fluxo que contém a localidade com a faceta numpunct usada para pontuar a saída e os sinalizadores para a formatação da saída.  
  
 `_Fill`  
 Um caractere que é usado para espaçamento.  
  
 `val`  
 O número ou tipo booliano que será a saída.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída que aborda uma posição além do último elemento produzido.  
  
### <a name="remarks"></a>Comentários  
 Todas as funções membro retornam [do_put](#do_put)( `next`, `_Iosbase`, `_Fill`, `val`).  
  
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
  
## <a name="see-also"></a>Consulte também  
 [\<locale>](../standard-library/locale.md)   
 [Classe facet](../standard-library/locale-class.md#facet_class)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

