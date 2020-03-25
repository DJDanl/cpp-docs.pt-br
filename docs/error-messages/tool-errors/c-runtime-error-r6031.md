---
title: Erro em runtime de C R6031
ms.date: 11/04/2016
f1_keywords:
- R6031
helpviewer_keywords:
- R6031
ms.assetid: 805d4cd1-cb2f-43fe-87e6-e7bd5b7329c5
ms.openlocfilehash: 4b75b0855f0f0d60304cfe8b7a00b4ce27a8daab
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197100"
---
# <a name="c-runtime-error-r6031"></a>Erro em runtime de C R6031

Tentativa de inicializar o CRT mais de uma vez. Isso indica um bug em seu aplicativo.

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Isso pode ser causado por um bug no aplicativo ou por um bug em um complemento ou extensão que o aplicativo usa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para remover, reparar ou reinstalar qualquer complemento ou programa de extensão usado pelo aplicativo.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse diagnóstico indica que as instruções MSIL estavam em execução durante o bloqueio do carregador. Para obter mais informações, consulte [inicialização de assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).
