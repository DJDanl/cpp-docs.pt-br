---
title: "_getw | Microsoft Docs"
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
  - "_getw"
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
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_getw"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _getw"
  - "Função getw"
  - "números inteiros, obtendo de fluxos"
ms.assetid: ef75facc-b84e-470f-9f5f-8746c90822a0
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _getw
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém um valor inteiro de um fluxo.  
  
## Sintaxe  
  
```  
int _getw(   
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## Valor de retorno  
 `_getw` retorna a leitura de valor inteiro.  Um valor de retorno `EOF` indica um erro ou a fim de arquivo.  Entretanto, como o valor de `EOF` também é um valor inteiro, use `feof` ou `ferror` legítimo verificar participante de Arquivo ou uma condição de erro.  Se `stream` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `errno` será definido como `EINVAL` e a função retornará `EOF`.  
  
## Comentários  
 A função de `_getw` ler o valor binário seguir do tipo `int` do arquivo associado com `stream` e incrementa o ponteiro de arquivo associado \(se houver\) para apontar para o caractere não lidas seguir.  `_getw` pressupõe que nenhum alinhamento especial de itens no fluxo.  Os problemas com mover podem ocorrer com `_getw` como o tamanho do tipo de `int` e a ordenação de bytes no tipo de `int` diferem nos sistemas.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_getw`|\<stdio.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_getw.c  
// This program uses _getw to read a word  
// from a stream, then performs an error check.  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   FILE *stream;  
   int i;  
  
   if( fopen_s( &stream, "crt_getw.txt", "rb" ) )  
      printf( "Couldn't open file\n" );  
   else  
   {  
      // Read a word from the stream:  
      i = _getw( stream );  
  
      // If there is an error...  
      if( ferror( stream ) )  
      {  
         printf( "_getw failed\n" );  
         clearerr_s( stream );  
      }  
      else  
         printf( "First data word in file: 0x%.4x\n", i );  
      fclose( stream );  
   }  
}  
```  
  
## Entrada: crt\_getw.txt  
  
```  
Line one.  
Line two.  
```  
  
### Saída  
  
```  
First data word in file: 0x656e694c  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_putw](../../c-runtime-library/reference/putw.md)