---
title: usesgetlasterror (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.usesgetlasterror
dev_langs:
- C++
helpviewer_keywords:
- usesgetlasterror attribute
ms.assetid: d149e33d-35a7-46cb-9137-ae6883d86122
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bb08e2442e34c4d579e568c68d240accdfdbde59
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50074235"
---
# <a name="usesgetlasterror"></a>usesgetlasterror

Informa ao chamador que se houver um erro ao chamar essa função, em seguida, o chamador pode, em seguida, chamar `GetLastError` para recuperar o código de erro.

## <a name="syntax"></a>Sintaxe

```cpp
[usesgetlasterror]
```

## <a name="remarks"></a>Comentários

O **usesgetlasterror** atributo C++ tem a mesma funcionalidade que o [usesgetlasterror](/windows/desktop/Midl/usesgetlasterror) atributo MIDL.

## <a name="example"></a>Exemplo

Consulte a [idl_module](idl-module.md) exemplo para obter um exemplo de como usar **usesgetlasterror**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**módulo** atributo|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)