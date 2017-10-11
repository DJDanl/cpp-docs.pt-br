---
title: C2435 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2435
dev_langs:
- C++
helpviewer_keywords:
- C2435
ms.assetid: be6aa8f8-579b-42ea-bdd8-2d01393646ad
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b70ebf347e2d5b6af8938e348a5e789412241256
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2435"></a>C2435 de erro do compilador
'var': inicialização dinâmica requer CRT gerenciado, não é possível compilar com /CLR: safe  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 A inicialização da variável global de domínio de aplicativo requer CRT compilado com `/clr:pure`, que não produz uma imagem pode ser verificada.  
  
 Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [processo](../../cpp/process.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2435:  
  
```  
// C2435.cpp  
// compile with: /clr:safe /c  
int globalvar = 0;   // C2435  
  
__declspec(process)  
int globalvar2 = 0;  
```
