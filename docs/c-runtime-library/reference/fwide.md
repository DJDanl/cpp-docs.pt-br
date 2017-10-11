---
title: fwide | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- fwide
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- fwide
dev_langs:
- C++
helpviewer_keywords:
- fwide function
ms.assetid: a4641f5b-d74f-4946-95d5-53a64610d28d
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: f10bd98a6dedba2181aa1d5ebba60f64dda093be
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fwide"></a>fwide
Não implementado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fwide(  
   FILE *stream,  
   int mode;  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE` (ignorado).  
  
 `mode`  
 A nova largura do fluxo: positiva para caractere largo, negativa para byte e zero para deixar inalterado. (Este valor é ignorado.)  
  
## <a name="return-value"></a>Valor de retorno  
 Atualmente, esta função retorna somente `mode`.  
  
## <a name="remarks"></a>Comentários  
 A versão atual dessa função não está em conformidade com o Padrão.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fwide`|\<wchar.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).
