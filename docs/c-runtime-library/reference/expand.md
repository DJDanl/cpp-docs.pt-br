---
title: _expand | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _expand
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
- _bexpand
- fexpand
- expand
- nexpand
- _fexpand
- _nexpand
- bexpand
- _expand
dev_langs:
- C++
helpviewer_keywords:
- memory blocks, changing size
- _expand function
- expand function
ms.assetid: 4ac55410-39c8-45c7-bccd-3f1042ae2ed3
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: d02e1ae2ec08a3fcd93700acb84c918f83088b1f
ms.lasthandoff: 02/25/2017

---
# <a name="expand"></a>_expand
Altera o tamanho de um bloco de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_expand(   
   void *memblock,  
   size_t size   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 Ponteiro para o bloco de memória alocado anteriormente.  
  
 `size`  
 Novo tamanho em bytes.  
  
## <a name="return-value"></a>Valor de retorno  
 `_expand` retorna um ponteiro nulo para o bloco de memória realocado. `_expand`, diferentemente de `realloc`, não pode mover um bloco para alterar seu tamanho. Portanto, se houver memória suficiente disponível para expandir o bloco sem movê-lo, o parâmetro `memblock` para `_expand` é o mesmo que o valor retornado.  
  
 `_expand` retorna `NULL` quando um erro é detectado durante sua operação. Por exemplo, se `_expand` é usado para reduzir um bloco de memória, ele pode detectar corrupção de heap de bloco pequeno ou um ponteiro de bloco inválido e retornar `NULL`.  
  
 Se houver memória insuficiente disponível para expandir o bloco para determinado tamanho sem movê-lo, a função retornará `NULL`. `_expand` nunca retorna um bloco expandido para um tamanho menor do que o solicitado. Se ocorrer uma falha, `errno` indicará a natureza da falha. Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para verificar o novo tamanho do item, use `_msize`. Para obter um ponteiro para um tipo que não seja `void`, use uma conversão de tipo no valor retornado.  
  
## <a name="remarks"></a>Comentários  
 A função `_expand` altera o tamanho de um bloco de memória alocado anteriormente ao tentar expandir ou recolher o bloco sem mover seu local no heap. O parâmetro `memblock` aponta para o início do bloco. O parâmetro `size` fornece o novo tamanho do bloco, em bytes. O conteúdo do bloco é inalterado até o menor dos tamanhos novos e antigos. `memblock` não deve ser um bloco que foi liberado.  
  
> [!NOTE]
>  Em plataformas de 64 bits, `_expand` não pode reduzir o bloco se o novo tamanho for menor que o tamanho atual, em particular, se o bloco for menor que 16K em tamanho e, portanto, alocado no heap de fragmentação baixo, `_expand` deixará o bloco inalterado e retornará `memblock`.  
  
 Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas de tempo de execução C, `_expand` será resolvido como [_expand_dbg](../../c-runtime-library/reference/expand-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).  
  
 Essa função valida seus parâmetros. Se `memblock` for um ponteiro nulo, a função invocará um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`. Se `size` for maior do que `_HEAP_MAXREQ`, `errno` será definido como `ENOMEM` e a função retornará `NULL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_expand`|\<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_expand.c  
  
#include <stdio.h>  
#include <malloc.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   char *bufchar;  
   printf( "Allocate a 512 element buffer\n" );  
   if( (bufchar = (char *)calloc( 512, sizeof( char ) )) == NULL )  
      exit( 1 );  
   printf( "Allocated %d bytes at %Fp\n",   
         _msize( bufchar ), (void *)bufchar );  
   if( (bufchar = (char *)_expand( bufchar, 1024 )) == NULL )  
      printf( "Can't expand" );  
   else  
      printf( "Expanded block to %d bytes at %Fp\n",   
            _msize( bufchar ), (void *)bufchar );  
   // Free memory   
   free( bufchar );  
   exit( 0 );  
}  
```  
  
```Output  
Allocate a 512 element buffer  
Allocated 512 bytes at 002C12BC  
Expanded block to 1024 bytes at 002C12BC  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [_msize](../../c-runtime-library/reference/msize.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)
