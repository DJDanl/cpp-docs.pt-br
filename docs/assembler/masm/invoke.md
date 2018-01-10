---
title: INVOCAR | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: Invoke
dev_langs: C++
helpviewer_keywords: INVOKE directive
ms.assetid: 12d9bb40-33b9-411e-b801-45a1d675967e
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a4e17298c59a1c8620eb2261c44e5bd9c3aaceb0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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