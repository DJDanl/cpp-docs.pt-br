---
title: R6026 de erro de tempo de execução de C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6026
dev_langs:
- C++
helpviewer_keywords:
- R6026
ms.assetid: 7ea751f8-fc20-46ab-99ef-84c95ca0b6b4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e5b10075912ce4fde65699cf7b2d413c0bdd10f0
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48860791"
---
# <a name="c-runtime-error-r6026"></a>R6026 de erro de tempo de execução do C

Não há espaço suficiente para inicialização stdio

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa. Ele também pode ser causado por um bug no aplicativo, por danos das bibliotecas do Visual C++ que ele usa ou por um driver.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover o novo aplicativo ou driver e tente novamente o seu aplicativo.
> - Use o **aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar todas as cópias do Microsoft Visual C++ redistribuível.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Esse erro ocorre quando não há memória livre suficiente disponível para inicializar o suporte de e/s padrão em tempo de execução C. Esse erro geralmente ocorre na inicialização do aplicativo. Verifique se que seu aplicativo e os drivers e as dlls que ele carrega não corromper o heap durante a inicialização.