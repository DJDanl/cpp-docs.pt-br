---
title: "Estilos da caixa de mensagem | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "MB_ICONQUESTION"
  - "MB_ICONINFORMATION"
  - "MB_DEFBUTTON2"
  - "MB_YESNO"
  - "MB_OKCANCEL"
  - "MB_TASKMODAL"
  - "MB_ICONEXCLAMATION"
  - "MB_OK"
  - "MB_DEFBUTTON3"
  - "MB_YESNOCANCEL"
  - "MB_APPLMODAL"
  - "MB_RETRYCANCEL"
  - "MB_DEFBUTTON1"
  - "MB_ABORTRETRYIGNORE"
  - "MB_SYSTEMMODAL"
  - "MB_ICONSTOP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante MB_ABORTRETRYIGNORE"
  - "Constante MB_APPLMODAL"
  - "Constante MB_DEFBUTTON1"
  - "Constante MB_DEFBUTTON2"
  - "Constante MB_DEFBUTTON3"
  - "Constante MB_ICONEXCLAMATION"
  - "Constante MB_ICONINFORMATION"
  - "Constante MB_ICONQUESTION"
  - "Constante MB_ICONSTOP"
  - "Constante MB_OK"
  - "Constante MB_OKCANCEL"
  - "Constante MB_RETRYCANCEL"
  - "Constante MB_SYSTEMMODAL"
  - "Constante MB_TASKMODAL"
  - "Constante MB_YESNO"
  - "Constante MB_YESNOCANCEL"
  - "estilos da caixa de mensagem"
ms.assetid: d87014c5-4ea4-4950-a27e-7bcdda67be7d
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos da caixa de mensagem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os seguintes estilos da caixa de mensagem estão disponíveis.  
  
## Tipos de Message\_Box  
  
-   **MB\_ABORTRETRYIGNORE** a caixa de mensagem contém três chaves: Nulo, tente, e ignorar.  
  
-   **MB\_OK** a caixa de mensagem contém uma tecla: OK.  
  
-   **MB\_OKCANCEL** a caixa de mensagem contém duas chaves: OK e cancelamento.  
  
-   **MB\_RETRYCANCEL** a caixa de mensagem contém duas chaves: Repetição e cancelamento.  
  
-   **MB\_YESNO** a caixa de mensagem contém duas chaves: Sim ou não.  
  
-   **MB\_YESNOCANCEL** a caixa de mensagem contém três chaves: Sim, não, e cancelamento.  
  
## O modo da caixa de mensagem  
  
-   **MB\_APPLMODAL** o usuário deve responder a caixa de mensagem antes de continuar o trabalho na janela atual.  No entanto, o usuário poderá passar para as janelas de outros aplicativos e trabalhar nas janelas.  A opção é **MB\_APPLMODAL** se nem nem **MB\_SYSTEMMODALMB\_TASKMODAL** são especificados.  
  
-   **MB\_SYSTEMMODAL** todos os aplicativos é suspenso até que o usuário responder a caixa de mensagem.  As caixas de mensagem modal sistema são usadas para notificar o usuário dos erros graves, potencialmente prejudiciais que exigem atenção imediata e devem ser usados com moderação.  
  
-   **MB\_TASKMODAL** semelhante a **MB\_APPLMODAL**, mas não útil em um aplicativo da classe do Microsoft.  Esse sinalizador é reservado para um aplicativo de chamada ou uma biblioteca que não tem um identificador de janela disponível.  
  
## Ícones da caixa de mensagem  
  
-   **MB\_ICONEXCLAMATION**que um ícone de ponto de exclamação aparece na caixa de mensagem.  
  
-   **MB\_ICONINFORMATION**que consista de ícone “i” em um círculo é exibida na caixa de mensagem.  
  
-   O ícone de ponto de interrogação de A**MB\_ICONQUESTION**aparece na caixa de mensagem.  
  
-   O ícone de sinal irrelevante de A**MB\_ICONSTOP**aparece na caixa de mensagem.  
  
## Botões padrão da caixa de mensagem  
  
-   **MB\_DEFBUTTON1** o primeiro botão é o padrão.  Observe que o primeiro botão é sempre o padrão a menos que **MB\_DEFBUTTON2** ou **MB\_DEFBUTTON3** é especificado.  
  
-   **MB\_DEFBUTTON2** o segundo botão é o padrão.  
  
-   **MB\_DEFBUTTON3** o terceiro botão é o padrão.  
  
## Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [AfxMessageBox](../Topic/AfxMessageBox.md)