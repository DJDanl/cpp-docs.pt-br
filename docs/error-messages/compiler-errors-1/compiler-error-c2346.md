---
title: C2346 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2346
dev_langs:
- C++
helpviewer_keywords:
- C2346
ms.assetid: 246145be-5645-4cd6-867c-e3bc39e33dca
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: bf0133aba65b8477bd949cd90b51edbd407bcda7
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2346"></a>C2346 de erro do compilador
'function' não pode ser compilado como nativo: motivo  
  
 O compilador não pôde compilar uma função para MSIL.  
  
 Para obter mais informações, consulte [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md) e [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Remova o código na função que não pode ser compilada para MSIL.  
  
2.  O não compilar o módulo com **/clr**, ou marcar a função como não gerenciado com o pragma não gerenciado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2346.  
  
```  
// C2346.cpp  
// processor: x86  
// compile with: /clr   
// C2346 expected  
struct S  
{  
   S()  
   {  
      { __asm { nop } }  
   }  
   virtual __clrcall ~S() { }  
};  
  
void main()  
{  
   S s;  
}  
```
