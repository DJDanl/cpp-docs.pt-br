---
title: Compilador (nível 4) do aviso C4242 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4242
dev_langs:
- C++
helpviewer_keywords:
- C4242
ms.assetid: 8df742e1-fbf1-42f3-8e93-c0e1c222dc7e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: befe02b363c17a670d3b33632ffa50ed8a7cb1f5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4242"></a>Compilador (nível 4) do aviso C4242
'Identificador': conversão de 'type1' em 'type2', possível perda de dados  
  
 Os tipos são diferentes. Conversão de tipo pode resultar em perda de dados. O compilador faz a conversão de tipo.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 Para obter informações adicionais sobre C4242, consulte [erros comuns de compilador](http://msdn.microsoft.com/library/windows/desktop/aa384160).  
  
 O exemplo a seguir gera C4242:  
  
```  
// C4242.cpp  
// compile with: /W4  
#pragma warning(4:4242)  
int func() {  
   return 0;  
}  
  
int main() {  
   char a;  
   a = func();   // C4242, return type and variable type do not match  
}  
```