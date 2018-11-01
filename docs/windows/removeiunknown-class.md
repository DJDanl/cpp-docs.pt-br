---
title: Classe RemoveIUnknown
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::RemoveIUnknown
ms.assetid: 998e711a-7d1a-44c6-a016-e6167aa40863
ms.openlocfilehash: 06b3ec86874bcf7968483eb4557b6b6b247ecdfe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50556345"
---
# <a name="removeiunknown-class"></a>Classe RemoveIUnknown

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
struct RemoveIUnknown;

template <typename T>
class RemoveIUnknown : public T;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe.

## <a name="remarks"></a>Comentários

Cria um tipo que é equivalente a um `IUnknown`-tipo com base, mas tem não virtuais `QueryInterface`, `AddRef`, e `Release` funções de membro.

Por padrão, os métodos fornecem virtual `QueryInterface`, `AddRef`, e `Release` métodos. No entanto, `ComPtr` não requer a sobrecarga de métodos virtuais. `RemoveIUnknown` elimina essa sobrecarga, fornecendo privado e não virtuais `QueryInterface`, `AddRef`, e `Release` métodos.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`ReturnType`|Um sinônimo para um tipo que é equivalente ao parâmetro de modelo *T* , mas tem não virtuais `IUnknown` membros.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`RemoveIUnknown`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)