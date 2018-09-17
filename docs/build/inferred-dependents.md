---
title: Dependentes inferidos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inferred dependents in NMAKE
- dependents, inferred
ms.assetid: 9303045c-69b3-4f35-bffc-19d5cd6ea3c3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 631c5631b60f0e05dd1f1541facc767f35944d3d
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45701474"
---
# <a name="inferred-dependents"></a>Dependentes inferidos

Um dependentes inferidos é derivada de uma regra de inferência de tipos e é avaliado antes dependentes explícitas. Se um dependentes inferidos estiver desatualizado com relação ao seu destino, NMAKE invoca o bloco de comandos para a dependência. Se um dependentes inferidos não existe ou está desatualizado em relação a seus próprios dependentes, NMAKE primeiro atualiza os dependentes inferidos. Para obter mais informações sobre dependentes inferidos, consulte [regras de inferência](../build/inference-rules.md).

## <a name="see-also"></a>Consulte também

[Dependentes](../build/dependents.md)