---
title: Erro em runtime de C R6025
ms.date: 11/04/2016
f1_keywords:
- R6025
helpviewer_keywords:
- R6025
ms.assetid: afa06d98-9c36-445b-b3e7-b6409bc8e779
ms.openlocfilehash: d5edb08278b7b6b9b3eb62e92fc04410f96a8f09
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80075123"
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

Esse erro é causado pela chamada de uma função virtual em uma classe base abstrata por meio de um ponteiro que é criado por uma conversão para o tipo da classe derivada, mas, na verdade, é um ponteiro para a classe base. Isso pode ocorrer ao converter de um **void** <strong>\*</strong> void para um ponteiro para uma classe quando o **void** <strong>\*</strong> void foi criado durante a construção da classe base.
