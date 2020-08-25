---
title: usesgetlasterror (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.usesgetlasterror
helpviewer_keywords:
- usesgetlasterror attribute
ms.assetid: d149e33d-35a7-46cb-9137-ae6883d86122
ms.openlocfilehash: e3d3c292554350d85296971a9bd3620909ef47c7
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831626"
---
# <a name="usesgetlasterror"></a>usesgetlasterror

Informa ao chamador que, se houver um erro ao chamar essa função, o chamador poderá então chamar `GetLastError` para recuperar o código de erro.

## <a name="syntax"></a>Sintaxe

```cpp
[usesgetlasterror]
```

## <a name="remarks"></a>Comentários

O atributo **usesgetlasterror** C++ tem a mesma funcionalidade que o atributo MIDL [usesgetlasterror](/windows/win32/Midl/usesgetlasterror) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [idl_module](idl-module.md) para obter um exemplo de como usar **usesgetlasterror**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|atributo de **módulo**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)
