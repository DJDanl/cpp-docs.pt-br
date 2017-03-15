---
title: "AddATLSupportToProject | Microsoft Docs"
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
  - "Método AddATLSupportToProject"
ms.assetid: 26708f22-1e9b-4432-83b2-ed94c765b753
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# AddATLSupportToProject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona o suporte ATL para um projeto MFC.  
  
## Sintaxe  
  
```  
  
      function AddATLSupportToProject(   
   oProj   
);  
```  
  
#### Parâmetros  
 `oProj`  
 O projeto selecionado.  
  
## Valor de retorno  
 **True** se o suporte ATL foi adicionado com êxito ao projeto MFC.  
  
## Comentários  
 Use esta função para adicionar suporte ATL para um projeto MFC criado pelo assistente.  
  
 O assistente exibe uma caixa de mensagem para confirmar a adicionar suporte ATL ao projeto MFC.  Após confirmação, o assistente verifica se há suporte existente e adiciona todos os GUIDs necessários, modelos, a cabeçalhos, e funcionalidade adicional para que o projeto MFC criado pelo assistente dá suporte ATL.  
  
## Exemplo  
  
```  
var oCM = selProj.CodeModel;  
var L_TRANSACTION_Text = "Add ATL Support To Project";  
oCM.StartTransaction(L_TRANSACTION_Text);  
var bRet = AddATLSupportToProject(selProj);  
if (bRet)  
   oCM.CommitTransaction();  
else  
   oCM.AbortTransaction();  
return bRet;  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)   
 [CanAddATLClass](../ide/canaddatlclass.md)   
 [IsMFCProject](../Topic/IsMFCProject.md)   
 [Introdução a ATL](../Topic/Introduction%20to%20ATL.md)