---
title: Classe moneypunct | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- moneypunct
- std.moneypunct
- xlocmon/std::moneypunct
- std::moneypunct
dev_langs:
- C++
helpviewer_keywords:
- moneypunct class
ms.assetid: cf2650da-3e6f-491c-95d5-23e57f582ee6
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
ms.openlocfilehash: 5bf4f8f69073e6c445f416a24b00e19b4a20adc4
ms.lasthandoff: 02/25/2017

---
# <a name="moneypunct-class"></a>Classe moneypunct
A classe de modelo que descreve um objeto que pode funcionar como uma faceta de localidade para descrever as sequências do tipo `CharType` usadas para representar um campo de entrada monetário ou um campo de saída monetário. Se o parâmetro de modelo `Intl` for `true`, as convenções internacionais serão observadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType, bool Intl>  
class moneypunct;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres.  
  
 `Intl`  
 Um sinalizador que especifica se as convenções internacionais devem ser observadas.  
  
## <a name="remarks"></a>Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**  
  
 O objeto estático const intl armazena o valor do parâmetro de modelo **Intl**.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[moneypunct](#moneypunct__moneypunct)|Construtor de objetos do tipo `moneypunct`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#moneypunct__char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[string_type](#moneypunct__string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[curr_symbol](#moneypunct__curr_symbol)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de moeda.|  
|[decimal_point](#moneypunct__decimal_point)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.|  
|[do_curr_symbol](#moneypunct__do_curr_symbol)|Uma função membro virtual protegida que retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de moeda.|  
|[do_decimal_point](#moneypunct__do_decimal_point)|Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.|  
|[do_frac_digits](#moneypunct__do_frac_digits)|A função membro virtual protegida retorna uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.|  
|[do_grouping](#moneypunct__do_grouping)|A função membro virtual protegida retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.|  
|[do_neg_format](#moneypunct__do_neg_format)|Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para formatação de saídas com valores negativos.|  
|[do_negative_sign](#moneypunct__do_negative_sign)|Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.|  
|[do_pos_format](#moneypunct__do_pos_format)|Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para formatação de saídas com valores positivos.|  
|[do_positive_sign](#moneypunct__do_positive_sign)|Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal positivo.|  
|[do_thousands_sep](#moneypunct__do_thousands_sep)|Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de separador de milhares.|  
|[frac_digits](#moneypunct__frac_digits)|Retorna uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.|  
|[grouping](#moneypunct__grouping)|Retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.|  
|[neg_format](#moneypunct__neg_format)|Retorna uma regra específica de localidade para formatação de saídas com valores negativos.|  
|[negative_sign](#moneypunct__negative_sign)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.|  
|[pos_format](#moneypunct__pos_format)|Retorna uma regra específica de localidade para formatação de saídas com valores positivos.|  
|[positive_sign](#moneypunct__positive_sign)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal positivo.|  
|[thousands_sep](#moneypunct__thousands_sep)|Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de separador de milhares.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
##  <a name="a-namemoneypunctchartypea--moneypunctchartype"></a><a name="moneypunct__char_type"></a>  moneypunct::char_type  
 Um tipo que é usado para descrever um caractere usado por uma localidade.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType**.  
  
##  <a name="a-namemoneypunctcurrsymbola--moneypunctcurrsymbol"></a><a name="moneypunct__curr_symbol"></a>  moneypunct::curr_symbol  
 Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de moeda.  
  
```  
string_type curr_symbol() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o símbolo de moeda.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_curr_symbol](#moneypunct__do_curr_symbol).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_curr_symbol.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "german_germany" );  
  
   const moneypunct < char, true > &mpunct = use_facet < moneypunct < char, true > >(loc);  
   cout << loc.name( ) << " international currency symbol "<<  mpunct.curr_symbol( ) << endl;  
  
   const moneypunct < char, false> &mpunct2 = use_facet < moneypunct < char, false> >(loc);  
   cout << loc.name( ) << " domestic currency symbol "<<  mpunct2.curr_symbol( ) << endl;  
};  
```  
  
##  <a name="a-namemoneypunctdecimalpointa--moneypunctdecimalpoint"></a><a name="moneypunct__decimal_point"></a>  moneypunct::decimal_point  
 Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.  
  
```  
CharType decimal_point() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_decimal_point](#moneypunct__do_decimal_point).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_decimal_pt.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc("german_germany");  
  
   const moneypunct < char, true > &mpunct = use_facet   
      < moneypunct < char, true > >(loc);  
   cout << loc.name( ) << " international decimal point "  
        << mpunct.decimal_point( ) << endl;  
  
   const moneypunct < char, false> &mpunct2 = use_facet   
      < moneypunct < char, false> >(loc);  
   cout << loc.name( ) << " domestic decimal point "  
        << mpunct2.decimal_point( ) << endl;  
}  
```  
  
```Output  
German_Germany.1252 international decimal point ,  
German_Germany.1252 domestic decimal point ,  
```  
  
##  <a name="a-namemoneypunctdocurrsymbola--moneypunctdocurrsymbol"></a><a name="moneypunct__do_curr_symbol"></a>  moneypunct::do_curr_symbol  
 Uma função membro virtual protegida que retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de moeda.  
  
```  
virtual string_type do_curr_symbol() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [curr_symbol](#moneypunct__curr_symbol), em que a função membro virtual é chamada por `curr_symbol`.  
  
##  <a name="a-namemoneypunctdodecimalpointa--moneypunctdodecimalpoint"></a><a name="moneypunct__do_decimal_point"></a>  moneypunct::do_decimal_point  
 Uma função membro virtual protegida que retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.  
  
```  
virtual CharType do_decimal_point() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma sequência de elementos específica de localidade a ser usada como um símbolo de vírgula decimal.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [decimal_point](#moneypunct__decimal_point), em que a função membro virtual é chamada por `decimal_point`.  
  
##  <a name="a-namemoneypunctdofracdigitsa--moneypunctdofracdigits"></a><a name="moneypunct__do_frac_digits"></a>  moneypunct::do_frac_digits  
 Uma função membro virtual protegida retorna uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.  
  
```  
virtual int do_frac_digits() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [frac_digits](#moneypunct__frac_digits), em que a função membro virtual é chamada por `frac_digits`.  
  
##  <a name="a-namemoneypunctdogroupinga--moneypunctdogrouping"></a><a name="moneypunct__do_grouping"></a>  moneypunct::do_grouping  
 Uma função membro virtual protegida que retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
```  
virtual string do_grouping() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [grouping](#moneypunct__grouping), em que a função membro virtual é chamada por **grouping**.  
  
##  <a name="a-namemoneypunctdonegformata--moneypunctdonegformat"></a><a name="moneypunct__do_neg_format"></a>  moneypunct::do_neg_format  
 Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para formatação de saídas com valores negativos.  
  
```  
virtual pattern do_neg_format() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro virtual protegida retorna uma regra específica de localidade para determinar como gerar o campo de saída monetário para um valor negativo. Cada um dos quatro elementos de **pattern::field** pode ter os valores:  
  
- **none** para corresponder a zero ou mais espaços ou gerar nada.  
  
- **sign** para corresponder ou gerar um sinal positivo ou negativo.  
  
- **space** para corresponder a zero ou mais espaços ou gerar um espaço.  
  
- **symbol** para corresponder ou gerar um símbolo de moeda.  
  
- **value** para corresponder ou gerar um valor monetário.  
  
 Os componentes de um campo de saída monetário são gerados e os componentes de um campo de entrada monetário são correspondidos na ordem em que esses elementos aparecem em **pattern::field**. Cada um dos valores **sign**, **symbol**, **value** e **none** ou **space** deve aparecer exatamente uma vez. O valor **none** não devem aparecer primeiro. O valor space não **deve** não devem aparecer primeiro ou por último. Se **Intl** for true, a ordem será **symbol**, **sign**, **none** e **value**.  
  
 A versão de modelo `moneypunct`\< **CharType**, **Intl**> retorna `{`**money_base::symbol**, **money_base::sign**, **money_base::value**, **money_base::none**`}`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [net_format](#moneypunct__neg_format), em que a função membro virtual é chamada por `neg_format`.  
  
##  <a name="a-namemoneypunctdonegativesigna--moneypunctdonegativesign"></a><a name="moneypunct__do_negative_sign"></a>  moneypunct::do_negative_sign  
 Uma função membro virtual protegida que é chamada para retornar uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.  
  
```  
virtual string_type do_negative_sign() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma sequência de elementos específica de localidade a ser usada como um sinal negativo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [negative_sign](#moneypunct__negative_sign), em que a função membro virtual é chamada por `negative_sign`.  
  
##  <a name="a-namemoneypunctdoposformata--moneypunctdoposformat"></a><a name="moneypunct__do_pos_format"></a>  moneypunct::do_pos_format  
 Uma função membro virtual protegida que é chamada para retornar uma regra específica de localidade para formatação de saídas com valores positivos.  
  
```  
virtual pattern do_pos_format() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro virtual protegida retorna uma regra específica de localidade para determinar como gerar o campo de saída monetário para um valor positivo. (Ela também determina como corresponder os componentes de um campo de entrada monetário.) A codificação é a mesma usada para [do_neg_format](#moneypunct__do_neg_format).  
  
 A versão do modelo de moneypunct\< **CharType**, **Inputlterator**> retorna `{`**money_base::symbol**, **money_base::sign**, **money_base::value**, **money_base::none**`}`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [pos_format](#moneypunct__pos_format), em que a função membro virtual é chamada por `pos_format`.  
  
##  <a name="a-namemoneypunctdopositivesigna--moneypunctdopositivesign"></a><a name="moneypunct__do_positive_sign"></a>  moneypunct::do_positive_sign  
 Uma função membro virtual protegida que retorna uma sequência de elementos específica de localidade a ser usada como um sinal positivo.  
  
```  
virtual string_type do_positive_sign() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma sequência de elementos específica de localidade a ser usada como um sinal positivo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [positive_sign](#moneypunct__positive_sign), em que a função membro virtual é chamada por `positive_sign`.  
  
##  <a name="a-namemoneypunctdothousandssepa--moneypunctdothousandssep"></a><a name="moneypunct__do_thousands_sep"></a>  moneypunct::do_thousands_sep  
 Uma função membro virtual protegida que retorna um elemento específico de localidade para ser usado como separador de grupo à esquerda da vírgula decimal.  
  
```  
virtual CharType do_thousands_sep() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um elemento específico de localidade a ser usado como um separador de grupo à esquerda de qualquer vírgula decimal.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [thousands_sep](#moneypunct__thousands_sep), em que a função membro virtual é chamada por `thousands_sep`.  
  
##  <a name="a-namemoneypunctfracdigitsa--moneypunctfracdigits"></a><a name="moneypunct__frac_digits"></a>  moneypunct::frac_digits  
 Retorna uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.  
  
```  
int frac_digits() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma contagem do número de dígitos específica de localidade a ser exibida à direita de qualquer vírgula decimal.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_frac_digits](#moneypunct__do_frac_digits).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_frac_digits.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "german_germany" );  
  
   const moneypunct <char, true> &mpunct =   
       use_facet <moneypunct <char, true> >(loc);  
   for (unsigned int i = 0; i <mpunct.grouping( ).length( ); i++ )  
   {  
      cout << loc.name( ) << " international grouping:\n the "  
           << i <<"th group to the left of the radix character "  
           << "is of size " << (int)(mpunct.grouping ( )[i])   
           << endl;  
   }  
   cout << loc.name( ) << " international frac_digits\n to the right"  
        << " of the radix character: "  
        << mpunct.frac_digits ( ) << endl << endl;  
  
   const moneypunct <char, false> &mpunct2 =   
       use_facet <moneypunct <char, false> >(loc);  
   for (unsigned int i = 0; i <mpunct2.grouping( ).length( ); i++ )  
   {  
      cout << loc.name( ) << " domestic grouping:\n the "  
           << i <<"th group to the left of the radix character "  
           << "is of size " << (int)(mpunct2.grouping ( )[i])   
           << endl;  
   }  
   cout << loc.name( ) << " domestic frac_digits\n to the right"  
        << " of the radix character: "  
        << mpunct2.frac_digits ( ) << endl << endl;  
}  
```  
  
```Output  
German_Germany.1252 international grouping:  
 the 0th group to the left of the radix character is of size 3  
German_Germany.1252 international frac_digits  
 to the right of the radix character: 2  
  
German_Germany.1252 domestic grouping:  
 the 0th group to the left of the radix character is of size 3  
German_Germany.1252 domestic frac_digits  
 to the right of the radix character: 2  
```  
  
##  <a name="a-namemoneypunctgroupinga--moneypunctgrouping"></a><a name="moneypunct__grouping"></a>  moneypunct::grouping  
 Retorna uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
```  
string grouping() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma regra específica de localidade para determinar como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_grouping](#moneypunct__do_grouping).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_grouping.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "german_germany" );  
  
   const moneypunct <char, true> &mpunct =   
       use_facet <moneypunct <char, true> >( loc );  
   for (unsigned int i = 0; i <mpunct.grouping( ).length( ); i++ )  
   {  
      cout << loc.name( ) << " international grouping:\n the "  
           << i <<"th group to the left of the radix character "  
           << "is of size " << (int)(mpunct.grouping ( )[i])   
           << endl;  
   }  
   cout << loc.name( ) << " international frac_digits\n to the right"  
        << " of the radix character: "  
        << mpunct.frac_digits ( ) << endl << endl;  
  
   const moneypunct <char, false> &mpunct2 =   
       use_facet <moneypunct <char, false> >( loc );  
   for (unsigned int i = 0; i <mpunct2.grouping( ).length( ); i++ )  
   {  
      cout << loc.name( ) << " domestic grouping:\n the "  
           << i <<"th group to the left of the radix character "  
           << "is of size " << (int)(mpunct2.grouping ( )[i])   
           << endl;  
   }  
   cout << loc.name( ) << " domestic frac_digits\n to the right"  
        << " of the radix character: "  
        << mpunct2.frac_digits ( ) << endl << endl;  
}  
```  
  
```Output  
German_Germany.1252 international grouping:  
 the 0th group to the left of the radix character is of size 3  
German_Germany.1252 international frac_digits  
 to the right of the radix character: 2  
  
German_Germany.1252 domestic grouping:  
 the 0th group to the left of the radix character is of size 3  
German_Germany.1252 domestic frac_digits  
 to the right of the radix character: 2  
```  
  
##  <a name="a-namemoneypunctmoneypuncta--moneypunctmoneypunct"></a><a name="moneypunct__moneypunct"></a>  moneypunct::moneypunct  
 Construtor de objetos do tipo `moneypunct`.  
  
```  
explicit moneypunct(size_t _Refs = 0);
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
  
 O construtor inicializa seu objeto base com [locale::facet](../standard-library/locale-class.md#facet_class)(_ *Refs*).  
  
##  <a name="a-namemoneypunctnegformata--moneypunctnegformat"></a><a name="moneypunct__neg_format"></a>  moneypunct::neg_format  
 Retorna uma regra específica de localidade para formatação de saídas com valores negativos.  
  
```  
pattern neg_format() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma regra específica de localidade para formatação de saídas com valores negativos.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_neg_format](#moneypunct__do_neg_format).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_neg_format.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
  
using namespace std;  
  
int main( ) {  
   locale loc( "german_germany" );  
  
   const moneypunct <char, true> &mpunct =   
      use_facet <moneypunct <char, true > >(loc);  
   cout << loc.name( ) << " international negative number format: "  
        << mpunct.neg_format( ).field[0]   
        << mpunct.neg_format( ).field[1]   
        << mpunct.neg_format( ).field[2]   
        << mpunct.neg_format( ).field[3] << endl;  
  
   const moneypunct <char, false> &mpunct2 =   
      use_facet <moneypunct <char, false> >(loc);  
   cout << loc.name( ) << " domestic negative number format: "  
        << mpunct2.neg_format( ).field[0]   
        << mpunct2.neg_format( ).field[1]   
        << mpunct2.neg_format( ).field[2]   
        << mpunct2.neg_format( ).field[3] << endl;  
}  
```  
  
##  <a name="a-namemoneypunctnegativesigna--moneypunctnegativesign"></a><a name="moneypunct__negative_sign"></a>  moneypunct::negative_sign  
 Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.  
  
```  
string_type negative_sign() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal negativo.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_negative_sign](#moneypunct__do_negative_sign).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_neg_sign.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
  
using namespace std;  
  
int main( )  
{  
   locale loc( "german_germany" );  
  
   const moneypunct <char, true> &mpunct =   
      use_facet <moneypunct <char, true> >(loc);  
   cout << loc.name( ) << " international negative sign: "  
        << mpunct.negative_sign( ) << endl;  
  
   const moneypunct <char, false> &mpunct2 =   
      use_facet <moneypunct <char, false> >(loc);  
   cout << loc.name( ) << " domestic negative sign: "  
        << mpunct2.negative_sign( ) << endl;  
  
   locale loc2( "French" );  
  
   const moneypunct <char, true> &mpunct3 =   
      use_facet <moneypunct <char, true> >(loc2);  
   cout << loc2.name( ) << " international negative sign: "  
        << mpunct3.negative_sign( ) << endl;  
  
   const moneypunct <char, false> &mpunct4 =   
      use_facet <moneypunct <char, false> >(loc2);  
   cout << loc2.name( ) << " domestic negative sign: "  
        << mpunct4.negative_sign( ) << endl;  
};  
```  
  
```Output  
German_Germany.1252 international negative sign: -  
German_Germany.1252 domestic negative sign: -  
French_France.1252 international negative sign: -  
French_France.1252 domestic negative sign: -  
```  
  
##  <a name="a-namemoneypunctposformata--moneypunctposformat"></a><a name="moneypunct__pos_format"></a>  moneypunct::pos_format  
 Retorna uma regra específica de localidade para formatação de saídas com valores positivos.  
  
```  
pattern pos_format() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma regra específica de localidade para formatação de saídas com valores positivos.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_pos_format](#moneypunct__do_pos_format).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_pos_format.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
  
using namespace std;  
  
int main() {  
   locale loc( "german_germany" );  
  
   const moneypunct <char, true> &mpunct =   
      use_facet <moneypunct <char, true> >(loc);  
   cout << loc.name( ) << " international positive number format: "  
        << mpunct.pos_format( ).field[0]   
        << mpunct.pos_format( ).field[1]   
        << mpunct.pos_format( ).field[2]   
        << mpunct.pos_format( ).field[3] << endl;  
  
   const moneypunct <char, false> &mpunct2 =   
      use_facet <moneypunct <char, false> >(loc);  
   cout << loc.name( ) << " domestic positive number format: "  
        << mpunct2.pos_format( ).field[0]   
        << mpunct2.pos_format( ).field[1]   
        << mpunct2.pos_format( ).field[2]   
        << mpunct2.pos_format( ).field[3] << endl;  
}  
```  
  
##  <a name="a-namemoneypunctpositivesigna--moneypunctpositivesign"></a><a name="moneypunct__positive_sign"></a>  moneypunct::positive_sign  
 Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal positivo.  
  
```  
string_type positive_sign() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma sequência de elementos específica de localidade a ser usada como um símbolo de sinal positivo.  
  
### <a name="remarks"></a>Comentários  
 -A função membro retorna [do_positive_sign](#moneypunct__do_positive_sign).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_pos_sign.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
  
using namespace std;  
  
int main( )  
{  
   locale loc( "german_germany" );  
  
   const moneypunct <char, true> &mpunct =   
      use_facet <moneypunct <char, true > >(loc);  
   cout << loc.name( ) << " international positive sign:"  
        << mpunct.positive_sign( ) << endl;  
  
   const moneypunct <char, false> &mpunct2 =   
      use_facet <moneypunct <char, false> >(loc);  
   cout << loc.name( ) << " domestic positive sign:"  
        << mpunct2.positive_sign( ) << endl;  
  
   locale loc2( "French" );  
  
   const moneypunct <char, true> &mpunct3 =   
      use_facet <moneypunct <char, true> >(loc2);  
   cout << loc2.name( ) << " international positive sign:"  
        << mpunct3.positive_sign( ) << endl;  
  
   const moneypunct <char, false> &mpunct4 =   
      use_facet <moneypunct <char, false> >(loc2);  
   cout << loc2.name( ) << " domestic positive sign:"  
        << mpunct4.positive_sign( ) << endl;  
};  
```  
  
```Output  
German_Germany.1252 international positive sign:  
German_Germany.1252 domestic positive sign:  
French_France.1252 international positive sign:  
French_France.1252 domestic positive sign:  
```  
  
##  <a name="a-namemoneypunctstringtypea--moneypunctstringtype"></a><a name="moneypunct__string_type"></a>  moneypunct::string_type  
 Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo **CharType**.  
  
```  
typedef basic_string<CharType, Traits, Allocator> string_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar cópias das sequências de pontuação.  
  
##  <a name="a-namemoneypunctthousandssepa--moneypunctthousandssep"></a><a name="moneypunct__thousands_sep"></a>  moneypunct::thousands_sep  
 Retorna uma sequência de elementos específica de localidade a ser usada como um símbolo de separador de milhares.  
  
```  
CharType thousands_sep() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma sequência de elementos específica de localidade a ser usada como separador de milhares  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_thousands_sep](#moneypunct__do_thousands_sep).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// moneypunct_thou_sep.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
int main( )  
{  
   locale loc( "german_germany" );  
  
   const moneypunct <char, true> &mpunct =   
       use_facet <moneypunct <char, true > >(loc);  
   cout << loc.name( ) << " international thousands separator: "  
        << mpunct.thousands_sep( ) << endl;  
  
   const moneypunct <char, false> &mpunct2 =   
      use_facet <moneypunct <char, false> >(loc);  
   cout << loc.name( ) << " domestic thousands separator: "  
        << mpunct2.thousands_sep( ) << endl << endl;  
  
   locale loc2( "english_canada" );  
  
   const moneypunct <char, true> &mpunct3 =   
       use_facet <moneypunct <char, true> >(loc2);  
   cout << loc2.name( ) << " international thousands separator: "  
        << mpunct3.thousands_sep( ) << endl;  
  
   const moneypunct <char, false> &mpunct4 =   
      use_facet <moneypunct <char, false> >(loc2);  
   cout << loc2.name( ) << " domestic thousands separator: "  
        << mpunct4.thousands_sep( ) << endl;  
}  
```  
  
```Output  
German_Germany.1252 international thousands separator: .  
German_Germany.1252 domestic thousands separator: .  
  
English_Canada.1252 international thousands separator: ,  
English_Canada.1252 domestic thousands separator: ,  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<locale>](../standard-library/locale.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


