---
title: fread_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- fread_s
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
- fread_s
- stdio/fread_s
dev_langs:
- C++
ms.assetid: ce735de0-f005-435d-a8f2-6f4b80ac775e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5fedb1419b3558fc773933619de247cfd3685e06
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="freads"></a>fread_s
Lê dados de um fluxo. Esta versão de [fread](../../c-runtime-library/reference/fread.md) tem melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t fread_s(   
   void *buffer,  
   size_t bufferSize,  
   size_t elementSize,  
   size_t count,  
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `buffer`  
 Local de armazenamento de dados.  
  
 `bufferSize`  
 Tamanho do buffer de destino em bytes.  
  
 `elementSize`  
 Tamanho do item a ser lido em bytes.  
  
 `count`  
 Número máximo de itens a serem lidos.  
  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## <a name="return-value"></a>Valor de retorno  
 `fread_s` retorna o número de itens (inteiros) que foram lidos no buffer, que pode ser menor que `count` se ocorrer um erro de leitura ou se o final do arquivo for alcançado antes que `count` seja atingido. Use a função `feof` ou `ferror` para diferenciar um erro de uma condição de fim de arquivo. Se `size` ou `count` for 0, `fread_s` retornará 0 e o conteúdo do buffer permanecerá inalterado. Se `stream` ou `buffer` for um ponteiro nulo, `fread_s` invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função define `errno` como `EINVAL` e retorna 0.  
  
 Para obter mais informações sobre códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `fread_s` lê até `count` itens de `elementSize` bytes do `stream` de entrada e os armazena em `buffer`.  O ponteiro do arquivo associado a `stream` (se houver) é aumentado de acordo com a quantidade de bytes lidos. Se o fluxo fornecido é aberto no modo de texto, pares de avanço de linha de retorno de carro são substituídos por caracteres de avanço de linha única. A substituição não interfere no ponteiro do arquivo ou no valor retornado. A posição do ponteiro do arquivo será indeterminada se ocorrer um erro. O valor de um item lido parcialmente não pode ser determinado.  
  
 Essa função bloqueia outros threads. Se for requerida uma versão sem bloqueio, use `_fread_nolock`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fread_s`|\<stdio.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// crt_fread_s.c  
// Command line: cl /EHsc /nologo /W4 crt_fread_s.c  
//  
// This program opens a file that's named FREAD.OUT and  
// writes characters to the file. It then tries to open  
// FREAD.OUT and read in characters by using fread_s. If the attempt succeeds,  
// the program displays the number of actual items read.  
  
#include <stdio.h>  
  
#define BUFFERSIZE 30  
#define DATASIZE 22  
#define ELEMENTCOUNT 2  
#define ELEMENTSIZE (DATASIZE/ELEMENTCOUNT)  
#define FILENAME "FREAD.OUT"  
  
int main( void )  
{  
   FILE *stream;  
   char list[30];  
   int  i, numread, numwritten;  
  
   for ( i = 0; i < DATASIZE; i++ )  
      list[i] = (char)('z' - i);  
   list[DATASIZE] = '\0'; // terminal null so we can print it  
  
   // Open file in text mode:  
   if( fopen_s( &stream, FILENAME, "w+t" ) == 0 )  
   {  
      // Write DATASIZE characters to stream   
      printf( "Contents of buffer before write/read:\n\t%s\n\n", list );  
      numwritten = fwrite( list, sizeof( char ), DATASIZE, stream );  
      printf( "Wrote %d items\n\n", numwritten );  
      fclose( stream );  
   } else {  
      printf( "Problem opening the file\n" );  
      return -1;  
   }  
  
   if( fopen_s( &stream, FILENAME, "r+t" ) == 0 )   {  
      // Attempt to read in characters in 2 blocks of 11  
      numread = fread_s( list, BUFFERSIZE, ELEMENTSIZE, ELEMENTCOUNT, stream );  
      printf( "Number of %d-byte elements read = %d\n\n", ELEMENTSIZE, numread );  
      printf( "Contents of buffer after write/read:\n\t%s\n", list );  
      fclose( stream );  
   } else {  
      printf( "File could not be opened\n" );  
      return -1;  
   }  
}  
```  
  
```Output  
Contents of buffer before write/read:   
        zyxwvutsrqponmlkjihgfe  
  
Wrote 22 items  
  
Number of 11-byte elements read = 2  
  
Contents of buffer after write/read:   
        zyxwvutsrqponmlkjihgfe  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fwrite](../../c-runtime-library/reference/fwrite.md)   
 [_read](../../c-runtime-library/reference/read.md)