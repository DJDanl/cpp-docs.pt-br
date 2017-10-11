---
title: "Função exit | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- Exit
dev_langs:
- C++
helpviewer_keywords:
- exit function
ms.assetid: 26ce439f-81e2-431c-9ff8-a09a96f32127
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 240636bf7b6f10421c5d4ebd202a5fb3473a819d
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
