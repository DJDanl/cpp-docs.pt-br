---
title: entrada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.entry
dev_langs:
- C++
helpviewer_keywords:
- entry attribute
ms.assetid: ba4843e3-d7ad-4b86-9a15-0b4192f0f698
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a40ad39b089ea68209bfef2997f015c355ca6893
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46414037"
---
# <a name="entry"></a>entry

Especifica uma constante ou uma função exportada em um módulo, identificando o ponto de entrada na DLL.

## <a name="syntax"></a>Sintaxe

```cpp
[ entry(
   id
) ]
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
A ID do ponto de entrada.

## <a name="remarks"></a>Comentários

O **entrada** atributo C++ tem a mesma funcionalidade que o [entrada](/windows/desktop/Midl/entry) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [idl_module](../windows/idl-module.md) para um exemplo de uso de **entrada**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Atributo `idl_module`|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  