---
title: _get_dstbias | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _get_dstbias
- __dstbias
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
- api-ms-win-crt-time-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- __dstbias
- _get_dstbias
- get_dstbias
dev_langs:
- C++
helpviewer_keywords:
- __dstbias
- daylight saving time offset
- get_dstbias function
- _get_dstbias function
ms.assetid: e751358c-1ecc-411b-ae2c-81b2ec54ea45
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4f6d43b904b96f7323c76637d1f38c024d4696f1
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="getdstbias"></a>_get_dstbias
Recupera a diferença de horário para o horário de verão em segundos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      error_t _get_dstbias(   
    int* seconds  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `seconds`  
 A diferença em segundos para o horário de verão.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero é bem-sucedido ou um valor `errno`, se ocorrer um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_get_dstbias` recupera o número de segundos no horário de verão como um número inteiro. Se o horário de verão estiver em vigor, a diferença padrão é de 3600 segundos, que é o número de segundos em uma hora (embora algumas regiões tenham uma diferença de duas horas).  
  
 Se `seconds` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `EINVAL`.  
  
 Recomendamos usar essa função em vez do macro `_dstbias` ou a função preterida `__dstbias`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_get_dstbias`|\<time.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)   
 [_get_daylight](../../c-runtime-library/reference/get-daylight.md)   
 [_get_timezone](../../c-runtime-library/reference/get-timezone.md)   
 [_get_tzname](../../c-runtime-library/reference/get-tzname.md)