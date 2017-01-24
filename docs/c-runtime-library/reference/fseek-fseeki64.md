---
title: "fseek, _fseeki64 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_fseeki64"
  - "fseek"
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
apitype: "DLLExport"
f1_keywords: 
  - "fseek"
  - "_fseeki64"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fseeki64"
  - "ponteiros de arquivo [C++]"
  - "ponteiros de arquivo [C++], movendo"
  - "Função fseek"
  - "Função fseeki64"
  - "procurar ponteiros de arquivo"
ms.assetid: f6bb1f8b-891c-426e-9e14-0e7e5c62df70
caps.latest.revision: 23
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fseek, _fseeki64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Move o ponteiro de arquivo em um local especificado.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
 `offset`  
 Número de bytes de `origin`.  
  
 `origin`  
 Posição inicial.  
  
## Valor de retorno  
 Se tiver êxito, `fseek` e retorna 0 de `_fseeki64` .  Caso contrário, retornará um valor diferente de zero.  Dispositivos pôde buscar, o valor de retorno será indefinido.  Se `stream` for um ponteiro nulo, ou se `origin` não for um dos valores permitidos descritos abaixo, `fseek` e `_fseeki64` invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão \-1.  
  
## Comentários  
 `fseek` e `_fseeki64` funcionam move o ponteiro de arquivo \(se houver\) associado a `stream` para um novo local que esteja bytes de `offset` de `origin`*.* A próxima operação no fluxo ocorre no novo local.  Em um fluxo aberto para a atualização, a próxima operação pode ser uma leitura ou uma gravação.  A origem do argumento deve ser uma das seguintes constantes, definido em STDIO.H:  
  
 `SEEK_CUR`  
 A posição atual do ponteiro de arquivo.  
  
 `SEEK_END`  
 Fim de arquivo.  
  
 `SEEK_SET`  
 Início do arquivo.  
  
 Você pode usar `fseek` e reposicionar `_fseeki64` para o ponteiro em qualquer lugar em um arquivo.  O ponteiro também pode ser posicionado antes do final do arquivo.  `fseek` e `_fseeki64`desmarque o indicador de participante de Arquivo e negações o efeito de todas as chamadas anteriores de `ungetc` em `stream`.  
  
 Quando um arquivo é aberto com dados, a posição atual do arquivo é determinada pela última operação de E\/S, não por onde a gravação seguinte ocorrerá.  Se nenhuma operação de E\/S ocorreu ainda em um arquivo aberto, anexando a posição do arquivo é o início do arquivo.  
  
 Para os fluxos abertos no modo de texto, `fseek` e `_fseeki64`têm uso limitado, porque as traduções de retorno\- avanço de linha de carro podem causar `fseek` e `_fseeki64`a resultados inesperados.  As únicas `fseek` e operaçõesde `_fseeki64`garantia do para trabalhar em fluxos abertos no modo de texto são:  
  
-   Buscar com um deslocamento de 0 em relação a qualquer um dos valores de origem.  
  
-   Buscar desde o início do arquivo com um valor de deslocamento retornado de uma chamada a `ftell` ao usar `fseek`ou `_ftelli64`ao usar`_fseeki64`.  
  
 Também no modo de texto, CTRL\+Z é interpretado como um caractere de participante de Arquivo na entrada.  Em arquivos abertos leitura\/gravação, `fopen` e qualquer verificação de rotinas relacionada para um CTRL\+Z no final do arquivo e solte\-o se possível.  Isso é feito como usar a combinação de `fseek` e `ftell`ou`_fseeki64` e `_ftelli64`, para se mover dentro de um arquivo que termina com um CTRL\+Z pode fazer com que `fseek` ou `_fseeki64` se comportem de forma incorreta próximo do fim do arquivo.  
  
 Quando o CRT abre um arquivo que começa com uma marca de ordem de byte \(BOM\), o ponteiro de arquivo é posicionado após a BOM \(isto é, no início do conteúdo real do arquivo\).  Se você tiver que `fseek` ao início do arquivo, use `ftell` ele obter a posição inicial e `fseek` em vez de para posicionar 0.  
  
 Essa função bloqueia out outros threads durante a execução e em virtude disso é seguro para threads.  Para uma versão sem bloqueio, consulte [\_fseek\_nolock, \_fseeki64\_nolock](../../c-runtime-library/reference/fseek-nolock-fseeki64-nolock.md).  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fseek`|\<stdio.h\>|  
|`_fseeki64`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
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
  
  **O ponteiro de Arquivo é definido na metade da primeira linha.**  
**Este é o arquivo “fseek.out”.**   
## Equivalência do .NET Framework  
  
-   [System::IO::FileStream::Position](https://msdn.microsoft.com/en-us/library/system.io.filestream.position.aspx)  
  
-   [System::IO::FileStream::Seek](https://msdn.microsoft.com/en-us/library/system.io.filestream.seek.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [ftell, \_ftelli64](../../c-runtime-library/reference/ftell-ftelli64.md)   
 [\_lseek, \_lseeki64](../../c-runtime-library/reference/lseek-lseeki64.md)   
 [rewind](../../c-runtime-library/reference/rewind.md)