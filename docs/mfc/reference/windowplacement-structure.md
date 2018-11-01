---
title: Estrutura WINDOWPLACEMENT
ms.date: 11/04/2016
f1_keywords:
- WINDOWPLACEMENT
helpviewer_keywords:
- WINDOWPLACEMENT structure [MFC]
ms.assetid: ea7d61f6-eb57-478e-9b08-7c1d07091aa8
ms.openlocfilehash: fecca306045805661a7799aca8d9ea57ea11f5b8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50518671"
---
# <a name="windowplacement-structure"></a>Estrutura WINDOWPLACEMENT

O `WINDOWPLACEMENT` estrutura contém informações sobre o posicionamento de uma janela na tela.

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

*length*<br/>
Especifica o comprimento, em bytes, da estrutura.

*flags*<br/>
Especifica sinalizadores que controlam a posição da janela minimizada e o método pelo qual a janela é restaurada. Esse membro pode ser um ou ambos os sinalizadores a seguir:

- WPF_SETMINPOSITION Especifica que as posições x e y da janela minimizada pode ser especificada. Este sinalizador deve ser especificado se as coordenadas são definidas no `ptMinPosition` membro.

- WPF_RESTORETOMAXIMIZED Especifica que a janela restaurada será ser maximizada, independentemente se ele foi maximizado antes que ele foi minimizado. Essa configuração é válida somente na próxima vez em que a janela é restaurada. Ele não altera o comportamento de restauração padrão. Esse sinalizador é válido somente quando o valor SW_SHOWMINIMIZED é especificado para o `showCmd` membro.

*showCmd*<br/>
Especifica o estado de Mostrar atual da janela. Esse membro pode ser um dos seguintes valores:

- SW_HIDE oculta a janela e passa a ativação para outra janela.

- SW_MINIMIZE minimiza a janela especificada e ativa a janela de nível superior da lista desse sistema.

- SW_RESTORE ativa e exibe uma janela. Se a janela é minimizada ou maximizada, o Windows irá restaurá-lo em sua posição (mesmo que do SW_SHOWNORMAL) e o tamanho original.

- SW_SHOW ativa uma janela e o exibe em sua posição e tamanho atual.

- SW_SHOWMAXIMIZED ativa uma janela e a exibe como uma janela maximizada.

- SW_SHOWMINIMIZED ativa uma janela e exibe-o como um ícone.

- SW_SHOWMINNOACTIVE exibe uma janela como um ícone. A janela ativa no momento permanece ativa.

- SW_SHOWNA exibe uma janela em seu estado atual. A janela ativa no momento permanece ativa.

- SW_SHOWNOACTIVATE exibe uma janela em seu tamanho e posição mais recentes. A janela ativa no momento permanece ativa.

- Ativa do SW_SHOWNORMAL e exibe uma janela. Se a janela é minimizada ou maximizada, o Windows irá restaurá-lo em sua posição (mesmo que SW_RESTORE) e o tamanho original.

*ptMinPosition*<br/>
Especifica a posição do canto de superior esquerdo da janela quando a janela é minimizada.

*ptMaxPosition*<br/>
Especifica a posição do canto de superior esquerdo da janela quando a janela está maximizada.

*rcNormalPosition*<br/>
Especifica as coordenadas da janela quando a janela está na posição normal (restaurada).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::SetWindowPlacement](../../mfc/reference/cwnd-class.md#setwindowplacement)

