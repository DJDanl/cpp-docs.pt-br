---
title: Classe Platform::ValueType
ms.date: 02/03/2017
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::ValueType::ToString
helpviewer_keywords:
- Platform::ValueType Class
ms.assetid: 79aa8754-b140-4974-a5b1-be046938a10a
ms.openlocfilehash: 57fb089f0d9dc53ba8a65cef41e3341168ffea45
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596398"
---
# <a name="platformvaluetype-class"></a>Classe Platform::ValueType

A classe base para instâncias de tipos de valor.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class ValueType : Object
```

## <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|[ValueType::ToString](#tostring)|Retorna uma representação de cadeia de caracteres do objeto. Herdado de [Platform:: Object](../cppcx/platform-object-class.md).|

### <a name="remarks"></a>Comentários

A classe ValueType é usada para construir os tipos de valor. ValueType é derivado de Object, que tem membros básicos. No entanto, o compilador desanexa os membros básicos dos tipos de valor que são derivados da classe ValueType. O compilador anexa novamente esses membros básicos quando um tipo de valor é convertido.

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="tostring"></a> Método ValueType:: ToString

Retorna uma representação de cadeia de caracteres do objeto.

### <a name="syntax"></a>Sintaxe

```cpp
Platform::String ToString();
```

### <a name="return-value"></a>Valor de retorno

Um Platform:: String que representa o valor.

## <a name="see-also"></a>Consulte também

[Namespace Platform](../cppcx/platform-namespace-c-cx.md)