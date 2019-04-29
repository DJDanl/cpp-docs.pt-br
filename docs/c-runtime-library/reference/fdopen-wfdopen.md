---
title: _fdopen, _wfdopen
ms.date: 12/12/2017
apiname:
- _fdopen
- _wfdopen
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
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tfdopen
- _fdopen
- _wfdopen
- wfdopen
- tfdopen
helpviewer_keywords:
- wfdopen function
- _fdopen function
- _wfdopen function
- tfdopen function
- fdopen function
- _tfdopen function
- streams, associating with files
ms.assetid: 262757ff-1e09-4472-a5b6-4325fc28f971
ms.openlocfilehash: 0cde110bf1dd12c23a6b0b658809502743d9edd3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62334769"
---
# <a name="fdopen-wfdopen"></a>_fdopen, _wfdopen

Associa um fluxo com um arquivo que foi aberto anteriormente para E/S de nível inferior.

## <a name="syntax"></a>Sintaxe

```C
FILE *_fdopen(
   int fd,
   const char *mode
);
FILE *_wfdopen(
   int fd,
   const wchar_t *mode
);
```

### <a name="parameters"></a>Parâmetros

*fd*<br/>
Descritor de arquivo do arquivo aberto.

*modo*<br/>
Tipo de acesso do arquivo.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o fluxo aberto. Um valor de ponteiro nulo indica um erro. Quando ocorre um erro, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EBADF**, que indica um descritor de arquivo incorreto, ou **EINVAL**, que indica que *modo*  é um ponteiro nulo.

Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **fdopen** função associa um fluxo de e/s com o arquivo que é identificado pelo *fd*e, portanto, permite que um arquivo é aberto para e/s baixo nível sejam armazenados em buffer e formatada. **wfdopen** é uma versão de caractere largo de **fdopen**; o *modo* argumento **wfdopen** é uma cadeia de caracteres largos. **wfdopen** e **fdopen** caso contrário, se comportam de forma idêntica.

Arquivo descritores passados para **fdopen** são de propriedade por retornado **arquivo &#42;**  fluxo. Se **fdopen** for bem-sucedida, não chame [ \_fechar](close.md) no descritor de arquivo. Chamando [fclose](fclose-fcloseall.md) em retornado **arquivo &#42;**  também fecha o descritor de arquivo.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfdopen**|**_fdopen**|**_fdopen**|**_wfdopen**|

O *modo* cadeia de caracteres Especifica o tipo de acesso ao arquivo solicitado para o arquivo:

| *modo* | Acesso |
|--------|--------|
| **"r"** | Abre para leitura. Se o arquivo não existe ou não for encontrado, o **fopen** chamar falhar. |
| **"w"** | Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos. |
| **"a"** | Abre para gravação no final do arquivo (acréscimo). Cria o arquivo se ele não existir. |
| **"r+"** | Abre para leitura e gravação. O arquivo deve existir. |
| **"w+"** | Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos. |
| **"a+"** | Abre para leitura e conexão. Cria o arquivo se ele não existir. |

Quando um arquivo é aberto com o **"a"** ou **"+"** acessar o tipo, todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [rewind](rewind.md), mas é sempre movido de volta até o final do arquivo antes de qualquer operação de gravação é realizada. Sendo assim, dados existentes não podem ser substituídos. Quando o **"r +"**, **"w +"**, ou **"+"** tipo de acesso for especificado, são permitidas leitura e gravação (o arquivo deve ser aberto para "atualização"). No entanto, quando você muda entre leitura e gravação, deve haver uma intervenção [fflush](fflush.md), [fsetpos](fsetpos.md), [fseek](fseek-fseeki64.md), ou [rewind](rewind.md) operação. Você pode especificar a posição atual para o [fsetpos](fsetpos.md) ou [fseek](fseek-fseeki64.md) operação, se você quiser.

Além dos valores acima, os caracteres a seguir podem ser incluídos no *modo* para especificar o modo de conversão de caracteres de nova linha:

| *modo* modificador | Comportamento |
|-----------------|----------|
| **t** | Abra no modo de texto (convertido). Neste modo, combinações de CR-LF (retorno de carro – avanço de linha) são convertidas em LFs (avanços de uma linha) na entrada e caracteres de LF são convertidos em combinações de CR-LF na saída. Além disso, Ctrl+Z é interpretado como um caractere de fim do arquivo na entrada. |
| **b** | Abre no modo binário (não convertido). Todas as conversões do **t** modo são suprimidas. |
| **c** | Habilitar o sinalizador de confirmação associado *filename* para que o conteúdo do buffer de arquivo sejam gravado diretamente no disco, se **fflush** ou **flushall** é chamado. |
| **n** | Redefinir o sinalizador de confirmação associado *filename* para "no-commit". Esse é o padrão. Também substitui o sinalizador de confirmação global se você vincular o programa a Commode.obj. O padrão do sinalizador de confirmação global é "no-commit", a menos que você vincule explicitamente o programa a Commode.obj. |

O **t**, **c**, e **n** *modo* opções são extensões da Microsoft para **fopen** e **fdopen**. Não as use se você quiser preservar a portabilidade ANSI.

Se **t** ou **b** não é fornecido na *modo*, o modo de translação padrão é definido pela variável global [ \_fmode](../../c-runtime-library/fmode.md). Se **t** ou **b** é prefixado para o argumento, a função falhará e retornará NULL. Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

Caracteres válidos para o *modo* cadeia de caracteres usada na **fopen** e **fdopen** correspondem às *oflag* argumentos usados no [ \_abra](open-wopen.md) e [ \_sopen](sopen-wsopen.md), conforme mostrado nesta tabela:

|Caracteres em *modo* cadeia de caracteres|Equivalente *oflag* valor para **Open** e **sopen**|
|---------------------------------|---------------------------------------------------|
|**a**|**\_U\_WRONLY &#124; \_s\_APPEND** (geralmente  **\_s\_WRONLY &#124; \_s\_CRI &#124; \_s \_APPEND**)|
|**a+**|**\_U\_RDWR &#124; \_s\_APPEND** (geralmente  **\_s\_RDWR &#124; \_s\_APPEND &#124; \_s\_ CRIAR** )|
|**r**|**\_O\_RDONLY**|
|**r+**|**\_O\_RDWR**|
|**w**|**\_U\_WRONLY** (geralmente  **\_s\_WRONLY &#124; \_s\_criar &#124; \_s\_TRUNC**)|
|**w+**|**\_U\_RDWR** (geralmente  **\_s\_RDWR &#124; \_s\_criar &#124; \_s\_TRUNC**)|
|**b**|**\_O\_BINARY**|
|**t**|**\_O\_TEXT**|
|**c**|Nenhum|
|**n**|Nenhum|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fdopen**|\<stdio.h>|
|**_wfdopen**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```c
// crt_fdopen.c
// This program opens a file by using low-level
// I/O, then uses _fdopen to switch to stream
// access. It counts the lines in the file.

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <share.h>

int main( void )
{
   FILE *stream;
   int  fd, count = 0;
   char inbuf[128];

   // Open a file.
   if( _sopen_s( &fd, "crt_fdopen.txt", _O_RDONLY, _SH_DENYNO, 0 ) )
      exit( 1 );

   // Get stream from file descriptor.
   if( (stream = _fdopen( fd, "r" )) == NULL )
      exit( 1 );

   while( fgets( inbuf, 128, stream ) != NULL )
      count++;

   // After _fdopen, close by using fclose, not _close.
   fclose( stream );
   printf( "Lines in file: %d\n", count );
}
```

### <a name="input-crtfdopentxt"></a>Entrada: crt_fdopen.txt

```Input
Line one
Line two
```

### <a name="output"></a>Saída

```Output
Lines in file: 2
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[\_dup, \_dup2](dup-dup2.md)<br/>
[fclose, \_fcloseall](fclose-fcloseall.md)<br/>
[fopen, \_wfopen](fopen-wfopen.md)<br/>
[freopen, \_wfreopen](freopen-wfreopen.md)<br/>
[\_Abrir, \_wopen](open-wopen.md)<br/>
