---
title: C R6008 de erro de tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6008
dev_langs:
- C++
helpviewer_keywords:
- R6008
ms.assetid: f0f304fc-709a-4843-bc7e-bad1ae0d1649
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 39b06566f84003b08f5fe3869a021c4bf86dcf5f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46105096"
---
# <a name="c-runtime-error-r6008"></a>C R6008 de erro de tempo de execução

Não há espaço suficiente para argumentos

> [!NOTE]
>  Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, muita memória executada por variáveis de ambiente ou um bug no programa.
>
>  Você pode tentar corrigir esse erro com estas etapas:
>
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> -   Reduza o número e tamanho dos argumentos de linha de comando para o aplicativo.
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> -   Verifique **Windows Update** na **painel de controle** para atualizações de software.
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Havia memória suficiente para carregar o programa, mas não há memória suficiente para criar o **argv** matriz. Isso pode ser causado por condições de memória extremamente baixa ou por excepcionalmente grande de linhas de comando ou o uso de variável de ambiente. Considere uma das seguintes soluções:

- Aumente a quantidade de memória disponível para o programa.

- Reduza o número e tamanho dos argumentos de linha de comando.

- Reduza o tamanho do ambiente, removendo variáveis desnecessárias.