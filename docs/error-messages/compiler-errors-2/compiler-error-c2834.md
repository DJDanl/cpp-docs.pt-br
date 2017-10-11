---
title: C2834 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2834
dev_langs:
- C++
helpviewer_keywords:
- C2834
ms.assetid: 28f9f6eb-ab2a-4e64-aaaa-9d14f955de41
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5b85b01fa832b0d14d01b6b7cbb5ef65107177ef
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2834"></a>C2834 de erro do compilador
'operador operator' deve ser qualificado globalmente  
  
 O `new` e `delete` operadores são associados à classe onde elas residam. Resolução do escopo não pode ser usada para selecionar uma versão de `new` ou `delete` de uma classe diferente. Para implementar várias formas da `new` ou `delete` operador, crie uma versão do operador com parâmetros formais extra.
