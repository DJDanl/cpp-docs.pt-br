---
title: Modificando a herança de RCustomRowset
ms.date: 10/26/2018
helpviewer_keywords:
- RMyProviderRowset
- inheritance [C++]
- RCustomRowset
ms.assetid: 33089c90-98a4-43e7-8e67-d4bb137e267e
ms.openlocfilehash: 51cca65b6b55de8b628cb5d233ab06f0101f466d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50637951"
---
# <a name="modifying-the-inheritance-of-rcustomrowset"></a>Modificando a herança de RCustomRowset

Para adicionar o `IRowsetLocate` da interface para o exemplo de provedor somente leitura simples, modifique a herança de `RCustomRowset`. Inicialmente, `RCustomRowset` herda de `CRowsetImpl`. Você precisa modificá-lo para herdar de `CRowsetBaseImpl`.

Para fazer isso, crie uma nova classe, `CCustomRowsetImpl`, em CustomRS.h:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.h

template <class T, class Storage, class CreatorClass, class ArrayType = CAtlArray<Storage>>
class CMyRowsetImpl:
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType, CSimpleRow, IRowsetLocateImpl< T, IRowsetLocate >>
{
...
};
```

Agora, edite o mapa de interface COM em *personalizado*RS.h ser da seguinte maneira:

```cpp
BEGIN_COM_MAP(CMyRowsetImpl)
   COM_INTERFACE_ENTRY(IRowsetLocate)
   COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)
END_COM_MAP()
```

Esse código cria um mapa de interface COM que informa `CMyRowsetImpl` chamar `QueryInterface` para ambas as `IRowset` e `IRowsetLocate` interfaces. Para obter a implementação para outro conjunto de linhas de todas as classes, os links do mapa a `CMyRowsetImpl` classe de volta para o `CRowsetBaseImpl` classe definida pelos modelos OLE DB; o mapa usa a macro COM_INTERFACE_ENTRY_CHAIN, que informa ao modelos OLE DB para verificar o mapa COM em `CRowsetBaseImpl` em resposta a um `QueryInterface` chamar.

Por fim, vincule `RAgentRowset` à `CMyRowsetBaseImpl` modificando `RAgentRowset` herdar de `CMyRowsetImpl`, da seguinte maneira:

```cpp
class RAgentRowset : public CMyRowsetImpl<RAgentRowset, CAgentMan, CCustomCommand>
```

`RAgentRowset` agora pode usar o `IRowsetLocate` interface aproveitando as vantagens do resto da implementação para a classe de conjunto de linhas.

Quando isso for feito, você pode [determinar dinamicamente colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).

## <a name="see-also"></a>Consulte também

[Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)<br/>
