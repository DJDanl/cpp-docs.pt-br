---
title: Regras de inferência | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inference rules in NMAKE
- rules, inference
- NMAKE program, inference rules
ms.assetid: caff320f-fb07-4eea-80c3-a6a2133a8492
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed45e5ad61ea1cc50172cd86716b357baa64fa39
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45724371"
---
# <a name="inference-rules"></a>Regras de inferência

Regras de inferência de fornecem comandos para atualizar destinos e inferir dependentes para destinos. Extensões em uma regra de inferência de tipos correspondem a um único destino e dependente que têm o mesmo nome base. Regras de inferência são definidos pelo usuário ou predefinidas; regras predefinidas podem ser redefinidas.

Se uma dependência desatualizada não tiver nenhum comando e se [. SUFIXOS](../build/dot-directives.md) contém a extensão do dependente, usos NMAKE uma regra cujas extensões correspondem a um existente e o destino de arquivo no diretório atual ou especificado. Se mais de uma regra corresponde a arquivos existentes, o **. SUFIXOS** lista determina qual deles usar; desce de prioridade de lista da esquerda para a direita. Se um arquivo dependente não existe e não estiver listado como um destino em outro bloco de descrição, uma regra de inferência de tipos pode criar o ausente dependente de outro arquivo com o mesmo nome de base. Se o destino de um bloco descrição não tiver dependentes ou comandos, uma regra de inferência de tipos pode atualizar o destino. Regras de inferência podem criar um destino de linha de comando, mesmo se não existe nenhum bloco de descrição. NMAKE pode invocar uma regra para um dependentes inferidos, mesmo se um dependente explícita for especificada.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Definindo uma regra](../build/defining-a-rule.md)

[Regras de modo de lote](../build/batch-mode-rules.md)

[Regras predefinidas](../build/predefined-rules.md)

[Dependentes inferidos e regras](../build/inferred-dependents-and-rules.md)

[Precedência em regras de inferência](../build/precedence-in-inference-rules.md)

## <a name="see-also"></a>Consulte também

[Referência a NMAKE](../build/nmake-reference.md)