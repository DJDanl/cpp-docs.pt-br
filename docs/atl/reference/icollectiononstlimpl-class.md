---
title: Classe ICollectionOnSTLImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- ICollectionOnSTLImpl
- ATLCOM/ATL::ICollectionOnSTLImpl
- ATLCOM/ATL::ICollectionOnSTLImpl::get__NewEnum
- ATLCOM/ATL::ICollectionOnSTLImpl::getcount
- ATLCOM/ATL::ICollectionOnSTLImpl::get_Item
- ATLCOM/ATL::ICollectionOnSTLImpl::m_coll
dev_langs:
- C++
helpviewer_keywords:
- ICollectionOnSTLImpl class
ms.assetid: 683c88b0-0d97-4779-a762-e493334ba7f9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6bbfb34d34f6bd920744621042f5f3e09143e896
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43751313"
---
# <a name="icollectiononstlimpl-class"></a>Classe ICollectionOnSTLImpl

Essa classe fornece métodos usados por uma classe de coleção.

## <a name="syntax"></a>Sintaxe

```
template <class T, class CollType, class ItemType, class CopyItem, class EnumType>  
class ICollectionOnSTLImpl : public T
```

#### <a name="parameters"></a>Parâmetros

*T*  
Uma interface de coleção de COM.

*CollType*  
Uma classe de contêiner da biblioteca padrão C++.

*ItemType*  
O tipo de item exposto pela interface do contêiner.

*CopyItem*  
Um [copie a classe da diretiva](../../atl/atl-copy-policy-classes.md).

*EnumType*  
Um [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md)-classe de enumerador compatível.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ICollectionOnSTLImpl::get__NewEnum](#newenum)|Retorna um objeto enumerador para a coleção.|
|[ICollectionOnSTLImpl::getcount](#get_count)|Retorna o número de elementos na coleção.|
|[ICollectionOnSTLImpl::get_Item](#get_item)|Retorna o item solicitado da coleção.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[ICollectionOnSTLImpl::m_coll](#m_coll)|A coleção.|

## <a name="remarks"></a>Comentários

Essa classe fornece a implementação de três métodos de uma interface de coleção: [getcount](#get_count), [get_Item](#get_item), e [get__NewEnum](#newenum).

Para usar essa classe:

- Definir (ou emprestar) uma interface de coleção que você deseja implementar.

- Derive sua classe de uma especialização de `ICollectionOnSTLImpl` com base nesta interface de coleção.

- Use sua classe derivada para implementar quaisquer métodos da interface de coleção não tratada pelo `ICollectionOnSTLImpl`.

> [!NOTE]
>  Se a interface de coleção é uma interface dupla, derive sua classe de [IDispatchImpl](../../atl/reference/idispatchimpl-class.md), passando o `ICollectionOnSTLImpl` especialização como o primeiro parâmetro de modelo se você quiser que o ATL para fornecer a implementação do `IDispatch` métodos.

- Adicionar itens para o [m_coll](#m_coll) membro para popular a coleção.

Para obter mais informações e exemplos, consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`ICollectionOnSTLImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="get_count"></a>  ICollectionOnSTLImpl::getcount

Esse método retorna o número de itens na coleção.

```
STDMETHOD(getcount)(long* pcount);
```

### <a name="parameters"></a>Parâmetros

*pcount*  
[out] O número de elementos na coleção.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="get_item"></a>  ICollectionOnSTLImpl::get_Item

Esse método retorna o item especificado da coleção.

```
STDMETHOD(get_Item)(long Index, ItemType* pvar);
```

### <a name="parameters"></a>Parâmetros

*Índice*  
[in] O índice baseado em 1 de um item na coleção.

*pvar*  
[out] O item correspondente *índice*.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O item é obtido, copiando os dados na posição especificada em [m_coll](#m_coll) usando o método de cópia do [copie a classe da diretiva](../../atl/atl-copy-policy-classes.md) passado como um argumento de modelo no `ICollectionOnSTLImpl` especialização.

##  <a name="newenum"></a>  ICollectionOnSTLImpl::get__NewEnum

Retorna um objeto enumerador para a coleção.

```
STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*ppUnk*  
[out] O **IUnknown** ponteiro de um objeto de enumerador recém-criado.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O enumerador recém-criado mantém um iterador de coleção original, `m_coll`(portanto, não é feita nenhuma cópia) e mantém uma referência COM no objeto de coleção para garantir que a coleção permaneça ativa enquanto houver enumeradores pendentes.

##  <a name="m_coll"></a>  ICollectionOnSTLImpl::m_coll

Esse membro contém os itens representados pela coleção.

```
CollType m_coll;
```

## <a name="see-also"></a>Consulte também

[Exemplo de ATLCollections](../../visual-cpp-samples.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
