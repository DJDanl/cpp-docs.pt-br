---
title: E/S de fluxo Unicode em modos de texto e binários
description: Uma descrição das conversões de caracteres com e/s de fluxo Unicode.
ms.topic: conceptual
ms.date: 11/04/2016
helpviewer_keywords:
- stream I/O routines
- I/O [CRT], unicode stream
- Unicode, stream I/O routines
- Unicode stream I/O
ms.assetid: 68be0c3e-a9e6-4fd5-b34a-1b5207f0e7d6
ms.openlocfilehash: 9c4ef7da54463021f9487849df0235ae289e38fa
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590232"
---
# <a name="unicode-stream-io-in-text-and-binary-modes"></a>E/S de fluxo Unicode em modos de texto e binários

Quando a rotina de E/S de fluxo Unicode (como **fwprintf**, **fwscanf**, **fgetwc**, **fputwc**, **fgetws** ou **fputws**) opera em um arquivo que está aberto no modo de texto (o padrão), dois tipos de conversões de caractere ocorrem:

- Conversão de Unicode em MBCS ou MBCS para Unicode. Quando uma função de E/S de fluxo Unicode opera no modo de texto, presume-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte. Portanto, as funções de entrada de fluxo Unicode convertem caracteres multibyte em caracteres largos (como por uma chamada à função **mbtowc**). Pelo mesmo motivo, as funções de saída de fluxo Unicode convertem caracteres largos em caracteres multibyte (como por uma chamada à função **wctomb**).

- Conversão CR-LF (retorno de carro – alimentação de linha). Essa conversão ocorre antes do MBCS – conversão Unicode (para funções de entrada de fluxo Unicode) e depois da conversão de Unicode – MBCS (para funções de saída de fluxo Unicode). Durante a entrada, cada combinação de retorno de carro – alimentação de linha é convertida em um caractere de alimentação de linha único. Durante a saída, cada caractere de alimentação de linha é convertido em uma combinação de retorno de carro – alimentação de linha.

No entanto, quando uma função de E/S de fluxo Unicode opera no modo binário, o arquivo é considerado como Unicode e nenhuma conversão de CR-LF ou conversão de caractere ocorre durante a entrada ou saída. Siga a instrução `_setmode( _fileno( stdin ), _O_BINARY );` para usar `wcin` corretamente em um arquivo de texto UNICODE.

## <a name="see-also"></a>Confira também

[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
[Entrada e saída](../c-runtime-library/input-and-output.md)<br/>
