---
title: "R6031 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6031
dev_langs:
- C++
helpviewer_keywords:
- R6031
ms.assetid: 805d4cd1-cb2f-43fe-87e6-e7bd5b7329c5
caps.latest.revision: 5
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
ms.openlocfilehash: d32c46d254963675cc283a8934a6a7b089e745ca
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6031"></a>R6031 de erro de tempo de execução do C
Tentativa de inicializar o CRT mais de uma vez. Isso indica um erro em seu aplicativo.  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Isso pode ser causado bug no aplicativo ou por um bug em um complemento ou extensão que o aplicativo usa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o programa.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para remover, reparar ou reinstalar os programas de complemento ou extensão usados pelo aplicativo.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse diagnóstico indica que instruções MSIL estavam executando durante o bloqueio do carregador. Para obter mais informações, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).
