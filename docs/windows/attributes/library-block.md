---
title: library_block (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.library_block
helpviewer_keywords:
- library_block attribute
ms.assetid: ae7a7ebe-5e1a-4eda-a058-11bbd058ece8
ms.openlocfilehash: 405cc1cd5af7dcd689e833764f3da2fdc6d5f703
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214767"
---
# <a name="library_block"></a>library_block

Coloca uma construção dentro do bloco de biblioteca IDL.

## <a name="syntax"></a>Sintaxe

```cpp
[library_block]
```

## <a name="remarks"></a>Comentários

Quando você coloca um constructo dentro do bloco de biblioteca, você garante que ele será passado para a biblioteca de tipos, independentemente de ser referenciado. Por padrão, apenas construções modificadas pelos atributos [coclass](coclass.md), [dispinterface](dispinterface.md)e [idl_module](idl-module.md) são colocadas no bloco de biblioteca.

## <a name="example"></a>Exemplo

No código a seguir, uma interface personalizada é colocada dentro do bloco de biblioteca.

```cpp
// cpp_attr_ref_library_block.cpp
// compile with: /LD
#include <windows.h>
[module(name="MyLib")];
[object, library_block, uuid("9E66A290-4365-11D2-A997-00C04FA37DDB")]
__interface IMyInterface {
   HRESULT f1();
};
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

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)
