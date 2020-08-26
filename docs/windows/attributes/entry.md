---
title: entrada (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.entry
helpviewer_keywords:
- entry attribute
ms.assetid: ba4843e3-d7ad-4b86-9a15-0b4192f0f698
ms.openlocfilehash: 63e5ccebb1d3844af8dd11b4b094abe96e3e257c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845309"
---
# <a name="entry"></a>entry

Especifica uma função ou constante exportada em um módulo identificando o ponto de entrada na DLL.

## <a name="syntax"></a>Sintaxe

```cpp
[ entry(id) ]
```

### <a name="parameters"></a>parâmetros

*id*<br/>
A ID do ponto de entrada.

## <a name="remarks"></a>Comentários

A **entrada** atributo C++ tem a mesma funcionalidade que o atributo MIDL de [entrada](/windows/win32/Midl/entry) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [idl_module](idl-module.md) para obter um exemplo de uso de **entrada**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Atributo `idl_module`|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)
