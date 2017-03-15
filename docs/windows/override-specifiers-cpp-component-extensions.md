---
title: "Substituir especificadores (extens&#245;es de componentes C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Substituir especificadores, Visual C++"
  - "especificadores de substituição"
ms.assetid: 155bbf6f-4722-4654-afb1-9cb52af799fb
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Substituir especificadores (extens&#245;es de componentes C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*Especificadores de substituição* modificam a forma como tipos e membros herdados de tipos herdados se comportam em tipos derivados.  
  
## Todos os Tempos de Execução  
 **Comentários**  
  
 Para obter mais informações sobre especificadores de substituição, consulte:  
  
-   [abstrata](../windows/abstract-cpp-component-extensions.md)  
  
-   [novo \(novo slot em vtable\)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)  
  
-   [override](../windows/override-cpp-component-extensions.md)  
  
-   [autenticada](../windows/sealed-cpp-component-extensions.md)  
  
-   [Especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md)  
  
 `abstract` e `sealed` também são válidos em declarações de tipo, onde não atuam como especificadores de substituição.  
  
 Para obter informações sobre a substituição explícita de funções de classe base, consulte [Substituições explícitas](../windows/explicit-overrides-cpp-component-extensions.md).  
  
## Tempo de execução do windows  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica somente Tempo de Execução do Windows\).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica somente ao common language runtime\).  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)