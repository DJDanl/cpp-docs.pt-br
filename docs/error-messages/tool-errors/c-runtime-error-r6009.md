---
title: C R6009 de erro de tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6009
dev_langs:
- C++
helpviewer_keywords:
- R6009
ms.assetid: edfb1f8b-3807-48f4-a994-318923b747ae
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 42a5aed9f823b5d2c5425c4d7baae129c08e76e7
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48860921"
---
# <a name="c-runtime-error-r6009"></a>C R6009 de erro de tempo de execução

Não há espaço suficiente para o ambiente

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, muita memória executada por variáveis de ambiente ou um bug no programa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Havia memória suficiente para carregar o programa, mas não há memória suficiente para criar o **envp** matriz.  Isso pode ser causado por condições de memória extremamente baixa, ou pelo uso de variável de ambiente extraordinariamente grandes. Considere uma das seguintes soluções:

- Aumente a quantidade de memória disponível para o programa.

- Reduza o número e tamanho dos argumentos de linha de comando.

- Reduza o tamanho do ambiente, removendo variáveis desnecessárias.