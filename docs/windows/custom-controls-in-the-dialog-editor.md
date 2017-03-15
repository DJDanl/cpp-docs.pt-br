---
title: "Controles personalizados no Editor de Caixa de Di&#225;logo | Microsoft Docs"
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
  - "Custom Control"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles [C++], modelos"
  - "controles personalizados [Visual Studio]"
  - "controles personalizados [Visual Studio], caixas de diálogo"
  - "controles de caixas de diálogo, controles personalizados (usuário)"
  - "Editor de caixa de diálogo, controles personalizados"
ms.assetid: f494b314-4000-4bbe-bbd0-4b18fb71ede1
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles personalizados no Editor de Caixa de Di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O editor de diálogo permite que você use existente "personalizada" ou controles de "usuário" em um modelo de caixa de diálogo.  
  
> [!NOTE]
>  Controles personalizados nesse sentido não são deve ser confundida com controles de ActiveX.  Controles de ActiveX às vezes eram chamados de controles personalizados de OLE.  Além disso, não confunda esses controles com os controles desenhados pelo proprietário no Windows.  
  
 Essa funcionalidade foi criada para permitir o uso de controles diferentes daqueles fornecidos pelo Windows.  Em tempo de execução, o controle está associado uma classe de janela \(não o mesmo que uma classe C\+\+\).  Uma maneira mais comum para realizar a mesma tarefa é instalar qualquer controle, como, por exemplo, um controle estático, na sua caixa de diálogo.  Em seguida, em tempo de execução, no  [OnInitDialog](../Topic/CDialog::OnInitDialog.md) funcionar, remova esse controle e substituí\-lo pelo seu próprio controle personalizado.  
  
 Essa é uma técnica antiga.  Hoje, você é aconselhado na maioria dos casos para escrever um controle ActiveX ou uma subclasse de um controle comum do Windows.  
  
 Para esses controles personalizados, você está limitado a:  
  
-   Definindo o local na caixa de diálogo.  
  
-   Digitando uma legenda.  
  
-   Identificando o nome da classe do Windows do controle \(o código do seu aplicativo deve registrar o controle com este nome\).  
  
-   Digitando um valor hexadecimal de 32 bits que define o estilo do controle.  
  
-   Definindo o estilo estendido.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Controles em caixas de diálogo](../mfc/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)