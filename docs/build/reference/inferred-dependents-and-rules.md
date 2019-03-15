---
title: Dependentes inferidos e regras
ms.date: 11/04/2016
helpviewer_keywords:
- rules, inferred
- inferred dependents in NMAKE
- inferred rules in NMAKE
- dependents, inferred
ms.assetid: 9381e74a-53d9-445c-836d-0ff7ef6112d9
ms.openlocfilehash: b9c3055db0cc173999e1737986166eb334dcf96c
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824350"
---
# <a name="inferred-dependents-and-rules"></a>Dependentes inferidos e regras

NMAKE pressupõe um dependente inferido para um destino se existe uma regra de inferência de tipos aplicáveis. Uma regra se aplica se:

- *toext* corresponde à extensão de destino.

- *fromext* correspondências a extensão de um arquivo que tem o nome do destino base e que existe no diretório atual ou especificado.

- *fromext* está em [. SUFIXOS](dot-directives.md); nenhuma outra *fromext* em uma regra de correspondência tem uma maior **. SUFIXOS** prioridade.

- Nenhum dependente explícita tem uma maior **. SUFIXOS** prioridade.

Dependentes inferidos podem causar efeitos colaterais inesperados. Se o bloco de descrição do destino contém comandos, NMAKE executa esses comandos em vez de comandos na regra.

## <a name="see-also"></a>Consulte também

[Regras de inferência](inference-rules.md)
