---
title: in (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.in
helpviewer_keywords:
- in attribute
ms.assetid: 7b450cc4-4d2e-4910-a195-7487c6b7c373
ms.openlocfilehash: f25f15148621d7092858577825dbdd6caa1ae0be
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166790"
---
# <a name="in-c"></a>in (C++)

Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.

## <a name="syntax"></a>Sintaxe

```cpp
[in]
```

## <a name="remarks"></a>Comentários

O atributo **in** C++ tem a mesma funcionalidade que o [no](/windows/win32/Midl/in) atributo MIDL.

## <a name="example"></a>Exemplo

Consulte [ligável](bindable.md) para obter um exemplo de como usar o **no**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|**retval**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[defaultvalue](defaultvalue.md)<br/>
[id](id.md)<br/>
[out](out-cpp.md)
