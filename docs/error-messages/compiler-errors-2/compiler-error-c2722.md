---
title: C2722 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2722
dev_langs:
- C++
helpviewer_keywords:
- C2722
ms.assetid: 4cc2c7fa-cb12-4bcf-9df1-6d627ef62973
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c2db3d8ac30d51e04d425bd27e9d9d5c12e62931
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2722"></a>C2722 de erro do compilador
':: operador ': inválido após comando operator; Use 'operator operador'  
  
 Um `operator` redefinições de instrução `::new` ou `::delete`. O `new` e `delete` operadores são globais, portanto, o operador de resolução do escopo (`::`) não tem sentido. Remover o `::` operador.
