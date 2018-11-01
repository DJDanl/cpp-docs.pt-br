---
title: C R6018 de erro de tempo de execução
ms.date: 11/04/2016
f1_keywords:
- R6018
helpviewer_keywords:
- R6018
ms.assetid: f6dd40d1-a119-4d8b-b39e-97350ea23349
ms.openlocfilehash: e0d229b4fd8c1a4f8e067c0e59a278344fd4e113
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50531905"
---
# <a name="c-runtime-error-r6018"></a>C R6018 de erro de tempo de execução

Erro inesperado de heap

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por um defeito no código do aplicativo.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

O programa encontrou um erro inesperado ao executar uma operação de gerenciamento de memória.

Esse erro geralmente ocorre se o programa inadvertidamente altera os dados de heap do tempo de execução. No entanto, ele também pode ser causado por um erro interno no tempo de execução ou código do sistema operacional.

Para corrigir esse problema, verifique se há bugs de corrupção de heap no seu código. Para obter mais informações e exemplos, consulte [detalhes do Heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Em seguida, verifique que você está usando os redistribuíveis mais recentes para sua implantação do aplicativo. Para obter informações, consulte [implantação no Visual C++](../../ide/deployment-in-visual-cpp.md).