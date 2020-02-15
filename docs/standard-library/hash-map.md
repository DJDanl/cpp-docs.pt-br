---
title: '&lt;hash_map&gt;'
ms.date: 01/18/2018
f1_keywords:
- <hash_map>
- std::<hash_map>
helpviewer_keywords:
- hash_map header
ms.openlocfilehash: 6bb2ca0cc14bcc4a9b9df9877902de9181e0a768
ms.sourcegitcommit: 8414cd91297dea88c480e208c7b5301db9972f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2020
ms.locfileid: "77258140"
---
# <a name="lthash_mapgt"></a>&lt;hash_map&gt;

> [!NOTE]
> Este cabeçalho é obsoleto. A alternativa é [\<unordered_map >](unordered-map.md).

Define os modelos de classe de contêiner hash_map e hash_multimap e seus modelos de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <hash_map>
```

### <a name="operators"></a>Operadores

|Versão hash_map|Versão hash_multimap|DESCRIÇÃO|
|-----------------------|----------------------------|-----------------|
|[operator!= (hash_map)](hash-map-operators.md#op_neq)|[operador! = (hash_multimap)](hash-map-operators.md#op_neq_mm)|Testa se o objeto hash_map ou hash_multimap no lado esquerdo do operador não é igual ao objeto hash_map ou hash_multimap no lado direito.|
|[operator== (hash_map)](hash-map-operators.md#op_eq_eq)|[operator== (hash_multimap)](hash-map-operators.md#op_eq_eq_mm)|Testa se o objeto hash_map ou hash_multimap no lado esquerdo do operador é igual ao objeto hash_map ou hash_multimap no lado direito.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|Versão hash_map|Versão hash_multimap|DESCRIÇÃO|
|-----------------------|----------------------------|-----------------|
|[swap (hash_map)](hash-map-class.md#swap)|[swap (hash_multimap)](hash-multimap-class.md#swap)|Troca os elementos de dois hash_maps ou hash_multimaps.|

### <a name="classes"></a>Classes

|Classe|DESCRIÇÃO|
|-|-|
|[Classe hash_compare](hash-compare-class.md)|Descreve um objeto que pode ser usado por qualquer um dos contêineres associativos de hash – hash_map, hash_multimap, hash_set ou hash_multiset — como um objeto de parâmetro de `Traits` padrão para ordenar e aplicar hash aos elementos que eles contêm.|
|[Classe value_compare](value-compare-class.md)|Fornece um objeto de função que pode comparar os elementos de um hash_map comparando os valores de suas chaves para determinar sua ordem relativa no hash_map.|
|[Classe hash_map](hash-map-class.md)|Usado para o armazenamento e a recuperação rápida de dados de uma coleção em que cada elemento é um par que tem uma chave de classificação cujo valor é único, bem como um valor de dados associado.|
|[Classe hash_multimap](hash-multimap-class.md)|Usado para o armazenamento e a recuperação rápida de dados de uma coleção em que cada elemento é um par que tem uma chave de classificação cujo valor não precisa ser único e ser um valor de dados associado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<hash_map >

**Namespace:** stdext

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](cpp-standard-library-reference.md)
