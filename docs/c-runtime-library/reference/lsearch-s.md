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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 720b83dd48b42d77f35bce12f16e8ac79eb3b4d3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341658"
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

*Chave*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base da matriz a ser pesquisada.

*number*<br/>
Número de elementos.

*Tamanho*<br/>
Tamanho de cada elemento da matriz em bytes.

*Comparar*<br/>
Ponteiro para a rotina de comparação. O segundo parâmetro é um ponteiro para a chave de pesquisa. O terceiro parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.

*contexto*<br/>
Um ponteiro para um objeto que pode ser acessado na função de comparação.

## <a name="return-value"></a>Valor retornado

Se *a tecla* for encontrada, **_lsearch_s** retorna um ponteiro para o elemento da matriz na *base* que corresponde à *tecla*. Se *a chave* não for encontrada, **_lsearch_s** retorna um ponteiro para o item recém-adicionado no final da matriz.

Se os parâmetros inválidos forem passados para a função, o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, **errno** será definido **como EINVAL** e a função retorna **NULL**. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de erro

|*Chave*|*base*|*Comparar*|*number*|*Tamanho*|**errno**|
|-----------|------------|---------------|-----------|------------|-------------|
|**NULO**|any|any|any|any|**Einval**|
|any|**NULO**|any|!= 0|any|**Einval**|
|any|any|any|any|zero|**Einval**|
|any|any|**NULO**|an|any|**Einval**|

## <a name="remarks"></a>Comentários

A função **_lsearch_s** realiza uma busca linear pela *chave* de valor em uma matriz de elementos *numéricos,* cada um dos bytes de *largura.* Ao contrário **bsearch_s,** **_lsearch_s** não exige que a matriz seja classificada. Se *a chave* não for encontrada, **_lsearch_s** a adiciona ao final da matriz e do *número*de incrementos .

A função *de comparação* é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de array e retorna um valor especificando seu relacionamento. A função *compare* também leva o ponteiro ao contexto como o primeiro argumento. **_lsearch_s** chamadas *comparam* uma ou mais vezes durante a pesquisa, passando ponteiros para dois elementos de matriz em cada chamada. *comparar* deve comparar os elementos e, em seguida, retornar não zero (o que significa que os elementos são diferentes) ou 0 (o que significa que os elementos são idênticos).

O ponteiro de *contexto* pode ser útil se a estrutura de dados pesquisada for parte de um objeto e a função *de comparação* precisar acessar os membros do objeto. Por exemplo, o código na função *compare* pode lançar o ponteiro vazio no tipo de objeto apropriado e acessar os membros desse objeto. A adição do ponteiro de *contexto* torna **_lsearch_s** mais seguras porque o contexto adicional pode ser usado para evitar bugs de reentrada associados ao uso de variáveis estáticas para disponibilizar dados à função *de comparação.*

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lsearch_s**|\<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[bsearch_s](bsearch-s.md)<br/>
[_lfind_s](lfind-s.md)<br/>
[_lsearch](lsearch.md)<br/>
