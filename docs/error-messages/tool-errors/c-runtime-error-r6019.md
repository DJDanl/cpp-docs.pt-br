---
title: "R6019 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "R6019"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6019"
ms.assetid: 8129923e-7db2-40ee-9602-def9365f8d28
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6019 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível abrir o dispositivo do console  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque tentou acessar o console, mas ele não tinha permissão suficiente. Há várias razões possíveis para esse erro, mas isso geralmente ocorre porque o programa deve ser executado como um administrador ou há um bug no programa.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Execute o programa como administrador.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **Painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre porque o aplicativo de chamada de função de console, mas o sistema operacional não concedeu acesso ao console. Exceto no modo de depuração, console funções geralmente não são permitidas em aplicativos da Windows Store. Se seu aplicativo requer privilégios de administrador para ser executado, verifique se que ele é instalado para ser executado como administrador, por padrão.