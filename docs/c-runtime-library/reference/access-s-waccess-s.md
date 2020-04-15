---
title: _access_s, _waccess_s
ms.date: 4/2/2020
api_name:
- _access_s
- _waccess_s
- _o__access_s
- _o__waccess_s
api_location:
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- waccess_s
- access_s
- _waccess_s
- _access_s
helpviewer_keywords:
- access_s function
- taccess_s function
- _taccess_s function
- waccess_s function
- _access_s function
- _waccess_s function
ms.assetid: fb3004fc-dcd3-4569-8b27-d817546e947e
ms.openlocfilehash: 7f16951b99eb29bcb8c39499c29be1018cb86616
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81349134"
---
# <a name="_access_s-_waccess_s"></a>_access_s, _waccess_s

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

*Modo*<br/>
Configuração de permissão.

## <a name="return-value"></a>Valor retornado

Cada função retorna 0 se o arquivo tem o modo determinado. A função retorna um código de erro se o arquivo nomeado não existe ou não está acessível no modo determinado. Nesse caso, a função retorna um código de erro do conjunto da seguinte maneira e também define `errno` com o mesmo valor.

|Valor errno|Condição|
|-|-|
`EACCES`|Acesso negado. A configuração de permissão do arquivo não permite o acesso especificado.
`ENOENT`|Nome ou caminho do arquivo não encontrado.
`EINVAL`|Parâmetro inválido.

Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Quando usado com arquivos, a função **_access_s** determina se o arquivo especificado existe e pode ser acessado conforme especificado pelo valor do *modo*. Quando usado com diretórios, **_access_s** determina apenas se o diretório especificado existe. No Windows 2000 e posteriores sistemas operacionais, todos os diretórios têm acesso a leitura e gravação.

|valor do modo|Verifica o arquivo quanto a|
|----------------|---------------------|
|00|Existência apenas.|
|02|Permissão de gravação.|
|04|Permissão de leitura.|
|06|Permissão de leitura e gravação.|

A permissão para ler ou gravar o arquivo não é suficiente para garantir a capacidade de abrir um arquivo. Por exemplo, se um arquivo é bloqueado por outro processo, ele pode não estar acessível mesmo **que _access_s** retorna 0.

**_waccess_s** é uma versão de grande caráter de **_access_s**, onde o argumento de *caminho* para **_waccess_s** é uma seqüência de caracteres amplo. Caso contrário, **_waccess_s** e **_access_s** se comportem de forma idêntica.

Essas funções validam seus parâmetros. Se *o caminho* for NULO ou o *modo* não especificar um modo válido, o manipulador de parâmetros inválidos será invocado, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|`_taccess_s`|**_access_s**|**_access_s**|**_waccess_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_access_s**|\<io.h>|\<errno.h>|
|**_waccess_s**|\<wchar.h> ou \<io.h>|\<errno.h>|

## <a name="example"></a>Exemplo

Este exemplo usa **_access_s** para verificar o arquivo chamado crt_access_s.c para ver se ele existe e se a escrita é permitida.

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

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_access, _waccess](access-waccess.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[Funções _stat, _wstat](stat-functions.md)
