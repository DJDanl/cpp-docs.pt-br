---
title: "Alterando a ordem de tabulação dos controles | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- controls [C++], tab order
- focus, tab order
- tab controls, tab order
- Tabstop property for controls
- controls [C++], focus
- dialog box controls, tab order
ms.assetid: e2cee764-4367-42d7-9563-65a68f76f5ff
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dca6b1bb894aa2219a0352ba9c359e6f3c5a4677
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changing-the-tab-order-of-controls"></a>Alterando a ordem de guia dos controles
A ordem de tabulação é a ordem na qual a tecla TAB move o foco de entrada de um controle para o próximo dentro de uma caixa de diálogo. Normalmente, a ordem de tabulação continua da esquerda para a direita e de cima para baixo na caixa de diálogo. Cada controle tem um **Tabstop** propriedade que determina se um controle recebe foco de entrada.  
  
### <a name="to-set-input-focus-for-a-control"></a>Para definir o foco de entrada para um controle  
  
1.  No [janela propriedades](/visualstudio/ide/reference/properties-window), selecione **True** ou **False** no **Tabstop** propriedade.  
  
 Controles mesmo que não tem a propriedade de parada de tabulação definida como True precisam ser parte da ordem de tabulação. Isso pode ser importante, por exemplo, quando você [definir chaves de acesso (mnemônico)](../windows/defining-mnemonics-access-keys.md) para controles que não têm legendas. Texto estático que contém uma chave de acesso para um controle relacionado deve preceder imediatamente o controle relacionado na ordem de tabulação.  
  
> [!NOTE]
>  Se a caixa de diálogo contém controles sobrepostos, alterando a ordem de tabulação pode alterar o modo como os controles são exibidos. Controles que são fornecidos posteriormente na ordem de tabulação são sempre exibidos na parte superior de quaisquer controles sobrepostos que precedem-os na ordem de tabulação.  
  
#### <a name="to-view-the-current-tab-order-for-all-controls-in-a-dialog-box"></a>Para exibir a ordem de tabulação para todos os controles em uma caixa de diálogo  
  
1.  Sobre o **formato** menu, clique em **ordem de tabulação**.  
  
 \- ou -  
  
-   Pressione CTRL + D.  
  
#### <a name="to-change-the-tab-order-for-all-controls-in-a-dialog-box"></a>Para alterar a ordem de tabulação para todos os controles em uma caixa de diálogo  
  
1.  Sobre o **formato** menu, clique em **ordem de tabulação**.  
  
     Um número no canto superior esquerdo de cada controle mostra seu lugar na ordem de tabulação atual.  
  
2.  Defina a ordem de tabulação, clicando em cada controle na ordem em que você deseja que a tecla TAB para seguir.  
  
3.  Pressione **ENTER** para sair **ordem de tabulação** modo.  
  
    > [!TIP]
    >  Depois que você entra no modo de ordem de tabulação, você pode pressionar ESC ou ENTER para desabilitar a capacidade de alterar a ordem de tabulação.  
  
#### <a name="to-change-the-tab-order-for-two-or-more-controls"></a>Para alterar a ordem de tabulação para dois ou mais controles  
  
1.  Do **formato** menu, escolha **ordem de tabulação**.  
  
2.  Especifique onde a alteração na ordem será iniciado. Para fazer isso, mantenha pressionada a **CTRL** chave e clique no controle antes do um onde você deseja que a ordem alterada para começar.  
  
     Por exemplo, se você quiser alterar a ordem dos controles de 7 a 9, mantenha pressionada a tecla CTRL e selecione o controle 6 pela primeira vez.  
  
    > [!NOTE]
    >  Para definir um controle específico para o número 1 (primeiro na ordem de tabulação), clique duas vezes no controle.  
  
3.  Solte a tecla CTRL e clique em controles na ordem em que você deseja que a tecla TAB para seguir a partir desse ponto.  
  
4.  Pressione **ENTER** para sair **ordem de tabulação** modo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
### <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Organização dos controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md)   
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)

