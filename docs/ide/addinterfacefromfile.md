---
title: "AddInterfaceFromFile | Microsoft Docs"
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
  - "AddInterfaceFromFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AddInterfaceFromFile"
ms.assetid: fa848690-ad98-4fb4-bbcf-dffcaad05df2
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# AddInterfaceFromFile
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Processa e insere um arquivo de modelo que contém uma interface.  
  
## Sintaxe  
  
```  
  
      function AddInterfaceFromFile(   
   oCM,   
   strInterfaceFile    
);  
```  
  
#### Parâmetros  
 `oCM`  
 O [Visual C\+\+ Code Model](http://msdn.microsoft.com/pt-br/dd6452c2-1054-44a1-b0eb-639a94a1216b) objeto.  
  
 *strInterfaceFile*  
 O modelo somente nome de arquivo, excluindo o caminho.  
  
## Comentários  
 Chame essa função para processar e inserir o arquivo do projeto. idl um arquivo de modelo que contém uma interface.  
  
 Se a interface não for adicionada com êxito, esta função exibe uma mensagem de erro.  
  
## Exemplo  
  
```  
// Render myint.idl and insert into strProject.idl  
AddInterfaceFromFile(oCM, "myint.idl");  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)