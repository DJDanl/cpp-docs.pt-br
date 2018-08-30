---
title: Compilador aviso (nível 1) C4312 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4312
dev_langs:
- C++
helpviewer_keywords:
- C4312
ms.assetid: 541906ed-4f62-4bcb-947f-cf9ae7411bcb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8b30d020532935c925b1ecab25d17cd43a7e8663
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43205896"
---
# <a name="compiler-warning-level-1-c4312"></a>Compilador aviso (nível 1) C4312
'operation': conversão de 'type1' em 'type2' de tamanho maior  
  
 Esse aviso detecta uma tentativa de atribuir um valor de 32 bits em um tipo de ponteiro de 64 bits, por exemplo, a conversão de 32 bits `int` ou `long` para um ponteiro de 64 bits.  
  
 Isso pode ser uma conversão não segura mesmo para valores de ponteiro que se encaixam em 32 bits quando ocorre de extensão de sinal. Se um inteiro de 32 bits negativo é atribuído a um tipo de ponteiro de 64 bits, extensão de sinal faz com que o valor do ponteiro fazer referência a um endereço de memória diferente do valor do inteiro.  
  
 Esse aviso é emitido apenas para destinos de compilação de 64 bits. Para obter mais informações, consulte [regras para usar ponteiros](/windows/desktop/WinProg64/rules-for-using-pointers).  
  
 O exemplo de código a seguir gera C4312 quando ele é compilado para destinos de 64 bits:  
  
```  
// C4312.cpp  
// compile by using: cl /W1 /LD C4312.cpp  
void* f(int i) {  
   return (void*)i;   // C4312 for 64-bit targets  
}  
  
void* f2(__int64 i) {  
   return (void*)i;   // OK  
}  
```