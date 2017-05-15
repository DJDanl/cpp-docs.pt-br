---
title: _tzset | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _tzset
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
- _tzset
dev_langs:
- C++
helpviewer_keywords:
- _tzset function
- time environment variables
- environment variables, setting time
ms.assetid: 3f6ed537-b414-444d-b272-5dd377481930
caps.latest.revision: 23
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
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 669b7d41234c21c3fb4e9a1a28f6b8d1a33c036b
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="tzset"></a>_tzset
Define variáveis de ambiente de tempo.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _tzset( void );  
```  
  
## <a name="remarks"></a>Comentários  
 A função `_tzset` usa a configuração atual da variável de ambiente `TZ` para atribuir valores a três variáveis globais: `_daylight`, `_timezone` e `_tzname`. Essas variáveis são usadas pelas funções [_ftime](../../c-runtime-library/reference/ftime-ftime32-ftime64.md) e [localtime](../../c-runtime-library/reference/localtime-localtime32-localtime64.md) para fazer correções de UTC (Tempo Universal Coordenado) para a hora local e pela função `time` para calcular o UTC de horário do sistema. Use a sintaxe a seguir para definir a variável de ambiente `TZ`:  
  
 `set` `TZ`=`tzn`[+ &#124; -]`hh`[`:``mm`[`:``ss`] ][`dzn`]  
  
 `tzn`  
 Nome de fuso horário de três letras, como PST. Você deve especificar o deslocamento correto da hora local em UTC.  
  
 `hh`  
 Diferença de horas entre UTC e hora local. Sinal (+) opcional para valores positivos.  
  
 `mm`  
 Minutos. Separado de `hh` por uma vírgula (`:`).  
  
 `ss`  
 Segundos. Separado de `mm` por uma vírgula (`:`).  
  
 `dzn`  
 Fuso horário de verão com três letras, como PDT. Se o horário de verão nunca estiver em vigor na localidade, defina `TZ` sem um valor para `dzn`. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo de DST (horário de verão).  
  
> [!NOTE]
>  Tome cuidado ao calcular o sinal da diferença de tempo. Como a diferença de tempo é o deslocamento de hora local em UTC (e não o contrário), o sinal pode ser o oposto do que você intuitivamente poderia esperar. Para fusos horários à frente do UTC, a diferença de tempo é negativa; para aqueles antes do UTC, a diferença é positiva.  
  
 Por exemplo, para definir a variável de ambiente `TZ` para corresponder ao fuso horário atual na Alemanha, digite o seguinte na linha de comando:  
  
```  
set TZ=GST-1GDT  
```  
  
 Esse comando usa o GST para indicar o horário padrão alemão, pressupõe que o UTC está uma hora atrás da Alemanha (ou, em outras palavras, que a Alemanha está uma hora à frente do UTC) e assume que a Alemanha observa o horário de verão.  
  
 Se o `TZ` valor não for definido, `_tzset` tenta usar as informações de fuso horário especificadas pelo sistema operacional. No sistema operacional Windows, essas informações são especificadas no aplicativo de Data/Hora no Painel de controle. Se `_tzset` não puder obter essas informações, usará PST8PDT por padrão, o que significa que o fuso horário do Pacífico.  
  
 Com base no valor da variável de ambiente `TZ`, os seguintes valores são atribuídos a variáveis globais `_daylight`, `_timezone` e `_tzname` quando `_tzset` é chamada:  
  
|Variável global|Descrição|Valor padrão|  
|---------------------|-----------------|-------------------|  
|`_daylight`|Um valor diferente de zero se for especificado um fuso horário de verão na configuração de `TZ`; caso contrário, 0.|1|  
|`_timezone`|Diferença em segundos entre a hora local e o UTC.|28800 (28.800 segundos é igual a 8 horas)|  
|`_tzname`[0]|Valor da cadeia de caracteres do nome do fuso horário da variável de ambiente `TZ`; vazio se `TZ` não tiver sido definida.|PST|  
|`_tzname`[1]|Valor da cadeia de caracteres do fuso horário de verão; vazio se o fuso horário de verão for omitido da variável de ambiente `TZ`.|PDT|  
  
 Os valores padrão mostrados na tabela anterior para `_daylight` e a matriz de `_tzname` correspondem a "PST8PDT." Se a zona do DST for omitida da variável de ambiente `TZ`, o valor de `_daylight` será 0 e as funções `_ftime`, `gmtime` e `localtime` retornarão 0 para seus sinalizadores de DST.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_tzset`|\<time.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_tzset.cpp  
// This program uses _tzset to set the global variables  
// named _daylight, _timezone, and _tzname. Since TZ is  
// not being explicitly set, it uses the system time.  
  
#include <time.h>  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
    _tzset();  
    int daylight;  
    _get_daylight( &daylight );  
    printf( "_daylight = %d\n", daylight );  
    long timezone;  
    _get_timezone( &timezone );  
    printf( "_timezone = %ld\n", timezone );  
    size_t s;  
    char tzname[100];  
    _get_tzname( &s, tzname, sizeof(tzname), 0 );  
    printf( "_tzname[0] = %s\n", tzname );  
    exit( 0 );  
}  
```  
  
```Output  
_daylight = 1  
_timezone = 28800  
_tzname[0] = Pacific Standard Time  
```  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)   
 [_utime, _utime32, _utime64, _wutime, _wutime32, _wutime64](../../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md)
