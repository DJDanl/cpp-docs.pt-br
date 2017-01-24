---
title: "Criando a imagem de um dispositivo (editor de imagens para &#237;cones) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.icon"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "cursores [C++], criando"
  - "dispositivos de exibição"
  - "dispositivos de exibição, criando imagem"
  - "ícones [C++], criando"
  - "ícones [C++], inserindo"
  - "imagens [C++], criando para dispositivos de exibição"
ms.assetid: 5a536928-32df-4ace-beb1-1521ce3b871f
caps.latest.revision: 12
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando a imagem de um dispositivo (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Primeiro quando você cria um novo ícone ou o cursor do recurso, a imagem editor cria uma imagem em um estilo específico \(32 × 32, 16 cores para ícones e 32 × 32, monocromático para cursores\).  Em seguida, você pode adicionar imagens em diferentes tamanhos e estilos para o ícone inicial ou o cursor e editar cada imagem adicional, conforme necessário, para os dispositivos de exibição diferentes.  Você também pode editar uma imagem, realizando uma operação recortar e colar a partir de um tipo de imagem existente ou um bitmap criado em um programa gráfico.  Para obter mais informações sobre o ícone tamanhos que utiliza Windows, consulte  [ícones](_win32_Icons_cpp) na documentação do SDK do Windows.  
  
 Quando você abre o recurso de ícone ou o cursor no  [editor de imagens](../mfc/image-editor-for-icons.md), a imagem mais intimamente correspondência o dispositivo de vídeo atual é aberta por padrão.  
  
### Para criar um novo ícone ou o cursor  
  
1.  Em  [Exibição de recurso](../windows/resource-view-window.md), seu arquivo. rc com o botão direito e escolha  **Inserir recursos** no menu de atalho.  \(Se você já tiver um recurso de imagem existente no seu arquivo. rc, como, por exemplo, um cursor, você pode simplesmente direito a  **Cursor** pasta e selecione  **Inserir o Cursor** no menu de atalho.\)  
  
    > [!NOTE]
    >  Se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No  [caixa de diálogo Inserir recurso](../Topic/Add%20Resource%20Dialog%20Box.md), selecione  **ícone** ou  **Cursor** e clique em  **New**.  Para ícones, isso cria um recurso de ícone com um 32 × 32, o ícone de 16 cores.  Para cursores, 32 × 32, imagem de monocromática \(cor 2\) é criada.  
  
     Se um sinal de adição \(**\+**\) é exibido ao lado do tipo de recurso de imagem na  **Inserir recursos** caixa de diálogo, significa que os modelos de barra de ferramentas estão disponíveis.  Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em  **New**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Nenhum  
  
## Consulte também  
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../mfc/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)   
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../mfc/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)