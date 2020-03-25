---
title: Erro em runtime de C R6032
ms.date: 11/04/2016
f1_keywords:
- R6032
helpviewer_keywords:
- R6032
ms.assetid: 52092a63-cc51-444a-bfc3-fad965a3558e
ms.openlocfilehash: b29b946d08cff903cf0ca398ba0d7589cb5d54ea
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197087"
---
# <a name="c-runtime-error-r6032"></a>Erro em runtime de C R6032

Não há espaço suficiente para informações de localidade

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há vários motivos possíveis para esse erro, mas geralmente ele é causado por uma condição de memória extremamente baixa ou por um bug no programa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

O tempo de execução mantém informações sobre a localidade em cada thread para que ele possa processar chamadas para funções sensíveis à localidade. Se a alocação da memória para essas informações falhar, o tempo de execução não poderá continuar porque muitas de suas instalações básicas dependem dela.
