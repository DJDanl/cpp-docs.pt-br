---
title: 2.6.1 Constructo master
ms.date: 11/04/2016
ms.assetid: c092064b-ea57-4d4e-9c99-a004d65656fe
ms.openlocfilehash: 0501b1fdfbd36829cee2793fc0f7bb03daeda900
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50475524"
---
# <a name="261-master-construct"></a>2.6.1 Constructo master

O **mestre** diretiva identifica uma construção que especifica um bloco estruturado que é executado pelo thread principal da equipe. A sintaxe do **mestre** diretiva é da seguinte maneira:

```
#pragma omp master new-linestructured-block
```

Outros threads da equipe não executem o bloco estruturado associado. Não há nenhum barreira implícita tanto na entrada ou saída da construção de mestre.