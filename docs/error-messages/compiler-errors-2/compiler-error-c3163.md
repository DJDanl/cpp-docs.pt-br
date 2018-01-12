---
title: C3163 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3163
dev_langs: C++
helpviewer_keywords: C3163
ms.assetid: 17dcafa3-f416-4e04-a232-f9569218ba75
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4d3cbb5c5c3e8391b3a549fc0c34661dc86b492c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3163"></a>C3163 de erro do compilador
'Criar': atributos inconsistentes com declaração anterior  
  
 Os atributos que são aplicados a uma definição em conflito com os atributos que são aplicados a uma declaração.  
  
 Uma maneira de resolver C3163 é eliminar atributos na declaração de encaminhamento. Os atributos em uma declaração de encaminhamento devem ser menor do que os atributos na definição de ou, no máximo, igual a eles.  
  
 Uma possível causa do erro C3163 envolve a linguagem de anotação de código de origem Microsoft (SAL). As macros SAL não expandem, a menos que você compilar o projeto usando o **/ANALYZE** sinalizador. Um programa que foi compilado corretamente sem /ANALYZE poderá gerar C3163 se você tentar recompilá-lo com a opção /Analyze. Para obter mais informações sobre SAL, consulte [anotações SAL](../../c-runtime-library/sal-annotations.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3163.  
  
```  
// C3163.cpp  
// compile with: /clr /c  
using namespace System;  
  
[CLSCompliant(true)] void f();  
[CLSCompliant(false)] void f() {}   // C3163  
// try the following line instead  
// [CLSCompliant(true)] void f() {}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Anotações de SAL](../../c-runtime-library/sal-annotations.md)