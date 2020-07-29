---
title: Erro em runtime de C R6025
ms.date: 11/04/2016
f1_keywords:
- R6025
helpviewer_keywords:
- R6025
ms.assetid: afa06d98-9c36-445b-b3e7-b6409bc8e779
ms.openlocfilehash: 6e184ba24ad535697a727276a980fd082625e082
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218046"
---
# <a name="c-runtime-error-r6025"></a>Erro em runtime de C R6025

chamada de função virtual pura

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. O motivo mais comum para esse erro é um bug no aplicativo ou uma instalação corrompida.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Nenhum objeto foi instanciado para manipular a chamada de função virtual pura.

Esse erro é causado pela chamada de uma função virtual em uma classe base abstrata por meio de um ponteiro que é criado por uma conversão para o tipo da classe derivada, mas, na verdade, é um ponteiro para a classe base. Isso pode ocorrer ao converter de um **`void`** <strong>\*</strong> para um ponteiro para uma classe quando o **`void`** <strong>\*</strong> foi criado durante a construção da classe base.
