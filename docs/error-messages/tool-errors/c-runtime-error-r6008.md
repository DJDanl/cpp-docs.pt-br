---
title: "R6008 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6008
dev_langs:
- C++
helpviewer_keywords:
- R6008
ms.assetid: f0f304fc-709a-4843-bc7e-bad1ae0d1649
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7ff8749859bd9f0300a606c7cc5e328873fe1f5c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6008"></a>R6008 de erro de tempo de execução do C
Não há espaço suficiente para argumentos  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, muita memória usada pelas variáveis de ambiente, ou um bug no programa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Reduza o número e tamanho dos argumentos de linha de comando para o aplicativo.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Havia memória suficiente para carregar o programa, mas não há memória suficiente para criar o **argv** matriz. Isso pode ser causado por condições de memória extremamente baixa ou muito grande de linhas de comando ou uso de variável de ambiente. Considere uma das seguintes soluções:  
  
-   Aumente a quantidade de memória disponível para o programa.  
  
-   Reduza o número e tamanho dos argumentos de linha de comando.  
  
-   Reduza o tamanho do ambiente, removendo variáveis desnecessárias.
