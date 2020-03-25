---
title: Erro em runtime de C R6024
ms.date: 11/04/2016
f1_keywords:
- R6024
helpviewer_keywords:
- R6024
ms.assetid: 0fb11c0f-9b81-4cab-81bd-4785742946a5
ms.openlocfilehash: de89d2e9e2b34f40b906a5dacca4179eade23f7e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197191"
---
# <a name="c-runtime-error-r6024"></a>Erro em runtime de C R6024

Não há espaço suficiente para a tabela _onexit/atexit

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Esse erro é geralmente causado por uma condição de memória extremamente baixa, ou raramente, por um bug no programa ou pela corrupção das bibliotecas visuais C++ que ele usa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar todas as cópias do Microsoft C++ Visual redistribuível.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse erro ocorre porque não havia memória disponível para a função de `_onexit` ou `atexit`. Esse erro é causado por uma condição de memória insuficiente. Você pode considerar alocar buffers na inicialização do aplicativo para ajudar a salvar os dados do usuário e executar uma saída limpa do aplicativo em condições de baixa memória.
