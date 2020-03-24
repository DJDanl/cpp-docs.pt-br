---
title: nullptr
ms.date: 11/04/2016
f1_keywords:
- nullptr_cpp
helpviewer_keywords:
- nullptr keyword [C++]
ms.assetid: e9d80ea6-2506-4eb5-b47b-2349df085832
ms.openlocfilehash: 223f4c3e8c838698f9716e241543db405c9394af
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177762"
---
# <a name="nullptr"></a>nullptr

Designa uma constante do ponteiro nulo do tipo `std::nullptr_t`, que é convertido em qualquer tipo bruto de ponteiro.  Embora você possa usar a palavra-chave **nullptr** sem incluir nenhum cabeçalho, se o seu código usar o tipo `std::nullptr_t`, você deverá defini-lo incluindo o cabeçalho `<cstddef>`.

> [!NOTE]
>  A palavra-chave **nullptr** também é C++definida em/CLI para aplicativos de código gerenciado e não é intercambiável com a C++ palavra-chave ISO Standard. Se o código puder ser compilado usando a opção de compilador [/CLR](../build/reference/clr-common-language-runtime-compilation.md) , que tem como alvo o código gerenciado, use `__nullptr` em qualquer linha de código onde você deve garantir que o compilador use C++ a interpretação nativa. Para obter mais informações, consulte [nullptr](../extensions/nullptr-cpp-component-extensions.md).

## <a name="remarks"></a>Comentários

Evite usar NULL ou zero (`0`) como uma constante de ponteiro nulo; o **nullptr** é menos vulnerável ao uso indevido e funciona melhor na maioria das situações.  Por exemplo, com `func(std::pair<const char *, double>)`, chamar `func(std::make_pair(NULL, 3.14))` causa um erro do compilador.  A macro NULL expande para `0`, para que a chamada `std::make_pair(0, 3.14)` retorne `std::pair<int, double>`, que não é conversível para o tipo de parâmetro `std::pair<const char *, double>` de func().  Chamar `func(std::make_pair(nullptr, 3.14))` resulta em uma compilação bem-sucedida porque `std::make_pair(nullptr, 3.14)` retorna `std::pair<std::nullptr_t, double>`, que é convertido em `std::pair<const char *, double>`.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[nullptr](../extensions/nullptr-cpp-component-extensions.md)(C++/CLI)
