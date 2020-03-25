---
title: Classe CAccessorBase
ms.date: 11/04/2016
f1_keywords:
- CAccessorBase
- CAccessorBase.Close
- CAccessorBase::Close
- GetHAccessor
- CAccessorBase::GetHAccessor
- CAccessorBase.GetHAccessor
- CAccessorBase::GetNumAccessors
- GetNumAccessors
- CAccessorBase.GetNumAccessors
- IsAutoAccessor
- CAccessorBase.IsAutoAccessor
- CAccessorBase::IsAutoAccessor
- CAccessorBase::ReleaseAccessors
- CAccessorBase.ReleaseAccessors
- ReleaseAccessors
helpviewer_keywords:
- CAccessorBase class
- Close method
- GetHAccessor method
- GetNumAccessors method
- IsAutoAccessor method
- ReleaseAccessors method
ms.assetid: 389b65be-11ca-4ae0-9290-60c621c4982b
ms.openlocfilehash: 8aef8a04d7adff903e21491a91014d55aab769da
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212286"
---
# <a name="caccessorbase-class"></a>Classe CAccessorBase

Todos os acessadores nos modelos de OLE DB derivam dessa classe. `CAccessorBase` permite que um conjunto de linhas gerencie vários acessadores. Ele também fornece Associação para parâmetros e colunas de saída.

## <a name="syntax"></a>Sintaxe

```cpp
// Replace with syntax
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Fechar](#close)|Fecha os acessadores.|
|[GetHAccessor](#geth)|Recupera o identificador de acessador.|
|[GetNumAccessors](#getnum)|Recupera o número de acessadores criados pela classe.|
|[IsAutoAccessor](#isauto)|Testa se o acessador especificado é um autoacesso.|
|[ReleaseAccessors](#release)|Libera os acessadores.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="caccessorbaseclose"></a><a name="close"></a>CAccessorBase:: fechar

Fecha os acessadores.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

Você deve chamar [ReleaseAccessors](../../data/oledb/caccessorbase-releaseaccessors.md) primeiro.

## <a name="caccessorbasegethaccessor"></a><a name="geth"></a>CAccessorBase::GetHAccessor

Recupera o identificador de acessador de um acessador especificado.

### <a name="syntax"></a>Sintaxe

```cpp
HACCESSOR GetHAccessor(ULONG nAccessor) const;
```

#### <a name="parameters"></a>parâmetros

*nAccessor*<br/>
no O número de deslocamento zero para o acessador.

### <a name="return-value"></a>Valor retornado

O identificador do acessador.

## <a name="caccessorbasegetnumaccessors"></a><a name="getnum"></a>CAccessorBase::GetNumAccessors

Recupera o número de acessadores criados pela classe.

### <a name="syntax"></a>Sintaxe

```cpp
ULONG GetNumAccessors() const;
```

### <a name="return-value"></a>Valor retornado

O número de acessadores criados pela classe.

## <a name="caccessorbaseisautoaccessor"></a><a name="isauto"></a>CAccessorBase::IsAutoAccessor

Retornará true se os dados forem recuperados automaticamente para o acessador durante uma operação de movimentação.

### <a name="syntax"></a>Sintaxe

```cpp
bool IsAutoAccessor(ULONG nAccessor) const;
```

#### <a name="parameters"></a>parâmetros

*nAccessor*<br/>
no O número de deslocamento zero para o acessador.

### <a name="return-value"></a>Valor retornado

Retornará **true** se o acessador for um autoaccesser. Caso contrário, retornará **false**.

## <a name="caccessorbasereleaseaccessors"></a><a name="release"></a>CAccessorBase::ReleaseAccessors

Libera os acessadores criados pela classe.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT ReleaseAccessors(IUnknown* pUnk);
```

#### <a name="parameters"></a>parâmetros

*pUnk*<br/>
no Um ponteiro para uma interface `IUnknown` para o objeto COM para o qual os acessadores foram criados.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Chamado de [CAccessorRowset:: Close](../../data/oledb/caccessorrowset-close.md).

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessorBase](../../data/oledb/caccessorbase-class.md)
