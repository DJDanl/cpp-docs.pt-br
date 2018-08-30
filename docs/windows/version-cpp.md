---
title: versão (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.version
dev_langs:
- C++
helpviewer_keywords:
- version attribute
- version information, version attribute
ms.assetid: db6ce5d8-82c2-4329-b1a8-8ca2f67342cb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 87186ee70b5863f51a7cd91f8695052f361bd11c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43222525"
---
# <a name="version-c"></a>version (C++)

Identifica uma versão específica entre várias versões de uma classe.

## <a name="syntax"></a>Sintaxe

```cpp
[ version(
   "version"
) ]
```

### <a name="parameters"></a>Parâmetros

*version*  
O número de versão a `coclass`. Se não for especificado, 1.0 será colocado no arquivo. idl.

## <a name="remarks"></a>Comentários

O **versão** atributo C++ tem a mesma funcionalidade que o [versão](/windows/desktop/Midl/version) atributo MIDL e é passado para o arquivo. idl gerado.

## <a name="example"></a>Exemplo

Consulte a [associável](../windows/bindable.md) exemplo para uso do exemplo **versão**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](../windows/compiler-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  