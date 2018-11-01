---
title: 2.8 Associação de diretiva
ms.date: 11/04/2016
ms.assetid: 7bdac45e-ab55-42f0-bd47-a2e3d5bbab3e
ms.openlocfilehash: fb22d1b503303842ff73550c1c6544cae7e5f2f3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50528606"
---
# <a name="28-directive-binding"></a>2.8 Associação de diretiva

Associação dinâmica de diretivas deve cumprir as regras a seguir:

- O **para**, **seções**, **único**, **mestre**, e **barreira** diretivas associar o dinamicamente colocando **paralelas**, se houver, independentemente do valor de qualquer **se** cláusula que pode estar presente nessa diretiva. Se nenhuma região paralela está sendo executada no momento, as diretivas são executadas por uma equipe composta de apenas o thread mestre.

- O **ordenados** diretiva vincula a dinamicamente delimitador **para**.

- O **atômica** diretiva garante o acesso exclusivo com relação ao **atômica** diretivas em todos os threads, não apenas a equipe atual.

- O **críticos** diretiva garante o acesso exclusivo com relação ao **críticos** diretivas em todos os threads, não apenas a equipe atual.

- Uma diretiva nunca pode vincular dinamicamente para qualquer uma das diretivas fora o mais próximo circunscrição **paralela**.