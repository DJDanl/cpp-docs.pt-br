---
title: Editando vários Menus ou comandos de Menu (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- menu commands [C++], selecting
- menus [C++], selecting
- commands [C++], menu commands
- commands [C++], copying on menus
- menu items, moving
- commands [C++], moving on menus
- menu items, copying
- menu items, deleting
- commands [C++], deleting from menus
- menus [C++], deleting
ms.assetid: b6f17897-2a40-4afd-97d4-a38b7661680b
ms.openlocfilehash: 45e2c4e97dc850b4d6fb13a5526911e4bd5caec2
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55703214"
---
# <a name="editing-multiple-menus-or-menu-commands"></a>Editando vários Menus ou comandos de Menu

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-select-multiple-menu-commands"></a>Para selecionar vários comandos de menu

Você pode selecionar vários nomes de menus ou comandos de menu para executar operações em massa como excluindo ou alterando as propriedades.

Enquanto mantém pressionada a **Ctrl** da chave, selecione os menus ou comandos do submenu desejado.

## <a name="to-move-and-copy-menus-and-menu-commands"></a>Mover e copiar os menus e comandos de menu

Você pode mover ou copiar os menus e comandos de menu usando o método de arrastar e soltar ou usando comandos no menu de atalho (menu de atalho).

### <a name="to-move-or-copy-menus-or-menu-commands-using-the-drag-and-drop-method"></a>Para mover ou copiar menus ou comandos de menu usando o método de arrastar e soltar

1. Arrastar ou copiar o item que você deseja mover para:

   - Um novo local no menu atual.

   - Um menu diferente. (Você pode navegar para outros menus, arrastando o ponteiro do mouse sobre eles.)

1. Cancelar o comando de menu quando o guia de inserção mostra a posição desejada.

### <a name="to-move-or-copy-menus-or-menu-commands-using-shortcut-menu-commands"></a>Para mover ou copiar menus ou comandos de menu usando comandos de menu de atalho

1. Um ou mais menus ou comandos de menu de atalho.

1. No menu de atalho, escolha **Recortar** (para mover) ou **cópia**.

1. Se você estiver movendo os itens para outro menu recurso ou o arquivo de script de recurso [abri-lo em outra janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

1. Selecione a posição do menu ou comando de menu que você deseja mover ou copiar para.

1. No menu de atalho, escolha **colar**. O item movido ou copiado é colocado antes do item selecionado.

   > [!NOTE]
   > Você também pode arrastar, copie e cole a outros menus em outras janelas do menu.

## <a name="to-delete-a-menu-or-menu-command"></a>Para excluir um menu ou um comando de menu

1. O comando ou o nome do menu de atalho.

1. Escolher **excluir** no menu de atalho.

   > [!NOTE]
   > Da mesma forma, você pode usar o menu de atalho para realizar outras ações como copiar, recortar, colar, inserir novas, separador de inserir, editar IDs, modo de exibição como pop-up, verificar mnemônicos, etc.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de Menu](../windows/menu-editor.md)