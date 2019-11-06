---
title: Erro fatal C1049
description: Descreve o erro fatal do compilador C1049, argumento numérico inválido e explica como resolvê-lo.
ms.date: 11/04/2019
f1_keywords:
- C1049
helpviewer_keywords:
- C1049
ms.openlocfilehash: f2669eec4bafb24f26c405d4fa74a96fe5337d13
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73633192"
---
# <a name="fatal-error-c1049"></a>Erro fatal C1049

> argumento numérico inválido '*Value*'

O CL. O analisador de linha de comando EXE encontrou um *valor* onde ele estava esperando um argumento numérico.

Um erro C1049 pode ocorrer quando o compilador não consegue encontrar um argumento numérico para uma dessas opções de compilador:

[/constexpr: profundidade](/cpp/build/reference/constexpr-control-constexpr-evaluation)\
[/constexpr: backtrace](/cpp/build/reference/constexpr-control-constexpr-evaluation)\
[/constexpr: etapas](/cpp/build/reference/constexpr-control-constexpr-evaluation)

As opções do compilador de linha de comando que esperam um argumento numérico também podem relatar `Command line error D8004`, `Command line error D8021`, `Command line warning D9002`, `Command line warning D9014`ou `Command line warning D9024`.

Para resolver esse erro, examine a linha de comando para argumentos que estão no local incorretos ou ausentes. Verifique se não há espaço em branco inesperado entre opções e argumentos. A linha de comando final pode ser gerada por macros, variáveis de ambiente ou outras operações de sistema de compilação. É por isso que é importante observar a linha de comando real passada para o compilador.

- Em arquivos de comando ou makefiles, você pode usar um comando **Echo** para relatar a linha de comando real.

- No Visual Studio, abra a caixa de diálogo **páginas de propriedades** do projeto. Na página **Propriedades de configuração** > **CC++ /**  > **geral** , altere a propriedade **Suprimir faixa de inicialização** para **não**. Escolha **OK** para salvar suas alterações. A janela **saída** agora mostra a linha de comando quando você cria, logo após a linha de direitos autorais.

Outros sistemas de compilação podem ter arquivos de log ou opções detalhadas para ver os comandos reais usados. Para obter informações, verifique a documentação do sistema de compilação.
