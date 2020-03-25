---
title: Erro em runtime de C R6017
ms.date: 11/04/2016
f1_keywords:
- R6017
helpviewer_keywords:
- R6017
ms.assetid: df3ec5f5-6771-4648-ba06-0e26c6a1cc6a
ms.openlocfilehash: 2d868939425c11f13dffd84e28c1afee45e3b11a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197296"
---
# <a name="c-runtime-error-r6017"></a>Erro em runtime de C R6017

erro de bloqueio de multithread inesperado

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Há vários motivos possíveis para esse erro, mas geralmente ele é causado por um defeito no código do aplicativo.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

O processo recebeu um erro inesperado ao tentar acessar um bloqueio de multithread de tempo de execução C em um recurso do sistema. Esse erro geralmente ocorre se o processo altera inadvertidamente os dados de heap de tempo de execução. No entanto, ela também pode ser causada por um erro interno na biblioteca de tempo de execução ou no código do sistema operacional.

Para corrigir esse problema, verifique se há bugs de corrupção de heap em seu código. Para obter mais informações e exemplos, consulte [detalhes de heap de depuração do CRT](/visualstudio/debugger/crt-debug-heap-details). Em seguida, verifique se você está usando os pacotes redistribuíveis mais recentes para a implantação do aplicativo. Para obter informações, consulte [Deployment in C++Visual ](../../windows/deployment-in-visual-cpp.md).
