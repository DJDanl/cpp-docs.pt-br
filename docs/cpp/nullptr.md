---
title: nullptr
ms.date: 11/04/2016
f1_keywords:
- nullptr_cpp
helpviewer_keywords:
- nullptr keyword [C++]
ms.assetid: e9d80ea6-2506-4eb5-b47b-2349df085832
ms.openlocfilehash: 57be8d71f1dac4f347ea6567c02a385719bb7306
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58781075"
---
# <a name="nullptr"></a>nullptr

Designa uma constante do ponteiro nulo do tipo `std::nullptr_t`, que é convertido em qualquer tipo bruto de ponteiro.  Embora você possa usar a palavra-chave **nullptr** sem incluir nenhum cabeçalho, se seu código usa o tipo `std::nullptr_t`, em seguida, você deve defini-lo, incluindo o cabeçalho `<cstddef>`.

> [!NOTE]
>  O **nullptr** palavra-chave também é definido em C++/CLI para aplicativos de código gerenciado e não é intercambiável com o padrão ISO C++ palavra-chave. Se seu código pode ser compilado usando o [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador, que se destina ao código gerenciado, em seguida, use `__nullptr` em qualquer linha de código em que você deve garantir que o compilador usará a interpretação do C++ nativo. Para obter mais informações, consulte [nullptr](../extensions/nullptr-cpp-component-extensions.md).

## <a name="remarks"></a>Comentários

Evite usar valor nulo ou zero (`0`) como uma constante de ponteiro nulo; **nullptr** é menos vulnerável ao uso indevido e funciona melhor na maioria das situações.  Por exemplo, com `func(std::pair<const char *, double>)`, chamar `func(std::make_pair(NULL, 3.14))` causa um erro do compilador.  A macro NULL expande para `0`, para que a chamada `std::make_pair(0, 3.14)` retorne `std::pair<int, double>`, que não é conversível para o tipo de parâmetro `std::pair<const char *, double>` de func().  Chamar `func(std::make_pair(nullptr, 3.14))` resulta em uma compilação bem-sucedida porque `std::make_pair(nullptr, 3.14)` retorna `std::pair<std::nullptr_t, double>`, que é convertido em `std::pair<const char *, double>`.

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[nullptr](../extensions/nullptr-cpp-component-extensions.md)(C++/CLI)