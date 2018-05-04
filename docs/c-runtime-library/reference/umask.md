---
title: _umask | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _umask
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
- _umask
dev_langs:
- C++
helpviewer_keywords:
- masks, file-permission-setting
- _umask function
- masks
- umask function
- file permissions [C++]
- files [C++], permission settings for
ms.assetid: 5e9a13ba-5321-4536-8721-6afb6f4c8483
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce3053bfb19cc81dff15d41d1b5bc6d405da619f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="umask"></a>_umask

Define a máscara de permissão de arquivo padrão. Uma versão mais segura dessa função está disponível. Consulte [_umask_s](umask-s.md).

## <a name="syntax"></a>Sintaxe

```C
int _umask( int pmode );
```

### <a name="parameters"></a>Parâmetros

*pmode*<br/>
Configuração de permissão padrão.

## <a name="return-value"></a>Valor de retorno

**umask** retorna o valor anterior da *pmode*. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

O **umask** função define a máscara de permissão de arquivo do processo atual para o modo especificado por *pmode*. A máscara de permissão de arquivo modifica a configuração de permissão de novos arquivos criados por **Creat**, **abrir**, ou **sopen**. Se um bit na máscara for 1, o bit correspondente no valor da permissão solicitada do arquivo será definido como 0 (não permitido). Se um bit na máscara for 0, o bit correspondente será deixado inalterado. A configuração de permissão para um novo arquivo não é definida até que o arquivo é seja fechado pela primeira vez.

A expressão de inteiro *pmode* contém uma ou ambas das seguintes constantes de manifesto, definidas em SYS\STAT. H:

|*pmode*||
|-|-|
**S_IWRITE**|Gravação permitida.
**S_IREAD**|Leitura permitida.
**S_IREAD** \| **S_IWRITE**|Leitura e gravação permitidas.

Quando ambas as constantes são fornecidas, eles são associados ao operador OR bit a bit ( **|** ). Se o *pmode* argumento é **s_iread**, leitura não é permitida (o arquivo é somente gravação). Se o *pmode* argumento é **s_iwrite**, gravação não é permitida (o arquivo é somente leitura). Por exemplo, se o bit de gravação estiver definido na máscara, quaisquer novos arquivos serão somente leitura. Observe que nos sistemas operacionais MS-DOS e Windows, todos os arquivos podem ser lidos; não é possível conceder permissão somente gravação. Portanto, definir a bit de leitura **umask** não tem nenhum efeito sobre os modos do arquivo.

Se *pmode* não é uma combinação de uma das constantes de manifesto ou incorpora um conjunto alternativo de constantes, a função simplesmente irá ignorar os.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_umask**|\<io.h>, \<sys/stat.h>, \<sys/types.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_umask.c
// compile with: /W3
// This program uses _umask to set
// the file-permission mask so that all future
// files will be created as read-only files.
// It also displays the old mask.
#include <sys/stat.h>
#include <sys/types.h>
#include <io.h>
#include <stdio.h>

int main( void )
{
   int oldmask;

   /* Create read-only files: */
   oldmask = _umask( _S_IWRITE ); // C4996
   // Note: _umask is deprecated; consider using _umask_s instead
   printf( "Oldmask = 0x%.4x\n", oldmask );
}
```

```Output
Oldmask = 0x0000
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
