---
title: "_heapadd | Microsoft Docs"
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
  - "_heapadd"
apilocation: 
  - "msvcr100.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr80.dll"
  - "msvcrt.dll"
  - "msvcr110.dll"
  - "msvcr90.dll"
apitype: "DLLExport"
f1_keywords: 
  - "heapadd"
  - "_heapadd"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _heapadd"
  - "memória, adicionando a heaps"
  - "heaps, adicionando memória"
  - "Função heapadd"
ms.assetid: 4d691fe2-2763-49f4-afb1-62738b7cd3ff
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _heapadd
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona a memória no heap.  
  
> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ele não está disponível no CRT.  
  
## Sintaxe  
  
```  
int _heapadd(   
   void *memblock,  
   size_t size   
);  
```  
  
#### Parâmetros  
 `memblock`  
 Ponteiro para a memória de heap.  
  
 `size`  
 Tamanho da memória para adicionar, em bytes.  
  
## Valor de retorno  
 Se for bem\-sucedido, `_heapadd` retornará 0; caso contrário, a função retorna – 1 e define `errno` para `ENOSYS`.  
  
 Para obter mais informações sobre esse e outros códigos de retorno, consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Começando com o Visual C\+\+ versão 4.0, a estrutura subjacente do heap foi movida para as bibliotecas de tempo de execução C para dar suporte os novos recursos de depuração. Como resultado, `_heapadd` não é suportada em qualquer plataforma que se baseia na API do Win32.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_heapadd`|\< malloc \>|\< errno. h \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../c-runtime-library/compatibility.md) na introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../c-runtime-library/memory-allocation.md)   
 [free](../c-runtime-library/reference/free.md)   
 [\_heapchk](../c-runtime-library/reference/heapchk.md)   
 [\_heapmin](../c-runtime-library/reference/heapmin.md)   
 [\_heapset](../c-runtime-library/heapset.md)   
 [\_heapwalk](../Topic/_heapwalk.md)   
 [malloc](../c-runtime-library/reference/malloc.md)   
 [realloc](../c-runtime-library/reference/realloc.md)