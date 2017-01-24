---
title: "_lsearch_s | Microsoft Docs"
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
  - "_lsearch_s"
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
  - "api-ms-win-crt-utility-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_lsearch_s"
  - "lsearch_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _lsearch_s"
  - "matrizes [CRT], procurando"
  - "chaves, localizando em matrizes"
  - "pesquisa linear"
  - "Função lsearch_s"
  - "procurando, linear"
  - "Valores, procurando"
ms.assetid: d2db0635-be7a-4799-8660-255f14450882
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _lsearch_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa uma pesquisa linear para um valor.  Uma versão de [\_lsearch](../../c-runtime-library/reference/lsearch.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
void *_lsearch_s(  
   const void *key,  
   void *base,  
   unsigned int *num,  
   size_t size,  
   int (__cdecl *compare)(void *, const void *, const void *),  
   void * context  
);  
```  
  
#### Parâmetros  
 `key`  
 Objeto para pesquisar por.  
  
 `base`  
 Ponteiro para a base da matriz a ser pesquisada.  
  
 `num`  
 Número de elementos.  
  
 `size`  
 Tamanho de cada elemento da matriz em bytes.  
  
 `compare`  
 Ponteiro para a rotina de comparação.  O segundo parâmetro é um ponteiro para a chave da pesquisa.  O terceiro parâmetro é um ponteiro para um elemento da matriz a ser comparado com a chave.  
  
 `context`  
 Um ponteiro para um objeto que pode ser acessado na função de comparação.  
  
## Valor de retorno  
 Se `key` for encontrado, `_lsearch_s` retorna um ponteiro para o elemento da matriz em `base` que corresponde `key`.  Se `key` não for encontrado, `_lsearch_s` retorna um ponteiro para o item recém\-adicionada ao final da matriz.  
  
 Se os parâmetros inválidos são passados para a função, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, então `errno` está definido como `EINVAL` e a função retorna `NULL`.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
### Condições de erro  
  
|`key`|`base`|`compare`|`num`|`size`|`errno`|  
|-----------|------------|---------------|-----------|------------|-------------|  
|`NULL`|any|any|any|any|`EINVAL`|  
|any|`NULL`|any|\!\= 0|any|`EINVAL`|  
|any|any|any|any|zero|`EINVAL`|  
|any|any|`NULL`|an|any|`EINVAL`|  
  
## Comentários  
 A função de `_lsearch_s` executa uma pesquisa linear para o valor `key` em uma matriz de elementos de `num` , cada um de bytes de `width` .  Ao contrário de `bsearch_s`, `_lsearch_s` não requer a matriz ser classificada.  Se `key` não for encontrado, então `_lsearch_s` o adiciona ao final da matriz e incrementar\-lo `num`.  
  
 A função de `compare` é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos da matriz e retorna um valor que especifica a relação.  A função de `compare` também coloca o ponteiro para o contexto como o primeiro argumento.  `_lsearch_s` chama `compare` uma ou mais vezes durante a pesquisa, passando ponteiros a dois elementos da matriz em cada chamada.  `compare` deverá comparar os elementos e depois retornar diferente de zero \(o que significa que os elementos seja diferente\) ou 0 \(o que significa que os elementos são idênticos.\)  
  
 O ponteiro de `context` pode ser útil se a estrutura de dados pesquisada é parte de um objeto e a função de `compare` precisa acessar membros do objeto.  Por exemplo, o código da função de `compare` é possível converter o ponteiro nulo no tipo de objeto apropriado e acessar membros desse objeto.  A adição do ponteiro de `context` faz `_lsearch_s` mais segura porque o contexto adicional pode ser usado para evitar a bugs de reentrancy associados com o uso de variáveis estáticas para tornar os dados disponíveis à função de `compare` .  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_lsearch_s`|\<search.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [bsearch\_s](../../c-runtime-library/reference/bsearch-s.md)   
 [\_lfind\_s](../Topic/_lfind_s.md)   
 [\_lsearch](../../c-runtime-library/reference/lsearch.md)