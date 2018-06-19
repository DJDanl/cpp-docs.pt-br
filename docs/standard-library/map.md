---
title: '&lt;mapa&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <map>
dev_langs:
- C++
helpviewer_keywords:
- map header
ms.assetid: bbf76680-7362-456e-88fa-ecda93561b6a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ac523342cc175721b9c1ef33a3d8ac4cad83033b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33853359"
---
# <a name="ltmapgt"></a>&lt;map&gt;

Define o mapa e o multimapa das classes de modelo do contêiner e seus modelos de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <map>

```

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

|Classe|Descrição|
|-|-|
|[Classe value_compare](../standard-library/value-compare-class-map.md)|Fornece um objeto de função que pode comparar os elementos de um mapa ao comparar os valores de suas chaves para determinar sua ordem relativa no mapa.|
|[Classe map](../standard-library/map-class.md)|Usada para o armazenamento e recuperação de dados de uma coleção em que cada um dos elementos tem uma chave exclusiva, com a qual os dados são automaticamente ordenados.|
|[Classe multimap](../standard-library/multimap-class.md)|Usada para o armazenamento e recuperação de dados de uma coleção em que cada um dos elementos tem uma chave, com a qual os dados são automaticamente ordenados e as chaves não precisam ter valores exclusivos.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
