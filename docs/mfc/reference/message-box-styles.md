---
title: Estilos de caixa de mensagem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- MB_ICONQUESTION
- MB_ICONINFORMATION
- MB_DEFBUTTON2
- MB_YESNO
- MB_OKCANCEL
- MB_TASKMODAL
- MB_ICONEXCLAMATION
- MB_OK
- MB_DEFBUTTON3
- MB_YESNOCANCEL
- MB_APPLMODAL
- MB_RETRYCANCEL
- MB_DEFBUTTON1
- MB_ABORTRETRYIGNORE
- MB_SYSTEMMODAL
- MB_ICONSTOP
dev_langs:
- C++
helpviewer_keywords:
- MB_RETRYCANCEL constant
- MB_TASKMODAL constant
- message-box styles
- MB_OKCANCEL constant
- MB_OK constant
- MB_DEFBUTTON1 constant
- MB_ICONQUESTION constant
- MB_ICONINFORMATION constant
- MB_SYSTEMMODAL constant
- MB_ICONSTOP constant
- MB_YESNO constant
- MB_YESNOCANCEL constant
- MB_DEFBUTTON2 constant
- MB_ABORTRETRYIGNORE constant
- MB_ICONEXCLAMATION constant
- MB_DEFBUTTON3 constant
- MB_APPLMODAL constant
ms.assetid: d87014c5-4ea4-4950-a27e-7bcdda67be7d
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7a6d3aa48a9e00eeb55bb62b7801edb64bd4285f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="message-box-styles"></a>Estilos da caixa de mensagem
Os estilos de caixa de mensagem a seguir estão disponíveis.  
  
## <a name="messagebox-types"></a>Tipos de Message_Box  
  
-   **MB_ABORTRETRYIGNORE** a caixa de mensagem contém três pushbuttons: Abortar, repetir e ignorar.  
  
-   **MB_OK** a caixa de mensagem contém um botão de ação: Okey.  
  
-   **MB_OKCANCEL** a caixa de mensagem contém dois pushbuttons: Okey e Cancelar.  
  
-   **MB_RETRYCANCEL** a caixa de mensagem contém dois pushbuttons: Repetir e Cancelar.  
  
-   **MB_YESNO** a caixa de mensagem contém dois pushbuttons: Sim e não.  
  
-   **MB_YESNOCANCEL** a caixa de mensagem contém três pushbuttons: Sim, não e Cancelar.  
  
## <a name="message-box-modality"></a>Caixa de mensagem modalidade  
  
-   **MB_APPLMODAL** o usuário deve responder à caixa de mensagem antes de continuar o trabalho na janela atual. No entanto, o usuário pode mover para janelas de outros aplicativos e de trabalho nessas janelas. O padrão é **MB_APPLMODAL** se nem **MB_SYSTEMMODAL** nem **MB_TASKMODAL** for especificado.  
  
-   **MB_SYSTEMMODAL** todos os aplicativos são suspensos até que o usuário responda à caixa de mensagem. Caixas de mensagem modal do sistema são usadas para notificar o usuário sobre sério, potencialmente prejudiciais erros que exigem atenção imediata e devem ser usados com moderação.  
  
-   **MB_TASKMODAL** semelhante ao **MB_APPLMODAL**, mas não é útil em um aplicativo de classe do Microsoft Foundation. Esse sinalizador é reservado para um aplicativo de chamada ou a biblioteca que não tem um identificador de janela disponível.  
  
## <a name="message-box-icons"></a>Ícones de caixa de mensagem  
  
-   **MB_ICONEXCLAMATION** um ícone de ponto de exclamação aparece na caixa de mensagem.  
  
-   **MB_ICONINFORMATION** um ícone consiste em um "I" em um círculo aparece na caixa de mensagem.  
  
-   **MB_ICONQUESTION** um ícone de ponto de interrogação é exibido na caixa de mensagem.  
  
-   **MB_ICONSTOP** um ícone de sinal de interrupção aparece na caixa de mensagem.  
  
## <a name="message-box-default-buttons"></a>Caixa de mensagem padrão botões  
  
-   **MB_DEFBUTTON1** o primeiro botão é o padrão. Observe que o primeiro botão é sempre o padrão, a menos que **MB_DEFBUTTON2** ou **MB_DEFBUTTON3** for especificado.  
  
-   **MB_DEFBUTTON2** o segundo botão é o padrão.  
  
-   **MB_DEFBUTTON3** o terceiro botão é o padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [AfxMessageBox](../../mfc/reference/cstring-formatting-and-message-box-display.md#afxmessagebox)


