---
title: Classe Platform::ValueType
ms.date: 02/03/2017
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::ValueType::ToString
helpviewer_keywords:
- Platform::ValueType Class
ms.assetid: 79aa8754-b140-4974-a5b1-be046938a10a
ms.openlocfilehash: 889cf3a53468491517d37978ca09472756ad9b7e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62182945"
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

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Plataforma

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

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
