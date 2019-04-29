---
title: _setmode
ms.date: 11/04/2016
apiname:
- _setmode
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: 67cca27ba03a99d7e192d438a98f1bb3a93845ee
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62356377"
---
# <a name="setmode"></a>_setmode

Define o modo de tradução do arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _setmode (
   int fd,
   int mode
);
```

### <a name="parameters"></a>Parâmetros

*fd*<br/>
Descritor de arquivo.

*modo*<br/>
Novo modo de conversão.

## <a name="return-value"></a>Valor de retorno

Se bem-sucedido, retorna para o modo de conversão anterior.

Se parâmetros inválidos forem passados para essa função, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará -1 e definirá **errno** para um **EBADF**, que indica um descritor de arquivo inválido, ou **EINVAL**, que indica um inválido *modo* argumento.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **setmode** função define como *modo* o modo de conversão do arquivo fornecido pelo *fd*. Passando **o_text** como *modo* define o texto (ou seja, convertido) modo. Combinações de (CR-LF) feeds do carro de retorno de linha são convertidas em uma única linha, caractere de alimentação na entrada. Os caracteres de alimentação de linha são convertidos para combinações CR-LF na saída. Passando **o_binary** conjuntos (não convertido) modo binário, em que essas conversões são suprimidas.

Você também pode passar **_O_U16TEXT**, **_O_U8TEXT**, ou **o_wtext** para habilitar o modo Unicode, conforme demonstrado no segundo exemplo neste documento.

> [!CAUTION]
> Modo Unicode é para funções de impressão largo (por exemplo, `wprintf`) e não há suporte para funções de impressa estreitas. Uso de uma função de impressão estreito em um fluxo de modo Unicode dispara uma declaração.

**setmode** normalmente é usado para modificar o modo de conversão padrão de **stdin** e **stdout**, mas você pode usá-lo em qualquer arquivo. Se você aplicar **setmode** para o descritor de arquivo para um fluxo, chame **setmode** antes de executar quaisquer operações de entrada ou saídas no fluxo.

> [!CAUTION]
> Se você gravar dados em um fluxo de arquivos, limpe explicitamente o código por meio [fflush](fflush.md) antes de usar **setmode** para alterar o modo. Se você não limpar o código, pode ocorrer comportamento inesperado. Se você não tiver dados gravados no fluxo, não será preciso limpar o código.

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

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_set_fmode](set-fmode.md)<br/>
