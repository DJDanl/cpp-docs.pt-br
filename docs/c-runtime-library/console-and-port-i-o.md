---
title: Console e E/S de porta
ms.date: 11/04/2016
f1_keywords:
- c.io
helpviewer_keywords:
- routines, console and port I/O
- routines
- ports, I/O routines
- I/O [CRT], console
- I/O [CRT], port
- I/O routines, console and port I/O
ms.assetid: 0eee1c92-9b3d-41e0-a43a-257e546eeec8
ms.openlocfilehash: 728ff6fa36d21e869c65db705b25bbe7c9d711ed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50446755"
---
# <a name="console-and-port-io"></a>Console e E/S de porta

Essas rotinas fazem leitura e gravação no seu console ou na porta especificada. As rotinas de E/S do console não são compatíveis com as rotinas de biblioteca de E/S de fluxo ou E/S de nível inferior. O console ou porta não precisa ser aberto ou fechado antes da realização da E/S; portanto, não há rotinas de abrir ou fechar nessa categoria. Nos sistemas operacionais Windows, a saída dessas funções é sempre direcionada para o console e não pode ser redirecionada.

## <a name="console-and-port-io-routines"></a>Rotinas de E/S de console e porta

|Rotina|Use|
|-------------|---------|
|[_cgets, _cgetws](../c-runtime-library/cgets-cgetws.md), [_cgets_s, _cgetws_s](../c-runtime-library/reference/cgets-s-cgetws-s.md)|Ler a cadeia de caracteres do console|
|[_cprintf, _cwprintf](../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md), [_cprintf_s, _cprintf_s_l, _cwprintf_s, _cwprintf_s_l](../c-runtime-library/reference/cprintf-s-cprintf-s-l-cwprintf-s-cwprintf-s-l.md)|Gravar dados formatados no console|
|[_cputs](../c-runtime-library/reference/cputs-cputws.md)|Gravar a cadeia de caracteres no console|
|[_cscanf, _cwscanf](../c-runtime-library/reference/cscanf-cscanf-l-cwscanf-cwscanf-l.md), [_cscanf_s, _cscanf_s_l, _cwscanf_s, _cwscanf_s_l](../c-runtime-library/reference/cscanf-s-cscanf-s-l-cwscanf-s-cwscanf-s-l.md)|Ler dados formatados do console|
|[_getch, _getwch](../c-runtime-library/reference/getch-getwch.md)|Ler caracteres do console|
|[_getche, _getwche](../c-runtime-library/reference/getch-getwch.md)|Ler caracteres do console e reproduzi-los|
|[_inp](../c-runtime-library/inp-inpw-inpd.md)|Ler um byte da porta de E/S especificada|
|[_inpd](../c-runtime-library/inp-inpw-inpd.md)|Ler uma palavra dupla da porta de E/S especificada|
|[_inpw](../c-runtime-library/inp-inpw-inpd.md)|Ler uma palavra de 2 bytes da porta de E/S especificada|
|[_kbhit](../c-runtime-library/reference/kbhit.md)|Procurar pressionamento de tecla no console; usar antes de tentar ler do console|
|[_outp](../c-runtime-library/outp-outpw-outpd.md)|Gravar um byte na porta de E/S especificada|
|[_outpd](../c-runtime-library/outp-outpw-outpd.md)|Gravar uma palavra dupla na porta de E/S especificada|
|[_outpw](../c-runtime-library/outp-outpw-outpd.md)|Gravar uma palavra na porta de E/S especificada|
|[_putch, _putwch](../c-runtime-library/reference/putch-putwch.md)|Gravar caracteres no console|
|[_ungetch, _ungetwch](../c-runtime-library/reference/ungetch-ungetwch-ungetch-nolock-ungetwch-nolock.md)|"Liberar" o último caractere lido do console para ele se tornar o próximo caractere lido|

## <a name="see-also"></a>Consulte também

[Entrada e saída](../c-runtime-library/input-and-output.md)<br/>
[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>