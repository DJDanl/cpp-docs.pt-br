---
title: Atribuindo teclas de acesso a comandos de Menu | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- access keys [C++], checking
- menus, shortcut keys
- keyboard shortcuts [C++], command assignments
- access keys [C++], assigning
- mnemonics, adding to menus
- keyboard shortcuts [C++], uniqueness checking
- mnemonics, uniqueness checking
- Check Mnemonics command
ms.assetid: fbcf1a00-af6a-4171-805a-0ac01d4e8b0d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 44a21e5930d0d8f2fcaad79cc5cef5bc984ad8b5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33857893"
---
# <a name="assigning-access-keys-to-menu-commands"></a>Atribuindo teclas de acesso a comandos do menu
Você pode atribuir uma chave de acesso (um mnemônico que permite ao usuário selecionar o menu com o teclado) para seus menus e comandos de menu.  
  
### <a name="to-assign-an-access-shortcut-key-to-a-menu-command"></a>Para atribuir uma chave de acesso (atalho) a um comando de menu  
  
1.  Digite um e comercial (**&**) na frente de uma letra no nome do menu ou nome de comando para especificar essa letra como a chave de acesso correspondente. Por exemplo "& de arquivo" conjuntos ALT + F, como a tecla de atalho para o menu arquivo em aplicativos gravados para o Microsoft Windows.  
  
     O item de menu fornecem uma indicação visível de que uma das letras tem uma tecla de atalho atribuída a ele. A seguinte letra que o e comercial aparecerá sublinhado (dependendo do sistema operacional).  
  
    > [!NOTE]
    >  Verifique se todas as chaves de acesso em um menu são exclusivas clicando duas vezes seu menu e selecionando **verificar mnemônico** no menu de atalho.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de Menu](../windows/menu-editor.md)