---
title: "_aligned_recalloc | Microsoft Docs"
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
  - "_aligned_recalloc"
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
  - "aligned_recalloc"
  - "_aligned_recalloc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função aligned_recalloc"
  - "Função _aligned_recalloc"
ms.assetid: d3da3dcc-79ef-4273-8af5-ac7469420142
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_recalloc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tamanho de um bloco de memória que é atribuído com [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0.  
  
## Sintaxe  
  
```  
void * _aligned_recalloc(  
   void *memblock,   
   size_t num,  
   size_t size,   
   size_t alignment  
);  
```  
  
#### Parâmetros  
 \[entrada\] `memblock`  
 O ponteiro atual do bloco de memória.  
  
 \[entrada\] `num`  
 O número de elementos.  
  
 \[entrada\] `size`  
 O tamanho em bytes de cada elemento.  
  
 \[entrada\] `alignment`  
 O valor de alinhamento, que deve ser uma potência de inteiro de 2.  
  
## Valor de retorno  
 `_aligned_recalloc` retorna um ponteiro nulo \(movido e possivelmente\) no bloco de memória realocado.  O valor de retorno é `NULL` se o tamanho for nulo e o argumento de buffer não é `NULL`, ou se não houver memória suficiente disponível para expandir o bloco ao tamanho especificado.  No primeiro caso, o bloco original é liberado.  No segundo caso, o bloco original permanece inalterado.  O valor de retorno para um espaço de armazenamento que é garantia de ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo diferente nulo, use uma conversão de tipos no valor de retorno.  
  
 É um erro para realocar a memória e alterar o alinhamento de um bloco.  
  
## Comentários  
 `_aligned_recalloc` é baseado em `malloc`.  Para obter mais informações sobre como usar `_aligned_offset_malloc`, consulte [malloc](../../c-runtime-library/reference/malloc.md).  
  
 Esta função define `errno` a `ENOMEM` se a alocação de memória falhou ou se o tamanho solicitado for maior que `_HEAP_MAXREQ`.  Para obter mais informações sobre `errno`, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  Além disso, `_aligned_recalloc` valida seus parâmetros.  Se `alignment` não é uma potência de 2, esta função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_recalloc`|\<malloc.h\>|  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)   
 [\_recalloc](../../c-runtime-library/reference/recalloc.md)   
 [\_aligned\_offset\_recalloc](../../c-runtime-library/reference/aligned-offset-recalloc.md)