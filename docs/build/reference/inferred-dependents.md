---
title: Dependentes inferidos
ms.date: 11/04/2016
helpviewer_keywords:
- inferred dependents in NMAKE
- dependents, inferred
ms.assetid: 9303045c-69b3-4f35-bffc-19d5cd6ea3c3
ms.openlocfilehash: 2382dec960ef93fc2f73987ad27b4670768a68cc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62291529"
---
# <a name="inferred-dependents"></a>Dependentes inferidos

Um dependentes inferidos é derivada de uma regra de inferência de tipos e é avaliado antes dependentes explícitas. Se um dependentes inferidos estiver desatualizado com relação ao seu destino, NMAKE invoca o bloco de comandos para a dependência. Se um dependentes inferidos não existe ou está desatualizado em relação a seus próprios dependentes, NMAKE primeiro atualiza os dependentes inferidos. Para obter mais informações sobre dependentes inferidos, consulte [regras de inferência](inference-rules.md).

## <a name="see-also"></a>Consulte também

[Dependentes](dependents.md)
