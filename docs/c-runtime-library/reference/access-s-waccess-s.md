---
title: _access_s, _waccess_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _access_s
- _waccess_s
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
- waccess_s
- access_s
- _waccess_s
- _access_s
dev_langs:
- C++
helpviewer_keywords:
- access_s function
- taccess_s function
- _taccess_s function
- waccess_s function
- _access_s function
- _waccess_s function
ms.assetid: fb3004fc-dcd3-4569-8b27-d817546e947e
caps.latest.revision: 28
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ea1207187d2e65103c1dd6167be6a579f2df315d
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="accesss-waccesss"></a>_access_s, _waccess_s

Determina as permissões de leitura/gravação do arquivo. Esta é uma versão de [_access, _waccess](access-waccess.md) com melhorias de segurança, conforme a descrição em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _access_s(
   const char *path,
   int mode
);
errno_t _waccess_s(
   const wchar_t *path,
   int mode
);
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Caminho do arquivo ou do diretório.

*modo*<br/>
Configuração de permissão.

## <a name="return-value"></a>Valor de retorno

Cada função retorna 0 se o arquivo tem o modo determinado. A função retorna um código de erro se o arquivo nomeado não existe ou não está acessível no modo determinado. Nesse caso, a função retorna um código de erro do conjunto da seguinte maneira e também define **errno** com o mesmo valor.

|Valor errno|Condição|
|-|-|
**EACCES**|Acesso negado. A configuração de permissão do arquivo não permite o acesso especificado.
**ENOENT**|Nome ou caminho do arquivo não encontrado.
**EINVAL**|Parâmetro inválido.

Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Quando usado com arquivos, o **access_s** função determina se o arquivo especificado existe e pode ser acessado como especificado pelo valor de *modo*. Quando usado com diretórios, **access_s** somente determina se o diretório especificado existe. No Windows 2000 e sistemas operacionais posteriores, todos os diretórios de tem lido em acesso de gravação.

|valor do modo|Verifica o arquivo quanto a|
|----------------|---------------------|
|00|Existência apenas.|
|02|Permissão de gravação.|
|04|Permissão de leitura.|
|06|Permissão de leitura e gravação.|

A permissão para ler ou gravar o arquivo não é suficiente para garantir a capacidade de abrir um arquivo. Por exemplo, se um arquivo está bloqueado por outro processo, ele pode não ser acessado, embora **access_s** retornará 0.

**waccess_s** é uma versão de caractere largo de **access_s**, onde o *caminho* argumento **waccess_s** é uma cadeia de caracteres largos. Caso contrário, **waccess_s** e **access_s** se comportam de forma idêntica.

Essas funções validam seus parâmetros. Se *caminho* é **nulo** ou *modo* não especificar um modo válido, o manipulador de parâmetro inválido é invocado, conforme descrito em [devalidaçãodeparâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções definido **errno** para **EINVAL** e retornar **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**taccess_s**|**_access_s**|**_access_s**|**_waccess_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_access_s**|\<io.h>|\<errno.h>|
|**_waccess_s**|\<wchar.h> ou \<io.h>|\<errno.h>|

## <a name="example"></a>Exemplo

Este exemplo usa **access_s** para verificar se o arquivo chamado crt_access_s.c para ver se ele existe e se a gravação é permitida.

```C
// crt_access_s.c

#include <io.h>
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    errno_t err = 0;

    // Check for existence.
    if ((err = _access_s( "crt_access_s.c", 0 )) == 0 )
    {
        printf_s( "File crt_access_s.c exists.\n" );

        // Check for write permission.
        if ((err = _access_s( "crt_access_s.c", 2 )) == 0 )
        {
            printf_s( "File crt_access_s.c does have "
                      "write permission.\n" );
        }
        else
        {
            printf_s( "File crt_access_s.c does not have "
                      "write permission.\n" );
        }
    }
    else
    {
        printf_s( "File crt_access_s.c does not exist.\n" );
    }
}
```

```Output
File crt_access_s.c exists.
File crt_access_s.c does not have write permission.
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_access, _waccess](access-waccess.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[Funções _stat, _wstat](stat-functions.md)<br/>
