---
title: Classe hash_compare
ms.date: 11/04/2016
f1_keywords:
- hash_set/stdext::hash_compare
helpviewer_keywords:
- hash_compare class
ms.assetid: d502bb59-de57-4585-beb9-00e3a998c0af
ms.openlocfilehash: 4fb44a371630a66275f6ef59a0bf66b4cb73a71f
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689558"
---
# <a name="hash_compare-class"></a>Classe hash_compare

O modelo de classe descreve um objeto que pode ser usado por qualquer um dos contêineres associativos de hash — hash_map, hash_multimap, hash_set ou hash_multiset — como um objeto de parâmetro de **características** padrão para ordenar e aplicar hash aos elementos que eles contêm.

## <a name="syntax"></a>Sintaxe

class hash_compare { Traits comp; public: const size_t bucket_size = 4; const size_t min_buckets = 8; hash_compare(); hash_compare(Traits pred); size_t operator()(const Key& key) const; bool operator()( const Key& key1, const Key& key2) const; };

## <a name="remarks"></a>Comentários

Cada contêiner associativo de hash armazena um objeto de características de hash do tipo `Traits` (um parâmetro de modelo). Você pode derivar uma classe de uma especialização de hash_compare para substituir seletivamente determinadas funções e objetos ou pode fornecer sua própria versão dessa classe se atender a certos requisitos mínimos. Especificamente, para um objeto hash_comp do tipo `hash_compare<Key, Traits>`, o seguinte comportamento é exigido pelos contêineres acima:

- Para todos os valores `key` do tipo `Key`, a chamada **hash_comp**(`key`) serve como uma função de hash, que produz uma distribuição de valores do tipo `size_t`. A função fornecida por hash_compare retorna `key`.

- Para qualquer valor `key1` do tipo `Key` que precede `key2` na sequência e tem o mesmo valor de hash (valor retornado pela função de hash), **hash_comp**(`key2`, `key1`) é false. A função deve impor uma ordenação total em valores do tipo `Key`. A função fornecida por hash_compare retorna *comp*(`key2`, `key1`) `,` em que *comp* é um objeto armazenado do tipo `Traits` que você pode especificar ao construir o objeto hash_comp. Para o tipo de parâmetro de `Traits` padrão `less<Key>`, as chaves de classificação nunca diminuem em valor.

- A constante de inteiro `bucket_size` especifica o número médio de elementos por "Bucket" (entrada de tabela de hash) que o contêiner deve tentar não exceder. Ela deve ser maior que zero. O valor fornecido por hash_compare é 4.

- A constante de inteiro `min_buckets` especifica o número mínimo de buckets a serem mantidos na tabela de hash. Ela deve ser uma potência de dois e maior que zero. O valor fornecido por hash_compare é 8.

## <a name="example"></a>Exemplo

Veja exemplos de [hash_map::hash_map](../standard-library/hash-map-class.md#hash_map), [hash_multimap::hash_multimap](../standard-library/hash-multimap-class.md#hash_multimap), [hash_set::hash_set](../standard-library/hash-set-class.md#hash_set) e [hash_multiset::hash_multiset](../standard-library/hash-multiset-class.md#hash_multiset), para ver exemplos de como declarar e usar hash_compare.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<hash_map>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
