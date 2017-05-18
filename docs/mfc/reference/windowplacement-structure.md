---
title: Estrutura WINDOWPLACEMENT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- WINDOWPLACEMENT
dev_langs:
- C++
helpviewer_keywords:
- WINDOWPLACEMENT structure
ms.assetid: ea7d61f6-eb57-478e-9b08-7c1d07091aa8
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 62cf7003f43d50d5998dd527ae5ad7b10ab95686
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="windowplacement-structure"></a>Estrutura WINDOWPLACEMENT
O `WINDOWPLACEMENT` estrutura contém informações sobre o posicionamento de uma janela na tela**.**  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagWINDOWPLACEMENT {     /* wndpl */  
    UINT length;  
    UINT flags;  
    UINT showCmd;  
    POINT ptMinPosition;  
    POINT ptMaxPosition;  
    RECT rcNormalPosition;  
} WINDOWPLACEMENT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *length*  
 Especifica o comprimento, em bytes, da estrutura**.**  
  
 `flags`  
 Especifica sinalizadores que controlam a posição da janela minimizada e o método pelo qual a janela é restaurada. Esse membro pode ser um ou ambos os sinalizadores a seguir:  
  
- **WPF_SETMINPOSITION** Especifica que as posições x e y da janela minimizada pode ser especificada**.** Esse sinalizador deve ser especificado se as coordenadas são definidas no **ptMinPosition** membro.  
  
- **WPF_RESTORETOMAXIMIZED** Especifica que a janela restaurada será ser maximizada, independentemente se ele foi maximizado antes que ele foi minimizado. Essa configuração é válida somente na próxima vez que a janela é restaurada. Ele não altera o comportamento de restauração padrão. Esse sinalizador é válido somente quando o **SW_SHOWMINIMIZED** valor for especificado para o **showCmd** membro.  
  
 *showCmd*  
 Especifica o estado atual da apresentação da janela. Esse membro pode ser um dos seguintes valores:  
  
- **SW_HIDE** oculta a janela e passa a ativação para outra janela.  
  
- **SW_MINIMIZE** minimiza a janela especificada e ativa a janela de nível superior na lista do sistema.  
  
- **SW_RESTORE** ativa e exibe uma janela. Se a janela for minimizada ou maximizada, Windows restaurá-lo em seu tamanho e posição original (mesmo que **SW_SHOWNORMAL**).  
  
- **SW_SHOW** ativa uma janela e exibe-o em sua posição e tamanho atual.  
  
- **SW_SHOWMAXIMIZED** ativa uma janela e exibe uma janela maximizada.  
  
- **SW_SHOWMINIMIZED** ativa uma janela e exibe-o como um ícone.  
  
- **SW_SHOWMINNOACTIVE** exibe uma janela como um ícone. A janela ativa no momento permanece ativa.  
  
- **SW_SHOWNA** exibe uma janela em seu estado atual. A janela ativa no momento permanece ativa.  
  
- **SW_SHOWNOACTIVATE** exibe uma janela em seu tamanho e posição mais recentes. A janela ativa no momento permanece ativa.  
  
- **SW_SHOWNORMAL** ativa e exibe uma janela. Se a janela for minimizada ou maximizada, Windows restaurá-lo em seu tamanho e posição original (mesmo que **SW_RESTORE**).  
  
 *ptMinPosition*  
 Especifica a posição do canto esquerdo superior da janela quando a janela é minimizada.  
  
 `ptMaxPosition`  
 Especifica a posição do canto esquerdo superior da janela quando a janela for maximizada.  
  
 *rcNormalPosition*  
 Especifica as coordenadas da janela quando a janela está na posição normal (restaurada).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::SetWindowPlacement](../../mfc/reference/cwnd-class.md#setwindowplacement)


