---
title: Definindo mnemônica (teclas de acesso) | Microsoft Docs
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
- dialog box controls, mnemonics
- access keys [C++], checking
- mnemonics, checking for duplicate
- mnemonics
- mnemonics, dialog box controls
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
ms.openlocfilehash: a60cf597a88fcf7038848be6c9e2d31269f6a906
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33873687"
---
# <a name="defining-mnemonics-access-keys"></a>Definindo mnemônica (teclas de acesso)
Normalmente, os usuários de teclado mover o foco de entrada de um controle para outro em uma caixa de diálogo com as teclas TAB e de direção. No entanto, você pode definir uma chave de acesso (um mnemônico ou fácil de lembrar nome) que permite aos usuários escolher um controle pressionando uma única chave.  
  
### <a name="to-define-an-access-key-for-a-control-with-a-visible-caption-push-buttons-check-boxes-and-radio-buttons"></a>Para definir uma chave de acesso para um controle com uma legenda visível (botões de ação, caixas de seleção e botões de opção)  
  
1.  Selecione o controle na caixa de diálogo.  
  
2.  No [janela propriedades](/visualstudio/ide/reference/properties-window), no **legenda** propriedade, digite um novo nome para o controle digitando um e comercial (**&**) na frente da letra que você deseja que o chave de acesso para o controle. Por exemplo, `&Radio1`.  
  
3.  Pressione **ENTER**.  
  
     Um sublinhado aparece na legenda exibida para indicar a chave de acesso, por exemplo, **R**adio1.  
  
### <a name="to-define-an-access-key-for-a-control-without-a-visible-caption"></a>Para definir uma chave de acesso para um controle sem uma legenda visível  
  
1.  Faça uma legenda para o controle, usando um **texto estático** controlar o [caixa de ferramentas](/visualstudio/ide/reference/toolbox).  
  
2.  A legenda de texto estático, digite um e comercial (**&**) na frente da letra que você deseja como a chave de acesso.  
  
3.  Verifique se o controle de texto estático que precede o controle rotula na ordem de tabulação.  
  
 Todas as chaves de acesso dentro de uma caixa de diálogo devem ser exclusivas.  
  
#### <a name="to-check-for-duplicate-access-keys"></a>Para verificar se há chaves de acesso duplicados  
  
1.  Sobre o **formato** menu, clique em **verificar mnemônico**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
### <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)

