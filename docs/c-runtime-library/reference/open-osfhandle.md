---
title: "_open_osfhandle | Microsoft Docs"
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
  - "_open_osfhandle"
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
  - "_open_osfhandle"
  - "open_osfhandle"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função open_osfhandle"
  - "associando os identificadores de arquivo [C++]"
  - "Função _open_osfhandle"
ms.assetid: 30d94df4-7868-4667-a401-9eb67ecb7855
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _open_osfhandle
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Associa o descritor de arquivo de tempo de execução c com um identificador de arquivo do sistema operacional existente.  
  
## Sintaxe  
  
```  
  
      int _open_osfhandle (  
   intptr_t osfhandle,  
   int flags   
);  
```  
  
#### Parâmetros  
 `osfhandle`  
 Identificador de arquivo do sistema operacional.  
  
 `flags`  
 Tipos de operações permitidos.  
  
## Valor de retorno  
 Se tiver êxito, `_open_osfhandle` retorna o descritor de arquivo de tempo de execução c.  Caso contrário, retornará – 1.  
  
## Comentários  
 A função de `_open_osfhandle` atribui o descritor de arquivo de tempo de execução c e associe\-o com o identificador de arquivo do sistema operacional especificado por `osfhandle`.  O argumento de `flags` é uma expressão de inteiro formada de uma ou mais das constantes manifestas definidas em Fcntl.h.  Quando duas ou mais manifestas constantes são usadas para formar o argumento de `flags` , as constantes são combinadas com AND bit a bit OR \(o operador  **&#124;** \).  
  
 Fcntl.h define as seguintes constantes manifestas.  
  
 **\_O\_APPEND**  
 Posiciona um ponteiro de arquivo ao final do arquivo antes de cada operação de gravação.  
  
 **\_O\_RDONLY**  
 Abre o arquivo para somente leitura.  
  
 **\_O\_TEXT**  
 Abre o arquivo no modo de texto traduzido \(\).  
  
 **\_O\_WTEXT**  
 Abre o arquivo no modo de Unicode \(UTF\-16 convertido\).  
  
 Para fechar um arquivo aberto com `_open_osfhandle`, chame `_close`.  O identificador subjacente também é fechada por uma chamada a `_close`portanto, não é necessário chamar a função `CloseHandle` do Win32 no identificador original.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_open_osfhandle`|\<io.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 [System::IO::FileStream::Handle](https://msdn.microsoft.com/en-us/library/system.io.filestream.handle.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)