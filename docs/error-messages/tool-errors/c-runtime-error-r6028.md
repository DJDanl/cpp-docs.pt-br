---
title: Erro em runtime de C R6028
ms.date: 11/04/2016
f1_keywords:
- R6028
helpviewer_keywords:
- R6028
ms.assetid: 81e99079-4388-4244-a4f7-4641c508871c
ms.openlocfilehash: 1c165b7c9351e34ef6316962cd90663f2b6152ab
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197126"
---
# <a name="c-runtime-error-r6028"></a>Erro em runtime de C R6028

não é possível inicializar o heap

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há muitos motivos possíveis para esse erro, mas geralmente ele é causado por uma condição de memória extremamente baixa, um bug no programa ou por drivers de hardware defeituosos.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para remover o novo aplicativo ou driver e tente o aplicativo novamente.
> - Verifique o site do seu fornecedor de hardware ou **Windows Update** no **painel de controle** para atualizações de software e driver.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse erro ocorre quando o sistema operacional não criou o pool de memória para o aplicativo. Especificamente, o CRT (C Runtime) chamou a função `HeapCreate` do Win32, que retornou NULL indicando uma falha.

Se esse erro ocorrer durante a inicialização do aplicativo, o sistema não poderá atender às solicitações do heap porque drivers com defeito foram carregados. Verifique o site do Windows Update ou do fornecedor de seu hardware para obter os drivers atualizados.
