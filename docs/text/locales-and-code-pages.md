---
title: Localidades e páginas de código
ms.date: 11/04/2016
helpviewer_keywords:
- locales [C++], about locales
- locale IDs [C++]
- locales [C++]
- code pages [C++]
- code pages [C++], dynamically changing
- character sets [C++], code pages
- multibyte code pages [C++]
- character sets [C++], locales
- localization [C++], code pages
- localization [C++], locales
- code pages [C++], locales
- conventions [C++], international character support
ms.assetid: bd937361-b6d3-4c98-af95-beb7c903187b
ms.openlocfilehash: 0015e0a7a81abbd3472a8c845a9b8c0d8caf4618
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50610530"
---
# <a name="locales-and-code-pages"></a>Localidades e páginas de código

Uma identificação de localidade reflete as convenções locais e o idioma para uma determinada região geográfica. Um determinado idioma pode ser falado em mais de um país/região; Por exemplo, português é falado no Brasil, bem como em Portugal. Por outro lado, um país/região pode ter mais de uma linguagem oficial. Por exemplo, no Canadá tem dois idiomas: inglês e francês. Portanto, o Canadá possui duas localidades distintas: canadense inglês e francês (Canadá). Algumas categorias de localidade dependentes incluem a formatação de datas e o formato de exibição de valores monetários.

O idioma determina o texto e formatação convenções, enquanto o país/região determina as convenções locais de dados. Cada linguagem tem um mapeamento exclusivo, representado por páginas de código, que inclui caracteres que não seja o alfabeto (por exemplo, sinais de pontuação e números). Uma página de código é um conjunto de caracteres e está relacionada à linguagem. Como tal, um [localidade](../c-runtime-library/locale.md) é uma combinação exclusiva de idioma, país/região e página de código. A configuração de localidade e o código da página pode ser alterada em tempo de execução chamando o [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) função.

Idiomas diferentes podem usar diferentes páginas de código. Por exemplo, a página de código ANSI 1252 é usada para inglês e a maioria dos idiomas europeus, e a página de código ANSI 932 é usada para japonês Kanji. Praticamente todas as páginas de código compartilham o caractere ASCII definido para os mais baixos 128 caracteres (0x00 a 0x7F).

Qualquer página de código de byte único pode ser representada em uma tabela (com 256 entradas) como um mapeamento de valores de bytes para caracteres (incluindo números e pontuação), ou glifos. Qualquer página de código multibyte também pode ser representada como uma tabela muito grande (com entradas de 64K) dos valores de byte duplo para caracteres. Na prática, no entanto, ele são geralmente representados como uma tabela para os primeiros 256 caracteres (um byte) e como os intervalos para os valores de byte duplo.

Para obter mais informações sobre páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md).

A biblioteca de tempo de execução C tem dois tipos de páginas de código interno: localidade e multibyte. Você pode alterar a página de código atual durante a execução do programa (consulte a documentação para o [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) e [setmbcp](../c-runtime-library/reference/setmbcp.md) funções). Além disso, a biblioteca de tempo de execução pode obter e usar o valor da página de código de sistema operacional, que é a constante para a duração da execução do programa.

Quando a página de código de localidade muda, o comportamento do conjunto de alterações de funções que ditado pela página de código escolhido dependente da localidade. Por padrão, todas as funções dependentes de localidade começam a execução com uma página de código de localidade exclusiva para a localidade "C". Você pode alterar a página de código de localidade internos (bem como outras propriedades específicas de localidade) chamando o `setlocale` função. Uma chamada para `setlocale`(LC_ALL, "") define a localidade como indicado pela localidade do usuário do sistema operacional.

Da mesma forma, quando a página de código multibyte muda, o comportamento das alterações funções multibyte que ditado pela página de código escolhido. Por padrão, todas as funções de multibyte iniciar a execução com uma página de código multibyte correspondente à página de código padrão do sistema operacional. Você pode alterar a página de código multibyte interno chamando o `_setmbcp` função.

A função de tempo de execução C `setlocale` define, as alterações ou consultas de algumas ou todas as informações de localidade do programa atual. O [wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) rotina é uma versão de caractere largo de `setlocale`; os argumentos e valores de retorno de `_wsetlocale` são cadeias de caracteres largos.

## <a name="see-also"></a>Consulte também

[Unicode e MBCS](../text/unicode-and-mbcs.md)<br/>
[Benefícios da portabilidade do conjunto de caracteres](../text/benefits-of-character-set-portability.md)