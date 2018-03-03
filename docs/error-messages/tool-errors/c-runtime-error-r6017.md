---
title: "R6017 de erro de tempo de execução C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6017
dev_langs:
- C++
helpviewer_keywords:
- R6017
ms.assetid: df3ec5f5-6771-4648-ba06-0e26c6a1cc6a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 57345feed2044683a1d5fd2a6ee7d14c412a827d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-runtime-error-r6017"></a>R6017 de erro de tempo de execução do C
Erro inesperado de bloqueio multithread  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por uma falha no código do aplicativo.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 O processo recebeu um erro inesperado ao tentar acessar um bloqueio de vários threads de tempo de execução C em um recurso do sistema. Esse erro normalmente ocorre se o processo inadvertidamente altera os dados de heap de tempo de execução. No entanto, ele também pode ser causado por um erro interno na biblioteca de tempo de execução ou código de sistema operacional.  
  
 Para corrigir esse problema, verifique se há erros de corrupção de heap em seu código. Para obter mais informações e exemplos, consulte [detalhes de Heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Em seguida, verifique que você está usando o redistribuíveis mais recentes para sua implantação do aplicativo. Para obter informações, consulte [implantação no Visual C++](../../ide/deployment-in-visual-cpp.md).