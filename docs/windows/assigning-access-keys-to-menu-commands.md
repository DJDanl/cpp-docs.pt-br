---
title: "Atribuindo teclas de acesso a comandos do menu | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "verificação de chaves de acesso [C++]"
  - "menus, teclas de atalho"
  - "atalhos de teclado [C++], atribuições de comandos"
  - "atribuição de chaves de acesso [C++]"
  - "mnemônicos, adicionando a menus"
  - "[C++], atalhos de teclado verificação de exclusividade"
  - "mnemônicos, verificação de exclusividade"
  - "Comando Verificar Mnemônico"
ms.assetid: fbcf1a00-af6a-4171-805a-0ac01d4e8b0d
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atribuindo teclas de acesso a comandos do menu
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode atribuir uma chave de acesso \(um mnemônico que permite que o usuário selecione o menu com o teclado\) para seus menus e comandos de menu.  
  
### Para atribuir uma chave de acesso \(atalho\) a um comando de menu  
  
1.  Digite um e comercial \(**&**\) na frente de uma letra no nome do menu ou nome de comando para especificar essa letra como a chave de acesso correspondente. Por exemplo "& arquivo" conjuntos ALT \+ F, como teclas de atalho do menu arquivo em aplicativos escritos para Microsoft Windows.  
  
     O item de menu fornecerá uma indicação visível de uma das letras com uma tecla de atalho atribuída a ele. O seguinte letra que o e comercial será exibido sublinhado \(dependendo do sistema operacional\).  
  
    > [!NOTE]
    >  Verifique se todas as chaves de acesso em um menu são exclusivas clicando seu menu e escolhendo **Verificar mnemônico** no menu de atalho.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Editor de menu](../Topic/Menu%20Editor.md)