---
title: _setmode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- Unicode [C++], console output
- files [C++], modes
- _setmode function
- file translation [C++], setting mode
- files [C++], translation
- setmode function
ms.assetid: 996ff7cb-11d1-43f4-9810-f6097182642a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 59aed27ec4803cd1709635da44ef37d748342e29
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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

Se parâmetros inválidos forem passados para essa função, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função retornará -1 e conjuntos de **errno** como **EBADF**, que indica que um descritor de arquivo inválido ou **EINVAL**, que indica um inválido *modo* argumento.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **setmode** função define como *modo* o modo de conversão do arquivo fornecido pelo *fd*. Passando **o_text** como *modo* define o texto (que é, convertido) modo. Combinações de feed (CR LF) carro retorno de linha são convertidas em uma única linha de caractere de alimentação na entrada. Os caracteres de alimentação de linha são convertidos para combinações CR-LF na saída. Passando **o_binary** conjuntos (não traduzido) modo binário, na qual essas conversões são suprimidos.

Você também pode passar **_O_U16TEXT**, **_O_U8TEXT**, ou **_O_WTEXT** para habilitar o modo de Unicode, conforme demonstrado no segundo exemplo neste documento. **setmode** normalmente é usado para modificar o modo de conversão padrão de **stdin** e **stdout**, mas você pode usá-lo em qualquer arquivo. Se você aplicar **setmode** para o descritor de arquivo para um fluxo, chame **setmode** antes de executar quaisquer operações de entrada ou saídas no fluxo.

> [!CAUTION]
> Se você gravar dados em um fluxo de arquivo, liberação explicitamente o código usando [fflush](fflush.md) antes de usar **setmode** para alterar o modo. Se você não limpar o código, pode ocorrer comportamento inesperado. Se você não tiver dados gravados no fluxo, não será preciso limpar o código.

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
