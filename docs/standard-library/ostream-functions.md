---
title: "Funções &lt;ostream&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ostream/std::swap
- ostream/std::endl
- ostream/std::ends
- ostream/std::flush
ms.assetid: d6e56cc0-c8df-4dbe-be10-98e14c35ed3a
caps.latest.revision: 15
manager: ghogen
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 89eebd013c08f52175e5e4038b501d4ce572e55a
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="ltostreamgt-functions"></a>Funções &lt;ostream&gt;
||||  
|-|-|-|  
|[swap](#swap)|[endl](#endl)|[ends](#ends)|  
|[flush](#flush)|  
  
##  <a name="endl"></a>  endl  
 Termina uma linha e libera o buffer.  
  
```  
template class<Elem, Tr> basic_ostream<Elem, Tr>& endl(basic_ostream<Elem, Tr>& Ostr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Elem`  
 O tipo de elemento.  
  
 `Ostr`  
 Um objeto do tipo `basic_ostream`.  
  
 `Tr`  
 Características de caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto do tipo `basic_ostream`.  
  
### <a name="remarks"></a>Comentários  
 O manipulador chama `Ostr`**.**[put](../standard-library/basic-ostream-class.md#put)( `Ostr`**.** [widen](../standard-library/basic-ios-class.md#widen)( **'\n'**)) e, em seguida, chama `Ostr`**.**[flush](../standard-library/basic-ostream-class.md#flush). Ele retorna `Ostr`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_endl.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   cout << "testing" << endl;  
}  
```  
  
```Output  
testing  
```  
  
##  <a name="ends"></a>  ends  
 Termina uma cadeia de caracteres.  
  
```  
template class<Elem, Tr> basic_ostream<Elem, Tr>& ends(basic_ostream<Elem, Tr>& Ostr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Elem`  
 O tipo de elemento.  
  
 `Ostr`  
 Um objeto do tipo `basic_ostream`.  
  
 `Tr`  
 Características de caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto do tipo `basic_ostream`.  
  
### <a name="remarks"></a>Comentários  
 O manipulador chama `Ostr`**.**[put](../standard-library/basic-ostream-class.md#put)( `Elem`( **'\0'**)). Retorna `Ostr.`  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_ends.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   cout << "a";  
   cout << "b" << ends;  
   cout << "c" << endl;  
}  
```  
  
```Output  
ab c  
```  
  
##  <a name="flush"></a>  flush  
 Libera o buffer.  
  
```  
template class<Elem, Tr> basic_ostream<Elem, Tr>& flush(basic_ostream<Elem, Tr>& Ostr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Elem`  
 O tipo de elemento.  
  
 `Ostr`  
 Um objeto do tipo `basic_ostream`.  
  
 `Tr`  
 Características de caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto do tipo `basic_ostream`.  
  
### <a name="remarks"></a>Comentários  
 O manipulador chama `Ostr`**.**[flush](../standard-library/basic-ostream-class.md#flush). Ele retorna `Ostr`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_flush.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   cout << "testing" << flush;  
}  
```  
  
```Output  
testing  
```  
  
##  <a name="swap"></a>  swap  
 Troca os valores de dois objetos `basic_ostream`.  
  
```  
template <class Elem, class Tr>  
void swap(
    basic_ostream<Elem, Tr>& left,  
    basic_ostream<Elem, Tr>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `left`  
 Uma referência lvalue a um objeto `basic_ostream`.  
  
 `right`  
 Uma referência lvalue a um objeto `basic_ostream`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo `swap` executa `left.swap(right)`.  
  
## <a name="see-also"></a>Consulte também  
 [\<ostream>](../standard-library/ostream.md)


