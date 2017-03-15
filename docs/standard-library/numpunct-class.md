---
title: Classe numpunct | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- xlocnum/std::numpunct
- std::numpunct
- numpunct
- std.numpunct
dev_langs:
- C++
helpviewer_keywords:
- numpunct class
ms.assetid: 73fb93cc-ac11-4c98-987c-bfa6267df596
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ee0b852d62065de4d6ded494339d4dd618fc44b2
ms.lasthandoff: 02/25/2017

---
# <a name="numpunct-class"></a>Classe numpunct
Uma classe de modelo que descreve um objeto que pode servir como uma faceta de local para descrever as sequências do tipo `CharType` usadas para representar informações sobre a formatação e pontuação de expressões numéricas e boolianas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType>  
class numpunct : public locale::facet;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres em uma localidade.  
  
## <a name="remarks"></a>Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[numpunct](#numpunct__numpunct)|O construtor para objetos do tipo `numpunct`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#numpunct__char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[string_type](#numpunct__string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[decimal_point](#numpunct__decimal_point)|Retorna um elemento específico de localidade a ser usado como uma vírgula decimal.|  
|[do_decimal_point](#numpunct__do_decimal_point)|Uma função membro virtual protegida que é chamada para retornar um elemento específico de localidade a ser usado como uma vírgula decimal.|  
|[do_falsename](#numpunct__do_falsename)|Uma função membro virtual protegida que é chamada para retornar uma cadeia de caracteres a ser usada como uma representação de texto do valor `false`.|  
|[do_grouping](#numpunct__do_grouping)|Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.|  
|[do_thousands_sep](#numpunct__do_thousands_sep)|Uma função membro virtual protegida que é chamada para retornar um elemento específico de localidade a ser usado como um separador de milhares.|  
|[do_truename](#numpunct__do_truename)|Uma função membro virtual protegida que é chamada para retornar uma cadeia de caracteres a ser usada como uma representação de texto do valor `true`.|  
|[falsename](#numpunct__falsename)|Retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor `false`.|  
|[grouping](#numpunct__grouping)|Retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.|  
|[thousands_sep](#numpunct__thousands_sep)|Retorna um elemento específico de localidade a ser usado como um separador de milhares.|  
|[truename](#numpunct__truename)|Retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor `true`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
##  <a name="a-namenumpunctchartypea--numpunctchartype"></a><a name="numpunct__char_type"></a>  numpunct::char_type  
 Um tipo que é usado para descrever um caractere usado por uma localidade.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType.**  
  
##  <a name="a-namenumpunctdecimalpointa--numpunctdecimalpoint"></a><a name="numpunct__decimal_point"></a>  numpunct::decimal_point  
 Retorna um elemento específico de localidade a ser usado como uma vírgula decimal.  
  
```  
CharType decimal_point() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um elemento específico de localidade a ser usado como uma vírgula decimal.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_decimal_point](#numpunct__do_decimal_point).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numpunct_decimal_point.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "german_germany" );  
  
   const numpunct <char> &npunct =   
   use_facet <numpunct <char> >( loc);  
   cout << loc.name( ) << " decimal point "<<   
   npunct.decimal_point( ) << endl;  
   cout << loc.name( ) << " thousands separator "   
   << npunct.thousands_sep( ) << endl;  
};  
```  
  
```Output  
German_Germany.1252 decimal point ,  
German_Germany.1252 thousands separator .  
```  
  
##  <a name="a-namenumpunctdodecimalpointa--numpunctdodecimalpoint"></a><a name="numpunct__do_decimal_point"></a>  numpunct::do_decimal_point  
 Uma função membro virtual protegida que é chamada para retornar um elemento específico de localidade a ser usado como uma vírgula decimal.  
  
```  
virtual CharType do_decimal_point() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um elemento específico de localidade a ser usado como uma vírgula decimal.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [decimal_point](#numpunct__decimal_point), em que a função membro virtual é chamada por `decimal_point`.  
  
##  <a name="a-namenumpunctdofalsenamea--numpunctdofalsename"></a><a name="numpunct__do_falsename"></a>  numpunct::do_falsename  
 A função membro virtual protegida retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor **false**.  
  
```  
virtual string_type do_falsename() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém uma sequência a ser usada como uma representação de texto do valor **false**.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna a cadeia de caracteres “false” para representar o valor **false** em todas as localidades.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [falsename](#numpunct__falsename), em que a função membro virtual é chamada por `falsename`.  
  
##  <a name="a-namenumpunctdogroupinga--numpunctdogrouping"></a><a name="numpunct__do_grouping"></a>  numpunct::do_grouping  
 Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
```  
virtual string do_grouping() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
### <a name="remarks"></a>Comentários  
 A função membro virtual protegida retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal. A codificação é a mesma usada para **lconv::grouping**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [grouping](#numpunct__grouping), em que a função membro virtual é chamada por **grouping**.  
  
##  <a name="a-namenumpunctdothousandssepa--numpunctdothousandssep"></a><a name="numpunct__do_thousands_sep"></a>  numpunct::do_thousands_sep  
 Uma função membro virtual protegida que é chamada para retornar um elemento específico de localidade a ser usado como um separador de milhares.  
  
```  
virtual CharType do_thousands_sep() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um elemento específico de localidade a ser usado como um separador de milhares.  
  
### <a name="remarks"></a>Comentários  
 A função membro virtual protegida retorna um elemento específico de localidade do tipo **CharType** para ser usado como separador de grupo à esquerda da vírgula decimal.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [thousands_sep](#numpunct__thousands_sep), em que a função membro virtual é chamada por `thousands_sep`.  
  
##  <a name="a-namenumpunctdotruenamea--numpunctdotruename"></a><a name="numpunct__do_truename"></a>  numpunct::do_truename  
 Uma função membro virtual protegida que é chamada para retornar uma cadeia de caracteres a ser usada como uma representação de texto do valor **true**.  
  
```  
virtual string_type do_truename() const;
```  
  
### <a name="remarks"></a>Comentários  
 Uma cadeia de caracteres a ser usada como uma representação de texto do valor **true**.  
  
 Todas as localidades retornam uma cadeia de caracteres “true” para representar o valor **true**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [truename](#numpunct__truename), em que a função membro virtual é chamada por `truename`.  
  
##  <a name="a-namenumpunctfalsenamea--numpunctfalsename"></a><a name="numpunct__falsename"></a>  numpunct::falsename  
 Retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor **false**.  
  
```  
string_type falsename() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém uma sequência de **CharType**s a ser usada como uma representação de texto do valor **false**.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna a cadeia de caracteres “false” para representar o valor **false** em todas as localidades.  
  
 A função de membro retorna [do_falsename](#numpunct__do_falsename).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numpunct_falsename.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "English" );  
  
   const numpunct <char> &npunct = use_facet <numpunct <char> >( loc );  
   cout << loc.name( ) << " truename "<< npunct.truename( ) << endl;  
   cout << loc.name( ) << " falsename "<< npunct.falsename( ) << endl;  
  
   locale loc2( "French" );  
   const numpunct <char> &npunct2 = use_facet <numpunct <char> >(loc2);  
   cout << loc2.name( ) << " truename "<< npunct2.truename( ) << endl;  
   cout << loc2.name( ) << " falsename "<< npunct2.falsename( ) << endl;  
}  
```  
  
```Output  
English_United States.1252 truename true  
English_United States.1252 falsename false  
French_France.1252 truename true  
French_France.1252 falsename false  
```  
  
##  <a name="a-namenumpunctgroupinga--numpunctgrouping"></a><a name="numpunct__grouping"></a>  numpunct::grouping  
 Retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
```  
string grouping() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_grouping](#numpunct__do_grouping).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numpunct_grouping.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "german_germany");  
  
   const numpunct <char> &npunct =   
       use_facet < numpunct <char> >( loc );  
   for (unsigned int i = 0; i < npunct.grouping( ).length( ); i++)  
   {  
      cout << loc.name( ) << " international grouping:\n the "  
           << i <<"th group to the left of the radix character "  
           << "is of size " << (int)(npunct.grouping ( )[i])   
           << endl;  
   }  
}  
```  
  
```Output  
German_Germany.1252 international grouping:  
 the 0th group to the left of the radix character is of size 3  
```  
  
##  <a name="a-namenumpunctnumpuncta--numpunctnumpunct"></a><a name="numpunct__numpunct"></a>  numpunct::numpunct  
 O construtor para objetos do tipo `numpunct`.  
  
```  
explicit numpunct(size_t _Refs = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Refs`  
 Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.  
  
### <a name="remarks"></a>Comentários  
 Os valores possíveis para o parâmetro `_Refs` e sua significância são:  
  
-   0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.  
  
-   1: o tempo de vida do objeto deve ser gerenciado manualmente.  
  
-   \> 0: esses valores não estão definidos.  
  
 Nenhum exemplo direto é possível, pois o destruidor está protegido.  
  
 O construtor inicializa seu objeto base com **locale::**[facet](../standard-library/locale-class.md#facet_class)( `_Refs`).  
  
##  <a name="a-namenumpunctstringtypea--numpunctstringtype"></a><a name="numpunct__string_type"></a>  numpunct::string_type  
 Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo **CharType**.  
  
```  
typedef basic_string<CharType, Traits, Allocator> string_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar cópias das sequências de pontuação.  
  
##  <a name="a-namenumpunctthousandssepa--numpunctthousandssep"></a><a name="numpunct__thousands_sep"></a>  numpunct::thousands_sep  
 Retorna um elemento específico de localidade a ser usado como um separador de milhares.  
  
```  
CharType thousands_sep() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um elemento específico de localidade a ser usado como um separador de milhares.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_thousands_sep](#numpunct__do_thousands_sep).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numpunct_thou_sep.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "german_germany" );  
  
   const numpunct <char> &npunct =   
   use_facet < numpunct < char > >( loc );  
   cout << loc.name( ) << " decimal point "<<   
   npunct.decimal_point( ) << endl;  
   cout << loc.name( ) << " thousands separator "   
   << npunct.thousands_sep( ) << endl;  
};  
```  
  
```Output  
German_Germany.1252 decimal point ,  
German_Germany.1252 thousands separator .  
```  
  
##  <a name="a-namenumpuncttruenamea--numpuncttruename"></a><a name="numpunct__truename"></a>  numpunct::truename  
 Retorna uma cadeia de caracteres a ser usada como uma representação de texto do valor **true**.  
  
```  
string_type falsename() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres a ser usada como uma representação de texto do valor **true**.  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna [do_truename](#numpunct__do_truename).  
  
 Todas as localidades retornam uma cadeia de caracteres “true” para representar o valor **true**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numpunct_truename.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "English" );  
  
   const numpunct < char> &npunct = use_facet <numpunct <char> >( loc );  
   cout << loc.name( ) << " truename "<< npunct.truename( ) << endl;  
   cout << loc.name( ) << " falsename "<< npunct.falsename( ) << endl;  
  
   locale loc2("French");  
   const numpunct <char> &npunct2 = use_facet <numpunct <char> >( loc2 );  
   cout << loc2.name( ) << " truename "<< npunct2.truename( ) << endl;  
   cout << loc2.name( ) << " falsename "<< npunct2.falsename( ) << endl;  
}  
```  
  
```Output  
English_United States.1252 truename true  
English_United States.1252 falsename false  
French_France.1252 truename true  
French_France.1252 falsename false  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<locale>](../standard-library/locale.md)   
 [Classe facet](../standard-library/locale-class.md#facet_class)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


