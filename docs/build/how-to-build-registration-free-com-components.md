---
title: "Como compilar componentes COM sem registro | Microsoft Docs"
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
  - "componentes COM, sem registro"
ms.assetid: 7e585d6a-0314-45b2-8f1b-cae9ac4df037
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como compilar componentes COM sem registro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os componentes COM interfaces são livres os componentes COM que têm os manifestos criados na DLL.  
  
### Para criar manifestos em componentes COM  
  
1.  Abrir as páginas de propriedades do projeto para o componente COM.  
  
2.  Expanda o nó de **Propriedades de Configuração** , e expanda o nó de **Ferramenta de Manifesto** .  
  
3.  Selecione a página de propriedades de **Entrada e Saída** , e defina a propriedade de **Inserir Manifesto** igual a **Sim**.  
  
4.  Clique em **OK**.  
  
5.  Crie a solução.  
  
## Consulte também  
 [Aplicativos isolados](http://msdn.microsoft.com/library/aa375190)   
 [Assemblies lado a lado](_win32_side_by_side_assemblies)   
 [Como compilar aplicativos isolados para consumir componentes COM](../Topic/How%20to:%20Build%20Isolated%20Applications%20to%20Consume%20COM%20Components.md)