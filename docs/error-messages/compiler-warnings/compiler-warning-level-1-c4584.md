---
title: "Compilador (nível 1) de aviso C4584 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4584
dev_langs: C++
helpviewer_keywords: C4584
ms.assetid: ad86582f-cb8c-4d21-8c4c-a6c800059e25
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ba427de26d07851c5bf2a2dd3f599c4cbe7afc5c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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