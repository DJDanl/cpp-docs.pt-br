---
title: fseek, _fseeki64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _fseeki64
- fseek
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
apitype: DLLExport
f1_keywords:
- fseek
- _fseeki64
dev_langs:
- C++
helpviewer_keywords:
- _fseeki64 function
- fseeki64 function
- fseek function
- file pointers [C++], moving
- file pointers [C++]
- seek file pointers
ms.assetid: f6bb1f8b-891c-426e-9e14-0e7e5c62df70
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4dd4c4e6550946bafdaf0ad8f521e1e942ae04c1
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fseek-fseeki64"></a>fseek, _fseeki64
Move o ponteiro do arquivo para um local especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fseek(   
   FILE *stream,  
   long offset,  
   int origin   
);  
int _fseeki64(   
   FILE *stream,  
   __int64 offset,  
   int origin   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
 `offset`  
 Número de bytes de `origin`.  
  
 `origin`  
 Posição inicial.  
  
## <a name="return-value"></a>Valor de retorno  
 Em caso de sucesso, `fseek` e `_fseeki64` retornarão 0. Caso contrário, retornará um valor diferente de zero. Em dispositivos sem capacidade de busca, o valor retornado será indefinido. Se `stream` for um ponteiro nulo ou `origin` não for um dos valores permitidos descritos abaixo, `fseek` e `_fseeki64` invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1.  
  
## <a name="remarks"></a>Comentários  
 O `fseek` e `_fseeki64` move o ponteiro do arquivo (se houver) associado com as funções `stream` para um novo local é `offset` bytes do `origin`. A operação seguinte no fluxo ocorre no novo local. Em um fluxo aberto para atualização, a operação seguinte pode ser uma leitura ou uma gravação. A origem do argumento deve ser uma das constantes a seguir, definidas em STDIO.H:  
  
 `SEEK_CUR`  
 Posição atual do ponteiro de arquivo.  
  
 `SEEK_END`  
 Final do arquivo.  
  
 `SEEK_SET`  
 Início do arquivo.  
  
 Você pode usar `fseek` e `_fseeki64` para reposicionar o ponteiro em qualquer lugar de um arquivo. O ponteiro também pode ser posicionado após o final do arquivo. `fseek` e `_fseeki64` limpa o indicador de fim de arquivo e nega o efeito de qualquer antes `ungetc` chamadas `stream`.  
  
 Quando um arquivo é aberto para acrescentar dados, a posição do arquivo atual é determinada pela última operação de E/S e não por onde a gravação seguinte ocorreria. Se nenhuma operação de E/S tiver ocorrido em um arquivo aberto para acréscimo, a posição do arquivo será o início do arquivo.  
  
 Para fluxos abertos no modo de texto, `fseek` e `_fseeki64` limitaram uso, como conversões de avanço de linha de retorno de carro podem causar `fseek` e `_fseeki64` para produzir resultados inesperados. A única `fseek` e `_fseeki64` operações garantidas em fluxos abertos no modo de texto são:  
  
-   buscar com um deslocamento de 0 em relação a qualquer um dos valores de origem.  
  
-   Busca do início do arquivo com um valor de deslocamento retornado de uma chamada para `ftell` ao usar `fseek` ou `_ftelli64` ao usar `_fseeki64`.  
  
 Também no modo de texto, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/gravação, `fopen` e todas as rotinas relacionadas verificam se há um CTRL+Z no fim do arquivo e o removem, se possível. Isso é feito porque usar a combinação de `fseek` e `ftell` ou de `_fseeki64` e `_ftelli64` para movimentação dentro de um arquivo que termina com CTRL+Z pode fazer com que `fseek` ou `_fseeki64` se comporte incorretamente perto do fim do arquivo.  
  
 Quando o CRT abre um arquivo que começa com uma BOM (marca de ordem de byte), o ponteiro do arquivo é posicionado após a BOM (ou seja, no início do conteúdo real do arquivo). Se você precisar `fseek` no início do arquivo, use `ftell` para obter a posição inicial e `fseek` a ele em vez de posicionar 0.  
  
 Essa função bloqueia outros threads durante a execução e, portanto, é thread-safe. Para obter uma versão sem bloqueio, consulte [fseek_nolock, _fseeki64_nolock](../../c-runtime-library/reference/fseek-nolock-fseeki64-nolock.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fseek`|\<stdio.h>|  
|`_fseeki64`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fseek.c  
// This program opens the file FSEEK.OUT and  
// moves the pointer to the file's beginning.  
  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   char line[81];  
   int  result;  
  
   if ( fopen_s( &stream, "fseek.out", "w+" ) != 0 )  
   {  
      printf( "The file fseek.out was not opened\n" );  
      return -1;  
   }  
   fprintf( stream, "The fseek begins here: "  
                    "This is the file 'fseek.out'.\n" );  
   result = fseek( stream, 23L, SEEK_SET);  
   if( result )  
      perror( "Fseek failed" );  
   else  
   {  
      printf( "File pointer is set to middle of first line.\n" );  
      fgets( line, 80, stream );  
      printf( "%s", line );  
    }  
   fclose( stream );  
}  
```  
  
```Output  
File pointer is set to middle of first line.  
This is the file 'fseek.out'.  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [ftell, _ftelli64](../../c-runtime-library/reference/ftell-ftelli64.md)   
 [_lseek, _lseeki64](../../c-runtime-library/reference/lseek-lseeki64.md)   
 [rewind](../../c-runtime-library/reference/rewind.md)