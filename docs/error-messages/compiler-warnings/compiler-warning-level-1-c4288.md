---
title: Compilador (nível 1) de aviso C4288 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4288
dev_langs:
- C++
helpviewer_keywords:
- C4288
ms.assetid: 6aaeb139-90cd-457a-9d37-65687042736f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f2c51bdc201b364d76f1692db8ee14973c90923f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33276624"
---
# <a name="compiler-warning-level-1-c4288"></a>Compilador C4288 de aviso (nível 1)
extensão não padrão usada: 'var': variável de controle de loop declarada no loop for é usada fora do escopo de loop for; ela está em conflito com a declaração no escopo externo  
  
 Ao compilar com [/Ze](../../build/reference/za-ze-disable-language-extensions.md) e **/Zc:forscope-**, uma variável declarada em um **para** loop foi usado após o [para](../../cpp/for-statement-cpp.md)-loop de escopo. Uma extensão da Microsoft para a linguagem C++ permite essa variável permanecerá no escopo e C4288 lembra você de que a primeira declaração da variável não é usada.  
  
 Consulte [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar a extensão da Microsoft em **para** loops com /Ze.  
  
 O exemplo a seguir gera C4288:  
  
```  
// C4288.cpp  
// compile with: /W1 /c /Zc:forScope-  
int main() {  
   int i = 0;    // not used in this program  
   for (int i = 0 ; ; ) ;  
   i++;   // C4288 using for-loop declaration of i  
}  
```