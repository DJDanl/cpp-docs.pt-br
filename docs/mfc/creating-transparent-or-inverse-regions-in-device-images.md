---
title: "Criando regi&#245;es transparentes ou inversas em imagens de dispositivo (editor de imagens para &#237;cones) | Microsoft Docs"
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
  - "C++"
helpviewer_keywords: 
  - "cores [C++], Editor de imagem"
  - "cursores [C++], regiões da tela"
  - "cursores [C++], regiões transparentes"
  - "projetos de dispositivo, imagens transparentes"
  - "dispositivos de exibição, regiões transparentes e da tela"
  - "ícones [C++], regiões da tela"
  - "ícones [C++], regiões transparentes"
  - "Editor de imagem [C++], imagens de dispositivo"
  - "inverter cores, imagens de dispositivo"
  - "inverter regiões, imagens de dispositivo"
  - "regiões, inverter"
  - "regiões, transparente"
  - "cores da tela"
  - "transparência, imagens de dispositivo"
  - "regiões transparentes em dispositivos"
  - "regiões transparentes, imagens de dispositivo"
ms.assetid: a994954b-b039-4391-a535-58d1fa10fc3b
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando regi&#245;es transparentes ou inversas em imagens de dispositivo (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No  [editor de imagens](../mfc/image-editor-for-icons.md), a imagem do ícone ou cursor inicial tem um atributo de transparente.  Embora as imagens de ícone e cursor retangulares, muitos não aparecem isso porque partes da imagem são transparentes; a imagem subjacente na tela mostra através do ícone ou o cursor.  Quando você arrasta um ícone, partes da imagem podem aparecer em uma cor invertida.  Criar esse efeito definindo as cores da tela e inverso no  [janela de cores](../Topic/Colors%20Window%20\(Image%20Editor%20for%20Icons\).md).  
  
 As cores da tela e o inverso é aplicar a ícones e cursores em forma e a imagem derivada de cores ou designar regiões inversas.  As cores indicam partes da imagem que possuam esses atributos.  Você pode alterar as cores que representam os atributos de cor da tela e cores inverso no modo de edição.  Essas alterações não afetam a aparência do cursor em seu aplicativo ou ícone.  
  
> [!NOTE]
>  As caixas de diálogo e comandos de menu demonstradas podem ser diferentes daqueles descritos na Ajuda, dependendo das configurações ativas ou configurações de edição.  Para alterar as configurações, escolha  **Import and Export Settings** sobre o  **Ferramentas** menu.  Para obter mais informações, consulte [Customizing Development Settings in Visual Studio](http://msdn.microsoft.com/pt-br/22c4debb-4e31-47a8-8f19-16f328d7dcd3).  
  
### Para criar áreas transparentes ou inversas  
  
1.  No  **cores** janela, clique no  **Cor da tela** seletor ou o  **Cores inverso** seletor.  
  
2.  Aplique a tela ou cores invertidas para sua imagem usando uma ferramenta de desenho.  Para obter mais informações sobre ferramentas de desenho, consulte [Usando uma ferramenta de desenho](../mfc/using-a-drawing-tool-image-editor-for-icons.md).  
  
### Para alterar a cor da tela ou inverso  
  
1.  Selecione o  **Cor da tela** seletor ou o  **Cores inverso** seletor.  
  
2.  Escolha uma cor a  **cores** paleta na  **cores** janela.  
  
     A cor complementar é designada automaticamente para o outro seletor.  
  
    > [!TIP]
    >  Se você clicar duas vezes no seletor de cor da tela ou cores inverso, o  [caixa de diálogo Seletor de cores personalizado](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md) é exibida.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Nenhum  
  
## Consulte também  
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../mfc/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)