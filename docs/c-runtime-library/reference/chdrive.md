---
title: _chdrive | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _chdrive
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- chdrive
- _chdrive
dev_langs:
- C++
helpviewer_keywords:
- drives, changing
- _chdrive function
- chdrive function
ms.assetid: 212a1a4b-4fa8-444e-9677-7fca4c8c47e3
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1290f5a29ce2b6d80f98889fbb0fc5709cfa43e4
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="chdrive"></a>_chdrive
Altera a unidade de trabalho atual.  
  
> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _chdrive(   
   int drive   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `drive`  
 Um inteiro de 1 a 26 que especifica a unidade de trabalho atual (1 = A, B = 2 e assim por diante).  
  
## <a name="return-value"></a>Valor de retorno  
 Zero (0) se a unidade de trabalho atual tiver sido alterada com sucesso; caso contrário, -1.  
  
## <a name="remarks"></a>Comentários  
 Se `drive` não estiver no intervalo de 1 a 26, o manipulador de parâmetro inválido será invocado conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função **_chdrive** retornará -1, `errno` será definido como `EACCES` e `_doserrno` será definido como `ERROR_INVALID_DRIVE`.  
  
 A função **_chdrive** não é thread-safe porque ela depende da função **SetCurrentDirectory**, que, em si, não é thread-safe. Para usar **_chdrive** com segurança em um aplicativo multithread, você deve fornecer sua própria sincronização de thread. Para obter mais informações, vá para a [Biblioteca MSDN](http://go.microsoft.com/fwlink/p/?linkid=150542) e pesquise por **SetCurrentDirectory**.  
  
 A função **_chdrive** altera somente unidade de trabalho atual;  **_chdir** altera o diretório de trabalho atual.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|**_chdrive**|\<direct.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo de [_getdrive](../../c-runtime-library/reference/getdrive.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [_chdir, _wchdir](../../c-runtime-library/reference/chdir-wchdir.md)   
 [_fullpath, _wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [_getcwd, _wgetcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)   
 [_getdrive](../../c-runtime-library/reference/getdrive.md)   
 [_mkdir, _wmkdir](../../c-runtime-library/reference/mkdir-wmkdir.md)   
 [_rmdir, _wrmdir](../../c-runtime-library/reference/rmdir-wrmdir.md)   
 [system, _wsystem](../../c-runtime-library/reference/system-wsystem.md)