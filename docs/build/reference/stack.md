---
title: -PILHA | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /stack
dev_langs: C++
helpviewer_keywords:
- -STACK editbin option
- STACK editbin option
- stack, setting size
- /STACK editbin option
ms.assetid: a39bcff0-c945-4355-80cc-8e4f24a5f142
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 21438bf8f214c10525aa7e9a5829f835b8a33f2c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="stack"></a>/STACK
```  
/STACK:reserve[,commit]  
```  
  
## <a name="remarks"></a>Comentários  
 Essa opção define o tamanho da pilha em bytes e usa argumentos na notação decimal ou linguagem C. A opção /STACK só se aplica a um arquivo executável.  
  
 O *reservar* argumento especifica a alocação da pilha total na memória virtual. EDITBIN Arredonda o valor especificado para os mais próximos 4 bytes.  
  
 Opcional `commit` argumento está sujeito a interpretação pelo sistema operacional. No Windows NT, Windows 95 e Windows 98, `commit` Especifica a quantidade de memória física para alocar a cada vez. Memória virtual confirmada faz com que o espaço a ser reservado no arquivo de paginação. Um maior `commit` valor economiza tempo quando o aplicativo precisa de mais espaço de pilha, mas aumenta os requisitos de memória e, possivelmente, tempo de inicialização.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de EDITBIN](../../build/reference/editbin-options.md)