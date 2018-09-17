---
title: no_injected_text | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 055b14c38e3084a7368953cbce4f95373e1a77f3
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45706290"
---
# <a name="noinjectedtext"></a>no_injected_text

Impede que o compilador injetando código como resultado do uso do atributo.

## <a name="syntax"></a>Sintaxe

```cpp
[ no_injected_text(
   boolean
) ];
```

### <a name="parameters"></a>Parâmetros

*valor booliano*  
(Opcional) **verdadeira** se você não quiser que nenhum código injetado, **falso** para permitir que o código injetado. **True** é o padrão.

## <a name="remarks"></a>Comentários

O uso mais comum do **no_injected_text** atributo C++ é a [/Fx](../build/reference/fx-merge-injected-code.md) opção de compilador, que insere os **no_injected_text** atributo no arquivo. mrg.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](../windows/compiler-attributes.md)  