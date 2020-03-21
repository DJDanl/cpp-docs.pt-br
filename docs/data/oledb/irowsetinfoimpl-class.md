---
title: Classe IRowsetInfoImpl
ms.date: 11/04/2016
f1_keywords:
- ATL.IRowsetInfoImpl
- IRowsetInfoImpl
- ATL::IRowsetInfoImpl
- ATL.IRowsetInfoImpl.GetProperties
- IRowsetInfoImpl.GetProperties
- ATL::IRowsetInfoImpl::GetProperties
- IRowsetInfoImpl::GetProperties
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
helpviewer_keywords:
- IRowsetInfoImpl class
- GetProperties method
- GetReferencedRowset method
- GetSpecification method
ms.assetid: 9c654155-7727-464e-bd31-143e68391a47
ms.openlocfilehash: 691871bfc4a9e63167611a3228807fb12e32d1cb
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077877"
---
# <a name="irowsetinfoimpl-class"></a>Classe IRowsetInfoImpl

Fornece uma implementação para a interface [IRowsetInfo](/previous-versions/windows/desktop/ms724541(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class PropClass = T>
class ATL_NO_VTABLE IRowsetInfoImpl :
   public IRowsetInfo,
   public CUtlProps<PropClass>
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `IRowsetInfoImpl`.

*PropClass*<br/>
Uma classe de propriedade definida pelo usuário que assume como padrão *T*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** altdb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetProperties](#getproperties)|Retorna as configurações atuais de todas as propriedades compatíveis com o conjunto de linhas.|
|[GetReferencedRowset](#getreferencedrowset)|Retorna um ponteiro de interface para o conjunto de linhas ao qual um indicador se aplica.|
|[Getespecíficaion](#getspecification)|Retorna um ponteiro de interface no objeto (comando ou sessão) que criou esse conjunto de linhas.|

## <a name="remarks"></a>Comentários

Uma interface obrigatória em conjuntos de linhas. Essa classe implementa as propriedades do conjunto de linhas usando o [mapa de conjunto de propriedades](../../data/oledb/begin-propset-map.md) definido em sua classe de comando. Embora a classe Rowset pareça estar usando os conjuntos de propriedades da classe Command, o conjunto de linhas é fornecido com sua própria cópia das propriedades de tempo de execução, quando ele é criado por um comando ou objeto de sessão.

## <a name="irowsetinfoimplgetproperties"></a><a name="getproperties"></a>IRowsetInfoImpl:: GetProperties

Retorna as configurações atuais das propriedades no grupo de `DBPROPSET_ROWSET`.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetProperties )(const ULONG cPropertyIDSets,
   const DBPROPIDSET rgPropertyIDSets[],
   ULONG* pcPropertySets,
   DBPROPSET** prgPropertySets);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetInfo:: GetProperties](/previous-versions/windows/desktop/ms719611(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetinfoimplgetreferencedrowset"></a><a name="getreferencedrowset"></a>IRowsetInfoImpl::GetReferencedRowset

Retorna um ponteiro de interface para o conjunto de linhas ao qual um indicador se aplica.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetReferencedRowset )(DBORDINAL iOrdinal,
   REFIID riid,
   IUnknown** ppReferencedRowset);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetInfo:: GetReferencedRowset](/previous-versions/windows/desktop/ms721145(v=vs.85)) na *referência do programador de OLE DB*. O parâmetro *iOrdinal* deve ser uma coluna de indicador.

## <a name="irowsetinfoimplgetspecification"></a><a name="getspecification"></a>IRowsetInfoImpl:: getespecificion

Retorna um ponteiro de interface no objeto (comando ou sessão) que criou esse conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetSpecification )(REFIID riid,
   IUnknown** ppSpecification);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetInfo:: Getespecification](/previous-versions/windows/desktop/ms716746(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Use esse método com [IGetDataSourceImpl](../../data/oledb/igetdatasourceimpl-class.md) para recuperar propriedades do objeto de fonte de dados.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)