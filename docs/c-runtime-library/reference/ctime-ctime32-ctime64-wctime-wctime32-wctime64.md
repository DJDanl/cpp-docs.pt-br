---
title: ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _ctime64
- _wctime32
- ctime
- _wctime64
- _ctime32
- _wctime
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
- _wctime64
- _ctime32
- _tctime
- _wctime
- _wctime32
- _tctime64
- _ctime64
- ctime
dev_langs:
- C++
helpviewer_keywords:
- tctime64 function
- _ctime32 function
- ctime32 function
- _wctime function
- wctime64 function
- _tctime64 function
- _tctime32 function
- _ctime64 function
- _wctime64 function
- ctime function
- wctime32 function
- ctime64 function
- _wctime32 function
- _tctime function
- tctime32 function
- tctime function
- wctime function
- time, converting
ms.assetid: 2423de37-a35c-4f0a-a378-3116bc120a9d
caps.latest.revision: 25
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: f26c3c03d4b1a3492450e08d2c871e892c2eb4af
ms.lasthandoff: 02/25/2017

---
# <a name="ctime-ctime32-ctime64-wctime-wctime32-wctime64"></a>ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64
Converta um valor temporal em uma cadeia de caracteres e ajuste as configurações de fuso horário local. Versões mais seguras dessas funções estão disponíveis; consulte [ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](../../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *ctime(   
   const time_t *timer   
);  
char *_ctime32(   
   const __time32_t *timer )  
;  
char *_ctime64(   
   const __time64_t *timer )  
;  
wchar_t *_wctime(   
   const time_t *timer   
);  
wchar_t *_wctime32(   
   const __time32_t *timer  
);  
wchar_t *_wctime64(   
   const __time64_t *timer   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `timer`  
 Ponteiro para a hora armazenada.  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o resultado da cadeia de caracteres. `NULL` será retornado se:  
  
-   `time` representar uma data anterior à meia-noite de 1º de janeiro de 1970, UTC.  
  
-   Se você usar `_ctime32` ou `_wctime32` e `time` representar uma data posterior a 23:59:59, 18 de janeiro de 2038, UTC.  
  
-   Se você usar `_ctime64` ou `_wctime64` e `time` representar uma data posterior a 23:59:59, 31 de dezembro de 3000, UTC.  
  
 `ctime` é uma função embutida que é avaliada como `_ctime64` e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t` como o `time_t` antigo de 32 bits, poderá definir `_USE_32BIT_TIME_T`. Essa ação fará com que `ctime` seja avaliado como `_ctime32`. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.  
  
## <a name="remarks"></a>Comentários  
 A função `ctime` converte um valor temporal armazenado como um valor [time_t](../../c-runtime-library/standard-types.md) em uma cadeia de caracteres. Geralmente, o valor `timer` é obtido de uma chamada a [time](../../c-runtime-library/reference/time-time32-time64.md), que retorna o número de segundos decorridos desde a meia-noite (00:00:00), 1º de janeiro de 1970, UTC (tempo universal coordenado). A cadeia de caracteres do valor retornado contém exatamente 26 caracteres e tem o formato:  
  
```  
Wed Jan 02 02:03:55 1980\n\0  
```  
  
 Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha ('\n') e o caractere nulo ('\0') ocupam as duas últimas posições da cadeia de caracteres.  
  
 A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local. Consulte as funções `time`, [_ftime](../../c-runtime-library/reference/ftime-ftime32-ftime64.md) e [localtime](../../c-runtime-library/reference/localtime-localtime32-localtime64.md) para obter informações sobre como configurar a hora local e a função [_tzset](../../c-runtime-library/reference/tzset.md) para obter detalhes sobre como definir o ambiente de fuso horário e as variáveis globais.  
  
 Uma chamada a `ctime` modifica o único buffer alocado estaticamente usado pelas funções `gmtime` e `localtime`. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior. `ctime` compartilha um buffer estático com a função `asctime`. Portanto, uma chamada a `ctime` destrói os resultados das chamadas anteriores a `asctime`, `localtime` ou `gmtime`.  
  
 `_wctime` e `_wctime64` são a versão de caractere largo de `ctime` e `_ctime64`, retornando um ponteiro para a cadeia de caracteres largos. Caso contrário, `_ctime64`, `_wctime` e `_wctime64` se comportarão de modo idêntico a `ctime`.  
  
 Essas funções validam seus parâmetros. Se `timer` for um ponteiro nulo ou se o valor do timer for negativo, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornarão `NULL` e definirão `errno` como `EINVAL`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tctime`|`ctime`|`ctime`|`_wctime`|  
|`_tctime32`|`_ctime32`|`_ctime32`|`_wctime32`|  
|`_tctime64`|`_ctime64`|`_ctime64`|`_wctime64`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`ctime`|\<time.h>|  
|`_ctime32`|\<time.h>|  
|`_ctime64`|\<time.h>|  
|`_wctime`|\<time.h> ou \<wchar.h>|  
|`_wctime32`|\<time.h> ou \<wchar.h>|  
|`_wctime64`|\<time.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_ctime64.c  
// compile with: /W3  
/* This program gets the current  
 * time in _time64_t form, then uses ctime to  
 * display the time in string form.  
 */  
  
#include <time.h>  
#include <stdio.h>  
  
int main( void )  
{  
   __time64_t ltime;  
  
   _time64( &ltime );  
   printf( "The time is %s\n", _ctime64( &ltime ) ); // C4996  
   // Note: _ctime64 is deprecated; consider using _ctime64_s  
}  
```  
  
```Output  
The time is Wed Feb 13 16:04:43 2002  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
  
-   [System::DateTime::GetDateTimeFormats](https://msdn.microsoft.com/en-us/library/system.datetime.getdatetimeformats.aspx)  
  
-   [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)  
  
-   [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx)  
  
-   [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](../../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)
