---
title: incluir (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.include
helpviewer_keywords:
- include attribute
ms.assetid: d23f8b91-fe5b-48fa-9371-8bd73af7b8e3
ms.openlocfilehash: d9c68601bea4cecd92b371dada5fb086aeb7657f
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59033691"
---
# <a name="include-c"></a>include (C++)

Especifica um ou mais arquivos de cabeçalho a serem incluídos no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ include(header_file) ];
```

### <a name="parameters"></a>Parâmetros

*header_file*<br/>
O nome de um arquivo que você deseja que sejam incluído no arquivo. idl gerado.

## <a name="remarks"></a>Comentários

O **incluem** C++ atributo faz com que um `#include` instrução a ser colocado abaixo do `import "docobj.idl"` instrução no arquivo. idl gerado.

O **incluem** atributo C++ tem a mesma funcionalidade que o [incluem](/windows/desktop/Midl/include) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra um exemplo de como usar **incluem**. Neste exemplo, o arquivo include.h contém apenas um `#include` instrução.

```cpp
// cpp_attr_ref_include.cpp
// compile with: /LD
[module(name="MyLib")];
[include(cpp_attr_ref_include.h)];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)<br/>
[import](import.md)<br/>
[importidl](importidl.md)<br/>
[includelib](includelib-cpp.md)<br/>
[importlib](importlib.md)