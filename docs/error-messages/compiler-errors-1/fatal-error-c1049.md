---
title: Erro fatal C1049
description: Descreve o erro fatal do compilador C1049, argumento numérico inválido e explica como resolvê-lo.
ms.date: 11/04/2019
f1_keywords:
- C1049
helpviewer_keywords:
- C1049
ms.openlocfilehash: 9b3cbe5d081e32680e5408fc4a6ddcd932db77a2
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91503267"
---
# <a name="fatal-error-c1049"></a>Erro fatal C1049

> argumento numérico inválido '*Value*'

O CL.EXE analisador de linha de comando encontrou um *valor* onde ele estava esperando um argumento numérico.

Um erro C1049 pode ocorrer quando o compilador não consegue encontrar um argumento numérico para uma dessas opções de compilador:

[/constexpr: profundidade](../../build/reference/constexpr-control-constexpr-evaluation.md)\
[/constexpr: backtrace](../../build/reference/constexpr-control-constexpr-evaluation.md)\
[/constexpr: etapas](../../build/reference/constexpr-control-constexpr-evaluation.md)

Opções de compilador de linha de comando que esperam um argumento numérico também podem relatar `Command line error D8004` , `Command line error D8021` ,, `Command line warning D9002` `Command line warning D9014` ou `Command line warning D9024` .

Para resolver esse erro, examine a linha de comando para argumentos que estão no local incorretos ou ausentes. Verifique se não há espaço em branco inesperado entre opções e argumentos. A linha de comando final pode ser gerada por macros, variáveis de ambiente ou outras operações de sistema de compilação. É por isso que é importante observar a linha de comando real passada para o compilador.

- Em arquivos de comando ou makefiles, você pode usar um comando **Echo** para relatar a linha de comando real.

- No Visual Studio, abra a caixa de diálogo **páginas de propriedades** do projeto. Na página **Propriedades de configuração**  >  **C/C++**  >  **geral** , altere a propriedade **Suprimir faixa de inicialização** para **não**. Escolha **OK** para salvar suas alterações. A janela **saída** agora mostra a linha de comando quando você cria, logo após a linha de direitos autorais.

Outros sistemas de compilação podem ter arquivos de log ou opções detalhadas para ver os comandos reais usados. Para obter informações, verifique a documentação do sistema de compilação.
