---
title: "Função exit | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: Exit
dev_langs: C++
helpviewer_keywords: exit function
ms.assetid: 26ce439f-81e2-431c-9ff8-a09a96f32127
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b9e0d6a7f903d4af39698b2d98c005cbf64515eb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exit-function"></a>Função exit
O **sair** função, declarada no arquivo de inclusão padrão STDLIB. H, encerra um programa C++.  
  
 O valor fornecido como um argumento para **sair** é retornado para o sistema operacional como o código de saída ou de código de retorno do programa. Por convenção, um código de retorno de zero indica que o programa foi encerrado com êxito.  
  
> [!NOTE]
>  Você pode usar as constantes `EXIT_FAILURE` e `EXIT_SUCCESS`, definidas em STDLIB.H, para indicar o êxito ou a falha do programa.  
  
 Emitir um `return` instrução from a **principal** função é equivalente a chamar o **sair** função com valor de retorno como seu argumento.  
  
 Para obter mais informações, consulte [sair](../c-runtime-library/reference/exit-exit-exit.md) no *referência da biblioteca de tempo de execução*.  
  
## <a name="see-also"></a>Consulte também  
 [Término do programa](../cpp/program-termination.md)