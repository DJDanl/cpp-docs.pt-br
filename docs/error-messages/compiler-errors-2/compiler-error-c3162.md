---
title: C3162 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3162
dev_langs:
- C++
helpviewer_keywords:
- C3162
ms.assetid: 0d4c4a24-1456-4191-b7d8-c38cb7b17c32
caps.latest.revision: 4
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8bfde260ef0efe58ed70469a80a8bf7316eefa46
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3162"></a>C3162 de erro do compilador
'type': um tipo de referência que tenha um destruidor não pode ser usado como o tipo de membro de dados estáticos 'member'  
  
 O common language runtime não é possível saber quando executar um destruidor definido pelo usuário quando a classe também contém a função de membro estático.  
  
 Um destruidor nunca será executado, a menos que o objeto é excluído explicitamente.  
  
 Para obter mais informações, consulte  
  
-   [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Problemas de migração de 64 bits do Visual C++ comuns](../../build/common-visual-cpp-64-bit-migration-issues.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3162.  
  
```  
// C3162.cpp  
// compile with: /clr /c  
ref struct A {  
   ~A() { System::Console::WriteLine("in destructor"); }  
   static A i;   // C3162  
   static A^ a = gcnew A;   // OK  
};  
  
int main() {  
   A ^ a = gcnew A;  
   delete a;  
}  
```
