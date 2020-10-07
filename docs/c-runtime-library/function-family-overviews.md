---
title: Visão geral da família de funções
description: Uma visão geral das funções de tempo de execução do Microsoft C por família.
ms.date: 10/05/2020
ms.assetid: b05a2755-9d11-4ea9-ab97-d00a4e872e16
ms.openlocfilehash: de5192cd03c3821afc646241d75a3e8c6c8c12e3
ms.sourcegitcommit: 8caaf5e00aeb727741a273aecafa15de293426cf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2020
ms.locfileid: "91806507"
---
# <a name="function-family-overview"></a>Visão geral da família de funções

Esta seção lista as rotinas da biblioteca de tempo de execução do C por família de funções.

## <a name="crt-library-routine-families"></a>Famílias de rotina da biblioteca CRT

[_exec, _wexec](exec-wexec-functions.md)\
Funções para carregar e executar um novo processo.

[Funções de pesquisa de nome de arquivo](filename-search-functions.md)\
Funções para pesquisar nomes de arquivo especificados e para fechar pesquisas.

[Sintaxe de especificação de formato para `printf` e `wprintf`](format-specification-syntax-printf-and-wprintf-functions.md)\
Descreve a cadeia de caracteres de formato e os argumentos para `printf` e `wprintf` .

[Caracteres de campo de especificação `scanf` de formato: e `wscanf`](format-specification-fields-scanf-and-wscanf-functions.md)\
Descreve os campos de especificação de formato para analisar um fluxo de entrada para toda a `scanf` família de funções.

[`is`, `isw` funções](is-isw-routines.md)\
Funções para testar caracteres para coisas como se são maiúsculas, ASCII, numérico, pontuação e assim por diante.

[`_ismbb` funções](ismbb-routines.md)\
Funções para testar um valor inteiro para se representar um caractere alfabético, um caractere em branco, um caractere de impressão e assim por diante.

[`_ismbc` funções](ismbc-routines.md)\
Funções para testar um caractere multibyte para se representar um caractere alfabético, um caractere em branco, um caractere de impressão e assim por diante.

[operador `delete` (CRT)](delete-operator-crt.md)\
A partir do Visual Studio 2013, o universal C Runtime (UCRT) não dá mais suporte à função de exclusão do operador específico do C++. Agora ele faz parte da biblioteca padrão C++.

[operador `new` (CRT)](new-operator-crt.md)\
A partir do Visual Studio 2013, o universal C Runtime (UCRT) não oferece mais suporte à nova função operadora de operadores específicos do C++. Agora ele faz parte da biblioteca padrão C++.

[`printf` funções de parâmetro posicionais](printf-p-positional-parameters.md)\
Os parâmetros posicionais especificam por número qual dos argumentos deve ser substituído em um campo em uma cadeia de caracteres de formato.

[`scanf` digitar caracteres de campo](scanf-type-field-characters.md)\
O caractere de tipo determina se o argumento associado é interpretado como um caractere, uma cadeia de caracteres ou um número para qualquer uma das `scanf` famílias de funções, incluindo as versões seguras, como `scanf_s` .

[`scanf` especificação de largura](scanf-width-specification.md)\
O campo largura é um inteiro decimal positivo que controla o número máximo de caracteres a serem lidos para esse campo. Aplica-se a qualquer uma das `scanf` famílias de funções, incluindo as versões seguras, como `scanf_s` .

[_spawn, _wspawn funções](spawn-wspawn-functions.md)\
Funções para criar e executar um novo processo.

[`strcoll` funções](strcoll-functions.md)\
As `strcoll` `wcscoll` funções e comparam duas cadeias de caracteres de acordo com a `LC_COLLATE` configuração de categoria da página de código de localidade.

[Cadeia de caracteres para funções de valor numérico](string-to-numeric-value-functions.md)\
A `strtod` família de funções converte uma cadeia de caracteres terminada em nulo para um valor numérico.

[`vprintf` funções](vprintf-functions.md)\
As `vprintf` funções tomam um ponteiro para uma lista de argumentos, formatam e gravam o resultado no destino especificado. As funções diferem na validação de parâmetro executada, independentemente de terem ou não cadeias de caracteres de bytes largos ou de byte único, o destino de saída e o suporte para especificar a ordem na qual os parâmetros são usados na cadeia de caracteres de formato.

## <a name="see-also"></a>Consulte também

[Referência da biblioteca de tempo de execução C](c-run-time-library-reference.md)