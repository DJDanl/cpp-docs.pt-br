---
title: "Compilador aviso (nível 1) C4312 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4312
dev_langs:
- C++
helpviewer_keywords:
- C4312
ms.assetid: 541906ed-4f62-4bcb-947f-cf9ae7411bcb
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ce3c69b4ae87b71a4d5c4d3ec748fb8b47b2a0ab
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4312"></a>Compilador C4312 de aviso (nível 1)
'operation': conversão de 'type1' em 'type2' de tamanho maior  
  
 Esse aviso detecta uma tentativa de atribuir um valor de 32 bits para um tipo de ponteiro de 64 bits, por exemplo, a conversão de 32 bits `int` ou `long` para um ponteiro de 64 bits.  
  
 Isso pode ser uma conversão não segura mesmo para valores de ponteiro que se encaixam em 32 bits quando ocorre de extensão de sinal. Se um inteiro de 32 bits negativo é atribuído a um tipo de ponteiro de 64 bits, extensão de sinal faz com que o valor do ponteiro fazer referência a um endereço de memória diferente do valor do inteiro.  
  
 Esse aviso é emitido apenas para destinos de compilação de 64 bits. Para obter mais informações, consulte [regras para usar ponteiros](http://msdn.microsoft.com/library/windows/desktop/aa384242).  
  
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
