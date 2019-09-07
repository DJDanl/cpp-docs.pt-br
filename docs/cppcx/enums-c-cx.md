---
title: Enums (C++/CX)
ms.date: 12/30/2016
ms.assetid: 99fbbe28-c1cd-43af-9ead-60f90eba6e68
ms.openlocfilehash: 3bdcff03872dcfe83f0be5752cec4f567fbc6b72
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740218"
---
# <a name="enums-ccx"></a>Enums (C++/CX)

C++O `public enum class` /CX dá suporte à palavra-chave, que é C++ `scoped  enum`análogo a um padrão. Quando você usa um enumerador que é declarado usando a palavra-chave `public enum class` , deve usar o identificador da enumeração para definir o escopo de cada valor de enumeração.

### <a name="remarks"></a>Comentários

Uma `public enum class` que não tem um especificador de acesso, como `public`, é tratada como um [enum com escopo](../cpp/enumerations-cpp.md)C++ padrão.

Uma `public enum class` Declaração `public enum struct` ou pode ter um tipo subjacente de qualquer tipo integral, embora a Windows Runtime em si exija que o tipo seja Int32 ou UInt32 para enum Flags. A sintaxe a seguir descreve as partes de uma `public enum class` ou de `public enum struct`.

Este exemplo mostra como definir uma classe enum pública:

[!code-cpp[cx_enums#01](../cppcx/codesnippet/CPP/cpp/class1.h#01)]

Este exemplo a seguir mostra como consumi-la:

[!code-cpp[cx_enums#02](../cppcx/codesnippet/CPP/cpp/class1.h#02)]

### <a name="examples"></a>Exemplos

Os exemplos a seguir mostram como declarar uma enum,

[!code-cpp[cx_enums#03](../cppcx/codesnippet/CPP/cpp/class1.h#03)]

O próximo exemplo mostra com converter em equivalentes numéricos e executar comparações. Observe que o uso do enumerador `One` tem seu escopo definido pelo identificador de enumeração `Enum1` e o enumerador `First` tem seu escopo definido por `Enum2`.

[!code-cpp[cx_enums#04](../cppcx/codesnippet/CPP/cpp/class1.h#04)]

## <a name="see-also"></a>Consulte também

[Sistema de tipos](../cppcx/type-system-c-cx.md)<br/>
[Referência da linguagem C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
