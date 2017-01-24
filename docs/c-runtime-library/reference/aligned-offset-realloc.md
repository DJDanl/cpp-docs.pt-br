---
title: "_aligned_offset_realloc | Microsoft Docs"
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
  - "_aligned_offset_realloc"
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
  - "aligned_offset_realloc"
  - "_aligned_offset_realloc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função aligned_offset_realloc"
  - "Função _aligned_offset_realloc"
ms.assetid: e0263533-991e-41b0-acc9-1b8a51ab9ecd
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_offset_realloc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md).  
  
## Sintaxe  
  
```  
void * _aligned_offset_realloc(  
   void *memblock,   
   size_t size,   
   size_t alignment,  
   size_t offset  
);  
```  
  
#### Parâmetros  
 `memblock`  
 O ponteiro atual do bloco de memória.  
  
 `size`  
 O tamanho da alocação de memória.  
  
 `alignment`  
 O valor de alinhamento, que deve ser uma potência de inteiro de 2.  
  
 `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## Valor de retorno  
 `_aligned_offset_realloc` retorna um ponteiro nulo \(movido e possivelmente\) no bloco de memória realocado.  O valor de retorno é `NULL` se o tamanho for nulo e o argumento de buffer não é `NULL`, ou se não houver memória suficiente disponível para expandir o bloco ao tamanho especificado.  No primeiro caso, o bloco original é liberado.  No segundo caso, o bloco original permanece inalterado.  O valor de retorno para um espaço de armazenamento que é garantia de ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo diferente nulo, use uma conversão de tipos no valor de retorno.  
  
 `_aligned_offset_realloc` é `__declspec(noalias)` marcado e `__declspec(restrict)`, o que significa que a função é garantia de não altere variáveis globais e que o ponteiro retornado não possui alias.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrinja](../../cpp/restrict.md).  
  
## Comentários  
 Como [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md), `_aligned_offset_realloc` permite que uma estrutura é alinhado em um deslocamento na estrutura.  
  
 `_aligned_offset_realloc` é baseado em `malloc`.  Para obter mais informações sobre como usar `_aligned_offset_malloc`, consulte [malloc](../../c-runtime-library/reference/malloc.md).  Se `memblock` é `NULL`, as chamadas de função `_aligned_offset_malloc` internamente.  
  
 Esta função define `errno` a `ENOMEM` se a alocação de memória falhou ou se o tamanho solicitado for maior que `_HEAP_MAXREQ`.  Para obter mais informações sobre `errno`, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  Além disso, `_aligned_offset_realloc` valida seus parâmetros.  Se `alignment` não é uma potência de 2 ou se `offset` é maior ou igual a `size` e diferente de zero, essa função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_offset_realloc`|\<malloc.h\>|  
  
## Exemplo  
 Para obter mais informações, consulte [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md).  
  
## Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)