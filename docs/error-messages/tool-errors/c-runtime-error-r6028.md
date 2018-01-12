---
title: "R6028 de erro de tempo de execução C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: R6028
dev_langs: C++
helpviewer_keywords: R6028
ms.assetid: 81e99079-4388-4244-a4f7-4641c508871c
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7d1d7260cd2416e9d157931b037cfd7fbe4c0081
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-runtime-error-r6028"></a>R6028 de erro de tempo de execução do C
não é possível inicializar o heap  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há muitas razões possíveis para esse erro, mas geralmente é causado por uma condição de memória muito baixa, um bug no programa, ou os drivers de hardware com defeito.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover a novo aplicativo ou driver e tente novamente o seu aplicativo.  
> -   Verifique o site do fornecedor do hardware ou **Windows Update** no **painel de controle** para atualizações de software e o driver.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Esse erro ocorre quando o sistema operacional não criou o pool de memória para o aplicativo. Especificamente, o CRT (C Runtime) chamou a função `HeapCreate` do Win32, que retornou NULL indicando uma falha.  
  
 Se esse erro ocorrer durante a inicialização do aplicativo, o sistema não poderá atender às solicitações do heap porque drivers com defeito foram carregados. Verifique o site do Windows Update ou do fornecedor de seu hardware para obter os drivers atualizados.