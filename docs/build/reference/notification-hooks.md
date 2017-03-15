---
title: "Ganchos de notifica&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "carregamento atrasado de DLLs, ganchos de notificação"
ms.assetid: e9c291ed-2f2d-4319-a171-09800625256f
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Ganchos de notifica&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os ganchos de notificação são chamados imediatamente antes das seguintes ações são coletadas a rotina auxiliares:  
  
-   O identificador armazenada na biblioteca é verificada para ver se ele já foi carregada nele.  
  
-   **LoadLibrary** é chamado para tentar a carga da DLL.  
  
-   **GetProcAddress** é chamado para tentar obter o endereço do procedimento.  
  
-   Retorne ao thunk de carga de importação de atraso.  
  
 O gancho de notificação é habilitado:  
  
-   Fornecendo uma nova definição do ponteiro **\_\_pfnDliNotifyHook2** que é inicializado para apontar para sua própria função que recebe as notificações.  
  
     \- ou \-  
  
-   Definindo o ponteiro **\_\_pfnDliNotifyHook2** à função de gancho antes que algumas chamadas para a DLL que o programa está carregando de atraso.  
  
 Se a notificação é **dliStartProcessing**, a função de gancho pode retornar:  
  
 NULL  
 O auxiliar padrão trata a carga da DLL.  Isso é útil ser chamado apenas para fins informativos.  
  
 ponteiro de função  
 Ignorar a manipulação padrão de atraso\- carga.  Isso permite fornecer seu próprio manipulador de carga.  
  
 Se a notificação é **dliNotePreLoadLibrary**, a função de gancho pode retornar:  
  
-   0, se deseja apenas mensagens informativas.  
  
-   O HMODULE para a DLL carregados, se o carregar a DLL próprio.  
  
 Se a notificação é **dliNotePreGetProcAddress**, a função de gancho pode retornar:  
  
-   0, se deseja apenas mensagens informativas.  
  
-   O endereço de função importada, se a função de gancho obtém o próprio endereço.  
  
 Se a notificação é **dliNoteEndProcessing**, o valor de retorno da função de gancho será ignorado.  
  
 Se esse ponteiro é inicializada \(diferente de zero\), o auxiliar de carga de atraso invocará a função em determinados pontos de notificação toda a sua execução.  O ponteiro de função tem a seguinte definição:  
  
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
  
 A passagem das notificações em uma estrutura de **DelayLoadInfo** à função de gancho junto com o valor de notificação.  Esses dados são idênticos aos usados por rotina auxiliares de carga de atraso.  O valor de notificação será um dos valores definidos em [Definições da estrutura e da constante](../../build/reference/structure-and-constant-definitions.md).  
  
## Consulte também  
 [Tratamento de erro e notificação](../../build/reference/error-handling-and-notification.md)