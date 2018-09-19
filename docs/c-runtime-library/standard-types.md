---
title: Tipos padrão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- __time64_t
- _diskfree_t
- _CRT_DUMP_CLIENT
- _fsize_t
- __timeb64
- File
- __utimeb64
- jmp_buf
- __finddata64_t
- _wfinddata_t
- _finddata_t
- utimbuf64
- wint_t
- wctrans_t
- wctype_t
- _HFILE
- _secerr_handler_func
- clock_t
- fpos_t
- _dev_t
- time64_t
- wfinddata64_t
- stat64
- ldiv_t
- _EXCEPTION_POINTERS
- terminate_function
- size_t
- timeb64
- tm
- _HEAPINFO
- unexpected_function
- _CrtMemState
- _se_translator_function
- sig_atomic_t
- _CRT_REPORT_HOOK
- _complex
- _w_finddatai64_t
- _timeb
- _onexit_t
- _RTC_ErrorNumber
- lconv
- _PNH
- _off_t
- ptrdiff_t
- time_t
- _FPIEEE_RECORD
- _exception
- __w_finddata64_t
- __stat64
- _utimbuf
- __utimbuf64
- div_t
- _CRT_ALLOC_HOOK
- int8_t
- uint8_t
- int16_t
- uint16_t
- int32_t
- uint32_t
- int64_t
- int_least8_t
- uint_least8_t
- int_least16_t
- uint_least16_t
- int_least32_t
- uint_least32_t
- int_least64_t
- uint_least64_t
- int_fast8_t
- uint_fast8_t
- int_fast16_t
- uint_fast16_t
- int_fast32_t
- uint_fast32_t
- int_fast64_t
- uint_fast64_t
- intmax_t
- uintmax_t
dev_langs:
- C++
helpviewer_keywords:
- __timeb64 type
- tm type
- clock_t type
- intptr_t type
- diskfree_t type
- wctype_t type
- CRT_DUMP_CLIENT type
- sig_atomic_t type
- _PNH type
- time_t type
- wfinddata_t type
- timeb64
- CRT, standard types
- wint_t type
- _RTC_ErrorNumber type
- _diskfree_t type
- _dev_t type
- _wfinddata_t type
- HFILE type
- __utimbuf64 type
- div_t type
- _onexit_t type
- _secerr_handler_func type
- FPIEEE_RECORD type
- HEAPINFO type
- PNH type
- _CRT_ALLOC_HOOK type
- _se_translater_function type
- va_list type
- wctrans_t type
- secerr_handler_func type
- _locale_t type
- timeb type
- lconv type
- utimbuf type
- dev_t type
- unexpected_function typedef
- _complex type
- _off_t type
- off_t type
- RTC_ErrorNumber type
- _FPIEEE_RECORD type
- exception type
- _CRT_REPORT_HOOK type
- _HEAPINFO type
- ldiv_t type
- terminate_function type
- uintptr_t type
- _CRT_DUMP_CLIENT type
- _utimbuf type
- wfinddatai64_t type
- fpos_t type
- wchar_t type
- CRT_ALLOC_HOOK type
- _HFILE type
- __time64_t type
- _timeb type
- CrtMemState type
- __finddata64_t type
- _exception type
- stat type
- onexit_t type
- FILE constant
- _stat type
- finddata_t type
- __wfinddata64_t type
- ptrdiff_t type
- complex types
- _wfinddatai64_t type
- _EXCEPTION_POINTERS type
- jmp_buf type
- se_translater_function type
- size_t type
- EXCEPTION_POINTERS type
- __stat64 type
- _fsize_t type
- CRT_REPORT_HOOK type
- _finddata_t type
ms.assetid: 23312dd2-4a6a-4d70-9b48-2a5d0d8c9f28
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 03d16ede9f980ae65ea45c3777e025bf1a78bd38
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099415"
---
# <a name="standard-types"></a>Tipos padrão

A biblioteca em tempo de execução da Microsoft define os seguintes tipos e definições de tipo padrão.

### <a name="fixed-width-integral-types-stdinth"></a>Tipos integrais de largura fixa (stdint.h)

|Nome|Tipo interno equivalente|
|----------|-------------------------------|
|int8\_t, uint8\_t|signed char, unsigned char|
|int16\_t, uint16\_t|short, unsigned short|
|int32\_t, uint32\_t|int, unsigned int|
|int64\_t, uint64\_t|long long, unsigned long long|
|int_least8_t, uint_least8_t|signed char, unsigned char|
|int_least16_t, uint_least16_t|short, unsigned short|
|int_least32_t, uint_least32_t|int, unsigned int|
|int_least64_t, uint_least64_t|long long, unsigned long long|
|int_fast8_t, uint_fast8_t|signed char, unsigned char|
|int_fast16_t, uint_fast16_t|int, unsigned int|
|int_fast32_t, uint_fast32_t|int, unsigned int|
|int_fast64_t, uint_fast64_t|long long, unsigned long long|
|intmax_t, uintmax_t|long long, unsigned long long|

|Tipo|Descrição|Declarado em|
|----------|-----------------|-----------------|
|`clock_t` (longo)|Armazena valores de tempo; usada por [clock](../c-runtime-library/reference/clock.md).|TIME.H|
|Estrutura `_complex`|Armazena partes reais e imaginárias de números complexos; usada por [_cabs](../c-runtime-library/reference/cabs.md).|MATH.H|
|`_CRT_ALLOC_HOOK`|Uma definição de tipo para a função hook definida pelo usuário. Usada em [_CrtSetAllocHook](../c-runtime-library/reference/crtsetallochook.md).|CRTDBG.H|
|`_CRT_DUMP_CLIENT`,<br /><br /> `_CRT_DUMP_CLIENT_M`|Uma definição de tipo para uma função call-back que é chamada em [_CrtMemDumpAllObjectsSince](../c-runtime-library/reference/crtmemdumpallobjectssince.md).|CRTDBG.H|
|Estrutura `_CrtMemState`|Fornece informações sobre o estado atual do heap de depuração do CRT.|CRTDBG.H|
|`_CRT_REPORT_HOOK`,<br /><br /> `_CRT_REPORT_HOOKW`,<br /><br /> `_CRT_REPORT_HOOKW_M`|Uma definição de tipo para uma função call-back que é chamada em [_CrtDbgReport](../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md).<br /><br /> Os parâmetros para essa função são: tipo de relatório, mensagem de saída e o valor de retorno da função call-back.|CRTDBG.H|
|`dev_t`, `_dev_t` curto ou inteiro sem sinal|Representa os identificadores do dispositivo.|SYS\TYPES.H|
|Estrutura `_diskfree_t`|Contém informações sobre uma unidade de disco. Usada por [_getdiskfree](../c-runtime-library/reference/getdiskfree.md)**.**|DOS.H e DIRECT.H|
|Estruturas `div_t`, `ldiv_t` e `lldiv_t`|Armazenam os valores retornados por [div](../c-runtime-library/reference/div.md), [ldiv](../c-runtime-library/reference/ldiv-lldiv.md) e [lldiv](../c-runtime-library/reference/ldiv-lldiv.md), respectivamente.|STDLIB.H|
|Inteiro `errno_t`|Usado para um tipo de retorno de função ou parâmetro que trata os códigos de erro de `errno`.|STDDEF.H,<br /><br /> CRTDEFS.H|
|Estrutura `_exception`|Armazena informações de erro para [_matherr](../c-runtime-library/reference/matherr.md).|MATH.H|
|`_EXCEPTION_POINTERS`|Contém um registro de exceção. Veja [EXCEPTION_POINTERS](/windows/desktop/api/winnt/ns-winnt-_exception_pointers) para saber mais.|FPIEEE.H|
|Estrutura `FILE`|Armazena informações sobre o estado atual do fluxo; usado em todas as operações de E/S de fluxo.|STDIO.H|
|Estruturas `_finddata_t`, `_wfinddata_t`, `_finddata32_t`, `_wfinddata32_t`, `_finddatai64_t`, `_wfinddatai64_t`, `__finddata64_t`, `__wfinddata64_t`, `__finddata32i64_t`, `__wfinddata32i64_t`, `__finddata64i32_t`, `__wfinddata64i32_t`|Armazenar informações de atributo de arquivo retornadas por [_findfirst, _wfindfirst e funções relacionadas](../c-runtime-library/reference/findfirst-functions.md) e [_findnext, _wfindnext e funções relacionadas](../c-runtime-library/reference/findnext-functions.md). Veja [Funções de pesquisa de nome de arquivo](../c-runtime-library/filename-search-functions.md) para saber mais sobre membros de estrutura.|IO.H, WCHAR.H|
|Estrutura `_FPIEEE_RECORD`|Contém informações que pertencem à exceção de ponto flutuante IEEE; passadas para o manipulador de interceptação definido pelo usuário por [_fpieee_flt](../c-runtime-library/reference/fpieee-flt.md).|FPIEEE.H|
|`fpos_t` (inteiro longo, `__int64`, ou estrutura, dependendo da plataforma de destino)|Usada por [fgetpos](../c-runtime-library/reference/fgetpos.md) e [fsetpos](../c-runtime-library/reference/fsetpos.md) para registrar informações para especificar exclusivamente cada posição dentro de um arquivo.|STDIO.H|
|`_fsize_t` (inteiro longo sem sinal)|Usado para representar o tamanho de um arquivo.|IO.H,<br /><br /> WCHAR.H|
|Estrutura `_HEAPINFO`|Contém informações sobre a próxima entrada do heap para [_heapwalk](../c-runtime-library/reference/heapwalk.md).|MALLOC.H|
|`_HFILE` (\* nulo)|Um identificador de arquivo do sistema operacional.|CRTDBG.H|
|`imaxdiv_t`|O tipo de valor retornado pela função [imaxdiv](../c-runtime-library/reference/imaxdiv.md), contendo o quociente e o restante.|inttypes.h|
|`ino_t`, `_ino_t` (curto sem sinal)|Para retornar informações de status.|WCHAR.H|
|`intmax_t`|Um tipo de inteiro com sinal capaz de representar qualquer valor de qualquer tipo de inteiro com sinal.|stdint.h|
|`intptr_t` (inteiro longo ou `__int64`, dependendo da plataforma de destino)|Armazena um ponteiro (ou IDENTIFICADOR) em plataformas Win32 e Win64.|STDDEF.H e outros arquivos de inclusão|
|Matriz `jmp_buf`|Usada por [setjmp](../c-runtime-library/reference/setjmp.md) e [longjmp](../c-runtime-library/reference/longjmp.md) para salvar e restaurar o ambiente do programa.|SETJMP.H|
|Estrutura `lconv`|Contém regras de formatação para valores numéricos em países/regiões diferentes. Usada por [localeconv](../c-runtime-library/reference/localeconv.md).|LOCALE.H|
|`_LDOUBLE`,<br /><br /> `_LONGDOUBLE`,<br /><br /> `_LDBL12` (double longo ou uma matriz unsigned char)|Use para representar um valor double longo.|STDLIB.H|
|Estrutura `_locale_t`|Armazena valores da localidade atual; usada em todas as bibliotecas CRT específicas da localidade.|CRTDEF.H|
|`mbstate_t`|Controla o estado de uma conversão de caracteres de vários bytes.|WCHAR.H|
|`off_t`, inteiro longo `_off_t`|Representa o valor de deslocamento do arquivo.|WCHAR.H, SYS\TYPES.H|
|`_onexit_t`,<br /><br /> Ponteiro `_onexit_m_t`|Retornada por [_onexit, _onexit_m](../c-runtime-library/reference/onexit-onexit-m.md).|STDLIB.H|
|Ponteiro para função `_PNH`|Tipo de argumento para [_set_new_handler](../c-runtime-library/reference/set-new-handler.md).|NEW.H|
|`ptrdiff_t` (inteiro longo ou `__int64`, dependendo da plataforma de destino)|Resultado da subtração de dois ponteiros.|CRTDEFS.H|
|`_purecall_handler`,<br /><br /> `_purecall_handler_m`|Uma definição de tipo para uma função call-back que é chamada quando uma função virtual pura é chamada. Usada por [_get_purecall_handler, _set_purecall_handler](../c-runtime-library/reference/get-purecall-handler-set-purecall-handler.md). Uma função `_purecall_handler` deve ter um tipo de retorno nulo.|STDLIB.H|
|Definição de tipo `_RTC_error_fn`|Uma definição de tipo para uma função que trata verificações de erro no tempo de execução. Usado em [_RTC_SetErrorFunc](../c-runtime-library/reference/rtc-seterrorfunc.md).|RTCAPI.H|
|Definição de tipo `_RTC_error_fnW`|Uma definição de tipo para uma função que trata verificações de erro no tempo de execução. Usada em [_RTC_SetErrorFuncW](../c-runtime-library/reference/rtc-seterrorfuncw.md).|RTCAPI.H|
|Enumeração `_RTC_ErrorNumber`|Define condições de erro para [_RTC_GetErrDesc](../c-runtime-library/reference/rtc-geterrdesc.md) e [_RTC_SetErrorType](../c-runtime-library/reference/rtc-seterrortype.md).|RTCAPI.H|
|`_se_translator_function`|Uma definição de tipo para uma função call-back que converte uma exceção. O primeiro parâmetro é o código de exceção e o segundo parâmetro é o registro de exceção. Usada por [_set_se_translator](../c-runtime-library/reference/set-se-translator.md).|EH.H|
|Inteiro `sig_atomic_t`|Tipo de objeto que pode ser modificado como entidade atômica, mesmo na presença de interrupções assíncronas; usado com [signal](../c-runtime-library/reference/signal.md).|SIGNAL.H|
|`size_t` (__int64 sem sinal ou inteiro sem sinal, dependendo da plataforma de destino)|Resultado do operador `sizeof`.|CRTDEFS.H e outros arquivos de inclusão|
|Estrutura `_stat`|Contém informações de status do arquivo retornadas por [_stat](../c-runtime-library/reference/stat-functions.md) e [_fstat](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md).|SYS\STAT.H|
|Estrutura `__stat64`|Contém informações de status do arquivo retornadas por [_fstat64](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md) e [_stat64](../c-runtime-library/reference/stat-functions.md) e [_wstat64](../c-runtime-library/reference/stat-functions.md).|SYS\STAT.H|
|Estrutura `_stati64`|Contém informações de status do arquivo retornadas por [_fstati64](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md), [_stati64](../c-runtime-library/reference/stat-functions.md) e [_wstati64](../c-runtime-library/reference/stat-functions.md).|SYS\STAT.H|
|Definição de tipo `terminate_function`|Uma definição de tipo para uma função call-back que é chamada quando [terminate](../c-runtime-library/reference/terminate-crt.md) é chamado. Usada por [set_terminate](../c-runtime-library/reference/set-terminate-crt.md).|EH.H|
|`time_t` (__int64 ou inteiro longo)|Representa valores de hora em [mktime](../c-runtime-library/reference/mktime-mktime32-mktime64.md), [time](../c-runtime-library/reference/time-time32-time64.md), [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md), [ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md), [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md) e [gmtime, _gmtime32, _gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md). O número de segundos desde 1º de janeiro de 1970, 0:00 UTC. Se _USE_32BIT_TIME_T for definido, `time_t` será um inteiro longo. Se não for definido, será um inteiro de 64 bits.|TIME.H,<br /><br /> SYS\STAT.H,<br /><br /> SYS\TIMEB.H|
|`__time32_t` (inteiro longo)|Representa valores de hora em [mktime, _mktime32, _mktime64](../c-runtime-library/reference/mktime-mktime32-mktime64.md), [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md), [ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md), [gmtime, _gmtime32, _gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) e [localtime, _localtime32, _localtime64](../c-runtime-library/reference/localtime-localtime32-localtime64.md).|CRTDEFS.H, SYS\STAT.H,<br /><br /> SYS\TIMEB.H|
|`__time64_t` (`__int64`)|Representa valores de hora em [mktime, mktime32, mktime64](../c-runtime-library/reference/mktime-mktime32-mktime64.md), [ctime64, wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md), [ctime_s, _ctime32_s, _ctime64_s, wctime_s, _wctime32_s, _wctime64_s](../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md), [gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md), [localtime64](../c-runtime-library/reference/localtime-localtime32-localtime64.md) e [time64](../c-runtime-library/reference/time-time32-time64.md).|TIME.H,<br /><br /> SYS\STAT.H,<br /><br /> SYS\TIMEB.H|
|Estrutura `_timeb`|Usada por [_ftime](../c-runtime-library/reference/ftime-ftime32-ftime64.md) e [_ftime_s, _ftime32_s, _ftime64_s](../c-runtime-library/reference/ftime-s-ftime32-s-ftime64-s.md) para armazenar a hora atual do sistema.|SYS\TIMEB.H|
|Estrutura `__timeb32`|Usado por [ftime, ftime32, ftime64](../c-runtime-library/reference/ftime-ftime32-ftime64.md) e [ftime_s, _ftime32_s, _ftime64_s](../c-runtime-library/reference/ftime-s-ftime32-s-ftime64-s.md) para armazenar a hora atual do sistema.|SYS\TIMEB.H|
|Estrutura `__timeb64`|Usada por [_ftime64](../c-runtime-library/reference/ftime-ftime32-ftime64.md) e [_ftime_s, _ftime32_s, _ftime64_s](../c-runtime-library/reference/ftime-s-ftime32-s-ftime64-s.md) para armazenar a hora atual do sistema.|SYS\TIMEB.H|
|Estrutura `tm`|Usada por [asctime, _wasctime](../c-runtime-library/reference/asctime-wasctime.md), [asctime_s, _wasctime_s](../c-runtime-library/reference/asctime-s-wasctime-s.md), [gmtime, _gmtime32, _gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md), [gmtime_s, _gmtime32_s, _gmtime64_s](../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md), [localtime, _localtime32, _localtime64](../c-runtime-library/reference/localtime-localtime32-localtime64.md), [localtime_s, _localtime32_s, _localtime64_s](../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md), [mktime, _mktime32, _mktime64](../c-runtime-library/reference/mktime-mktime32-mktime64.md) e [strftime, wcsftime, _strftime_l, _wcsftime_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para armazenar e recuperar informações de hora.|TIME.H|
|`uintmax_t`|Um tipo de inteiro sem sinal capaz de representar qualquer valor de qualquer tipo de inteiro sem sinal.|stdint.h|
|`uintptr_t` (inteiro longo ou `__int64`, dependendo da plataforma de destino)|Um inteiro sem sinal ou uma versão __int64 sem sinal de `intptr_t`.|STDDEF.H e outros arquivos de inclusão|
|`unexpected_function`|Uma definição de tipo para uma função call-back que é chamada quando [unexpected](../c-runtime-library/reference/unexpected-crt.md) é chamado. Usada por [set_unexpected](../c-runtime-library/reference/set-unexpected-crt.md).|EH.H|
|Estrutura `_utimbuf`|Armazena os horários de acesso e modificação dos arquivos usados por [_utime, _wutime](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md) e [_futime, _futime32, _futime64](../c-runtime-library/reference/futime-futime32-futime64.md) para alterar as datas de modificação dos arquivos.|SYS\UTIME.H|
|Estrutura `_utimbuf32`|Armazena os horários de acesso e modificação usados por arquivos [utime, utime32, utime64, wutime, wutime32, wutime64](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md) e [futime, futime32, futime64](../c-runtime-library/reference/futime-futime32-futime64.md) para alterar as datas de modificação do arquivo.|SYS\UTIME.H|
|Estrutura `__utimbuf64`|Usada por [_utime64, _wutime64](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md) e [_futime64](../c-runtime-library/reference/futime-futime32-futime64.md) para armazenar a hora atual.|SYS\UTIME.H|
|Estrutura `va_list`|Usada para manter as informações necessárias pelas macros [va_arg](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md) e [va_end](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md). A função chamada declara a variável de tipo `va_list` que pode ser passada como argumento para outra função.|STDARG.H,<br /><br /> CRTDEFS.H|
|Caractere largo `wchar_t`|Útil para escrever programas portáteis para mercados internacionais.|STDDEF.H, STDLIB.H,<br /><br /> CRTDEFS.H,<br /><br /> SYS\STAT.H|
|Inteiro `wctrans_t`|Representa mapeamentos de caracteres específicos da localidade.|WCTYPE.H|
|Inteiro `wctype_t`|Pode representar todos os caracteres do conjunto de caracteres de qualquer idioma.|WCHAR.H,<br /><br /> CRTDEFS.H|
|Inteiro `wint_t`|Tipo de objeto de dados que pode conter qualquer caractere largo ou valor de fim de arquivo largo.|WCHAR.H,<br /><br /> CRTDEFS.H|

## <a name="see-also"></a>Consulte também

[Referência da biblioteca em tempo de execução C](../c-runtime-library/c-run-time-library-reference.md)
