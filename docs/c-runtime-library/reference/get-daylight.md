---
title: _get_daylight | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- __daylight
- _get_daylight
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
- get_daylight
- _get_daylight
dev_langs:
- C++
helpviewer_keywords:
- get_daylight function
- daylight saving time offset
- _get_daylight function
ms.assetid: f85a6ba3-e187-4ca7-aed7-ffc694c8ac4c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7af224cbf405ccb37927848bc0ee500f83ef0ada
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="getdaylight"></a>_get_daylight
Recupera a diferença de horário para o horário de verão em horas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      error_t _get_daylight(   
    int* hours  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hours`  
 A diferença em horas para o horário de verão.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero é bem-sucedido ou um valor `errno`, se ocorrer um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_get_daylight` recupera o número de horas no horário de verão como um número inteiro. Se o horário de verão estiver em vigor, a diferença de horário é de uma hora (embora algumas regiões tenham uma diferença de horário de duas horas).  
  
 Se `hours` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `EINVAL`.  
  
 Recomendamos usar essa função em vez do macro `_daylight` ou a função preterida `__daylight`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_get_daylight`|\<time.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)   
 [_get_dstbias](../../c-runtime-library/reference/get-dstbias.md)   
 [_get_timezone](../../c-runtime-library/reference/get-timezone.md)   
 [_get_tzname](../../c-runtime-library/reference/get-tzname.md)