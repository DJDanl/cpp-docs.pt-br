---
title: 2.7.2.4 compartilhado | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: c9c5d653-58fc-4620-ab0a-443ac4f8ba2e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4320a3df64d8056cf1c8657acc78281f56cd1c85
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="2724-shared"></a>2.7.2.4 shared
Essa cláusula compartilha variáveis que aparecem no *lista variável* entre todos os threads em uma equipe. Área de armazenamento para acesso a todos os threads em uma equipe **compartilhado** variáveis.  
  
 A sintaxe do **compartilhado** cláusula é o seguinte:  
  
```  
shared(variable-list)  
```