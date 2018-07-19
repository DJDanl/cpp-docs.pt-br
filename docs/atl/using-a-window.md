---
title: Usando uma janela (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ATL, windows
- CWindow class, about CWindow class
- windows [C++], ATL
ms.assetid: b3b9cc8e-4287-486b-b080-38852bc2943a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 44b9988c0ecde4d0aee917fea686ec6511473318
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37847918"
---
# <a name="using-a-window"></a>Usando uma janela
Classe [CWindow](../atl/reference/cwindow-class.md) permite que você use uma janela. Depois que você anexe uma janela para um `CWindow` do objeto, em seguida, você pode chamar `CWindow` métodos para manipular a janela. `CWindow` também contém um operador HWND para converter um `CWindow` objeto para um HWND. Portanto, você pode passar um `CWindow` objeto para qualquer função que requer um identificador para uma janela. Você pode facilmente combinar `CWindow` chamadas de método e chamadas de função do Win32, sem criar todos os objetos temporários.  
  
 Porque `CWindow` tem um membro de dados apenas dois (um identificador de janela e as dimensões padrão), ele não impõe uma sobrecarga em seu código. Além disso, muitos do `CWindow` métodos simplesmente encapsulam funções de API do Win32 correspondentes. Usando `CWindow`, o membro HWND é automaticamente passado para a função do Win32.  
  
 Além de usar `CWindow` diretamente, você também pode derivar dela para adicionar dados ou código à sua classe. Três classes de ATL em si é derivado `CWindow`: [CWindowImpl](../atl/implementing-a-window.md), [CDialogImpl](../atl/implementing-a-dialog-box.md), e [CContainedWindowT](../atl/using-contained-windows.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classes de janela](../atl/atl-window-classes.md)

