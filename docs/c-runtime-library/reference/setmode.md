---
title: _setmode
ms.date: 4/2/2020
api_name:
- _setmode
- _o__setmode
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _setmode
helpviewer_keywords:
- Unicode [C++], console output
- files [C++], modes
- _setmode function
- file translation [C++], setting mode
- files [C++], translation
- setmode function
ms.assetid: 996ff7cb-11d1-43f4-9810-f6097182642a
ms.openlocfilehash: 36d2130d4039f1f87f7f54fc26ad02cb8d519b4a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81353828"
---
# <a name="_setmode"></a>_setmode

Define o modo de tradução do arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _setmode (
   int fd,
   int mode
);
```

### <a name="parameters"></a>Parâmetros

*Fd*<br/>
Descritor de arquivo.

*Modo*<br/>
Novo modo de conversão.

## <a name="return-value"></a>Valor retornado

Se bem-sucedido, retorna para o modo de conversão anterior.

Se parâmetros inválidos forem passados para essa função, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essa função retorna -1 e define **errno** para **ebadf**, o que indica um descritor de arquivo inválido, ou **EINVAL,** que indica um argumento *de modo* inválido.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_setmode** define para *moder* o modo de tradução do arquivo dado por *fd*. Passar **_O_TEXT** como *modo* define texto (isto é, traduzido) modo. As combinações de alimentação de linha de retorno de transporte (CR-LF) são traduzidas em um único caractere de alimentação de linha na entrada. Os caracteres de alimentação de linha são convertidos para combinações CR-LF na saída. Passar **_O_BINARY** define o modo binário (não traduzido), no qual essas traduções são suprimidas.

Você também pode passar **_O_U16TEXT**, **_O_U8TEXT**ou **_O_WTEXT** para habilitar o modo Unicode, como demonstrado no segundo exemplo mais tarde neste documento.

> [!CAUTION]
> O modo Unicode é para funções `wprintf`de impressão ampla (por exemplo, ) e não é suportado para funções de impressão estreitas. O uso de uma função de impressão estreita em um fluxo de modo Unicode aciona uma afirmação.

**_setmode** é normalmente usado para modificar o modo de tradução padrão de **stdin** e **stdout,** mas você pode usá-lo em qualquer arquivo. Se você aplicar **_setmode** ao descritor de arquivo de um fluxo, chame **_setmode** antes de executar qualquer operação de entrada ou saída no fluxo.

> [!CAUTION]
> Se você gravar dados em um fluxo de arquivos, lave explicitamente o código usando [fflush](fflush.md) antes de usar **_setmode** para alterar o modo. Se você não limpar o código, pode ocorrer comportamento inesperado. Se você não tiver dados gravados no fluxo, não será preciso limpar o código.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**_setmode**|\<io.h>|\<fcntl.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_setmode.c
// This program uses _setmode to change
// stdin from text mode to binary mode.

#include <stdio.h>
#include <fcntl.h>
#include <io.h>

int main( void )
{
   int result;

   // Set "stdin" to have binary mode:
   result = _setmode( _fileno( stdin ), _O_BINARY );
   if( result == -1 )
      perror( "Cannot set mode" );
   else
      printf( "'stdin' successfully changed to binary mode\n" );
}
```

```Output
'stdin' successfully changed to binary mode
```

## <a name="example"></a>Exemplo

```C
// crt_setmodeunicode.c
// This program uses _setmode to change
// stdout to Unicode. Cyrillic and Ideographic
// characters will appear on the console (if
// your console font supports those character sets).

#include <fcntl.h>
#include <io.h>
#include <stdio.h>

int main(void) {
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L"\x043a\x043e\x0448\x043a\x0430 \x65e5\x672c\x56fd\n");
    return 0;
}
```

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_set_fmode](set-fmode.md)<br/>
