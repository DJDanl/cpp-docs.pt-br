---
title: ArquivoDeAjuda (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpfile
helpviewer_keywords:
- helpfile attribute
ms.assetid: d75161c1-1363-4019-ae09-e7e3b8a3971e
ms.openlocfilehash: 641823779346bf5417ec0db26b83083fa949e960
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222115"
---
# <a name="helpfile"></a>helpfile

Define o nome do arquivo de ajuda para uma biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpfile("filename") ]
```

### <a name="parameters"></a>parâmetros

*nome do arquivo*<br/>
O nome do arquivo que contém os tópicos da ajuda.

## <a name="remarks"></a>Comentários

O atributo **HelpFile** C++ tem a mesma funcionalidade que o atributo MIDL de [HelpFile](/windows/win32/Midl/helpfile) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [módulo](module-cpp.md) para obter um exemplo de como usar o **HelpFile**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**, **`typedef`** , **`class`** , método,**`property`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[helpcontext](helpcontext.md)<br/>
[helpstring](helpstring.md)
