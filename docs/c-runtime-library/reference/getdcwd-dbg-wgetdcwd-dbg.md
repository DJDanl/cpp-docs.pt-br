---
title: "_getdcwd_dbg, _wgetdcwd_dbg | Microsoft Docs"
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
  - "_getdcwd_dbg"
  - "_wgetdcwd_dbg"
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
  - "_getdcwd_dbg"
  - "getdcwd_dbg"
  - "_wgetdcwd_dbg"
  - "wgetdcwd_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _getdcwd_dbg"
  - "Função _wgetdcwd_dbg"
  - "diretório de trabalho atual"
  - "diretórios [C++], trabalho atual"
  - "Função getdcwd_dbg"
  - "Função wgetdcwd_dbg"
  - "diretório de trabalho"
ms.assetid: 266bf6f0-0417-497f-963d-2e0f306d9385
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _getdcwd_dbg, _wgetdcwd_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Versões de depuração das funções [\_getdcwd, \_wgetdcwd](../../c-runtime-library/reference/getdcwd-wgetdcwd.md) \(disponíveis somente durante a depuração\).  
  
## Sintaxe  
  
```  
char *_getdcwd_dbg(    int drive,    char *buffer,    int maxlen,    int blockType,    const char *filename,    int linenumber  ); wchar_t *_wgetdcwd_dbg(    int drive,    wchar_t *buffer,    int maxlen,    int blockType,    const char *filename,    int linenumber  );  
```  
  
#### Parâmetros  
 `drive`  
 Nome da unidade de disco.  
  
 `buffer`  
 Local de armazenamento para o caminho.  
  
 `maxlen`  
 Comprimento máximo do caminho em caracteres:  `char`para `_getdcwd_dbg`e `wchar_t`para `_wgetdcwd_dbg`.  
  
 `blockType`  
 Tipo solicitado do bloco de memória:  `_CLIENT_BLOCK`ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
## Valor de retorno  
 Retorna um ponteiro para `buffer`.  Um valor retornado `NULL` indica que houve um erro e `errno` é definido como `ENOMEM`, indicando que a memória não é suficiente para alocar os bytes de `maxlen` \(quando um argumento `NULL` é informado como `buffer`\), ou como `ERANGE`, indicando que o caminho tem mais caracteres que o definido pelo parâmetro `maxlen`.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 As funções `_getdcwd_dbg` e `_wgetdcwd_dbg` são idênticas a `_getdcwd` e `_wgetdcwd`, exceto pelo fato de que, quando `_DEBUG` é definido, essas funções usam a versão de depuração de `malloc` e `_malloc_dbg` para alocar memória se `NULL` for apresentado como parâmetro `buffer`.  Para obter mais informações, consulte [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md).  
  
 Na maioria dos casos, não é necessário chamar essas funções explicitamente.  Em vez disso, você pode definir o sinalizador `_CRTDBG_MAP_ALLOC`.  Quando `_CRTDBG_MAP_ALLOC` é definido, as chamadas a `_getdcwd` e `_wgetdcwd` são remapeadas para `_getdcwd_dbg` e `_wgetdcwd_dbg`, respectivamente, com o `blockType` definido como `_NORMAL_BLOCK`.  Assim, não é necessário chamar essas funções explicitamente, a menos que você queira marcar os blocos de heap como `_CLIENT_BLOCK`.  Para obter mais informações, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tgetdcwd_dbg`|`_getdcwd_dbg`|`_getdcwd_dbg`|`_wgetdcwd_dbg`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_getdcwd_dbg`|\<crtdbg.h\>|  
|`_wgetdcwd_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 <xref:System.Environment.CurrentDirectory%2A?displayProperty=fullName>  
  
## Consulte também  
 [\_getdcwd, \_wgetdcwd](../../c-runtime-library/reference/getdcwd-wgetdcwd.md)   
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md)