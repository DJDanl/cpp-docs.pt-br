---
title: cpp_quote (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.cpp_quote
helpviewer_keywords:
- cpp_quote attribute
ms.assetid: f75327ff-42bd-498b-9177-7ffa25427e1f
ms.openlocfilehash: 27be83d123b5433f79c4c8a702197fc6f9f1a753
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833160"
---
# <a name="cpp_quote"></a>cpp_quote

Emite a cadeia de caracteres especificada, sem os caracteres de aspas, no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ cpp_quote("statement") ];
```

### <a name="parameters"></a>parâmetros

*instrução*<br/>
Uma instrução C.

## <a name="remarks"></a>Comentários

O atributo **cpp_quote** C++ será útil se você quiser colocar uma diretiva de pré-processador em um arquivo. idl.

Você também pode usar **cpp_quote** e gerar um arquivo. h como parte da compilação MIDL. Por exemplo, se você tiver um arquivo de cabeçalho C++ que usa atributos IDL C++, mas não puder usar esse arquivo para alguma tarefa, você poderá compilá-lo para criar um arquivo. h gerado por MIDL, que você deve ser capaz de usar.

O atributo **cpp_quote** tem a mesma funcionalidade que o atributo MIDL [cpp_quote](/windows/win32/Midl/cpp-quote) .

## <a name="example"></a>Exemplo

Veja o exemplo de [Dual](dual.md) para um exemplo use como usar **cpp_quote**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)
