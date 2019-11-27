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
ms.openlocfilehash: 5821048363d92911f2902a580cb11f5b349f5e7c
ms.sourcegitcommit: 4f15b69e35dd112001b24fe9dc836dd5d6902465
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/25/2019
ms.locfileid: "74474076"
---
# <a name="locales-and-code-pages"></a>Localidades e páginas de código

Uma ID de localidade reflete as convenções locais e o idioma de uma região geográfica específica. Um determinado idioma pode ser falado em mais de um país/região; por exemplo, o português é falado no Brasil, bem como em Portugal. Por outro lado, um país/região pode ter mais de um idioma oficial. Por exemplo, o Canadá tem dois idiomas: Inglês e francês. Portanto, o Canadá tem duas localidades distintas: Canadá – inglês e Canadá-francês. Algumas categorias de localidade dependentes incluem a formatação de datas e o formato de exibição de valores monetários.

O idioma determina as convenções de texto e formatação de dados, enquanto o país/região determina as convenções locais. Cada idioma tem um mapeamento exclusivo, representado por páginas de código, que inclui caracteres diferentes daqueles no alfabeto (como marcas e números de pontuação). Uma página de código é um conjunto de caracteres e está relacionada ao idioma. Dessa forma, uma [localidade](../c-runtime-library/locale.md) é uma combinação exclusiva de idioma, país/região e página de código. A configuração de localidade e página de código pode ser alterada em tempo de execução chamando a função [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) .

Idiomas diferentes podem usar páginas de código diferentes. Por exemplo, a página de código ANSI 1252 é usada para idiomas inglês e mais europeus, e a página de código ANSI 932 é usada para japonês kanji. Praticamente todas as páginas de código compartilham o conjunto de caracteres ASCII para os mais baixos 128 caracteres (0x00 a 0x7F).

Qualquer página de código de byte único pode ser representada em uma tabela (com 256 entradas) como um mapeamento de valores de byte para caracteres (incluindo números e sinais de pontuação) ou glifos. Qualquer página de código multibyte também pode ser representada como uma tabela muito grande (com entradas de 64K) de valores de byte duplo para caracteres. Na prática, no entanto, normalmente ele é representado como uma tabela para os primeiros caracteres 256 (byte único) e como intervalos para os valores de byte duplo.

Para obter mais informações sobre páginas de códigos, consulte [Páginas de código](../c-runtime-library/code-pages.md).

A biblioteca de tempo de execução do C tem dois tipos de páginas de código internas: localidade e multibyte. Você pode alterar a página de código atual durante a execução do programa (consulte a documentação para as funções [setlocal](../c-runtime-library/reference/setlocale-wsetlocale.md) e [_setmbcp](../c-runtime-library/reference/setmbcp.md) ). Além disso, a biblioteca de tempo de execução pode obter e usar o valor da página de código do sistema operacional, que é constante para a duração da execução do programa.

Quando a página de código de localidade é alterada, o comportamento do conjunto de funções dependente de localidade é alterado para o que é determinado pela página de código escolhida. Por padrão, todas as funções dependentes de localidade iniciam a execução com uma página de código de localidade exclusiva para a localidade "C". Você pode alterar a página de código de localidade interna (bem como outras propriedades específicas de localidade) chamando a função `setlocale`. Uma chamada para `setlocale`(LC_ALL, "") define a localidade como indicada pela localidade do usuário do sistema operacional.

Da mesma forma, quando a página de código multibyte é alterada, o comportamento das funções multibyte é alterado para isso ditado pela página de código escolhida. Por padrão, todas as funções multibyte iniciam a execução com uma página de código multibyte correspondente à página de código padrão do sistema operacional. Você pode alterar a página de código multibyte interna chamando a função `_setmbcp`.

A função de tempo de execução C `setlocale` define, altera ou consulta algumas ou todas as informações de localidade do programa atual. A rotina de [_wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) é uma versão de caractere largo do `setlocale`; os argumentos e valores de retorno de `_wsetlocale` são cadeias de caracteres largos.

## <a name="see-also"></a>Consulte também

[Unicode e MBCS](../text/unicode-and-mbcs.md)<br/>
[Benefícios da portabilidade do conjunto de caracteres](../text/benefits-of-character-set-portability.md)
