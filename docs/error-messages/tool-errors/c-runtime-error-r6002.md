---
title: "R6002 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6002
dev_langs:
- C++
helpviewer_keywords:
- R6002
ms.assetid: 8fbbe65a-9c43-459e-8342-e1f6d1cef7d0
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e9b50be6f1fd646f45ea1530c78e652f38b09c90
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6002"></a>R6002 de erro de tempo de execução do C
suporte de ponto flutuante não carregado  
  
 A biblioteca de ponto flutuante necessária não foi vinculada.  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por um defeito no código do aplicativo ou ao tentar executar um aplicativo que não foi criado para o processador do computador específico.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro pode ocorrer em seu aplicativo quando a biblioteca de ponto flutuante não foi vinculada. Verificar uma dessas causas:  
  
-   Uma cadeia de caracteres de formato para um `printf_s` ou `scanf_s` função continha uma especificação de formato de ponto flutuante e o programa não contém quaisquer valores de ponto flutuante ou variáveis. Para corrigir esse problema, use um argumento de ponto flutuante para que correspondam à especificação de formato de ponto flutuante ou executar uma atribuição de ponto flutuante em outro lugar no programa. Isso faz com que o suporte de ponto flutuante a ser carregado.  
  
-   O compilador minimiza o tamanho do programa carregando o suporte de ponto flutuante somente quando necessário. O compilador não pode detectar operações de ponto flutuante ou especificações de formato de ponto flutuante em cadeias de caracteres de formato, portanto não carrega as rotinas de ponto flutuantes necessárias. Para corrigir esse problema, use uma especificação de formato de ponto flutuante e fornecer um argumento de ponto flutuante ou executar uma atribuição de ponto flutuante em outro lugar no programa. Isso faz com que o suporte de ponto flutuante a ser carregado.  
  
-   Em um programa de linguagem mista, uma biblioteca C foi especificada antes de uma biblioteca FORTRAN quando o programa foi vinculado. Vincular novamente e especifique a biblioteca C última.
