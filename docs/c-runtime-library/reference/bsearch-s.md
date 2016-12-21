---
title: "bsearch_s | Microsoft Docs"
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
  - "bsearch_s"
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
  - "bsearch_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "matrizes [CRT], pesquisa binária"
  - "Função bsearch_s"
ms.assetid: d5690d5e-6be3-4f1d-aa0b-5ca6dbded276
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# bsearch_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa uma pesquisa binária de uma matriz classificada. Esta é a versão de [bsearch](../../c-runtime-library/reference/bsearch.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
void *bsearch_s(   
   const void *key,  
   const void *base,  
   size_t num,  
   size_t width,  
   int ( __cdecl *compare ) ( void *, const void *key, const void *datum),  
   void * context  
);  
```  
  
#### Parâmetros  
 `key`  
 Objeto pesquisar.  
  
 `base`  
 Ponteiro para a base de dados de pesquisa.  
  
 `num`  
 Número de elementos.  
  
 `width`  
 Largura de elementos.  
  
 `compare`  
 Função de retorno de chamada que compara dois elementos. O primeiro argumento é o `context` ponteiro. O segundo argumento é um ponteiro para o `key` para a pesquisa. O terceiro argumento é um ponteiro para o elemento de matriz a ser comparada com `key`.  
  
 `context`  
 Um ponteiro para um objeto que pode ser acessado na função de comparação.  
  
## Valor de retorno  
 `bsearch_s` Retorna um ponteiro para uma ocorrência de`key` na matriz apontada por `base`. Se `key` não for encontrado, a função retornará `NULL`. Se a matriz não está em ordem de classificação crescente ou contém registros duplicados com chaves idênticas, o resultado é imprevisível.  
  
 Se parâmetros inválidos forem passados para a função, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `errno`é definido como `EINVAL` e a função retorna `NULL`. Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
### Condições de erro  
  
|||||||  
|-|-|-|-|-|-|  
|`key`|`base`|`compare`|`num`|`width`|`errno`|  
|`NULL`|qualquer|qualquer|qualquer|qualquer|`EINVAL`|  
|qualquer|`NULL`|qualquer|\!\= 0|qualquer|`EINVAL`|  
|qualquer|qualquer|qualquer|qualquer|\= 0|`EINVAL`|  
|qualquer|qualquer|`NULL`|um|qualquer|`EINVAL`|  
  
## Comentários  
 O `bsearch_s` função realiza uma pesquisa binária de uma matriz classificada de `num` elementos, cada um dos `width` bytes de tamanho. O `base` valor é um ponteiro para a base da matriz a ser pesquisada, e `key` é o valor que está sendo procurado. O `compare` parâmetro é um ponteiro para uma rotina fornecido pelo usuário que compara a chave solicitada para um elemento de matriz e retorna um dos valores a seguir, especificando sua relação:  
  
|Valor retornado por `compare` rotina|Descrição|  
|------------------------------------------|---------------|  
|\< 0|Chave é menor que o elemento da matriz.|  
|0|Chave é igual ao elemento de matriz.|  
|\> 0|Chave é maior que o elemento da matriz.|  
  
 O `context` ponteiro pode ser útil se a estrutura de dados pesquisada é parte de um objeto, e a função comparar precisa acessar membros do objeto. O `compare` função pode converter o ponteiro nulo em membros de tipo e acesso a objeto apropriado desse objeto. A adição do `context` parâmetro torna `bsearch_s` mais segura, pois o contexto adicional pode ser usado para evitar bugs de reentrância associadas ao uso de variáveis estáticas para tornar dados disponíveis para o `compare` função.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`bsearch_s`|\< stdlib. h \> e \< h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
 Este programa classifica uma matriz de cadeia de caracteres com [qsort\_s](../../c-runtime-library/reference/qsort-s.md), e, em seguida, usa bsearch\_s para localizar a palavra "gato".  
  
```  
// crt_bsearch_s.cpp  
// This program uses bsearch_s to search a string array,  
// passing a locale as the context.  
// compile with: /EHsc  
#include <stdlib.h>  
#include <stdio.h>  
#include <search.h>  
#include <process.h>  
#include <locale.h>  
#include <locale>  
#include <windows.h>  
using namespace std;  
  
// The sort order is dependent on the code page.  Use 'chcp' at the  
// command line to change the codepage.  When executing this application,  
// the command prompt codepage must match the codepage used here:  
  
#define CODEPAGE_850  
  
#ifdef CODEPAGE_850  
#define ENGLISH_LOCALE "English_US.850"  
#endif  
  
#ifdef CODEPAGE_1252  
#define ENGLISH_LOCALE "English_US.1252"  
#endif  
  
// The context parameter lets you create a more generic compare.  
// Without this parameter, you would have stored the locale in a  
// static variable, thus making it vulnerable to thread conflicts  
// (if this were a multithreaded program).  
  
int compare( void *pvlocale, char **str1, char **str2)  
{  
    char *s1 = *str1;  
    char *s2 = *str2;  
  
    locale& loc = *( reinterpret_cast< locale * > ( pvlocale));  
  
    return use_facet< collate<char> >(loc).compare(  
       s1, s1+strlen(s1),  
       s2, s2+strlen(s2) );  
}  
  
int main( void )  
{  
   char *arr[] = {"dog", "pig", "horse", "cat", "human", "rat", "cow", "goat"};  
  
   char *key = "cat";  
   char **result;  
   int i;  
  
   /* Sort using Quicksort algorithm: */  
   qsort_s( arr,  
            sizeof(arr)/sizeof(arr[0]),  
            sizeof( char * ),  
            (int (*)(void*, const void*, const void*))compare,  
            &locale(ENGLISH_LOCALE) );  
  
   for( i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i )    /* Output sorted list */  
      printf( "%s ", arr[i] );  
  
   /* Find the word "cat" using a binary search algorithm: */  
   result = (char **)bsearch_s( &key,  
                                arr,  
                                sizeof(arr)/sizeof(arr[0]),  
                                sizeof( char * ),  
                                (int (*)(void*, const void*, const void*))compare,  
                                &locale(ENGLISH_LOCALE) );  
   if( result )  
      printf( "\n%s found at %Fp\n", *result, result );  
   else  
      printf( "\nCat not found!\n" );  
}  
```  
  
```Output  
cat cow dog goat horse human pig rat cat found at 002F0F04  
```  
  
## Equivalência do .NET Framework  
 <xref:System.Collections.ArrayList.BinarySearch%2A>  
  
## Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [\_lfind](../../c-runtime-library/reference/lfind.md)   
 [\_lsearch](../../c-runtime-library/reference/lsearch.md)   
 [qsort](../../c-runtime-library/reference/qsort.md)