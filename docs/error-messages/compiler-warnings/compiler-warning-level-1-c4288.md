---
title: "Compilador (nível 1) de aviso C4288 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4288
dev_langs:
- C++
helpviewer_keywords:
- C4288
ms.assetid: 6aaeb139-90cd-457a-9d37-65687042736f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a10a7573df5986ed20475b34208a1e0f301d9bb9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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