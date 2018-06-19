---
title: INVOKE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- Invoke
dev_langs:
- C++
helpviewer_keywords:
- INVOKE directive
ms.assetid: 12d9bb40-33b9-411e-b801-45a1d675967e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 27c18c83b623ce1a22ffcb5e1a9f1ce98ee6eb20
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32055164"
---
# <a name="invoke"></a>INVOKE
Chama o procedimento no endereço fornecido pelo *expressão*, passando os argumentos na pilha ou nos registros de acordo com as convenções de chamada padrão do tipo de idioma.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
INVOKE   
expression [[, arguments]]  
```  
  
## <a name="remarks"></a>Comentários  
 Cada argumento passado para o procedimento pode ser uma expressão, um par de registro ou uma expressão de endereço (uma expressão é precedido por `ADDR`).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)