---
title: "Verificação de memória substitui | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- memory, overwrites
ms.assetid: da7c5d77-a267-415f-a8ab-ee5ce5bfc286
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 573710ae62384c8674009770b3c4fb29100db446
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="checking-for-memory-overwrites"></a>Verificando substituições de memória
Se você receber uma violação de acesso em uma chamada para uma função de manipulação de heap, é possível que seu programa corrompeu o heap. Deve ser um sintoma comum dessa situação:  
  
```  
Access Violation in _searchseg  
```  
  
 O [heapchk](../../c-runtime-library/reference/heapchk.md) função está disponível em ambos os debug e release cria (somente Windows NT) para verificar a integridade do heap de biblioteca de tempo de execução. Você pode usar `_heapchk` da mesma maneira como o `AfxCheckMemory` função para isolar uma substituição de heap, por exemplo:  
  
```  
if(_heapchk()!=_HEAPOK)  
   DebugBreak();  
```  
  
 Se essa função nunca falhar, você precisa isolar no ponto em que o heap foi corrompido.  
  
## <a name="see-also"></a>Consulte também  
 [Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)