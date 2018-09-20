---
title: em (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.in
dev_langs:
- C++
helpviewer_keywords:
- in attribute
ms.assetid: 7b450cc4-4d2e-4910-a195-7487c6b7c373
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cd6b79d84e4737cdbeb670bdd31b8cacf35cf8f1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373381"
---
# <a name="in-c"></a>in (C++)

Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.

## <a name="syntax"></a>Sintaxe

```cpp
[in]
```

## <a name="remarks"></a>Comentários

O **na** atributo C++ tem a mesma funcionalidade que o [em](/windows/desktop/Midl/in) atributo MIDL.

## <a name="example"></a>Exemplo

Ver [associável](../windows/bindable.md) para obter um exemplo de como usar **em**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|**retval**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos de parâmetro](../windows/parameter-attributes.md)<br/>
[Atributos de método](../windows/method-attributes.md)<br/>
[defaultvalue](../windows/defaultvalue.md)<br/>
[id](../windows/id.md)<br/>
[out](../windows/out-cpp.md)  