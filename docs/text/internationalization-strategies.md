---
title: Estratégias de internacionalização
ms.date: 11/04/2016
helpviewer_keywords:
- globalization [C++], character sets
- language-portable code [C++]
- MBCS [C++], internationalization strategies
- Windows API [C++], international programming strategies
- Win32 [C++], international programming strategies
- Unicode [C++], globalizing applications
- character sets [C++], international programming strategies
- localization [C++], character sets
ms.assetid: b09d9854-0709-4b9a-a00c-b0b8bc4199b1
ms.openlocfilehash: 615ad42d5a1e4cb6076877e1d1b5de4bd11fdf83
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501316"
---
# <a name="internationalization-strategies"></a>Estratégias de internacionalização

Dependendo de seus sistemas operacionais de destino e os mercados, você tem várias estratégias de internacionalização:

- Seu aplicativo usa o Unicode.

   Você usa funcionalidade específica do Unicode e todos os caracteres são 16 bits de largura (embora você pode usar caracteres ANSI em algumas partes do seu programa para fins especiais). A biblioteca de tempo de execução C fornece os tipos de funções, macros e dados para programação somente Unicode. O MFC é totalmente habilitado para Unicode.

- Seu aplicativo usa MBCS e pode ser executado em qualquer plataforma de Win32.

   Você usar a funcionalidade específica do MBCS. Cadeias de caracteres podem conter caracteres de byte único, os caracteres de byte duplo ou ambos. A biblioteca de tempo de execução C fornece os tipos de funções, macros e dados para programação de MBCS. O MFC é totalmente habilitado MBCS.

- O código-fonte para o seu aplicativo é escrito para portabilidade completa — por meio da recompilação com o símbolo `_UNICODE` ou o símbolo `_MBCS` definido, você pode produzir as versões que usam qualquer um. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).

   Use o totalmente portáteis C Runtime funções, macros e tipos de dados. Flexibilidade do MFC dá suporte a qualquer uma dessas estratégias.

O restante desses tópicos se concentrar em escrever código totalmente portáteis que podem ser compilados como Unicode ou MBCS.

## <a name="see-also"></a>Consulte também

[Unicode e MBCS](../text/unicode-and-mbcs.md)<br/>
[Localidades e páginas de código](../text/locales-and-code-pages.md)