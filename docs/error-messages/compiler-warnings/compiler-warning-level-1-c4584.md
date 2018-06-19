---
title: Compilador (nível 1) de aviso C4584 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4584
dev_langs:
- C++
helpviewer_keywords:
- C4584
ms.assetid: ad86582f-cb8c-4d21-8c4c-a6c800059e25
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: df3f92142fe42451ca7ae8272463d9347a263121
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33281158"
---
# <a name="compiler-warning-level-1-c4584"></a>Compilador C4584 de aviso (nível 1)
'class1': classe base 'class2' já é uma classe base de 'class3'  
  
 A classe que você definiu herda de duas classes, uma que herda de outra. Por exemplo:  
  
```  
// C4584.cpp  
// compile with: /W1 /LD  
class A {  
};  
  
class B : public A {  
};  
  
class C : public A, public B { // C4584  
};  
```  
  
 Nesse caso, um aviso será emitido na classe C porque ele herda da classe e a classe B, que também herda da classe A. Esse aviso serve como um lembrete de que você deve qualificar totalmente o uso de membros dessas classes base ou será gerado um erro do compilador devido à ambiguidade sobre qual membro de classe que você consulte.