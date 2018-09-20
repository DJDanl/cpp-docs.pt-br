---
title: 2.6.1 constructo de mestre | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c092064b-ea57-4d4e-9c99-a004d65656fe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8d82ae673e428c635172f35f9b0f682aa65dc2b8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46445627"
---
# <a name="261-master-construct"></a>2.6.1 Constructo master

O **mestre** diretiva identifica uma construção que especifica um bloco estruturado que é executado pelo thread principal da equipe. A sintaxe do **mestre** diretiva é da seguinte maneira:

```
#pragma omp master new-linestructured-block
```

Outros threads da equipe não executem o bloco estruturado associado. Não há nenhum barreira implícita tanto na entrada ou saída da construção de mestre.