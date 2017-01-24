---
title: "Classe money_put | Microsoft Docs"
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
  - "std::money_put"
  - "xlocmon/std::money_put"
  - "money_put"
  - "std.money_put"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe money_put"
ms.assetid: f439fd56-c9b1-414c-95e1-66c918c6eee6
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe money_put
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

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
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em **id.**  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[money_put](#money_put__money_put)|O construtor para objetos do tipo `money_put`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#money_put__char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|  
|[iter_type](#money_put__iter_type)|Um tipo que descreve um iterador de saída.|  
|[STRING_TYPE](#money_put__string_type)|Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo `CharType`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[do_put](#money_put__do_put)|Uma função virtual chamada para converter o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.|  
|[colocar](#money_put__put)|Converte o número ou uma cadeia de caracteres em uma sequência de caracteres que representa um valor monetário.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< localidade>  
  
 **Namespace:** std  
  
##  <a name="a-namemoneyputchartypea-moneyputchartype"></a><a name="money_put__char_type"></a>  money_put:: char_type  
 Um tipo que é usado para descrever um caractere usado por uma localidade.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **CharType**.  
  
##  <a name="a-namemoneyputdoputa-moneyputdoput"></a><a name="money_put__do_put"></a>  money_put:: do_put  
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
 ` next`  
 Um iterador que trata o primeiro elemento da cadeia de caracteres inserida.  
  
 `_Intl`  
 Um valor booleano que indica o tipo do símbolo de moeda esperado na sequência: **true** se internacionais, **false** se nacionais.  
  
 `_Iosbase`  
 Um formato sinalizar que quando definido indica que o símbolo de moeda é opcional. Caso contrário, será necessário  
  
 `_Fill`  
 Um caractere que é usado para espaçamento.  
  
 ` val`  
 Um objeto de cadeia de caracteres a ser convertido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída produzida de uma posição além do último elemento os endereços.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro protegido virtual gera elementos sequenciais começando no ` next` para produzir um campo de saída monetário do [string_type](#money_put__string_type) objeto ` val`. A sequência controlada por ` val` deve começar com um ou mais dígitos decimais, opcionalmente precedidos por um sinal de subtração (-), que representa a quantidade. A função retorna um iterador que designam o primeiro elemento além do campo de saída monetário gerado.  
  
 A segunda função de membro protegido virtual se comporta da mesma maneira como a primeira, exceto que ele efetivamente primeiramente converte ` val` em uma sequência de dígitos decimais, opcionalmente precedido por um sinal de subtração, converte essa sequência acima.  
  
 O formato de um campo de saída monetário é determinado pelo [faceta de localidade](../standard-library/locale-class.md#facet_class) PAT retornado pela chamada (efetiva) [use_facet](../Topic/%3Clocale%3E%20functions.md#use_facet) < [moneypunct](../Topic/moneypunct%20Class.md)\< **CharType**, **intl**>> ( **iosbase**. [getloc](../standard-library/ios-base-class.md#ios_base__getloc)).  
  
 Especificamente:  
  
- **PAT**. [pos_format](../Topic/moneypunct%20Class.md#moneypunct__pos_format) determina a ordem na qual os componentes do campo são gerados para um valor negativo.  
  
- **PAT**. [neg_format](../Topic/moneypunct%20Class.md#moneypunct__neg_format) determina a ordem na qual os componentes do campo são geradas para um valor negativo.  
  
- **PAT**. [curr_symbol](../Topic/moneypunct%20Class.md#moneypunct__curr_symbol) determina a sequência de elementos para gerar um símbolo de moeda.  
  
- **PAT**. [positive_sign](../Topic/moneypunct%20Class.md#moneypunct__positive_sign) determina a sequência de elementos para gerar um sinal positivo.  
  
- **PAT**. [negative_sign](../Topic/moneypunct%20Class.md#moneypunct__negative_sign) determina a sequência de elementos para gerar um sinal negativo.  
  
- **PAT**. [agrupando](../Topic/moneypunct%20Class.md#moneypunct__grouping) determina como os dígitos são agrupados à esquerda de qualquer vírgula decimal.  
  
- **PAT**. [thousands_sep](../Topic/moneypunct%20Class.md#moneypunct__thousands_sep) determina o elemento que separa grupos de dígitos à esquerda de qualquer vírgula decimal.  
  
- **PAT**. [decimal_point](../Topic/moneypunct%20Class.md#moneypunct__decimal_point) determina o elemento que separa os dígitos de inteiro dos dígitos de fração.  
  
- **PAT**. [frac_digits](../Topic/moneypunct%20Class.md#moneypunct__frac_digits) determina o número de dígitos de fração significativa à direita de qualquer vírgula decimal.  
  
 Se a cadeia de caracteres de entrada ( **PAT**. `negative_sign` ou **PAT**. `positive_sign`) tem mais de um elemento, apenas o primeiro elemento é gerado em que o elemento igual a **money_base::sign** aparece no formato padrão ( **PAT**. `neg_format` ou **PAT**. `pos_format`). Todos os elementos restantes são gerados no final do campo de saída monetário.  
  
 Se **iosbase**. [sinalizadores de](../standard-library/ios-base-class.md#ios_base__flags) & [showbase](../Topic/%3Cios%3E%20functions.md#showbase) é diferente de zero, a cadeia de caracteres **PAT**. `curr_symbol` é gerado em que o elemento igual a **money_base::symbol** aparece no formato padrão. Caso contrário, nenhum símbolo de moeda é gerado.  
  
 Se nenhum agrupamento restrições são impostas pelo **PAT**. **agrupamento** (o primeiro elemento tem o valor CHAR_MAX), então não há instâncias de **PAT**. `thousands_sep` são gerados na parte do valor do campo de saída monetário (onde o elemento igual a **money_base::value** aparece no formato padrão). Se **PAT**. `frac_digits` é zero, então não nenhuma instância de **PAT**. `decimal_point` é gerado após os dígitos decimais. Caso contrário, o campo de saída monetário resultante coloca de ordem inferior **PAT**. `frac_digits` dígitos à direita da vírgula decimal.  
  
 Preenchimento ocorre para qualquer campo de saída numérico, exceto que se **iosbase**. **sinalizadores de** & **iosbase**. [interno](../Topic/%3Cios%3E%20functions.md#internal) é diferente de zero, qualquer interno de preenchimento é gerado em que o elemento igual a **money_base::space** aparece no padrão de formato, se ele aparecer. Caso contrário, o preenchimento interno ocorre antes da sequência gerada. O caractere de preenchimento é **preenchimento**.  
  
 As chamadas de função **iosbase**. **largura**para redefinir a largura do campo como zero (0).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [colocar](#money_put__put), onde a função membro virtual é chamada pelo **colocar**.  
  
##  <a name="a-namemoneyputitertypea-moneyputitertype"></a><a name="money_put__iter_type"></a>  money_put:: iter_type  
 Um tipo que descreve um iterador de saída.  
  
```  
typedef OutputIterator iter_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **OutputIterator.**  
  
##  <a name="a-namemoneyputmoneyputa-moneyputmoneyput"></a><a name="money_put__money_put"></a>  money_put:: money_put  
 O construtor para objetos do tipo `money_put`.  
  
```  
explicit money_put(size_t _Refs = 0);
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
  
 O construtor inicializa o objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)( `_Refs`).  
  
##  <a name="a-namemoneyputputa-moneyputput"></a><a name="money_put__put"></a>  money_put:: Put  
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
 ` next`  
 Um iterador que trata o primeiro elemento da cadeia de caracteres inserida.  
  
 `_Intl`  
 Um valor booleano que indica o tipo do símbolo de moeda esperado na sequência: **true** se internacionais, **false** se nacionais.  
  
 `_Iosbase`  
 Um formato sinalizar que quando definido indica que o símbolo de moeda é opcional. Caso contrário, será necessário  
  
 `_Fill`  
 Um caractere que é usado para espaçamento.  
  
 ` val`  
 Um objeto de cadeia de caracteres a ser convertido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída produzida de uma posição além do último elemento os endereços.  
  
### <a name="remarks"></a>Comentários  
 Ambas as funções de membro retornam [do_put](#money_put__do_put)( ` next`, `_Intl`, `_Iosbase`, `_Fill`, ` val`).  
  
### <a name="example"></a>Exemplo  
  
```  
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
  
##  <a name="a-namemoneyputstringtypea-moneyputstringtype"></a><a name="money_put__string_type"></a>  money_put:: STRING_TYPE  
 Um tipo que descreve uma cadeia de caracteres que contém caracteres do tipo **CharType**.  
  
```  
typedef basic_string<CharType, Traits, Allocator> string_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar sequências de elementos da sequência de origem.  
  
## <a name="see-also"></a>Consulte também  
 [\< localidade>](../standard-library/locale.md)   
 [Classe facet](../standard-library/locale-class.md#facet_class)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

