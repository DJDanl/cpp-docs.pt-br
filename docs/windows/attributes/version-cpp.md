---
title: versão (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.version
helpviewer_keywords:
- version attribute
- version information, version attribute
ms.assetid: db6ce5d8-82c2-4329-b1a8-8ca2f67342cb
ms.openlocfilehash: fe1df9e12b9adbf9ce55978fd3479f7e740ddc96
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59025746"
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
|**Aplica-se a**|**class**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos de classe](class-attributes.md)