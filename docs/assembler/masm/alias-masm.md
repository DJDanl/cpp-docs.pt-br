---
title: ALIAS (MASM) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- Alias
dev_langs:
- C++
helpviewer_keywords:
- ALIAS directive
ms.assetid: d9725c49-58de-41da-ab01-b06a56cf5cf2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c1487afc250646b5cf1a12673dd43f6b1996a4f0
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="alias-masm"></a>ALIAS (MASM)
O **ALIAS** diretiva cria um nome alternativo para uma função.  Isso permite que você crie vários nomes para uma função ou bibliotecas que permitem que o vinculador (LINK.exe) para mapear uma função antiga para uma nova função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
ALIAS  <  
alias  
> = <  
actual-name  
>  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `actual-name`  
 O nome real da função ou procedimento.  Os colchetes são necessários.  
  
 `alias`  
 O nome de alias ou alternativo.  Os colchetes são necessários.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)