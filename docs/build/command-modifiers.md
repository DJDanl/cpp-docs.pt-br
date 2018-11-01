---
title: Modificadores de comando
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, command modifiers
- command modifiers
ms.assetid: b661c432-210f-4f05-bc56-744a46e0fc0b
ms.openlocfilehash: a9a79364880cf95adca6066b48f0d786391c8ba0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50431806"
---
# <a name="command-modifiers"></a>Modificadores de comando

Você pode especificar um ou mais modificadores de comando anterior de um comando, opcionalmente, separado por espaços ou tabulações. Assim como acontece com comandos, modificadores devem ser recuados.

|Modificador|Finalidade|
|--------------|-------------|
|\@*Comando*|Impede a exibição do comando. Exibição por comandos não será suprimida. Por padrão, NMAKE ecoa comandos executados tudo. Use /S para suprimir a exibição para o makefile inteira; usar **. SILENCIOSA** para suprimir a exibição para a parte do makefile.|
|**-**\[*número*] *comando*|Desativa a verificação de erros para *comando*. Por padrão, NMAKE é interrompida quando um comando retorna um código de saída diferente de zero. Se -*número* é usado, NMAKE parará se o código de saída excede *número*. Espaços ou tabulações não podem aparecer entre o traço e *número.* Pelo menos um espaço ou tabulação deve aparecer entre `number` e *comando*. Use/i para desativar a verificação de erros para o makefile inteiro; usar **. Ignorar** para desativar a verificação de erros para a parte do makefile.|
|**\!** *command*|Executa *comando* para cada arquivo dependente se *comando* usa <strong>$ \* \*</strong> (todos os arquivos dependentes na dependência) ou **$?** (todos os arquivos dependentes na dependência com um carimbo de hora posterior que o destino.)|

## <a name="see-also"></a>Consulte também

[Comandos em um makefile](../build/commands-in-a-makefile.md)
