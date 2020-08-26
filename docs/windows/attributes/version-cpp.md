---
title: versão (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.version
helpviewer_keywords:
- version attribute
- version information, version attribute
ms.assetid: db6ce5d8-82c2-4329-b1a8-8ca2f67342cb
ms.openlocfilehash: 7d21761a556455cec27087896984bdc721841d9d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832939"
---
# <a name="version-c"></a>version (C++)

Identifica uma versão específica entre várias versões de uma classe.

## <a name="syntax"></a>Sintaxe

```cpp
[ version("version") ]
```

### <a name="parameters"></a>parâmetros

*version*<br/>
O número de versão do `coclass` . Se não for especificado, 1,0 será colocado no arquivo. idl.

## <a name="remarks"></a>Comentários

O atributo da **versão** C++ tem a mesma funcionalidade que o atributo MIDL da [versão](/windows/win32/Midl/version) e é passado para o arquivo. idl gerado.

## <a name="example"></a>Exemplo

Consulte o exemplo [vinculável](bindable.md) para obter uma amostra de uso da **versão**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos do compilador](compiler-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
