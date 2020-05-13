---
title: Atributos (C++/CX)
ms.date: 12/30/2016
ms.assetid: 4438e03c-4de3-433d-abcc-31aa863bc0e0
ms.openlocfilehash: b9e645de021e8618d1dc15a7d58dbbe5998e6fbc
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032376"
---
# <a name="attributes-ccx"></a>Atributos (C++/CX)

Um atributo é um tipo especial de classe de ref que pode ser preparado em suportes quadrados para tipos e métodos do Windows Runtime para especificar certos comportamentos na criação de metadados. Vários atributos predefinidos — por exemplo, [Windows:Foundation::Metadata::WebHostHidden](/uwp/api/windows.foundation.metadata.webhosthiddenattribute)— são comumente usados no código C++/CX. Este exemplo mostra como o atributo é aplicado a uma classe:

[!code-cpp[cx_attributes#01](../cppcx/codesnippet/CPP/cx_attributes/class1.h#01)]

## <a name="custom-attributes"></a>Atributos personalizados

Você também pode definir atributos personalizados. Os atributos personalizados devem estar em conformidade com essas regras do Windows Runtime:

- Atributos personalizados podem conter somente campos públicos.

- Os campos de atributo personalizado podem ser inicializados quando o atributo é aplicado a uma classe.

- Um campo pode ser de um destes tipos:

  - int32 (int)

  - uint32 (int não assinado)

  - bool

  - Platform::String^

  - Windows::Foundation::HResult

  - Platform::Type^

  - classe enum pública (inclui enums definidos pelo usuário)

O exemplo a seguir mostra como definir um atributo personalizado e inicializá-lo quando você for usá-lo.

[!code-cpp[cx_attributes#02](../cppcx/codesnippet/CPP/cx_attributes/class1.h#02)]

## <a name="see-also"></a>Confira também

[Type System (C++/CX)](../cppcx/type-system-c-cx.md)<br/>
[Referência da linguagem C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
