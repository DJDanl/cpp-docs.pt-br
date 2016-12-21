---
title: "P&#225;gina de propriedades Recursos Gerenciados | Microsoft Docs"
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
  - "VC.Project.VCManagedResourceCompilerTool.ResourceFileName"
  - "VC.Project.VCManagedResourceCompilerTool.OutputFileName"
  - "VC.Project.VCManagedResourceCompilerTool.DefaultLocalizedResources"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Página de propriedades Recursos Gerenciados"
ms.assetid: 80b80384-ee55-494d-9f0e-907bb98cfc19
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;gina de propriedades Recursos Gerenciados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Permite configurações para o compilador de recurso.  
  
 A página de propriedades de **Recursos Gerenciados** contém as seguintes propriedades:  
  
 **Nome do recurso lógico**  
 Especifica *o nome do* arquivo intermediário gerado de recurso.  O nome lógica é o nome usado para carregar o recurso.  Se nenhum nome lógica é especificado, o nome de arquivo de recurso \(.resx\) é usado como o nome de lógica.  
  
 **Nome de arquivo de saída**  
 Especifica o nome do arquivo de saída final para que o arquivo de recurso \(.resx\) contribui.  
  
 **Recursos localizados opção**  
 Especifica se o arquivo .resx determinado contribui para recursos padrão ou um satellite .dll.  
  
 Para obter informações sobre como acessar a página de propriedades de **Recursos Gerenciados** , consulte [Como especificar propriedades do projeto com páginas de propriedades](../Topic/How%20to:%20Specify%20Project%20Properties%20with%20Property%20Pages.md).  
  
## Consulte também  
 [Using RC \(The RC Command Line\)](http://msdn.microsoft.com/library/windows/desktop/aa381055)   
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)   
 [\/ASSEMBLYRESOURCE \(inserir um recurso gerenciado\)](../build/reference/assemblyresource-embed-a-managed-resource.md)