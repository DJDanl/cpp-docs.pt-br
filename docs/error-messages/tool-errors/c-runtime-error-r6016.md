---
title: Erro em tempo de execução de C R6016
ms.date: 11/04/2016
f1_keywords:
- R6016
helpviewer_keywords:
- R6016
ms.assetid: 7bd3f274-d9c4-4bc4-8252-80bf168c4c3a
ms.openlocfilehash: b617e3cf6d48a24b01479ef7ef3fb6ac425b3996
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62279275"
---
# <a name="c-runtime-error-r6016"></a>Erro em tempo de execução de C R6016

não há espaço suficiente para dados do thread

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há muitas razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, um bug no aplicativo, ou por um bug em um suplemento ou a extensão usada pelo aplicativo.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o aplicativo.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover, reparar ou reinstalar o add-ins ou extensões usadas pelo aplicativo.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Esse erro ocorre porque o programa não recebeu memória suficiente do sistema operacional para concluir uma [beginthread](../../c-runtime-library/reference/beginthread-beginthreadex.md) ou `_beginthreadex` chamada ou armazenamento local não foi inicializado por thread `_beginthread` ou `_beginthreadex`.

Quando um thread novo é iniciado, a biblioteca deve criar um banco de dados interno para o thread. Se o banco de dados não pode ser expandido usando memória fornecida pelo sistema operacional, ele não inicia e o processo de chamada para. Isso pode acontecer quando muitos threads foram criados pelo processo, ou se o armazenamento de thread local se esgotou.

É recomendável que um executável que chama a biblioteca de tempo de execução C (CRT) deve usar `_beginthreadex` para a criação do thread em vez da API do Windows `CreateThread`. `_beginthreadex` inicializa o armazenamento estático interno usado por muitas funções CRT no armazenamento de thread local. Se você usar `CreateThread` para criar um thread, o CRT pode finalizar o processo com R6016 quando for feita uma chamada para uma função CRT que exija o armazenamento estático interno inicializado.