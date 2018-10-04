---
title: no_injected_text (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.no_injected_text
dev_langs:
- C++
helpviewer_keywords:
- no_injected_text attribute
ms.assetid: 5256f808-e41e-4f4a-9ea5-e447919f5696
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a9289c1b8f28b90dd5a3a4a437d3e2a5870e8468
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790239"
---
# <a name="noinjectedtext"></a>no_injected_text

Impede que o compilador injetando código como resultado do uso do atributo.

## <a name="syntax"></a>Sintaxe

```cpp
[ no_injected_text(boolean) ];
```

### <a name="parameters"></a>Parâmetros

*valor booliano*<br/>
(Opcional) **verdadeira** se você não quiser que nenhum código injetado, **falso** para permitir que o código injetado. **True** é o padrão.

## <a name="remarks"></a>Comentários

O uso mais comum do **no_injected_text** atributo C++ é a [/Fx](../../build/reference/fx-merge-injected-code.md) opção de compilador, que insere os **no_injected_text** atributo no arquivo. mrg.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)  