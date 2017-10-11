---
title: C2600 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2600
dev_langs:
- C++
helpviewer_keywords:
- C2600
ms.assetid: cce11943-ea01-4bee-a7b0-b67d24ec6493
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 1fe5383e17212b21c11394c6b987e92aacbe637e
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2600"></a>C2600 de erro do compilador
"função": não é possível definir uma função de membro especial gerado pelo compilador (deve ser declarado primeiro na classe)  
  
 Antes de funções de membro, como construtores ou destruidores, podem ser definidas para uma classe, devem ser declaradas na classe. O compilador pode gerar construtores e destruidores padrão (chamados de funções de membro especiais) se nenhum for declarado na classe. No entanto, se você definir uma dessas funções sem uma declaração correspondente na classe, o compilador detecta um conflito.  
  
 Para corrigir esse erro, na declaração da classe, declare cada função de membro definida por você fora da declaração de classe.  
  
 O seguinte exemplo gera C2600:  
  
```  
// C2600.cpp  
// compile with: /c  
class C {};  
C::~C() {}   // C2600  
  
class D {  
   D::~D();  
};  
  
D::~D() {}  
```
