---
title: "Variáveis globais | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.variables
dev_langs:
- C++
helpviewer_keywords:
- global variables
- variables, global
- global variables, Microsoft run-time library
ms.assetid: 01d1551c-2f0c-4f72-935c-6442caccf84f
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 5ca2249ca9011f8e00116441820af135492d3122
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="global-variables"></a>Variáveis globais
A biblioteca de tempo de execução C da Microsoft fornece as macros ou as variáveis globais a seguir. Diversas delas foram preteridas e versões funcionais mais seguras foram adotadas. Recomendamos que você use as novas versões, em vez das variáveis globais.  
  
|Variável|Descrição|  
|--------------|-----------------|  
|[__argc, \__argv, \__wargv](../c-runtime-library/argc-argv-wargv.md)|Contém os argumentos da linha de comando.|  
|[_daylight, _dstbias, _timezone, and _tzname](../c-runtime-library/daylight-dstbias-timezone-and-tzname.md)|Preterido. Use `_get_daylight`, `_get_dstbias`, `_get_timezone` e `_get_tzname`.<br /><br /> Ajusta a hora local; usada em algumas funções de data e hora.|  
|[errno, _doserrno, _sys_errlist e _sys_nerr](../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)|Preterido. Use `_get_errno`, `_set_errno`, `_get_doserrno`, `_set_doserrno`, `perror` e `strerror`.<br /><br /> Armazena códigos de erros e informações relacionadas.|  
|[_environ, _wenviron](../c-runtime-library/environ-wenviron.md)|Preterido. Use `getenv_s`, `_wgetenv_s`, `_dupenv_s`, `_wdupenv_s`, `_putenv_s` e `_wputenv_s`.<br /><br /> Ponteiros para matrizes de ponteiros para cadeias de caracteres do ambiente do processo; iniciada na inicialização.|  
|[_fmode](../c-runtime-library/fmode.md)|Preterido. Use `_get_fmode` ou `_set_fmode`.<br /><br /> Define o modo padrão de conversão do arquivo.|  
|[_iob](../c-runtime-library/iob.md)|Matriz de estruturas de controle de E/S para console, arquivos e dispositivos.|  
|[_pctype, _pwctype, _wctype, _mbctype, _mbcasemap](../c-runtime-library/pctype-pwctype-wctype-mbctype-mbcasemap.md)|Contém informações usadas por funções de classificação de caracteres.|  
|[_pgmptr, _wpgmptr](../c-runtime-library/pgmptr-wpgmptr.md)|Preterido. Use `_get_pgmptr` ou `_get_wpgmptr`.<br /><br /> Iniciada na inicialização do programa para o caminho completamente qualificado ou relativo do programa, o nome completo do programa ou o nome do programa sem a extensão do nome do arquivo, dependendo do modo como o programa foi invocado.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca em tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)   
 [__argc, \__argv, \__wargv](../c-runtime-library/argc-argv-wargv.md)   
 [_get_daylight](../c-runtime-library/reference/get-daylight.md)   
 [_get_dstbias](../c-runtime-library/reference/get-dstbias.md)   
 [_get_timezone](../c-runtime-library/reference/get-timezone.md)   
 [_get_tzname](../c-runtime-library/reference/get-tzname.md)   
 [perror](../c-runtime-library/reference/perror-wperror.md)   
 [strerror](../c-runtime-library/reference/strerror-strerror-wcserror-wcserror.md)   
 [_get_doserrno](../c-runtime-library/reference/get-doserrno.md)   
 [_set_doserrno](../c-runtime-library/reference/set-doserrno.md)   
 [_get_errno](../c-runtime-library/reference/get-errno.md)   
 [_set_errno](../c-runtime-library/reference/set-errno.md)   
 [_dupenv_s, _wdupenv_s](../c-runtime-library/reference/dupenv-s-wdupenv-s.md)   
 [getenv, _wgetenv](../c-runtime-library/reference/getenv-wgetenv.md)   
 [getenv_s, _wgetenv_s](../c-runtime-library/reference/getenv-s-wgetenv-s.md)   
 [_putenv, _wputenv](../c-runtime-library/reference/putenv-wputenv.md)   
 [_putenv_s, _wputenv_s](../c-runtime-library/reference/putenv-s-wputenv-s.md)   
 [_get_fmode](../c-runtime-library/reference/get-fmode.md)   
 [_set_fmode](../c-runtime-library/reference/set-fmode.md)
