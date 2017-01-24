---
title: "_aligned_offset_malloc | Microsoft Docs"
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
  - "_aligned_offset_malloc"
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
  - "api-ms-win-crt-heap-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_aligned_offset_malloc"
  - "aligned_offset_malloc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _aligned_offset_malloc"
  - "Função aligned_offset_malloc"
ms.assetid: 447681a3-7c95-4655-86ba-fa3a4ca4c521
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_offset_malloc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Aloca memória em um limite de alinhamento especificado.  
  
## Sintaxe  
  
```  
void * _aligned_offset_malloc(  
   size_t size,   
   size_t alignment,   
   size_t offset  
);  
```  
  
#### Parâmetros  
 \[entrada\] `size`  
 O tamanho da alocação de memória solicitada.  
  
 \[entrada\] `alignment`  
 O valor de alinhamento, que deve ser uma potência de inteiro de 2.  
  
 \[entrada\] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## Valor de retorno  
 Um ponteiro para o bloco de memória que foi atribuído a `NULL` ou se houve falha na operação.  
  
## Comentários  
 `_aligned_offset_malloc` é útil em situações em que o alinhamento será necessário em um elemento aninhado; por exemplo, se o alinhamento foi necessário em uma classe aninhada.  
  
 `_aligned_offset_malloc` é baseado em `malloc`; para obter mais informações, consulte [malloc](../../c-runtime-library/reference/malloc.md).  
  
 `_aligned_offset_malloc` é `__declspec(noalias)` marcado e `__declspec(restrict)`, o que significa que a função é garantia de não altere variáveis globais e que o ponteiro retornado não possui alias.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrinja](../../cpp/restrict.md).  
  
 Esta função define `errno` a `ENOMEM` se a alocação de memória falhou ou se o tamanho solicitado for maior que `_HEAP_MAXREQ`.  Para obter mais informações sobre `errno`, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  Além disso, `_aligned_offset_malloc` valida seus parâmetros.  Se `alignment` não é uma potência de 2 ou se `offset` é maior ou igual a `size` e diferente de zero, essa função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_offset_malloc`|\<malloc.h\>|  
  
## Exemplo  
 Para obter mais informações, consulte [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md).  
  
## Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)