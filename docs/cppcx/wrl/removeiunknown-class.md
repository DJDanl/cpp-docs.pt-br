---
title: Classe RemoveIUnknown
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::RemoveIUnknown
ms.assetid: 998e711a-7d1a-44c6-a016-e6167aa40863
ms.openlocfilehash: cfcdefbb8d7cd12d2ebf99710f595fdd2fc16f76
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213610"
---
# <a name="removeiunknown-class"></a>Classe RemoveIUnknown

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
struct RemoveIUnknown;

template <typename T>
class RemoveIUnknown : public T;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe.

## <a name="remarks"></a>Comentários

Torna um tipo equivalente a um tipo baseado em `IUnknown`, mas tem funções de membro `QueryInterface`, `AddRef`e `Release` não virtuais.

Por padrão, os métodos COM fornecem os métodos `QueryInterface`virtual, `AddRef`e `Release`. No entanto, `ComPtr` não exige a sobrecarga dos métodos virtuais. `RemoveIUnknown` elimina essa sobrecarga fornecendo métodos privados, não virtuais `QueryInterface`, `AddRef`e `Release`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`ReturnType`|Um sinônimo de um tipo que é equivalente ao parâmetro de modelo *T* , mas tem membros `IUnknown` não virtuais.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`RemoveIUnknown`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
