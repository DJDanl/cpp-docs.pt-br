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
ms.openlocfilehash: 623183e5ee54c995d624f47461c724ee8f4befae
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43217392"
---
# <a name="compiler-warning-level-4-c4242"></a>Compilador aviso (nível 4) C4242
'identifier': conversão de 'type1' em 'type2', possível perda de dados  
  
 Os tipos forem diferentes. Conversão de tipo pode resultar em perda de dados. O compilador faz a conversão de tipo.  
  
 Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 Para obter informações adicionais sobre C4242, consulte [comuns de erros de compilador](/windows/desktop/WinProg64/common-compiler-errors).  
  
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