---
title: Atribuindo teclas de acesso a comandos de Menu | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 27291689e3fbfb9418d783917f59ffeee7a54235
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="assigning-access-keys-to-menu-commands"></a>Atribuindo teclas de acesso a comandos do menu
Você pode atribuir uma chave de acesso (um mnemônico que permite ao usuário selecionar o menu com o teclado) para seus menus e comandos de menu.  
  
### <a name="to-assign-an-access-shortcut-key-to-a-menu-command"></a>Para atribuir uma chave de acesso (atalho) a um comando de menu  
  
1.  Digite um e comercial (**&**) na frente de uma letra no nome do menu ou nome de comando para especificar essa letra como a chave de acesso correspondente. Por exemplo "& de arquivo" conjuntos ALT + F, como a tecla de atalho para o menu arquivo em aplicativos gravados para o Microsoft Windows.  
  
     O item de menu fornecem uma indicação visível de que uma das letras tem uma tecla de atalho atribuída a ele. A seguinte letra que o e comercial aparecerá sublinhado (dependendo do sistema operacional).  
  
    > [!NOTE]
    >  Verifique se todas as chaves de acesso em um menu são exclusivas clicando duas vezes seu menu e selecionando **verificar mnemônico** no menu de atalho.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](https://msdn.microsoft.com/library/f45fce5x.aspx) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](https://msdn.microsoft.com/library/xbx3z216.aspx). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](https://msdn.microsoft.com/library/h6270d0z.aspx).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de Menu](../windows/menu-editor.md)