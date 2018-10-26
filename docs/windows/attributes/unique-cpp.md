---
title: (C++ COM atributo exclusivo) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.unique
dev_langs:
- C++
helpviewer_keywords:
- unique attribute
ms.assetid: abd7ed14-5ae7-44a8-8333-0058e9c92b2f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ca5d2da5dc06b1cdf0e999939fcb110608ff3359
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50062673"
---
# <a name="unique-c"></a>unique (C++)

Especifica um ponteiro exclusivo.

## <a name="syntax"></a>Sintaxe

```cpp
[unique]
```

## <a name="remarks"></a>Comentários

O **exclusivos** atributo C++ tem a mesma funcionalidade que o [exclusivo](/windows/desktop/Midl/unique) atributo MIDL.

## <a name="example"></a>Exemplo

Consulte a [ref](ref-cpp.md) exemplo para uso do exemplo **exclusivo**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**TypeDef**, **struct**, **união**, a interface do parâmetro, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)