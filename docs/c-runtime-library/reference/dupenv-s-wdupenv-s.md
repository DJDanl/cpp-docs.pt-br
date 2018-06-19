---
title: _dupenv_s, _wdupenv_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _dupenv_s
- _wdupenv_s
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
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- tdupenv_s
- _dupenv_s
- wdupenv_s
- dupenv_s
- _tdupenv_s
- _wdupenv_s
dev_langs:
- C++
helpviewer_keywords:
- _dupenv_s function
- _tdupenv_s function
- _wdupenv_s function
- environment variables
- wdupenv_s function
- dupenv_s function
- tdupenv_s function
ms.assetid: b729ecc2-a31d-4ccf-92a7-5accedb8f8c8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5a918b866b0b43fb0e6b31e2deb5d9861dabe9a2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32402108"
---
# <a name="dupenvs-wdupenvs"></a>_dupenv_s, _wdupenv_s

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
Tamanho de *buffer*.

*varname*<br/>
Nome da variável de ambiente.

## <a name="return-value"></a>Valor de retorno

Zero em caso de êxito; código de erro em caso de falha.

Essas funções validam seus parâmetros. Se *buffer* ou *varname* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, as funções de conjunto **errno** para **EINVAL** e retornar **EINVAL**.

Se essas funções não é possível alocar memória suficiente, eles definidos *buffer* para **nulo** e *numberOfElements* para 0 e retornar **ENOMEM**.

## <a name="remarks"></a>Comentários

O **dupenv_s** função pesquisa a lista de variáveis de ambiente para *varname*. Se a variável for encontrada, **dupenv_s** aloca um buffer e copia o valor da variável no buffer. Endereço e o comprimento do buffer são retornados no *buffer* e *numberOfElements*. Ao alocar o buffer em si, **dupenv_s** fornece uma alternativa mais conveniente para [getenv_s, wgetenv_s](getenv-s-wgetenv-s.md).

> [!NOTE]
> É de responsabilidade do programa chamador liberar a memória chamando [free](free.md).

Se a variável não for encontrada, em seguida, *buffer* é definido como **nulo**, *numberOfElements* é definido como 0, e o valor de retorno é 0, porque essa situação não é considerada como um erro condição.

Se você não estiver interessado no tamanho do buffer que você pode passar **nulo** para *numberOfElements*.

**dupenv_s** não diferencia maiusculas de minúsculas no sistema operacional Windows. **dupenv_s** usa a cópia do ambiente apontada pela variável global **Environ** acessem o ambiente. Consulte os comentários na [getenv_s, wgetenv_s](getenv-s-wgetenv-s.md) para uma discussão sobre **Environ**.

O valor em *buffer* é uma cópia do valor da variável de ambiente; modificá-la não tem nenhum efeito no ambiente. Use a função [_putenv_s, _wputenv_s](putenv-s-wputenv-s.md) para modificar o valor de uma variável de ambiente.

**wdupenv_s** é uma versão de caractere largo de **dupenv_s**; os argumentos de **wdupenv_s** são cadeias de caracteres do caractere largo. O **wenviron** variável global é uma versão de caractere largo de **Environ**. Consulte os comentários na [getenv_s, wgetenv_s](getenv-s-wgetenv-s.md) para saber mais sobre **wenviron**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tdupenv_s**|**_dupenv_s**|**_dupenv_s**|**_wdupenv_s**|

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
