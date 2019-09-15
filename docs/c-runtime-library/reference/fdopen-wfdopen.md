---
title: _fdopen, _wfdopen
ms.date: 12/12/2017
api_name:
- _fdopen
- _wfdopen
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
- api-ms-win-crt-math-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: 5202c84cd1a9038faf68587f9207d376ed8c0af1
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70941253"
---
# <a name="_fdopen-_wfdopen"></a>_fdopen, _wfdopen

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

Cada uma dessas funções retorna um ponteiro para o fluxo aberto. Um valor de ponteiro nulo indica um erro. Quando ocorre um erro, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EBADF**, que indica um descritor de arquivo inválido ou **EINVAL**, que indica que o *modo* era um ponteiro nulo.

Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_fdopen** associa um fluxo de e/s ao arquivo que é identificado pelo *FD*e, portanto, permite que um arquivo aberto para e/s de baixo nível seja armazenado em buffer e formatado. **_wfdopen** é uma versão de caractere largo do **_fdopen**; o argumento de *modo* para **_wfdopen** é uma cadeia de caracteres largos. caso contrário, **_wfdopen** e **_fdopen** se comportam de forma idêntica.

Os descritores de arquivo passados para **_fdopen** pertencem ao fluxo de **arquivos &#42;**  retornado. Se **_fdopen** for bem-sucedido, não chame [ \_fechar](close.md) no descritor de arquivo. Chamar [fclose](fclose-fcloseall.md) no **arquivo &#42;**  retornado também fecha o descritor de arquivo.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|\_Unicode e \_MBCS não definidos|\_MBCS definição|\_Definido em UNICODE|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfdopen**|**_fdopen**|**_fdopen**|**_wfdopen**|

A cadeia de caracteres do *modo* especifica o tipo de acesso ao arquivo solicitado para o arquivo:

| *modo* | Access |
|--------|--------|
| **"r"** | Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada **fopen** falhará. |
| **"w"** | Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos. |
| **"a"** | Abre para gravação no final do arquivo (acrescentando). Cria o arquivo se ele não existir. |
| **"r+"** | Abre para leitura e gravação. O arquivo deve existir. |
| **"w+"** | Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos. |
| **"a+"** | Abre para leitura e conexão. Cria o arquivo se ele não existir. |

Quando um arquivo é aberto com o tipo de acesso **"a"** ou **"a +"** , todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [retrocesso](rewind.md), mas sempre é movido de volta para o final do arquivo antes de qualquer operação de gravação ser executada. Sendo assim, dados existentes não podem ser substituídos. Quando o tipo de acesso **"r +"** , **"w +"** ou **"a +"** é especificado, a leitura e a gravação são permitidas (o arquivo é considerado aberto para "atualização"). No entanto, quando você alterna entre leitura e gravação, deve haver uma operação intermediária [fflush](fflush.md), [fsetpos](fsetpos.md), [fseek](fseek-fseeki64.md)ou [retrocesso](rewind.md) . Você pode especificar a posição atual para a operação [fsetpos](fsetpos.md) ou [fseek](fseek-fseeki64.md) , se desejar.

Além dos valores acima, os caracteres a seguir também podem ser incluídos no *modo* para especificar o modo de tradução para caracteres de nova linha:

| modificador de *modo* | Comportamento |
|-----------------|----------|
| **t** | Abra no modo de texto (convertido). Neste modo, combinações de CR-LF (retorno de carro – avanço de linha) são convertidas em LFs (avanços de uma linha) na entrada e caracteres de LF são convertidos em combinações de CR-LF na saída. Além disso, Ctrl+Z é interpretado como um caractere de fim do arquivo na entrada. |
| **b** | Abre no modo binário (não convertido). Todas as traduções do modo **t** são suprimidas. |
| **c** | Habilite o sinalizador de confirmação para o *nome de arquivo* associado para que o conteúdo do buffer de arquivo seja gravado diretamente no disco se o **fflush** ou **_flushall** for chamado. |
| **n** | Redefina o sinalizador de confirmação para o *nome de arquivo* associado como "sem confirmação". Esse é o padrão. Também substitui o sinalizador de confirmação global se você vincular o programa a Commode.obj. O padrão do sinalizador de confirmação global é "no-commit", a menos que você vincule explicitamente o programa a Commode.obj. |

As opções de *modo* **t**, **c**e **n** são extensões da Microsoft para **fopen** e **_fdopen**. Não as use se você quiser preservar a portabilidade ANSI.

Se **t** ou **b** não for fornecido no *modo*, o modo de tradução padrão será definido pela variável [ \_global fmode](../../c-runtime-library/fmode.md). Se **t** ou **b** for prefixado para o argumento, a função falhará e retornará NULL. Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

Os caracteres válidos para a cadeia de caracteres de *modo* usada em **fopen** e **_fdopen** correspondem aos argumentos *oflag* usados em [ \_Open](open-wopen.md) e [ \_sopen](sopen-wsopen.md), conforme mostrado nesta tabela:

|Caracteres no *modo* String|Valor equivalente de *oflag* para **_open** e **_sopen**|
|---------------------------------|---------------------------------------------------|
|**a**|**\_O\_ &#124; WRONLYoAppend\_(geralmente o WRONLY o CRI o \_** **\_ &#124; \_ &#124; \_ \_ \_\_ ACRESCENTAR**)|
|**a +**|**\_O\_ &#124; RDWRoAppend\_(geralmente o RDWR o Append o CR \_** **\_ &#124; \_ &#124; \_ \_ \_\_**  )|
|**r**|**\_O\_RDONLY**|
|**r+**|**\_O\_RDWR**|
|**w**|**\_O\_WRONLY** (geralmente  **\_oWRONLY\_ &#124; o CRI otrunc\_) &#124; \_\_ \_**|
|**w+**|**\_O\_RDWR** (geralmente  **\_oRDWR\_ &#124; o CRI otrunc\_) &#124; \_\_ \_**|
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

### <a name="input-crt_fdopentxt"></a>Entrada: crt_fdopen.txt

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
[\_abrir, \_wopen](open-wopen.md)<br/>
