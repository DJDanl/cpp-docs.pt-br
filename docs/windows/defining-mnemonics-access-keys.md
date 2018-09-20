---
title: Definindo a mnemônica (teclas de acesso) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- access keys [C++], adding
- keyboard shortcuts [C++], controls
- dialog box controls [C++], mnemonics
- access keys [C++], checking
- mnemonics [C++], checking for duplicate
- mnemonics
- mnemonics [C++], dialog box controls
- keyboard shortcuts [C++], uniqueness checking
- Check Mnemonics command
- controls [C++], access keys
- access keys [C++]
ms.assetid: 60a85435-aa30-4c5c-98b6-42fb045b9eb2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6d707b0205c3f13954681eb4f6a033496a2997ce
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46425782"
---
# <a name="defining-mnemonics-access-keys"></a>Definindo mnemônica (teclas de acesso)

Normalmente, os usuários de teclado movem o foco de entrada de um controle para outro em uma caixa de diálogo com o **guia** e **seta** chaves. No entanto, você pode definir uma chave de acesso (um nome mnemônico ou fácil de lembrar) que permite aos usuários escolher um controle pressionando uma tecla única.

### <a name="to-define-an-access-key-for-a-control-with-a-visible-caption-push-buttons-check-boxes-and-radio-buttons"></a>Para definir uma chave de acesso para um controle com uma legenda visível (botões de ação, caixas de seleção e botões de opção)

1. Selecione o controle na caixa de diálogo.

2. No [janela de propriedades](/visualstudio/ide/reference/properties-window), no **legenda** propriedade, digite um novo nome para o controle, digitando um e comercial (`&`) na frente da letra que você deseja como a chave de acesso para o controle. Por exemplo, `&Radio1`.

3. Pressione **ENTER**.

   Um sublinhado será exibido na legenda exibida para indicar a chave de acesso, por exemplo, **R**adio1.

### <a name="to-define-an-access-key-for-a-control-without-a-visible-caption"></a>Para definir uma chave de acesso para um controle sem uma legenda visível

1. Faça uma legenda para o controle, usando um **texto estático** no controlar a [caixa de ferramentas](/visualstudio/ide/reference/toolbox).

2. Na legenda de texto estático, digite um e comercial (`&`) na frente da letra que você deseja como a chave de acesso.

3. Verifique se o controle de texto estático que precede o controle rotula na ordem de tabulação.

Todas as chaves de acesso dentro de uma caixa de diálogo devem ser exclusivas.

### <a name="to-check-for-duplicate-access-keys"></a>Para verificar se há teclas de acesso duplicadas

1. Sobre o **formato** menu, clique em **Verificar mnemônicos**.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)