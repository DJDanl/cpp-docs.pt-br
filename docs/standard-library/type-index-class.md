---
title: Classe type_index
ms.date: 11/04/2016
f1_keywords:
- typeindex/std::type_index
helpviewer_keywords:
- type_index class
ms.assetid: db366119-74cb-43e8-aacf-9679e561fa2f
ms.openlocfilehash: b30c9719957b9ffc5f3ce17692eb90c1b266ae0f
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68447048"
---
# <a name="typeindex-class"></a>Classe type_index

A classe `type_index` encapsula um ponteiro para a [Classe type_info](../cpp/type-info-class.md) para auxiliar na indexação por esses objetos.

classe type_index { public: type_index(const type_info& tinfo); const char *name() const; size_t hash_code() const; bool operator==(const type_info& right) const; bool operator!=(const type_info& right) const; bool operator<(const type_info& right) const; bool operator\<=(const type_info& right) const; bool operator>(const type_info& right) const; bool operator>=(const type_info& right) const; };

O construtor inicializa `ptr` para `&tinfo`.

`name` retorna `ptr->name()`.

`hash_code` retorna `ptr->hash_code().`

`operator==` retorna `*ptr == right.ptr`.

`operator!=` retorna `!(*this == right)`.

`operator<` retorna `*ptr->before(*right.ptr)`.

`operator<=` retorna `!(right < *this).`

`operator>` retorna `right < *this`.

`operator>=` retorna `!(*this < right)`.

## <a name="see-also"></a>Consulte também

[Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)\
[\<typeindex>](../standard-library/typeindex.md)
