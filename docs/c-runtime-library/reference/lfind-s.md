---
title: _lfind_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _lfind_s
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-utility-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- lfind_s
- _lfind_s
dev_langs:
- C++
helpviewer_keywords:
- linear searching
- keys, finding in arrays
- lfind_s function
- arrays [CRT], searching
- searching, linear
- _lfind_s function
ms.assetid: f1d9581d-5c9d-4222-a31c-a6dfafefa40d
caps.latest.revision: 26
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: c50893f1dc73db9f928eaea346a381d1bd991d2f
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="lfinds"></a>_lfind_s
Executa uma pesquisa linear da chave especificada. Uma versão de [_lfind](../../c-runtime-library/reference/lfind.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_lfind_s(  
   const void *key,  
   const void *base,  
   unsigned int *num,  
   size_t size,  
   int (__cdecl *compare)(void *, const void *, const void *),  
   void * context  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `key`  
 O objeto a ser pesquisado.  
  
 `base`  
 Ponteiro para a base dos dados de pesquisa.  
  
 `num`  
 Número de elementos da matriz.  
  
 `size`  
 Tamanho dos elementos da matriz de bytes.  
  
 `compare`  
 Ponteiro para a rotina de comparação. O primeiro parâmetro é o ponteiro `context`. O segundo parâmetro é um ponteiro para a chave a ser pesquisada. O terceiro parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.  
  
 `context`  
 Um ponteiro para um objeto que pode ser acessado na função de comparação.  
  
## <a name="return-value"></a>Valor de retorno  
 Se a chave for encontrada, `_lfind_s` retornará um ponteiro para o elemento da matriz em `base` que corresponde a `key`. Se a chave não for encontrada, `_lfind_s` retornará `NULL`.  
  
 Se parâmetros inválidos forem passados para a função, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|key|base|compare|num|size|errno|  
|---------|----------|-------------|---------|----------|-----------|  
|`NULL`|qualquer|qualquer|qualquer|qualquer|`EINVAL`|  
|qualquer|`NULL`|qualquer|!= 0|qualquer|`EINVAL`|  
|qualquer|qualquer|qualquer|qualquer|zero|`EINVAL`|  
|qualquer|qualquer|`NULL`|an|qualquer|`EINVAL`|  
  
## <a name="remarks"></a>Comentários  
 A função `_lfind_s` executa uma pesquisa linear para o valor `key` em uma matriz de `num` elementos, cada uma de `width` bytes. Ao contrário de `bsearch_s`, `_lfind_s` não exige que a matriz seja classificada. O argumento `base` é um ponteiro para a base da matriz a ser pesquisada. O argumento `compare` é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos da matriz e retorna um valor que especifica seu relacionamento. `_lfind_s` chama a rotina `compare` uma ou mais vezes durante a pesquisa, passando o ponteiro `context` e ponteiros para dois elementos da matriz em cada chamada. A rotina `compare` deve comparar os elementos e retornar um valor diferente de zero (ou seja, os elementos são diferentes) ou 0 (ou seja, os elementos são idênticos).  
  
 `_lfind_s` é semelhante a `_lfind`, exceto pela adição dos ponteiros `context` aos argumentos da função de comparação e da lista de parâmetros da função. O ponteiro `context` poderá ser útil se a estrutura de dados pesquisada for parte de um objeto e a função `compare` precisar acessar membros do objeto. A função `compare` pode converter o ponteiro nulo no tipo de objeto apropriado e acessar membros desse objeto. A adição do parâmetro `context` torna `_lfind_s` mais seguro, pois o contexto adicional pode ser usado para evitar bugs de reentrância associados ao uso de variáveis estáticas para disponibilizar dados para a função `compare`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_lfind_s`|\<search.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_lfind_s.cpp  
// This program uses _lfind_s to search a string array,  
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
// Codepage 850 is the OEM codepage used by the command line,  
// so \x00e1 is the German Sharp S  
  
char *array1[] = { "wei\x00e1", "weis", "annehmen", "weizen", "Zeit",  
                   "weit" };  
  
#define GERMAN_LOCALE "German_Germany.850"  
  
#endif  
  
#ifdef CODEPAGE_1252  
   // If using codepage 1252 (ISO 8859-1, Latin-1), use \x00df  
   // for the German Sharp S  
char *array1[] = { "wei\x00df", "weis", "annehmen", "weizen", "Zeit",  
                   "weit" };  
  
#define GERMAN_LOCALE "German_Germany.1252"  
  
#endif  
  
// The context parameter lets you create a more generic compare.  
// Without this parameter, you would have stored the locale in a  
// static variable, thus making it vulnerable to thread conflicts  
// (if this were a multithreaded program).  
  
int compare( void *pvlocale, const void *str1, const void *str2)  
{  
    char *s1 = *(char**)str1;  
    char *s2 = *(char**)str2;  
  
    locale& loc = *( reinterpret_cast< locale * > ( pvlocale));  
  
    return use_facet< collate<char> >(loc).compare(  
       s1, s1+strlen(s1),  
       s2, s2+strlen(s2) );  
}  
  
void find_it( char *key, char *array[], unsigned int num, locale &loc )  
{  
   char **result = (char **)_lfind_s( &key, array,   
                      &num, sizeof(char *), compare, &loc );  
   if( result )  
      printf( "%s found\n", *result );  
   else  
      printf( "%s not found\n", key );  
}  
  
int main( )  
{  
   find_it( "weit", array1, sizeof(array1)/sizeof(char*), locale(GERMAN_LOCALE) );  
}  
```  
  
```Output  
weit found  
```  
  
## <a name="see-also"></a>Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [bsearch_s](../../c-runtime-library/reference/bsearch-s.md)   
 [_lsearch_s](../../c-runtime-library/reference/lsearch-s.md)   
 [qsort_s](../../c-runtime-library/reference/qsort-s.md)   
 [_lfind](../../c-runtime-library/reference/lfind.md)
