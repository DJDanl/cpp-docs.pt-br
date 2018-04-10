---
title: -HEAP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- /heap
dev_langs:
- C++
helpviewer_keywords:
- heap allocation, setting heap size
- HEAP editbin option
- -HEAP editbin option
- /HEAP editbin option
ms.assetid: 6ce759b5-75b7-44ff-a5fd-3a83a0ba9a48
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3d21fe68d96274eaf42c2b7d58aa025c49f8a6d6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="heap"></a>/HEAP
Define o tamanho do heap em bytes. Essa opção só se aplica a arquivos executáveis.  
  
```  
  
/HEAP:  
reserve[,commit]  
```  
  
## <a name="remarks"></a>Comentários  
 O `reserve` argumento especifica a alocação inicial de heap total na memória virtual. Por padrão, o tamanho do heap é 1 MB. [Referência de EDITBIN](../../build/reference/editbin-reference.md) Arredonda o valor especificado para o múltiplo mais próximo de 4 bytes.  
  
 Opcional `commit` argumento está sujeito a interpretação pelo sistema operacional. Em um sistema operacional Windows, ele especifica a quantidade inicial de memória física para alocar e a quantidade de memória adicional para alocar ao heap deve ser expandido. Memória virtual confirmada faz com que o espaço a ser reservado no arquivo de paginação. Um maior `commit` valor permite que o sistema alocar memória menor com frequência quando o aplicativo precisa de mais espaço de heap, mas aumenta os requisitos de memória e, possivelmente, a duração de inicialização do aplicativo. O `commit` valor deve ser menor ou igual a `reserve` valor.  
  
 Especifique o `reserve` e `commit` valores em decimal ou notação hexadecimal ou octal de linguagem C. Por exemplo, um valor de 1 MB pode ser especificado como 1048576 em decimal, ou 0x100000 em hexadecimal ou 04000000 em octal.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de EDITBIN](../../build/reference/editbin-options.md)