---
title: Funções Obsoletas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp
- devlang-cpp
ms.topic: conceptual
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
dev_langs:
- C++
helpviewer_keywords:
- obsolete functions
- _beep function
- _sleep function
- _seterrormode function
ms.assetid: 8e14c2d4-1481-4240-8586-47eb43db02b0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3d04265e27cd569b8b390bb19377a3111fbb9c8c
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42578329"
---
# <a name="obsolete-functions"></a>Funções obsoletas
Determinadas funções de biblioteca são obsoletas e têm equivalentes mais recentes. Recomendamos que você altere-as para as versões atualizadas. Outras funções obsoletas foram removidas do CRT. Este tópico lista as funções preteridas como obsoletas e as funções removidas em uma versão específica do Visual Studio.  
  
## <a name="deprecated-as-obsolete-in-visual-studio-2015"></a>Preteridas como obsoletas no Visual Studio 2015  
  
|Função obsoleta|Alternativa|  
|-----------------------|-----------------|  
|`is_wctype`|[iswctype](../c-runtime-library/reference/isctype-iswctype-isctype-l-iswctype-l.md)|  
|`_loaddll`|[LoadLibrary](http://go.microsoft.com/fwlink/p/?LinkID=259187), [LoadLibraryEx](http://go.microsoft.com/fwlink/p/?LinkID=236091) ou [LoadPackagedLibrary](/windows/desktop/api/winbase/nf-winbase-loadpackagedlibrary)|  
|`_unloaddll`|[FreeLibrary](http://go.microsoft.com/fwlink/p/?LinkID=259188)|  
|`_getdllprocaddr`|[GetProcAddress](../build/getprocaddress.md)|  
|`_seterrormode`|[SetErrorMode](http://go.microsoft.com/fwlink/p/?LinkID=255242)|  
|`_beep`|[Beep](https://msdn.microsoft.com/library/windows/desktop/ms679277\(v=vs.85\).aspx)|  
|`_sleep`|[Sleep](/windows/desktop/api/synchapi/nf-synchapi-sleep)|  
|`_getsystime`|[GetLocalTime](https://msdn.microsoft.com/library/windows/desktop/ms724338\(v=vs.85\).aspx)|  
|`_setsystime`|[SetLocalTime](https://msdn.microsoft.com/library/windows/desktop/ms724936\(v=vs.85\).aspx)|  
  
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