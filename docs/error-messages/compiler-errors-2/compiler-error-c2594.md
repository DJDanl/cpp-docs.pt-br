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
ms.workload: cplusplus
ms.openlocfilehash: d4cca18672aad77e051ff4428dc115c53cd5ddad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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