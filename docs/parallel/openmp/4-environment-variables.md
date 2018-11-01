---
title: 4. Variáveis de ambiente
ms.date: 11/04/2016
ms.assetid: 4ec7ed81-e9ca-46a1-84f8-8f9ce4587346
ms.openlocfilehash: 0dec302762ad22fc3c7f6691ef63df1b07d5940d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456596"
---
# <a name="4-environment-variables"></a>4. Variáveis de ambiente

Este capítulo descreve as variáveis de ambiente OpenMP C e C++ API (ou equivalentes mecanismos de específico da plataforma) que controlam a execução do código paralelo.  Os nomes das variáveis de ambiente devem ser maiusculos. Os valores atribuídos a eles diferenciam maiusculas de minúsculas e podem ter espaços em branco à esquerda e à direita.  Modificações aos valores depois que o programa foi iniciado são ignoradas.

As variáveis de ambiente são da seguinte maneira:

- **OMP_SCHEDULE** define o tamanho de bloco e de tipo de agendamento de tempo de execução.

- **OMP_NUM_THREADS** define o número de threads a serem usados durante a execução.

- **OMP_DYNAMIC** ativa ou desativa o ajuste dinâmico do número de threads.

- **OMP_NESTED** habilita ou desabilita o paralelismo aninhado.

Os exemplos neste capítulo somente demonstram como essas variáveis podem ser definidas em ambientes de shell (csh) de C do Unix. No Korn shell e ambientes das ações são semelhantes, da seguinte maneira:

csh: setenv OMP_SCHEDULE "dinâmica"

ksh: exportar OMP_SCHEDULE = "dynamic"

DOS: definir OMP_SCHEDULE = "dynamic"