---
title: Classe IRowsetUpdateImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IRowsetUpdateImpl
- ATL.IRowsetUpdateImpl
- ATL::IRowsetUpdateImpl
dev_langs:
- C++
helpviewer_keywords:
- providers, updatable
- IRowsetUpdateImpl class
- updatable providers, deferred update
ms.assetid: f85af76b-ab6f-4f8b-8f4a-337c9679d68f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 34efd252f67a0e3da9827ef97cff8bcab0a45532
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="irowsetupdateimpl-class"></a>Classe IRowsetUpdateImpl
A implementação de modelos OLE DB do [IRowsetUpdate](https://msdn.microsoft.com/en-us/library/ms714401.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <  
   class T,   
   class Storage,   
   class UpdateArray = CAtlArray<Storage>,   
   class RowClass = CSimpleRow,   
   class MapClass = CAtlMap <RowClass::KeyType, RowClass*>   
>  

class IRowsetUpdateImpl : public IRowsetChangeImpl<  
   T,   
   Storage,   
   IRowsetUpdate,   
   RowClass,   
   MapClass>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe derivada de `IRowsetUpdateImpl`.  
  
 `Storage`  
 O registro do usuário.  
  
 `UpdateArray`  
 Uma matriz que contém os dados armazenados em cache para atualizar o conjunto de linhas.  
  
 `RowClass`  
 A unidade de armazenamento para o **HROW**.  
  
 `MapClass`  
 A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods-used-with-irowsetchange"></a>Métodos de interface (usados com IRowsetChange)  
  
|||  
|-|-|  
|[SetData](../../data/oledb/irowsetupdateimpl-setdata.md)|Define valores de dados em uma ou mais colunas.|  
  
### <a name="interface-methods-used-with-irowsetupdate"></a>Métodos de interface (usados com IRowsetUpdate)  
  
|||  
|-|-|  
|[GetOriginalData](../../data/oledb/irowsetupdateimpl-getoriginaldata.md)|Obtém os dados transmitidos para ou obtidos da fonte de dados, ignorando as alterações pendentes mais recentemente.|  
|[GetPendingRows](../../data/oledb/irowsetupdateimpl-getpendingrows.md)|Retorna uma lista de linhas com alterações pendentes.|  
|[GetRowStatus](../../data/oledb/irowsetupdateimpl-getrowstatus.md)|Retorna o status de linhas especificados.|  
|[Desfazer](../../data/oledb/irowsetupdateimpl-undo.md)|Desfaz todas as alterações a linha desde a última busca ou atualização.|  
|[Atualizar](../../data/oledb/irowsetupdateimpl-update.md)|Transmite todas as alterações feitas desde a última busca ou atualizar a linha.|  
  
### <a name="implementation-methods-callback"></a>Métodos de implementação (retorno de chamada)  
  
|||  
|-|-|  
|[IsUpdateAllowed](../../data/oledb/irowsetupdateimpl-isupdateallowed.md)|Usado para verificar a segurança, a integridade, e assim por diante antes de permitir atualizações.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_mapCachedData](../../data/oledb/irowsetupdateimpl-m-mapcacheddata.md)|Contém os dados originais para a operação adiada.|  
  
## <a name="remarks"></a>Comentários  
 Primeiro, você deve ler e entender a documentação de [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx), pois tudo descrita lá também se aplica aqui. Você também deve ler o capítulo 6 o *referência do programador de DB OLE* sobre a definição de dados.  
  
 `IRowsetUpdateImpl` implementa o OLE DB `IRowsetUpdate` interface, que permite que os consumidores atrasar a transmissão das alterações feitas com `IRowsetChange` para os dados de origem e desfazer as alterações antes da transmissão.  
  
> [!IMPORTANT]
>  É altamente recomendável que você leia a documentação a seguir antes de tentar implementar seu provedor:  
  
-   [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)  
  
-   Capítulo 6 a *referência do programador de OLE DB*  
  
-   Consulte também como o `RUpdateRowset` classe é usada no exemplo UpdatePV  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)