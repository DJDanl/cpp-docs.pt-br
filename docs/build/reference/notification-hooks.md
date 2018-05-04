---
title: Ganchos de notificação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- delayed loading of DLLs, notification hooks
ms.assetid: e9c291ed-2f2d-4319-a171-09800625256f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0210c4ee058694594893a029789442c89003da2e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="notification-hooks"></a>Ganchos de notificação
Ganchos de notificação são chamados antes que as seguintes ações são executadas na rotina auxiliar:  
  
-   O identificador armazenado na biblioteca é verificado para ver se ele já foi carregado.  
  
-   **LoadLibrary** é chamado para tentar o carregamento da DLL.  
  
-   **GetProcAddress** é chamado para tentar obter o endereço do procedimento.  
  
-   Retornar para a conversão de carga de importação de atraso.  
  
 O gancho de notificação está habilitado:  
  
-   Fornecendo uma nova definição do ponteiro **__pfnDliNotifyHook2** que é inicializado para apontar para sua própria função que recebe as notificações.  
  
     -ou-  
  
-   Definindo o ponteiro **__pfnDliNotifyHook2** para a função de gancho antes de qualquer chamada para a DLL que o programa é atrasar o carregamento.  
  
 Se a notificação é **dliStartProcessing**, a função de gancho pode retornar:  
  
 NULL  
 O auxiliar padrão manipula o carregamento da DLL. Isso é útil para ser chamado apenas para fins informativos.  
  
 ponteiro de função  
 Ignore a manipulação de carregamento de atraso padrão. Isso permite que você forneça seu próprio manipulador de carga.  
  
 Se a notificação é **dliNotePreLoadLibrary**, a função de gancho pode retornar:  
  
-   0, se desejar apenas informativas notificações.  
  
-   O HMODULE de DLL carregada, se ele carregar a DLL em si.  
  
 Se a notificação é **dliNotePreGetProcAddress**, a função de gancho pode retornar:  
  
-   0, se desejar apenas informativas notificações.  
  
-   Endereço da função importados, se a função de gancho obtém o endereço em si.  
  
 Se a notificação é **dliNoteEndProcessing**, o valor de retorno da função de gancho é ignorado.  
  
 Se esse ponteiro for inicializado (diferente de zero), o auxiliar de carregamento de atraso chamará a função em determinados pontos de notificação durante sua execução. O ponteiro de função tem a seguinte definição:  
  
```  
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
  
 As notificações de transmitir um **DelayLoadInfo** estrutura para a função de gancho junto com o valor de notificação. Esses dados são idênticos aos usados pela rotina de auxiliar de carregamento de atraso. O valor de notificação será um dos valores definidos em [estrutura e definições de constantes](../../build/reference/structure-and-constant-definitions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de erro e notificação](../../build/reference/error-handling-and-notification.md)