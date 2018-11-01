---
title: malloc
ms.date: 11/04/2016
apiname:
- malloc
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
- api-ms-win-crt-heap-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- malloc
helpviewer_keywords:
- malloc function
- memory allocation
ms.assetid: 144fcee2-be34-4a03-bb7e-ed6d4b99eea0
ms.openlocfilehash: e6a007fb6f089ebf1c9f5fc9ce59cbcbf0b13888
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50520361"
---
# <a name="malloc"></a>malloc

Aloca os blocos de memória.

## <a name="syntax"></a>Sintaxe

```C
void *malloc(
   size_t size
);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Bytes para alocar.

## <a name="return-value"></a>Valor de retorno

**malloc** retorna um ponteiro nulo para o espaço alocado, ou **nulo** se há memória suficiente disponível. Para retornar um ponteiro para um tipo diferente de **void**, use uma conversão no valor de retorno de tipo. O espaço de armazenamento apontado pelo valor retornado é garantido para ser sutilmente alinhado para armazenamento de qualquer tipo de objeto que tenha um requisito de alinhamento menor ou igual ao alinhamento fundamental. (No Visual C++, o alinhamento fundamental é o alinhamento que é necessário para um **duplas**, ou 8 bytes. No código que direciona plataformas de 64 bits, ele tem 16 bytes.) Use [aligned_malloc](aligned-malloc.md) alocar armazenamento para objetos que têm um requisito de alinhamento maior — por exemplo, os tipos SSE [__m128](../../cpp/m128.md) e **__m256**e os tipos que são declarado usando `__declspec(align( n ))` onde **n** é maior que 8. Se *tamanho* é 0, o **malloc** alocará um item de comprimento zero no heap e retorna um ponteiro válido para aquele item. Sempre verifique o retorno de **malloc**, mesmo que a quantidade de memória solicitada seja pequena.

## <a name="remarks"></a>Comentários

O **malloc** função aloca um bloco de memória de pelo menos *tamanho* bytes. O bloco pode ser maior que *tamanho* bytes por causa do espaço necessário para obter informações de alinhamento e manutenção.

**malloc** define **errno** à **ENOMEM** se uma alocação de memória falhar ou se a quantidade de memória solicitada exceder **heap_maxreq**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Usa o código de inicialização **malloc** alocar armazenamento para o **Environ**, *envp*, e *argv* variáveis. As seguintes funções e suas contrapartes de caractere largo também chamam **malloc**.

|||||
|-|-|-|-|
|[calloc](calloc.md)|[fscanf](fscanf-fscanf-l-fwscanf-fwscanf-l.md)|[_getw](getw.md)|[setvbuf](setvbuf.md)|
|[Funções _exec](../../c-runtime-library/exec-wexec-functions.md)|[fseek](fseek-fseeki64.md)|[_popen](popen-wpopen.md)|[Funções _spawn](../../c-runtime-library/spawn-wspawn-functions.md)|
|[fgetc](fgetc-fgetwc.md)|[fsetpos](fsetpos.md)|[printf](printf-printf-l-wprintf-wprintf-l.md)|[_strdup](strdup-wcsdup-mbsdup.md)|
|[_fgetchar](fgetc-fgetwc.md)|[_fullpath](fullpath-wfullpath.md)|[putc](putc-putwc.md)|[system](system-wsystem.md)|
|[fgets](fgets-fgetws.md)|[fwrite](fwrite.md)|[putchar](putc-putwc.md)|[_tempnam](tempnam-wtempnam-tmpnam-wtmpnam.md)|
|[fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md)|[getc](getc-getwc.md)|[_putenv](putenv-wputenv.md)|[ungetc](ungetc-ungetwc.md)|
|[fputc](fputc-fputwc.md)|[getchar](getc-getwc.md)|[puts](puts-putws.md)|[vfprintf](vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)|
|[_fputchar](fputc-fputwc.md)|[_getcwd](getcwd-wgetcwd.md)|[_putw](putw.md)|[vprintf](vprintf-vprintf-l-vwprintf-vwprintf-l.md)|
|[fputs](fputs-fputws.md)|[_getdcwd](getcwd-wgetcwd.md)|[scanf](scanf-scanf-l-wscanf-wscanf-l.md)||
|[fread](fread.md)|[gets](../../c-runtime-library/gets-getws.md)|[_searchenv](searchenv-wsearchenv.md)||

A função de C++ [set_new_mode](set-new-mode.md) define o novo modo do manipulador para **malloc**. O novo modo do manipulador indica se, em caso de falha, **malloc** é chamar a nova rotina do manipulador conforme definido pela [set_new_handler](set-new-handler.md). Por padrão, **malloc** não chama a nova rotina do manipulador em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando **malloc** falhar ao alocar memória, **malloc** chame a nova rotina do manipulador da mesma forma que o **novo** operador faz Quando ele falha pelo mesmo motivo. Para substituir o padrão, chame `_set_new_mode(1)` no início do seu programa ou vincule com NEWMODE. OBJ (consulte [opções de Link](../../c-runtime-library/link-options.md)).

Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas de tempo de execução C, **malloc** resolve [malloc_dbg](malloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [CRT Debug Heap Details](/visualstudio/debugger/crt-debug-heap-details) (Detalhes do heap de depuração CRT).

**malloc** está marcada `__declspec(noalias)` e `__declspec(restrict)`; isso significa que a função não é garantido que modifica variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**malloc**|\<stdlib.h> e \<malloc.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_malloc.c
// This program allocates memory with
// malloc, then frees the memory with free.

#include <stdlib.h>   // For _MAX_PATH definition
#include <stdio.h>
#include <malloc.h>

int main( void )
{
   char *string;

   // Allocate space for a path name
   string = malloc( _MAX_PATH );

   // In a C++ file, explicitly cast malloc's return.  For example,
   // string = (char *)malloc( _MAX_PATH );

   if( string == NULL )
      printf( "Insufficient memory available\n" );
   else
   {
      printf( "Memory space allocated for path name\n" );
      free( string );
      printf( "Memory freed\n" );
   }
}
```

```Output
Memory space allocated for path name
Memory freed
```

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[free](free.md)<br/>
[realloc](realloc.md)<br/>
[_aligned_malloc](aligned-malloc.md)<br/>
