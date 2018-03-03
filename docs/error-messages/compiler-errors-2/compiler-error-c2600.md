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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 407598a68df37aa130ce26e4f02e98de975ab527
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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