---
title: "_tempnam_dbg, _wtempnam_dbg | Microsoft Docs"
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
  - "_wtempnam_dbg"
  - "_tempnam_dbg"
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
  - "wtempnam_dbg"
  - "tempnam_dbg"
  - "_tempnam_dbg"
  - "_wtempnam_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tempnam_dbg"
  - "Função _wtempnam_dbg"
  - "nomes de arquivos [C++], criando temporário"
  - "nomes de arquivos [C++], temporário"
  - "Função tempnam_dbg"
  - "arquivos temporários, criando"
  - "Função wtempnam_dbg"
ms.assetid: e3760bb4-bb01-4808-b689-2c45af56a170
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _tempnam_dbg, _wtempnam_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Versões da função do [\_tempnam, \_wtempnam, tmpnam, \_wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md) que usam a versão de depuração do `malloc, _malloc_dbg`.  
  
## Sintaxe  
  
```  
char *_tempnam_dbg(    const char *dir,    const char *prefix,    int blockType,    const char *filename,    int linenumber  ); wchar_t *_wtempnam_dbg(    const wchar_t *dir,    const wchar_t *prefix,    int blockType,    const char *filename,    int linenumber  );  
```  
  
#### Parâmetros  
 `dir`  
 O caminho usado no nome de arquivo, se não houver variável de ambiente TMP ou se TMP não for um diretório válido.  
  
 `prefix`  
 A cadeia de caracteres que será pré\-anexada a nomes retornados pelo `_tempnam`.  
  
 `blockType`  
 Tipo solicitado de bloco de memória: `_CLIENT_BLOCK`ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Nome do ponteiro do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
## Valor de retorno  
 Cada função retorna um ponteiro para o nome gerado ou `NULL`, caso tenha ocorrido uma falha.  Pode ocorrer uma falha se houver um nome de diretório inválido especificado na variável de ambiente TMP e no parâmetro `dir`.  
  
> [!NOTE]
>  `free` \(ou `free_dbg`\) não precisa ser chamado para ponteiros alocados por `_tempnam_dbg` e `_wtempnam_dbg`.  
  
## Comentários  
 As funções `_tempnam_dbg`e `_wtempnam_dbg`são idênticas a `_tempnam`e `_wtempnam`exceto que, quando `_DEBUG`é definido, essas funções usam a versão de depuração de `malloc` e `_malloc_dbg` para alocar memória se `NULL` for enviado como primeiro parâmetro.  Para obter mais informações, consulte [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md).  
  
 Na maioria dos casos, não é necessário chamar essas funções explicitamente.  Em vez disso, defina o sinalizador `_CRTDBG_MAP_ALLOC`.  Quando `_CRTDBG_MAP_ALLOC` estiver definido, as chamadas para `_tempnam` e `_wtempnam` são remapeadas para  `_tempnam_dbg` e `_wtempnam_dbg`, respectivamente, com `blockType` definido para `_NORMAL_BLOCK`.  Assim, não é necessário chamar essas funções explicitamente, a menos que você queira marcar os blocos de heap como `_CLIENT_BLOCK`.  Para obter mais informações, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_ttempnam_dbg`|`_tempnam_dbg`|`_tempnam_dbg`|`_wtempnam_dbg`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_tempnam_dbg`, `_wtempnam_dbg`|\<crtdbg.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [\_tempnam, \_wtempnam, tmpnam, \_wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)   
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md)