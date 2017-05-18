---
title: "R6033 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6033
dev_langs:
- C++
helpviewer_keywords:
- R6033
ms.assetid: f9cffdc9-81bd-4a64-a698-02762cbd82c9
caps.latest.revision: 4
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 27bf1610d6db9f778a4355183257fb237fc4a175
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6033"></a>R6033 de erro de tempo de execução do C
Tentativa de usar código MSIL desse assembly durante a inicialização do código nativo. Isso indica um erro em seu aplicativo. Provavelmente é o resultado da chamada de uma compilação MSIL (/ clr) a partir de um construtor nativo ou DllMain de função.  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Esse erro pode ser causado por um bug no aplicativo ou por um bug em um suplemento ou extensão que ele usa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o programa.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover, reparar ou reinstalar quaisquer extensões ou suplementos.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse diagnóstico indica que instruções MSIL estavam executando durante o bloqueio do carregador. Isso pode ocorrer se você tiver compilado C++ nativo usando o sinalizador /clr. Use somente o sinalizador /clr em módulos que contêm código gerenciado. Para obter mais informações, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).
