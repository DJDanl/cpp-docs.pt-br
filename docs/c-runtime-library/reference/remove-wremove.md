---
title: remove, _wremove | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _wremove
- remove
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
- remove
- _wremove
- _tremove
dev_langs:
- C++
helpviewer_keywords:
- tremove function
- _wremove function
- files [C++], deleting
- _tremove function
- files [C++], removing
- wremove function
- remove function
ms.assetid: b6345ec3-3289-4645-93a4-28b9e478cc19
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 97c258d79af8247af993732405d2c792a0822075
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="remove-wremove"></a>remove, _wremove

Excluir um arquivo.

## <a name="syntax"></a>Sintaxe

```C
int remove(
   const char *path
);
int _wremove(
   const wchar_t *path
);
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Caminho do arquivo a ser removido.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retornará 0 se o arquivo for excluído com êxito. Caso contrário, retornará -1 e define **errno** para **EACCES** para indicar que o caminho Especifica um arquivo somente leitura ou o arquivo está aberto, ou **ENOENT** para indicar que o nome do arquivo ou caminho não foi encontrado ou o caminho Especifica um diretório.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

A função **remove** exclui o arquivo especificado por *path.* **wremove** é uma versão de caractere largo de **remover**; o *caminho* argumento **wremove** é uma cadeia de caracteres largos. **wremove** e **remover** se comportam de forma idêntica caso contrário. Todos os manipuladores de um arquivo devem ser fechados para que ele possa ser excluído.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tremove**|**remove**|**remove**|**_wremove**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**remove**|\<stdio.h> ou \<io.h>|
|**_wremove**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_remove.c
/* This program uses remove to delete crt_remove.txt */

#include <stdio.h>

int main( void )
{
   if( remove( "crt_remove.txt" ) == -1 )
      perror( "Could not delete 'CRT_REMOVE.TXT'" );
   else
      printf( "Deleted 'CRT_REMOVE.TXT'\n" );
}
```

### <a name="input-crtremovetxt"></a>Entrada: crt_remove.txt

```Input
This file will be deleted.
```

### <a name="sample-output"></a>Saída de Exemplo

```Output
Deleted 'CRT_REMOVE.TXT'
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_unlink, _wunlink](unlink-wunlink.md)<br/>
