---
title: 'Interface Platform:: iboxarray | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- VCCORLIB/Namespace not found::Platform
- VCCORLIB/Namespace not found::Platform::Value
dev_langs:
- C++
helpviewer_keywords:
- Platform::IBoxArray
ms.assetid: 6cd82c9e-4230-4147-9edb-7a652875dbf1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 66e3ff5a2daf0ddef41ea478b55ca2fc67298c01
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44108441"
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

`IBoxArray` é o C + + / nome CX para `Windows::Foundation::IReferenceArray`.

### <a name="members"></a>Membros

A interface `IBoxArray` herda da interface `IValueType` . `IBoxArray` também tem estes membros:

|Método|Descrição|
|------------|-----------------|
|[Valor](#value)|Retorna a matriz não demarcada que foi armazenadas anteriormente nessa instância de `IBoxArray` .|

## <a name="value"></a> Propriedade iboxarray:: Value

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

Por exemplo, consulte [conversão Boxing](../cppcx/boxing-c-cx.md).

## <a name="see-also"></a>Consulte também

[Matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md)