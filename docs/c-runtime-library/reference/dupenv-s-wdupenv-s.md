---
title: _dupenv_s, _wdupenv_s
ms.date: 11/04/2016
api_name:
- _dupenv_s
- _wdupenv_s
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
ms.openlocfilehash: f66828e0941c2324d75797cbb1fa77bdfa184205
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70942016"
---
# <a name="_dupenv_s-_wdupenv_s"></a>_dupenv_s, _wdupenv_s

Obtém um valor do ambiente atual.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*buffer*<br/>
Buffer para armazenar o valor da variável.

*numberOfElements*<br/>
Tamanho do *buffer*.

*varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor de retorno

Zero em caso de êxito; código de erro em caso de falha.

Essas funções validam seus parâmetros; Se *buffer* ou *VarName* for **NULL**, o manipulador de parâmetro inválido será invocado conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções definirão **errno** como **EINVAL** e retornarão **EINVAL**.

Se essas funções não puderem alocar memória suficiente, elas definirão o *buffer* como **nulo** e *numberOfElements* como 0 e retornará **ENOMEM**.

## <a name="remarks"></a>Comentários

A função **_dupenv_s** pesquisa a lista de variáveis de ambiente para *VarName*. Se a variável for encontrada, **_dupenv_s** alocará um buffer e copiará o valor da variável para o buffer. O endereço e o comprimento do buffer são retornados em *buffer* e *numberOfElements*. Ao alocar o buffer em si, o **_dupenv_s** fornece uma alternativa mais conveniente para [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md).

> [!NOTE]
> É de responsabilidade do programa chamador liberar a memória chamando [free](free.md).

Se a variável não for encontrada, o *buffer* será definido como **NULL**, *numberOfElements* será definido como 0 e o valor de retorno será 0 porque essa situação não é considerada uma condição de erro.

Se você não estiver interessado no tamanho do buffer, poderá passar **NULL** para *numberOfElements*.

**_dupenv_s** não diferencia maiúsculas de minúsculas no sistema operacional Windows. **_dupenv_s** usa a cópia do ambiente apontado pela variável global **_environ** para acessar o ambiente. Consulte os comentários em [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md) para uma discussão de **_environ**.

O valor no *buffer* é uma cópia do valor da variável de ambiente; modificá-lo não tem nenhum efeito no ambiente. Use a função [_putenv_s, _wputenv_s](putenv-s-wputenv-s.md) para modificar o valor de uma variável de ambiente.

**_wdupenv_s** é uma versão de caractere largo do **_dupenv_s**; os argumentos de **_wdupenv_s** são cadeias de caracteres largos. A variável global **_wenviron** é uma versão de caractere largo de **_environ**. Consulte os comentários em [getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md) para obter mais informações sobre **_wenviron**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tdupenv_s**|**_dupenv_s**|**_dupenv_s**|**_wdupenv_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_dupenv_s**|\<stdlib.h>|
|**_wdupenv_s**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Constantes ambientais](../../c-runtime-library/environmental-constants.md)<br/>
[_dupenv_s_dbg, _wdupenv_s_dbg](dupenv-s-dbg-wdupenv-s-dbg.md)<br/>
[getenv_s, _wgetenv_s](getenv-s-wgetenv-s.md)<br/>
[_putenv_s, _wputenv_s](putenv-s-wputenv-s.md)<br/>
