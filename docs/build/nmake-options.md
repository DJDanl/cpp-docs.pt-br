---
title: "Opções de NMAKE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, options
ms.assetid: 00ba1aec-ef27-44cf-8d82-c5c095e45bae
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8ef3b987de737d8300f88690754456b73c946180
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-options"></a>Opções de NMAKE
Opções de NMAKE são descritas na tabela a seguir. Opções são precedidas por uma barra (/) ou um traço (-) e não diferenciam maiusculas de minúsculas. Use [! CMDSWITCHES](../build/makefile-preprocessing-directives.md) para alterar as configurações de opção em um makefile ou em Tools.ini.  
  
|Opção|Finalidade|  
|------------|-------------|  
|/A|Compilação de força de todos os destinos avaliadas, mesmo se não desatualizadas em relação a seus dependentes. Não force a compilação de destinos não relacionados.|  
|/ B|Força compilação mesmo que os carimbos de hora são iguais. Recomendado apenas para sistemas muito rápida (resolução de dois segundos ou menos).|  
|/C|Suprime o padrão de saída, incluindo erros NMAKE não fatais ou avisos, os carimbos de hora e mensagem de direitos autorais NMAKE. Suprime avisos emitidos pelo /K.|  
|/D|Exibe os carimbos de hora de cada avaliado destino e dependente e uma mensagem quando um destino não existe. Útil com/p para depurar um makefile. Use **! CMDSWITCHES** para definir ou limpar /D para parte de um makefile.|  
|/E|Faz com que as variáveis de ambiente substituir as definições de macro makefile.|  
|/ERRORREPORT [NENHUM &#124; PROMPT &#124; FILA &#124; ENVIO]|Se nmake.exe falhar em tempo de execução, você pode usar /ERRORREPORT para enviar à Microsoft informações sobre esses erros internos.<br /><br /> Para obter mais informações sobre /ERRORREPORT, consulte [/errorReport (relatório de erros do compilador interno)](../build/reference/errorreport-report-internal-compiler-errors.md).|  
|/F`filename`|Especifica `filename` como um makefile. Tabulações ou espaços podem preceder `filename`. Especifique /F uma vez para cada makefile. Para fornecer um makefile da entrada padrão, especifique um traço (-) para `filename`e terminar a entrada do teclado com F6 ou CTRL + Z.|  
|/G|Exibe os makefiles incluídos com o! Diretiva INCLUDE.  Consulte [diretivas de pré-processamento de Makefile](../build/makefile-preprocessing-directives.md) para obter mais informações.|  
|/ AJUDAR, /?|Exibe um resumo da sintaxe de linha de comando NMAKE.|  
|/I|Ignora códigos de saída de todos os comandos. Para definir ou limpar/i para parte de um makefile, use **! CMDSWITCHES**. Para ignorar os códigos de saída para a parte de um makefile, use o modificador de comando um traço (-) ou [. Ignorar](../build/dot-directives.md). Substitui /K se ambos estiverem especificados.|  
|/K|Continuará a criar dependências relacionadas, se um comando retornará um erro. Também emite um aviso e retorna um código de saída de 1. Por padrão, NMAKE é interrompida se qualquer comando retorna um código de saída diferente de zero. Avisos de /K são suprimidos pela c; /I substitui /K se ambos estiverem especificados.|  
|/N|Exibe, mas não executar os comandos; comandos de pré-processamento são executados. Não exibe os comandos em chamadas NMAKE recursiva. É útil para depuração makefiles e verificando os carimbos de hora. Para definir ou limpar /N para parte de um makefile, use **! CMDSWITCHES**.|  
|/NOLOGO|Suprime a mensagem de direitos autorais NMAKE.|  
|/P|Exibe informações (definições de macro, regras de inferência, destinos, [. SUFIXOS](../build/dot-directives.md) lista) para a saída padrão, e, em seguida, executa a compilação. Se não existe nenhum makefile ou o destino de linha de comando, ele exibe informações somente. Use com /D para depurar um makefile.|  
|/Q|Carimbos de hora de verificações de destinos; não executar a compilação. Retorna um código de saída zero se todos os destinos são atualizados e um código de saída diferente de zero se qualquer destino não é. Comandos de pré-processamento são executados. Útil quando executando NMAKE de um arquivo em lotes.|  
|/R|Limpa o **. SUFIXOS** Liste e ignora as regras de inferência e macros que são definidos no arquivo Tools.ini ou que são predefinidas.|  
|/S|Suprime a exibição de comandos executados. Para suprimir a exibição em parte de um makefile, use o  **@**  modificador de comando ou [. SILENCIOSA](../build/dot-directives.md). Para definir ou limpar /S para parte de um makefile, use **! CMDSWITCHES**.|  
|/T|Atualiza os carimbos de hora de destinos de linha de comando (ou primeiro makefile destino) e executa os comandos de pré-processamento, mas não executar a compilação.|  
|/U|Deve ser usado em conjunto com /N. Despeja arquivos NMAKE embutido para que a saída /N pode ser usada como um arquivo em lotes.|  
|/X`filename`|Envia a saída de erro NMAKE para `filename` em vez de erro padrão. Tabulações ou espaços podem preceder `filename`. Para enviar a saída de erro para a saída padrão, especifique um traço (-) para `filename`. Não afeta a saída de comandos para o erro padrão.|  
|/Y|Desabilita as regras de inferência de modo de lote. Quando essa opção é selecionada, todas as regras de inferência de modo de lote são tratadas como regras de inferência regular.|  
  
## <a name="see-also"></a>Consulte também  
 [Executando NMAKE](../build/running-nmake.md)