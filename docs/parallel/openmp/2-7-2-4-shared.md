---
title: 2.7.2.4 compartilhado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c9c5d653-58fc-4620-ab0a-443ac4f8ba2e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9d1a545f1c505f9f578cad682399c8d69a882824
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46400140"
---
# <a name="2724-shared"></a>2.7.2.4 shared

Essa cláusula compartilha as variáveis que aparecem na *lista variável* entre todos os threads em uma equipe. Todos os threads em uma equipe de acessem a área de armazenamento para **compartilhado** variáveis.

A sintaxe do **compartilhado** cláusula é da seguinte maneira:

```
shared(variable-list)
```