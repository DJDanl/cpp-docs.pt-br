---
title: Funções obsoletas
ms.date: 11/04/2016
f1_keywords:
- is_wctype
- _loaddll
- _unloaddll
- _getdllprocaddr
- _seterrormode
- _beep
- _sleep
- _getsystime
- corecrt_wctype/is_wctype
- process/_loaddll
- process/_unloaddll
- process/_getdllprocaddr
- stdlib/_seterrormode
- stdlib/_beep
- stdlib/_sleep
- time/_getsystime
- time/_setsystime
helpviewer_keywords:
- obsolete functions
- _beep function
- _sleep function
- _seterrormode function
ms.assetid: 8e14c2d4-1481-4240-8586-47eb43db02b0
ms.openlocfilehash: 2f42593620c3457694bd57ccdc5a90216b3a28f1
ms.sourcegitcommit: c85c8a1226d8fbbaa29f4691ed719f8e6cc6575c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2019
ms.locfileid: "54893880"
---
# <a name="obsolete-functions"></a>Funções obsoletas

Determinadas funções de biblioteca são obsoletas e têm equivalentes mais recentes. Recomendamos que você altere-as para as versões atualizadas. Outras funções obsoletas foram removidas do CRT. Este tópico lista as funções preteridas como obsoletas e as funções removidas em uma versão específica do Visual Studio.

## <a name="deprecated-as-obsolete-in-visual-studio-2015"></a>Preteridas como obsoletas no Visual Studio 2015

|Função obsoleta|Alternativa|
|-----------------------|-----------------|
|`is_wctype`|[iswctype](../c-runtime-library/reference/isctype-iswctype-isctype-l-iswctype-l.md)|
|`_loaddll`|[LoadLibrary](/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya), [LoadLibraryEx](/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) ou [LoadPackagedLibrary](/windows/desktop/api/winbase/nf-winbase-loadpackagedlibrary)|
|`_unloaddll`|[FreeLibrary](/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary)|
|`_getdllprocaddr`|[GetProcAddress](../build/getprocaddress.md)|
|`_seterrormode`|[SetErrorMode](https://msdn.microsoft.com/library/windows/desktop/ms680621)|
|`_beep`|[Beep](/windows/desktop/api/utilapiset/nf-utilapiset-beep)|
|`_sleep`|[Sleep](/windows/desktop/api/synchapi/nf-synchapi-sleep)|
|`_getsystime`|[GetLocalTime](/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlocaltime)|
|`_setsystime`|[SetLocalTime](/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setlocaltime)|

## <a name="removed-from-the-crt-in-visual-studio-2015"></a>Removida de CRT no Visual Studio 2015

|Função obsoleta|Alternativa|
|-----------------------|-----------------|
|[_cgets, _cgetws](../c-runtime-library/cgets-cgetws.md)|[_cgets_s, _cgetws_s](../c-runtime-library/reference/cgets-s-cgetws-s.md)|
|[gets, _getws](../c-runtime-library/gets-getws.md)|[gets_s, _getws_s](../c-runtime-library/reference/gets-s-getws-s.md)|
|[_get_output_format](../c-runtime-library/get-output-format.md)|Nenhum|
|[_heapadd](../c-runtime-library/heapadd.md)|Nenhum|
|[_heapset](../c-runtime-library/heapset.md)|Nenhum|
|[inp, inpw](../c-runtime-library/inp-inpw.md)|Nenhum|
|[_inp, _inpw, _inpd](../c-runtime-library/inp-inpw-inpd.md)|Nenhum|
|[outp, outpw](../c-runtime-library/outp-outpw.md)|Nenhum|
|[_outp, _outpw, _outpd](../c-runtime-library/outp-outpw-outpd.md)|Nenhum|
|[_set_output_format](../c-runtime-library/set-output-format.md)|Nenhum|

## <a name="removed-from-the-crt-in-earlier-versions-of-visual-studio"></a>Removida do CRT nas versões anteriores do Visual Studio

[_lock](../c-runtime-library/lock.md)

[_unlock](../c-runtime-library/unlock.md)