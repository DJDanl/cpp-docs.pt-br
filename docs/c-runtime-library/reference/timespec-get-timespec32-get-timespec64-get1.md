---
title: timespec_get, _timespec32_get, _timespec64_get1 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- timespec_get
- _timespec32_get
- _timespec64_get
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
- timespec_get
- _timespec32_get
- _timespec64_get
- time/timespec_get
- time/_timespec32_get
- time/_timespec64_get
- timespec
- _timespec32
- _timespec64
dev_langs:
- C++
helpviewer_keywords:
- timespec_get function
- _timespec32_get function
- _timespec64_get function
ms.assetid: ed757258-b4f2-4c1d-a91b-22ea6ffce4ab
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 13b85eef72ed1a2180af1b41bf93eefe499967bd
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="timespecget-timespec32get-timespec64get"></a>timespec_get, _timespec32_get, _timespec64_get
Define o intervalo apontado pelo primeiro argumento com o horário do calendário atual, de acordo com a base de tempo especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int timespec_get(  
    struct timespec* const time_spec,  
    int const base  
);  
int _timespec32_get(  
    struct _timespec32* const time_spec,  
    int const base  
);  
int _timespec64_get(  
    struct _timespec64* const time_spec,  
    int const base  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `time_spec`  
 Ponteiro para um struct definido com a hora em segundos e nanossegundos desde o início da época.  
  
 `base`  
 Um valor específico à implementação diferente de zero que especifica a base de tempo.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor `base` se tiver êxito; caso contrário, retornará zero.  
  
## <a name="remarks"></a>Comentários  
 As funções `timespec_get` definem a hora atual no struct apontado para o argumento `time_spec`. Todas as versões desse struct têm dois membros, `tv_sec` e `tv_nsec`. O valor `tv_sec` é definido com o número inteiro de segundos e `tv_nsec` com o número integral de nanossegundos, arredondado para a resolução do relógio do sistema, desde o início da época especificado por `base`.  
  
 **Seção específica da Microsoft**  
  
 Essas funções dão suporte apenas a `TIME_UTC` como o valor `base`. Isso define o valor `time_spec` com o número de segundos e nanossegundos desde o início da época, meia-noite, 1º de janeiro de 1970, UTC (Tempo Universal Coordenado). Em um `struct _timespec32`, `tv_sec` é um valor `__time32_t`. Em um `struct _timespec64`, `tv_sec` é um valor `__time64_t`. Em um `struct timespec`, `tv_sec` é um tipo `time_t`, que tem um tamanho de 32 ou 64 bits, dependendo se a macro do pré-processador _USE_32BIT_TIME_T está definida. A função `timespec_get` é uma função embutida que chamará `_timespec32_get` se _USE_32BIT_TIME_T estiver definido; caso contrário, ela chamará `_timespec64_get`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`timespec_get`, `_timespec32_get`, `_timespec64_get`|C: \<time.h>, C++: \<ctime> ou \<time.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [asctime_s, _wasctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [gmtime_s, _gmtime32_s, _gmtime64_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [localtime_s, _localtime32_s, _localtime64_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)   
 [_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64](../../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md)