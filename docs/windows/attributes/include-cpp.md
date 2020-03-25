---
title: include (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.include
helpviewer_keywords:
- include attribute
ms.assetid: d23f8b91-fe5b-48fa-9371-8bd73af7b8e3
ms.openlocfilehash: 39f991bb036dce1c50a9d2ee800d3fec65af7c55
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166777"
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

O atributo **include** C++ faz com que uma instrução `#include` seja colocada abaixo da instrução `import "docobj.idl"` no arquivo. idl gerado.

O atributo **include** C++ tem a mesma funcionalidade que o atributo MIDL [include](/windows/win32/Midl/include) .

## <a name="example"></a>Exemplo

O código a seguir mostra um exemplo de como usar **include**. Para este exemplo, o arquivo include. h contém apenas uma instrução `#include`.

```cpp
// cpp_attr_ref_include.cpp
// compile with: /LD
[module(name="MyLib")];
[include(cpp_attr_ref_include.h)];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[import](import.md)<br/>
[importidl](importidl.md)<br/>
[includelib](includelib-cpp.md)<br/>
[importlib](importlib.md)
