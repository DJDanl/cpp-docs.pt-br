---
title: Modificadores de comando | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, command modifiers
- command modifiers
ms.assetid: b661c432-210f-4f05-bc56-744a46e0fc0b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3739c053797bdccd08310e17bf669413ead0db48
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="command-modifiers"></a>Modificadores de comando
Você pode especificar um ou mais modificadores de comando anterior de um comando, opcionalmente, separado por tabulações ou espaços. Assim como acontece com comandos, modificadores devem ser recuados.  
  
|Modificador|Finalidade|  
|--------------|-------------|  
|@*Comando*|Impede a exibição do comando. Exibição por comandos não será suprimida. Por padrão, NMAKE exibe executar todos os comandos. Use /S para suprimir a exibição para o makefile inteiro; Use **. SILENCIOSA** para suprimir a exibição para a parte do makefile.|  
|**-**[`number` ]*comando*|Desativa a verificação de erros de *comando*. Por padrão, NMAKE é interrompida quando um comando retorna um código de saída diferente de zero. Se -`number` é usado, NMAKE para de se o código de saída exceder `number`. Tabulações ou espaços não podem aparecer entre o traço e *número.* Pelo menos um espaço ou tabulação deve aparecer entre `number` e *comando*. Use/i para desativar a verificação de erros para o makefile inteiro; Use **. Ignorar** para desativar a verificação de erros para a parte do makefile.|  
|**!** *command*|Executa *comando* para cada arquivo dependente se *comando* usa **$ \* \*** (todos os arquivos dependentes na dependência) ou **$?** (todos os arquivos dependentes em dependência com um carimbo de hora posterior que o destino.)|  
  
## <a name="see-also"></a>Consulte também  
 [Comandos em um makefile](../build/commands-in-a-makefile.md)