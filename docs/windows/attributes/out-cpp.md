---
title: out (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.out
dev_langs:
- C++
helpviewer_keywords:
- out attribute
ms.assetid: 5051b1bf-4949-4bf1-b82f-35e14f0f244b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c695dbee2b92a2a3fbc5de0830f298b81e63ad8d
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790078"
---
# <a name="out-c"></a>out (C++)

Identifica os parâmetros de ponteiro que são retornados do procedimento chamado ao procedimento de chamada (do servidor para o cliente).

## <a name="syntax"></a>Sintaxe

```cpp
[out]
```

## <a name="remarks"></a>Comentários

O **horizontalmente** atributo C++ tem a mesma funcionalidade que o [out](/windows/desktop/Midl/out-idl) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](bindable.md) para uso do exemplo **out**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[defaultvalue](defaultvalue.md)<br/>
[id](id.md)  