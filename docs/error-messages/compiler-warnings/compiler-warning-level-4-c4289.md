---
title: "Compilador (nível 4) de aviso C4289 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4289
dev_langs: C++
helpviewer_keywords: C4289
ms.assetid: 0dbd2863-4cde-4e16-894b-104a2d5fa724
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 98acda62a984f2625ddc742e309aca7628d9c9f3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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