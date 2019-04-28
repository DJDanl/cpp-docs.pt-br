---
title: Erro em tempo de execução de C R6008
ms.date: 11/04/2016
f1_keywords:
- R6008
helpviewer_keywords:
- R6008
ms.assetid: f0f304fc-709a-4843-bc7e-bad1ae0d1649
ms.openlocfilehash: 60e6475a84d2662ad3718e04dba879dc06afeee7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62214071"
---
# <a name="c-runtime-error-r6008"></a>Erro em tempo de execução de C R6008

Não há espaço suficiente para argumentos

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, muita memória executada por variáveis de ambiente ou um bug no programa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Reduza o número e tamanho dos argumentos de linha de comando para o aplicativo.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Havia memória suficiente para carregar o programa, mas não há memória suficiente para criar o **argv** matriz. Isso pode ser causado por condições de memória extremamente baixa ou por excepcionalmente grande de linhas de comando ou o uso de variável de ambiente. Considere uma das seguintes soluções:

- Aumente a quantidade de memória disponível para o programa.

- Reduza o número e tamanho dos argumentos de linha de comando.

- Reduza o tamanho do ambiente, removendo variáveis desnecessárias.