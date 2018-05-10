---
title: Criando um Menu | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.menu
dev_langs:
- C++
helpviewer_keywords:
- mnemonics, associating menu items
- menus, associating commands with mnemonic keys
- menus, creating
ms.assetid: 66f94448-9b97-4b73-bf97-10d4bf87cc65
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 95d9051e44216de9a64b68fc112fe8f17de112e3
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="creating-a-menu"></a>Criando um menu
> [!NOTE]
>  A janela de recurso não está disponível em edições Express.  
  
### <a name="to-create-a-standard-menu"></a>Criar um menu padrão  
  
1.  Do **exibição** menu, clique na **exibição recursos** e, em seguida, clique no **Menu** título e escolha **adicionar recurso**. Escolha **Menu**.  
  
2.  Selecione o **Novo Item** caixa (o retângulo que contém "Digite aqui") na barra de menus.  
  
     ![Caixa de novo Item no editor de menu](../windows/media/vcmenueditornewitembox.gif "vcMenuEditorNewItemBox")  
Caixa de novo Item  
  
3.  Digite um nome para o novo menu, por exemplo, "File".  
  
     O texto aparece no **Menu** editor e na **legenda** caixa o [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades para o novo menu em qualquer local.  
  
     Depois que você tiver atribuído um nome de seu novo menu na barra de menus, a caixa de novo item desloca para a direita (para permitir a adição de outro menu) e outra caixa de novo item abre abaixo de seu primeiro menu assim você pode adicionar comandos de menu a ele.  
  
     ![Caixa de novo Item expandida](../windows/media/vcmenueditornewitemboxexpanded.gif "vcMenuEditorNewItemBoxExpanded")  
Caixa de novo Item com foco alterado depois que você digitar o nome do Menu  
  
    > [!NOTE]
    >  Para criar um único item de menu na barra de menus, defina a propriedade de pop-up como False.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de Menu](../windows/menu-editor.md)