---
title: C2594 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2594
dev_langs: C++
helpviewer_keywords: C2594
ms.assetid: 68cd708f-266e-44b0-a211-3e3ab63b11bf
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a6a73e5202b90a0bc436d93be142162531c6d204
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2594"></a>C2594 de erro do compilador
'operator': conversões ambíguas de 'type1' em 'type2'  
  
 Nenhuma conversão de *type1* para *type2* foi mais direta de qualquer outro. Sugerimos duas soluções possíveis para converter do *type1* para *type2*. A primeira opção é definir uma conversão direta de *type1* para *type2*, e a segunda opção é especificar uma sequência de conversões de *type1* para  *type2*.  
  
 O exemplo a seguir gera C2594. A resolução sugerida para o erro é uma sequência de conversões:  
  
```  
// C2594.cpp  
// compile with: /c  
struct A{};  
struct I1 : A {};  
struct I2 : A {};  
struct D : I1, I2 {};  
  
A *f (D *p) {  
   return (A*) (p);    // C2594  
  
// try the following line instead  
// return static_cast<A *>(static_cast<I1 *>(p));  
}  
```