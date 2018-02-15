---
title: LOCAL (MASM) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- Local
dev_langs:
- C++
helpviewer_keywords:
- LOCAL directive
ms.assetid: 76147e2d-23ca-4f1e-8817-81428becd113
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 037baa2032902060f6dc3e7ab3e54d95dd0922aa
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="local-masm"></a>LOCAL (MASM)
Na primeira diretiva, dentro de uma macro, **LOCAL** define rótulos que são exclusivos para cada instância da macro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      LOCAL localname [[, localname]]...  
LOCAL label [[ [count ] ]] [[:type]] [[, label [[ [count] ]] [[type]]]]...  
```  
  
## <a name="remarks"></a>Comentários  
 Na segunda diretiva, dentro de uma definição de procedimento (**PROC**), **LOCAL** cria variáveis com base em pilha que existem para a duração do procedimento. O *rótulo* pode ser uma variável simple ou uma matriz contendo *contagem* elementos.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)