---
title: C2435 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2435
dev_langs:
- C++
helpviewer_keywords:
- C2435
ms.assetid: be6aa8f8-579b-42ea-bdd8-2d01393646ad
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 44c4dec71cdf077dc8fbd1ba81b555090b524007
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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