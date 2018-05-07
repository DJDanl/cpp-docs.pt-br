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
ms.openlocfilehash: 75acbc8370c1ea164c72aa6f0c61a95fe287e3d6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="modifying-the-inheritance-of-rmyproviderrowset"></a>Modificando a herança de RMyProviderRowset
Para adicionar o `IRowsetLocate` interface para o exemplo simples de provedor somente leitura, modifique a herança de **RMyProviderRowset**. Inicialmente, **RMyProviderRowset** herda de `CRowsetImpl`. Você precisa modificá-la para herdar de **CRowsetBaseImpl**.  
  
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
  
```  
BEGIN_COM_MAP(CMyRowsetImpl)  
   COM_INTERFACE_ENTRY(IRowsetLocate)  
   COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)  
END_COM_MAP()  
```  
  
 Isso cria um mapa de interface COM que informa `CMyRowsetImpl` chamar **QueryInterface** para ambos os `IRowset` e `IRowsetLocate` interfaces. Para obter todos os a implementação para outro conjunto de linhas de classes, os links do mapa de `CMyRowsetImpl` classe de volta para o **CRowsetBaseImpl** classe definida pelos modelos OLE DB; o mapa usa a macro COM_INTERFACE_ENTRY_CHAIN, que informa Modelos OLE DB para verificar o COM mapeiam em **CRowsetBaseImpl** em resposta a um `QueryInterface` chamar.  
  
 Por fim, vincular `RAgentRowset` para `CMyRowsetBaseImpl` modificando `RAgentRowset` herde `CMyRowsetImpl`, da seguinte maneira:  
  
```  
class RAgentRowset : public CMyRowsetImpl<RAgentRowset, CAgentMan, CMyProviderCommand>  
```  
  
 `RAgentRowset` agora pode usar o `IRowsetLocate` interface, aproveitando o restante da implementação da classe de conjunto de linhas.  
  
 Quando isso for feito, você pode [determinar dinamicamente colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).  
  
## <a name="see-also"></a>Consulte também  
 [Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)