---
title: "_fullpath_dbg, _wfullpath_dbg | Microsoft Docs"
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
  - "_wfullpath_dbg"
  - "_fullpath_dbg"
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
  - "wfullpath_dbg"
  - "_wfullpath_dbg"
  - "_fullpath_dbg"
  - "fullpath_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fullpath_dbg"
  - "Função _wfullpath_dbg"
  - "caminhos absolutos"
  - "Função fullpath_dbg"
  - "caminhos de arquivo relativos"
  - "Função wfullpath_dbg"
ms.assetid: 81f72f85-07da-4f5c-866a-598e0fb03f6b
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fullpath_dbg, _wfullpath_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Versões do [\_fullpath, \_wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md) que usam a versão de depuração de `malloc` para alocar memória.  
  
## Sintaxe  
  
```  
char *_fullpath_dbg(     char *absPath,    const char *relPath,    size_t maxLength,    int blockType,    const char *filename,    int linenumber  ); wchar_t *_wfullpath_dbg(     wchar_t *absPath,    const wchar_t *relPath,    size_t maxLength,    int blockType,    const char *filename,    int linenumber  );  
```  
  
#### Parâmetros  
 `absPath`  
 Ponteiro para um buffer contendo o nome de caminho absoluto ou completo, ou `NULL`.  
  
 `relPath`  
 Nome de caminho relativo.  
  
 `maxLength`  
 Comprimento máximo do buffer do nome de caminho absoluto \(`absPath`\).  Esse comprimento é em bytes para `_fullpath` mas em caracteres largos \(`wchar_t`\) para `_wfullpath`.  
  
 `blockType`  
 Tipo de bloco de memória solicitado:  `_CLIENT_BLOCK`ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
## Valor de retorno  
 Cada função retorna um ponteiro para um buffer contendo o nome de caminho absoluto \(`absPath`\).  Se houver um erro \(por exemplo, se o valor transmitido em `relPath` incluir uma letra da unidade que não seja válida e não possa ser localizada, ou se o comprimento do nome de caminho absoluto criado \(`absPath`\) for maior que `maxLength`\), a função retornará `NULL`.  
  
## Comentários  
 As funções `_fullpath_dbg` e `_wfullpath_dbg` são idênticas a `_fullpath` e `_wfullpath`. A única diferença é que, quando **\_**`DEBUG`é definido, essas funções usam a versão de depuração de `malloc` e `_malloc_dbg` para alocar memória se NULL for apresentado como primeiro parâmetro.  Para obter informações sobre os recursos de depuração de `_malloc_dbg`, consulte [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md).  
  
 Na maioria dos casos, não é necessário chamar essas funções explicitamente.  Em vez disso, você pode definir o sinalizador `_CRTDBG_MAP_ALLOC`.  Quando `_CRTDBG_MAP_ALLOC` é definido, as chamadas a `_fullpath` e `_wfullpath` são remapeadas para `_fullpath_dbg` e `_wfullpath_dbg`, respectivamente, com o `blockType` definido como `_NORMAL_BLOCK`.  Assim, não é necessário chamar essas funções explicitamente, a menos que você queira marcar os blocos de heap como `_CLIENT_BLOCK`.  Para obter mais informações, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tfullpath_dbg`|`_fullpath_dbg`|`_fullpath_dbg`|`_wfullpath_dbg`|  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_fullpath_dbg`|\<crtdbg.h\>|  
|`_wfullpath_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 <xref:System.IO.File.Create%2A>  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_fullpath, \_wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md)