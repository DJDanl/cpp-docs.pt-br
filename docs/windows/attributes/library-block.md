---
title: library_block (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.library_block
dev_langs:
- C++
helpviewer_keywords:
- library_block attribute
ms.assetid: ae7a7ebe-5e1a-4eda-a058-11bbd058ece8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cf4bcdd9290817bb77eeb20f1a014bd537d15d8b
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790219"
---
# <a name="libraryblock"></a>library_block

Coloca uma construção de dentro do bloco de biblioteca IDL.

## <a name="syntax"></a>Sintaxe

```cpp
[library_block]
```

## <a name="remarks"></a>Comentários

Quando você coloca um constructo de dentro do bloco de biblioteca, você certifique-se de que ele será passado para a biblioteca de tipos, independentemente se ele é referenciado. Por padrão, somente construções modificado pela [coclass](coclass.md), [dispinterface](dispinterface.md), e [idl_module](idl-module.md) atributos são colocados no bloco de biblioteca.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)  