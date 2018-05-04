---
title: _access, _waccess | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _access
- _waccess
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
- _waccess
- _access
- taccess
- waccess
- _taccess
dev_langs:
- C++
helpviewer_keywords:
- access function
- _taccess function
- waccess function
- _access function
- _waccess function
- taccess function
ms.assetid: ba34f745-85c3-49e5-a7d4-3590bd249dd3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 775d0b699c6ac9664bae8cd0e6e28438ef019e69
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="access-waccess"></a>_access, _waccess

Determina se um arquivo é somente leitura ou não. Há versões mais seguras disponíveis, consulte [access_s, waccess_s](access-s-waccess-s.md).

## <a name="syntax"></a>Sintaxe

```C
int _access(
   const char *path,
   int mode
);
int _waccess(
   const wchar_t *path,
   int mode
);
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Caminho do arquivo ou do diretório.

*modo*<br/>
Atributo de leitura/gravação.

## <a name="return-value"></a>Valor de retorno

Cada função retorna 0 se o arquivo tem o modo determinado. A função retornará -1 se o arquivo não existe ou não tem o modo determinado; Nesse caso, **errno** é definido como mostrado na tabela a seguir.

|||
|-|-|
**EACCES**|Acesso negado: a configuração de permissão do arquivo não permite o acesso especificado.
**ENOENT**|Nome ou caminho do arquivo não encontrado.
**EINVAL**|Parâmetro inválido.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Quando usado com arquivos, o **Access** função determina se o arquivo ou diretório especificado existe e se tem os atributos especificados pelo valor de *modo*. Quando usado com diretórios, **Access** somente determina se o diretório especificado existe; no Windows 2000 e posterior sistemas operacionais, todos os diretórios leram e acesso de gravação.

|*modo* valor|Verifica o arquivo quanto a|
|------------------|---------------------|
|00|Existência apenas|
|02|Somente gravação|
|04|Somente leitura|
|06|Leitura e gravação|

Essa função apenas verifica se os arquivos e diretórios são somente leitura ou não, ela não verifica as configurações de segurança do sistema de arquivos. Para isso você precisa de um token de acesso. Para obter mais informações sobre a segurança do sistema de arquivos, consulte [Access Tokens (Tokens de acesso)](http://msdn.microsoft.com/library/windows/desktop/aa374909). Existe uma classe ATL para fornecer essa funcionalidade, consulte [Classe CAccessToken](../../atl/reference/caccesstoken-class.md).

**waccess** é uma versão de caractere largo de **Access**; o *caminho* argumento **waccess** é uma cadeia de caracteres largos. **waccess** e **Access** se comportam de forma idêntica caso contrário.

Essa função valida seus parâmetros. Se *caminho* é **nulo** ou *modo* não especificar um modo válido, o manipulador de parâmetro inválido é invocado, conforme descrito em [devalidaçãodeparâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, a função define **errno** para **EINVAL** e retorna -1.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**taccess**|**_access**|**_access**|**_waccess**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**_access**|\<io.h>|\<errno.h>|
|**_waccess**|\<wchar.h> ou \<io.h>|\<errno.h>|

## <a name="example"></a>Exemplo

O exemplo a seguir usa **Access** para verificar se o arquivo chamado crt_ACCESS. C para ver se ele existe e se a gravação é permitida.

```C
// crt_access.c
// compile with: /W1
// This example uses _access to check the file named
// crt_ACCESS.C to see if it exists and if writing is allowed.

#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>

int main( void )
{
    // Check for existence.
    if( (_access( "crt_ACCESS.C", 0 )) != -1 )
    {
        printf_s( "File crt_ACCESS.C exists.\n" );

        // Check for write permission.
        // Assume file is read-only.
        if( (_access( "crt_ACCESS.C", 2 )) == -1 )
            printf_s( "File crt_ACCESS.C does not have write permission.\n" );
    }
}
```

```Output
File crt_ACCESS.C exists.
File crt_ACCESS.C does not have write permission.
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[Funções _stat, _wstat](stat-functions.md)<br/>
