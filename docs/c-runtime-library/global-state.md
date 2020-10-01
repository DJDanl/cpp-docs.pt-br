---
title: Estado global no CRT
description: Descreve como o estado global compartilhado é tratado no tempo de execução do Microsoft Universal C.
ms.topic: conceptual
ms.date: 04/02/2020
helpviewer_keywords:
- CRT global state
ms.openlocfilehash: 60532fbdb905bd8ea78b4ce705ec8ecc3e374d9d
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91589725"
---
# <a name="global-state-in-the-crt"></a>Estado global no CRT

Algumas funções no tempo de execução universal C (UCRT) usam o estado global. Por exemplo, `setlocale()` define a localidade para todo o programa, que afeta os separadores de dígitos, a página de código de texto e assim por diante.

O estado global do UCRT não é compartilhado entre aplicativos e o sistema operacional. Por exemplo, se seu aplicativo chamar `setlocale()` , ele não afetará a localidade de qualquer componente do sistema operacional que use o tempo de execução C ou vice-versa.

## <a name="os-specific-versions-of-crt-functions"></a>Versões específicas do sistema operacional das funções do CRT

No UCRT, as funções que interagem com o estado global têm uma função "" "", prefixada com `_o_` . Por exemplo:

- `setlocale()` afeta o estado global específico do aplicativo.
- `_o_setlocale()` afeta o estado global compartilhado por todos os componentes do sistema operacional, mas não por aplicativos.

A única diferença entre essas funções "cópia" é que, ao ler/gravar o estado global do CRT, as versões específicas do sistema operacional (ou seja, as versões que começam com `_o_` ) usam a cópia do estado global do sistema operacional em vez da cópia do estado global do aplicativo.

As versões específicas do sistema operacional dessas funções estão no `ucrt.osmode.lib` . Por exemplo, a versão específica do sistema operacional do `setlocale()` é `_o_setlocale()`

Há duas maneiras de isolar o estado CRT do componente do estado CRT de um aplicativo:

- Vincule estaticamente seu componente usando as opções de compilador/MT (versão) ou MTd (depuração). Para obter detalhes, consulte [/MD,/MT,/LD](../build/reference/md-mt-ld-use-run-time-library.md). Observe que a vinculação estática pode aumentar significativamente o tamanho binário.
- Começando com o Windows 10 20H2, obtenha o isolamento do estado do CRT vinculando dinamicamente ao CRT, mas chame as exportações do modo do sistema operacional (as funções que começam com _o_). Para chamar as exportações do modo de sistema operacional, vincule estaticamente como antes, mas ignore o UCRT estático usando a opção de vinculador `/NODEFAULTLIB:libucrt.lib` (versão) ou `/NODEFAULTLIB:libucrtd.lib` (depuração) consulte [/NODEFAULTLIB (ignorar bibliotecas)](../build/reference/nodefaultlib-ignore-libraries.md) para obter detalhes. E adicione `ucrt.osmode.lib` à entrada do vinculador.

> [!Note]
> No código-fonte, escreva `setlocale()` , não `_o_setlocale()` . Ao vincular `ucrt.osmode.lib` , o vinculador substituirá automaticamente a versão específica do sistema operacional da função. Ou seja, `setlocale()` será substituído por `_o_setlocale()` .

A vinculação em `ucrt.osmode.lib` desabilita algumas chamadas UCRT que estão disponíveis apenas no modo de aplicativo. A tentativa de chamá-los resultará em um erro de link.

## <a name="global-state-affected-by-appos-separation"></a>Estado global afetado pela separação de aplicativo/so

O estado global afetado pela separação do aplicativo e do estado do sistema operacional inclui:

- [Dados de localidade](locale.md)
- Manipuladores de sinal definidos por [sinal](reference/signal.md)
- Rotinas de encerramento definidas por [Terminate](reference/set-terminate-crt.md)
- [errno e _doserrno](errno-doserrno-sys-errlist-and-sys-nerr.md)
- Estado de geração de número aleatório usado por [Rand](reference/rand.md) e [srand](reference/srand.md)
- Funções que retornam um buffer que o usuário não precisa para liberar: [strtok, wcstok, _mbstok](reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) [tmpnam, _wtmpnam](reference/tempnam-wtempnam-tmpnam-wtmpnam.md) [asctime, _wasctime](reference/asctime-wasctime.md) [gmtime, _gmtime32, _gmtime64](reference/gmtime-gmtime32-gmtime64.md) [_fcvt](reference/fcvt.md) [_ecvt](reference/ecvt.md) [strerror, _strerror, _wcserror,](reference/strerror-strerror-wcserror-wcserror.md) __wcserror
- O buffer usado pelo [_putch, _putwch](reference/putch-putwch.md)
- [_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md)
- [_set_new_handler](reference/set-new-handler.md) e [_set_new_mode](reference/set-new-mode.md)
- [fmode] (text-and-binary-mode-file-i-o.md)
- [Informações de fuso horário](time-management.md)

## <a name="see-also"></a>Confira também

[Referência da biblioteca de tempo de execução C](c-run-time-library-reference.md)
