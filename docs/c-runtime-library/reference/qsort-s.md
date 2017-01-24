---
title: "qsort_s | Microsoft Docs"
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
  - "qsort_s"
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
  - "qsort_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "matrizes [C++], classificando"
  - "Função qsort_s"
  - "algoritmo de classificação rápida"
  - "classificando matrizes"
ms.assetid: 6ee817b0-4408-4355-a5d4-6605e419ab91
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# qsort_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa um tipo rápido.  Uma versão de [qsort](../../c-runtime-library/reference/qsort.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
void qsort_s(  
   void *base,  
   size_t num,  
   size_t width,  
   int (__cdecl *compare )(void *, const void *, const void *),  
   void * context  
);  
```  
  
#### Parâmetros  
 `base`  
 Início da matriz de destino.  
  
 `num`  
 Tamanho da matriz em elementos.  
  
 `width`  
 Tamanho do elemento em bytes.  
  
 `compare`  
 A função de comparação.  O primeiro argumento é o ponteiro de `context` .  O segundo argumento é um ponteiro para `key` da pesquisa.  O terceiro argumento é um ponteiro para o elemento da matriz a ser comparado com `key`.  
  
 `context`  
 Um ponteiro para um contexto, que pode ser qualquer objeto que a rotina de `compare` precisar acessar.  
  
## Comentários  
 A função de `qsort_s` implementa de um algoritmo de classificação para classificar uma matriz de elementos de `num` , cada um de bytes de `width` .  O argumento `base` é um ponteiro para a base da matriz a ser classificada.  substitui`qsort_s` esta matriz com os elementos classificados.  O argumento `compare` é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos da matriz e retorna um valor que especifica a relação.  `qsort_s` chama a rotina de `compare` uma ou mais vezes durante o tipo, passando ponteiros a dois elementos da matriz em cada chamada:  
  
```  
compare( context, (void *) & elem1, (void *) & elem2 );  
```  
  
 A rotina deverá comparar os elementos e depois retornar um dos seguintes valores:  
  
|Valor de retorno|Descrição|  
|----------------------|---------------|  
|\< 0|`elem1` menor que `elem2`|  
|0|equivalente a `elem2`de`elem1`|  
|\> 0|`elem1` maior que `elem2`|  
  
 A matriz é classificada em ordem crescente, como definido pela função de comparação.  Para classificar em ordem decrescente uma matriz, inverta sentido de “maior que” e “menor que” na função de comparação.  
  
 Se os parâmetros inválidos são passados para a função, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, a função retorna e `errno` é definido como `EINVAL`.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
### Condições de erro  
  
|key|base|comparar|numérico|width|errno|  
|---------|----------|--------------|--------------|-----------|-----------|  
|`NULL`|any|any|any|any|`EINVAL`|  
|any|`NULL`|any|\!\= 0|any|`EINVAL`|  
|any|any|any|any|\<\= 0|`EINVAL`|  
|any|any|`NULL`|any|any|`EINVAL`|  
  
 `qsort_s` tem o mesmo comportamento que `qsort` mas tem o parâmetro de `context` e define `errno`.  Transmitindo um parâmetro de `context` , as funções de comparação podem usar um ponteiro de objeto para a funcionalidade do objeto de acesso ou a outras informações não acessível através de um ponteiro de elemento.  A adição do parâmetro de `context` faz `qsort_s`mais segura porque `context` pode ser usado para evitar a bugs de reentrancy introduzidos usando variáveis estáticas para fazer as informações disponíveis compartilhada à função de `compare` .  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`qsort_s`|\<stdlib.h e\> search.h \<\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na apresentação.  
  
 **Bibliotecas:** Todas as versões das [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como usar o parâmetro de `context` na função de `qsort_s`.  O parâmetro de `context` facilita a execução tipos seguro para threads.  Em vez de usar variáveis estáticas devem ser sincronizadas para garantir a segurança de thread, passar um parâmetro diferente de `context` em cada tipo.  Neste exemplo, um objeto da localidade é usado como o parâmetro de `context` .  
  
```  
// crt_qsort_s.cpp  
// compile with: /EHsc /MT  
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
// Codepage 850 is the OEM codepage used by the command line,  
// so \x00e1 is the German Sharp S in that codepage and \x00a4  
// is the n tilde.  
  
char *array1[] = { "wei\x00e1", "weis", "annehmen", "weizen", "Zeit",  
                   "weit" };  
char *array2[] = { "Espa\x00a4ol", "Espa\x00a4" "a", "espantado" };  
char *array3[] = { "table", "tableux", "tablet" };  
  
#define GERMAN_LOCALE "German_Germany.850"  
#define SPANISH_LOCALE "Spanish_Spain.850"  
#define ENGLISH_LOCALE "English_US.850"  
  
#endif  
  
#ifdef CODEPAGE_1252  
   // If using codepage 1252 (ISO 8859-1, Latin-1), use \x00df  
   // for the German Sharp S and \x001f for the n tilde.  
char *array1[] = { "wei\x00df", "weis", "annehmen", "weizen", "Zeit",  
                   "weit" };  
char *array2[] = { "Espa\x00f1ol", "Espa\x00f1" "a", "espantado" };  
char *array3[] = { "table", "tableux", "tablet" };  
  
#define GERMAN_LOCALE "German_Germany.1252"  
#define SPANISH_LOCALE "Spanish_Spain.1252"  
#define ENGLISH_LOCALE "English_US.1252"  
  
#endif  
  
// The context parameter lets you create a more generic compare.  
// Without this parameter, you would have stored the locale in a  
// static variable, thus making sort_array vulnerable to thread  
// conflicts.  
  
int compare( void *pvlocale, const void *str1, const void *str2)  
{  
    char s1[256];  
    char s2[256];  
    strcpy_s(s1, 256, *(char**)str1);  
    strcpy_s(s2, 256, *(char**)str2);  
    _strlwr_s( s1, sizeof(s1) );  
    _strlwr_s( s2, sizeof(s2) );  
  
    locale& loc = *( reinterpret_cast< locale * > ( pvlocale));  
  
    return use_facet< collate<char> >(loc).compare(s1,   
       &s1[strlen(s1)], s2, &s2[strlen(s2)]);  
  
}  
  
void sort_array(char *array[], int num, locale &loc)  
{  
    qsort_s(array, num, sizeof(char*), compare, &loc);  
}  
  
void print_array(char *a[], int c)  
{  
   for (int i = 0; i < c; i++)  
     printf("%s ", a[i]);  
   printf("\n");  
  
}  
  
void sort_german(void * Dummy)  
{  
   sort_array(array1, 6, locale(GERMAN_LOCALE));  
}  
  
void sort_spanish(void * Dummy)  
{     
   sort_array(array2, 3, locale(SPANISH_LOCALE));       
}  
  
void sort_english(void * Dummy)  
{     
   sort_array(array3, 3, locale(ENGLISH_LOCALE));     
}  
  
int main( )  
{  
  
   int i;  
   HANDLE threads[3];  
  
   printf("Unsorted input:\n");  
   print_array(array1, 6);  
   print_array(array2, 3);  
   print_array(array3, 3);  
  
   // Create several threads that perform sorts in different  
   // languages at the same time.   
  
   threads[0] = reinterpret_cast<HANDLE>(  
                 _beginthread( sort_german , 0, NULL));  
   threads[1] = reinterpret_cast<HANDLE>(  
                 _beginthread( sort_spanish, 0, NULL));  
   threads[2] = reinterpret_cast<HANDLE>(  
                 _beginthread( sort_english, 0, NULL));  
  
   for (i = 0; i < 3; i++)  
   {  
      if (threads[i] == reinterpret_cast<HANDLE>(-1))  
      {  
         printf("Error creating threads.\n");  
         exit(1);  
      }  
   }  
  
   // Wait until all threads have terminated.  
   WaitForMultipleObjects(3, threads, true, INFINITE);  
  
   printf("Sorted output: \n");  
  
   print_array(array1, 6);  
   print_array(array2, 3);  
   print_array(array3, 3);  
  
}  
```  
  
## Saída de Exemplo  
  
```  
Unsorted input:  
weiß weis annehmen weizen Zeit weit   
Español España espantado   
table tableux tablet   
Sorted output:   
annehmen weiß weis weit weizen Zeit   
España Español espantado   
table tablet tableux  
```  
  
## Equivalência do .NET Framework  
 <xref:System.Collections.ArrayList.Sort%2A>  
  
## Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [bsearch\_s](../../c-runtime-library/reference/bsearch-s.md)   
 [\_lsearch\_s](../../c-runtime-library/reference/lsearch-s.md)   
 [qsort](../../c-runtime-library/reference/qsort.md)