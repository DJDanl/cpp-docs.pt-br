---
title: Compilador (nível 1) de aviso C4311 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4311
dev_langs:
- C++
helpviewer_keywords:
- C4311
ms.assetid: ddc579d0-d051-47bc-915d-71ffb32323c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ba06488ed41e7e296f9f6c16f34af827274acfd4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33279117"
---
# <a name="compiler-warning-level-1-c4311"></a>Compilador C4311 de aviso (nível 1)
'variable': truncamento de ponteiro de 'type' para 'type'  
  
 Esse aviso detecta problemas de truncamento de ponteiro de 64 bits. Por exemplo, se o código é compilado para uma arquitetura de 64 bits, o valor de um ponteiro (64 bits) será truncado se ele for atribuído a um `int` (32 bits). Para obter mais informações, consulte [regras para usar ponteiros](http://msdn.microsoft.com/library/windows/desktop/aa384242).  
  
 Para obter informações adicionais sobre as causas comuns de aviso C4311, consulte [erros comuns de compilador](http://msdn.microsoft.com/library/windows/desktop/aa384160).  
  
 O exemplo de código a seguir gera C4311 quando compilado para um destino de 64 bits e, em seguida, demonstra como corrigi-lo:  
  
```  
// C4311.cpp  
// compile by using: cl /W1 C4311.cpp  
int main() {  
   void* p = &p;  
   unsigned int i = (unsigned int) p;   // C4311 for 64-bit targets  
   unsigned long long j = (unsigned long long) p;   // OK  
}  
  
```