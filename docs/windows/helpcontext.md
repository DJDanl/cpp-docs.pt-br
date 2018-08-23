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
ms.openlocfilehash: 8d782246f44148805f9acc8d912b0fbf554227f7
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42595722"
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

*id*  
A ID de contexto do tópico da Ajuda. Ver [Ajuda em HTML: sensível ao contexto de ajuda para seus programas](../mfc/html-help-context-sensitive-help-for-your-programs.md) para obter mais informações sobre IDs de contexto.

## <a name="remarks"></a>Comentários

O **helpcontext** atributo C++ tem a mesma funcionalidade que o [helpcontext](http://msdn.microsoft.com/library/windows/desktop/aa366851) atributo MIDL.

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

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de interface](../windows/interface-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  
[helpfile](../windows/helpfile.md)  
[helpstring](../windows/helpstring.md)  