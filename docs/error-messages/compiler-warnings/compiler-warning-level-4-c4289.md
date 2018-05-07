---
title: Compilador (nível 4) de aviso C4289 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4289
dev_langs:
- C++
helpviewer_keywords:
- C4289
ms.assetid: 0dbd2863-4cde-4e16-894b-104a2d5fa724
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6f7f09bd85d3740d43b6e4b6a80ed562f8cc2261
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4289"></a>Compilador C4289 de aviso (nível 4)
extensão não padrão usada: 'var': variável de controle de loop declarada no loop for é usada fora do escopo do loop for  
  
 Ao compilar com [/Ze](../../build/reference/za-ze-disable-language-extensions.md) e **/Zc:forScope-**, uma variável declarada em um [para](../../cpp/for-statement-cpp.md) loop foi usado após o **para**-loop de escopo.  
  
 Consulte [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar o comportamento padrão em **para** loops com **/Ze**.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 O exemplo a seguir gera C4289:  
  
```  
// C4289.cpp  
// compile with: /W4 /Zc:forScope-  
#pragma warning(default:4289)  
int main() {  
   for (int i = 0 ; ; )   // C4289  
      break;  
   i++;  
}  
```