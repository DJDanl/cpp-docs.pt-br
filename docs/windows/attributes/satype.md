---
title: satype (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.satype
dev_langs:
- C++
helpviewer_keywords:
- satype attribute
ms.assetid: 1716590b-6bcb-4aba-b1bc-82f7335f02c3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 255517789a5854ee6f76c4982bb75825905df546
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790276"
---
# <a name="satype"></a>satype

Especifica o tipo de dados a `SAFEARRAY` estrutura.

## <a name="syntax"></a>Sintaxe

```cpp
[ satype(data_type) ]
```

### <a name="parameters"></a>Parâmetros

*data_type*<br/>
O tipo de dados para o `SAFEARRAY` estrutura de dados que está sendo passada como um parâmetro para um método de interface.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

## <a name="remarks"></a>Comentários

O **satype** atributo C++ Especifica o tipo de dados a `SAFEARRAY`.

> [!NOTE]
> Um nível de indireção é descartado do `SAFEARRAY` ponteiro no arquivo. idl gerado a partir de como ele é declarado no arquivo. cpp.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_satype.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="MyModule")];
[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]
__interface A {
   [id(1)] HRESULT MyMethod ([in, satype("BSTR")] SAFEARRAY **p);
};
```

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[id](id.md)  