---
title: _lsearch_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _lsearch_s
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
- _lsearch_s
- lsearch_s
dev_langs:
- C++
helpviewer_keywords:
- linear searching
- values, searching for
- keys, finding in arrays
- arrays [CRT], searching
- searching, linear
- _lsearch_s function
- lsearch_s function
ms.assetid: d2db0635-be7a-4799-8660-255f14450882
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 21d2aface59c4c2fd4247d299af26c63cdf46d45
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="lsearchs"></a>_lsearch_s

Executa uma pesquisa linear para um valor. Uma versão de [_lsearch](lsearch.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
void *_lsearch_s(
   const void *key,
   void *base,
   unsigned int *num,
   size_t size,
   int (__cdecl *compare)(void *, const void *, const void *),
   void * context
);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base da matriz a ser pesquisada.

*Número*<br/>
Número de elementos.

*size*<br/>
Tamanho de cada elemento da matriz em bytes.

*compare*<br/>
Ponteiro para a rotina de comparação. O segundo parâmetro é um ponteiro para a chave de pesquisa. O terceiro parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.

*context*<br/>
Um ponteiro para um objeto que pode ser acessado na função de comparação.

## <a name="return-value"></a>Valor de retorno

Se *chave* for encontrado, **lsearch_s** retorna um ponteiro para o elemento da matriz em *base* que corresponda *chave*. Se *chave* não for encontrado, **lsearch_s** retorna um ponteiro para o novo item no final da matriz.

Se parâmetros inválidos forem passados para a função, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, em seguida, **errno** é definido como **EINVAL** e a função retorna **nulo**. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de Erro

|*key*|*base*|*compare*|*Número*|*size*|**errno**|
|-----------|------------|---------------|-----------|------------|-------------|
|**NULL**|qualquer|qualquer|qualquer|qualquer|**EINVAL**|
|qualquer|**NULL**|qualquer|!= 0|qualquer|**EINVAL**|
|qualquer|qualquer|qualquer|qualquer|zero|**EINVAL**|
|qualquer|qualquer|**NULL**|an|qualquer|**EINVAL**|

## <a name="remarks"></a>Comentários

O **lsearch_s** função executa uma pesquisa linear para o valor *chave* em uma matriz de *número* elementos, cada um dos *largura* bytes. Ao contrário de **bsearch_s**, **lsearch_s** não exige que a matriz a ser classificada. Se *chave* não for encontrado, em seguida, **lsearch_s** adiciona ao final da matriz e incrementos *número*.

O *comparar* função é um ponteiro para uma rotina fornecido pelo usuário que compara dois elementos de matriz e retorna um valor que especifica sua relação. O *comparar* função também usa o ponteiro para o contexto como o primeiro argumento. **lsearch_s** chamadas *comparar* uma ou mais vezes durante a pesquisa, passando os ponteiros para os dois elementos de matriz em cada chamada. *Comparar* deve comparar os elementos e, em seguida, retornar zero (ou seja, os elementos são diferentes) ou 0 (ou seja, os elementos são idênticos).

O *contexto* ponteiro pode ser útil se a estrutura de dados pesquisada é parte de um objeto e o *comparar* função precisa acessar membros do objeto. Por exemplo, o código no *comparar* função pode converter o ponteiro nulo em membros de tipo e o acesso a objeto apropriado do objeto. A adição do *contexto* ponteiro torna **lsearch_s** mais segura porque o contexto adicional pode ser usado para evitar bugs reentrada associados ao uso de variáveis estáticas para tornar dados disponíveis para o *comparar* função.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lsearch_s**|\<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[bsearch_s](bsearch-s.md)<br/>
[_lfind_s](lfind-s.md)<br/>
[_lsearch](lsearch.md)<br/>
