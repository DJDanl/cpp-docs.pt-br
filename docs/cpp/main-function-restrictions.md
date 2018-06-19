---
title: Restrições da função Main | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- Main
dev_langs:
- C++
helpviewer_keywords:
- main function, restrictions on using
ms.assetid: 7b3df731-344b-44a8-850c-11cbcbfbfa83
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ed5be2df6e152b26bcade1970b35ad33655e8e02
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32419665"
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