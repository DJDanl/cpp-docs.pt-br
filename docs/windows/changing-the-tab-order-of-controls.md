---
title: Alterando a ordem de tabulação dos controles | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], tab order
- focus, tab order
- tab controls [C++], tab order
- Tabstop property for controls
- controls [C++], focus
- dialog box controls [C++], tab order
ms.assetid: e2cee764-4367-42d7-9563-65a68f76f5ff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 822e0c5ac0232ac30e4db63b3605fda0126959de
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46434590"
---
# <a name="changing-the-tab-order-of-controls"></a>Alterando a ordem de guia dos controles

A ordem de tabulação é a ordem na qual o **guia** tecla move o foco de entrada de um controle para o próximo dentro de uma caixa de diálogo. Normalmente, a ordem de tabulação prossegue da esquerda para a direita e de cima para baixo em uma caixa de diálogo. Cada controle tem um **Tabstop** propriedade que determina se um controle recebe foco de entrada.

### <a name="to-set-input-focus-for-a-control"></a>Para definir o foco de entrada para um controle

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), selecione **verdadeiro** ou **False** no **Tabstop** propriedade.

Até mesmo os controles que não têm o **Tabstop** propriedade definida como **verdadeiro** precisam fazer parte da ordem de tabulação. Isso pode ser importante, por exemplo, quando você [definir chaves de acesso (mnemônicos)](../windows/defining-mnemonics-access-keys.md) para controles que não têm legendas. Texto estático que contém uma chave de acesso para um controle relacionada deve preceder imediatamente o controle relacionado na ordem de tabulação.

> [!NOTE]
> Se a caixa de diálogo contém controles sobrepostos, alterando a ordem de tabulação pode alterar a maneira como os controles são exibidos. Controles que acompanham a ordem de tabulação são sempre exibidos na parte superior de todos os controles sobrepostos que precedem-os na ordem de tabulação.

### <a name="to-view-the-current-tab-order-for-all-controls-in-a-dialog-box"></a>Para exibir a ordem de tabulação para todos os controles em uma caixa de diálogo

1. Sobre o **formato** menu, clique em **ordem de tabulação**.

\- ou -

- Pressione **Ctrl**+**1!d**.

### <a name="to-change-the-tab-order-for-all-controls-in-a-dialog-box"></a>Para alterar a ordem de tabulação para todos os controles em uma caixa de diálogo

1. Sobre o **formato** menu, clique em **ordem de tabulação**.

   Um número no canto superior esquerdo de cada controle mostra seu lugar na ordem de tabulação atual.

2. Definir a ordem de tabulação, clicando em cada controle na ordem em que você deseja que o **guia** chave a seguir.

3. Pressione **Enter** para sair **ordem de tabulação** modo.

   > [!TIP]
   > Depois de digitar **ordem de tabulação** modo, você pode pressionar **Esc** ou **Enter** para desabilitar a capacidade de alterar a ordem de tabulação.

### <a name="to-change-the-tab-order-for-two-or-more-controls"></a>Para alterar a ordem de tabulação para dois ou mais controles

1. Dos **formato** menu, escolha **ordem de tabulação**.

2. Especifique onde começará a alteração na ordem. Para fazer isso, mantenha pressionada a **Ctrl** da chave e clique no controle antes daquele onde você deseja que a ordem alterada para começar.

   Por exemplo, se você quiser alterar a ordem dos controles `7` por meio `9`, mantenha pressionada **Ctrl**, em seguida, selecione o controle `6` primeiro.

   > [!NOTE]
   > Para definir um controle específico para número `1` (primeiro na ordem de tabulação), clique duas vezes no controle.

3. Versão do **Ctrl** da chave, em seguida, clicar nos controles na ordem em que você deseja o **guia** chave a serem seguidos a partir desse ponto.

4. Pressione **Enter** para sair **ordem de tabulação** modo.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Organização de controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md)<br/>
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)