---
title: nullptr
ms.date: 11/04/2016
f1_keywords:
- nullptr_cpp
helpviewer_keywords:
- nullptr keyword [C++]
ms.assetid: e9d80ea6-2506-4eb5-b47b-2349df085832
ms.openlocfilehash: 51df20ea00e5dd77ab1fc1a2a01253b8f788ad0a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358850"
---
# <a name="nullptr"></a>nullptr

Designa uma constante do ponteiro nulo do tipo `std::nullptr_t`, que é convertido em qualquer tipo bruto de ponteiro.  Embora você possa usar o **nulo** de palavras-chave sem `std::nullptr_t`incluir quaisquer cabeçalhos, `<cstddef>`se o seu código usa o tipo, então você deve defini-lo incluindo o cabeçalho .

> [!NOTE]
> A **palavra-chave nullptr** também é definida em C++/CLI para aplicativos de código gerenciados e não é intercambiável com a palavra-chave ISO Standard C++. Se o seu código pode ser compilado usando a opção [/clr](../build/reference/clr-common-language-runtime-compilation.md) compilr, que tem como alvo o código gerenciado, use `__nullptr` em qualquer linha de código onde você deve garantir que o compilador use a interpretação C++ nativa. Para obter mais informações, consulte [nullptr](../extensions/nullptr-cpp-component-extensions.md).

## <a name="remarks"></a>Comentários

Evite usar NULL`0`ou zero () como uma constante de ponteiro nulo; **nullptr** é menos vulnerável ao uso indevido e funciona melhor na maioria das situações.  Por exemplo, com `func(std::pair<const char *, double>)`, chamar `func(std::make_pair(NULL, 3.14))` causa um erro do compilador.  A macro NULL expande para `0`, para que a chamada `std::make_pair(0, 3.14)` retorne `std::pair<int, double>`, que não é conversível para o tipo de parâmetro `std::pair<const char *, double>` de func().  Chamar `func(std::make_pair(nullptr, 3.14))` resulta em uma compilação bem-sucedida porque `std::make_pair(nullptr, 3.14)` retorna `std::pair<std::nullptr_t, double>`, que é convertido em `std::pair<const char *, double>`.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[nulo](../extensions/nullptr-cpp-component-extensions.md)(C++/CLI)
