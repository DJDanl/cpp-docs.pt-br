---
title: _lsearch_s
ms.date: 4/2/2020
api_name:
- _lsearch_s
- _o__lsearch_s
api_location:
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _lsearch_s
- lsearch_s
helpviewer_keywords:
- linear searching
- values, searching for
- keys, finding in arrays
- arrays [CRT], searching
- searching, linear
- _lsearch_s function
- lsearch_s function
ms.assetid: d2db0635-be7a-4799-8660-255f14450882
ms.openlocfilehash: d8c421eb3c7a6a617ce073cbf5f36416294c1874
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82920453"
---
# <a name="_lsearch_s"></a>_lsearch_s

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

*chave*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base da matriz a ser pesquisada.

*number*<br/>
Número de elementos.

*size*<br/>
Tamanho de cada elemento da matriz em bytes.

*comparar*<br/>
Ponteiro para a rotina de comparação. O segundo parâmetro é um ponteiro para a chave de pesquisa. O terceiro parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.

*contexto*<br/>
Um ponteiro para um objeto que pode ser acessado na função de comparação.

## <a name="return-value"></a>Valor retornado

Se a *chave* for encontrada, **_lsearch_s** retornará um ponteiro para o elemento da matriz na *base* que corresponde à *chave*. Se a *chave* não for encontrada, **_lsearch_s** retornará um ponteiro para o item recém-adicionado no final da matriz.

Se parâmetros inválidos forem passados para a função, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **errno** será definido como **EINVAL** e a função retornará **NULL**. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de erro

|*chave*|*base*|*comparar*|*number*|*size*|**errno**|
|-----------|------------|---------------|-----------|------------|-------------|
|**NULO**|any|any|any|any|**EINVAL**|
|any|**NULO**|any|!= 0|any|**EINVAL**|
|any|any|any|any|zero|**EINVAL**|
|any|any|**NULO**|an|any|**EINVAL**|

## <a name="remarks"></a>Comentários

A função **_lsearch_s** executa uma pesquisa linear para a *chave* de valor em uma matriz de elementos *Number* , cada um dos bytes de *largura* . Ao contrário de **bsearch_s**, **_lsearch_s** não exige que a matriz seja classificada. Se a *chave* não for encontrada, **_lsearch_s** a adicionar ao final da matriz e incrementar o *número*.

A função *Compare* é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de matriz e retorna um valor especificando sua relação. A função *Compare* também leva o ponteiro para o contexto como o primeiro argumento. **_lsearch_s** chamadas *comparam* uma ou mais vezes durante a pesquisa, passando ponteiros para dois elementos de matriz em cada chamada. *Compare* deve comparar os elementos e retornar zero (ou seja, os elementos são diferentes) ou 0 (o que significa que os elementos são idênticos).

O ponteiro de *contexto* poderá ser útil se a estrutura de dados pesquisada fizer parte de um objeto e a função *Compare* precisar acessar os membros do objeto. Por exemplo, o código na função *Compare* pode converter o ponteiro void no tipo de objeto apropriado e acessar os membros desse objeto. A adição do ponteiro de *contexto* torna o **_lsearch_s** mais seguro, pois o contexto adicional pode ser usado para evitar bugs de reentrância associados ao uso de variáveis estáticas para disponibilizar os dados para a função de *comparação* .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

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
