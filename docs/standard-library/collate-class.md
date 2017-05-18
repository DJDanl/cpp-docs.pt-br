---
title: Classe collate | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- locale/std::collate
- collate
- Collate
- locale/std::collate::char_type
- locale/std::collate::string_type
- locale/std::collate::compare
- locale/std::collate::do_compare
- locale/std::collate::do_hash
- locale/std::collate::do_transform
- locale/std::collate::hash
- locale/std::collate::transform
dev_langs:
- C++
helpviewer_keywords:
- collate class
ms.assetid: 92168798-9628-4a2e-be6e-fa62dcd4d6a6
caps.latest.revision: 18
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 070813dde1fc118e35ade636261541e585504c50
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="collate-class"></a>Classe collate
Uma classe de modelo que descreve um objeto que pode funcionar como uma faceta de localidade para controlar a ordenação e o agrupamento de caracteres em uma cadeia de caracteres, as comparações entre eles e o hash de cadeias de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class CharType>  
class collate : public locale::facet;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres.  
  
## <a name="remarks"></a>Comentários  
 Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.** Em algumas linguagens, os caracteres são agrupados e tratados como um único caractere e, em outras, caracteres individuais são tratados como se fossem dois caracteres. Os serviços de agrupamento fornecidos pela classe collate fornecem o meio de classificar esses casos.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[collate](#collate)|O construtor para objetos da classe `collate` que serve como uma faceta de localidade para tratar convenções de classificação de cadeia de caracteres.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#char_type)|Um tipo que descreve um caractere do tipo `CharType`.|  
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo `CharType`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[compare](#compare)|Compara duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.|  
|[do_compare](#do_compare)|Uma função virtual chamada para comparar duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.|  
|[do_hash](#do_hash)|Uma função virtual chamada para determinar o valor de hash das sequências de acordo com as respectivas regras específicas de faceta.|  
|[do_transform](#do_transform)|Uma função virtual chamada para converter uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.|  
|[hash](#hash)|Determina o valor de hash da sequência de acordo com suas regras específicas de faceta.|  
|[transform](#transform)|Converte uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
##  <a name="char_type"></a>  collate::char_type  
 Um tipo que descreve um caractere do tipo **CharType**.  
  
```  
typedef CharType char_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType**.  
  
##  <a name="collate"></a>  collate::collate  
 O construtor de objetos da classe collate que funciona como uma faceta de localidade para manipular convenções de classificação de cadeia de caracteres.  
  
```  
public:  
    explicit collate(
    size_t _Refs = 0);

protected:  
    collate(
 const char* _Locname,  
    size_t _Refs = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Refs`  
 Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.  
  
 `_Locname`  
 O nome da localidade.  
  
### <a name="remarks"></a>Comentários  
 Os valores possíveis para o parâmetro `_Refs` e sua significância são:  
  
-   0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.  
  
-   1: o tempo de vida do objeto deve ser gerenciado manualmente.  
  
-   \>1: esses valores não são definidos.  
  
 O construtor inicializa o objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)(`_Refs`).  
  
##  <a name="compare"></a>  collate::compare  
 Compara duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.  
  
```  
int compare(const CharType* first1,
    const CharType* last1,
    const CharType* first2,
    const CharType* last2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `first1`  
 Ponteiro para o primeiro elemento na primeira sequência a ser comparada.  
  
 `last1`  
 Ponteiro para o último elemento na primeira sequência a ser comparada.  
  
 `first2`  
 Ponteiro para o primeiro elemento na segunda sequência a ser comparada.  
  
 `last2`  
 Ponteiro para o último elemento na segunda sequência a ser comparada.  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro retornará:  
  
-   –1 se a primeira sequência comparar menos do que a segunda sequência.  
  
-   +1 se a segunda sequência comparar menos do que a primeira sequência.  
  
-   0 se as sequências forem equivalentes.  
  
### <a name="remarks"></a>Comentários  
 A primeira sequência comparará menos se ela tiver o elemento menor do par desigual mais antigo nas sequências ou, se não existir nenhum par desigual, mas a primeira sequência for menor.  
  
 A função membro retorna [do_compare](#do_compare)( `first1`, `last1`, `first2`, `last2`).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// collate_compare.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <tchar.h>  
using namespace std;  
  
int main() {  
   locale loc ( "German_germany" );  
   _TCHAR * s1 = _T("Das ist wei\x00dfzz."); // \x00df is the German sharp-s, it comes before z in the German alphabet  
   _TCHAR * s2 = _T("Das ist weizzz.");  
   int result1 = use_facet<collate<_TCHAR> > ( loc ).  
      compare ( s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << result1 << endl;  
  
   locale loc2 ( "C" );  
   int result2 = use_facet<collate<_TCHAR> > ( loc2 ).  
      compare (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
   cout << result2 << endl;  
}  
```  
  
##  <a name="do_compare"></a>  collate::do_compare  
 Uma função virtual chamada para comparar duas sequências de caracteres de acordo com as igualdades ou desigualdades das respectivas regras específicas de faceta.  
  
```  
virtual int do_compare(const CharType* first1,
    const CharType* last1,
    const CharType* first2,
    const CharType* last2) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `first1`  
 Ponteiro para o primeiro elemento na primeira sequência a ser comparada.  
  
 `last1`  
 Ponteiro para o último elemento na primeira sequência a ser comparada.  
  
 `first2`  
 Ponteiro para o primeiro elemento na segunda sequência a ser comparada.  
  
 `last2`  
 Ponteiro para o último elemento na segunda sequência a ser comparada.  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro retornará:  
  
-   –1 se a primeira sequência comparar menos do que a segunda sequência.  
  
-   +1 se a segunda sequência comparar menos do que a primeira sequência.  
  
-   0 se as sequências forem equivalentes.  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegido compara a sequência em [* first1, Last1) * com a sequência em *[first2, last2*). Ele compara valores aplicando **operator<** entre pares de elementos correspondentes do tipo **CharType**. A primeira sequência comparará menos se ela tiver o elemento menor do par desigual mais antigo nas sequências ou, se não existir nenhum par desigual, mas a primeira sequência for menor.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [collate::compare](#compare), que chama `do_compare`.  
  
##  <a name="do_hash"></a>  collate::do_hash  
 Uma função virtual chamada para determinar o valor de hash das sequências de acordo com as respectivas regras específicas de faceta.  
  
```  
virtual long do_hash(const CharType* first, const CharType* last) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `first`  
 Um ponteiro para o primeiro caractere na sequência cujo valor será determinado.  
  
 `last`  
 Um ponteiro para o último caractere na sequência cujo valor será determinado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de hash do tipo **longo** da sequência.  
  
### <a name="remarks"></a>Comentários  
 Um valor de hash pode ser útil, por exemplo, na distribuição de sequências de maneira pseudo-aleatória em uma matriz de listas.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [hash](#hash), que chama `do_hash`.  
  
##  <a name="do_transform"></a>  collate::do_transform  
 Uma função virtual chamada para converter uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.  
  
```  
virtual string_type do_transform(const CharType* first, const CharType* last) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `first`  
 Um ponteiro para o primeiro caractere na sequência a ser convertida.  
  
 `last`  
 Um ponteiro para o último caractere na sequência a ser convertida.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que é a sequência de caracteres transformados.  
  
### <a name="remarks"></a>Comentários  
 A função membro virtual protegida retorna um objeto da classe [string_type](#string_type) cuja sequência controlada é uma cópia da sequência [ `first`, `last`). Se uma classe derivada decollate\< **CharType**> substituir [do_compare](#do_compare), ela também deverá substituir `do_transform` para haver correspondência. Quando passadas para `collate::compare`, duas cadeias de caracteres transformadas devem produzir o mesmo resultado que você obteria ao passar as cadeias de caracteres não transformadas para serem comparadas na classe derivada.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [transform](#transform), que chama `do_transform`.  
  
##  <a name="hash"></a>  collate::hash  
 Determina o valor de hash da sequência de acordo com suas regras específicas de faceta.  
  
```  
long hash(const CharType* first, const CharType* last) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `first`  
 Um ponteiro para o primeiro caractere na sequência cujo valor será determinado.  
  
 `last`  
 Um ponteiro para o último caractere na sequência cujo valor será determinado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de hash do tipo **longo** da sequência.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_hash](#do_hash)( `first`, `last`).  
  
 Um valor de hash pode ser útil, por exemplo, na distribuição de sequências de maneira pseudo-aleatória em uma matriz de listas.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// collate_hash.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <tchar.h>  
using namespace std;  
  
int main( )     
{  
   locale loc ( "German_germany" );  
   _TCHAR * s1 = _T("\x00dfzz abc."); // \x00df is the German sharp-s (looks like beta), it comes before z in the alphabet  
   _TCHAR * s2 = _T("zzz abc."); // \x00df is the German sharp-s (looks like beta), it comes before z in the alphabet  
  
   long r1 = use_facet< collate<_TCHAR> > ( loc ).  
      hash (s1, &s1[_tcslen( s1 )-1 ]);  
   long r2 =  use_facet< collate<_TCHAR> > ( loc ).  
      hash (s2, &s2[_tcslen( s2 )-1 ] );  
   cout << r1 << " " << r2 << endl;  
}  
```  
  
```Output  
541187293 551279837  
```  
  
##  <a name="string_type"></a>  collate::string_type  
 Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo **CharType**.  
  
```  
typedef basic_string<CharType> string_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar cópias das sequências de origem.  
  
### <a name="example"></a>Exemplo  
  Para obter um exemplo de como declarar e usar `string_type`, consulte [transform](#transform).  
  
##  <a name="transform"></a>  collate::transform  
 Converte uma sequência de caracteres de uma localidade em uma cadeia de caracteres que pode ser usada em comparações lexicográficas com outras sequências de caracteres convertidas da mesma forma da mesma localidade.  
  
```  
string_type transform(const CharType* first, const CharType* last) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `first`  
 Um ponteiro para o primeiro caractere na sequência a ser convertida.  
  
 `last`  
 Um ponteiro para o último caractere na sequência a ser convertida.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém a sequência de caracteres transformados.  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna [do_transform](#do_transform)( `first`, `last`).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// collate_transform.cpp  
// compile with: /EHsc  
#include <locale>  
#include <iostream>  
#include <tchar.h>  
using namespace std;  
  
int main( )     
{  
   locale loc ( "German_Germany" );  
   _TCHAR* s1 = _T("\x00dfzz abc.");   
   // \x00df is the German sharp-s (looks like beta),   
   // it comes before z in the alphabet  
   _TCHAR* s2 = _T("zzz abc.");   
  
   collate<_TCHAR>::string_type r1;   // OK for typedef  
   r1 = use_facet< collate<_TCHAR> > ( loc ).  
      transform (s1, &s1[_tcslen( s1 )-1 ]);  
  
   cout << r1 << endl;  
  
   basic_string<_TCHAR> r2 = use_facet< collate<_TCHAR> > ( loc ).  
      transform (s2, &s2[_tcslen( s2 )-1 ]);  
  
   cout << r2 << endl;  
  
   int result1 = use_facet<collate<_TCHAR> > ( loc ).compare   
      (s1, &s1[_tcslen( s1 )-1 ],  s2, &s2[_tcslen( s2 )-1 ] );  
  
   cout << _tcscmp(r1.c_str( ),r2.c_str( )) << result1   
      << _tcscmp(s1,s2) <<endl;  
}  
```  
  
```Output  
      
  
        
  
-1-11  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<locale>](../standard-library/locale.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


