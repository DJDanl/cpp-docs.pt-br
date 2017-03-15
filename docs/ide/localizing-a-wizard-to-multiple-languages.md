---
title: "Localizando um assistente para v&#225;rios idiomas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "assistentes personalizados, localizando"
  - "globalização [C++], assistentes"
  - "localização [C++], assistentes"
  - "assistentes [C++], localizando"
ms.assetid: 879885c2-fafd-44fd-8032-bf0c301f4f45
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Localizando um assistente para v&#225;rios idiomas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar um assistente em qualquer idioma para o qual o Visual Studio oferece suporte.  Por padrão, quando você instala o Visual Studio, ele identifica a localidade do registro e fornece os modelos apropriados para essa localidade.  
  
 Visual Studio usa a linguagem de IDs para identificar o suporte de idioma que requer de um assistente.  Por padrão, a identificação de idioma é definida para o valor decimal da entrada do registro HKEY\_CURRENT\_USER\\Software\\Microsoft\\VisualStudio\\7.0\\General\\UILanguage.  Se o assistente não pode localizar nenhuma entrada de idioma, o padrão para inglês \(1033\).  
  
> [!NOTE]
>  Para obter uma lista de valores decimais de idioma, consulte  [Assistente de suporte para outros idiomas](../ide/wizard-support-for-other-languages.md).  
  
 O idioma ID é especificado como um parâmetro personalizado na. [arquivo vsz](../Topic/Configuring%20.Vsz%20Files%20to%20Start%20Wizards.md) nos caminhos onde o  [arquivos HTML](../ide/html-files.md) e o  [arquivos de modelo](../ide/template-files.md) residem.  
  
 Você deve especificar caminhos para cada idioma para o qual você fornece um arquivo. htm.  
  
## Exemplo  
 Definindo os seguintes parâmetros personalizados no arquivo vsz indicam que você esteja usando HTML em inglês \(1033\), japonês \(1041\) e alemão \(1031\):  
  
```  
Param="START_PATH\HTML\1033"  
Param="START_PATH\HTML\1041"  
Param="START_PATH\HTML\1031"  
Param="START_PATH\Templates\1033"  
Param="START_PATH\Templates\1041"  
Param="START_PATH\Templates\1031"  
```  
  
 Configuração de parâmetros personalizados acima define a estrutura de diretório do Assistente da seguinte maneira:  
  
```  
MyWizard1  
   HTML  
      1033  
         default.htm  
         myEnglishHTML.htm  
      1041  
         default.htm  
         myJapaneseHTML.htm  
      1031  
         default.htm  
         myGermanHTML.htm  
   Templates  
      1033  
         stdafx.h  
         stdafx.cpp  
      1041  
         stdafx.h  
         stdafx.cpp  
      1031  
         stdafx.h  
         stdafx.cpp  
   Images  
      HtmlPage1.bmp  
      HtmlPage2.jpg  
   Scripts  
      Default.js  
```  
  
## Consulte também  
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [Parâmetros personalizados no arquivo .Vsz do assistente](../ide/custom-parameters-in-the-wizard-dot-vsz-file.md)