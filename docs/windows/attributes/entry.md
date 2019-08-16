---
title: entrada (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.entry
helpviewer_keywords:
- entry attribute
ms.assetid: ba4843e3-d7ad-4b86-9a15-0b4192f0f698
ms.openlocfilehash: 71abf4f183255fa137b43ac9cabd88d15c3fc85d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69490898"
---
# <a name="entry"></a>entry

Especifica uma função ou constante exportada em um módulo identificando o ponto de entrada na DLL.

## <a name="syntax"></a>Sintaxe

```cpp
[ entry(id) ]
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
A ID do ponto de entrada.

## <a name="remarks"></a>Comentários

O atributo de **entrada** C++ tem a mesma funcionalidade que o atributo MIDL de [entrada](/windows/win32/Midl/entry) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [idl_module](idl-module.md) para obter um exemplo de uso de **entrada**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|`idl_module`Attribute|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)