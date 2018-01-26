---
title: "Convenções de chamada obsoletas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __fortran
- __pascal
- __syscall
dev_langs: C++
helpviewer_keywords:
- WINAPI [C++]
- __syscall keyword [C++]
- __pascal keyword [C++]
- __fortran keyword [C++]
- calling conventions, obsolete
ms.assetid: a91fc665-034a-48ce-b6bd-d27125f308a7
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ad065eb3f35080ff2e5743c0259b20ba72ee6175
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="obsolete-calling-conventions"></a>Convenções de chamada obsoletas
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O **Pascal**, **Fortran**, e **syscall** convenções de chamada não têm mais suporte. Você pode emular a funcionalidade delas usando uma das convenções de chamada com suporte e as opções do vinculador apropriadas.  
  
 \<Windows. h > agora oferece suporte a **WINAPI** macro, que pode ser convertido para a convenção de chamada apropriada para o destino. Use **WINAPI** em que você usou anteriormente **PASCAL** ou **__far \__pascal**.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)