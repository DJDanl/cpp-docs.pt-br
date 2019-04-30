---
title: entrada (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.entry
helpviewer_keywords:
- entry attribute
ms.assetid: ba4843e3-d7ad-4b86-9a15-0b4192f0f698
ms.openlocfilehash: 703a55ee7c56b64a5b168016770508508bab09e0
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346124"
---
# <a name="entry"></a>entry

Especifica uma constante ou uma função exportada em um módulo, identificando o ponto de entrada na DLL.

## <a name="syntax"></a>Sintaxe

```cpp
[ entry(id) ]
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
A ID do ponto de entrada.

## <a name="remarks"></a>Comentários

O **entrada** atributo C++ tem a mesma funcionalidade que o [entrada](/windows/desktop/Midl/entry) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [idl_module](idl-module.md) para um exemplo de uso de **entrada**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|`idl_module` Atributo|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)