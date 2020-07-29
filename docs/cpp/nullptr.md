---
title: nullptr
ms.date: 07/22/2020
f1_keywords:
- nullptr_cpp
helpviewer_keywords:
- nullptr keyword [C++]
ms.assetid: e9d80ea6-2506-4eb5-b47b-2349df085832
ms.openlocfilehash: 801ae927d6c9fb70c3187d10269e87097a879bfc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223623"
---
# <a name="nullptr"></a>nullptr

A **`nullptr`** palavra-chave especifica uma constante de ponteiro NULL do tipo `std::nullptr_t` , que é conversível para qualquer tipo de ponteiro bruto.  Embora você possa usar a palavra-chave **`nullptr`** sem incluir nenhum cabeçalho, se o seu código usar o tipo `std::nullptr_t` , você deverá defini-lo incluindo o cabeçalho `<cstddef>` .

> [!NOTE]
> A **`nullptr`** palavra-chave também é definida em C++/CLI para aplicativos de código gerenciado e não é intercambiável com a palavra-chave ISO Standard C++. Se o código puder ser compilado usando a [`/clr`](../build/reference/clr-common-language-runtime-compilation.md) opção do compilador, que tem como alvo o código gerenciado, use `__nullptr` em qualquer linha de código em que você deve garantir que o compilador use a interpretação C++ nativa. Para obter mais informações, consulte [ `nullptr` (c++/CLI e C++/CX)](../extensions/nullptr-cpp-component-extensions.md).

## <a name="remarks"></a>Comentários

Evite usar `NULL` ou zero ( `0` ) como uma constante de ponteiro NULL; **`nullptr`** é menos vulnerável ao uso indevido e funciona melhor na maioria das situações.  Por exemplo, com `func(std::pair<const char *, double>)`, chamar `func(std::make_pair(NULL, 3.14))` causa um erro do compilador.  A macro se `NULL` expande para `0` , de forma que a chamada `std::make_pair(0, 3.14)` retorne `std::pair<int, double>` , que não é conversível para o `std::pair<const char *, double>` tipo de parâmetro no `func` .  Chamar `func(std::make_pair(nullptr, 3.14))` resulta em uma compilação bem-sucedida porque `std::make_pair(nullptr, 3.14)` retorna `std::pair<std::nullptr_t, double>`, que é convertido em `std::pair<const char *, double>`.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[`nullptr`(C++/CLI e C++/CX)](../extensions/nullptr-cpp-component-extensions.md)
