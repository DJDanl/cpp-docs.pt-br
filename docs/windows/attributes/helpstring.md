---
title: HelpString (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.helpstring
dev_langs:
- C++
helpviewer_keywords:
- helpstring attribute [C++]
ms.assetid: 0401e905-a63e-4fad-98d0-d1efea111966
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8cca35d151d0f28c7273c84643662b442afbd3a3
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50056978"
---
# <a name="helpstring"></a>helpstring

Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstring("string") ]
```

### <a name="parameters"></a>Parâmetros

*string*<br/>
O texto da cadeia de caracteres de Ajuda.

## <a name="remarks"></a>Comentários

O **helpstring** atributo C++ tem a mesma funcionalidade que o [helpstring](/windows/desktop/Midl/helpstring) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [defaultvalue](defaultvalue.md) para obter um exemplo de como usar **helpstring**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**, **typedef**, **classe**, método, propriedade|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[helpfile](helpfile.md)<br/>
[helpcontext](helpcontext.md)