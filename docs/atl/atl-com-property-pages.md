---
title: "P&#225;gina de propriedades ATL COM | Microsoft Docs"
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
  - "objetos COM da ATL"
  - "páginas de propriedades da ATL"
  - "objetos COM, ATL"
  - "páginas de propriedades do COM"
  - "páginas de propriedade, ATL"
  - "páginas de propriedade, COM"
ms.assetid: 663c7caa-2e5e-4b5c-b8ea-fd434ceb1654
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;gina de propriedades ATL COM
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As páginas de propriedades COM fornece uma interface de usuário para definir as propriedades \(ou chamar os métodos\) de um ou mais objetos COM.  As páginas de propriedades são usadas amplamente por controles ActiveX fornecendo as interfaces ricas de usuário que permite que as propriedades do controle sejam definidas em tempo de design.  
  
 As páginas de propriedades são objetos COM que implementam a interface de [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) ou de [IPropertyPage2](http://msdn.microsoft.com/library/windows/desktop/ms683996) .  Essas classes fornecem métodos que permitem que a página está associada com `site` \(um objeto COM que representa o contêiner da página\) e um número *de objetos* \(COM objetos cujos métodos serão chamados em resposta a alterações feitas pelo usuário da página de propriedades\).  O contêiner da página de propriedades é responsável por chamar métodos na interface da página de propriedades para informar a página quando mostrar ou ocultar sua interface do usuário, e quando aplicar as alterações feitas pelo usuário para objetos subjacentes.  
  
 Cada página de propriedades pode ser compilada completamente independentemente dos objetos cujas propriedades podem ser definidas.  Tudo o que uma página de propriedades precisa compreender é uma interface específica \(ou conjunto de interfaces\) e fornecer uma interface de usuário para chamar métodos na interface.  
  
 Para obter mais informações, consulte [folhas e páginas de propriedades de propriedade](http://msdn.microsoft.com/library/windows/desktop/ms686577) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Nesta seção  
 [especificando páginas de propriedades](../atl/specifying-property-pages.md)  
 Lista as etapas para especificar páginas de propriedades para o controle e mostra uma classe de exemplo.  
  
 [implementando páginas de propriedades](../atl/implementing-property-pages.md)  
 Lista as etapas para implementar páginas de propriedades, incluindo métodos para substituir.  Conduz você com um exemplo completo com base no programa de exemplo ATLPages.  
  
## Seções relacionadas  
 [exemplo de ATLPages](../top/visual-cpp-samples.md)  
 O sumário de exemplo para o exemplo de ATLPages, que implementa uma página de propriedades usando `IPropertyPageImpl`.  
  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando a biblioteca ativa do modelo.  
  
## Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)