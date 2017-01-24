---
title: "P&#225;ginas de propriedade MIDL: avan&#231;ado | Microsoft Docs"
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
  - "VC.Project.VCMidlTool.ErrorCheckBounds"
  - "VC.Project.VCMidlTool.ErrorCheckStubData"
  - "VC.Project.VCMidlTool.ErrorCheckAllocations"
  - "VC.Project.VCMidlTool.CPreprocessOptions"
  - "VC.Project.VCMidlTool.UndefinePreprocessorDefinitions"
  - "VC.Project.VCMidlTool.EnableErrorChecks"
  - "VC.Project.VCMidlTool.RedirectOutputAndErrors"
  - "VC.Project.VCMidlTool.ErrorCheckEnumRange"
  - "VC.Project.VCMidlTool.StructMemberAlignment"
  - "VC.Project.VCMidlTool.ErrorCheckRefPointers"
  - "VC.Project.VCMidlTool.ValidateParameters"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "MIDL, páginas de propriedade"
ms.assetid: d1c92e01-f403-4ed6-ab45-4043a3c9c6bb
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;ginas de propriedade MIDL: avan&#231;ado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O  **Advanced**  página de propriedade no  **MIDL** pasta Especifica as opções do compilador MIDL:  
  
-   Ativar verificação de erros \([\/error](http://msdn.microsoft.com/library/windows/desktop/aa367324)\)  
  
-   Verificar alocações \([\/error](http://msdn.microsoft.com/library/windows/desktop/aa367324)\)  
  
-   Verifique os limites \([\/error](http://msdn.microsoft.com/library/windows/desktop/aa367324)\)  
  
-   Verificar intervalo de Enum \([\/error](http://msdn.microsoft.com/library/windows/desktop/aa367324)\)  
  
-   Verificar ponteiros de referência \([\/error](http://msdn.microsoft.com/library/windows/desktop/aa367324)\)  
  
-   Verificar dados Stub \([\/error](http://msdn.microsoft.com/library/windows/desktop/aa367324)\)  
  
-   Validar parâmetros \([\/ robusta](http://msdn.microsoft.com/library/windows/desktop/aa367363)\) \*  
  
-   Alinhamento de membro struct \([\/Zp](http://msdn.microsoft.com/library/windows/desktop/aa367388)\)  
  
-   Redirecionar a saída \([\/o](http://msdn.microsoft.com/library/windows/desktop/aa367351)\)  
  
-   Opções de pré\-processo C \([\/cpp\_opt](http://msdn.microsoft.com/library/windows/desktop/aa367318)\)  
  
-   Cancele as definições do pré\-processador \([\/U](http://msdn.microsoft.com/library/windows/desktop/aa367373)\)  
  
 \* \/ robusta é somente para uso durante a criação de um Windows 2000 ou posterior máquina.  Se você criar um projeto do ATL e deseja usar \/ robusto, altere esta linha no arquivo dlldatax.c:  
  
```  
#define _WIN32_WINNT 0x0400   //for Windows NT 4.0 or Windows 95 with DCOM  
to   
#define _WIN32_WINNT 0x0500   //for Windows NT 4.0 or Windows 95 with DCOM  
```  
  
 Para obter informações sobre como acessar o  **Advanced**  página de propriedade no  **MIDL** pasta, consulte  [How To: especificar propriedades do projeto com páginas de propriedade](../Topic/How%20to:%20Specify%20Project%20Properties%20with%20Property%20Pages.md).  
  
 Para obter informações sobre como acessar programaticamente opções MIDL para projetos do C\+\+, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCMidlTool>.  
  
## Consulte também  
 [Páginas de propriedade MIDL](../ide/midl-property-pages.md)