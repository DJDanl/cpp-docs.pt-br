---
title: "_chsize_s | Microsoft Docs"
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
  - "_chsize_s"
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
  - "chsize_s"
  - "_chsize_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _chsize_s"
  - "Função chsize_s"
  - "Arquivos  [C++], alterando tamanho"
ms.assetid: d88d2e94-6e3b-42a5-8631-16ac4d82fa38
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _chsize_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tamanho de um arquivo.  Essa é uma versão de [\_chsize](../../c-runtime-library/reference/chsize.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _chsize_s(   
   int fd,  
   __int64 size   
);  
```  
  
#### Parâmetros  
 `fd`  
 O descritor de Arquivo que faz referência a um arquivo aberto.  
  
 `size`  
 Novo comprimento do arquivo em bytes.  
  
## Valor de retorno  
 `_chsize_s` retorna o valor 0 se o tamanho do arquivo é modificado com êxito.  Um valor de retorno diferente de zero indica um erro: o valor de retorno é `EACCES` se o arquivo especificado está bloqueado de acesso, `EBADF` se o arquivo especificado é somente leitura ou o descritor for inválido, `ENOSPC` se nenhum espaço é deixado no dispositivo, ou `EINVAL` se o tamanho é menor que zero.  `errno` é definido com o mesmo valor.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `_chsize_s` estende ou trunca o arquivo associado com `fd` ao comprimento especificado por `size`.  O arquivo deve estar aberto em um modo que permite gravar.  Os caracteres nulos \(\\ “0 "\) são acrescentados se o arquivo é estendido.  Se o arquivo é truncado, todos os dados do final do arquivo reduzido ao tamanho original do arquivo serão perdidos.  
  
 `_chsize_s` usa um inteiro de 64 bits do tamanho de arquivo e, consequentemente pode tratar tamanhos de arquivo maior que 4 GB.  `_chsize` é limitado aos tamanhos de arquivo de 32 bits.  
  
 Essa função valida seus parâmetros.  Se `fd` não é um descritor de arquivo válido ou o tamanho é menor que zero, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_chsize_s`|\<io.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
  
-   [System::IO::Stream::SetLength](https://msdn.microsoft.com/en-us/library/system.io.stream.setlength.aspx)  
  
-   [System::IO::FileStream::SetLength](https://msdn.microsoft.com/en-us/library/system.io.filestream.setlength.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_chsize](../../c-runtime-library/reference/chsize.md)   
 [\_close](../Topic/_close.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)