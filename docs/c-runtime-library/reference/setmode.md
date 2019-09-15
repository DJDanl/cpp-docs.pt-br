---
title: _setmode
ms.date: 11/04/2016
api_name:
- _setmode
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
ms.openlocfilehash: 7f14cc9451b93a9077916b8c650645990ba654a3
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948585"
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

*fd*<br/>
Descritor de arquivo.

*modo*<br/>
Novo modo de conversão.

## <a name="return-value"></a>Valor de retorno

Se bem-sucedido, retorna para o modo de conversão anterior.

Se parâmetros inválidos forem passados para essa função, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função retornará-1 e definirá **errno** como **EBADF**, que indica um descritor de arquivo inválido ou **EINVAL**, que indica um argumento de *modo* inválido.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_setmode** define como *modo* o modo de tradução do arquivo fornecido pelo *fd*. Passar **_O_TEXT** como *Mode* define o modo de texto (ou seja, traduzido). As combinações de CR-LF (retorno de carro-alimentação de linha) são convertidas em um único caractere de alimentação de linha na entrada. Os caracteres de alimentação de linha são convertidos para combinações CR-LF na saída. Passar **_O_BINARY** define o modo binário (não traduzido), no qual essas traduções são suprimidas.

Você também pode passar **_O_U16TEXT**, **_O_U8TEXT**ou **_O_WTEXT** para habilitar o modo Unicode, conforme demonstrado no segundo exemplo posteriormente neste documento.

> [!CAUTION]
> O modo Unicode é para funções de impressão amplas ( `wprintf`por exemplo,) e não tem suporte para funções de impressão restritas. O uso de uma função de impressão restrita em um fluxo de modo Unicode dispara uma declaração.

**_setmode** normalmente é usado para modificar o modo de tradução padrão de **stdin** e **stdout**, mas você pode usá-lo em qualquer arquivo. Se você aplicar **_setmode** ao descritor de arquivo para um fluxo, chame **_setmode** antes de executar qualquer operação de entrada ou saída no fluxo.

> [!CAUTION]
> Se você gravar dados em um fluxo de arquivos, libere explicitamente o código usando [fflush](fflush.md) antes de usar **_setmode** para alterar o modo. Se você não limpar o código, pode ocorrer comportamento inesperado. Se você não tiver dados gravados no fluxo, não será preciso limpar o código.

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
