---
title: Estado global no CRT
ms.date: 04/02/2020
helpviewer_keywords:
- CRT global state
ms.openlocfilehash: 487418da104b2edbc45b5d3a664e4385394ada31
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81379096"
---
# <a name="global-state-in-the-crt"></a>Estado global no CRT

Algumas funções no Universal C Runtime (UCRT) usam o estado global. Por exemplo, `setlocale()` define o local para todo o programa, que afeta os separadores de dígitos, a página de código de texto e assim por diante.

O estado global da UCRT não é compartilhado entre aplicativos e o SO. Por exemplo, se `setlocale()`o aplicativo chamar, não afetará a localização de quaisquer componentes do SISTEMA OPERACIONAL que usem o tempo de execução C ou vice-versa.

## <a name="os-specific-versions-of-crt-functions"></a>Versões específicas do SISTEMA OPERACIONAL de funções CRT

Na UCRT, as funções que interagem com o estado `_o_`global têm uma função "gêmea", prefixada com . Por exemplo:

    `setlocale()` affects global state specific to the app.
    `_o_setlocale()` affects global state shared by all OS components, but not apps.

A única diferença entre essas funções "gêmeas" é que, quando lêem/escrevem o estado global de `_o_`CRT, as versões específicas do Sistema Operacional (ou seja, as versões que começam ) usam a cópia do SO do estado global em vez da cópia do estado global do aplicativo.

As versões específicas do Sistema `ucrt.osmode.lib`Operacional dessas funções estão em . Por exemplo, a versão `setlocale()` específica do Sistema Operacional é`_o_setlocale()`

Existem duas maneiras de isolar o estado CRT do seu componente do estado CRT de um aplicativo:

- Vincule o componente de forma estática usando opções de compilador /MT (versão) ou MTd (depuração). Para obter detalhes, consulte [/MD, /MT, /LD](https://docs.microsoft.com/cpp/build/reference/md-mt-ld-use-run-time-library?view=vs-2019). Observe que a ligação estática pode aumentar muito o tamanho binário.
- A partir do Windows 10 20H2, obtenha o isolamento do estado CRT ligando-se dinamicamente ao CRT, mas chame as exportações do modo SO (as funções que começam com _o_). Para chamar as exportações do modo SO, vincule estáticamente como `/NODEFAULTLIB:libucrt.lib` antes, mas `/NODEFAULTLIB:libucrtd.lib` ignore o UCRT estático usando a opção linker (versão) ou (depuração) Consulte [/NODEFAULTLIB (Ignorar bibliotecas)](https://docs.microsoft.com/cpp/build/reference/nodefaultlib-ignore-libraries?view=vs-2019) para obter detalhes. E `ucrt.osmode.lib` adicione à entrada do linker.

> [!Note]
> No código fonte, `setlocale()` `_o_setlocale()`escreva, não . Quando você `ucrt.osmode.lib`se vincula, o linker substituirá automaticamente a versão específica do sistema operacional da função. Ou seja, `setlocale()` será substituído `_o_setlocale()`por .

Vincular `ucrt.osmode.lib` contra desabilita algumas chamadas UCRT que só estão disponíveis no modo de aplicativo. Tentar chamá-los resultará em um erro de link.

## <a name="global-state-affected-by-appos-separation"></a>Estado global afetado pela separação do aplicativo/SO

O estado global afetado pela separação do aplicativo e do estado do SO inclui:

- [Dados locais](locale.md)
- Manipuladores de sinal definidos por [sinal](reference/signal.md)
- Rotinas de término definidas por [término](reference/set-terminate-crt.md)
- [errno e _doserrno](errno-doserrno-sys-errlist-and-sys-nerr.md)
- Estado de geração de números aleatórios usado por [rand](reference/rand.md) e [srand](reference/srand.md)
- Funções que retornam um buffer que o usuário não precisa liberar: [strtok, wcstok, _mbstok](reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) [Tmpnam, _wtmpnam](reference/tempnam-wtempnam-tmpnam-wtmpnam.md) [asctime, _wasctime](reference/asctime-wasctime.md) [gmtime, _gmtime32, _gmtime64](reference/gmtime-gmtime32-gmtime64.md) [_fcvt](reference/fcvt.md) [_ecvt](reference/ecvt.md) [strerror, _strerror, _wcserror, __wcserror](reference/strerror-strerror-wcserror-wcserror.md)
- O buffer usado por [_putch, _putwch](reference/putch-putwch.md)
- [_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md)
- [_set_new_handler](reference/set-new-handler.md) e [_set_new_mode](reference/set-new-mode.md)
- [fmode] (text-and-binary-mode-file-i-o.md)
- [Informações de fuso horário](time-management.md)

## <a name="see-also"></a>Confira também

[Referência da biblioteca C Run-Time](c-run-time-library-reference.md)