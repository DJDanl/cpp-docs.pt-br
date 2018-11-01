---
title: C R6033 de erro de tempo de execução
ms.date: 11/04/2016
f1_keywords:
- R6033
helpviewer_keywords:
- R6033
ms.assetid: f9cffdc9-81bd-4a64-a698-02762cbd82c9
ms.openlocfilehash: 39d8a20dacb0cdeb2a767529e9716bd476f406dc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50467178"
---
# <a name="c-runtime-error-r6033"></a>C R6033 de erro de tempo de execução

Tentativa de usar o código MSIL desse assembly durante a inicialização do código nativo. Isso indica um bug em seu aplicativo. Provavelmente é o resultado da chamada de uma compilação de MSIL (/ clr) a partir de um construtor nativo ou DllMain de função.

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Esse erro pode ser causado por um bug no aplicativo ou por um bug em um suplemento ou uma extensão que ele usa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover, reparar ou reinstalar todos os suplementos ou extensões.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Este diagnóstico indica que instruções MSIL estavam em execução durante o bloqueio do carregador. Isso pode ocorrer se você tiver compilado o C++ nativo usando o sinalizador de /clr. Use somente o sinalizador de /clr em módulos que contêm código gerenciado. Para obter mais informações, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).