---
title: Classe CAccessor
ms.date: 11/04/2016
f1_keywords:
- ATL.CAccessor<T>
- ATL::CAccessor
- CAccessor
- ATL::CAccessor<T>
- ATL.CAccessor
helpviewer_keywords:
- CAccessor class
ms.assetid: b2ba959f-a686-46f3-8837-176248aef748
ms.openlocfilehash: 2b30cef2baf8c13c5001e44901b984aa1293494d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212284"
---
# <a name="caccessor-class"></a>Classe CAccessor

Representa um dos tipos de acessadores.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class CAccessor : public CAccessorBase, public T
```

### <a name="parameters"></a>parâmetros

*T*<br/>
A classe de registro de usuário.

## <a name="remarks"></a>Comentários

Ele é usado quando um registro é ligado estaticamente a uma fonte de dados. O registro contém o buffer. Essa classe dá suporte a vários acessadores em um conjunto de linhas.

Use esse tipo de acessador quando você souber a estrutura e o tipo do banco de dados.

Se o acessador contiver campos que apontam para memória (como uma `BSTR` ou interface) que devem ser liberados, chame a função de membro [CAccessorRowset:: FreeRecordMemory](../../data/oledb/caccessorrowset-freerecordmemory.md) antes que o próximo registro seja lido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
