---
title: _CIatan | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _CIatan
apilocation:
- msvcr120.dll
- msvcr110.dll
- msvcrt.dll
- msvcr80.dll
- msvcr100.dll
- msvcr90.dll
- msvcr110_clr0400.dll
apitype: DLLExport
f1_keywords:
- _CIatan
- CIatan
dev_langs: C++
helpviewer_keywords:
- CIatan intrinsic
- _CIatan intrinsic
ms.assetid: 3baa0429-fe46-4bab-8b00-868e2186dc8c
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f50d9471f6ef1bcc6c28d474687c27e6f803df99
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ciatan"></a>_CIatan
Calcula o arco tangente do valor superior na pilha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __cdecl _CIatan();  
```  
  
## <a name="remarks"></a>Comentários  
 Esta versão da função `atan` tem uma convenção de chamada especializada que o compilador compreende. Ele acelera a execução porque ele evita que cópias sejam geradas e ajuda na alocação de registro.  
  
 O valor resultante é colocado na parte superior da pilha.  
  
## <a name="requirements"></a>Requisitos  
 **Plataforma:** x86  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [atan, atanf, atanl, atan2, atan2f, atan2l](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)