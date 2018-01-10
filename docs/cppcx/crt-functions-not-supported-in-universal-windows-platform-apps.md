---
title: "Funções de CRT sem suporte em aplicativos de plataforma Universal do Windows | Microsoft Docs"
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: cbfc957d-6c60-48f4-97e3-1ed8526743b4
caps.latest.revision: "15"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 65d058780ee71731559733ac07eef3f614a47784
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crt-functions-not-supported-in-universal-windows-platform-apps"></a>Funções de CRT sem suporte em aplicativos da Plataforma Universal do Windows
Muitas funções CRT (tempo de execução do C) não estão disponíveis quando você cria aplicativos UWP (Plataforma Universal do Windows). Em alguns casos, estão disponíveis soluções alternativas –-por exemplo, você pode usar o tempo de execução do Windows ou as APIs do Win32. No entanto, em outros casos, as funções de CRT foram proibidas, pois os recursos que correspondem a elas ou às APIs de suporte não são aplicáveis aos aplicativos UWP.  
  
 A tabela a seguir lista as funções de CRT que não estão disponíveis quando você compila aplicativos UWP e indica as soluções alternativas aplicáveis.  
  
## <a name="unsupported-crt-functions"></a>Funções CRT sem suporte  
  
||||  
|-|-|-|  
|_beep _sleep _seterrormode|Essas funções eram obsoletas em versões anteriores do CRT. Além disso, as APIs do Win32 correspondentes não estão disponíveis para aplicativos UWP.|Sem solução alternativa.|  
|chdir _chdrive getcwd|Essas funções são obsoletas ou não são thread-safe.|Use _chdir, _getcwd e funções relacionadas.|  
|_cgets _cgets_s _cgetws _cgetws_s _cprintf _cprintf_l _cprintf_p _cprintf_p_l _cprintf_s _cprintf_s_l _cputs _cputws _cscanf _cscanf_l _cscanf_s _cscanf_s_l _cwait _cwprintf _cwprintf_l _cwprintf_p _cwprintf_p_l _cwprintf_s _cwprintf_s_l _cwscanf _cwscanf_l _cwscanf_s _cwscanf_s_l _vcprintf _vcprintf_l _vcprintf_p _vcprintf_p_l _vcprintf_s _vcprintf_s_l _vcwprintf _vcwprintf_l _vcwprintf_p _vcwprintf_p_l _vcwprintf_s _vcwprintf_s_l _getch _getch_nolock _getche _getche_nolock _getwch _getwch_nolock _getwche _getwche_nolock _putch _putch_nolock _putwch _putwch_nolock _ungetch _ungetch_nolock _ungetwch _ungetwch_nolock _kbhit kbhit putch cgets cprintf cputs cscanf cwait getch getche ungetch|Essas funções são usadas para ler e gravar diretamente no e para o console. Os aplicativos UWP são apenas GUI; eles não dão suporte a console.|Sem solução alternativa.|  
|getpid|Essa função é obsoleta.|Use _getpid ou a API do Win32 `GetCurrentProcessId()`.|  
|_getdiskfree|Não disponível.|Use a API do Win32 `GetDiskFreeSpaceExW()`.|  
|_getdrive _getdrives|A API correspondente não está disponível para aplicativos UWP.|Sem solução alternativa.|  
|_inp _inpd _inpw _outp _outpd _outpw inp inpd inpw outp outpd outpw|Não há suporte para E/S da porta em aplicativos UWP.|Sem solução alternativa.|  
|_ismbcalnum _ismbcalnum_l _ismbcalpha _ismbcalpha_l _ismbcdigit _ismbcdigit_l _ismbcgraph _ismbcgraph_l _ismbchira _ismbchira_l _ismbckata _ismbckata_l _ismbcl0 _ismbcl0_l _ismbcl1 _ismbcl1_l _ismbcl2 _ismbcl2_l _ismbclegal _ismbclegal_l _ismbclower _ismbclower_l _ismbcprint _ismbcprint_l _ismbcpunct _ismbcpunct_l _ismbcspace _ismbcspace_l _ismbcsymbol _ismbcsymbol_l _ismbcupper _ismbcupper_l _mbbtombc _mbbtombc_l _mbbtype _mbbtype_l _mbccpy _mbccpy_l _mbccpy_s _mbccpy_s_l _mbcjistojms _mbcjistojms_l _mbcjmstojis _mbcjmstojis_l _mbclen _mbclen_l _mbctohira _mbctohira_l _mbctokata _mbctokata_l _mbctolower _mbctolower_l _mbctombb _mbctombb_l _mbctoupper _mbctoupper_l _mbsbtype _mbsbtype_l _mbscat _mbscat_l _mbscat_s _mbscat_s_l _mbschr _mbschr_l _mbscmp _mbscmp_l _mbscoll _mbscoll_l _mbscpy _mbscpy_l _mbscpy_s _mbscpy_s_l _mbscspn _mbscspn_l _mbsdec _mbsdec_l _mbsicmp _mbsicmp_l _mbsicoll _mbsicoll_l _mbsinc _mbsinc_l _mbslen _mbslen_l _mbslwr _mbslwr_l _mbslwr_s _mbslwr_s_l _mbsnbcat _mbsnbcat_l _mbsnbcat_s _mbsnbcat_s_l _mbsnbcmp _mbsnbcmp_l _mbsnbcnt _mbsnbcnt_l _mbsnbcoll _mbsnbcoll_l _mbsnbcpy _mbsnbcpy_l _mbsnbcpy_s _mbsnbcpy_s_l _mbsnbicmp _mbsnbicmp_l _mbsnbicoll _mbsnbicoll_l _mbsnbset _mbsnbset_l _mbsnbset_s _mbsnbset_s_l _mbsncat _mbsncat_l _mbsncat_s _mbsncat_s_l _mbsnccnt _mbsnccnt_l _mbsncmp _mbsncmp_l _mbsncoll _mbsncoll_l _mbsncpy _mbsncpy_l _mbsncpy_s _mbsncpy_s_l _mbsnextc _mbsnextc_l _mbsnicmp _mbsnicmp_l _mbsnicoll _mbsnicoll_l _mbsninc _mbsninc_l _mbsnlen _mbsnlen_l _mbsnset _mbsnset_l _mbsnset_s _mbsnset_s_l _mbspbrk _mbspbrk_l _mbsrchr _mbsrchr_l _mbsrev _mbsrev_l _mbsset _mbsset_l _mbsset_s _mbsset_s_l _mbsspn _mbsspn_l _mbsspnp _mbsspnp_l _mbsstr _mbsstr_l _mbstok _mbstok_l _mbstok_s _mbstok_s_l _mbsupr _mbsupr_l _mbsupr_s _mbsupr_s_l is_wctype|Não há suporte para cadeias de caracteres multibyte em aplicativos UWP.|Use cadeias de caracteres Unicode.|  
|_pclose _pipe _popen _wpopen|A funcionalidade de pipe não está disponível para aplicativos UWP.|Sem solução alternativa.|  
|_resetstkoflw|O suporte às APIs do Win32 não está disponível para aplicativos UWP.|Sem solução alternativa.|  
|_getsystime _setsystime|Elas eram APIs obsoletas em versões anteriores do CRT. Além disso, um usuário não pode definir a hora do sistema em um aplicativo UWP devido à falta de permissões.|Para apenas obter a hora do sistema, use a API do Win32 `GetSystemTime`. Não é possível definir a hora do sistema.|  
|_environ _putenv _putenv_s _searchenv _searchenv_s _dupenv_s _wputenv _wputenv_s _wsearchenv getenv getenv_s putenv _wdupenv_s _wenviron _wgetenv _wgetenv_s _wsearchenv_s tzset|As variáveis de ambiente não estão disponíveis para aplicativos UWP.|Sem solução alternativa. Para definir o fuso horário, use _tzset.|  
|_loaddll _getdllprocaddr _unloaddll|Elas eram funções obsoletas em versões anteriores do CRT. Além disso, o usuário não pode carregar DLLs, exceto as que estão no mesmo pacote de aplicativos.|Use as APIs do Win32 `LoadPackagedLibrary`, `GetProcAddress`e `FreeLibrary` para carregar e usar DLLs empacotadas.|  
|_wexecl _wexecle _wexeclp _wexeclpe _wexecv _wexecve _wexecvp _wexecvpe _execl _execle _execlp _execlpe _execv _execve _execvp _execvpe _spawnl _spawnle _spawnlp _spawnlpe _spawnv _spawnve _spawnvp _spawnvpe _wspawnl _wspawnle _wspawnlp _wspawnlpe _wspawnv _wspawnve _wspawnvp _wspawnvpe _wsystem execl execle execlp execlpe execv execve execvp execvpe spawnl spawnle spawnlp spawnlpe spawnv spawnve spawnvp spawnvpe system|A funcionalidade não está disponível em aplicativos UWP. Um aplicativo UWP não pode invocar outro aplicativo UWP ou um aplicativo de área de trabalho.|Sem solução alternativa.|  
|_heapwalk _heapadd _heapchk _heapset _heapused|Essas funções são normalmente usadas para funcionar com o heap. No entanto, não há suporte para as APIs do Win32 correspondentes em aplicativos UWP. Além disso, os aplicativos não podem mais criar ou usar heaps privados.|Sem solução alternativa. No entanto, o `_heapwalk` está disponível em DEBUG CRT, apenas para fins de depuração. Eles não são usados em aplicativos que são carregados na Windows Store.|  
  
 As funções a seguir estão disponíveis no CRT para aplicativos UWP, mas deve ser usadas somente quando o Win32 correspondente ou as APIs do Windows Runtime não pode ser usado, por exemplo, quando você estiver compatibilizando grandes bases de código  
  
|||  
|-|-|  
|Funções de cadeia de caracteres de um byte – por exemplo, `strcat`, `strcpy`, `strlwr`e assim por diante.|Tornar seus aplicativos uwp USEM estritamente Unicode porque todas as APIs do Win32 e APIs do Windows Runtime que são expostas usam apenas conjuntos de caracteres Unicode.  As funções de um byte foram deixadas para compatibilizar grandes bases de códigos, mas, de outra forma, devem ser evitadas e, em vez disso, as funções de caractere amplo correspondentes devem ser usadas, quando possível.|  
|Funções de E/S de transmissão e E/S de arquivo de nível baixo — por exemplo, `fopen`, `open`e assim por diante.|Essas funções são síncronas, o que não é recomendado para aplicativos UWP. Em seus aplicativos UWP, use APIs assíncronas para abrir, ler e gravar arquivos para evitar o bloqueio do thread da interface do usuário. Exemplos de APIs desse tipo são os contidos na classe `Windows::Storage::FileIO` .|  
  
## <a name="windows-8x-store-apps-and-windows-phone-8x-apps"></a>Aplicativos da Windows 8.x Store e aplicativos do Windows Phone 8.x  
 Além das APIs mencionadas anteriormente, as seguintes APIs não estão disponíveis em aplicativos da Windows 8.x Store e aplicativos do Windows Phone 8.x.  
  
||||  
|-|-|-|  
|_beginthread _beginthreadex _endthread _endthreadex|O threading de APIs do Win32 não está disponível em aplicativos do Windows 8.x da Loja.|Use o `Windows Runtime Windows::System::Threading::ThreadPool` ou `concurrency::task` em vez disso.|  
|_chdir _wchdir _getcwd _getdcwd _wgetcwd _wgetdcwd|O conceito de um diretório de trabalho não se aplica aos aplicativos do Windows 8.x da Loja.|Use caminhos completos.|  
|_getpid|Essa função era obsoleta em versões anteriores do CRT.|Use a API do Win32 `GetCurrentProcessId()`|  
|_isleadbyte_l _ismbbalnum, _ismbbalnum_l, _ismbbalpha, _ismbbalpha _ismbbalpha_l _ismbbgraph _ismbbgraph_l _ismbbkalnum _ismbbkalnum_l _ismbbkana _ismbbkana_l _ismbbkprint _ismbbkprint_l _ismbbkpunct _ismbbkpunct_l _ismbblead _ismbblead_l _ismbbprint _ismbbprint_l _ismbbpunct _ismbbpunct_l _ismbbtrail _ismbbtrail_l _ismbslead _ismbslead_l _ismbstrail _ismbstrail_l _mbsdup isleadbyte|Não há suporte para cadeias de caracteres multibyte em aplicativos da Windows 8.x Store.|Use cadeias de caracteres Unicode.|  
|_tzset|As variáveis de ambiente não estão disponíveis para aplicativos da Windows 8.x Store.|Sem solução alternativa.|  
|_get_heap_handle, _heapmin|Não há suporte para as APIs do Win32 correspondentes em aplicativos do Windows 8.x da Loja. Além disso, os aplicativos não podem mais criar heaps privados.|Sem solução alternativa. No entanto, o `_get_heap_handle` está disponível em DEBUG CRT, apenas para fins de depuração.|