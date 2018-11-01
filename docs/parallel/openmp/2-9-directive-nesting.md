---
title: 2.9 Aninhamento de diretiva
ms.date: 11/04/2016
ms.assetid: 6565a43c-fd2d-4366-8322-8d75e1b06600
ms.openlocfilehash: 804cafd65fde19e501b89c47925f471143d74938
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50438721"
---
# <a name="29-directive-nesting"></a>2.9 Aninhamento de diretiva

Aninhamento dinâmico das diretivas deve cumprir as regras a seguir:

- Um **paralelas** diretiva dinamicamente dentro de outra **paralela** logicamente estabelece uma nova equipe é composta de apenas o thread atual, exceto se aninhados paralelismo está habilitada.

- **para**, **seções**, e **único** diretivas que se associam à mesma **paralela** não podem ser aninhados dentro uns aos outros.

- **crítico** diretivas com o mesmo nome não podem ser aninhados dentro uns aos outros. Observe que essa restrição não é suficiente para evitar o deadlock.

- **para**, **seções**, e **único** diretivas não são permitidas na extensão de dinâmico **críticos**, **ordenados**, e **mestre** regiões se as diretivas que se associar à mesma **paralela** como as regiões.

- **barreira** diretivas não são permitidas na extensão de dinâmico **para**, **ordenados**, **seções**, **único**, **mestre**, e **críticos** regiões se as diretivas que se associar à mesma **paralela** como as regiões.

- **mestre** diretivas não são permitidas na extensão de dinâmico **para**, **seções**, e **único** diretivas se o **mestre** diretivas associar à mesma **paralela** como as diretivas de compartilhamento de trabalho.

- **ordenados** diretivas não são permitidas na extensão de dinâmico **críticos** regiões se as diretivas que se associar ao mesmo **paralela** como as regiões.

- Qualquer uma das diretivas que é permitida quando executado dinamicamente dentro de uma região parallel também é permitida quando executado fora de uma região paralela. Quando executado dinamicamente fora de uma região paralela especificada pelo usuário, a diretiva é executada por uma equipe composta de apenas o thread mestre.