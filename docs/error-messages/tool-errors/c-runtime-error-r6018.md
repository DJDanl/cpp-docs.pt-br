---
title: "R6018 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6018
dev_langs:
- C++
helpviewer_keywords:
- R6018
ms.assetid: f6dd40d1-a119-4d8b-b39e-97350ea23349
caps.latest.revision: 7
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
ms.sourcegitcommit: 6cad5222fb0d97594d5b13b5cf8903eb2934ee88
ms.openlocfilehash: 07aa2d06b990f0eed1f089b677e55c4d2e78a01e
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6018"></a>R6018 de erro de tempo de execução do C
Erro inesperado de heap  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por um defeito no código do aplicativo.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 O programa encontrou um erro inesperado ao executar uma operação de gerenciamento de memória.  
  
 Esse erro geralmente ocorre se o programa inadvertidamente altera os dados da pilha de tempo de execução. No entanto, ele também pode ser causado por um erro interno no tempo de execução ou código do sistema operacional.  
  
 Para corrigir esse problema, procure bugs de corrupção de heap no seu código. Para obter mais informações e exemplos, consulte [detalhes da pilha de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Em seguida, verifique se estão usando os redistribuíveis mais recentes para sua implantação do aplicativo. Para obter informações, consulte [implantação no Visual C++](../../ide/deployment-in-visual-cpp.md).
