---
title: _lfind | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _lfind
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
- lfind
- _lfind
dev_langs:
- C++
helpviewer_keywords:
- linear searching
- lfind function
- arrays [CRT], searching
- searching, linear
- finding keys in arrays
- _lfind function
ms.assetid: a40ece70-1674-4b75-94bd-9f57cfff18f2
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 488863a32319fac17f5d1c84f56edaeeb63ff0ce
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="lfind"></a>_lfind

Executa uma pesquisa linear da chave especificada. Uma versão mais segura dessa função está disponível, consulte [_lfind_s](lfind-s.md).

## <a name="syntax"></a>Sintaxe

```C
void *_lfind(
   const void *key,
   const void *base,
   unsigned int *num,
   unsigned int width,
   int (__cdecl *compare)(const void *, const void *)
);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base dos dados de pesquisa.

*Número*<br/>
Número de elementos da matriz.

*width*<br/>
Largura dos elementos da matriz.

*compare*<br/>
Ponteiro para a rotina de comparação. O primeiro parâmetro é um ponteiro para a chave a ser pesquisada. O segundo parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.

## <a name="return-value"></a>Valor de retorno

Se a chave for encontrada, **lfind** retorna um ponteiro para o elemento da matriz em *base* que corresponda *chave*. Se a chave não for encontrada, **lfind** retorna **nulo**.

## <a name="remarks"></a>Comentários

O **lfind** função executa uma pesquisa linear para o valor *chave* em uma matriz de *número* elementos, cada um dos *largura* bytes. Ao contrário de **bsearch**, **lfind** não exige que a matriz a ser classificada. O *base* argumento é um ponteiro para a base da matriz a ser pesquisada. O *comparar* argumento é um ponteiro para uma rotina fornecido pelo usuário que compara dois elementos de matriz e, em seguida, retorna um valor especificando suas relações. **lfind** chama o *comparar* rotina um ou mais vezes durante a pesquisa, passando os ponteiros para os dois elementos de matriz em cada chamada. O *comparar* rotina deve comparar os elementos e, em seguida, retornar diferente de zero (ou seja, os elementos são diferentes) ou 0 (ou seja, os elementos são idênticos).

Essa função valida seus parâmetros. Se *comparar*, *chave* ou *número* é **nulo**, ou se *base* é NULL e **número*  é diferente de zero, ou se *largura* é menor que zero, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **errno** é definido como **EINVAL** e a função retorna **nulo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lfind**|\<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_lfind.c
// This program uses _lfind to search a string array
// for an occurrence of "hello".

#include <search.h>
#include <string.h>
#include <stdio.h>

int compare(const void *arg1, const void *arg2 )
{
   return( _stricmp( * (char**)arg1, * (char**)arg2 ) );
}

int main( )
{
   char *arr[] = {"Hi", "Hello", "Bye"};
   int n = sizeof(arr) / sizeof(char*);
   char **result;
   char *key = "hello";

   result = (char **)_lfind( &key, arr,
                      &n, sizeof(char *), compare );

   if( result )
      printf( "%s found\n", *result );
   else
      printf( "hello not found!\n" );
}
```

```Output
Hello found
```

## <a name="see-also"></a>Consulte também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[_lfind_s](lfind-s.md)<br/>
[bsearch](bsearch.md)<br/>
[_lsearch](lsearch.md)<br/>
[qsort](qsort.md)<br/>
