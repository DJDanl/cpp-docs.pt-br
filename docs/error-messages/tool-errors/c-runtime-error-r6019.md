---
title: "R6019 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6019
dev_langs:
- C++
helpviewer_keywords:
- R6019
ms.assetid: 8129923e-7db2-40ee-9602-def9365f8d28
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0a490fa1c15c3c2dc3285af6c69689c2a7fbd4b6
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6019"></a>R6019 de erro de tempo de execução do C
não é possível abrir o dispositivo do console  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque tentou acessar o console, mas ele não tinha permissão suficiente. Há várias razões possíveis para esse erro, mas isso geralmente ocorre porque o programa deve ser executado como um administrador ou há um bug no programa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Execute o programa como administrador.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre porque o aplicativo de chamada de função de console, mas o sistema operacional não concedeu acesso ao console. Exceto no modo de depuração, console funções geralmente não são permitidas em aplicativos da Windows Store. Se seu aplicativo requer privilégios de administrador para ser executado, verifique se que ele é instalado para ser executado como administrador, por padrão.
