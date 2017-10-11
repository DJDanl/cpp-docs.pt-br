---
title: "Restrições da função Main | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- Main
dev_langs:
- C++
helpviewer_keywords:
- main function, restrictions on using
ms.assetid: 7b3df731-344b-44a8-850c-11cbcbfbfa83
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 10fe82b0bb7ad700164b05ba466854db7716ba76
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="main-function-restrictions"></a>Restrições da função main
Várias restrições se aplicam ao **principal** função que não se aplicam a outras funções de C++. O **principal** função:  
  
-   Não pode ser sobrecarregado (consulte [sobrecarga de função](function-overloading.md)).  
  
-   Não pode ser declarado como **embutido**.  
  
-   Não pode ser declarado como **estático**.  
  
-   Não pode ter seu endereço removido.  
  
-   Não pode ser chamada.  
  
## <a name="see-also"></a>Consulte também  
 [main: inicialização do programa](../cpp/main-program-startup.md)
