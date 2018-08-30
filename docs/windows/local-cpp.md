---
title: local (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.local
dev_langs:
- C++
helpviewer_keywords:
- local attribute
ms.assetid: 35cdd668-bd8e-492a-b7b8-263e7b662437
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b910ce2416dc345e2a36c9858f260ef5b42c2cc8
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43203316"
---
# <a name="local-c"></a>local (C++)

Quando usado no cabeçalho da interface, permite que você use o compilador MIDL como um gerador de cabeçalho. Quando usado em uma função individual, designa um procedimento de local para o qual nenhuma stubs são gerados.

## <a name="syntax"></a>Sintaxe

```cpp
[local]
```

## <a name="remarks"></a>Comentários

O **local** atributo C++ tem a mesma funcionalidade que o [local](/windows/desktop/Midl/local) atributo MIDL.

## <a name="example"></a>Exemplo

Ver [call_as](../windows/call-as.md) para obter um exemplo de como usar **local**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`dispinterface`|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de interface](../windows/interface-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  
[call_as](../windows/call-as.md)  