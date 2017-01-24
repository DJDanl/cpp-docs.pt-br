---
title: "_aligned_realloc | Microsoft Docs"
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
  - "_aligned_realloc"
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
  - "_aligned_realloc"
  - "aligned_realloc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função aligned_realloc"
  - "Função _aligned_realloc"
ms.assetid: 80ce96e8-6087-416f-88aa-4dbb8cb1d218
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_realloc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md).  
  
## Sintaxe  
  
```  
void * _aligned_realloc(  
   void *memblock,   
   size_t size,   
   size_t alignment  
);  
```  
  
#### Parâmetros  
 \[entrada\] `memblock`  
 O ponteiro atual do bloco de memória.  
  
 \[entrada\] `size`  
 O tamanho da alocação de memória solicitada.  
  
 \[entrada\] `alignment`  
 O valor de alinhamento, que deve ser uma potência de inteiro de 2.  
  
## Valor de retorno  
 `_aligned_realloc` retorna um ponteiro nulo \(movido e possivelmente\) no bloco de memória realocado.  O valor de retorno é `NULL` se o tamanho for nulo e o argumento de buffer não é `NULL`, ou se não houver memória suficiente disponível para expandir o bloco ao tamanho especificado.  No primeiro caso, o bloco original é liberado.  No segundo, o bloco original permanece inalterado.  O valor de retorno para um espaço de armazenamento que é garantia de ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo diferente nulo, use uma conversão de tipos no valor de retorno.  
  
 É um erro para realocar a memória e alterar o alinhamento de um bloco.  
  
## Comentários  
 `_aligned_realloc` é baseado em `malloc`.  Para obter mais informações sobre como usar `_aligned_offset_malloc`, consulte [malloc](../../c-runtime-library/reference/malloc.md).  
  
 Esta função define `errno` a `ENOMEM` se a alocação de memória falhou ou se o tamanho solicitado for maior que `_HEAP_MAXREQ`.  Para obter mais informações sobre `errno`, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  Além disso, `_aligned_realloc` valida seus parâmetros.  Se `alignment` não é uma potência de 2, esta função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_realloc`|\<malloc.h\>|  
  
## Exemplo  
 Para obter mais informações, consulte [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md).  
  
## Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)