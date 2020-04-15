---
title: _fdopen, _wfdopen
ms.date: 4/2/2020
api_name:
- _fdopen
- _wfdopen
- _o__fdopen
- _o__wfdopen
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 82a7e891e8bd6031ebbf761534b6df7cd8488d36
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347382"
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

*Fd*<br/>
Descritor de arquivo do arquivo aberto.

*Modo*<br/>
Tipo de acesso do arquivo.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um ponteiro para o fluxo aberto. Um valor de ponteiro nulo indica um erro. Quando ocorre um erro, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, **errno** será definido como **EBADF**, o que indica um descritor de arquivo ruim, ou **EINVAL,** o que indica que *o modo* era um ponteiro nulo.

Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_fdopen** associa um fluxo de I/O com o arquivo identificado pelo *fd*, e assim permite que um arquivo aberto para I/O de baixo nível seja tamponado e formatado. **_wfdopen** é uma versão ampla do **_fdopen;** o argumento de *modo* para **_wfdopen** é uma seqüência de caracteres amplo. **_wfdopen** e **_fdopen** de outra forma se comportam de forma idêntica.

Descritores de arquivos passados para **_fdopen** são de propriedade do fluxo **de &#42;FILE** retornado. Se **_fdopen** for bem-sucedida, não ligue [ \_para perto](close.md) no descritor do arquivo. Chamar [fclose](fclose-fcloseall.md) no **arquivo** retornado &#42;também fecha o descritor de arquivo.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|\_UNICODE \_e MBCS não definidos|\_MBCS definido|\_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfdopen**|**_fdopen**|**_fdopen**|**_wfdopen**|

A seqüência de caracteres do *modo* especifica o tipo de acesso ao arquivo solicitado para o arquivo:

| *Modo* | Acesso |
|--------|--------|
| **"R"** | Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada **fopen** falhará. |
| **"W"** | Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos. |
| **"A"** | Abre para escrever no final do arquivo (anexo). Cria o arquivo se ele não existir. |
| **"r+"** | Abre para leitura e gravação. O arquivo deve existir. |
| **"W+"** | Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos. |
| **"a+"** | Abre para leitura e conexão. Cria o arquivo se ele não existir. |

Quando um arquivo é aberto com o tipo de acesso **"a"** ou **"a+",** todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [rebobinar,](rewind.md)mas é sempre movido de volta para o final do arquivo antes que qualquer operação de gravação seja realizada. Assim, os dados existentes não podem ser substituídos. Quando o tipo de acesso **"r+",** **"w+"** ou **"a+"** é especificado, tanto a leitura quanto a escrita são permitidas (o arquivo está aberto para "atualização"). No entanto, quando você alterna entre a leitura e a escrita, deve haver uma operação [de fflush,](fflush.md) [fsetpos,](fsetpos.md) [fseek](fseek-fseeki64.md)ou [rebobinar.](rewind.md) Você pode especificar a posição atual para a operação [fsetpos](fsetpos.md) ou [fseek,](fseek-fseeki64.md) se quiser.

Além dos valores acima, os seguintes caracteres também podem ser incluídos no *modo* para especificar o modo de tradução para caracteres newline:

| modificador *de modo* | Comportamento |
|-----------------|----------|
| **t** | Abra no modo de texto (convertido). Neste modo, combinações de CR-LF (retorno de carro – avanço de linha) são convertidas em LFs (avanços de uma linha) na entrada e caracteres de LF são convertidos em combinações de CR-LF na saída. Além disso, Ctrl+Z é interpretado como um caractere de fim do arquivo na entrada. |
| **B** | Abre no modo binário (não convertido). Todas as traduções do modo **T** são suprimidas. |
| **C** | Habilite o sinalizador de confirmação para o nome de *arquivo* associado para que o conteúdo do buffer de arquivo seja gravado diretamente no disco se for chamado **fflush** ou **_flushall.** |
| **n** | Redefinir o sinalizador de confirmação para o *nome de arquivo* associado para "não-compromisso". Esse é o padrão. Ele também substitui a bandeira de confirmação global se você vincular seu programa ao Commode.obj. O padrão global de bandeira de confirmação é "não-compromisso" a menos que você vincule explicitamente seu programa ao Commode.obj. |

As opções de *modo* **t,** **c**e **n** são extensões microsoft para **fopen** e **_fdopen**. Não as use se você quiser preservar a portabilidade ANSI.

Se **t** ou **b** não for dado no *modo,* o modo de tradução padrão é definido pela variável [ \_](../../c-runtime-library/fmode.md)global fmode . Se **t** ou **b forprefixado** ao argumento, a função falhará e retorna NULL. Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

Caracteres válidos para a seqüência *de modos* usados em **fopen** e **_fdopen** correspondem aos argumentos *oflag* usados em [ \_aberto](open-wopen.md) e [ \_aberto,](sopen-wsopen.md)como mostrado nesta tabela:

|Caracteres na seqüência *de modo*|Valor *equivalente de bandeira* para **_open** e **_sopen**|
|---------------------------------|---------------------------------------------------|
|**Um**|**\_O\_WRONLY \_\_&#124; O APPEND** (geralmente ** \_\_O WRONLY \_&#124; O\_CREAT \_&#124; O\_APPEND**)|
|**a+**|**\_O\_RDWR \_\_&#124; O APPEND** (geralmente ** \_\_O RDWR \_&#124; O APÊNDICE\_&#124; \_O\_CREAT)**|
|**r**|**\_O\_RDONLY**|
|**r+**|**\_O\_RDWR**|
|**w**|**\_O\_WRONLY** (geralmente ** \_\_O \_\_WRONLY \_&#124;\_O CREAT &#124; O TRUNC**)|
|**w+**|**\_O\_RDWR** (geralmente ** \_\_O \_\_RDWR \_&#124;\_O CREAT &#124; O TRUNC**)|
|**B**|**\_O\_BINÁRIO**|
|**t**|**\_O\_TEXTO**|
|**C**|Nenhum|
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

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[\_dup2 \_](dup-dup2.md)<br/>
[fclose, \_fcloseall](fclose-fcloseall.md)<br/>
[fopen, \_wfopen](fopen-wfopen.md)<br/>
[freopen, \_wfreopen](freopen-wfreopen.md)<br/>
[\_aberto, \_wopen](open-wopen.md)<br/>
