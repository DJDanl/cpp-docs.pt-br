---
title: C R6027 de erro de tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6027
dev_langs:
- C++
helpviewer_keywords:
- R6027
ms.assetid: c06a62b3-08d9-4bf5-bcad-8340ec552f69
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3694c367c090d0dcc2fb5e4ac72c8f00593fed27
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46084803"
---
# <a name="c-runtime-error-r6027"></a>C R6027 de erro de tempo de execução

Não há espaço suficiente para a inicialização de lowio

> [!NOTE]
>  Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa. Ele também pode ser causado por um bug no aplicativo, por danos das bibliotecas do Visual C++ que ele usa ou por um driver.
>
>  Você pode tentar corrigir esse erro com estas etapas:
>
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> -   Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover o novo aplicativo ou driver e tente novamente o seu aplicativo.
> -   Use o **aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar todas as cópias do Microsoft Visual C++ redistribuível.
> -   Verifique **Windows Update** na **painel de controle** para atualizações de software.
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Esse erro ocorre quando não há memória suficiente disponível para inicializar o suporte de e/s de baixo nível no tempo de execução C. Esse erro geralmente ocorre na inicialização do aplicativo. Verifique se que seu aplicativo e os drivers e as dlls que ele carrega não corromper o heap durante a inicialização.