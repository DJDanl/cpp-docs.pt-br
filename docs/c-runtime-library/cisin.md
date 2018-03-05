---
title: _CIsin | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CIsin
apilocation:
- msvcr80.dll
- msvcr100.dll
- msvcrt.dll
- msvcr110.dll
- msvcr120.dll
- msvcr90.dll
- msvcr110_clr0400.dll
apitype: DLLExport
f1_keywords:
- CIsin
- _CIsin
dev_langs:
- C++
helpviewer_keywords:
- _CIsin intrinsic
- CIsin intrinsic
ms.assetid: f215f39a-2341-4f1c-ba8e-cb522451ceb2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7e87589421c5a1e24c490a0f03928281bc7fb92b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cisin"></a>_CIsin
Calcula o seno do valor superior na pilha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __cdecl _CIsin();  
```  
  
## <a name="remarks"></a>Comentários  
 Esta versão da função `sin` tem uma convenção de chamada especializada que o compilador compreende. Ele acelera a execução porque ele evita que cópias sejam geradas e ajuda na alocação de registro.  
  
 O valor resultante é colocado na parte superior da pilha.  
  
## <a name="requirements"></a>Requisitos  
 **Plataforma:** x86  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [sin, sinf, sinl, sinh, sinhf, sinhl](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)