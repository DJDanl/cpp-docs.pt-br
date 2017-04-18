---
title: C4693 de aviso do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4693
dev_langs:
- C++
helpviewer_keywords:
- C4693
ms.assetid: 72d8db01-5e6f-4794-8731-76107e8f064a
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0a2262d559f9771dc2ba4286e675de1bdea6c9ee
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-c4693"></a>C4693 de aviso do compilador
'class': uma classe abstrata lacrada não pode ter qualquer membro de instância 'Test'  
  
 Se um tipo é marcado [lacrado](../../windows/sealed-cpp-component-extensions.md) e [abstrato](../../windows/abstract-cpp-component-extensions.md), ele só pode ter membros estáticos.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4693.  
  
```  
// C4693.cpp  
// compile with: /clr /c  
public ref class Public_Ref_Class sealed abstract {  
public:  
   void Test() {}   // C4693  
   static void Test2() {}   // OK  
};  
```
