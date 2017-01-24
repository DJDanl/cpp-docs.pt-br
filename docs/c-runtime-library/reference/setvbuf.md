---
title: "setvbuf | Microsoft Docs"
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
  - "setvbuf"
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
  - "setvbuf"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "controlando buffer de fluxo"
  - "Função setvbuf"
  - "buffer de fluxo"
ms.assetid: 6aa5aa37-3408-4fa0-992f-87f9f9c4baea
caps.latest.revision: 16
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# setvbuf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Proteção e tamanho do buffer de fluxo de controle.  
  
## Sintaxe  
  
```  
int setvbuf(  
   FILE *stream,  
   char *buffer,  
   int mode,  
   size_t size   
);  
```  
  
#### Parâmetros  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
 `buffer`  
 Buffer usuário atribuído.  
  
 `mode`  
 Modo de proteção.  
  
 `size`  
 Tamanho do buffer em bytes.  Intervalo permitido: 2 \<\= `size` \<\= INT\_MAX \(2147483647\).  Internamente, o valor fornecido para `size` é arredondado para baixo para o múltiplo mais próximo de 2.  
  
## Valor de retorno  
 Retorna 0 se tiver êxito.  
  
 Se `stream` é `NULL`, ou se `mode` ou `size` não estão dentro de uma alteração válida, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, os essa função retornará \-1 e definirá `errno` a `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `setvbuf` permite que o programa controle a proteção e o tamanho do buffer para `stream`.  `stream` deve recorrer a um arquivo aberto que não se envie a uma operação de E\/S desde que foi aberta.  A matriz apontada por `buffer` é usada como o buffer, a menos que seja `NULL`, nesse caso `setvbuf` usa um buffer atribuído automaticamente de comprimento `size`\/2 \* 2 bytes.  
  
 O modo deve ser `_IOFBF`, `_IOLBF`, ou `_IONBF`.  Se `mode` é `_IOFBF` ou `_IOLBF`, então `size` será usado como o tamanho do buffer.  Se `mode` é `_IONBF`, o fluxo será não armazenado e `size` e `buffer` são ignorados.  Os valores para `mode` e seus significados são:  
  
 `_IOFBF`  
 Proteção completa; isto é, `buffer` é usado como o buffer e `size` são usados como o tamanho do buffer.  Se `buffer` é `NULL`, os bytes atribuídos automaticamente de `size` de um buffer são usados por muito tempo.  
  
 `_IOLBF`  
 Para alguns sistemas, isso fornece a linha proteção.  No entanto, para o Win32, o comportamento é o mesmo que `_IOFBF` \- proteção completa.  
  
 `_IONBF`  
 Nenhum buffer é usado, independentemente de `buffer` ou de `size`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`setvbuf`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
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
  
  **“stream1” tem um buffer de 1024 bytes**  
**“stream2” não tem nenhum buffer agora**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fclose, \_fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [fflush](../Topic/fflush.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [setbuf](../../c-runtime-library/reference/setbuf.md)