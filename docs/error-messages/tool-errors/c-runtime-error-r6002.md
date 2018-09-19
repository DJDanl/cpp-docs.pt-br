---
title: C R6002 de erro de tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6002
dev_langs:
- C++
helpviewer_keywords:
- R6002
ms.assetid: 8fbbe65a-9c43-459e-8342-e1f6d1cef7d0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc23cf3c692eef37a86b5385d2e9e3a68340374e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46080916"
---
# <a name="c-runtime-error-r6002"></a>R6002 de erro de tempo de execução do C

suporte de ponto flutuante não carregado

A biblioteca de ponto flutuante necessário não foi vinculada.

> [!NOTE]
>  Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por um defeito no código do aplicativo ou pela tentativa de executar um aplicativo que não foi criado para o processador do computador específico.
>
>  Você pode tentar corrigir esse erro com estas etapas:
>
>  -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> -   Verifique **Windows Update** na **painel de controle** para atualizações de software.
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Esse erro pode ocorrer em seu aplicativo quando a biblioteca de ponto flutuante não foi vinculada. Verifique se há um desses exemplos faz:

- Uma cadeia de caracteres de formato para um `printf_s` ou `scanf_s` função continha uma especificação de formato de ponto flutuante e o programa não contém quaisquer valores de ponto flutuante ou variáveis. Para corrigir esse problema, use um argumento de ponto flutuante para corresponder à especificação de formato de ponto flutuante ou executar uma atribuição de ponto flutuante em outro lugar no programa. Isso faz com que o suporte de ponto flutuante a ser carregado.

- O compilador minimiza o tamanho de um programa, carregando o suporte de ponto flutuante somente quando necessário. O compilador não pode detectar operações de ponto flutuante ou especificações de formato de ponto flutuante em cadeias de caracteres de formato, portanto, não o carrega as rotinas de ponto flutuantes necessário. Para corrigir esse problema, use uma especificação de formato de ponto flutuante e fornecer um argumento de ponto flutuante ou executar uma atribuição de ponto flutuante em outro lugar no programa. Isso faz com que o suporte de ponto flutuante a ser carregado.

- Em um programa de linguagem mista, uma biblioteca C foi especificada antes de uma biblioteca FORTRAN quando o programa foi vinculado. Vincular novamente e especifique a biblioteca C pela última vez.