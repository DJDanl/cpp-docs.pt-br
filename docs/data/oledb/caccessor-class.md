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
ms.openlocfilehash: 032274d7dc85aa823cd28cf61e4606903f13ad9e
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509561"
---
# <a name="caccessor-class"></a>Classe CAccessor

Representa um dos tipos de acessadores.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class CAccessor : public CAccessorBase, public T
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe de registro de usuário.

## <a name="remarks"></a>Comentários

Ele é usado quando um registro é ligado estaticamente a uma fonte de dados. O registro contém o buffer. Essa classe dá suporte a vários acessadores em um conjunto de linhas.

Use esse tipo de acessador quando você souber a estrutura e o tipo do banco de dados.

Se o acessador contiver campos que apontam para memória (como uma `BSTR` interface ou) que devem ser liberados, chame a função de membro [CAccessorRowset:: FreeRecordMemory](./caccessorrowset-class.md#freerecordmemory) antes que o próximo registro seja lido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
