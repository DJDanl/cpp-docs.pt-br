---
title: _dupenv_s_dbg, _wdupenv_s_dbg
ms.date: 11/04/2016
api_name:
- _dupenv_s_dbg
- _wdupenv_s_dbg
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _tdupenv_s_dbg
- _dupenv_s_dbg
- _wdupenv_s_dbg
helpviewer_keywords:
- _tdupenv_s_dbg function
- dupenv_s_dbg function
- _wdupenv_s_dbg function
- environment variables
- tdupenv_s_dbg function
- wdupenv_s_dbg function
- _dupenv_s_dbg function
ms.assetid: e3d81148-e24e-46d0-a21d-fd87b5e6256c
ms.openlocfilehash: 6c61986184f93c6cf6e83b33f77dce2bd017cfae
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70937687"
---
# <a name="_dupenv_s_dbg-_wdupenv_s_dbg"></a>_dupenv_s_dbg, _wdupenv_s_dbg

Obter um valor do ambiente atual.  Versões do [_dupenv_s, _wdupenv_s](dupenv-s-wdupenv-s.md) que alocam memória com [_malloc_dbg](malloc-dbg.md) para fornecer informações adicionais de depuração.

## <a name="syntax"></a>Sintaxe

```C
errno_t _dupenv_s_dbg(
   char **buffer,
   size_t *numberOfElements,
   const char *varname,
   int blockType,
   const char *filename,
   int linenumber
);
errno_t _wdupenv_s_dbg(
   wchar_t **buffer,
   size_t * numberOfElements,
   const wchar_t *varname,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Buffer para armazenar o valor da variável.

*numberOfElements*<br/>
Tamanho do *buffer*.

*varname*<br/>
Nome da variável de ambiente.

*blockType*<br/>
Tipo solicitado do bloco de memória: **_CLIENT_BLOCK** ou **_NORMAL_BLOCK**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem ou **nulo**.

## <a name="return-value"></a>Valor de retorno

Zero em caso de êxito; código de erro em caso de falha.

Essas funções validam seus parâmetros; Se *buffer* ou *VarName* for **NULL**, o manipulador de parâmetro inválido será invocado conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções definirão **errno** como **EINVAL** e retornarão **EINVAL**.

Se essas funções não puderem alocar memória suficiente, elas definirão o *buffer* como **nulo** e *numberOfElements* como 0 e retornará **ENOMEM**.

## <a name="remarks"></a>Comentários

As funções **_dupenv_s_dbg** e **_wdupenv_s_dbg** são idênticas a **_dupenv_s** e **_wdupenv_s** , exceto que, quando **_DEBUG** é definido, essas funções usam a versão de depuração de [malloc](malloc.md), [_malloc_dbg](malloc-dbg.md), para alocar memória para o valor da variável de ambiente. Para obter informações sobre os recursos de depuração do **_malloc_dbg**, consulte [_malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir o sinalizador **_CRTDBG_MAP_ALLOC**. Quando **_CRTDBG_MAP_ALLOC** é definido, as chamadas para **_dupenv_s** e **_wdupenv_s** são remapeadas para **_dupenv_s_dbg** e **_wdupenv_s_dbg**, respectivamente, com o *blockType* definido como **_NORMAL_BLOCK**. Portanto, você não precisa chamar essas funções explicitamente, a menos que queira marcar os blocos de heap como **_CLIENT_BLOCK**. Para obter mais informações sobre os tipos de bloco, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tdupenv_s_dbg**|**_dupenv_s_dbg**|**_dupenv_s_dbg**|**_wdupenv_s_dbg**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_dupenv_s_dbg**|\<crtdbg.h>|
|**_wdupenv_s_dbg**|\<crtdbg.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_dupenv_s_dbg.c
#include  <stdlib.h>
#include <crtdbg.h>

int main( void )
{
   char *pValue;
   size_t len;
   errno_t err = _dupenv_s_dbg( &pValue, &len, "pathext",
      _NORMAL_BLOCK, __FILE__, __LINE__ );
   if ( err ) return -1;
   printf( "pathext = %s\n", pValue );
   free( pValue );
   err = _dupenv_s_dbg( &pValue, &len, "nonexistentvariable",
      _NORMAL_BLOCK, __FILE__, __LINE__ );
   if ( err ) return -1;
   printf( "nonexistentvariable = %s\n", pValue );
   free( pValue ); // It's OK to call free with NULL
}
```

```Output
pathext = .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.pl
nonexistentvariable = (null)
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Constantes ambientais](../../c-runtime-library/environmental-constants.md)<br/>
[getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md)<br/>
[_putenv_s, _wputenv_s](putenv-s-wputenv-s.md)<br/>
