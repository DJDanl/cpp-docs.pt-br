---
title: '&lt;hash_set&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <hash_set>
- std::<hash_set>
dev_langs:
- C++
helpviewer_keywords:
- hash_set header
ms.assetid: 6b556967-c808-4869-9b4d-f9e030864435
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dccf608b9949ad9e1502b489a237adf60a4d50a6
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33845733"
---
# <a name="lthashsetgt"></a>&lt;hash_set&gt;

> [!NOTE]
> Este cabeçalho é obsoleto. A alternativa é [<unordered_set>](../standard-library/unordered-set.md).

Define as classes de modelo do contêiner hash_set e hash_multiset e seus modelos de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <hash_set>

```

## <a name="remarks"></a>Comentários

### <a name="operators"></a>Operadores

|Versão hash_set|Versão hash_multiset|Descrição|
|-----------------------|----------------------------|-----------------|
|[operator!= (hash_set)](../standard-library/hash-set-operators.md#op_neq)|[operator!= (hash_multiset)](../standard-library/hash-set-operators.md#op_neq)|Testa se o objeto hash_set ou hash_multiset no lado esquerdo do operador não é igual ao objeto hash_set ou hash_multiset no lado direito.|
|[operator== (hash_set)](../standard-library/hash-set-operators.md#op_eq_eq)|[operator== (hash_multiset)](../standard-library/hash-set-operators.md#op_eq_eq)|Testa se o objeto hash_set ou hash_multiset no lado esquerdo do operador é igual ao objeto hash_set ou hash_multiset no lado direito.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|Versão hash_set|Versão hash_multiset|Descrição|
|-----------------------|----------------------------|-----------------|
|[swap (hash_set)](../standard-library/hash-set-functions.md#swap)|[swap (hash_multiset)](../standard-library/hash-set-functions.md#swap_hash_multiset)|Troca os elementos de dois hash_sets ou hash_multisets.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe hash_compare](../standard-library/hash-compare-class.md)|Descreve um objeto que pode ser usado por qualquer um dos contêineres associativos de hash — hash_map, hash_multimap, hash_set ou hash_multiset — como um objeto de parâmetro **Traits** padrão para ordenar e fazer o hash dos elementos que eles contêm.|
|[Classe hash_set](../standard-library/hash-set-class.md)|Usado para o armazenamento e a recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como valores chave.|
|[Classe hash_multiset](../standard-library/hash-multiset-class.md)|Usado para o armazenamento e a recuperação rápida de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como valores chave.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
