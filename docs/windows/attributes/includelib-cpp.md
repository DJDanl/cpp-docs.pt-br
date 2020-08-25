---
title: includelib (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.includelib
helpviewer_keywords:
- includelib attribute
ms.assetid: cd90ea6e-5ae8-4f11-b8d1-662db95412b2
ms.openlocfilehash: 30e84a6c82ec25e07ca0eb08f64c7aa5b560e9e7
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830690"
---
# <a name="includelib-c"></a>includelib (C++)

Faz com que um arquivo. IDL ou. h seja incluído no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ includelib(name.idl) ];
```

### <a name="parameters"></a>parâmetros

*nome. idl*<br/>
O nome do arquivo. idl que você deseja incluir como parte do arquivo. idl gerado.

## <a name="remarks"></a>Comentários

O atributo **includelib** C++ faz com que um arquivo. IDL ou. h seja incluído no arquivo. idl gerado, após a `importlib` instrução.

## <a name="example"></a>Exemplo

O código a seguir é mostrado em um arquivo. cpp:

```cpp
// cpp_attr_ref_includelib.cpp
// compile with: /LD
[module(name="MyLib")];
[includelib("includelib.idl")];
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Qualquer lugar|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)<br/>
[import](import.md)<br/>
[importidl](importidl.md)<br/>
[incluir](include-cpp.md)<br/>
[importlib](importlib.md)
