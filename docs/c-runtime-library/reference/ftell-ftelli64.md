---
title: ftell, _ftelli64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _ftelli64
- ftell
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
- _ftelli64
- ftell
dev_langs:
- C++
helpviewer_keywords:
- ftell function
- ftelli64 function
- _ftelli64 function
- file pointers [C++], getting current position
- file pointers [C++]
ms.assetid: 40149cd8-65f2-42ff-b70c-68e3e918cdd7
caps.latest.revision: 19
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
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 220b34e5bba7a4a6716d6ef18d6621b58d36ecc3
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="ftell-ftelli64"></a>ftell, _ftelli64
Obtém a posição atual de um ponteiro de arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
long ftell(   
   FILE *stream   
);  
__int64 _ftelli64(   
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Estrutura `FILE` de destino.  
  
## <a name="return-value"></a>Valor de retorno  
 `ftell` e `_ftelli64` retornam a posição do arquivo atual. O valor retornado por `ftell` e `_ftelli64` podem não refletir o deslocamento de byte físico para fluxos aberto no modo de texto, como o modo de texto faz com que a conversão de avanço de linha de retorno de carro. Use `ftell` com `fseek` ou `_ftelli64` com `_fseeki64` para retornar para locais de arquivo corretamente. Em erro, `ftell` e `_ftelli64` invocar o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam L-1 e o conjunto `errno` a uma das duas constantes, definidos em ERRNO. H. A constante `EBADF` significa que o argumento `stream` não é um valor de ponteiro de arquivo válido ou não faz referência a um arquivo aberto. `EINVAL` significa que um argumento `stream` inválido foi passado para a função. Em dispositivos incapazes de fazer buscas (como terminais e impressoras) ou quando `stream` não se referir a um arquivo aberto, o valor retornado será indefinido.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
## <a name="remarks"></a>Comentários  
 O `ftell` e `_ftelli64` funções recuperam a posição atual do ponteiro do arquivo (se houver) associada `stream`. A posição é expressa como um deslocamento relativo ao início do fluxo.  
  
 Observe que quando um arquivo é aberto para acrescentar dados, a posição do arquivo atual é determinada pela última operação de E/S e não por onde a gravação seguinte ocorreria. Por exemplo, se um arquivo for aberto para fazer um acréscimo e a última operação tiver sido uma leitura, a posição do arquivo será o ponto em que a operação de leitura seguinte começaria e não onde a próxima gravação começaria. (Quando um arquivo é aberto para fazer um acréscimo, a posição do arquivo é movida para o final do arquivo antes de qualquer operação de gravação.) Se nenhuma operação de E/S tiver ocorrido em um arquivo aberto para acréscimo, a posição do arquivo será o início do arquivo.  
  
 No modo de texto, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/gravação, `fopen` e todas as rotinas relacionadas verificam se há um CTRL+Z no fim do arquivo e o removem, se possível. Isso é feito porque usar a combinação de `ftell` e `fseek` ou de `_ftelli64` e `_fseeki64` para movimentação dentro de um arquivo que termina com CTRL+Z pode fazer com que `ftell` ou `_ftelli64` se comporte incorretamente perto do fim do arquivo.  
  
 Essa função bloqueia o thread de chamada durante a execução e, portanto, é thread-safe. Para uma versão sem bloqueio, consulte `_ftell_nolock`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalhos opcionais|  
|--------------|---------------------|----------------------|  
|`ftell`|\<stdio.h>|\<errno.h>|  
|`_ftelli64`|\<stdio.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_ftell.c  
// This program opens a file named CRT_FTELL.C  
// for reading and tries to read 100 characters. It  
// then uses ftell to determine the position of the  
// file pointer and displays this position.  
  
#include <stdio.h>  
  
FILE *stream;  
  
int main( void )  
{  
   long position;  
   char list[100];  
   if( fopen_s( &stream, "crt_ftell.c", "rb" ) == 0 )  
   {  
      // Move the pointer by reading data:   
      fread( list, sizeof( char ), 100, stream );  
      // Get position after read:   
      position = ftell( stream );  
      printf( "Position after trying to read 100 bytes: %ld\n",  
              position );  
      fclose( stream );  
   }  
}  
```  
  
```Output  
Position after trying to read 100 bytes: 100  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [fgetpos](../../c-runtime-library/reference/fgetpos.md)   
 [fseek, _fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md)   
 [_lseek, _lseeki64](../../c-runtime-library/reference/lseek-lseeki64.md)
