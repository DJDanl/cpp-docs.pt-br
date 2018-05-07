---
title: R6027 de erro de tempo de execução C | Microsoft Docs
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
ms.openlocfilehash: cc38d664a6c9e2e2be0c360709ed6b39b1014b05
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="c-runtime-error-r6027"></a>R6027 de erro de tempo de execução do C
Não há espaço suficiente para a inicialização de lowio  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória muito baixa. Ele também pode ser causado por um bug no aplicativo, por danos das bibliotecas do Visual C++ que usa ou por um driver.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover a novo aplicativo ou driver e tente novamente o seu aplicativo.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar todas as cópias do Microsoft Visual C++ redistribuível.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Esse erro ocorre quando não há memória suficiente disponível para inicializar o suporte de e/s de baixo nível no tempo de execução C. Esse erro normalmente ocorre durante a inicialização do aplicativo. Verifique se seu aplicativo e os drivers e dlls que ele carrega não sejam corrompidos heap durante a inicialização.