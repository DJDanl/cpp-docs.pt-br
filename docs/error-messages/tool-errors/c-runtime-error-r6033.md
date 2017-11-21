---
title: "R6033 de erro de tempo de execução C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: R6033
dev_langs: C++
helpviewer_keywords: R6033
ms.assetid: f9cffdc9-81bd-4a64-a698-02762cbd82c9
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 3ae5eddbce2e590e53e51b132ebbbd9589b385eb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-runtime-error-r6033"></a>R6033 de erro de tempo de execução do C
Tentativa de usar código MSIL desse assembly durante a inicialização de código nativo. Isso indica um bug em seu aplicativo. Provavelmente é o resultado da chamada de uma compilação MSIL (/ clr) de um construtor nativo ou de DllMain de função.  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Esse erro pode ser causado por um bug no aplicativo ou por um bug em um suplemento ou extensão que ele usa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover, repare ou reinstale o qualquer extensão ou suplementos.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Este diagnóstico indica que as instruções da MSIL estavam em execução durante o bloqueio do carregador. Isso pode ocorrer se você tiver compilado C++ nativo usando o sinalizador /clr. Use somente o sinalizador /clr em módulos que contêm o código gerenciado. Para obter mais informações, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md).