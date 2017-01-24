---
title: "_CrtIsMemoryBlock | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_CrtIsMemoryBlock"
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
  - "CrtlsMemoryBlock"
  - "_CrtIsMemoryBlock"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _CrtIsMemoryBlock"
  - "Função CrtIsMemoryBlock"
ms.assetid: f7cbbc60-3690-4da0-a07b-68fd7f250273
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtIsMemoryBlock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verifica se um bloco de memória especificado está no heap e local que tem um identificador em blocos de heap válido de depuração \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
int _CrtIsMemoryBlock(   
   const void *userData,  
   unsigned int size,  
   long *requestNumber,  
   char **filename,  
   int *linenumber   
);  
```  
  
#### Parâmetros  
 \[entrada\] `userData`  
 Ponteiro para o início do bloco de memória a ser verificado.  
  
 \[entrada\] `size`  
 Tamanho do bloco especificado \(em bytes\).  
  
 \[saída\] `requestNumber`  
 Ponteiro para o número de alocação do bloco ou de `NULL`.  
  
 \[saída\] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou o bloco ou `NULL`.  
  
 \[saída\] `linenumber`  
 Ponteiro para a linha número no arquivo de origem ou em `NULL`.  
  
## Valor de retorno  
 `_CrtIsMemoryBlock` retorna `TRUE` se o bloco de memória especificado está localizado no heap local e tem um identificador em blocos de heap válido de depuração; caso contrário, a função retornará `FALSE`.  
  
## Comentários  
 A função de `_CrtIsMemoryBlock` verifica se um bloco de memória especificada está localizado no heap local do aplicativo e que tem um identificador válido em blocos.  Essa função pode ser usada também para obter o número da ordem de alocação do objeto e o nome do arquivo de origem\/número de linha na alocação do bloco de memória solicitada foi originalmente.  Passando valores não nulos para `requestNumber`, `filename`, ou faz com que `_CrtIsMemoryBlock` parâmetros de `linenumber` definir esses parâmetros para os valores no cabeçalho de depuração do bloco de memória, se encontrar o bloco no heap local.  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, as chamadas para `_CrtIsMemoryBlock` serão removidos durante pré\-processamento.  
  
 Se `_CrtIsMemoryBlock` falhar, retornará `FALSE` e parâmetros de saída são inicializados com os valores padrão: `requestNumber` e `lineNumber` são definidos como 0 e `filename` é definido como `NULL`.  
  
 Como essa função retorna `TRUE` ou `FALSE`, pode ser transmitido para um de macros de [\_ASSERT](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md) para criar um mecanismo simples de tratamento de erros de depuração.  O exemplo a seguir faz com que uma falha de asserção se o endereço especificado não está localizado no heap local:  
  
```  
_ASSERTE( _CrtIsMemoryBlock( userData, size, &requestNumber,   
&filename, &linenumber ) );  
```  
  
 Para obter mais informações sobre como `_CrtIsMemoryBlock` pode ser usado com outras funções e macros de depuração, consulte [Macros para relatórios](../Topic/Macros%20for%20Reporting.md).  Para obter informações sobre como os blocos de memória são atribuídos, inicializados, e gerenciados na versão de depuração da heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtIsMemoryBlock`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Exemplo  
 Consulte o exemplo do tópico de [\_CrtIsValidHeapPointer](../../c-runtime-library/reference/crtisvalidheappointer.md) .  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)