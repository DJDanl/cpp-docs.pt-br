---
title: Modificando a herança de RMyProviderRowset | Microsoft Docs
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
ms.assetid: 33089c90-98a4-43e7-8e67-d4bb137e267e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 77b26d1d0b67726e1ba2cd66d0e181bc04105a6a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46028162"
---
# <a name="modifying-the-inheritance-of-rmyproviderrowset"></a>Modificando a herança de RMyProviderRowset

Para adicionar o `IRowsetLocate` da interface para o exemplo de provedor somente leitura simples, modifique a herança de `RMyProviderRowset`. Inicialmente, `RMyProviderRowset` herda de `CRowsetImpl`. Você precisa modificá-lo para herdar de `CRowsetBaseImpl`.  
  
Para fazer isso, crie uma nova classe, `CMyRowsetImpl`, em myproviderrs. H:  
  
```cpp
////////////////////////////////////////////////////////////////////////  
// MyProviderRS.h  
  
template <class T, class Storage, class CreatorClass, class ArrayType = CAtlArray<Storage>>  
class CMyRowsetImpl:  
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType, CSimpleRow, IRowsetLocateImpl< T, IRowsetLocate >>  
{  
...  
};  
```  
  
Agora, edite o mapa de interface COM em myproviderrs. H para ser da seguinte maneira:  
  
```cpp  
BEGIN_COM_MAP(CMyRowsetImpl)  
   COM_INTERFACE_ENTRY(IRowsetLocate)  
   COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)  
END_COM_MAP()  
```  
  
Isso cria um mapa de interface COM que informa `CMyRowsetImpl` chamar `QueryInterface` para ambas as `IRowset` e `IRowsetLocate` interfaces. Para obter a implementação para outro conjunto de linhas de todas as classes, os links do mapa a `CMyRowsetImpl` classe de volta para o `CRowsetBaseImpl` classe definida pelos modelos OLE DB; o mapa usa a macro COM_INTERFACE_ENTRY_CHAIN, que informa ao modelos OLE DB para verificar o mapa COM em `CRowsetBaseImpl` em resposta a um `QueryInterface` chamar.  
  
Por fim, vincule `RAgentRowset` à `CMyRowsetBaseImpl` modificando `RAgentRowset` herdar de `CMyRowsetImpl`, da seguinte maneira:  
  
```cpp  
class RAgentRowset : public CMyRowsetImpl<RAgentRowset, CAgentMan, CMyProviderCommand>  
```  
  
`RAgentRowset` agora pode usar o `IRowsetLocate` interface aproveitando as vantagens do resto da implementação para a classe de conjunto de linhas.  
  
Quando isso for feito, você pode [determinar dinamicamente colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).  
  
## <a name="see-also"></a>Consulte também  

[Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)