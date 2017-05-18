---
title: "Compilador aviso (nível 1) C4965 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4965
dev_langs:
- C++
helpviewer_keywords:
- C4965
ms.assetid: 47f3f6dc-459b-4a25-9947-f394c8966cb5
caps.latest.revision: 14
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
ms.openlocfilehash: 53ed24bf928a971d1a315af73fa01b786da8958e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4965"></a>Compilador C4965 de aviso (nível 1)
box implícito de inteiro 0; use nullptr ou conversão explícita  
  
 Conversão boxing implícita de tipos de valor de recursos do Visual C++. Uma instrução que resultaram em uma atribuição null usando extensões gerenciadas para C++ agora se torna uma atribuição a um int. box  
  
 Para obter mais informações, consulte [conversão Boxing](../../windows/boxing-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4965.  
  
```  
// C4965.cpp  
// compile with: /clr /W1  
int main() {  
   System::Object ^o = 0;   // C4965  
  
   // the previous line is the same as the following line  
   // using Managed Extensions for C++  
   // System::Object *o = __box(0);  
  
   // OK  
   System::Object ^o2 = nullptr;  
   System::Object ^o3 = safe_cast<System::Object^>(0);  
}  
```
