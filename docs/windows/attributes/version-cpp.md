---
title: versão (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.version
helpviewer_keywords:
- version attribute
- version information, version attribute
ms.assetid: db6ce5d8-82c2-4329-b1a8-8ca2f67342cb
ms.openlocfilehash: 9a432267632b1f2a716a833a485b182cd93a27e2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514881"
---
# <a name="version-c"></a>version (C++)

Identifica uma versão específica entre várias versões de uma classe.

## <a name="syntax"></a>Sintaxe

```cpp
[ version("version") ]
```

### <a name="parameters"></a>Parâmetros

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

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos de classe](class-attributes.md)