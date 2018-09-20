---
title: HelpContext | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.helpcontext
dev_langs:
- C++
helpviewer_keywords:
- helpcontext attribute
ms.assetid: 6fbb022d-a4b7-4989-a02f-7f18a9b0ad96
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d9c2efecf34e5d58f633bc21e62801157b1b8955
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46388583"
---
# <a name="helpcontext"></a>helpcontext

Especifica uma ID de contexto que permite que usuários exibir informações sobre este elemento na **ajudar** arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpcontext(
   id
) ]
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
A ID de contexto do tópico da Ajuda. Ver [Ajuda em HTML: sensível ao contexto de ajuda para seus programas](../mfc/html-help-context-sensitive-help-for-your-programs.md) para obter mais informações sobre IDs de contexto.

## <a name="remarks"></a>Comentários

O **helpcontext** atributo C++ tem a mesma funcionalidade que o [helpcontext](/windows/desktop/Midl/helpcontext) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [defaultvalue](../windows/defaultvalue.md) para obter um exemplo de como usar **helpcontext**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**, **typedef**, **classe**, método, propriedade|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos de interface](../windows/interface-attributes.md)<br/>
[Atributos de classe](../windows/class-attributes.md)<br/>
[Atributos de método](../windows/method-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)<br/>
[helpfile](../windows/helpfile.md)<br/>
[helpstring](../windows/helpstring.md)  