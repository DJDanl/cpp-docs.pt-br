---
title: C R6033 de erro de tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6033
dev_langs:
- C++
helpviewer_keywords:
- R6033
ms.assetid: f9cffdc9-81bd-4a64-a698-02762cbd82c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 64ff3069064b981ca1f4dd7b5c2d9a792cac8f26
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861856"
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