---
title: "Restrições da função Main | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: Main
dev_langs: C++
helpviewer_keywords: main function, restrictions on using
ms.assetid: 7b3df731-344b-44a8-850c-11cbcbfbfa83
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8a94844a0d5636c58a764114ed6f413923d69950
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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