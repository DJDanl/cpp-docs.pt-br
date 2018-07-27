---
title: Classe IRowsetInfoImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IRowsetInfoImpl
- IRowsetInfoImpl
- ATL::IRowsetInfoImpl
- ATL.IRowsetInfoImpl.GetProperties
- IRowsetInfoImpl.GetProperties
- ATL::IRowsetInfoImpl::GetProperties
- IRowsetInfoImpl::GetProperties
- GetProperties
- ATL::IRowsetInfoImpl::GetReferencedRowset
- GetReferencedRowset
- ATL.IRowsetInfoImpl.GetReferencedRowset
- IRowsetInfoImpl.GetReferencedRowset
- IRowsetInfoImpl::GetReferencedRowset
- IRowsetInfoImpl::GetSpecification
- ATL.IRowsetInfoImpl.GetSpecification
- IRowsetInfoImpl.GetSpecification
- GetSpecification
- ATL::IRowsetInfoImpl::GetSpecification
dev_langs:
- C++
helpviewer_keywords:
- IRowsetInfoImpl class
- GetProperties method
- GetReferencedRowset method
- GetSpecification method
ms.assetid: 9c654155-7727-464e-bd31-143e68391a47
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4ccf4d6b34362d4c8b7875319af444f755d741e7
ms.sourcegitcommit: e5792fcb89b9ba64c401f90f4f26a8e45d4a2359
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2018
ms.locfileid: "39322030"
---
# <a name="irowsetinfoimpl-class"></a>Classe IRowsetInfoImpl
Fornece uma implementação para o [IRowsetInfo](https://msdn.microsoft.com/library/ms724541.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class PropClass = T>  
class ATL_NO_VTABLE IRowsetInfoImpl :   
   public IRowsetInfo,    
   public CUtlProps<PropClass>  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IRowsetInfoImpl`.  
  
 *PropClass*  
 Uma classe de propriedade definidos pelo usuário que assume como padrão *T*. 

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** altdb.h   
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetProperties](#getproperties)|Retorna as configurações atuais de todas as propriedades compatíveis com o conjunto de linhas.|  
|[GetReferencedRowset](#getreferencedrowset)|Retorna um ponteiro de interface para o conjunto de linhas ao qual se aplica a um indicador.|  
|[GetSpecification](#getspecification)|Retorna um ponteiro de interface no objeto (comando ou sessão) que criou esse conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória em conjuntos de linhas. Essa classe implementa as propriedades do conjunto de linhas usando o [mapa de conjunto de propriedade](../../data/oledb/begin-propset-map.md) definidos em sua classe de comando. Embora a classe de conjunto de linhas é exibida para estar usando a propriedade a classe de comando conjuntos, o conjunto de linhas é fornecido com sua própria cópia das propriedades do tempo de execução, quando ele é criado por um objeto de comando ou sessão.  
  
## <a name="getproperties"></a> Irowsetinfoimpl:: GetProperties
Retorna as configurações atuais para as propriedades no `DBPROPSET_ROWSET` grupo.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD (GetProperties )(const ULONG cPropertyIDSets,  
   const DBPROPIDSET rgPropertyIDSets[],  
   ULONG* pcPropertySets,  
   DBPROPSET** prgPropertySets);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [irowsetinfo:: GetProperties](https://msdn.microsoft.com/library/ms719611.aspx) na *referência do programador do OLE DB*. 

## <a name="getreferencedrowset"></a> Irowsetinfoimpl:: Getreferencedrowset
Retorna um ponteiro de interface para o conjunto de linhas ao qual se aplica a um indicador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD (GetReferencedRowset )(DBORDINAL iOrdinal,  
   REFIID riid,  
   IUnknown** ppReferencedRowset);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IRowsetInfo::GetReferencedRowset](https://msdn.microsoft.com/library/ms721145.aspx) na *referência do programador do OLE DB*. O *iOrdinal* parâmetro deve ser uma coluna de indicador. 

## <a name="getspecification"></a> Irowsetinfoimpl:: Getspecification
Retorna um ponteiro de interface no objeto (comando ou sessão) que criou esse conjunto de linhas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD (GetSpecification )(REFIID riid,  
   IUnknown** ppSpecification);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IRowsetInfo::GetSpecification](https://msdn.microsoft.com/library/ms716746.aspx) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 Use esse método com [IGetDataSourceImpl](../../data/oledb/igetdatasourceimpl-class.md) para recuperar as propriedades do objeto de fonte de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
