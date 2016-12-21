---
title: "Tipos padr&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "__time64_t"
  - "_diskfree_t"
  - "_CRT_DUMP_CLIENT"
  - "_fsize_t"
  - "__timeb64"
  - "File"
  - "__utimeb64"
  - "jmp_buf"
  - "__finddata64_t"
  - "_wfinddata_t"
  - "_finddata_t"
  - "utimbuf64"
  - "wint_t"
  - "wctrans_t"
  - "wctype_t"
  - "_HFILE"
  - "_secerr_handler_func"
  - "clock_t"
  - "fpos_t"
  - "_dev_t"
  - "time64_t"
  - "wfinddata64_t"
  - "stat64"
  - "ldiv_t"
  - "_EXCEPTION_POINTERS"
  - "terminate_function"
  - "size_t"
  - "timeb64"
  - "tm"
  - "_HEAPINFO"
  - "unexpected_function"
  - "_CrtMemState"
  - "_se_translator_function"
  - "sig_atomic_t"
  - "_CRT_REPORT_HOOK"
  - "_complex"
  - "_w_finddatai64_t"
  - "_timeb"
  - "_onexit_t"
  - "_RTC_ErrorNumber"
  - "lconv"
  - "_PNH"
  - "_off_t"
  - "ptrdiff_t"
  - "time_t"
  - "_FPIEEE_RECORD"
  - "_exception"
  - "__w_finddata64_t"
  - "__stat64"
  - "_utimbuf"
  - "__utimbuf64"
  - "div_t"
  - "_CRT_ALLOC_HOOK"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Tipo __finddata64_t"
  - "Tipo __stat64"
  - "Tipo __time64_t"
  - "Tipo __timeb64"
  - "Tipo __utimbuf64"
  - "Tipo __wfinddata64_t"
  - "Tipo _complex"
  - "Tipo _CRT_ALLOC_HOOK"
  - "Tipo _CRT_DUMP_CLIENT"
  - "Tipo _CRT_REPORT_HOOK"
  - "Tipo _dev_t"
  - "Tipo _diskfree_t"
  - "Tipo _exception"
  - "Tipo _EXCEPTION_POINTERS"
  - "Tipo _finddata_t"
  - "Tipo _FPIEEE_RECORD"
  - "Tipo _fsize_t"
  - "Tipo _HEAPINFO"
  - "Tipo _HFILE"
  - "Tipo _locale_t"
  - "Tipo _off_t"
  - "Tipo _onexit_t"
  - "Tipo _PNH"
  - "Tipo _RTC_ErrorNumber"
  - "Tipo _se_translater_function"
  - "Tipo _secerr_handler_func"
  - "Tipo _stat"
  - "Tipo _timeb"
  - "Tipo _utimbuf"
  - "Tipo _wfinddata_t"
  - "Tipo _wfinddatai64_t"
  - "Tipo clock_t"
  - "tipos complexos"
  - "CRT, tipos padrão"
  - "Tipo CRT_ALLOC_HOOK"
  - "Tipo CRT_DUMP_CLIENT"
  - "Tipo CRT_REPORT_HOOK"
  - "Tipo CrtMemState"
  - "Tipo dev_t"
  - "Tipo diskfree_t"
  - "Tipo div_t"
  - "tipo de exceção"
  - "Tipo EXCEPTION_POINTERS"
  - "Constante FILE"
  - "Tipo finddata_t"
  - "Tipo FPIEEE_RECORD"
  - "Tipo fpos_t"
  - "Tipo HEAPINFO"
  - "Tipo HFILE"
  - "Tipo intptr_t"
  - "Tipo jmp_buf"
  - "Tipo lconv"
  - "Tipo ldiv_t"
  - "Tipo off_t"
  - "Tipo onexit_t"
  - "Tipo PNH"
  - "Tipo ptrdiff_t"
  - "Tipo RTC_ErrorNumber"
  - "Tipo se_translater_function"
  - "Tipo secerr_handler_func"
  - "Tipo sig_atomic_t"
  - "Tipo size_t"
  - "Tipo stat"
  - "Tipo terminate_function"
  - "Tipo time_t"
  - "Tipo timeb"
  - "timeb64"
  - "Tipo tm"
  - "Tipo uintptr_t"
  - "unexpected_function (typedefs)"
  - "Tipo utimbuf"
  - "Tipo va_list"
  - "Tipo wchar_t"
  - "Tipo wctrans_t"
  - "Tipo wctype_t"
  - "Tipo wfinddata_t"
  - "Tipo wfinddatai64_t"
  - "Tipo wint_t"
ms.assetid: 23312dd2-4a6a-4d70-9b48-2a5d0d8c9f28
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tipos padr&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de tempo de execução do Microsoft define os seguintes tipos padrão e definições de tipo.  
  
### Tipos integrais de largura fixa \(stdint\)  
  
|Nome|Tipo interno equivalente|  
|----------|------------------------------|  
|int8\_t, uint8\_t|char assinada, char não assinada|  
|int16\_t, int16\_t|Em suma, curto sem sinal|  
|int32\_t, uint32\_t|int, int não assinado|  
|int64\_t, int64\_t|unsigned long long, long long|  
|int\_least8\_t, uint\_least8\_t|char assinada, char não assinada|  
|int\_least16\_t, uint\_least16\_t|Em suma, curto sem sinal|  
|int\_least32\_t, uint\_least32\_t|int, int não assinado|  
|int\_least64\_t, uint\_least64\_t|unsigned long long, long long|  
|int\_fast8\_t, uint\_fast8\_t|char assinada, char não assinada|  
|int\_fast16\_t, uint\_fast16\_t|int, int não assinado|  
|int\_fast32\_t, uint\_fast32\_t|int, int não assinado|  
|int\_fast64\_t, uint\_fast64\_t|unsigned long long, long long|  
|intmax\_t, uintmax\_t|unsigned long long, long long|  
  
|Tipo|Descrição|Declarado em|  
|----------|---------------|------------------|  
|`clock_t` \(longo\)|Armazena valores de tempo; usado por [clock](../c-runtime-library/reference/clock.md).|TIME.H|  
|Estrutura `_complex`|Armazena partes reais e imaginárias de números complexos; usado por [\_cabs](../Topic/_cabs.md).|MATH.H|  
|`_CRT_ALLOC_HOOK`|Uma definição de tipo para a função hook definida pelo usuário.  Usado em [\_CrtSetAllocHook](../Topic/_CrtSetAllocHook.md).|CRTDBG.H|  
|`_CRT_DUMP_CLIENT`,<br /><br /> `_CRT_DUMP_CLIENT_M`|Uma definição de tipo para uma função call\-back que é chamada em [\_CrtMemDumpAllObjectsSince](../Topic/_CrtMemDumpAllObjectsSince.md).|CRTDBG.H|  
|Estrutura `_CrtMemState`|Fornece informações sobre o estado atual do heap de depuração do CRT.|CRTDBG.H|  
|`_CRT_REPORT_HOOK`,<br /><br /> `_CRT_REPORT_HOOKW`,<br /><br /> `_CRT_REPORT_HOOKW_M`|Uma definição de tipo para uma função call\-back que é chamada em [\_CrtDbgReport](../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md).<br /><br /> Os parâmetros para essa função são: tipo de relatório, mensagem de saída e o valor de retorno da função call\-back.|CRTDBG.H|  
|`dev_t`, `_dev_t` curto ou inteiro sem sinal|Representa os identificadores do dispositivo.|SYS\\TYPES.H|  
|`_diskfree_t` estrutura|Contém informações sobre uma unidade de disco.  Usado por [\_getdiskfree](../Topic/_getdiskfree.md)**.**|DOS.H e DIRECT.H|  
|Estruturas `div_t`, `ldiv_t` e `lldiv_t`|Armazenam os valores retornados por [div](../c-runtime-library/reference/div.md), [ldiv](../Topic/ldiv,%20lldiv.md) e [lldiv](../Topic/ldiv,%20lldiv.md), respectivamente.|STDLIB.H|  
|Inteiro `errno_t`|Usado para um tipo de retorno de função ou parâmetro que trata os códigos de erro de `errno`.|STDDEF.H,<br /><br /> CRTDEFS.H|  
|Estrutura `_exception`|Armazena informações de erro para [\_matherr](../c-runtime-library/reference/matherr.md).|MATH.H|  
|`_EXCEPTION_POINTERS`|Contém um registro de exceção.  Consulte [EXCEPTION\_POINTERS](http://msdn.microsoft.com/library/windows/desktop/ms679331) para obter mais informações.|FPIEEE.H|  
|`FILE` estrutura|Armazena informações sobre o estado atual do fluxo; usado em todas as operações de E\/S de fluxo.|STDIO.H|  
|Estruturas `_finddata_t`, `_wfinddata_t`, `_finddata32_t`, `_wfinddata32_t`, `_finddatai64_t`, `_wfinddatai64_t`, `__finddata64_t`, `__wfinddata64_t`, `__finddata32i64_t`, `__wfinddata32i64_t`, `__finddata64i32_t`, `__wfinddata64i32_t`|Armazenar informações de atributo de arquivo retornadas por [FindFirst, wfindfirst e funções relacionadas](../Topic/_findfirst,%20_findfirst32,%20_findfirst32i64,%20_findfirst64,%20_findfirst64i32,%20_findfirsti64,%20_wfindfirst,%20_wfindfirst32,%20_wfindfirst32i64,%20_wfindfirst64,%20_wfindfirst64i32,%20_wfindfirsti64.md) e [funções relacionadas, wfindnext e FindNext](../Topic/_findnext,%20_findnext32,%20_findnext32i64,%20_findnext64,%20_findnext64i32,%20_findnexti64,%20_wfindnext,%20_wfindnext32,%20_wfindnext32i64,%20_wfindnext64,%20_wfindnext64i32,%20_wfindnexti64.md).  Consulte [Funções de pesquisa de nome de arquivo](../c-runtime-library/filename-search-functions.md) para obter informações sobre membros de estrutura.|IO.H, WCHAR.H|  
|`_FPIEEE_RECORD` estrutura|Contém informações que pertencem à exceção de ponto flutuante IEEE; passadas para o manipulador de interceptação definido pelo usuário por [\_fpieee\_flt](../c-runtime-library/reference/fpieee-flt.md).|FPIEEE.H|  
|`fpos_t` \(inteiro longo, `__int64`, ou estrutura, dependendo da plataforma de destino\)|Usado por [fgetpos](../c-runtime-library/reference/fgetpos.md) e [fsetpos](../Topic/fsetpos.md) para registrar informações para especificar exclusivamente cada posição dentro de um arquivo.|STDIO.H|  
|`_fsize_t` \(inteiro longo sem sinal\)|Usado para representar o tamanho de um arquivo.|IO.H,<br /><br /> WCHAR.H|  
|Estrutura `_HEAPINFO`|Contém informações sobre a próxima entrada do heap para [\_heapwalk](../Topic/_heapwalk.md).|MALLOC.H|  
|`_HFILE` \(nulo \*\)|Um identificador de arquivo do sistema operacional.|CRTDBG.H|  
|`imaxdiv_t`|O tipo do valor retornado pelo [imaxdiv](../c-runtime-library/reference/imaxdiv.md) função, contendo o quociente e o restante.|inttypes.h|  
|`ino_t`, `_ino_t` \(curto sem sinal\)|Para retornar informações de status.|WCHAR.H|  
|`intmax_t`|Um tipo de inteiro com sinal capaz de representar qualquer valor de qualquer tipo de inteiro com sinal.|stdint.h|  
|`intptr_t` \(inteiro longo ou `__int64`, dependendo da plataforma de destino\)|Armazena um ponteiro \(ou IDENTIFICADOR\) em plataformas Win32 e Win64.|STDDEF.H e outros arquivos de inclusão|  
|Matriz `jmp_buf`|Usada por [setjmp](../c-runtime-library/reference/setjmp.md) e [longjmp](../c-runtime-library/reference/longjmp.md) para salvar e restaurar o ambiente do programa.|SETJMP.H|  
|Estrutura `lconv`|Contém regras de formatação para valores numéricos em países\/regiões diferentes.  Usado por [localeconv](../c-runtime-library/reference/localeconv.md).|LOCALE.H|  
|`_LDOUBLE`,<br /><br /> `_LONGDOUBLE`,<br /><br /> `_LDBL12` \(double longo ou uma matriz unsigned char\)|Use para representar um valor double longo.|STDLIB.H|  
|Estrutura `_locale_t`|Armazena valores da localidade atual; usada em todas as bibliotecas CRT específicas da localidade.|CRTDEF.H|  
|`mbstate_t`|Controla o estado de uma conversão de caracteres de vários bytes.|WCHAR.H|  
|`off_t`, inteiro longo `_off_t`|Representa o valor de deslocamento do arquivo.|WCHAR.H, SYS\\TYPES.H|  
|`_onexit_t`,<br /><br /> Ponteiro `_onexit_m_t`|Retornado por [\_onexit, \_onexit\_m](../c-runtime-library/reference/onexit-onexit-m.md).|STDLIB.H|  
|Ponteiro para função `_PNH`|Tipo de argumento para [\_set\_new\_handler](../Topic/_set_new_handler.md).|NEW.H|  
|`ptrdiff_t` \(inteiro longo ou `__int64`, dependendo da plataforma de destino\)|Resultado da subtração de dois ponteiros.|CRTDEFS.H|  
|`_purecall_handler`,<br /><br /> `_purecall_handler_m`|Uma definição de tipo para uma função call\-back que é chamada quando uma função virtual pura é chamada.  Usado por [\_get\_purecall\_handler, set\_purecall\_handler](../c-runtime-library/reference/get-purecall-handler-set-purecall-handler.md).  Uma função `_purecall_handler` deve ter um tipo de retorno nulo.|STDLIB.H|  
|Definição de tipo `_RTC_error_fn`|Uma definição de tipo para uma função que trata verificações de erro no tempo de execução.  Usada em [\_RTC\_SetErrorFunc](../c-runtime-library/reference/rtc-seterrorfunc.md).|RTCAPI.H|  
|Definição de tipo `_RTC_error_fnW`|Uma definição de tipo para uma função que trata verificações de erro no tempo de execução.  Usado em [\_RTC\_SetErrorFuncW](../c-runtime-library/reference/rtc-seterrorfuncw.md).|RTCAPI.H|  
|Enumeração `_RTC_ErrorNumber`|Define as condições de erro para [\_RTC\_GetErrDesc](../c-runtime-library/reference/rtc-geterrdesc.md) e [RTC\_SetErrorType](../Topic/_RTC_SetErrorType.md).|RTCAPI.H|  
|`_se_translator_function`|Uma definição de tipo para uma função call\-back que converte uma exceção.  O primeiro parâmetro é o código de exceção e o segundo parâmetro é o registro de exceção.  Usado por [\_set\_se\_translator](../c-runtime-library/reference/set-se-translator.md).|EH.H|  
|Inteiro `sig_atomic_t`|Tipo de objeto que pode ser modificado como entidade atômica, mesmo na presença de interrupções assíncronas; usado com [signal](../c-runtime-library/reference/signal.md).|SIGNAL.H|  
|`size_t` \(\_\_int64 sem sinal ou inteiro sem sinal, dependendo da plataforma de destino\)|Resultado do operador  `sizeof`.|CRTDEFS.H e outros arquivos de inclusão|  
|Estrutura `_stat`|Contém informações de status do arquivo retornadas por [\_stat](../c-runtime-library/reference/stat-functions.md) e [\_fstat](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md).|SYS\\STAT.H|  
|Estrutura `__stat64`|Contém informações de status do arquivo retornadas por [\_fstat64](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md), [\_stat64](../c-runtime-library/reference/stat-functions.md) e [\_wstat64](../c-runtime-library/reference/stat-functions.md).|SYS\\STAT.H|  
|Estrutura `_stati64`|Contém informações de status do arquivo retornadas por [\_fstati64](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md), [\_stati64](../c-runtime-library/reference/stat-functions.md) e [\_wstati64](../c-runtime-library/reference/stat-functions.md).|SYS\\STAT.H|  
|Definição de tipo `terminate_function`|Uma definição de tipo para uma função call\-back que é chamada quando [terminate](../c-runtime-library/reference/terminate-crt.md) é chamado.  Usado por [set\_terminate](../c-runtime-library/reference/set-terminate-crt.md).|EH.H|  
|`time_t` \(\_\_int64 ou inteiro longo\)|Representa valores de hora em [mktime](../Topic/mktime,%20_mktime32,%20_mktime64.md), [tempo](../Topic/time,%20_time32,%20_time64.md), [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md), [ctime\_s, \_ctime32\_s, \_ctime64\_s, \_wctime\_s, \_wctime32\_s, \_wctime64\_s](../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md), [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md) e [gmtime, \_gmtime32, \_gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md).  O número de segundos desde 1º de janeiro de 1970, 0:00 UTC.  Se \_USE\_32BIT\_TIME\_T for definido, `time_t` será um inteiro longo.  Se não for definido, será um inteiro de 64 bits.|TIME.H,<br /><br /> SYS\\STAT.H,<br /><br /> SYS\\TIMEB.H|  
|`__time32_t` \(inteiro longo\)|Representa valores de hora em [mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md), [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md), [ctime\_s, \_ctime32\_s, \_ctime64\_s, \_wctime\_s, \_wctime32\_s, \_wctime64\_s](../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md), [gmtime, \_gmtime32, \_gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) e [localtime, \_localtime32, \_localtime64](../c-runtime-library/reference/localtime-localtime32-localtime64.md).|CRTDEFS.H, SYS\\STAT.H,<br /><br /> SYS\\TIMEB.H|  
|`__time64_t` \(`__int64`\)|Representa valores de hora em [mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md), [ctime64, wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md), [ctime\_s, \_ctime32\_s, \_ctime64\_s, \_wctime\_s, \_wctime32\_s, \_wctime64\_s](../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md), [gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md), [localtime64](../c-runtime-library/reference/localtime-localtime32-localtime64.md) e [time64](../Topic/time,%20_time32,%20_time64.md).|TIME.H,<br /><br /> SYS\\STAT.H,<br /><br /> SYS\\TIMEB.H|  
|Estrutura `_timeb`|Usado por [ftime](../c-runtime-library/reference/ftime-ftime32-ftime64.md) e [\_ftime\_s, \_ftime32\_s, \_ftime64\_s](../Topic/_ftime_s,%20_ftime32_s,%20_ftime64_s.md) para armazenar a hora atual do sistema.|SYS\\TIMEB.H|  
|Estrutura `__timeb32`|Usado por [\_ftime, \_ftime32, \_ftime64](../c-runtime-library/reference/ftime-ftime32-ftime64.md) e [\_ftime\_s, \_ftime32\_s, \_ftime64\_s](../Topic/_ftime_s,%20_ftime32_s,%20_ftime64_s.md) para armazenar a hora atual do sistema.|SYS\\TIMEB.H|  
|Estrutura `__timeb64`|Usado por [ftime64](../c-runtime-library/reference/ftime-ftime32-ftime64.md) e [\_ftime\_s, \_ftime32\_s, \_ftime64\_s](../Topic/_ftime_s,%20_ftime32_s,%20_ftime64_s.md) para armazenar a hora atual do sistema.|SYS\\TIMEB.H|  
|Estrutura `tm`|Usado por [asctime, \_wasctime](../c-runtime-library/reference/asctime-wasctime.md), [asctime\_s, \_wasctime\_s](../c-runtime-library/reference/asctime-s-wasctime-s.md), [gmtime, \_gmtime32, \_gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md), [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md), [localtime, \_localtime32, \_localtime64](../c-runtime-library/reference/localtime-localtime32-localtime64.md), [localtime\_s, \_localtime32\_s, \_localtime64\_s](../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md), [mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md) e [strftime, wcsftime, \_strftime\_l, \_wcsftime\_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para armazenar e recuperar informações de tempo.|TIME.H|  
|`uintmax_t`|Um tipo de inteiro sem sinal capaz de representar qualquer valor de qualquer tipo de inteiro sem sinal.|stdint.h|  
|`uintptr_t` \(inteiro longo ou `__int64`, dependendo da plataforma de destino\)|Um inteiro sem sinal ou uma versão \_\_int64 sem sinal de `intptr_t`.|STDDEF.H e outros arquivos de inclusão|  
|`unexpected_function`|Uma definição de tipo para uma função call\-back que é chamada quando [unexpected](../Topic/unexpected%20\(CRT\).md) é chamado.  Usado por [set\_unexpected](../c-runtime-library/reference/set-unexpected-crt.md).|EH.H|  
|Estrutura `_utimbuf`|Armazena os horários de acesso e modificação usados por arquivos [utime, wutime](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md) e [\_futime, \_futime32, \_futime64](../c-runtime-library/reference/futime-futime32-futime64.md) para alterar as datas de modificação do arquivo.|SYS\\UTIME.H|  
|Estrutura `_utimbuf32`|Armazena os horários de acesso e modificação usados por arquivos [\_utime, \_utime32, \_utime64, \_wutime, \_wutime32, \_wutime64](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md) e [\_futime, \_futime32, \_futime64](../c-runtime-library/reference/futime-futime32-futime64.md) para alterar as datas de modificação do arquivo.|SYS\\UTIME.H|  
|Estrutura `__utimbuf64`|Usado por [\_utime64, \_wutime64](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md) e [\_futime64](../c-runtime-library/reference/futime-futime32-futime64.md) para armazenar a hora atual.|SYS\\UTIME.H|  
|Estrutura `va_list`|Usada para manter as informações necessárias pelas macros [va\_arg](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md) e [va\_end](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md).  A função chamada declara a variável de tipo `va_list` que pode ser passada como argumento para outra função.|STDARG.H,<br /><br /> CRTDEFS.H|  
|Caractere largo `wchar_t`|Útil para escrever programas portáteis para mercados internacionais.|STDDEF.H, STDLIB.H,<br /><br /> CRTDEFS.H,<br /><br /> SYS\\STAT.H|  
|Inteiro `wctrans_t`|Representa mapeamentos de caracteres específicos da localidade.|WCTYPE.H|  
|Inteiro `wctype_t`|Pode representar todos os caracteres do conjunto de caracteres de qualquer idioma.|WCHAR.H,<br /><br /> CRTDEFS.H|  
|Inteiro `wint_t`|Tipo de objeto de dados que pode conter qualquer caractere largo ou valor de fim de arquivo largo.|WCHAR.H,<br /><br /> CRTDEFS.H|  
  
## Consulte também  
 [Referência da biblioteca em tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md)