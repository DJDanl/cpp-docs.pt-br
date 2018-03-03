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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8c3526eecbe125a1a76b637734fecc72785556b7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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