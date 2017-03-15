---
title: C2600 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 76494452dbf2d32fc1ff810bb58e059116bc4e3a
ms.lasthandoff: 02/25/2017

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
