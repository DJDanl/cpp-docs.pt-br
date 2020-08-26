---
title: include (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.include
helpviewer_keywords:
- include attribute
ms.assetid: d23f8b91-fe5b-48fa-9371-8bd73af7b8e3
ms.openlocfilehash: 6b75df74ee69ee4f89eb7bf18fb6bcd77d8a6284
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842189"
---
# <a name="include-c"></a>include (C++)

Especifica um ou mais arquivos de cabeçalho a serem incluídos no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ include(header_file) ];
```

### <a name="parameters"></a>parâmetros

*header_file*<br/>
O nome de um arquivo que você deseja incluir no arquivo. idl gerado.

## <a name="remarks"></a>Comentários

O atributo **include** C++ faz com que uma `#include` instrução seja colocada abaixo da `import "docobj.idl"` instrução no arquivo. idl gerado.

O atributo **include** C++ tem a mesma funcionalidade que o atributo MIDL [include](/windows/win32/Midl/include) .

## <a name="example"></a>Exemplo

O código a seguir mostra um exemplo de como usar **include**. Para este exemplo, o arquivo include. h contém apenas uma `#include` instrução.

```cpp
// cpp_attr_ref_include.cpp
// compile with: /LD
[module(name="MyLib")];
[include(cpp_attr_ref_include.h)];
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)<br/>
[import](import.md)<br/>
[importidl](importidl.md)<br/>
[includelib](includelib-cpp.md)<br/>
[importlib](importlib.md)
