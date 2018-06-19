---
title: _CIlog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apiname:
- _CIlog
apilocation:
- msvcr90.dll
- msvcr120.dll
- msvcr80.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcrt.dll
apitype: DLLExport
f1_keywords:
- _CIlog
- CIlog
dev_langs:
- C++
helpviewer_keywords:
- _CIlog intrinsic
- CIlog intrinsic
ms.assetid: 23503854-ddaa-4fe0-a4a3-7fbb3a43bdec
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1cb6b88af98c047f4de641eba92033c0b2ac0c26
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32386979"
---
# <a name="cilog"></a>_CIlog
Calcula o logaritmo natural do valor superior na pilha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __cdecl _CIlog();  
```  
  
## <a name="remarks"></a>Comentários  
 Esta versão da função `log` tem uma convenção de chamada especializada que o compilador compreende. Ele acelera a execução porque ele evita que cópias sejam geradas e ajuda na alocação de registro.  
  
 O valor resultante é colocado na parte superior da pilha.  
  
## <a name="requirements"></a>Requisitos  
 **Plataforma:** x86  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [log, logf, log10, log10f](../c-runtime-library/reference/log-logf-log10-log10f.md)