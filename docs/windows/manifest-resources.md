---
title: "Recursos de manifesto | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "recursos de manifesto"
  - "recursos [Visual Studio], manifesto"
ms.assetid: 8615334c-22a0-44c0-93e0-5924528c9917
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Recursos de manifesto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recursos do manifesto são arquivos XML que descrevem as dependências que um aplicativo usa. Por exemplo, no Visual Studio, o arquivo de manifesto gerado pelo assistente MFC define quais o controle comum do Windows DLLs o aplicativo deve usar, versão 5.0 ou 6.0:  
  
```  
<description>Your app description here</description>   
<dependency>   
    <dependentAssembly>   
        <assemblyIdentity   
            type="win32"   
            name="Microsoft.Windows.Common-Controls"   
            version="6.0.0.0"   
            processorArchitecture="X86"   
            publicKeyToken="6595b64144ccf1df"   
            language="*"   
        />   
    </dependentAssembly>   
</dependency>   
```  
  
 Para um aplicativo do Windows XP ou Windows Vista, o recurso de manifesto não só especifica que o aplicativo usar a versão mais atual dos controles comuns do Windows \(v 6.0, como mostrado acima\), mas também oferece suporte a [Syslink controle](http://msdn.microsoft.com/library/windows/desktop/bb760706).  
  
 Para exibir a versão e digite as informações contidas em um recurso de manifesto, você pode abrir o arquivo em um visualizador XML ou no Visual Studio [Editor de texto](http://msdn.microsoft.com/pt-br/508e1f18-99d5-48ad-b5ad-d011b21c6ab1). Para obter mais informações, consulte [Abrindo um recurso de manifesto no Editor de texto do Visual Studio](../Topic/How%20to:%20Open%20a%20Manifest%20Resource.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte  [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Limitações  
 Você pode ter apenas um recurso de manifesto por módulo.  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Controles](../mfc/controls-mfc.md)   
 [Trabalhando com arquivos de recurso](../mfc/working-with-resource-files.md)