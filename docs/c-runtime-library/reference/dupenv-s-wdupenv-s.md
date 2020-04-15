---
title: _dupenv_s, _wdupenv_s
ms.date: 4/2/2020
api_name:
- _dupenv_s
- _wdupenv_s
- _o__dupenv_s
- _o__wdupenv_s
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
- api-ms-win-crt-environment-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- tdupenv_s
- _dupenv_s
- wdupenv_s
- dupenv_s
- _tdupenv_s
- _wdupenv_s
helpviewer_keywords:
- _dupenv_s function
- _tdupenv_s function
- _wdupenv_s function
- environment variables
- wdupenv_s function
- dupenv_s function
- tdupenv_s function
ms.assetid: b729ecc2-a31d-4ccf-92a7-5accedb8f8c8
ms.openlocfilehash: f65f1da3e8cef077df04d0bdb7eb2aaf75afd9fa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348067"
---
# <a name="_dupenv_s-_wdupenv_s"></a>_dupenv_s, _wdupenv_s

Obtém um valor do ambiente atual.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _dupenv_s(
   char **buffer,
   size_t *numberOfElements,
   const char *varname
);
errno_t _wdupenv_s(
   wchar_t **buffer,
   size_t *numberOfElements,
   const wchar_t *varname
);
```

### <a name="parameters"></a>Parâmetros

*Buffer*<br/>
Buffer para armazenar o valor da variável.

*Numberofelements*<br/>
Tamanho do *buffer*.

*Varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor retornado

Zero em caso de êxito; código de erro em caso de falha.

Essas funções validam seus parâmetros; se *buffer* ou *varname* for **NULL,** o manipulador de parâmetros inválidos é invocado conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, as funções se configuram **para** **EINVAL** e retornam **EINVAL**.

Se essas funções não puderem alocar memória suficiente, elas definem *o buffer* para **NULL** e *numberOfElements* para 0 e retornam **o ENOMEM**.

## <a name="remarks"></a>Comentários

A **função _dupenv_s** pesquisa a lista de variáveis de ambiente para *varname*. Se a variável for encontrada, **_dupenv_s** alocar um buffer e copiar o valor da variável no buffer. O endereço e o comprimento do buffer são retornados em *buffer* e *numberOfElements*. Ao alocar o buffer em si, **_dupenv_s** fornece uma alternativa mais conveniente para [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md).

> [!NOTE]
> É de responsabilidade do programa chamador liberar a memória chamando [free](free.md).

Se a variável não for encontrada, o *buffer* será definido como **NULL**, *numberOfElements* é definido como 0, e o valor de retorno é 0 porque essa situação não é considerada uma condição de erro.

Se você não estiver interessado no tamanho do buffer, você pode passar **NULL** para *numberOfElements*.

**_dupenv_s** não é sensível a casos no sistema operacional Windows. **_dupenv_s** usa a cópia do ambiente apontada pela variável global **_environ** para acessar o ambiente. Veja as observações em [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md) para uma discussão sobre **_environ**.

O valor em *buffer* é uma cópia do valor da variável ambiente; modificá-lo não tem efeito sobre o ambiente. Use a função [_putenv_s, _wputenv_s](putenv-s-wputenv-s.md) para modificar o valor de uma variável de ambiente.

**_wdupenv_s** é uma versão ampla de **_dupenv_s;** os argumentos de **_wdupenv_s** são cordas de caráter amplo. A **_wenviron** variável global é uma versão ampla de **_environ**. Veja os Comentários em [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md) para mais informações sobre **_wenviron**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tdupenv_s**|**_dupenv_s**|**_dupenv_s**|**_wdupenv_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_dupenv_s**|\<stdlib.h>|
|**_wdupenv_s**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_dupenv_s.c
#include  <stdlib.h>

int main( void )
{
   char *pValue;
   size_t len;
   errno_t err = _dupenv_s( &pValue, &len, "pathext" );
   if ( err ) return -1;
   printf( "pathext = %s\n", pValue );
   free( pValue );
   err = _dupenv_s( &pValue, &len, "nonexistentvariable" );
   if ( err ) return -1;
   printf( "nonexistentvariable = %s\n", pValue );
   free( pValue ); // It's OK to call free with NULL
}
```

```Output
pathext = .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.pl
nonexistentvariable = (null)
```

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Constantes ambientais](../../c-runtime-library/environmental-constants.md)<br/>
[_dupenv_s_dbg, _wdupenv_s_dbg](dupenv-s-dbg-wdupenv-s-dbg.md)<br/>
[getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md)<br/>
[_putenv_s, _wputenv_s](putenv-s-wputenv-s.md)<br/>
