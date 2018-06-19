---
title: R6018 de erro de tempo de execução C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6018
dev_langs:
- C++
helpviewer_keywords:
- R6018
ms.assetid: f6dd40d1-a119-4d8b-b39e-97350ea23349
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4946e3a8341963ee1a1ca2c3ad65d64cfbad8080
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302822"
---
# <a name="c-runtime-error-r6018"></a>R6018 de erro de tempo de execução do C
Erro inesperado de heap  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Há várias razões possíveis para esse erro, mas geralmente é causado por uma falha no código do aplicativo.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 O programa encontrou um erro inesperado ao executar uma operação de gerenciamento de memória.  
  
 Esse erro normalmente ocorre se o programa inadvertidamente altera os dados de heap de tempo de execução. No entanto, ele também pode ser causado por um erro interno no tempo de execução ou código de sistema operacional.  
  
 Para corrigir esse problema, verifique se há erros de corrupção de heap em seu código. Para obter mais informações e exemplos, consulte [detalhes de Heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Em seguida, verifique que você está usando o redistribuíveis mais recentes para sua implantação do aplicativo. Para obter informações, consulte [implantação no Visual C++](../../ide/deployment-in-visual-cpp.md).