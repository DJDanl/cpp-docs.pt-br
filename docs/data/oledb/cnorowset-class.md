---
title: Classe CNoRowset
ms.date: 11/04/2016
f1_keywords:
- ATL.CNoRowset
- ATL::CNoRowset<TAccessor>
- CNoRowset
- ATL.CNoRowset<TAccessor>
- ATL::CNoRowset
helpviewer_keywords:
- CNoRowset class
ms.assetid: 55c6c7a4-9e3a-4775-a2dd-c8b333012fa6
ms.openlocfilehash: 19a1e01fd29c74cf1c44081c24bf384704cf2acd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211465"
---
# <a name="cnorowset-class"></a>Classe CNoRowset

Pode ser usado como um argumento de modelo (`TRowset`) para [CCommand](../../data/oledb/ccommand-class.md) ou [CTable](../../data/oledb/ctable-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CAccessorBase>
class CNoRowset
```

### <a name="parameters"></a>parâmetros

*TAccessor*<br/>
Uma classe de acessador. O padrão é `CAccessorBase`.

## <a name="remarks"></a>Comentários

Use `CNoRowset` como um argumento de modelo se o comando não retornar um conjunto de linhas.

`CNoRowset` implementa os seguintes métodos stub, cada um dos quais corresponde a outros métodos de classe de acessador:

- `BindFinished`-indica quando a associação está concluída (retorna `S_OK`).

- `Close`-libera as linhas e a interface IRowset atual.

- `GetIID`-recupera a ID de interface de um ponto de conexão.

- `GetInterface`-recupera uma interface.

- `GetInterfacePtr`-recupera um ponteiro de interface encapsulado.

- `SetAccessor`-define um ponteiro para o acessador.

- `SetupOptionalRowsetInterfaces`-Configura interfaces opcionais para o conjunto de linhas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
