---
title: Vantagens do assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- assembler [C++], advantages
- inline assembly [C++], about inline assembly
- inline assembly [C++], using
ms.assetid: 94364d97-faa7-4bdf-8473-570956986c51
ms.openlocfilehash: 7e634f78eca753487cf122ac95df55828bb64625
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169650"
---
# <a name="advantages-of-inline-assembly"></a>Vantagens do assembly embutido

**Seção específica da Microsoft**

Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. O código do assembly integrado pode usar qualquer nome de variável ou de função C que esteja no escopo. Portanto, ele é de fácil integração com código C do programa. Como o código do assembly pode ser combinado embutido com C++ instruções C ou, ele pode executar tarefas que são complicadas ou impossíveis em C ou C++.

Os usos do assembly embutido incluem:

- Gravando funções na linguagem do assembly.

- A otimização de cores de seções críticas de velocidade de código.

- Fazendo o acesso direto ao hardware para drivers de dispositivo.

- Escrever o prólogo e o código epílogo para chamadas "Naked".

O assembly embutido é uma ferramenta de finalidade especial. Se você planeja portar um aplicativo para computadores diferentes, provavelmente desejará colocar o código específico do computador em um módulo separado. Como o Assembler embutido não dá suporte a todas as diretivas de macro e de dados do Microsoft Macro Assembler (MASM), você pode achar mais conveniente usar o MASM para esses módulos.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
