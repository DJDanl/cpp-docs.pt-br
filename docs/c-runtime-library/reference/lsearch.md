---
title: "_lsearch | Microsoft Docs"
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
  - "_lsearch"
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
  - "_lsearch"
  - "lsearch"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _lsearch"
  - "matrizes [CRT], procurando"
  - "chaves, localizando em matrizes"
  - "pesquisas lineares"
  - "Função lsearch"
  - "procurando, linear"
  - "Valores, procurando"
ms.assetid: 8200f608-159a-46f0-923b-1a37ee1af7e0
caps.latest.revision: 19
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _lsearch
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa uma pesquisa linear para um valor; adiciona uma ao final da lista se não encontrada.  Uma versão mais segura dessa função está disponível; consulte [\_lsearch\_s](../../c-runtime-library/reference/lsearch-s.md).  
  
## Sintaxe  
  
```  
void *_lsearch(  
   const void *key,  
   void *base,  
   unsigned int *num,  
   unsigned int width,  
   int (__cdecl *compare)(const void *, const void *)   
);  
```  
  
#### Parâmetros  
 `key`  
 Objeto para pesquisar por.  
  
 `base`  
 Ponteiro para a base da matriz a ser pesquisada.  
  
 `num`  
 Número de elementos.  
  
 `width`  
 Largura de cada elemento da matriz.  
  
 `compare`  
 Ponteiro para a rotina de comparação.  O primeiro parâmetro é um ponteiro para a chave da pesquisa.  O segundo parâmetro é um ponteiro para um elemento da matriz a ser comparado com a chave.  
  
## Valor de retorno  
 Se a chave for localizada, `_lsearch` retorna um ponteiro para o elemento da matriz em `base` que corresponde `key`.  Se a chave não for localizada, `_lsearch` retorna um ponteiro para o item recém\-adicionada ao final da matriz.  
  
## Comentários  
 A função de `_lsearch` executa uma pesquisa linear para o valor `key` em uma matriz de elementos de `num` , cada um de bytes de `width` .  Ao contrário de `bsearch`, `_lsearch` não requer a matriz ser classificada.  Se `key` não for encontrado, `_lsearch` o adiciona ao final da matriz e incrementar\-lo `num`.  
  
 O argumento de `compare` é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos da matriz e retorna um valor que especifica a relação.  `_lsearch` chama a rotina de `compare` uma ou mais vezes durante a pesquisa, passando ponteiros a dois elementos da matriz em cada chamada.  `compare` deverá comparar os elementos e retornar diferente de zero \(o que significa que os elementos seja diferente\) ou 0 \(o que significa que os elementos são idênticos.\)  
  
 Essa função valida seus parâmetros.  Se `compare`, `key` ou `num` são `NULL`, ou se `base` for NULL e \*`num` for diferente de zero, ou se `width` é menor que zero, o manipulador inválido do parâmetro é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_lsearch`|\<search.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_lsearch.c  
#include <search.h>  
#include <string.h>  
#include <stdio.h>  
  
int compare( const void *arg1, const void *arg2 );  
  
int main(void)  
{  
   char * wordlist[4] = { "hello", "thanks", "bye" };  
                            // leave room to grow...  
   int n = 3;  
   char **result;  
   char *key = "extra";  
   int i;  
  
   printf( "wordlist before _lsearch:" );  
   for( i=0; i<n; ++i ) printf( " %s", wordlist[i] );  
   printf( "\n" );  
  
   result = (char **)_lsearch( &key, wordlist,   
                      &n, sizeof(char *), compare );  
  
   printf( "wordlist after _lsearch:" );  
   for( i=0; i<n; ++i ) printf( " %s", wordlist[i] );  
   printf( "\n" );  
}  
  
int compare(const void *arg1, const void *arg2 )  
{  
   return( _stricmp( * (char**)arg1, * (char**)arg2 ) );  
}  
```  
  
  **wordlist antes de \_lsearch: hello world adeus do graças**  
**wordlist depois do \_lsearch: hello world acréscimo de adeus do graças**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [bsearch](../../c-runtime-library/reference/bsearch.md)   
 [\_lfind](../../c-runtime-library/reference/lfind.md)   
 [\_lsearch\_s](../../c-runtime-library/reference/lsearch-s.md)