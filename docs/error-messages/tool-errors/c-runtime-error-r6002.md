---
title: "R6002 de erro de tempo de execução C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6002
dev_langs:
- C++
helpviewer_keywords:
- R6002
ms.assetid: 8fbbe65a-9c43-459e-8342-e1f6d1cef7d0
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6652435425cdb04084d183987ea25be7c11114ff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-runtime-error-r6002"></a>R6002 de erro de tempo de execução do C
suporte de ponto flutuante não carregado  
  
 A biblioteca de ponto flutuante necessário não foi vinculada.  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por uma falha no código do aplicativo ou ao tentar executar um aplicativo que não foi criado para o processador de determinado computador.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Esse erro pode ocorrer em seu aplicativo quando a biblioteca de ponto flutuante não foi vinculada. Verifique se há uma dessas causas:  
  
-   Uma cadeia de caracteres de formato para um `printf_s` ou `scanf_s` função continha uma especificação de formato de ponto flutuante e o programa não contém quaisquer valores de ponto flutuante ou variáveis. Para corrigir esse problema, use um argumento de ponto flutuante para corresponder com a especificação de formato de ponto flutuante ou executar uma atribuição de ponto flutuante em outro lugar no programa. Isso faz com que o suporte de ponto flutuante ser carregado.  
  
-   O compilador minimiza o tamanho de um programa, carregar o suporte de ponto flutuante somente quando necessário. O compilador não pode detectar as operações de ponto flutuantes ou especificações de formato de ponto flutuante em cadeias de caracteres de formato, portanto ele não carregue as rotinas de ponto flutuantes necessário. Para corrigir esse problema, use uma especificação de formato de ponto flutuante e forneça um argumento de ponto flutuante ou executar uma atribuição de ponto flutuante em outro lugar no programa. Isso faz com que o suporte de ponto flutuante ser carregado.  
  
-   Em um programa de linguagem mista, uma biblioteca C foi especificada antes de uma biblioteca FORTRAN quando o programa foi vinculado. Vincular novamente e especifique a biblioteca C última.