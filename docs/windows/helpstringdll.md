---
title: helpstringdll | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.helpstringdll
dev_langs:
- C++
helpviewer_keywords:
- helpstringdll attribute [C++]
ms.assetid: 121271fa-f061-492b-b87f-bbfcf4b02e7b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1eecedca8988c95466a3f257fbc77768b7c67b3b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392860"
---
# <a name="helpstringdll"></a>helpstringdll

Especifica o nome da DLL a usar para executar a pesquisa de cadeia de caracteres do documento (localização).

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstringdll(
   "string"
) ]
```

### <a name="parameters"></a>Parâmetros

*string*<br/>
A DLL de usar para executar a pesquisa de cadeia de caracteres do documento.

## <a name="remarks"></a>Comentários

O **helpstringdll** atributo C++ tem a mesma funcionalidade que o [helpstringdll](/windows/desktop/Midl/helpstringdll) atributo MIDL.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_helpstringdll.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib", helpstringdll="xx.dll")];

[object, uuid("00000000-0000-0000-0000-000000000001")]
__interface IMyI
{
   HRESULT xxx();
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **interface**, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos de interface](../windows/interface-attributes.md)<br/>
[Atributos de classe](../windows/class-attributes.md)<br/>
[Atributos de método](../windows/method-attributes.md)  