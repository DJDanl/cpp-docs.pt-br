---
title: C R6031 de erro de tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6031
dev_langs:
- C++
helpviewer_keywords:
- R6031
ms.assetid: 805d4cd1-cb2f-43fe-87e6-e7bd5b7329c5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4a0ccd608baa2765ae355a16b9a71afbf3695d8f
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48859777"
---
# <a name="c-runtime-error-r6031"></a>C R6031 de erro de tempo de execução

Tentativa de inicializar o CRT mais de uma vez. Isso indica um bug em seu aplicativo.

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Isso pode ser causado bug no aplicativo ou por um bug em um complemento ou extensão que o aplicativo usa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover, reparar ou reinstalar todos os programas de complemento ou extensão usados pelo aplicativo.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Este diagnóstico indica que instruções MSIL estavam em execução durante o bloqueio do carregador. Para obter mais informações, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).