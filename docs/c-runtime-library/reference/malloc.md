---
title: malloc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
helpviewer_keywords:
- malloc function
- memory allocation
ms.assetid: 144fcee2-be34-4a03-bb7e-ed6d4b99eea0
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 3c024862e1bf993c4e602846d4da125599f3fe7f
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="malloc"></a>malloc
Aloca os blocos de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *malloc(  
   size_t size   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `size`  
 Bytes para alocar.  
  
## <a name="return-value"></a>Valor de retorno  
 `malloc` retornará um ponteiro nulo para o espaço alocado ou `NULL` se houver memória suficiente disponível. Para retornar um ponteiro para um tipo que não seja o `void`, digite a conversão no valor retornado. O espaço de armazenamento apontado pelo valor retornado é garantido para ser sutilmente alinhado para armazenamento de qualquer tipo de objeto que tenha um requisito de alinhamento menor ou igual ao alinhamento fundamental. (No Visual C++, o alinhamento fundamental é o alinhamento necessário para um `double` ou 8 bytes. No código que direciona plataformas de 64 bits, ele tem 16 bytes.) Use [aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) para alocar armazenamento para objetos que tenham um requisito de alinhamento maior — por exemplo, os tipos SSE [__m128](../../cpp/m128.md) e `__m256` e os tipos que são declarados por usar `__declspec(align(``n``))`, em que `n` é maior que 8. Se `size` for 0, `malloc` alocará um item de comprimento zero no heap e retornará um ponteiro válido para esse item. Sempre verifique o retorno de `malloc`, mesmo que a quantidade de memória solicitada seja pequena.  
  
## <a name="remarks"></a>Comentários  
 A função `malloc` aloca um bloco de memória de, pelo menos, `size` bytes. O bloco pode ser maior que `size` bytes por causa do espaço necessário para as informações de alinhamento e manutenção.  
  
 `malloc` definirá `errno` como `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória solicitada exceder `_HEAP_MAXREQ`. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 O código de inicialização usa `malloc` para alocar armazenamento para as variáveis `_environ`, `envp` e `argv`. As seguintes funções e suas contrapartes de caractere largo também chamam `malloc`.  
  
|||||  
|-|-|-|-|  
|[calloc](../../c-runtime-library/reference/calloc.md)|[fscanf](../../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md)|[_getw](../../c-runtime-library/reference/getw.md)|[setvbuf](../../c-runtime-library/reference/setvbuf.md)|  
|[Funções _exec](../../c-runtime-library/exec-wexec-functions.md)|[fseek](../../c-runtime-library/reference/fseek-fseeki64.md)|[_popen](../../c-runtime-library/reference/popen-wpopen.md)|[Funções _spawn](../../c-runtime-library/spawn-wspawn-functions.md)|  
|[fgetc](../../c-runtime-library/reference/fgetc-fgetwc.md)|[fsetpos](../../c-runtime-library/reference/fsetpos.md)|[printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)|[_strdup](../../c-runtime-library/reference/strdup-wcsdup-mbsdup.md)|  
|[_fgetchar](../../c-runtime-library/reference/fgetc-fgetwc.md)|[_fullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)|[putc](../../c-runtime-library/reference/putc-putwc.md)|[system](../../c-runtime-library/reference/system-wsystem.md)|  
|[fgets](../../c-runtime-library/reference/fgets-fgetws.md)|[fwrite](../../c-runtime-library/reference/fwrite.md)|[putchar](../../c-runtime-library/reference/putc-putwc.md)|[_tempnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)|  
|[fprintf](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)|[getc](../../c-runtime-library/reference/getc-getwc.md)|[_putenv](../../c-runtime-library/reference/putenv-wputenv.md)|[ungetc](../../c-runtime-library/reference/ungetc-ungetwc.md)|  
|[fputc](../../c-runtime-library/reference/fputc-fputwc.md)|[getchar](../../c-runtime-library/reference/getc-getwc.md)|[puts](../../c-runtime-library/reference/puts-putws.md)|[vfprintf](../../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)|  
|[_fputchar](../../c-runtime-library/reference/fputc-fputwc.md)|[_getcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)|[_putw](../../c-runtime-library/reference/putw.md)|[vprintf](../../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md)|  
|[fputs](../../c-runtime-library/reference/fputs-fputws.md)|[_getdcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)|[scanf](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)||  
|[fread](../../c-runtime-library/reference/fread.md)|[gets](../../c-runtime-library/gets-getws.md)|[_searchenv](../../c-runtime-library/reference/searchenv-wsearchenv.md)||  
  
 A função de C++ [set_new_mode](../../c-runtime-library/reference/set-new-mode.md) define o novo modo manipulador para `malloc`. O novo modo do manipulador indica se, em caso de falha, `malloc` deverá chamar a nova rotina do manipulador conforme definido por [_set_new_handler](../../c-runtime-library/reference/set-new-handler.md). Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando `malloc` falhar ao alocar memória, `malloc` chame a nova rotina do manipulador da mesma forma que o operador `new` fará quando ele falhar pelo mesmo motivo. Para substituir o padrão, chame `_set_new_mode(1)` no início do seu programa, ou link com NEWMODE. OBJ (consulte [opções Link](../../c-runtime-library/link-options.md)).  
  
 Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas em tempo de execução de C, `malloc` será resolvido como [_malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [CRT Debug Heap Details](/visualstudio/debugger/crt-debug-heap-details) (Detalhes do heap de depuração CRT).  
  
 `malloc` está marcado como `__declspec(noalias)` e `__declspec(restrict)`; isto significa que há garantias de que a função não modificará as variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`malloc`|\<stdlib.h> e \<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
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
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md)

