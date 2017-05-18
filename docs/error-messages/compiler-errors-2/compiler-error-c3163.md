---
title: C3163 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3163
dev_langs:
- C++
helpviewer_keywords:
- C3163
ms.assetid: 17dcafa3-f416-4e04-a232-f9569218ba75
caps.latest.revision: 8
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
ms.openlocfilehash: 310e67b1e1dbeb58554c9630faed4d60ba5690e1
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3163"></a>C3163 de erro do compilador
'Criar': atributos inconsistentes com a declaração anterior  
  
 Os atributos que são aplicados a uma definição em conflito com os atributos que são aplicados a uma declaração.  
  
 Uma maneira de resolver C3163 é eliminar atributos na declaração de encaminhamento. Os atributos em uma declaração de encaminhamento devem ser menor do que os atributos na definição ou, no máximo, igual a eles.  
  
 Uma possível causa do erro C3163 envolve a linguagem de anotação do código Microsoft fonte (SAL). As macros SAL não expandir, a menos que você compila seu projeto usando o **/ANALYZE** sinalizador. Um programa que foi compilado corretamente sem /ANALYZE poderá gerar C3163 se você tentar recompilá-lo com a opção /Analyze. Para obter mais informações sobre o SAL, consulte [anotações de SAL](../../c-runtime-library/sal-annotations.md).  
  
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
