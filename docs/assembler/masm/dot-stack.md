---
title: . PILHA | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .STACK
dev_langs:
- C++
helpviewer_keywords:
- .STACK directive
ms.assetid: 70019463-5d4f-41b6-8464-023a8ac2466f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dab47677da8db2afca73a078b110300a017e7c8d
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="stack"></a>.STACK
Quando usado com [. MODELO](../../assembler/masm/dot-model.md), define um segmento de pilha (com nome de segmento pilha). Opcional `size` Especifica o número de bytes para a pilha (1.024 padrão). O `.STACK` diretiva fecha automaticamente a instrução de pilha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
.STACK [[size]]  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)