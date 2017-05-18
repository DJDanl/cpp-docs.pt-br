---
title: gmtime_s, _gmtime32_s, _gmtime64_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _gmtime32_s
- gmtime_s
- _gmtime64_s
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
- _gmtime_s
- gmtime64_s
- gmtime32_s
- _gmtime64_s
- gmtime_s
- _gmtime32_s
dev_langs:
- C++
helpviewer_keywords:
- gmtime_s function
- gmtime32_s function
- time functions
- gmtime64_s function
- _gmtime64_s function
- time structure conversion
- _gmtime_s function
- _gmtime32_s function
ms.assetid: 261c7df0-2b0c-44ba-ba61-cb83efaec60f
caps.latest.revision: 29
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: e130b125651c29a4ba2607b47b02b95c81468869
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="gmtimes-gmtime32s-gmtime64s"></a>gmtime_s, _gmtime32_s, _gmtime64_s
Converte um valor temporal em uma estrutura. Estas são versões de [_gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) com melhorias de segurança como descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t gmtime_s(  
   struct tm* _tm,  
   const __time_t* time  
);  
errno_t _gmtime32_s(  
   struct tm* _tm,  
   const __time32_t* time  
);  
errno_t _gmtime64_s(  
   struct tm* _tm,  
   const __time64_t* time   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_tm`  
 Ponteiro para uma estrutura `tm`. Os campos da estrutura retornada contêm o valor avaliado do argumento `timer` no horário UTC e não no horário local.  
  
 `time`  
 Ponteiro para a hora armazenada. A hora é representada como os segundos transcorridos desde a meia-noite (00:00:00) de 1º de janeiro de 1970, no horário UTC (Tempo Universal Coordenado).  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h; para obter uma lista desses erros, consulte [errno](../../c-runtime-library/errno-constants.md).  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`_tm`|`time`|Valor de|Valor em `_tm`|  
|-----------|------------|------------|--------------------|  
|`NULL`|qualquer|`EINVAL`|Não modificado.|  
|Não é `NULL` (aponta para a memória válida)|`NULL`|`EINVAL`|Todos os campos definidos como -1.|  
|Não é `NULL`|< 0|`EINVAL`|Todos os campos definidos como -1.|  
  
 Caso as duas primeiras condições de erro ocorram, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_gmtime32_s` divide o valor de `time` e o armazena em uma estrutura do tipo `tm`, definida em Time.h. O endereço da estrutura é passada em `_tm`. O valor de `time` normalmente é obtido com uma chamada para a função `time`.  
  
> [!NOTE]
>  O ambiente de destino deve tentar determinar se o horário de verão está em vigor. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo do horário de verão.  
  
 Cada um dos campos da estrutura é do tipo `int`, conforme mostrado na tabela a seguir.  
  
 `tm_sec`  
 Segundos após minuto (0 - 59).  
  
 `tm_min`  
 Minutos após a hora (0 - 59).  
  
 `tm_hour`  
 Horas desde a meia-noite (0 - 23).  
  
 `tm_mday`  
 Dia do mês (1-31).  
  
 `tm_mon`  
 Mês (0 - 11; Janeiro = 0).  
  
 `tm_year`  
 Ano (ano atual menos 1900).  
  
 `tm_wday`  
 Dia da semana (0 - 6; Domingo = 0).  
  
 `tm_yday`  
 Dia do ano (0 - 365; 1 de janeiro = 0).  
  
 `tm_isdst`  
 Sempre 0 para `gmtime`.  
  
 `_gmtime64_s`, que usa a estrutura `__time64_t`, permite que as datas sejam expressas até 23:59:59 de 31 de dezembro de 3000, no UTC, enquanto `gmtime32_s` representa apenas datas até 23:59:59 de 18 de janeiro de 2038, no UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para essas duas funções.  
  
 `gmtime_s` é uma função embutida que é avaliada como `_gmtime64_s` e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t` como o `time_t` antigo de 32 bits, poderá definir `_USE_32BIT_TIME_T`. Essa ação fará com que `gmtime_s` seja embutido em `_gmtime32_s`. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`gmtime_s`|\<time.h>|  
|`_gmtime32_s`|\<time.h>|  
|`_gmtime64_s`|\<time.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_gmtime64_s.c  
// This program uses _gmtime64_s to convert a 64-bit  
// integer representation of coordinated universal time  
// to a structure named newtime, then uses asctime_s to  
// convert this structure to an output string.  
  
#include <time.h>  
#include <stdio.h>  
  
int main( void )  
{  
   struct tm newtime;  
   __int64 ltime;  
   char buf[26];  
   errno_t err;  
  
   _time64( &ltime );  
  
   // Obtain coordinated universal time:   
   err = _gmtime64_s( &newtime, &ltime );  
   if (err)  
   {  
      printf("Invalid Argument to _gmtime64_s.");  
   }  
  
   // Convert to an ASCII representation   
   err = asctime_s(buf, 26, &newtime);  
   if (err)  
   {  
      printf("Invalid Argument to asctime_s.");  
   }  
  
   printf( "Coordinated universal time is %s\n",   
           buf );  
}  
```  
  
```Output  
Coordinated universal time is Fri Apr 25 20:12:33 2003  
```  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime_s, _wasctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime_s, _localtime32_s, _localtime64_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [_mkgmtime, _mkgmtime32, _mkgmtime64](../../c-runtime-library/reference/mkgmtime-mkgmtime32-mkgmtime64.md)   
 [mktime, _mktime32, _mktime64](../../c-runtime-library/reference/mktime-mktime32-mktime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)
