---
title: C R6025 de erro de tempo de execução
ms.date: 11/04/2016
f1_keywords:
- R6025
helpviewer_keywords:
- R6025
ms.assetid: afa06d98-9c36-445b-b3e7-b6409bc8e779
ms.openlocfilehash: 461bfb2aa46053ec56fff67de70038b1fcd97389
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50639552"
---
# <a name="c-runtime-error-r6025"></a>C R6025 de erro de tempo de execução

chamada de função virtual pura

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. O motivo mais comum para esse erro é um bug no aplicativo ou uma instalação corrompida.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Nenhum objeto de instância foi instanciado para lidar com a chamada de função virtual pura.

Esse erro é causado por chamar uma função virtual em uma classe base abstrata através de um ponteiro que é criado por uma conversão para o tipo da classe derivada, mas é, na verdade, um ponteiro para a classe base. Isso pode ocorrer ao converter de um **void** <strong>\*</strong> em um ponteiro para uma classe quando o **void** <strong>\*</strong> foi criado durante a construção da classe base.

