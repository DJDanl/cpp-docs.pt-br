---
title: C2893 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2893
dev_langs:
- C++
helpviewer_keywords:
- C2893
ms.assetid: ec0cbe43-005d-45da-8742-aaeb9b81d28e
caps.latest.revision: 12
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6dca7f1acf10620232859ac6b9f5a2ff87d4b865
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2893"></a>C2893 de erro do compilador
Falha de especializar o nome do modelo do modelo de função  
  
 O compilador não conseguiu especializar um modelo de função. Pode haver várias causas para esse erro.  
  
 Em geral, a maneira de resolver um erro C2893 é examinar a assinatura da função e certificar-se de que você pode instanciar cada tipo.  
  
## <a name="example"></a>Exemplo  
 C2893 ocorre porque `f`do parâmetro de modelo `T` é deduzida como sendo `std::map<int,int>`, mas `std::map<int,int>` não tiver nenhum membro `data_type` (`T::data_type` não pode ser instanciado com `T = std::map<int,int>`.). O exemplo a seguir gera C2893.  
  
```  
// C2893.cpp  
// compile with: /c /EHsc  
#include<map>  
using namespace std;  
class MyClass {};  
  
template<class T>   
inline typename T::data_type  
// try the following line instead  
// inline typename  T::mapped_type  
f(T const& p1, MyClass const& p2);  
  
template<class T>  
void bar(T const& p1) {  
    MyClass r;  
    f(p1,r);   // C2893  
}  
  
int main() {  
   map<int,int> m;  
   bar(m);  
}  
```
