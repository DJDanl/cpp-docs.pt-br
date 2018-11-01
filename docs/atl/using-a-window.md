---
title: Usando uma janela (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- ATL, windows
- CWindow class, about CWindow class
- windows [C++], ATL
ms.assetid: b3b9cc8e-4287-486b-b080-38852bc2943a
ms.openlocfilehash: 7446196e9eec4b9d9236d4ab55afd9fcf859254b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50568644"
---
# <a name="using-a-window"></a>Usando uma janela

Classe [CWindow](../atl/reference/cwindow-class.md) permite que você use uma janela. Depois que você anexe uma janela para um `CWindow` do objeto, em seguida, você pode chamar `CWindow` métodos para manipular a janela. `CWindow` também contém um operador HWND para converter um `CWindow` objeto para um HWND. Portanto, você pode passar um `CWindow` objeto para qualquer função que requer um identificador para uma janela. Você pode facilmente combinar `CWindow` chamadas de método e chamadas de função do Win32, sem criar todos os objetos temporários.

Porque `CWindow` tem um membro de dados apenas dois (um identificador de janela e as dimensões padrão), ele não impõe uma sobrecarga em seu código. Além disso, muitos do `CWindow` métodos simplesmente encapsulam funções de API do Win32 correspondentes. Usando `CWindow`, o membro HWND é automaticamente passado para a função do Win32.

Além de usar `CWindow` diretamente, você também pode derivar dela para adicionar dados ou código à sua classe. Três classes de ATL em si é derivado `CWindow`: [CWindowImpl](../atl/implementing-a-window.md), [CDialogImpl](../atl/implementing-a-dialog-box.md), e [CContainedWindowT](../atl/using-contained-windows.md).

## <a name="see-also"></a>Consulte também

[Classes de janela](../atl/atl-window-classes.md)

