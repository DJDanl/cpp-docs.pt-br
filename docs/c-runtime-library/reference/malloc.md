---
title: malloc
ms.date: 4/2/2020
api_name:
- malloc
- _o_malloc
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
- api-ms-win-crt-heap-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- malloc
helpviewer_keywords:
- malloc function
- memory allocation
ms.assetid: 144fcee2-be34-4a03-bb7e-ed6d4b99eea0
ms.openlocfilehash: 4e699920f37139be40542ba91b3740cd9edef148
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82917509"
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

## <a name="return-value"></a>Valor retornado

**malloc** retorna um ponteiro void para o espaço alocado ou **NULL** se não houver memória suficiente disponível. Para retornar um ponteiro para um tipo diferente de **void**, use uma conversão de tipo no valor de retorno. O espaço de armazenamento apontado pelo valor retornado é garantido para ser sutilmente alinhado para armazenamento de qualquer tipo de objeto que tenha um requisito de alinhamento menor ou igual ao alinhamento fundamental. (No Visual C++, o alinhamento fundamental é o alinhamento necessário para um **duplo**, ou 8 bytes. No código que tem como destino plataformas de 64 bits, é 16 bytes.) Use [_aligned_malloc](aligned-malloc.md) para alocar armazenamento para objetos que têm um requisito de alinhamento maior — por exemplo, os tipos de SSE [__m128](../../cpp/m128.md) e **__m256**e os tipos declarados usando `__declspec(align( n ))` onde **n** é maior que 8. Se o *tamanho* for 0, **malloc** alocará um item de comprimento zero no heap e retornará um ponteiro válido para esse item. Sempre verifique o retorno de **malloc**, mesmo se a quantidade de memória solicitada for pequena.

## <a name="remarks"></a>Comentários

A função **malloc** aloca um bloco de memória de pelo menos bytes de *tamanho* . O bloco pode ser maior que o *tamanho* em bytes devido ao espaço necessário para informações de alinhamento e manutenção.

**malloc** define **errno** como **ENOMEM** se uma alocação de memória falhar ou se a quantidade de memória solicitada excede **_HEAP_MAXREQ**. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

O código de inicialização usa **malloc** para alocar armazenamento para as variáveis **_environ**, *envp*e *argv* . As funções a seguir e suas contrapartes de caracteres largos também chamam **malloc**.

|||||
|-|-|-|-|
|[calloc](calloc.md)|[fscanf](fscanf-fscanf-l-fwscanf-fwscanf-l.md)|[_getw](getw.md)|[setvbuf](setvbuf.md)|
|[Funções _exec](../../c-runtime-library/exec-wexec-functions.md)|[fseek](fseek-fseeki64.md)|[_popen](popen-wpopen.md)|[Funções _spawn](../../c-runtime-library/spawn-wspawn-functions.md)|
|[fgetc](fgetc-fgetwc.md)|[fsetpos](fsetpos.md)|[printf](printf-printf-l-wprintf-wprintf-l.md)|[_strdup](strdup-wcsdup-mbsdup.md)|
|[_fgetchar](fgetc-fgetwc.md)|[_fullpath](fullpath-wfullpath.md)|[putc](putc-putwc.md)|[sistema](system-wsystem.md)|
|[fgets](fgets-fgetws.md)|[fwrite](fwrite.md)|[putchar](putc-putwc.md)|[_tempnam](tempnam-wtempnam-tmpnam-wtmpnam.md)|
|[fprintf](fprintf-fprintf-l-fwprintf-fwprintf-l.md)|[getc](getc-getwc.md)|[_putenv](putenv-wputenv.md)|[ungetc](ungetc-ungetwc.md)|
|[fputc](fputc-fputwc.md)|[GetChar](getc-getwc.md)|[puts](puts-putws.md)|[vfprintf](vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)|
|[_fputchar](fputc-fputwc.md)|[_getcwd](getcwd-wgetcwd.md)|[_putw](putw.md)|[vprintf](vprintf-vprintf-l-vwprintf-vwprintf-l.md)|
|[fputs](fputs-fputws.md)|[_getdcwd](getcwd-wgetcwd.md)|[scanf](scanf-scanf-l-wscanf-wscanf-l.md)||
|[fread](fread.md)|[visível](../../c-runtime-library/gets-getws.md)|[_searchenv](searchenv-wsearchenv.md)||

A função de C++ [set_new_mode](set-new-mode.md) define o novo modo do manipulador para **malloc**. O novo modo de manipulador indica se, em caso de falha, **malloc** é chamar a nova rotina do manipulador, conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, o **malloc** não chama a nova rotina do manipulador em caso de falha para alocar memória. Você pode substituir esse comportamento padrão para que, quando **malloc** não alocar memória, **malloc** chame a nova rotina do manipulador da mesma maneira que o **novo** operador faz quando ele falha pelo mesmo motivo. Para substituir o padrão, chame `_set_new_mode(1)` no início do programa ou VINCULE com NEWMODE. OBJ (consulte [Opções de link](../../c-runtime-library/link-options.md)).

Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução do C, o **malloc** é resolvido para [_malloc_dbg](malloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [CRT Debug Heap Details](/visualstudio/debugger/crt-debug-heap-details) (Detalhes do heap de depuração CRT).

**malloc** está marcado `__declspec(noalias)` como `__declspec(restrict)`e; Isso significa que a função está garantida para não modificar variáveis globais e que o ponteiro retornado não tem um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**malloc**|\<stdlib.h> e \<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

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

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[informações](free.md)<br/>
[realloc](realloc.md)<br/>
[_aligned_malloc](aligned-malloc.md)<br/>
