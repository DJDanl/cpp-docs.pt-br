---
title: Regras de inferência
ms.date: 11/04/2016
helpviewer_keywords:
- inference rules in NMAKE
- rules, inference
- NMAKE program, inference rules
ms.assetid: caff320f-fb07-4eea-80c3-a6a2133a8492
ms.openlocfilehash: d3d7ca41d96d3845237b445edefff05044dacdc2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170508"
---
# <a name="inference-rules"></a>Regras de inferência

As regras de inferência fornecem comandos para atualizar os destinos e inferir os dependentes de destinos. As extensões em uma regra de inferência correspondem a um único destino e dependentes que têm o mesmo nome base. As regras de inferência são definidas pelo usuário ou predefinidas; regras predefinidas podem ser redefinidas.

Se uma dependência desatualizada não tiver nenhum comando, e se [. Os sufixos](dot-directives.md) contêm a extensão dependente, o NMAKE usa uma regra cujas extensões correspondem ao destino e a um arquivo existente no diretório atual ou especificado. Se mais de uma regra corresponder aos arquivos existentes, o **. A lista de sufixos** determina qual deve ser usada; a prioridade da lista descende da esquerda para a direita. Se um arquivo dependente não existir e não estiver listado como um destino em outro bloco de descrição, uma regra de inferência poderá criar o dependente ausente de outro arquivo com o mesmo nome base. Se o destino de um bloco de descrição não tiver nenhum dependente ou comando, uma regra de inferência poderá atualizar o destino. As regras de inferência podem criar um destino de linha de comando mesmo se não existir nenhum bloco de descrição. NMAKE pode invocar uma regra para um dependente inferido mesmo se um dependente explícito for especificado.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Definindo uma regra](defining-a-rule.md)

[Regras de modo de lote](batch-mode-rules.md)

[Regras predefinidas](predefined-rules.md)

[Regras e dependentes inferidos](inferred-dependents-and-rules.md)

[Precedência em regras de inferência](precedence-in-inference-rules.md)

## <a name="see-also"></a>Confira também

[Referência a NMAKE](nmake-reference.md)
