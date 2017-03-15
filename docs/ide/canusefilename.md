---
title: "CanUseFileName | Microsoft Docs"
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
  - "CanUseFileName"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CanUseFileName"
ms.assetid: 60b669fa-9484-4435-b502-78ec8e960a00
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CanUseFileName
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Verifica se existe um arquivo.  Se o arquivo existe e não está restrito, o assistente solicita ao usuário para mesclar o código a ser adicionado ao arquivo existente.  
  
## Sintaxe  
  
```  
  
      function CanUseFileName(   
   strFileName,   
   bCheckIfMidlHeader,   
   bCannotExist,   
   bSetMergeFlag    
);  
```  
  
#### Parâmetros  
 `strFileName`  
 O nome do arquivo para verificar.  
  
 *bCheckIfMidlHeader*  
 Definido como  **true** para verificar se o nome do arquivo é gerado pelo MIDL.  
  
 *bCannotExist*  
 Definido como  **true** para verificar se o nome do arquivo já existe e não pode ser substituído.  
  
 *bSetMergeFlag*  
 Definido como  **true** para incluir o símbolo MERG\_FILE, indicando que o usuário pode mesclar o código para o nome do arquivo existente.  
  
## Valor de retorno  
 **True** se `strFileName` é exclusivo, ou se o código pode ser acrescentado ao arquivo existente; Caso contrário,  **false**.  
  
## Comentários  
 Chame essa função para verificar se existe um nome de arquivo.  Se existe um nome de arquivo e ele não é criado pelo MIDL ou não está restrito, a função solicita que o usuário possa mesclar o novo código ao arquivo existente.  
  
 Se o nome do arquivo não existe e não é restrito, o arquivo o nome especificado é criado.  
  
 Se o nome do arquivo é criado pelo MIDL ou caso contrário, é restrito, o assistente exibe uma mensagem de erro.  
  
## Exemplo  
  
```  
case "HTML_FILE":  
if (!HTML_FILE.disabled)  
   {  
   if (!window.external.FindSymbol("HTML_FILE_VALID"))  
      {  
      bValid = CanUseFileName(obj.value, false, true);  
      if (!bValid)  
      break;  
      window.external.AddSymbol("HTML_FILE_VALID", true)  
      }  
   }  
   bValid = window.external.ValidateFile(HTML_FILE.value, vsCMValidateFileExtHtml);  
   break;   
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)