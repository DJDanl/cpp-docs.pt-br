---
title: "Classe money_get | Microsoft Docs"
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
  - "xlocmon/std::money_get"
  - "money_get"
  - "std.money_get"
  - "std::money_get"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe money_get"
ms.assetid: 692d3374-3fe7-4b46-8aeb-f8d91ed66b2e
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe money_get
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo `CharType` em valores monetários.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class CharType, class InputIterator = istreambuf_iterator<CharType>>  
class money_get : public locale::facet;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres em uma localidade.  
  
 `InputIterator`  
 O tipo de iterador do qual as funções get leem sua entrada.  
  
## <a name="remarks"></a>Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em **id.**  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[money_get](#money_get__money_get)|O construtor para objetos do tipo `money_get` que são usados para extrair valores numéricos das sequências que representam valores monetários.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#money_get__char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[iter_type](#money_get__iter_type)|Um tipo que descreve um iterador de entrada.|  
|[STRING_TYPE](#money_get__string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[do_get](#money_get__do_get)|Uma função virtual chamada para extrair um valor numérico de uma sequência de caracteres que representa um valor monetário.|  
|[Obter](#money_get__get)|Extrai um valor numérico de uma sequência de caracteres que representa um valor monetário.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< localidade>  
  
 **Namespace:** std  
  
##  <a name="a-namemoneygetchartypea-moneygetchartype"></a><a name="money_get__char_type"></a>  money_get:: char_type  
 Um tipo que é usado para descrever um caractere usado por uma localidade.  
  
```
typedef CharType char_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **CharType**.  
  
##  <a name="a-namemoneygetdogeta-moneygetdoget"></a><a name="money_get__do_get"></a>  money_get:: do_get  
 Função virtual chamada para extrai um valor numérico de uma sequência de caracteres que representa um valor monetário.  
  
```
virtual iter_type do_get(iter_type first,
    iter_type last,
    bool _Intl,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long double& val) const virtual iter_type do_get(iter_type first,
    iter_type last,
    bool _Intl,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    string_type& val) const
```  
  
### <a name="parameters"></a>Parâmetros  
 `first`  
 Entrada de iterador que trata o início da sequência a ser convertido.  
  
 `last`  
 Entrada de iterador que trata o final da sequência a ser convertido.  
  
 `_Intl`  
 Um valor booleano que indica o tipo do símbolo de moeda esperado na sequência: **true** se internacionais, **false** se nacionais.  
  
 `_Iosbase`  
 Um formato sinalizar que quando definido indica que o símbolo de moeda é opcional. Caso contrário, é necessário.  
  
 `_State`  
 Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas ou não.  
  
 `val`  
 Uma cadeia de caracteres que armazenar a sequência convertida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de entrada que trata o primeiro elemento além do campo de entrada monetário.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro protegido virtual tenta corresponder elementos sequenciais, começando no primeiro na sequência [ `first`, `last`) até que ele reconheceu uma completa, nonempty monetário campo de entrada. Se for bem-sucedido, ele converte esse campo em uma sequência de um ou mais dígitos decimais, opcionalmente precedido por um sinal de subtração ( `–`), para representar a quantidade e armazena o resultado no [string_type](#money_get__string_type) objeto `val`. Ele retorna um iterador que designam o primeiro elemento além do campo de entrada monetário. Caso contrário, a função armazena uma sequência vazia no `val` e define `ios_base::failbit` em `_State`. Ele retorna um iterador que designam o primeiro elemento além de qualquer prefixo de um campo de entrada monetário válido. Em ambos os casos, se o valor de retorno é igual a `last`, os conjuntos de função `ios_base::eofbit` em `_State`.  
  
 A segunda função de membro protegido virtual se comporta da mesma maneira como o primeiro, exceto que, se for bem-sucedido ele converte a sequência de dígitos opcionalmente assinado com um valor do tipo `long double` e armazena esse valor em `val`.  
  
 O formato de um campo de entrada monetário é determinado pelo [faceta de localidade](../standard-library/locale-class.md#facet_class)**PAT** retornado pela chamada efetiva [use_facet](../Topic/%3Clocale%3E%20functions.md#use_facet) < [moneypunct](../Topic/moneypunct%20Class.md)\< **CharType**, **intl**>> ( **iosbase**. [getloc](../standard-library/ios-base-class.md#ios_base__getloc)).  
  
 Especificamente:  
  
- **PAT**. [neg_format](../Topic/moneypunct%20Class.md#moneypunct__neg_format) determina a ordem na qual os componentes do campo ocorrerem.  
  
- **PAT**. [curr_symbol](../Topic/moneypunct%20Class.md#moneypunct__curr_symbol) determina a sequência de elementos que constitui um símbolo de moeda.  
  
- **PAT**. [positive_sign](../Topic/moneypunct%20Class.md#moneypunct__positive_sign) determina a sequência de elementos que constitui um sinal positivo.  
  
- **PAT**. [negative_sign](../Topic/moneypunct%20Class.md#moneypunct__negative_sign) determina a sequência de elementos que constitui um sinal negativo.  
  
- **PAT**. [agrupando](../Topic/moneypunct%20Class.md#moneypunct__grouping) determina como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
- **PAT**. [thousands_sep](../Topic/moneypunct%20Class.md#moneypunct__thousands_sep) determina o elemento que separa grupos de dígitos à esquerda de qualquer vírgula decimal.  
  
- **PAT**. [decimal_point](../Topic/moneypunct%20Class.md#moneypunct__decimal_point) determina o elemento que separa os dígitos de inteiro de dígitos de fração.  
  
- **PAT**. [frac_digits](../Topic/moneypunct%20Class.md#moneypunct__frac_digits) determina o número de dígitos de fração significativa à direita de qualquer vírgula decimal. Ao analisar um valor monetário com mais dígitos de fração que são chamados para por `frac_digits`, `do_get` interrompe a análise após consumir no máximo `frac_digits` caracteres.  
  
 Se a cadeia de caracteres de entrada ( **PAT**. `negative_sign` ou **PAT**. `positive_sign`) tem mais de um elemento, apenas o primeiro elemento é correspondido onde o elemento igual a **money_base::sign** aparece no formato padrão ( **PAT**. `neg_format`). Todos os elementos restantes são comparados ao final do campo de entrada monetário. Se nenhuma cadeia de caracteres tem um primeiro elemento que coincide com o próximo elemento no campo de entrada monetário, a cadeia de caracteres de entrada é assumida como vazia e o sinal é positivo.  
  
 Se **iosbase**. [sinalizadores de](../standard-library/ios-base-class.md#ios_base__flags) & [showbase](../Topic/%3Cios%3E%20functions.md#showbase) é diferente de zero, a cadeia de caracteres **PAT**. `curr_symbol` deve corresponder a onde o elemento igual a **money_base::symbol** aparece no formato padrão. Caso contrário, se **money_base::symbol** ocorre no final do padrão de formato, e se nenhum elemento da sequência de caracteres de entrada continuarem a ser correspondida, o símbolo de moeda não é correspondente. Caso contrário, o símbolo de moeda é opcionalmente correspondente.  
  
 Se nenhuma instância de **PAT**. `thousands_sep` ocorrem na parte do valor do campo de entrada monetário (onde o elemento igual a **money_base::value** aparece no formato padrão), nenhuma restrição de agrupamento é imposta. Caso contrário, qualquer agrupamento restrições impostas pelo **PAT**. **agrupando** é imposta. Observe que a sequência resultante de dígito representa um número inteiro cuja ordem baixa **PAT**. `frac_digits` dígitos decimais são considerados para a direita da vírgula decimal.  
  
 Espaço em branco arbitrário é correspondido onde o elemento igual a **money_base::space** aparece no padrão de formato, se ela aparecer diferente no final do padrão de formato. Caso contrário, nenhum espaço em branco interno é correspondente. Um elemento *ch* é considerado o espaço em branco se [use_facet](../Topic/%3Clocale%3E%20functions.md#use_facet) < [ctype](../standard-library/ctype-class.md)\< **CharType**>> ( **iosbase**. [getloc](../standard-library/ios-base-class.md#ios_base__getloc)). [é](../standard-library/ctype-class.md#ctype__is)( **ctype_base::space**, *ch*) é **true**.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [obter](#money_get__get), que chama `do_get`.  
  
##  <a name="a-namemoneygetgeta-moneygetget"></a><a name="money_get__get"></a>  money_get:: Get  
 Extrai um valor numérico de uma sequência de caracteres que representa um valor monetário.  
  
```
iter_type get(iter_type first,
    iter_type last,
    bool _Intl,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    long double& val) const;

iter_type get(iter_type first,
    iter_type last,
    bool _Intl,
    ios_base& _Iosbase,
    ios_base::iostate& _State,
    string_type& val) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `first`  
 Entrada de iterador que trata o início da sequência a ser convertido.  
  
 `last`  
 Entrada de iterador que trata o final da sequência a ser convertido.  
  
 `_Intl`  
 Um valor booleano que indica o tipo do símbolo de moeda esperado na sequência: **true** se internacionais, **false** se nacionais.  
  
 `_Iosbase`  
 Um formato sinalizar que quando definido indica que o símbolo de moeda é opcional. Caso contrário, será necessário  
  
 `_State`  
 Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.  
  
 `val`  
 Uma cadeia de caracteres que armazenar a sequência convertida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de entrada que trata o primeiro elemento além do campo de entrada monetário.  
  
### <a name="remarks"></a>Comentários  
 Ambas as funções de membro retornam [do_get](#money_get__do_get)( `first``,` `last``,` `_Intl`, `_Iosbase`, `_State`, `val`).  
  
### <a name="example"></a>Exemplo  
  
```  
// money_get_get.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <sstream>  
using namespace std;  
  
int main( )  
{  
   locale loc( "german_germany" );  
  
   basic_stringstream< char > psz;  
   psz << use_facet<moneypunct<char, 1> >(loc).curr_symbol() << "-1.000,56";  
   basic_stringstream< char > psz2;  
   psz2 << "-100056" << use_facet<moneypunct<char, 1> >(loc).curr_symbol();  
  
   ios_base::iostate st = 0;  
   long double fVal;  
  
   psz.flags( psz.flags( )|ios_base::showbase );   
   // Which forced the READING the currency symbol  
   psz.imbue(loc);  
   use_facet < money_get < char > >( loc ).  
      get( basic_istream<char>::_Iter( psz.rdbuf( ) ),     
           basic_istream<char>::_Iter( 0 ), true, psz, st, fVal );  
  
   if ( st & ios_base::failbit )  
      cout << "money_get(" << psz.str( ) << ", intl = 1) FAILED"  
           << endl;  
   else  
      cout << "money_get(" << psz.str( ) << ", intl = 1) = "   
           << fVal/100.0 << endl;  
  
   use_facet < money_get < char > >( loc ).  
      get(basic_istream<char>::_Iter(psz2.rdbuf( )),     
          basic_istream<char>::_Iter(0), false, psz2, st, fVal);  
  
   if ( st & ios_base::failbit )  
      cout << "money_get(" << psz2.str( ) << ", intl = 0) FAILED"   
           << endl;  
   else  
      cout << "money_get(" << psz2.str( ) << ", intl = 0) = "   
           << fVal/100.0 << endl;  
};  
```  
  
##  <a name="a-namemoneygetitertypea-moneygetitertype"></a><a name="money_get__iter_type"></a>  money_get:: iter_type  
 Um tipo que descreve um iterador de entrada.  
  
```
typedef InputIterator iter_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **InputIterator**.  
  
##  <a name="a-namemoneygetmoneygeta-moneygetmoneyget"></a><a name="money_get__money_get"></a>  money_get:: money_get  
 O construtor para objetos do tipo `money_get` que são usados para extrair valores numéricos das sequências que representam valores monetários.  
  
```
explicit money_get(size_t _Refs = 0);
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
  
 O construtor inicializa o objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)( **_***Refs*).  
  
##  <a name="a-namemoneygetstringtypea-moneygetstringtype"></a><a name="money_get__string_type"></a>  money_get:: STRING_TYPE  
 Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo **CharType**.  
  
```
typedef basic_string<CharType, Traits, Allocator> string_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [\< localidade>](../standard-library/locale.md)   
 [Classe facet](../standard-library/locale-class.md#facet_class)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



