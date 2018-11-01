---
title: versão (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.version
helpviewer_keywords:
- version attribute
- version information, version attribute
ms.assetid: db6ce5d8-82c2-4329-b1a8-8ca2f67342cb
ms.openlocfilehash: 01c4cca846326d237fdacd19187a44e21bd15913
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519308"
---
# <a name="version-c"></a>version (C++)

Identifica uma versão específica entre várias versões de uma classe.

## <a name="syntax"></a>Sintaxe

```cpp
[ version("version") ]
```

### <a name="parameters"></a>Parâmetros

*version*<br/>
O número de versão a `coclass`. Se não for especificado, 1.0 será colocado no arquivo. idl.

## <a name="remarks"></a>Comentários

O **versão** atributo C++ tem a mesma funcionalidade que o [versão](/windows/desktop/Midl/version) atributo MIDL e é passado para o arquivo. idl gerado.

## <a name="example"></a>Exemplo

Consulte a [associável](bindable.md) exemplo para uso do exemplo **versão**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos de classe](class-attributes.md)