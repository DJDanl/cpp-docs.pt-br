---
title: "Personalizando assistentes do C++ com fun&#231;&#245;es JScript comuns | Microsoft Docs"
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
  - "métodos JScript de assistente, criando assistentes C++"
ms.assetid: c602978f-a2c4-462f-85c3-50b5897bec46
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Personalizando assistentes do C++ com fun&#231;&#245;es JScript comuns
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você cria um projeto do assistente com o  [Assistente personalizada](../ide/creating-a-custom-wizard.md), seu projeto inclui Common.js.  Se você especificar uma interface de usuário do assistente, o projeto também contém páginas HTML que especifique a linguagem de script de JScript e incluam o arquivo Common.js, da seguinte maneira:  
  
```  
<SCRIPT ID="INCLUDE_COMMON" LANGUAGE ="JSCRIPT"></SCRIPT>  
```  
  
 O assistente também criará um arquivo exclusivo, chamado Default. js.  Você pode personalizar suas próprias funções de JScript em Default. js.  Consulte  [O arquivo JScript](../ide/jscript-file.md) para obter mais informações.  
  
 Common.js contém funções que podem ser chamados de páginas em HTML do cada assistente e de default. js.  Se você tiver as mesmas funções que você gostaria de usar através de assistentes diferentes, você pode colocar essas funções no Common.js.  
  
## Consulte também  
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)