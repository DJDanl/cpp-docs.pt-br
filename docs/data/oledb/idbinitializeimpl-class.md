---
title: Classe IDBInitializeImpl
ms.date: 11/04/2016
f1_keywords:
- ATL.IDBInitializeImpl<T>
- ATL::IDBInitializeImpl<T>
- IDBInitializeImpl
- ATL::IDBInitializeImpl
- ATL.IDBInitializeImpl
- IDBInitializeImpl.IDBInitializeImpl
- IDBInitializeImpl::IDBInitializeImpl
- Initialize
- IDBInitializeImpl::Initialize
- IDBInitializeImpl.Initialize
- IDBInitializeImpl.Uninitialize
- Uninitialize
- IDBInitializeImpl::Uninitialize
- ATL::IDBInitializeImpl::m_dwStatus
- IDBInitializeImpl.m_dwStatus
- ATL.IDBInitializeImpl.m_dwStatus
- IDBInitializeImpl::m_dwStatus
- IDBInitializeImpl<T>::m_dwStatus
- ATL.IDBInitializeImpl<T>.m_dwStatus
- ATL::IDBInitializeImpl<T>::m_dwStatus
- m_dwStatus
- ATL::IDBInitializeImpl<T>::m_pCUtlPropInfo
- m_pCUtlPropInfo
- IDBInitializeImpl::m_pCUtlPropInfo
- ATL.IDBInitializeImpl.m_pCUtlPropInfo
- IDBInitializeImpl<T>::m_pCUtlPropInfo
- IDBInitializeImpl.m_pCUtlPropInfo
- ATL::IDBInitializeImpl::m_pCUtlPropInfo
helpviewer_keywords:
- IDBInitializeImpl class
- IDBInitializeImpl constructor
- Initialize method
- Uninitialize method
- m_dwStatus
- m_pCUtlPropInfo
ms.assetid: e4182f81-0443-44f5-a0d3-e7e075d6f883
ms.openlocfilehash: aff02e812d2806201a08164aeb4a8ef290550725
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845530"
---
# <a name="idbinitializeimpl-class"></a>Classe IDBInitializeImpl

Fornece uma implementação para a interface [IDBInitialize](/previous-versions/windows/desktop/ms713706(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE IDBInitializeImpl : public IDBInitialize
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `IDBInitializeImpl` .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[IDBInitializeImpl](#idbinitializeimpl)|O construtor.|

### <a name="interface-methods"></a>Métodos de interface

| Nome | Descrição |
|-|-|
|[Inicializar](#initialize)|Inicia o provedor.|
|[Cancelar](#uninitialize)|Interrompe o provedor.|

### <a name="data-members"></a>Membros de dados

| Nome | Descrição |
|-|-|
|[m_dwStatus](#dwstatus)|Sinalizadores de fonte de dados.|
|[m_pCUtlPropInfo](#pcutlpropinfo)|Um ponteiro para a implementação das informações de propriedades do banco de dados.|

## <a name="remarks"></a>Comentários

Uma interface obrigatória em objetos de fonte de dados e interface opcional em enumeradores.

## <a name="idbinitializeimplidbinitializeimpl"></a><a name="idbinitializeimpl"></a> IDBInitializeImpl::IDBInitializeImpl

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
IDBInitializeImpl();
```

### <a name="remarks"></a>Comentários

Inicializa todos os membros de dados.

## <a name="idbinitializeimplinitialize"></a><a name="initialize"></a> IDBInitializeImpl:: Initialize

Inicializa o objeto de fonte de dados preparando seu suporte de propriedade.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(Initialize)(void);
```

### <a name="remarks"></a>Comentários

Consulte [IDBInitialize:: Initialize](/previous-versions/windows/desktop/ms718026(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="idbinitializeimpluninitialize"></a><a name="uninitialize"></a> IDBInitializeImpl:: Uninitialize

Coloca o objeto de fonte de dados em um estado não inicializado liberando recursos internos, como o suporte à propriedade.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(Uninitialize)(void);
```

### <a name="remarks"></a>Comentários

Consulte [IDBInitialize:: Uninitialize](/previous-versions/windows/desktop/ms719648(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="idbinitializeimplm_dwstatus"></a><a name="dwstatus"></a> IDBInitializeImpl:: m_dwStatus

Sinalizadores de fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
DWORD m_dwStatus;
```

### <a name="remarks"></a>Comentários

Esses sinalizadores especificam ou indicam o status de vários atributos para o objeto de fonte de dados. Contém um ou mais dos seguintes **`enum`** valores:

```cpp
enum DATASOURCE_FLAGS {
    DSF_MASK_INIT     = 0xFFFFF00F,
    DSF_PERSIST_DIRTY = 0x00000001,
    DSF_INITIALIZED   = 0x00000010,
};
```

| Valor | Descrição |
|-|-|
|`DSF_MASK_INIT`|Uma máscara para habilitar a restauração do estado não inicializado.|
|`DSF_PERSIST_DIRTY`|Defina se o objeto de fonte de dados exigirá persistência (ou seja, se houver alterações).|
|`DSF_INITIALIZED`|Defina se a fonte de dados foi inicializada.|

## <a name="idbinitializeimplm_pcutlpropinfo"></a><a name="pcutlpropinfo"></a> IDBInitializeImpl:: m_pCUtlPropInfo

Um ponteiro para objeto de implementação para informações de propriedades de banco de dados.

### <a name="syntax"></a>Sintaxe

```cpp
CUtlPropInfo< T >* m_pCUtlPropInfo;
```

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
