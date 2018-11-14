---
title: _locking
ms.date: 11/04/2016
apiname:
- _locking
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
- _locking
helpviewer_keywords:
- locking function
- bytes [C++], locking file
- files [C++], locking bytes
- files [C++], locking
- _locking function
ms.assetid: 099aaac1-d4ca-4827-aed6-24dff9844150
ms.openlocfilehash: 90327ed3388d4f18e0f64f92c33112c9ddd800f5
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51327038"
---
# <a name="locking"></a>_locking

Bloqueia ou desbloqueia os bytes de um arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _locking(
   int fd,
   int mode,
   long nbytes
);
```

### <a name="parameters"></a>Parâmetros

*fd*<br/>
Descritor de arquivo.

*modo*<br/>
Bloqueio de ação a ser executada.

*nbytes*<br/>
O número de bytes a serem bloqueados.

## <a name="return-value"></a>Valor de retorno

**Locking** retorna 0 se for bem-sucedido. Um valor de retorno de -1 indica falha, caso em que [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) é definido como um dos valores a seguir.

|Valor errno|Condição|
|-|-|
| **EACCES** | Violação de bloqueio (arquivo já foi bloqueado ou desbloqueado). |
| **EBADF** | Descritor de arquivo inválido. |
| **EDEADLOCK** | Violação de bloqueio. Retornado quando o **lk_lock** ou **lk_rlck** sinalizador for especificado e o arquivo não pode ser bloqueado após 10 tentativas. |
| **EINVAL** | Um argumento inválido foi fornecido ao **Locking**. |

Se houver uma falha devido a um parâmetro incorreto, como um descritor de arquivo inválido, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md).

## <a name="remarks"></a>Comentários

O **Locking** função bloqueia ou desbloqueia *nbytes* bytes do arquivo especificado por *fd*. Os bytes bloqueados em um arquivo impedem o acesso a esses bytes por outros processos. Todos os bloqueios ou desbloqueios se iniciam na posição atual do ponteiro do arquivo e avança para os próximos bytes *nbytes*. É possível bloquear bytes após o final do arquivo.

*mode* deve ser uma das seguintes constantes de manifesto definidas em Locking.h.

|*modo* valor|Efeito|
|-|-|
| **LK_LOCK** | Bloqueia os bytes especificados. Se os bytes não puderem ser bloqueados, o programa tentará novamente após 1 segundo. Se, após 10 tentativas, os bytes não puderem ser bloqueados, a constante retornará um erro. |
| **LK_NBLCK** | Bloqueia os bytes especificados. Se os bytes não puderem ser bloqueados, a constante retornará um erro. |
| **LK_NBRLCK** | Mesmo que **lk_nblck**. |
| **LK_RLCK** | Mesmo que **lk_lock**. |
| **LK_UNLCK** | Desbloqueia os bytes especificados, que devem ter sido bloqueados anteriormente. |

Várias regiões de um arquivo que não se sobrepõem podem ser bloqueadas. Uma região que está sendo desbloqueada deve ter sido bloqueada anteriormente. **Locking** mescla regiões adjacentes; se duas regiões bloqueadas forem adjacentes, cada região deve ser desbloqueada separadamente. Regiões devem ser bloqueadas por um curto período de tempo e devem ser desbloqueadas antes de fechar um arquivo ou sair do programa.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_locking**|\<io.h> e \<sys/locking.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_locking.c
/* This program opens a file with sharing. It locks
* some bytes before reading them, then unlocks them. Note that the
* program works correctly only if the file exists.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/locking.h>
#include <share.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>

int main( void )
{
   int  fh, numread;
   char buffer[40];

   /* Quit if can't open file or system doesn't
    * support sharing.
    */
   errno_t err = _sopen_s( &fh, "crt_locking.txt", _O_RDONLY, _SH_DENYNO,
                          _S_IREAD | _S_IWRITE );
   printf( "%d %d\n", err, fh );
   if( err != 0 )
      exit( 1 );

   /* Lock some bytes and read them. Then unlock. */
   if( _locking( fh, LK_NBLCK, 30L ) != -1 )
   {
      long lseek_ret;
      printf( "No one can change these bytes while I'm reading them\n" );
      numread = _read( fh, buffer, 30 );
      buffer[30] = '\0';
      printf( "%d bytes read: %.30s\n", numread, buffer );
      lseek_ret = _lseek( fh, 0L, SEEK_SET );
      _locking( fh, LK_UNLCK, 30L );
      printf( "Now I'm done. Do what you will with them\n" );
   }
   else
      perror( "Locking failed\n" );

   _close( fh );
}
```

### <a name="input-crtlockingtxt"></a>Entrada: crt_locking.txt

```Input
The first thirty bytes of this file will be locked.
```

## <a name="sample-output"></a>Saída de Exemplo

```Output
No one can change these bytes while I'm reading them
30 bytes read: The first thirty bytes of this
Now I'm done. Do what you will with them
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
