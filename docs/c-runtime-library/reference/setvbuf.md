---
title: setvbuf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: setvbuf
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
f1_keywords: setvbuf
dev_langs: C++
helpviewer_keywords:
- controlling stream buffering
- stream buffering
- setvbuf function
ms.assetid: 6aa5aa37-3408-4fa0-992f-87f9f9c4baea
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: b5020a0186399ec35fb42a0479f7466318c45c18
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="setvbuf"></a>setvbuf
Controla o tamanho do buffer e o buffer de fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int setvbuf(  
   FILE *stream,  
   char *buffer,  
   int mode,  
   size_t size   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
 `buffer`  
 Buffer alocado pelo usuário.  
  
 `mode`  
 Modo de buffer.  
  
 `size`  
 O tamanho do buffer, em bytes. Intervalo permitido: 2 <= `size` <= INT_MAX (2147483647). Internamente, o valor fornecido para `size` é arredondado para baixo até o múltiplo mais próximo de 2.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna 0 se for bem-sucedido.  
  
 Se `stream` é `NULL` ou então se `mode` ou `size` não está dentro de uma alteração válida, o manipulador de parâmetro inválido é invocado, conforme a descrição em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará um valor –1 e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `setvbuf` permite que o programa controle o buffer e o tamanho do buffer para `stream`. `stream` deve se referir a um arquivo aberto que não passou por uma operação de E/S desde que foi aberto. A matriz para a qual `buffer` aponta é usada como o buffer, a menos que ele seja `NULL`, caso em que `setvbuf` utiliza um buffer alocado automaticamente com comprimento de `size`/2 * 2 bytes.  
  
 O modo deve ser `_IOFBF`, `_IOLBF` ou `_IONBF`. Se `mode` é `_IOFBF` ou `_IOLBF`, `size` é usado como o tamanho do buffer. Se `mode` é `_IONBF`, o fluxo é sem buffer e `size` e `buffer` são ignorados. Valores de `mode` e seus significados são:  
  
 `_IOFBF`  
 Buffer completo; ou seja, `buffer` é usado como o buffer e `size` é usado como o tamanho do buffer. Se `buffer` é `NULL`, um buffer alocado automaticamente com `size` bytes de comprimento é usado.  
  
 `_IOLBF`  
 Para alguns sistemas, isso fornece buffer em linha. No entanto, para o Win32, o comportamento é o mesmo que `_IOFBF` – buffer completo.  
  
 `_IONBF`  
 Nenhum buffer é usado, independentemente de `buffer` ou `size`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`setvbuf`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_setvbuf.c  
// This program opens two streams: stream1  
// and stream2. It then uses setvbuf to give stream1 a  
// user-defined buffer of 1024 bytes and stream2 no buffer.  
//  
  
#include <stdio.h>  
  
int main( void )  
{  
   char buf[1024];  
   FILE *stream1, *stream2;  
  
   if( fopen_s( &stream1, "data1", "a" ) == 0 &&  
       fopen_s( &stream2, "data2", "w" ) == 0 )  
   {  
      if( setvbuf( stream1, buf, _IOFBF, sizeof( buf ) ) != 0 )  
         printf( "Incorrect type or size of buffer for stream1\n" );  
      else  
         printf( "'stream1' now has a buffer of 1024 bytes\n" );  
      if( setvbuf( stream2, NULL, _IONBF, 0 ) != 0 )  
         printf( "Incorrect type or size of buffer for stream2\n" );  
      else  
         printf( "'stream2' now has no buffer\n" );  
      _fcloseall();  
   }  
}  
```  
  
```Output  
'stream1' now has a buffer of 1024 bytes  
'stream2' now has no buffer  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fclose, _fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [fflush](../../c-runtime-library/reference/fflush.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [setbuf](../../c-runtime-library/reference/setbuf.md)