---
title: includelib (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.includelib
helpviewer_keywords:
- includelib attribute
ms.assetid: cd90ea6e-5ae8-4f11-b8d1-662db95412b2
ms.openlocfilehash: 4022a3f1f2d4ccaabe65c24065be8e1c846d604d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214832"
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

O atributo **includelib** C++ faz com que um arquivo. IDL ou. h seja incluído no arquivo. idl gerado, após a instrução de `importlib`.

## <a name="example"></a>Exemplo

O código a seguir é mostrado em um arquivo. cpp:

```cpp
// cpp_attr_ref_includelib.cpp
// compile with: /LD
[module(name="MyLib")];
[includelib("includelib.idl")];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Sim|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[import](import.md)<br/>
[importidl](importidl.md)<br/>
[include](include-cpp.md)<br/>
[importlib](importlib.md)
