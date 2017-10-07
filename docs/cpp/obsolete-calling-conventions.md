---
title: "Convenções de chamada obsoletas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __fortran
- __pascal
- __syscall
dev_langs:
- C++
helpviewer_keywords:
- WINAPI [C++]
- __syscall keyword [C++]
- __pascal keyword [C++]
- __fortran keyword [C++]
- calling conventions, obsolete
ms.assetid: a91fc665-034a-48ce-b6bd-d27125f308a7
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 90f328552677bc0f41accc316433365467dd7673
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="obsolete-calling-conventions"></a>Convenções de chamada obsoletas
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O **Pascal**, **Fortran**, e **syscall** convenções de chamada não têm mais suporte. Você pode emular a funcionalidade delas usando uma das convenções de chamada com suporte e as opções do vinculador apropriadas.  
  
 WINDOWS. H agora dá suporte ao **WINAPI** macro, que pode ser convertido para a convenção de chamada apropriada para o destino. Use **WINAPI** em que você usou anteriormente **PASCAL** ou **__far \__pascal**.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)
