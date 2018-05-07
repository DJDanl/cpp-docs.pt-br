---
title: C2588 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2588
dev_langs:
- C++
helpviewer_keywords:
- C2588
ms.assetid: 19a0cabd-ca13-44a5-9be3-ee676abf9bc4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 67eb6362ff55e09b05349d10fcdc2377d8ff2996
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2588"></a>C2588 de erro do compilador
':: ~ identificador ': destruidor global inválido  
  
 O destruidor é definido para algo diferente de uma classe, estrutura ou união. Isso não é permitido.  
  
 Esse erro pode ser causado por uma classe ausente, a estrutura ou o nome de união no lado esquerdo da resolução de escopo (`::`) operador.  
  
 O exemplo a seguir gera C2588:  
  
```  
// C2588.cpp  
~F();   // C2588  
```