---
title: Modificando a herança de RCustomRowset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- RMyProviderRowset
- inheritance [C++]
- RCustomRowset
ms.assetid: 33089c90-98a4-43e7-8e67-d4bb137e267e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1a9b6e238d3824451ab0f820917c34c97826ffab
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060384"
---
# <a name="modifying-the-inheritance-of-rcustomrowset"></a>Modificando a herança de RCustomRowset

Para adicionar o `IRowsetLocate` da interface para o exemplo de provedor somente leitura simples, modifique a herança de `RCustomRowset`. Inicialmente, `RCustomRowset` herda de `CRowsetImpl`. Você precisa modificá-lo para herdar de `CRowsetBaseImpl`.

Para fazer isso, crie uma nova classe, `CCustomRowsetImpl`, em CustomRS.h:

```cpp
////////////////////////////////////////////////////////////////////////
// CustomRS.h

template <class T, class Storage, class CreatorClass, class ArrayType = CAtlArray<Storage>>
class CCustomRowsetImpl:
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType, CSimpleRow, IRowsetLocateImpl< T, IRowsetLocate >>
{
...
};
```

Agora, edite o mapa de interface COM em CustomRS.h ser da seguinte maneira:

```cpp
BEGIN_COM_MAP(CCustomRowsetImpl)
   COM_INTERFACE_ENTRY(IRowsetLocate)
   COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)
END_COM_MAP()
```

Isso cria um mapa de interface COM que informa `CCustomRowsetImpl` chamar `QueryInterface` para ambas as `IRowset` e `IRowsetLocate` interfaces. Para obter a implementação para outro conjunto de linhas de todas as classes, os links do mapa a `CCustomRowsetImpl` classe de volta para o `CRowsetBaseImpl` classe definida pelos modelos OLE DB; o mapa usa a macro COM_INTERFACE_ENTRY_CHAIN, que informa ao modelos OLE DB para verificar o mapa COM em `CRowsetBaseImpl` em resposta a um `QueryInterface` chamar.

Por fim, vincule `RAgentRowset` à `CCustomRowsetBaseImpl` modificando `RAgentRowset` herdar de `CCustomRowsetImpl`, da seguinte maneira:

```cpp
class RAgentRowset : public CCustomRowsetImpl<RAgentRowset, CAgentMan, CCustomCommand>
```

`RAgentRowset` agora pode usar o `IRowsetLocate` interface aproveitando as vantagens do resto da implementação para a classe de conjunto de linhas.

Quando isso for feito, você pode [determinar dinamicamente colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).

## <a name="see-also"></a>Consulte também

[Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)