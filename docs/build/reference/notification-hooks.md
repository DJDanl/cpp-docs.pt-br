---
title: Ganchos de notificação
ms.date: 11/04/2016
helpviewer_keywords:
- delayed loading of DLLs, notification hooks
ms.assetid: e9c291ed-2f2d-4319-a171-09800625256f
ms.openlocfilehash: 1e4dc6331e2a957c0268e686fff7dbb3f7eb0b24
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426544"
---
# <a name="notification-hooks"></a>Ganchos de notificação

Os ganchos de notificação são chamados antes que as seguintes ações são executadas na rotina auxiliar:

- O identificador armazenado na biblioteca é verificado para ver se ele já foi carregado.

- **LoadLibrary** é chamado para tentar o carregamento da DLL.

- **GetProcAddress** é chamado para tentar obter o endereço do procedimento.

- Retorne para a conversão de carga de importação de atraso.

O gancho de notificação está habilitado:

- Fornecendo uma nova definição do ponteiro **__pfnDliNotifyHook2** que é inicializado para apontar para sua própria função que recebe as notificações.

   \-ou-

- Definindo o ponteiro **__pfnDliNotifyHook2** à sua função de gancho antes de todas as chamadas para a DLL que o programa é atrasar o carregamento.

Se a notificação for **dliStartProcessing**, a função de gancho pode retornar:

- NULL

   O auxiliar padrão manipula o carregamento da DLL. Isso é útil a ser chamado apenas para fins informativos.

- ponteiro de função

   Ignore o tratamento de carregamento de atraso padrão. Isso lhe permite fornecer seu próprio manipulador de carga.

Se a notificação for **dliNotePreLoadLibrary**, a função de gancho pode retornar:

- 0, se ele quer apenas notificações informativas.

- O HMODULE para DLL carregada, se ele carregado da própria DLL.

Se a notificação for **dliNotePreGetProcAddress**, a função de gancho pode retornar:

- 0, se ele quer apenas notificações informativas.

- Endereço da função importada, se a função de gancho obtém o endereço em si.

Se a notificação for **dliNoteEndProcessing**, o valor de retorno da função de gancho é ignorado.

Se esse ponteiro é inicializado (diferente de zero), o auxiliar de carregamento de atraso invocará a função em determinados pontos de notificação em toda a sua execução. O ponteiro de função tem a seguinte definição:

```C
// The "notify hook" gets called for every call to the
// delay load helper.  This allows a user to hook every call and
// skip the delay load helper entirely.
//
// dliNotify == {
//  dliStartProcessing |
//  dliNotePreLoadLibrary  |
//  dliNotePreGetProc |
//  dliNoteEndProcessing}
//  on this call.
//
ExternC
PfnDliHook   __pfnDliNotifyHook2;

// This is the failure hook, dliNotify = {dliFailLoadLib|dliFailGetProc}
ExternC
PfnDliHook   __pfnDliFailureHook2;
```

As notificações de passam uma **DelayLoadInfo** estrutura para a função de gancho juntamente com o valor de notificação. Esses dados são idênticos àquela usada pela rotina do auxiliar de carga do atraso. O valor de notificação será um dos valores definidos na [definições de estrutura e constante](../../build/reference/structure-and-constant-definitions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de erro e notificação](../../build/reference/error-handling-and-notification.md)
