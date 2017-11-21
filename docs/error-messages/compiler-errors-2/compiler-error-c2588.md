---
title: C2588 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2588
dev_langs: C++
helpviewer_keywords: C2588
ms.assetid: 19a0cabd-ca13-44a5-9be3-ee676abf9bc4
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c6d71e5bfe442f2b3f2225cd4dc6cb88fc73d24a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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