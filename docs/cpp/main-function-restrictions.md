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
ms.openlocfilehash: 981d4c8c0ef30993811e5dbb6fd0a112a6447011
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39406488"
---
# <a name="main-function-restrictions"></a>Restrições da função main
Várias restrições se aplicam para o **principal** função que não se aplicam a quaisquer outras funções do C++. O **principal** função:  
  
-   Não pode ser sobrecarregado (consulte [sobrecarregamento de função](function-overloading.md)).  
  
-   Não pode ser declarado como **embutido**.  
  
-   Não pode ser declarado como **estático**.  
  
-   Não pode ter seu endereço removido.  
  
-   Não pode ser chamada.  
  
## <a name="see-also"></a>Consulte também  
 [main: inicialização do programa](../cpp/main-program-startup.md)