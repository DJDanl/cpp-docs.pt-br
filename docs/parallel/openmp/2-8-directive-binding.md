---
title: 2.8 associação de diretiva | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 7bdac45e-ab55-42f0-bd47-a2e3d5bbab3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dc5b702b17e01bb8d4625a837abdb71086113e68
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46415896"
---
# <a name="28-directive-binding"></a>2.8 Associação de diretiva

Associação dinâmica de diretivas deve cumprir as regras a seguir:

- O **para**, **seções**, **único**, **mestre**, e **barreira** diretivas associar o dinamicamente colocando **paralelas**, se houver, independentemente do valor de qualquer **se** cláusula que pode estar presente nessa diretiva. Se nenhuma região paralela está sendo executada no momento, as diretivas são executadas por uma equipe composta de apenas o thread mestre.

- O **ordenados** diretiva vincula a dinamicamente delimitador **para**.

- O **atômica** diretiva garante o acesso exclusivo com relação ao **atômica** diretivas em todos os threads, não apenas a equipe atual.

- O **críticos** diretiva garante o acesso exclusivo com relação ao **críticos** diretivas em todos os threads, não apenas a equipe atual.

- Uma diretiva nunca pode vincular dinamicamente para qualquer uma das diretivas fora o mais próximo circunscrição **paralela**.