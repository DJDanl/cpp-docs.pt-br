---
title: Vantagens do assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- assembler [C++], advantages
- inline assembly [C++], about inline assembly
- inline assembly [C++], using
ms.assetid: 94364d97-faa7-4bdf-8473-570956986c51
ms.openlocfilehash: ecf1598ec90a8600e1fa9aae565724c254dc11e6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50556732"
---
# <a name="advantages-of-inline-assembly"></a>Vantagens do assembly embutido

**Seção específica da Microsoft**

Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. O código do assembly integrado pode usar qualquer nome de variável ou de função C que esteja no escopo. Portanto, ele é de fácil integração com código C do programa. Porque o código do assembly pode ser mesclado embutido com instruções C ou C++, ele pode realizar tarefas que são incômodas ou impossíveis em C ou C++.

Os usos de assembly embutido incluem:

- Escrevendo funções na linguagem assembly.

- Otimizando o ponto a seções críticas de velocidade do código.

- Tornando o acesso direto de hardware para drivers de dispositivo.

- Escrevendo código de prólogo e epílogo para chamadas de "naked".

Assembly embutido é uma ferramenta de finalidade especial. Se você planeja transferir um aplicativo em computadores diferentes, provavelmente você desejará colocar código específicas do computador em um módulo separado. Como o assembler embutido não dá suporte a todos os do Microsoft Macro Assembler (MASM) diretivas de macro e dados, talvez seja mais conveniente usar MASM para esses módulos.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>