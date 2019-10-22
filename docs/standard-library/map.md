---
title: '&lt;map&gt;'
ms.date: 11/04/2016
f1_keywords:
- <map>
helpviewer_keywords:
- map header
ms.assetid: bbf76680-7362-456e-88fa-ecda93561b6a
ms.openlocfilehash: 2e861d2250585fbcdf3e1ef63d92f18185fc7f1c
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687770"
---
# <a name="ltmapgt"></a>&lt;map&gt;

Define os modelos de classe de contêiner Map e Multimap e seus modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<map>

**Namespace:** std

> [!NOTE]
> A biblioteca \<map > também usa a instrução `#include <initializer_list>`.

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|Versão do mapa|Versão do multimapa|Descrição|
|-----------------|----------------------|-----------------|
|[operator!= (map)](../standard-library/map-operators.md#op_neq)|[operator!= (multimap)](../standard-library/map-operators.md#op_neq)|Testa se o objeto do mapa ou multimapa à esquerda do operador é diferente do objeto do mapa ou multimapa à direita.|
|[operator< (mapa)](../standard-library/map-operators.md#op_eq_eq)|[operator< (multimapa)](../standard-library/map-operators.md#op_eq_eq)|Testa se o objeto do mapa ou multimapa à esquerda do operador é menor que o objeto de mapa ou multimapa à direita.|
|[operator<= (mapa)](../standard-library/map-operators.md#op_lt)|[operator\<= (multimapa)](../standard-library/map-operators.md#op_lt)|Testa se o objeto do mapa ou multimapa à esquerda do operador é menor ou igual ao objeto do mapa ou multimapa à direita.|
|[operator== (mapa)](../standard-library/map-operators.md#op_eq_eq)|[operator== (multimapa)](../standard-library/map-operators.md#op_eq_eq_multimap)|Testa se o objeto do mapa ou multimapa à esquerda do operador é igual ao objeto do mapa ou multimapa à direita.|
|[operator> (mapa)](../standard-library/map-operators.md#op_gt)|[operator> (multimapa)](../standard-library/map-operators.md#op_gt_multimap)|Testa se o objeto do mapa ou multimapa à esquerda do operador é maior que o objeto do mapa ou multimapa à direita.|
|[operator>= (mapa)](../standard-library/map-operators.md#op_gt_eq)|[operator>= (multimapa)](../standard-library/map-operators.md#op_gt_eq_multimap)|Testa se o objeto do mapa ou multimapa à esquerda do operador é maior ou igual ao objeto do mapa ou multimapa à direita.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|Versão do mapa|Versão do multimapa|Descrição|
|-----------------|----------------------|-----------------|
|[swap (map)](../standard-library/map-functions.md#swap)|[swap (multimap)](../standard-library/map-functions.md#swap_multimap)|Troca os elementos de dois mapas ou multimapas.|

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe value_compare](../standard-library/value-compare-class-map.md)|Fornece um objeto de função que pode comparar os elementos de um mapa ao comparar os valores de suas chaves para determinar sua ordem relativa no mapa.|
|[Classe map](../standard-library/map-class.md)|Usada para o armazenamento e recuperação de dados de uma coleção em que cada um dos elementos tem uma chave exclusiva, com a qual os dados são automaticamente ordenados.|
|[Classe multimap](../standard-library/multimap-class.md)|Usada para o armazenamento e recuperação de dados de uma coleção em que cada um dos elementos tem uma chave, com a qual os dados são automaticamente ordenados e as chaves não precisam ter valores exclusivos.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
