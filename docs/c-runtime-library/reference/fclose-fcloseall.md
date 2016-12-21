---
title: "fclose, _fcloseall | Microsoft Docs"
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
  - "fclose"
  - "_fcloseall"
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
  - "fclose"
  - "_fcloseall"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função fclose"
  - "fluxos de fechamento"
  - "Função _fcloseall"
ms.assetid: c3c6ea72-92c6-450a-a33e-3e568d2784a4
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fclose, _fcloseall
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fecha um fluxo \(ou fluxos\)`fclose`fecha todas abertos`_fcloseall`\(\).  
  
## Sintaxe  
  
```  
int fclose(   
   FILE *stream   
);  
int _fcloseall( void );  
```  
  
#### Parâmetros  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
## Valor de retorno  
 `fclose` retornará 0 se o fluxo é desligado com êxito.  `_fcloseall` retorna o número total de fluxos fechados.  Ambas as funções `EOF` de retorno para indicar um erro.  
  
## Comentários  
 A função de `fclose` fecha `stream`.  Se `stream` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, `fclose` define `errno` a `EINVAL` e retorna `EOF`.  É recomendado que o ponteiro de `stream` está sempre verificada antes de chamar essa função.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 A função de `_fcloseall` fluxos fecha todas abertos exceto `stdin`, `stdout`, `stderr` \(e, no MS\-DOS, em `_stdaux` e em `_stdprn`\).  Fecha e também exclui todos os arquivos temporários criados por `tmpfile`.  Em ambas as funções, todos armazena em buffer associado com o fluxo é liberado antes de fechar.  Os buffers alocados pelo sistema são liberados quando o fluxo é fechado.  Os buffers alocados pelo usuário com `setbuf` e `setvbuf` não são liberados automaticamente.  
  
 **Note:** quando essas funções são usadas para fechar um fluxo, o descritor de arquivo e o identificador de arquivo do sistema operacional \(ou o soquete subjacente\) são fechados, bem como o fluxo.  Assim, se o arquivo foi aberto como um descritor do identificador de arquivo ou de arquivo e é fechado originalmente com `fclose`, também não chame `_close` para fechar o descritor de arquivo; não chame a função `CloseHandle` do Win32 para fechar o identificador de arquivo.  
  
 `fclose` e `_fcloseall` incluem o código para proteger contra interferência de outros threads.  Para a versão sem\-bloqueio de `fclose`, consulte `_fclose_nolock`.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fclose`|\<stdio.h\>|  
|`_fcloseall`|\<stdio.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [fopen](../../c-runtime-library/reference/fopen-wfopen.md).  
  
## Equivalência do .NET Framework  
  
-   [System::IO::BinaryReader::Close](https://msdn.microsoft.com/en-us/library/system.io.binaryreader.close.aspx)  
  
-   [System::IO::BinaryWriter::Close](https://msdn.microsoft.com/en-us/library/system.io.binarywriter.close.aspx)  
  
-   [System::IO::StringReader::Close](https://msdn.microsoft.com/en-us/library/system.io.stringreader.close.aspx)  
  
-   [System::IO::StringWriter::Close](https://msdn.microsoft.com/en-us/library/system.io.stringwriter.close.aspx)  
  
-   [System::IO::Stream::Close](https://msdn.microsoft.com/en-us/library/system.io.stream.close.aspx)  
  
-   [System::IO::StreamReader::Close](https://msdn.microsoft.com/en-us/library/system.io.streamreader.close.aspx)  
  
-   [System::IO::StreamWriter::Close](https://msdn.microsoft.com/en-us/library/system.io.streamwriter.close.aspx)  
  
-   [System::IO::TextReader::Close](https://msdn.microsoft.com/en-us/library/system.io.textreader.close.aspx)  
  
-   [System::IO::TextWriter::Close](https://msdn.microsoft.com/en-us/library/system.io.textwriter.close.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [\_close](../Topic/_close.md)   
 [\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)   
 [fflush](../Topic/fflush.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, \_wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)