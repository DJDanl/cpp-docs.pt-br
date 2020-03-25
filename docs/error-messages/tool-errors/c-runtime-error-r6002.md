---
title: Erro em runtime de C R6002
ms.date: 11/04/2016
f1_keywords:
- R6002
helpviewer_keywords:
- R6002
ms.assetid: 8fbbe65a-9c43-459e-8342-e1f6d1cef7d0
ms.openlocfilehash: b2e617b6f7841f1aa7e6fd2f6962c0e117fab6c8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197412"
---
# <a name="c-runtime-error-r6002"></a>Erro em runtime de C R6002

suporte a ponto flutuante não carregado

A biblioteca de ponto flutuante necessária não foi vinculada.

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Há vários motivos possíveis para esse erro, mas geralmente ele é causado por um defeito no código do aplicativo ou pela tentativa de executar um aplicativo que não foi criado para o processador de seu computador específico.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse erro pode ocorrer em seu aplicativo quando a biblioteca de ponto flutuante não estava vinculada. Verifique se há uma destas causas:

- Uma cadeia de caracteres de formato para uma função `printf_s` ou `scanf_s` continha uma especificação de formato de ponto flutuante e o programa não continha nenhum valor de ponto flutuante ou variáveis. Para corrigir esse problema, use um argumento de ponto flutuante para corresponder à especificação de formato de ponto flutuante ou execute uma atribuição de ponto flutuante em outro lugar no programa. Isso faz com que o suporte de ponto flutuante seja carregado.

- O compilador minimiza o tamanho do programa ao carregar o suporte de ponto flutuante somente quando necessário. O compilador não pode detectar operações de ponto flutuante ou especificações de formato de ponto flutuante em cadeias de caracteres de formato, portanto, ele não carrega as rotinas de ponto flutuante necessárias. Para corrigir esse problema, use uma especificação de formato de ponto flutuante e forneça um argumento de ponto flutuante ou execute uma atribuição de ponto flutuante em outro lugar no programa. Isso faz com que o suporte de ponto flutuante seja carregado.

- Em um programa de linguagem mista, uma biblioteca C foi especificada antes de uma biblioteca FORTRAN quando o programa foi vinculado. Vincule novamente e especifique a biblioteca C por último.
