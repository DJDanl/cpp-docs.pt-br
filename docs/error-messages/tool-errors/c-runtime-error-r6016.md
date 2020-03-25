---
title: Erro em runtime de C R6016
ms.date: 11/04/2016
f1_keywords:
- R6016
helpviewer_keywords:
- R6016
ms.assetid: 7bd3f274-d9c4-4bc4-8252-80bf168c4c3a
ms.openlocfilehash: 22bf4b7e8951215d1a013edb29af1ebff7517ffc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197334"
---
# <a name="c-runtime-error-r6016"></a>Erro em runtime de C R6016

não há espaço suficiente para dados do thread

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há muitos motivos possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, um bug no aplicativo ou por um bug em um suplemento ou uma extensão usada pelo aplicativo.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o aplicativo.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para remover, reparar ou reinstalar suplementos ou extensões usados pelo aplicativo.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse erro ocorre porque o programa não recebeu memória suficiente do sistema operacional para concluir uma chamada de [_beginthread](../../c-runtime-library/reference/beginthread-beginthreadex.md) ou `_beginthreadex`, ou o armazenamento local de thread não foi inicializado pelo `_beginthread` ou `_beginthreadex`.

Quando um thread novo é iniciado, a biblioteca deve criar um banco de dados interno para o thread. Se o banco de dados não pode ser expandido usando memória fornecida pelo sistema operacional, ele não inicia e o processo de chamada para. Isso pode acontecer quando muitos threads foram criados pelo processo, ou se o armazenamento de thread local se esgotou.

Recomendamos que um executável que chama a biblioteca de tempo de execução C (CRT) deve usar `_beginthreadex` para a criação de thread em vez da API do Windows `CreateThread`. `_beginthreadex` inicializa o armazenamento estático interno usado por muitas funções CRT no armazenamento de thread local. Se você usar `CreateThread` para criar um thread, o CRT pode finalizar o processo com R6016 quando for feita uma chamada para uma função CRT que exija o armazenamento estático interno inicializado.
