---
title: "Compilador aviso (nível 3) C4636 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4636
dev_langs: C++
helpviewer_keywords: C4636
ms.assetid: 59112a0f-850f-41c6-bd84-8ae8dc84706a
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e5433688fee855654e29715ceffa4af432e2c30a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4636"></a>Compilador C4636 de aviso (nível 3)
Comentário de documento XML aplicado para 'Criar': marca requer não vazia ' atributo.  
  
 A marca, como `cref`, não tinha um valor.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4636.  
  
```  
// C4636.cpp  
// compile with: /clr /doc /W3 /c  
/// <see cref=''/>  
// /// <see cref='System::Exception'/>  
ref struct A {   // C4636  
   void f(int);  
};  
  
// OK  
/// <see cref='System::Exception'/>  
ref struct B {  
   void f(int);  
};  
```