---
title: Classe ICollectionOnSTLImpl
ms.date: 11/04/2016
f1_keywords:
- ICollectionOnSTLImpl
- ATLCOM/ATL::ICollectionOnSTLImpl
- ATLCOM/ATL::ICollectionOnSTLImpl::get__NewEnum
- ATLCOM/ATL::ICollectionOnSTLImpl::getcount
- ATLCOM/ATL::ICollectionOnSTLImpl::get_Item
- ATLCOM/ATL::ICollectionOnSTLImpl::m_coll
helpviewer_keywords:
- ICollectionOnSTLImpl class
ms.assetid: 683c88b0-0d97-4779-a762-e493334ba7f9
ms.openlocfilehash: a8ccab08b89da8c1b8ef56c8932e27a6c74e62aa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329904"
---
# <a name="icollectiononstlimpl-class"></a>Classe ICollectionOnSTLImpl

Esta classe fornece métodos usados por uma classe de coleta.

## <a name="syntax"></a>Sintaxe

```
template <class T, class CollType, class ItemType, class CopyItem, class EnumType>
class ICollectionOnSTLImpl : public T
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma interface de coleção COM.

*CollType*<br/>
Uma classe de contêiner C++ Standard Library.

*ItemType*<br/>
O tipo de item exposto pela interface do contêiner.

*CopyItem*<br/>
Uma [aula de política de cópia.](../../atl/atl-copy-policy-classes.md)

*Enumtype*<br/>
Uma classe de enumerator compatível com [CComEnumONSTL.](../../atl/reference/ccomenumonstl-class.md)

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iCollectionOnSTLImpl::get__NewEnum](#newenum)|Retorna um objeto enumerador para a coleção.|
|[ICollectionOnSTLImpl::getcount](#get_count)|Retorna o número de elementos da coleção.|
|[iCollectionOnSTLImpl::get_Item](#get_item)|Devolve o item solicitado da coleção.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[iCollectionOnSTLImpl::m_coll](#m_coll)|A coleção.|

## <a name="remarks"></a>Comentários

Esta classe fornece a implementação para três métodos de uma interface de coleção: [getcount](#get_count), [get_Item](#get_item)e [get__NewEnum](#newenum).

Para usar esta classe:

- Defina (ou empreste) uma interface de coleção que você deseja implementar.

- Obtenha sua classe a `ICollectionOnSTLImpl` partir de uma especialização baseada nesta interface de coleção.

- Use sua classe derivada para implementar quaisquer métodos `ICollectionOnSTLImpl`da interface de coleta não manipulados por .

> [!NOTE]
> Se a interface de coleta for uma interface dupla, obtenha `ICollectionOnSTLImpl` sua classe do [IDispatchImpl](../../atl/reference/idispatchimpl-class.md), passando a especialização como o primeiro parâmetro de modelo se você quiser que a ATL forneça a `IDispatch` implementação dos métodos.

- Adicione itens ao [membro m_coll](#m_coll) para preencher a coleção.

Para obter mais informações e exemplos, consulte [ATL Collections e Enumerators](../../atl/atl-collections-and-enumerators.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`ICollectionOnSTLImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="icollectiononstlimplgetcount"></a><a name="get_count"></a>ICollectionOnSTLImpl::getcount

Este método retorna o número de itens da coleção.

```
STDMETHOD(getcount)(long* pcount);
```

### <a name="parameters"></a>Parâmetros

*pcount*<br/>
[fora] O número de elementos na coleção.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="icollectiononstlimplget_item"></a><a name="get_item"></a>iCollectionOnSTLImpl::get_Item

Este método retorna o item especificado da coleção.

```
STDMETHOD(get_Item)(long Index, ItemType* pvar);
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
[em] O índice baseado em 1 de um item na coleção.

*Pvar*<br/>
[fora] O item correspondente ao *Índice*.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O item é obtido copiando os dados na posição especificada em [m_coll](#m_coll) usando o método de `ICollectionOnSTLImpl` cópia da classe de diretiva de [cópia](../../atl/atl-copy-policy-classes.md) aprovado como um argumento de modelo na especialização.

## <a name="icollectiononstlimplget__newenum"></a><a name="newenum"></a>iCollectionOnSTLImpl::get__NewEnum

Retorna um objeto enumerador para a coleção.

```
STDMETHOD(get__NewEnum)(IUnknown** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*ppUnk*<br/>
[fora] O ponteiro **IUnknown** de um objeto enumerador recém-criado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O enumerador recém-criado mantém um iterator `m_coll`na coleção original, (para que nenhuma cópia seja feita) e mantém uma referência COM sobre o objeto de coleta para garantir que a coleção permaneça viva enquanto houver enumeradores pendentes.

## <a name="icollectiononstlimplm_coll"></a><a name="m_coll"></a>iCollectionOnSTLImpl::m_coll

Este membro detém os itens representados pela coleção.

```
CollType m_coll;
```

## <a name="see-also"></a>Confira também

[Amostra atlcollections](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
