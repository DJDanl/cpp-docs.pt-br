---
title: C2588 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2588
dev_langs:
- C++
helpviewer_keywords:
- C2588
ms.assetid: 19a0cabd-ca13-44a5-9be3-ee676abf9bc4
caps.latest.revision: 6
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
ms.openlocfilehash: fb584343099adf3edb8463bfac75a0d1a5ab2943
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2588"></a>C2588 de erro do compilador
':: ~ identificador ': destruidor global ilegal  
  
 O destruidor é definido para algo diferente de uma classe, estrutura ou união. Isso não é permitido.  
  
 Esse erro pode ser causado por uma classe ausente, estrutura ou união nome no lado esquerdo da resolução de escopo (`::`) operador.  
  
 O exemplo a seguir gera C2588:  
  
```  
// C2588.cpp  
~F();   // C2588  
```
