---
title: Classe IDBPropertiesImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IDBPropertiesImpl
- ATL.IDBPropertiesImpl
- ATL.IDBPropertiesImpl<T>
- ATL::IDBPropertiesImpl<T>
- ATL::IDBPropertiesImpl
- IDBPropertiesImpl::GetProperties
- IDBPropertiesImpl.GetProperties
- GetProperties
- IDBPropertiesImpl::GetPropertyInfo
- IDBPropertiesImpl.GetPropertyInfo
- GetPropertyInfo
- IDBPropertiesImpl.SetProperties
- SetProperties
- IDBPropertiesImpl::SetProperties
dev_langs:
- C++
helpviewer_keywords:
- IDBPropertiesImpl class
- GetProperties method
- GetPropertyInfo method
- SetProperties method
ms.assetid: a7f15a8b-95b2-4316-b944-d5d03f8d74ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 51593d14967e2814d69cb0a912d937b689dc3632
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39337109"
---
# <a name="idbpropertiesimpl-class"></a>Classe IDBPropertiesImpl
Fornece uma implementação para o `IDBProperties` interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T>   
class ATL_NO_VTABLE IDBPropertiesImpl   
   : public IDBProperties, public CUtlProps<T>  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IDBPropertiesImpl`.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetProperties](#getproperties)|Retorna os valores das propriedades dos grupos de propriedade de inicialização, informações de fonte de dados e fonte de dados que estão atualmente definidas no objeto de fonte de dados ou os valores das propriedades no grupo de propriedades de inicialização são definidas no momento no enumerador.|  
|[GetPropertyInfo](#getpropertyinfo)|Retorna informações sobre todas as propriedades com suporte pelo provedor.|  
|[SetProperties](#setproperties)|Define propriedades em grupos de propriedades fonte de dados e de inicialização, para objetos de fonte de dados, ou o grupo de propriedades de inicialização para enumeradores.|  
  
## <a name="remarks"></a>Comentários  
 [IDBProperties](https://msdn.microsoft.com/library/ms719607.aspx) é uma interface obrigatória para objetos de fonte de dados e uma interface opcional para enumeradores. No entanto, se expõe um enumerador [IDBInitialize](https://msdn.microsoft.com/library/ms713706.aspx), ele deve expor `IDBProperties`. `IDBPropertiesImpl` implementa `IDBProperties` usando uma função estática definida por [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  

## <a name="getproperties"></a> Idbpropertiesimpl:: GetProperties
Retorna os valores das propriedades dos grupos de propriedade de inicialização, informações de fonte de dados e fonte de dados que estão atualmente definidas no objeto de fonte de dados ou os valores das propriedades no grupo de propriedades de inicialização são definidas no momento no enumerador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetProperties)(ULONG cPropertySets,   
   const DBPROPIDSET rgPropertySets[],   
   ULONG * pcProperties,   
   DBPROPSET ** prgProperties);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [idbproperties:: GetProperties](https://msdn.microsoft.com/library/ms714344.aspx) na *referência do programador do OLE DB*.  
  
 Alguns parâmetros correspondem aos *referência do programador DB OLE* parâmetros de nomes diferentes, que são descritos em `IDBProperties::GetProperties`:  
  
|Parâmetros de modelo de banco de dados OLE|*Referência do OLE DB Programmer* parâmetros|  
|--------------------------------|------------------------------------------------|  
|*cPropertySets*|*cPropertyIDSets*|  
|*rgPropertySets*|*rgPropertyIDSets*|  
|*pcProperties*|*pcPropertySets*|  
|*prgProperties*|*prgPropertySets*|  
  
### <a name="remarks"></a>Comentários  
 Se o provedor é inicializado, esse método retorna os valores das propriedades em DBPROPSET_DATASOURCE, DBPROPSET_DATASOURCEINFO, grupos de propriedades DBPROPSET_DBINIT definidas atualmente no objeto de fonte de dados. Se o provedor não é inicializado, ele retorna somente propriedades de grupo DBPROPSET_DBINIT. 
  
## <a name="getpropertyinfo"></a> Idbpropertiesimpl:: Getpropertyinfo
Retorna informações de propriedade com suporte pela fonte de dados.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetPropertyInfo)(ULONG cPropertySets,   
   const DBPROPIDSET rgPropertySets[],   
   ULONG * pcPropertyInfoSets,   
   DBPROPINFOSET ** prgPropertyInfoSets,   
   OLECHAR ** ppDescBuffer);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [idbproperties:: Getpropertyinfo](https://msdn.microsoft.com/library/ms718175.aspx) na *referência do programador do OLE DB*.  
  
 Alguns parâmetros correspondem aos *referência do programador DB OLE* parâmetros de nomes diferentes, que são descritos em `IDBProperties::GetPropertyInfo`:  
  
|Parâmetros de modelo de banco de dados OLE|*Referência do OLE DB Programmer* parâmetros|  
|--------------------------------|------------------------------------------------|  
|*cPropertySets*|*cPropertyIDSets*|  
|*rgPropertySets*|*rgPropertyIDSets*|  
  
### <a name="remarks"></a>Comentários  
 Usa [idbinitializeimpl:: M_pcutlpropinfo](../../data/oledb/idbinitializeimpl-m-pcutlpropinfo.md) para implementar essa funcionalidade. 

## <a name="setproperties"></a> Idbpropertiesimpl:: SetProperties
Define propriedades em grupos de propriedades fonte de dados e de inicialização, para objetos de fonte de dados, ou o grupo de propriedades de inicialização para enumeradores.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,   
   DBPROPSET rgPropertySets[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [idbproperties:: SetProperties](https://msdn.microsoft.com/library/ms723049.aspx) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 Se o provedor é inicializado, esse método define os valores das propriedades de DBPROPSET_DATASOURCE, DBPROPSET_DATASOURCEINFO, grupos de propriedades DBPROPSET_DBINIT para o objeto de fonte de dados. Se o provedor não é inicializado, ele define somente propriedades de grupo DBPROPSET_DBINIT.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)