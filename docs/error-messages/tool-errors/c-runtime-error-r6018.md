---
title: Erro em runtime de C R6018
ms.date: 11/04/2016
f1_keywords:
- R6018
helpviewer_keywords:
- R6018
ms.assetid: f6dd40d1-a119-4d8b-b39e-97350ea23349
ms.openlocfilehash: 83ad191fe1518e5e6bab0798840415ef392db71e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197282"
---
# <a name="c-runtime-error-r6018"></a>Erro em runtime de C R6018

erro de heap inesperado

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Há vários motivos possíveis para esse erro, mas geralmente ele é causado por um defeito no código do aplicativo.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

O programa encontrou um erro inesperado ao executar uma operação de gerenciamento de memória.

Esse erro geralmente ocorre se o programa altera inadvertidamente os dados de heap de tempo de execução. No entanto, ela também pode ser causada por um erro interno no tempo de execução ou no código do sistema operacional.

Para corrigir esse problema, verifique se há bugs de corrupção de heap em seu código. Para obter mais informações e exemplos, consulte [detalhes de heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details). Em seguida, verifique se você está usando os pacotes redistribuíveis mais recentes para a implantação do aplicativo. Para obter informações, consulte [Deployment in C++Visual ](../../windows/deployment-in-visual-cpp.md).
