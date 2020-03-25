---
title: Erro em runtime de C R6033
ms.date: 11/04/2016
f1_keywords:
- R6033
helpviewer_keywords:
- R6033
ms.assetid: f9cffdc9-81bd-4a64-a698-02762cbd82c9
ms.openlocfilehash: 86ac98a2635975b811c7b50020e4d4782675ae4d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197011"
---
# <a name="c-runtime-error-r6033"></a>Erro em runtime de C R6033

Tentativa de usar o código MSIL desse assembly durante a inicialização de código nativo. Isso indica um bug em seu aplicativo. É mais provável que o resultado da chamada de uma função com compilação MSIL (/CLR) de um construtor nativo ou de DllMain.

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Esse erro pode ser causado por um bug no aplicativo ou por um bug em um suplemento ou extensão que ele usa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para remover, reparar ou reinstalar quaisquer extensões ou suplementos.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse diagnóstico indica que as instruções MSIL estavam em execução durante o bloqueio do carregador. Isso pode ocorrer se você tiver compilado nativo C++ usando o sinalizador/CLR. Use apenas o sinalizador/CLR em módulos que contêm código gerenciado. Para obter mais informações, consulte [inicialização de assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).
