---
title: C R6017 de erro de tempo de execução
ms.date: 11/04/2016
f1_keywords:
- R6017
helpviewer_keywords:
- R6017
ms.assetid: df3ec5f5-6771-4648-ba06-0e26c6a1cc6a
ms.openlocfilehash: 75e2512196937b483d6bc1a9817f6957bb468418
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50653906"
---
# <a name="c-runtime-error-r6017"></a>C R6017 de erro de tempo de execução

Erro de bloqueio inesperado de multithread

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por um defeito no código do aplicativo.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

O processo recebeu um erro inesperado ao tentar acessar um bloqueio de vários threads de tempo de execução do C em um recurso do sistema. Esse erro geralmente ocorre se o processo inadvertidamente altera os dados de heap do tempo de execução. No entanto, ele também pode ser causado por um erro interno na biblioteca de tempo de execução ou código do sistema operacional.

Para corrigir esse problema, verifique se há bugs de corrupção de heap no seu código. Para obter mais informações e exemplos, consulte [detalhes do Heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Em seguida, verifique que você está usando os redistribuíveis mais recentes para sua implantação do aplicativo. Para obter informações, consulte [implantação no Visual C++](../../ide/deployment-in-visual-cpp.md).