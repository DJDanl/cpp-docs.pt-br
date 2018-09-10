---
title: Criando um Menu (C++) | Microsoft Docs
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
- mnemonics [C++], associating menu items
- menus [C++], associating commands with mnemonic keys
- menus [C++], creating
ms.assetid: 66f94448-9b97-4b73-bf97-10d4bf87cc65
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 59689abec68fc6cff2a742bd4db97b58cd023af1
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44316257"
---
# <a name="creating-a-menu-c"></a>Criando um Menu (C++)

> [!NOTE]
> O **janela recursos** não está disponível nas edições Express.

### <a name="to-create-a-standard-menu"></a>Criar um menu padrão

1. Do **modo de exibição** menu, clique em **exibição de recurso** e, em seguida, clique duas vezes no **Menu** título e escolha **adicionar recurso**. Escolher **Menu**.

2. Selecione o **Novo Item** caixa (o retângulo que contém "Digite aqui") na barra de menus.

   ![Caixa de novo Item no editor de menu](../windows/media/vcmenueditornewitembox.gif "vcMenuEditorNewItemBox")  
Caixa de novo Item

3. Digite um nome para o novo menu, por exemplo, "Arquivo".

   O texto digitado aparece em ambas a **Menu** editor e, na **legenda** caixa a [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode editar as propriedades para o novo menu em qualquer local.

   Depois de você ter recebe um nome de seu novo menu na barra de menus, caixa novo item desloca para a direita (para permitir que você adicione outro menu) e outra caixa do novo item é aberta abaixo do menu do seu primeiro para que você possa adicionar comandos de menu a ele.

   ![Caixa de novo Item expandida](../windows/media/vcmenueditornewitemboxexpanded.gif "vcMenuEditorNewItemBoxExpanded")  
Depois de digitar o nome do Menu deslocados para a caixa de novo Item com foco

   > [!NOTE]
   > Para criar um único item de menu na barra de menus, defina as **pop-up** propriedade **falso**.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de Menu](../windows/menu-editor.md)