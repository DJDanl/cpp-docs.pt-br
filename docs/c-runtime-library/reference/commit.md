---
title: "_commit | Microsoft Docs"
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
  - "_commit"
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
  - "_commit"
  - "commit"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _commit"
  - "Função commit"
  - "confirmando arquivos para o disco"
  - "Arquivos  [C++], liberando"
  - "liberando arquivos para o disco"
ms.assetid: d0c74d3a-4f2d-4fb0-b140-2d687db3d233
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _commit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Libera um arquivo diretamente no disco.  
  
## Sintaxe  
  
```  
int _commit(   
   int fd   
);  
```  
  
#### Parâmetros  
 `fd`  
 O descritor de Arquivo que faz referência ao arquivo aberto.  
  
## Valor de retorno  
 `_commit` retornará 0 se o arquivo foi liberado com êxito no disco.  Um valor de retorno – 1 indica um erro.  
  
## Comentários  
 A função de `_commit` força o sistema operacional para gravar o arquivo associado com `fd` no disco.  Essa chamada assegura que o arquivo especificado seja liberado imediatamente, não a discreção do sistema operacional.  
  
 Se `fd` é um descritor de arquivo inválido, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, a função retorna \-1 e `errno` é definido como `EBADF`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`_commit`|\<io.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Consulte também  
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_read](../Topic/_read.md)   
 [\_write](../../c-runtime-library/reference/write.md)