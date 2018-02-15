---
title: _getdcwd, _wgetdcwd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _getdcwd
- _wgetdcwd
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wgetdcwd
- getdcwd
- _getdcwd
- tgetdcwd
- _wgetdcwd
- _tgetdcwd
dev_langs:
- C++
helpviewer_keywords:
- wgetdcwd function
- working directory
- getdcwd function
- _getdcwd function
- _wgetdcwd function
- current working directory
- directories [C++], current working
ms.assetid: 184152f5-c7b0-495b-918d-f9a6adc178bd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b74cc20c6f96381d445740db9d41828f28d5a53a
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="getdcwd-wgetdcwd"></a>_getdcwd, _wgetdcwd
Obtém o caminho completo do diretório de trabalho atual na unidade especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_getdcwd(   
   int drive,  
   char *buffer,  
   int maxlen   
);  
wchar_t *_wgetdcwd(   
   int drive,  
   wchar_t *buffer,  
   int maxlen   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `drive`  
 Um inteiro não negativo que especifica a unidade (0 = unidade padrão, 1 = A, 2 = B e assim por diante).  
  
 Se a unidade especificada não estiver disponível ou o tipo da unidade (por exemplo, removível, fixo, CD-ROM, disco RAM ou unidade de rede) não puder ser determinado, o manipulador de parâmetro inválido, que é descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md), é invocado.  
  
 `buffer`  
 Local de armazenamento para o caminho ou **NULL**.  
  
 Se **NULL** for especificado, esta função alocará um buffer de pelo menos `maxlen` usando **malloc** e o valor retornado de `_getdcwd` será um ponteiro para o buffer alocado. O buffer pode ser liberado chamando `free` e passando o ponteiro para ele.  
  
 `maxlen`  
 Um inteiro positivo diferente de zero que especifica o tamanho máximo do caminho em caracteres: `char` para `_getdcwd` e `wchar_t` para `_wgetdcwd`.  
  
 Se `maxlen` não for maior que zero, o manipulador de parâmetro inválido, que é descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md), será invocado.  
  
## <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma cadeia de caracteres que representa o caminho completo do diretório de trabalho atual na unidade especificada ou `NULL`, que indica um erro.  
  
 Se `buffer` for especificado como `NULL` e não houver memória suficiente para alocar caracteres `maxlen`, ocorrerá um erro e `errno` será definido como `ENOMEM`. Se o tamanho do caminho, que inclui o caractere nulo de terminação, ultrapassar `maxlen`, ocorrerá um erro e `errno` será definido como `ERANGE`. Para obter mais informações sobre esses códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_getdcwd` obtém o caminho completo do diretório de trabalho atual na unidade especificada e o armazena em `buffer`. Se o diretório de trabalho atual estiver definido como o raiz, a cadeia de caracteres terminará com uma barra invertida (\\). Se o diretório de trabalho atual estiver definido como um diretório que não seja o raiz, a cadeia de caracteres terminará com o nome do diretório e não com uma barra invertida.  
  
 `_wgetdcwd` é uma versão de caractere largo de `_getdcwd`; seu parâmetro `buffer` e o valor retornado são cadeias de caracteres largos. Caso contrário, `_wgetdcwd` e `_getdcwd` comportam-se de modo idêntico.  
  
 Essa função é thread-safe, embora dependa de **GetFullPathName**, que não thread-safe. No entanto, você pode violar o acesso thread-safe se seu aplicativo multi-threaded chamar essa função e **GetFullPathName**. Para obter mais informações, vá até a [Biblioteca MSDN](http://go.microsoft.com/fwlink/p/?linkid=150542) e pesquise por **GetFullPathName**.  
  
 A versão dessa função que tem o sufixo `_nolock` se comporta de forma idêntica a essa função, exceto pelo fato de não ser thread-safe e não estar protegida contra interferência de outros threads. Para obter mais informações, consulte [_getdcwd_nolock, _wgetdcwd_nolock](../../c-runtime-library/reference/getdcwd-nolock-wgetdcwd-nolock.md).  
  
 Quando `_DEBUG` e `_CRTDBG_MAP_ALLOC` são definidos, chamadas para `_getdcwd` e `_wgetdcwd` são substituídos por chamadas para `_getdcwd_dbg` e `_wgetdcwd_dbg`, para que você possa depurar alocações de memória. Para obter mais informações, consulte [_getdcwd_dbg, _wgetdcwd_dbg](../../c-runtime-library/reference/getdcwd-dbg-wgetdcwd-dbg.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tgetdcwd`|`_getdcwd`|`_getdcwd`|`_wgetdcwd`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_getdcwd`|\<direct.h>|  
|`_wgetdcwd`|\<direct.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo em [_getdrive](../../c-runtime-library/reference/getdrive.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [_chdir, _wchdir](../../c-runtime-library/reference/chdir-wchdir.md)   
 [_getcwd, _wgetcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)   
 [_getdrive](../../c-runtime-library/reference/getdrive.md)   
 [_mkdir, _wmkdir](../../c-runtime-library/reference/mkdir-wmkdir.md)   
 [_rmdir, _wrmdir](../../c-runtime-library/reference/rmdir-wrmdir.md)