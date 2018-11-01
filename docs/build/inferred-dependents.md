---
title: Dependentes inferidos
ms.date: 11/04/2016
helpviewer_keywords:
- inferred dependents in NMAKE
- dependents, inferred
ms.assetid: 9303045c-69b3-4f35-bffc-19d5cd6ea3c3
ms.openlocfilehash: 958a33c29be0d68fee1044fff1d81235ea9370c6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641370"
---
# <a name="inferred-dependents"></a>Dependentes inferidos

Um dependentes inferidos é derivada de uma regra de inferência de tipos e é avaliado antes dependentes explícitas. Se um dependentes inferidos estiver desatualizado com relação ao seu destino, NMAKE invoca o bloco de comandos para a dependência. Se um dependentes inferidos não existe ou está desatualizado em relação a seus próprios dependentes, NMAKE primeiro atualiza os dependentes inferidos. Para obter mais informações sobre dependentes inferidos, consulte [regras de inferência](../build/inference-rules.md).

## <a name="see-also"></a>Consulte também

[Dependentes](../build/dependents.md)