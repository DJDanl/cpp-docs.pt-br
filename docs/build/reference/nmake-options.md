---
title: Opções de NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, options
ms.assetid: 00ba1aec-ef27-44cf-8d82-c5c095e45bae
ms.openlocfilehash: c60b6d821d8e16e87f86e3b79825aa1dee7867c8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320533"
---
# <a name="nmake-options"></a>Opções de NMAKE

Opções de NMAKE são descritas na tabela a seguir. As opções são precedidas por uma barra (/) ou um traço (-) e não diferenciam maiusculas de minúsculas. Use [! CMDSWITCHES](makefile-preprocessing-directives.md) para alterar as configurações de opção em um makefile ou em Tools. ini.

|Opção|Finalidade|
|------------|-------------|
|/A|Compilação de forças de todos os destinos avaliados, mesmo se não desatualizadas em relação a seus dependentes. Não força a compilação de destinos não relacionados.|
|/B|Força compilar mesmo que os carimbos de hora são iguais. Recomendado somente para sistemas muito rápidos (resolução de dois segundos ou menos).|
|/C|Suprime o padrão de saída, incluindo avisos ou erros não fatais de NMAKE, carimbos de hora e mensagem de direitos autorais de NMAKE. Suprime os avisos emitidos pelo /K.|
|/D|Exibe os carimbos de hora de cada avaliada destino e dependente e uma mensagem quando um destino não existe. Útil com/p para depurar um makefile. Use **! CMDSWITCHES** para definir ou limpar /D para parte de um makefile.|
|/E|Faz com que as variáveis de ambiente substituir as definições de macro de makefile.|
|/ERRORREPORT[NONE &#124; PROMPT &#124; QUEUE &#124; SEND ]|Se nmake.exe falhar em tempo de execução, você pode usar /ERRORREPORT para enviar à Microsoft informações sobre esses erros internos.<br /><br /> Para obter mais informações sobre /ERRORREPORT, consulte [/errorReport (relatório de erros do compilador interno)](errorreport-report-internal-compiler-errors.md).|
|/F *filename*|Especifica *filename* como um makefile. Espaços ou tabulações podem preceder *filename*. Especifica /F uma vez para cada makefile. Para fornecer um makefile da entrada padrão, especifique um traço (-) para *filename*e terminar a entrada de teclado com F6 ou CTRL + Z.|
|/G|Exibe os makefiles incluídos com o! Diretiva INCLUDE.  Ver [diretivas de pré-processamento de Makefile](makefile-preprocessing-directives.md) para obter mais informações.|
|/HELP, /?|Exibe um resumo da sintaxe de linha de comando NMAKE.|
|/I|Ignora códigos de saída de todos os comandos. Para definir ou limpar/i para parte de um makefile, use **! CMDSWITCHES**. Para ignorar os códigos de saída para a parte de um makefile, use um modificador de comando de traço (-) ou [. Ignorar](dot-directives.md). Substitui /K se ambos forem especificados.|
|/K|Continuará a criar dependências não relacionadas, se um comando retornará um erro. Além disso, emite um aviso e retorna um código de saída igual a 1. Por padrão, NMAKE interromperá se qualquer comando retorna um código de saída diferente de zero. Avisos de /K são suprimidos pela /C; /I substitui /K se ambos forem especificados.|
|/N|Exibe, mas não executar os comandos; comandos de pré-processamento são executados. Não exibe comandos nas chamadas NMAKE recursivas. É útil para depuração makefiles e verificando os carimbos de hora. Para definir ou limpar /N para parte de um makefile, use **! CMDSWITCHES**.|
|/NOLOGO|Suprime a mensagem de direitos autorais de NMAKE.|
|/P|Exibe informações (definições de macro, regras de inferência, destinos, [. SUFIXOS](dot-directives.md) lista) para a saída padrão, e, em seguida, executa a compilação. Se não existe nenhum makefile ou o destino de linha de comando, ele exibe apenas informações. Use com /D para depurar um makefile.|
|/Q|Carimbos de hora de verificações de destinos; não executar a compilação. Retorna um código de saída zero se todos os destinos estiverem atualizados e um código de saída diferente de zero se não for de qualquer destino. Comandos de pré-processamento são executados. É útil ao executar NMAKE de um arquivo em lotes.|
|/R|Limpa o **. SUFIXOS** listar e ignora as regras de inferência de tipos e macros que são definidos no arquivo Tools. ini ou que são predefinidas.|
|/S|Suprime a exibição de comandos executados. Para suprimir a exibição em parte de um makefile, use o **\@** modificador de comando ou [. SILENCIOSA](dot-directives.md). Para definir ou limpar /S para parte de um makefile, use **! CMDSWITCHES**.|
|/T|Atualiza os carimbos de hora de destinos de linha de comando (ou o primeiro destino makefile) e executa comandos de pré-processamento, mas não executa a compilação.|
|/U|Deve ser usado em conjunto com /N. Despeja arquivos NMAKE embutidos para que a saída /N pode ser usada como um arquivo em lotes.|
|/X *filename*|Envia a saída de erro NMAKE *filename* em vez de erro padrão. Espaços ou tabulações podem preceder *filename*. Para enviar a saída de erro para a saída padrão, especifique um traço (-) para *filename*. Não afeta a saída de comandos para o erro padrão.|
|/Y|Desabilita as regras de inferência de modo de lote. Quando essa opção é selecionada, todas as regras de inferência de tipos de modo de lote são tratadas como regras de inferência regular.|

## <a name="see-also"></a>Consulte também

[Executando NMAKE](running-nmake.md)
