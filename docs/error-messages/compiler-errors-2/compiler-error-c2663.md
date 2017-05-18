---
title: C2663 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2663
dev_langs:
- C++
helpviewer_keywords:
- C2663
ms.assetid: 1e93e368-fd52-42bf-9908-9b6df467c8c9
caps.latest.revision: 9
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
ms.openlocfilehash: 1803d1bd5576143add604cfd4bfcad149310d606
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2663"></a>C2663 de erro do compilador
'function': número sobrecargas não tem nenhuma conversão legal para o ponteiro 'this'  
  
 O compilador não foi possível converter `this` para qualquer uma das versões sobrecarregadas da função de membro.  
  
 Esse erro pode ser causado invocando um não -`const` função de membro em uma `const` objeto.  Possíveis resoluções:  
  
1.  Remover o `const` da declaração de objeto.  
  
2.  Adicionar `const` para uma das sobrecargas de função de membro.  
  
 O exemplo a seguir gera C2663:  
  
```  
// C2663.cpp  
struct C {  
   void f() volatile {}  
   void f() {}  
};  
  
struct D {  
   void f() volatile;  
   void f() const {}  
};  
  
const C *pcc;  
const D *pcd;  
  
int main() {  
   pcc->f();    // C2663  
   pcd->f();    // OK  
}  
```
