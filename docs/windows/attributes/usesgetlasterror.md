---
title: usesgetlasterror (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.usesgetlasterror
helpviewer_keywords:
- usesgetlasterror attribute
ms.assetid: d149e33d-35a7-46cb-9137-ae6883d86122
ms.openlocfilehash: b14316bd929f4b41b13a76c41e94b31b7534e9d8
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513883"
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

Consulte o exemplo de [idl_module](idl-module.md) para obter um exemplo de como usar o **usesgetlasterror**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|atributo de **módulo**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)