---
title: "R6032 de erro de tempo de execução C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: R6032
dev_langs: C++
helpviewer_keywords: R6032
ms.assetid: 52092a63-cc51-444a-bfc3-fad965a3558e
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: afe6ba23315dfd00114e3d2b956a19cadf6342c3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-runtime-error-r6032"></a>R6032 de erro de tempo de execução do C
Não há espaço suficiente para obter informações de localidade  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória muito baixa ou por um bug no programa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 O tempo de execução mantém informações sobre a localidade em cada thread para que ele possa processar chamadas a funções de distinção de localidade. Se a alocação de memória para obter essas informações falhar, o tempo de execução é não é possível prosseguir porque muitas de suas instalações básicas dependem dele.