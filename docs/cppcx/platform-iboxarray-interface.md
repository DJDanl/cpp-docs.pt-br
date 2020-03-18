---
title: Interface Platform::IBoxArray
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::IBoxArray
- VCCORLIB/Platform::IBoxArray::Value
helpviewer_keywords:
- Platform::IBoxArray
ms.assetid: 6cd82c9e-4230-4147-9edb-7a652875dbf1
ms.openlocfilehash: 493770cab092c2bb719d47e5d3a9d6a9f0646489
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444162"
---
# <a name="platformiboxarray-interface"></a>Interface Platform::IBoxArray

`IBoxArray` é o wrapper para arrays de tipos de valores que são transmitidos pela interface binária de aplicativo (ABI) ou armazenados em coleções de elementos `Platform::Object^` como aqueles em controles XAML.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
interface class IBoxArray
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do valor demarcado em cada elemento da matriz.

### <a name="remarks"></a>Comentários

`IBoxArray` é o C++nome de/cx para `Windows::Foundation::IReferenceArray`.

### <a name="members"></a>Membros

A interface `IBoxArray` herda da interface `IValueType` . `IBoxArray` também tem estes membros:

|Método|Descrição|
|------------|-----------------|
|[Valor](#value)|Retorna a matriz não demarcada que foi armazenadas anteriormente nessa instância de `IBoxArray` .|

## <a name="value"></a>Propriedade IBoxArray:: Value

Retorna o valor que foi originalmente armazenado neste objeto.

### <a name="syntax"></a>Sintaxe

```cpp
property T Value {T get();}
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo do valor demarcado.

### <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno

Retorna o valor que foi originalmente armazenado neste objeto.

### <a name="remarks"></a>Comentários

Para obter um exemplo, consulte [Boxing](../cppcx/boxing-c-cx.md).

## <a name="see-also"></a>Consulte também

[Matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md)
