---
title: "malloc | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "malloc"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-heap-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "malloc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função malloc"
  - "alocação de memória"
ms.assetid: 144fcee2-be34-4a03-bb7e-ed6d4b99eea0
caps.latest.revision: 22
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# malloc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Atribui blocos de memória.  
  
## Sintaxe  
  
```  
void *malloc(  
   size_t size   
);  
```  
  
#### Parâmetros  
 `size`  
 Bytes para alocar.  
  
## Valor de retorno  
 `malloc` retorna um ponteiro nulo para o espaço alocado ou `NULL` se houver memória insuficiente disponível.  Para retornar um ponteiro para um tipo diferente `void`, use uma conversão de tipo no valor de retorno.  O espaço de armazenamento apontado pelo valor de retorno é garantido para ser alinhado corretamente para o armazenamento de qualquer tipo de objeto que tem um requisito de alinhamento menor ou igual ao de alinhamento fundamental. \(No Visual C\+\+, alinhamento fundamental é o alinhamento que é necessário para `double`, ou 8 bytes.  No código que se destina a plataformas de 64 bits, é de 16 bytes\). Use [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) para atribuir o armazenamento para os objetos que possuem um requisito de alinhamento maior, por exemplo, os tipos SSE [\_\_m128](../Topic/__m128.md) e `__m256`, e os tipos que são declarados usando `__declspec(align(``n``))` onde `n` é maior que 8.  Se `size` for 0, `malloc` alocará um item de comprimento zero no heap e retornará um ponteiro válido naquele item.  Sempre verifique o retorno de `malloc`, mesmo se a quantidade de memória solicitada for pequena.  
  
## Comentários  
 A função `malloc` atribui um bloco de memória de pelo menos `size` bytes.  O bloco pode ser maior do que `size` bytes devido ao espaço necessário para informações de alinhamento e manutenção.  
  
 `malloc` define `errno` a `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória solicitada exceder `_HEAP_MAXREQ`.  Para obter informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 O código de inicialização usa `malloc` para atribuir o armazenamento de `_environ`, `envp`, e variáveis de `argv` .  As funções a seguir e suas contrapartes de caracteres largos também chamam `malloc`.  
  
|||||  
|-|-|-|-|  
|[calloc](../../c-runtime-library/reference/calloc.md)|[fscanf](../../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md)|[\_getw](../../c-runtime-library/reference/getw.md)|[setvbuf](../../c-runtime-library/reference/setvbuf.md)|  
|[funções de \_exec](../../c-runtime-library/exec-wexec-functions.md)|[fseek](../../c-runtime-library/reference/fseek-fseeki64.md)|[\_popen](../../c-runtime-library/reference/popen-wpopen.md)|[funções de \_spawn](../Topic/_spawn,%20_wspawn%20Functions.md)|  
|[fgetc](../Topic/fgetc,%20fgetwc.md)|[fsetpos](../Topic/fsetpos.md)|[printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)|[\_strdup](../../c-runtime-library/reference/strdup-wcsdup-mbsdup.md)|  
|[\_fgetchar](../Topic/fgetc,%20fgetwc.md)|[\_fullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)|[putc](../../c-runtime-library/reference/putc-putwc.md)|[sistema](../../c-runtime-library/reference/system-wsystem.md)|  
|[fgets](../../c-runtime-library/reference/fgets-fgetws.md)|[fwrite](../Topic/fwrite.md)|[putchar](../../c-runtime-library/reference/putc-putwc.md)|[\_tempnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)|  
|[fprintf](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)|[getc](../../c-runtime-library/reference/getc-getwc.md)|[\_putenv](../../c-runtime-library/reference/putenv-wputenv.md)|[ungetc](../../c-runtime-library/reference/ungetc-ungetwc.md)|  
|[fputc](../../c-runtime-library/reference/fputc-fputwc.md)|[getchar](../../c-runtime-library/reference/getc-getwc.md)|[puts](../Topic/puts,%20_putws.md)|[vfprintf](../../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)|  
|[\_fputchar](../../c-runtime-library/reference/fputc-fputwc.md)|[\_getcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)|[\_putw](../../c-runtime-library/reference/putw.md)|[vprintf](../../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md)|  
|[fputs](../Topic/fputs,%20fputws.md)|[\_getdcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)|[scanf](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)||  
|[fread](../../c-runtime-library/reference/fread.md)|[gets](../../c-runtime-library/gets-getws.md)|[\_searchenv](../../c-runtime-library/reference/searchenv-wsearchenv.md)||  
  
 A função C\+\+ [\_set\_new\_mode](../../c-runtime-library/reference/set-new-mode.md) define o novo modo do manipulador para `malloc`.  O novo modo de manipulador indica se, em caso de falha, `malloc` deve chamar a nova rotina do manipulador conforme definido por [\_set\_new\_handler](../Topic/_set_new_handler.md).  Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha para alocar memória.  Você pode substituir esse comportamento padrão para que, quando `malloc` não aloca memória, `malloc` chama a nova rotina de manipulador da mesma forma que o operador de `new` faz quando falha pela mesma razão.  Para substituir o padrão, chame  
  
```cpp  
_set_new_mode(1)  
```  
  
 no início do seu programa, ou no link com NEWMODE.OBJ \(consulte [Opções de link](../Topic/Link%20Options.md)\).  
  
 Quando o aplicativo é associado com uma versão de depuração das bibliotecas em tempo de execução de C, `malloc` resolve a [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md).  Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 `malloc` está marcado como `__declspec(noalias)` e `__declspec(restrict)`; isso significa que é garantido que a função não alterará variáveis globais e que o ponteiro retornado não terá um alias.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`malloc`|\<stdlib.h\> e \<malloc.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```c  
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
  
  **O espaço de memória alocado para o nome de caminho**  
**Memória liberada**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md)