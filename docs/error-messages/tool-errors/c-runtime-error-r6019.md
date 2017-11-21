---
title: "R6019 de erro de tempo de execução C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: R6019
dev_langs: C++
helpviewer_keywords: R6019
ms.assetid: 8129923e-7db2-40ee-9602-def9365f8d28
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 32b2b2f29b1b426ab67f089ae7a54a9730f16535
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-runtime-error-r6019"></a>R6019 de erro de tempo de execução do C
não é possível abrir o dispositivo do console  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tentou acessar o console, mas ele não tem permissão suficiente. Há várias razões possíveis para esse erro, mas é normalmente porque o programa deve ser executado como um administrador, ou há um bug no programa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Execute o programa como administrador.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Esse erro ocorre porque o aplicativo de chamada de função de console, mas o sistema operacional não conceder acesso ao console. Exceto no modo de depuração, console funções geralmente não são permitidas em aplicativos da Windows Store. Se seu aplicativo requer privilégios de administrador para executar, verifique se que ele é instalado para ser executado como administrador, por padrão.