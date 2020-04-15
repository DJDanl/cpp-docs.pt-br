---
title: _umask
ms.date: 4/2/2020
api_name:
- _umask
- _o__umask
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
- api-ms-win-crt-filesystem-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _umask
helpviewer_keywords:
- masks, file-permission-setting
- _umask function
- masks
- umask function
- file permissions [C++]
- files [C++], permission settings for
ms.assetid: 5e9a13ba-5321-4536-8721-6afb6f4c8483
ms.openlocfilehash: b451f979f2925a31f5baaac52351c5d2c0a76da0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362019"
---
# <a name="_umask"></a>_umask

Define a máscara de permissão de arquivo padrão. Uma versão mais segura dessa função está disponível. Consulte [_umask_s](umask-s.md).

## <a name="syntax"></a>Sintaxe

```C
int _umask( int pmode );
```

### <a name="parameters"></a>Parâmetros

*Pmode*<br/>
Configuração de permissão padrão.

## <a name="return-value"></a>Valor retornado

**_umask** devolve o valor anterior do *pmode*. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

A função **_umask** define a máscara de permissão de arquivo do processo atual para o modo especificado pelo *pmode*. A máscara de permissão de arquivo modifica a configuração de permissão de novos arquivos criados por **_creat,** **_open**ou **_sopen**. Se um bit na máscara for 1, o bit correspondente no valor da permissão solicitada do arquivo será definido como 0 (não permitido). Se um bit na máscara for 0, o bit correspondente será deixado inalterado. A configuração de permissão para um novo arquivo não é definida até que o arquivo é seja fechado pela primeira vez.

O *pmode* de expressão inteiro contém uma ou ambas as seguintes constantes de manifesto, definidas em SYS\STAT. H:

|*Pmode*| |
|-|-|
| **_S_IWRITE** | Gravação permitida. |
| **_S_IREAD** | Leitura permitida. |
| **_S_IREAD** **_S_IWRITE &#124;** | Leitura e gravação permitidas. |

Quando ambas as constantes são dadas, elas se juntam ao operador bitwise-OR **(&#124;).** Se o argumento *pmode* for **_S_IREAD,** a leitura não é permitida (o arquivo é somente gravação). Se o argumento *pmode* for **_S_IWRITE,** a escrita não é permitida (o arquivo é somente leitura). Por exemplo, se o bit de gravação estiver definido na máscara, quaisquer novos arquivos serão somente leitura. Observe que nos sistemas operacionais MS-DOS e Windows, todos os arquivos podem ser lidos; não é possível conceder permissão somente gravação. Portanto, definir a broca de leitura com **_umask** não tem efeito nos modos do arquivo.

Se *o pmode* não for uma combinação de uma das constantes manifestas ou incorporar um conjunto alternativo de constantes, a função simplesmente ignorará essas.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_umask**|\<io.h>, \<sys/stat.h>, \<sys/types.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

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

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
