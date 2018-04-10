---
title: Usando uma janela (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- ATL, windows
- CWindow class, about CWindow class
- windows [C++], ATL
ms.assetid: b3b9cc8e-4287-486b-b080-38852bc2943a
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a2be573e10190b385274de9afab498c77a094550
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-a-window"></a>Usando uma janela
Classe [CWindow](../atl/reference/cwindow-class.md) permite que você use uma janela. Quando você anexa uma janela para um `CWindow` do objeto, em seguida, você pode chamar `CWindow` métodos para manipular a janela. `CWindow`também contém um `HWND` para converter um `CWindow` o objeto para um `HWND`. Portanto, você pode passar um `CWindow` objeto para qualquer função que requer um identificador para uma janela. Você pode facilmente combinar `CWindow` chamadas de método e chamadas de função do Win32, sem criar todos os objetos temporários.  
  
 Porque `CWindow` tem um membro de dados apenas dois (um identificador de janela e as dimensões padrão), ele não impõe uma sobrecarga no seu código. Além disso, muitos do `CWindow` métodos simplesmente encapsular funções de API do Win32 correspondentes. Usando `CWindow`, o `HWND` membro automaticamente é passado para a função Win32.  
  
 Além de usar `CWindow` diretamente, você também pode derivar de para adicionar o código ou dados à sua classe. ATL em si deriva três classes de `CWindow`: [CWindowImpl](../atl/implementing-a-window.md), [CDialogImpl](../atl/implementing-a-dialog-box.md), e [CContainedWindowT](../atl/using-contained-windows.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classes de janela](../atl/atl-window-classes.md)

