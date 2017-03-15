---
title: "SetNoPchSettings | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "SetNoPchSettings"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetNoPchSettings"
ms.assetid: 52373c98-ad5e-4e9b-9e0f-9f58ddb2a636
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SetNoPchSettings
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Configura propriedades de configuração do projeto quando não há cabeçalho pré\-compilado é usado.  
  
## Sintaxe  
  
```  
  
      function SetNoPchSettings(   
   oProj    
);  
```  
  
#### Parâmetros  
 `oProj`  
 O projeto selecionado.  
  
## Comentários  
 Chame essa função para configurar o projeto quando o projeto não utiliza nenhuma configuração de cabeçalho pré\-compilado.  
  
## Exemplo  
 Consulte  [SetCommonPchSettings](../ide/setcommonpchsettings.md).  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [SetCommonPchSettings](../ide/setcommonpchsettings.md)   
 [AddCommonConfig](../ide/addcommonconfig.md)