---
title: HelpFile (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpfile
helpviewer_keywords:
- helpfile attribute
ms.assetid: d75161c1-1363-4019-ae09-e7e3b8a3971e
ms.openlocfilehash: 594ab4d02065e9b4efe1142c5ced9b76642e5481
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50488043"
---
# <a name="helpfile"></a>helpfile

Define o nome do arquivo de ajuda para uma biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpfile("filename") ]
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
O nome do arquivo que contém os tópicos da Ajuda.

## <a name="remarks"></a>Comentários

O **helpfile** atributo C++ tem a mesma funcionalidade que o [helpfile](/windows/desktop/Midl/helpfile) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [módulo](module-cpp.md) para obter um exemplo de como usar **helpfile**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**, **typedef**, **classe**, método, **propriedade**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[helpcontext](helpcontext.md)<br/>
[helpstring](helpstring.md)