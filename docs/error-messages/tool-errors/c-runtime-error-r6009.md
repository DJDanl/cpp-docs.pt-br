---
title: C R6009 de erro de tempo de execução
ms.date: 11/04/2016
f1_keywords:
- R6009
helpviewer_keywords:
- R6009
ms.assetid: edfb1f8b-3807-48f4-a994-318923b747ae
ms.openlocfilehash: 5e1914d5d2f665609cfc24c2db3dc8a123d7e83f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50591302"
---
# <a name="c-runtime-error-r6009"></a>C R6009 de erro de tempo de execução

Não há espaço suficiente para o ambiente

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, muita memória executada por variáveis de ambiente ou um bug no programa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Havia memória suficiente para carregar o programa, mas não há memória suficiente para criar o **envp** matriz.  Isso pode ser causado por condições de memória extremamente baixa, ou pelo uso de variável de ambiente extraordinariamente grandes. Considere uma das seguintes soluções:

- Aumente a quantidade de memória disponível para o programa.

- Reduza o número e tamanho dos argumentos de linha de comando.

- Reduza o tamanho do ambiente, removendo variáveis desnecessárias.