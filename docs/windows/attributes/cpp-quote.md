---
title: cpp_quote (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.cpp_quote
helpviewer_keywords:
- cpp_quote attribute
ms.assetid: f75327ff-42bd-498b-9177-7ffa25427e1f
ms.openlocfilehash: 451313b5bd1eb5011f1175de5c3bcfe6fb054299
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214910"
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

Você também pode usar **cpp_quote** e gerar um arquivo. h como parte da compilação MIDL. Por exemplo, se você tiver um C++ arquivo de cabeçalho que C++ usa atributos IDL, mas não puder usar esse arquivo para alguma tarefa, você poderá compilá-lo para criar um arquivo. h gerado por MIDL, que você deve ser capaz de usar.

O atributo **cpp_quote** tem a mesma funcionalidade que o atributo MIDL [cpp_quote](/windows/win32/Midl/cpp-quote) .

## <a name="example"></a>Exemplo

Veja o exemplo de [Dual](dual.md) para um exemplo use como usar **cpp_quote**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)
