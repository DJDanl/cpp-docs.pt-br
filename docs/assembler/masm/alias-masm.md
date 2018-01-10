---
title: ALIAS (MASM) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: Alias
dev_langs: C++
helpviewer_keywords: ALIAS directive
ms.assetid: d9725c49-58de-41da-ab01-b06a56cf5cf2
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 59dc4fd5481b22e69153c68e94a81b2887118ebc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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