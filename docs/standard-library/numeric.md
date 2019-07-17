---
title: '&lt;numeric&gt;'
ms.date: 11/04/2016
f1_keywords:
- <numeric>
helpviewer_keywords:
- <numeric> header
ms.assetid: 6d6ccb94-48cc-479b-b4a9-bd9c78d4896a
ms.openlocfilehash: ce195742605c3dd2e127c84ac2f4e1e696c75bd0
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68246692"
---
# <a name="ltnumericgt"></a>&lt;numeric&gt;

Define as funções de modelo de contêiner que executam algoritmos para processamento numérico.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<numérico >

**Namespace:** std

## <a name="remarks"></a>Comentários

Os algoritmos numéricos parecem com os algoritmos da biblioteca padrão C++ em [\<algorithm>](algorithm.md) e podem operar em uma variedade de estruturas de dados. Isso inclui classes de contêiner da biblioteca padrão, por exemplo, [vector](../standard-library/vector-class.md) e [list](../standard-library/list-class.md), além de estruturas de dados definidas pelo programa e matrizes de elementos que atendem aos requisitos de um determinado algoritmo. Os algoritmos atingem esse nível de generalidade acessando e percorrendo os elementos de um contêiner indiretamente pelos iteradores. Os algoritmos processam intervalos de iteradores que geralmente são especificados pelas respectivas posições de início ou fim. Os intervalos referenciados devem ser válidos no sentido de que todos os ponteiros nos intervalos devem ser desreferenciáveis e dentro das sequências de cada intervalo, e a última posição deve ser acessível desde a primeira por meio de incrementação.

Os algoritmos estendem as ações que têm suporte pelas funções membro e operações de cada um dos contêineres da biblioteca padrão C++ e permitem a interação com diferentes tipos de objeto de contêiner ao mesmo tempo.

## <a name="members"></a>Membros

### <a name="functions"></a>Funções

|||
|-|-|
|[accumulate](../standard-library/numeric-functions.md#accumulate)|Calcula a soma de todos os elementos em um intervalo especificado, incluindo qualquer valor inicial, calculando somas parciais sucessivas ou calcula o resultado de resultados parciais sucessivos que são obtidos usando uma operação binária especificada no lugar da operação de soma.|
|[adjacent_difference](../standard-library/numeric-functions.md#adjacent_difference)|Calcula as diferenças sucessivas entre cada elemento e seu predecessor em um intervalo de entrada e gera os resultados em um intervalo de destino ou calcula o resultado de um procedimento generalizado, em que a operação de diferença é substituída por outra operação binária especificada.|
|[exclusive_scan](../standard-library/numeric-functions.md#exclusive_scan)||
|[GCD](../standard-library/numeric-functions.md#gcd)||
|[inclusive_scan](../standard-library/numeric-functions.md#inclusive_scan)||
|[inner_product](../standard-library/numeric-functions.md#inner_product)|Calcula a soma do produto em relação ao elemento de dois intervalos e a adiciona a um valor inicial especificado ou calcula o resultado de um procedimento generalizado, em que as operações de produto e a soma são substituídas por outras operações binárias especificadas.|
|[iota](../standard-library/numeric-functions.md#iota)|Armazena um valor inicial, começando com o primeiro elemento e preenchendo com incrementos sucessivos do valor (`value++`) em cada um dos elementos no intervalo `[first, last)`.|
|[LCM](../standard-library/numeric-functions.md#lcm)||
|[partial_sum](../standard-library/numeric-functions.md#partial_sum)|Calcula uma série de somas em um intervalo de entrada, do primeiro ao *i*-ésimo elemento e armazena o resultado de cada soma no *i*-ésimo elemento de um intervalo de destino ou calcula o resultado de um procedimento generalizado, em que a operação de soma é substituída por outra operação binária especificada.|
|[reduzir](../standard-library/numeric-functions.md#reduce)||
|[transform_exclusive_scan](../standard-library/numeric-functions.md#transform_exclusive_scan)||
|[transform_inclusive_scan](../standard-library/numeric-functions.md#transform_inclusive_scan)||
|[transform_reduce](../standard-library/numeric-functions.md#transform_reduce)||

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
