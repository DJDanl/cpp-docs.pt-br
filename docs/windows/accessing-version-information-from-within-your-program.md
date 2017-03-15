---
title: "Acessando informa&#231;&#245;es de vers&#227;o a partir do programa | Microsoft Docs"
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
  - "vc.editors.version"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "VerQueryValue"
  - "informações de versão, acessando a partir de programas"
  - "GetFileVersionInfo"
  - "informações de versão"
ms.assetid: 18622333-d9e8-4309-9465-677cd10c79b1
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acessando informa&#231;&#245;es de vers&#227;o a partir do programa
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para acessar informações de versão a partir do seu programa  
  
1.  Se você quiser acessar as informações de versão do seu programa, use o [GetFileVersionInfo](http://msdn.microsoft.com/library/windows/desktop/ms647003.aspx) função e o [VerQueryValue](http://msdn.microsoft.com/library/windows/desktop/ms647464.aspx) função.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Editor de informações da versão](../mfc/version-information-editor.md)   
 [Informações de versão \(Windows\)](https://msdn.microsoft.com/library/windows/desktop/ms646981.aspx)