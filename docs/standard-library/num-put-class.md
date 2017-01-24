---
title: "Classe num_put | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::num_put"
  - "xlocnum/std::num_put"
  - "num_put"
  - "std.num_put"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe num_put"
ms.assetid: 36c5bffc-8283-4201-8ed4-78c4d81f8a17
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe num_put
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

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
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em **id.**  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[num_put](#num_put__num_put)|O construtor para objetos do tipo `num_put`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#num_put__char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[iter_type](#num_put__iter_type)|Um tipo que descreve um iterador de saída.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[do_put](#num_put__do_put)|Uma função virtual que é chamada para converter um número em uma sequência de `CharType`s que representa o número formatado para uma determinada localidade.|  
|[colocar](#num_put__put)|Converte um número em uma sequência de `CharType`s que representa o número formatado para uma determinada localidade.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< localidade>  
  
 **Namespace:** std  
  
##  <a name="a-namenumputchartypea-numputchartype"></a><a name="num_put__char_type"></a>  num_put:: char_type  
 Um tipo que é usado para descrever um caractere usado por uma localidade.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **CharType**.  
  
##  <a name="a-namenumputdoputa-numputdoput"></a><a name="num_put__do_put"></a>  num_put:: do_put  
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
 ` next`  
 Um iterador que trata o primeiro elemento da cadeia de caracteres inserida.  
  
 `_Iosbase`  
 Especificado no fluxo que contém a localidade com a faceta numpunct usada para pontuar os sinalizadores para a formatação de saída e saída.  
  
 `_Fill`  
 Um caractere que é usado para espaçamento.  
  
 ` val`  
 O número ou tipo booliano que será a saída.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída produzida de uma posição além do último elemento os endereços.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro protegido virtual gera elementos sequenciais começando no ` next` para produzir um campo de saída inteiro do valor de ` val`. A função retorna um iterador designando o local para inserir um elemento além do campo de saída gerado inteiro.  
  
 O campo de saída inteiro é gerado pelas mesmas regras usadas pelas funções de impressão para gerar uma série de `char` elementos em um arquivo. Cada elemento de char tais será considerado para mapear para um elemento equivalente do tipo **CharType** por um mapeamento simple, um para um. Quando uma função de impressão acrescenta um campo com espaços ou dígito 0, no entanto, `do_put` usa **preenchimento**. A especificação de conversão impressão equivalente é determinada como segue:  
  
-   Se **iosbase**. [sinalizadores de](../standard-library/ios-base-class.md#ios_base__flags) & `ios_base::basefield` == `ios_base::`[oct](../Topic/%3Cios%3E%20functions.md#oct), a especificação de conversão é **lo**.  
  
-   Se **iosbase.flags** & **ios_base::basefield** == `ios_base::`[hexadecimal](../Topic/%3Cios%3E%20functions.md#hex), a especificação de conversão é **lx**.  
  
-   Caso contrário, a especificação de conversão é **ld**.  
  
 Se **iosbase**. [largura](../standard-library/ios-base-class.md#ios_base__width) é diferente de zero, uma largura de campo desse valor é anexada. Em seguida, chama a função **iosbase**. **largura**para redefinir a largura do campo como zero (0).  
  
 Preenchimento ocorre apenas se o número mínimo de elementos *N* necessárias para especificar o campo de saída é menor que **iosbase**. [largura](../standard-library/ios-base-class.md#ios_base__width). Esse preenchimento consiste em uma sequência de *N* – **largura** copia de **preenchimento**. Em seguida, preenchimento ocorre da seguinte maneira:  
  
-   Se **iosbase**. **sinalizadores de** & `ios_base::adjustfield` == `ios_base::`[esquerda](../Topic/%3Cios%3E%20functions.md#left), o sinalizador **–** é anexado. (Preenchimento ocorre após o texto gerado.)  
  
-   Se **iosbase.flags** & **ios_base::adjustfield** == `ios_base::`[interno](../Topic/%3Cios%3E%20functions.md#internal), o sinalizador **0** é anexado. (Para um campo de saída numérico, preenchimento ocorre em que as funções de cópia preencher com 0.)  
  
-   Caso contrário, nenhum sinalizador adicional é acrescentado. (Preenchimento ocorre antes da sequência gerada).  
  
 Por fim:  
  
-   Se **iosbase**. **sinalizadores de** & `ios_base::`[showpos](../Topic/%3Cios%3E%20functions.md#showpos) é diferente de zero, o sinalizador **+** é anexado à especificação de conversão.  
  
-   Se **iosbase**. **sinalizadores de** & **ios_base::**[showbase](../Topic/%3Cios%3E%20functions.md#showbase) é diferente de zero, o sinalizador **#** é anexado à especificação de conversão.  
  
 O formato de um número inteiro de saída campo é determinado pelo [faceta de localidade](../standard-library/locale-class.md#facet_class)**PAT** retornado pela chamada [use_facet](../Topic/%3Clocale%3E%20functions.md#use_facet) < [numpunct](../standard-library/numpunct-class.md)\< **Elem**> ( **iosbase**. [getloc](../standard-library/ios-base-class.md#ios_base__getloc)). Especificamente:  
  
- **PAT**. [agrupando](../standard-library/numpunct-class.md#numpunct__grouping) determina como os dígitos são agrupados à esquerda de qualquer vírgula decimal  
  
- **PAT**. [thousands_sep](../standard-library/numpunct-class.md#numpunct__thousands_sep) determina a sequência que separa grupos de dígitos à esquerda de qualquer vírgula decimal  
  
 Se nenhum agrupamento restrições são impostas pelo **PAT**. **agrupamento** (o primeiro elemento tem o valor CHAR_MAX), então não há instâncias de **PAT**. `thousands_sep` são gerados no campo de saída. Caso contrário, separadores são inseridas após a conversão de impressa.  
  
 A segunda função de membro protegido virtual:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    unsigned long val) const;
```  
  
 se comporta da mesma maneira como a primeira, exceto que ele substitui uma especificação de conversão de **ld** com **lu**.  
  
 A terceira função de membro protegido virtual:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    double val) const;
```  
  
 se comporta da mesma maneira como a primeira, exceto que ele produz um campo de saída de ponto flutuante do valor de **val**. **PAT**. [decimal_point](../standard-library/numpunct-class.md#numpunct__decimal_point) determina a sequência que separa os dígitos de inteiro de dígitos de fração. A especificação de conversão impressão equivalente é determinada como segue:  
  
-   Se **iosbase**. **sinalizadores de** & `ios_base::floatfield` == `ios_base::`[fixo](../Topic/%3Cios%3E%20functions.md#fixed), a especificação de conversão é **lf**.  
  
-   Se **iosbase**. **sinalizadores de** & **ios_base::floatfield** == `ios_base::`[científica](../Topic/%3Cios%3E%20functions.md#scientific), a especificação de conversão é `le`. Se **iosbase**. **sinalizadores de** & `ios_base::`[maiusculas](../Topic/%3Cios%3E%20functions.md#uppercase) é diferente de zero, **e** é substituído por **E**.  
  
-   Caso contrário, a especificação de conversão é **lg**. Se **iosbase**. **sinalizadores de** & **ios_base::uppercase** é diferente de zero, **g** é substituído pelo **G**.  
  
 Se **iosbase**. **sinalizadores de** & **ios_base::fixed** é diferente de zero ou se **iosbase**. [precisão](../standard-library/ios-base-class.md#ios_base__precision) é maior que zero, uma precisão com o valor **iosbase**. **precisão** é anexado à especificação de conversão. Todos os preenchimentos se comporta da mesma maneira que um campo de saída inteiro. O caractere de preenchimento é **preenchimento**. Por fim:  
  
-   Se **iosbase**. **sinalizadores de** & `ios_base::`[showpos](../Topic/%3Cios%3E%20functions.md#showpos) é diferente de zero, o sinalizador **+** é anexado à especificação de conversão.  
  
-   Se **iosbase**. **sinalizadores de** & `ios_base::`[showpoint](../Topic/%3Cios%3E%20functions.md#showpoint) é diferente de zero, o sinalizador **#** é anexado à especificação de conversão.  
  
 A função de membro protegido virtual quarta:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    long double val) const;
```  
  
 se comporta como o terceiro, exceto que o qualificador **l** na conversão de especificação é substituída pelo **L**.  
  
 A função de membro protegido virtual quinta:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    const void* val) const;
```  
  
 se comporta como o primeiro, exceto que a especificação de conversão é `p`**,** plus qualquer qualificador necessária para especificar o preenchimento.  
  
 A função de membro protegido virtual sexta:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& _Iosbase,  
    CharType _Fill,
    bool val) const;
```  
  
 se comporta da mesma maneira como a primeira, exceto que ele gera um campo booleano saída da ` val`.  
  
 Um campo de saída booleana usa uma das duas formas. Se **iosbase**. **sinalizadores de** & `ios_base::`[boolalpha](../Topic/%3Cios%3E%20functions.md#boolalpha) é **false**, retorna a função de membro `do_put`(_ *próximo*, \_ *Iosbase*, \_ *preenchimento*, ( **longo**) ` val`), que geralmente produz uma sequência gerada de 0 (para **false**) ou 1 (para **true**). Caso contrário, a sequência de gerado é **PAT**. [falsename](../standard-library/numpunct-class.md#numpunct__falsename)`)` (para **false**), ou **PAT**. [truename](../standard-library/numpunct-class.md#numpunct__truename) (para **true**).  
  
 A função de membro protegido virtual sétima:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& iosbase,  
    Elem fill,
    long long val) const;
```  
  
 se comporta da mesma maneira como a primeira, exceto que ele substitui uma especificação de conversão de **ld** com **lld**.  
  
 A função de membro protegido virtual oitava:  
  
```  
virtual iter_type do_put(iter_type next,
    ios_base& iosbase,  
    Elem fill,
    unsigned long long val) const;
```  
  
 se comporta da mesma maneira como a primeira, exceto que ele substitui uma especificação de conversão de `ld` com `llu`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [colocar](#num_put__put), que chama `do_put`.  
  
##  <a name="a-namenumputitertypea-numputitertype"></a><a name="num_put__iter_type"></a>  num_put:: iter_type  
 Um tipo que descreve um iterador de saída.  
  
```  
typedef OutputIterator iter_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **OutputIterator.**  
  
##  <a name="a-namenumputnumputa-numputnumput"></a><a name="num_put__num_put"></a>  num_put:: num_put  
 O construtor para objetos do tipo `num_put`.  
  
```  
explicit num_put(size_t _Refs = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Refs`  
 Valor inteiro usado para especificar o tipo de gerenciamento de memória para o objeto.  
  
### <a name="remarks"></a>Comentários  
 Os valores possíveis para a `_Refs` e seus significados são:  
  
-   0: o tempo de vida do objeto é gerenciado pelas localidades que contêm-lo.  
  
-   1: o tempo de vida do objeto deve ser gerenciado manualmente.  
  
-   \> 0: esses valores não são definidos.  
  
 Nenhum exemplo direto é possível, como o destruidor é protegido.  
  
 O construtor inicializa o objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)(_ *Refs*).  
  
##  <a name="a-namenumputputa-numputput"></a><a name="num_put__put"></a>  num_put:: Put  
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
 ` dest`  
 Um iterador que trata o primeiro elemento da cadeia de caracteres inserida.  
  
 `_Iosbase`  
 Especificar o fluxo que contém a localidade com a faceta numpunct usada para pontuar os sinalizadores para a formatação de saída e saída.  
  
 `_Fill`  
 Um caractere que é usado para espaçamento.  
  
 ` val`  
 O número ou tipo booliano que será a saída.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída produzida de uma posição além do último elemento os endereços.  
  
### <a name="remarks"></a>Comentários  
 Retornam todas as funções de membro [do_put](#num_put__do_put)( ` next`, `_Iosbase`, `_Fill`, ` val`).  
  
### <a name="example"></a>Exemplo  
  
```  
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
 [\< localidade>](../standard-library/locale.md)   
 [Classe facet](../standard-library/locale-class.md#facet_class)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

