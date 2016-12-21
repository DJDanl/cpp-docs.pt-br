---
title: "Usando uma janela | Microsoft Docs"
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
  - "ATL, o windows"
  - "Classe de CWindow, sobre a classe de CWindow"
  - "windows [C++], ATL"
ms.assetid: b3b9cc8e-4287-486b-b080-38852bc2943a
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando uma janela
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

a classe [CWindow](../atl/reference/cwindow-class.md) permite que você use uma janela.  Uma vez que você anexar uma janela em um objeto de `CWindow` , você pode chamar métodos de `CWindow` para manipular a janela.  `CWindow` também contém um operador de `HWND` para converter um objeto de `CWindow` a `HWND`.  Assim você pode passar um objeto de `CWindow` a qualquer função que requer um identificador para uma janela.  Você pode facilmente misturar chamadas de método de `CWindow` e chamadas de função do Win32, sem criar os objetos temporários.  
  
 Porque `CWindow` tem o membro de apenas dois dados \(um identificador de janela e as dimensões de opção\), não impõe uma sobrecarga em seu código.  Além de isso, muitos dos métodos de `CWindow` envolvem simplesmente corresponder funções da API do Win32.  Usando `CWindow`, o membro de `HWND` é passado automaticamente à função do Win32.  
  
 Além de usar de `CWindow` diretamente, você também pode derivar de ele para adicionar dados ou código à sua classe.  ATL próprio derivado três classes de `CWindow`: [CWindowImpl](../atl/implementing-a-window.md), [CDialogImpl](../atl/implementing-a-dialog-box.md), e [CContainedWindowT](../Topic/Using%20Contained%20Windows.md).  
  
## Consulte também  
 [Classes de janela](../Topic/ATL%20Window%20Classes.md)