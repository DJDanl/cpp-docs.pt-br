---
title: Classe money_put | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- xlocmon/std::money_put
- xlocmon/std::money_put::char_type
- xlocmon/std::money_put::iter_type
- xlocmon/std::money_put::string_type
- xlocmon/std::money_put::do_put
- xlocmon/std::money_put::put
dev_langs: C++
helpviewer_keywords:
- std::money_put [C++]
- std::money_put [C++], char_type
- std::money_put [C++], iter_type
- std::money_put [C++], string_type
- std::money_put [C++], do_put
- std::money_put [C++], put
ms.assetid: f439fd56-c9b1-414c-95e1-66c918c6eee6
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d93a25339802edc4f03b1f5e5cf03be0b2558dda
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="moneyput-class"></a>Classe money_put
A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores monetários em sequências do tipo `CharType`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType,  
    class OutputIterator = ostreambuf_iterator<CharType>>  
class money_put : public locale::facet;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres em uma localidade.  
  
 `OutputIterator`  
 O tipo de iterador para o qual as funções put monetárias gravam sua saída.  
  
## <a name="remarks"></a>Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[money_put](#money_put)|O construtor para objetos do tipo `money_put`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[iter_type](#iter_type)|Um tipo que descreve um iterador de saída.|  
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[do_put](#do_put)|Uma função virtual chamada para converter o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.|  
|[put](#put)|Converte o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
##  <a name="char_type"></a>  money_put::char_type  
 Um tipo que é usado para descrever um caractere usado por uma localidade.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType**.  
  
##  <a name="do_put"></a>  money_put::do_put  
 Uma função virtual chamada para converter o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.  
  
```  
virtual iter_type do_put(
    iter_type next,   
    bool _Intl,   
    ios_base& _Iosbase,  
    CharType _Fill,   
    const string_type& val) const;

 
virtual iter_type do_put(
    iter_type next,   
    bool _Intl,   
    ios_base& _Iosbase,  
    CharType _Fill,  
    long double val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `next`  
 Um iterador que trata o primeiro elemento na cadeia de caracteres inserida.  
  
 `_Intl`  
 Um valor booliano que indica o tipo do símbolo de moeda esperado na sequência: **true** se internacional, **false** se nacional.  
  
 `_Iosbase`  
 Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório  
  
 `_Fill`  
 Um caractere que é usado para espaçamento.  
  
 `val`  
 Um objeto de cadeia de caracteres a ser convertido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída que aborda uma posição além do último elemento produzido.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro protegida virtual gera elementos sequenciais começando em `next` para produzir um campo de saída monetário do objeto [string_type](#string_type) `val`. A sequência controlada pelo `val` devem começar com um ou mais dígitos decimais, opcionalmente, precedidos por um sinal de menos (-), que representa a quantidade. A função retorna um iterador que designa o primeiro elemento além do campo de saída monetário gerado.  
  
 A segunda função membro protegida virtual se comporta da mesma maneira que a primeira, exceto que ela efetivamente primeiro converte `val` em uma sequência de dígitos decimais, opcionalmente precedida por um sinal de subtração e converte essa sequência como acima.  
  
 O formato de um campo de saída monetário é determinado pelo [locale facet](../standard-library/locale-class.md#facet_class) fac retornado pela chamada (efetiva) [use_facet](../standard-library/locale-functions.md#use_facet) < [moneypunct](../standard-library/moneypunct-class.md)\< **CharType**, **intl**> >( **iosbase**. [getloc](../standard-library/ios-base-class.md#getloc)).  
  
 Especificamente:  
  
- **fac**. [pos_format](../standard-library/moneypunct-class.md#pos_format) determina a ordem na qual os componentes do campo são gerados para um valor não negativo.  
  
- **fac**. [neg_format](../standard-library/moneypunct-class.md#neg_format) determina a ordem na qual os componentes do campo são gerados para um valor negativo.  
  
- **fac**. [curr_symbol](../standard-library/moneypunct-class.md#curr_symbol) determina a sequência de elementos a ser gerada para um símbolo de moeda.  
  
- **fac**. [positive_sign](../standard-library/moneypunct-class.md#positive_sign) determina a sequência de elementos a ser gerada para um sinal positivo.  
  
- **fac**. [negative_sign](../standard-library/moneypunct-class.md#negative_sign) determina a sequência de elementos a ser gerada para um sinal negativo.  
  
- **fac**. [grouping](../standard-library/moneypunct-class.md#grouping) determina como os dígitos são agrupados à esquerda da vírgula decimal.  
  
- **fac**. [thousands_sep](../standard-library/moneypunct-class.md#thousands_sep) determina o elemento que separa grupos de dígitos à esquerda da vírgula decimal.  
  
- **fac**. [decimal_point](../standard-library/moneypunct-class.md#decimal_point) determina a sequência que separa os dígitos de inteiros de qualquer dígito de fração.  
  
- **fac**. [frac_digits](../standard-library/moneypunct-class.md#frac_digits) determina o número de dígitos de fração significativa à direita de qualquer vírgula decimal.  
  
 Se a cadeia de caracteres de sinal (**fac**. `negative_sign` ou **fac**. `positive_sign`) tiver mais de um elemento, apenas o primeiro elemento gerado quando o elemento for igual a **money_base::sign** aparecerá no padrão do formato (**fac**. `neg_format` ou **fac**. `pos_format`). Todos os elementos restantes são gerados ao final do campo de saída monetário.  
  
 Se **iosbase**. [flags](../standard-library/ios-base-class.md#flags) & [showbase](../standard-library/ios-functions.md#showbase) for diferente de zero, a cadeia de caracteres **fac**. `curr_symbol` será gerada quando o elemento igual a **money_base::symbol** aparece no padrão do formato. Caso contrário, nenhum símbolo de moeda será gerado.  
  
 Se nenhuma restrição de agrupamento for imposta por **fac**. **grouping** (o primeiro elemento tem o valor CHAR_MAX), então não há instâncias de **fac**. `thousands_sep` são gerados na parte de valor do campo de saída monetário (em que o elemento igual a **money_base::value** aparece no padrão de formato). Se **fac**. `frac_digits` for zero, nenhuma instância de **fac**. `decimal_point` será gerada após os dígitos decimais. Caso contrário, o campo de saída monetário resultante colocará os dígitos decimais **fac**. `frac_digits` de ordem baixa à direita da vírgula decimal.  
  
 O preenchimento ocorre para qualquer campo de saída numérico, exceto se **iosbase**. **flags** & **iosbase**. [internal](../standard-library/ios-functions.md#internal) for diferente de zero, o preenchimento será gerado quando o elemento igual a **money_base::space** aparece no padrão de formato, se ele aparecer. Caso contrário, o preenchimento interno ocorrerá antes da sequência gerada. O caractere de preenchimento é **fill**.  
  
 A função chama **iosbase**. **width**(0) para redefinir a largura do campo como zero.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [put](#put), em que a função membro virtual é chamada por **put**.  
  
##  <a name="iter_type"></a>  money_put::iter_type  
 Um tipo que descreve um iterador de saída.  
  
```  
typedef OutputIterator iter_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **OutputIterator.**  
  
##  <a name="money_put"></a>  money_put::money_put  
 O construtor para objetos do tipo `money_put`.  
  
```  
explicit money_put(size_t _Refs = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Refs`  
 Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.  
  
### <a name="remarks"></a>Comentários  
 Os valores possíveis para o parâmetro `_Refs` e sua significância são:  
  
-   0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.  
  
-   1: o tempo de vida do objeto deve ser gerenciado manualmente.  
  
-   \>1: esses valores não são definidos.  
  
 Nenhum exemplo direto é possível, pois o destruidor está protegido.  
  
 O construtor inicializa seu objeto base com **locale::**[facet](../standard-library/locale-class.md#facet_class)( `_Refs`).  
  
##  <a name="put"></a>  money_put::put  
 Converte o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.  
  
```  
iter_type put(
    iter_type next,   
    bool _Intl,   
    ios_base& _Iosbase,  
    CharType _Fill,   
    const string_type& val) const;

 
iter_type put(
    iter_type next,   
    bool _Intl,   
    ios_base& _Iosbase,  
    CharType _Fill,  
    long double val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `next`  
 Um iterador que trata o primeiro elemento na cadeia de caracteres inserida.  
  
 `_Intl`  
 Um valor booliano que indica o tipo do símbolo de moeda esperado na sequência: **true** se internacional, **false** se nacional.  
  
 `_Iosbase`  
 Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório  
  
 `_Fill`  
 Um caractere que é usado para espaçamento.  
  
 `val`  
 Um objeto de cadeia de caracteres a ser convertido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída que aborda uma posição além do último elemento produzido.  
  
### <a name="remarks"></a>Comentários  
 Ambas as funções membro retornam [do_put](#do_put)( `next`, `_Intl`, `_Iosbase`, `_Fill`, `val`).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// money_put_put.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
//   locale loc( "german_germany" );  
   locale loc( "english_canada" );  
   basic_stringstream<char> psz, psz2;  
   ios_base::iostate st = 0;  
  
   psz2.imbue( loc );  
   psz2.flags( psz2.flags( )|ios_base::showbase ); // force the printing of the currency symbol  
   use_facet < money_put < char > >(loc).put(basic_ostream<char>::_Iter( psz2.rdbuf( ) ), true, psz2, st, 100012);  
   if (st & ios_base::failbit)  
      cout << "money_put( ) FAILED" << endl;  
   else  
      cout << "money_put( ) = \"" << psz2.rdbuf( )->str( ) <<"\""<< endl;     
  
   st = 0;  
};  
```  
  
```Output  
money_put( ) = "CAD1,000.12"  
```  
  
##  <a name="string_type"></a>  money_put::string_type  
 Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo **CharType**.  
  
```  
typedef basic_string<CharType, Traits, Allocator> string_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar sequências de elementos da sequência de origem.  
  
## <a name="see-also"></a>Consulte também  
 [\<locale>](../standard-library/locale.md)   
 [Classe facet](../standard-library/locale-class.md#facet_class)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

