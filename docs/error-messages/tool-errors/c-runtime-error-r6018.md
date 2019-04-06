---
title: C Runtime Error R6018
ms.date: 11/04/2016
f1_keywords:
- R6018
helpviewer_keywords:
- R6018
ms.assetid: f6dd40d1-a119-4d8b-b39e-97350ea23349
ms.openlocfilehash: b36e2184e5be131645fb4dd58a361fdb9a31da63
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58774965"
---
# <a name="c-runtime-error-r6018"></a>C Runtime Error R6018

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

Para corrigir esse problema, verifique se há bugs de corrupção de heap no seu código. Para obter mais informações e exemplos, consulte [detalhes do Heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Em seguida, verifique que você está usando os redistribuíveis mais recentes para sua implantação do aplicativo. Para obter informações, consulte [implantação no Visual C++](../../windows/deployment-in-visual-cpp.md).