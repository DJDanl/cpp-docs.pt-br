---
title: versão (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.version
helpviewer_keywords:
- version attribute
- version information, version attribute
ms.assetid: db6ce5d8-82c2-4329-b1a8-8ca2f67342cb
ms.openlocfilehash: e5fcf80ef753a869b8798d6ab9c8e9f8ecff16fd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165984"
---
# <a name="version-c"></a>version (C++)

Identifica uma versão específica entre várias versões de uma classe.

## <a name="syntax"></a>Sintaxe

```cpp
[ version("version") ]
```

### <a name="parameters"></a>parâmetros

*version*<br/>
O número de versão do `coclass`. Se não for especificado, 1,0 será colocado no arquivo. idl.

## <a name="remarks"></a>Comentários

O atributo **version** C++ tem a mesma funcionalidade que o atributo MIDL da [versão](/windows/win32/Midl/version) e é passado para o arquivo. idl gerado.

## <a name="example"></a>Exemplo

Consulte o exemplo [vinculável](bindable.md) para obter uma amostra de uso da **versão**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
