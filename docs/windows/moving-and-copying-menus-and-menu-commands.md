---
title: Movendo e copiando Menus e comandos de Menu | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- commands, copying on menus
- menu items, moving
- commands, moving on menus
- menu items, copying
ms.assetid: 1d8df535-9922-4579-a9c2-37aeac1856eb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0da935ebdce7de61d5ed6b1a816f87b7cef7ce98
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33878431"
---
# <a name="moving-and-copying-menus-and-menu-commands"></a>Movendo e copiando menus e comandos de menu
Você pode mover ou copiar menus e comandos de menu usando o método de arrastar e soltar ou usando os comandos no menu de atalho (menu de atalho).  
  
### <a name="to-move-or-copy-menus-or-menu-commands-using-the-drag-and-drop-method"></a>Para mover ou copiar menus ou comandos de menu usando o método de arrastar e soltar  
  
1.  Arrastar ou copiar o item que você deseja mover para:  
  
    -   Um novo local no menu atual.  
  
    -   Um menu diferente. (Você pode navegar para outros menus arrastando o ponteiro do mouse sobre eles.)  
  
2.  Cancelar o comando de menu quando o guia de inserção mostra a posição em que você deseja.  
  
### <a name="to-move-or-copy-menus-or-menu-commands-using-shortcut-menu-commands"></a>Para mover ou copiar menus ou comandos de menu usando comandos de menu de atalho  
  
1.  Um ou mais menus ou comandos de menu de atalho.  
  
2.  No menu de atalho, escolha **Recortar** (para mover) ou **cópia**.  
  
3.  Se você estiver movendo os itens de menu de outro recurso ou arquivo de script de recurso, [abri-lo em outra janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio).  
  
4.  Selecione a posição do menu ou comando de menu que você deseja mover ou copiar.  
  
5.  No menu de atalho, escolha **colar**. O item movido ou copiado é colocado antes do item selecionado.  
  
    > [!NOTE]
    >  Você também pode arrastar, copiar e colar a outros menus em outras janelas do menu.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acesso a recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, e [passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de Menu](../windows/menu-editor.md)