---
title: incluir (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.include
dev_langs:
- C++
helpviewer_keywords:
- include attribute
ms.assetid: d23f8b91-fe5b-48fa-9371-8bd73af7b8e3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 14a58573af8b8cb917d7aaaa864b6b4d61e70172
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50062997"
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

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[import](import.md)<br/>
[importidl](importidl.md)<br/>
[includelib](includelib-cpp.md)<br/>
[importlib](importlib.md)