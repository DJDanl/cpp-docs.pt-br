---
title: Erro em runtime de C R6009
ms.date: 11/04/2016
f1_keywords:
- R6009
helpviewer_keywords:
- R6009
ms.assetid: edfb1f8b-3807-48f4-a994-318923b747ae
ms.openlocfilehash: 64391f8ec05a99bb85a9d6cd00d6488a945fdb62
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197347"
---
# <a name="c-runtime-error-r6009"></a>Erro em runtime de C R6009

Não há espaço suficiente para o ambiente

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há vários motivos possíveis para esse erro, mas, muitas vezes, é causado por uma condição de memória extremamente baixa, muita memória usada por variáveis de ambiente ou um bug no programa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Havia memória suficiente para carregar o programa, mas não há memória suficiente para criar a matriz **envp** .  Isso pode ser causado por condições de memória extremamente baixas ou por uso incomum de variável de ambiente muito grande. Considere uma das seguintes soluções:

- Aumente a quantidade de memória disponível para o programa.

- Reduza o número e o tamanho dos argumentos de linha de comando.

- Reduza o tamanho do ambiente removendo variáveis desnecessárias.
