---
title: R6008 de erro de tempo de execução C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6008
dev_langs:
- C++
helpviewer_keywords:
- R6008
ms.assetid: f0f304fc-709a-4843-bc7e-bad1ae0d1649
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2d32734850c58b64694e96c3a27b759131e6c5ff
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33299871"
---
# <a name="c-runtime-error-r6008"></a>R6008 de erro de tempo de execução do C
Não há espaço suficiente para argumentos  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há várias razões possíveis para esse erro, mas geralmente é causado por uma condição de memória muito baixa, muita memória usada por um bug no programa ou variáveis de ambiente.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Reduza o número e tamanho dos argumentos de linha de comando para o aplicativo.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Havia memória suficiente para carregar o programa, mas não há memória suficiente para criar o **argv** matriz. Isso pode ser causado por condições de memória muito baixa ou muito grande de linhas de comando ou uso de variável de ambiente. Considere uma das seguintes soluções:  
  
-   Aumente a quantidade de memória disponível para o programa.  
  
-   Reduza o número e tamanho dos argumentos de linha de comando.  
  
-   Removendo variáveis desnecessários para reduzir o tamanho de ambiente.