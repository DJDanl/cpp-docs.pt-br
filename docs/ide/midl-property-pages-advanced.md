---
title: "Páginas de propriedade MIDL: Avançado | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCMidlTool.ErrorCheckBounds
- VC.Project.VCMidlTool.ErrorCheckStubData
- VC.Project.VCMidlTool.ErrorCheckAllocations
- VC.Project.VCMidlTool.CPreprocessOptions
- VC.Project.VCMidlTool.UndefinePreprocessorDefinitions
- VC.Project.VCMidlTool.EnableErrorChecks
- VC.Project.VCMidlTool.RedirectOutputAndErrors
- VC.Project.VCMidlTool.ErrorCheckEnumRange
- VC.Project.VCMidlTool.StructMemberAlignment
- VC.Project.VCMidlTool.ErrorCheckRefPointers
- VC.Project.VCMidlTool.ValidateParameters
dev_langs: C++
helpviewer_keywords: MIDL, property pages
ms.assetid: d1c92e01-f403-4ed6-ab45-4043a3c9c6bb
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d6e7dde047c3311c6fd694a91c7a63fcfbcc95d0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="midl-property-pages-advanced"></a>Páginas de propriedade MIDL: avançado
O **avançado** página de propriedades no **MIDL** pasta especifica as opções do compilador MIDL:  
  
-   Habilitar a verificação de erros ([/error](http://msdn.microsoft.com/library/windows/desktop/aa367324))  
  
-   Verificar alocações ([/error](http://msdn.microsoft.com/library/windows/desktop/aa367324))  
  
-   Verifique os limites ([/error](http://msdn.microsoft.com/library/windows/desktop/aa367324))  
  
-   Verificar intervalo de Enum ([/error](http://msdn.microsoft.com/library/windows/desktop/aa367324))  
  
-   Verificar ponteiros de referência ([/error](http://msdn.microsoft.com/library/windows/desktop/aa367324))  
  
-   Verificar dados Stub ([/error](http://msdn.microsoft.com/library/windows/desktop/aa367324))  
  
-   Validar parâmetros ([/ robusto](http://msdn.microsoft.com/library/windows/desktop/aa367363)) *  
  
-   Alinhamento de membro de struct ([/Zp](http://msdn.microsoft.com/library/windows/desktop/aa367388))  
  
-   Redirecionar a saída ([/o](http://msdn.microsoft.com/library/windows/desktop/aa367351))  
  
-   Opções de pré-processo C ([/cpp_opt](http://msdn.microsoft.com/library/windows/desktop/aa367318))  
  
-   Exclua definições de pré-processador ([/u](http://msdn.microsoft.com/library/windows/desktop/aa367373))  
  
 \*/ é eficiente apenas para uso durante a criação de um Windows 2000 ou posterior máquina. Se você criar um projeto de ATL e deseja usar / robusta, altere essa linha no arquivo dlldatax.c:  
  
```  
#define _WIN32_WINNT 0x0400   //for Windows NT 4.0 or Windows 95 with DCOM  
to   
#define _WIN32_WINNT 0x0500   //for Windows NT 4.0 or Windows 95 with DCOM  
```  
  
 Para obter informações sobre como acessar o **avançado** página de propriedades no **MIDL** pasta, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
 Para obter informações sobre como acessar programaticamente opções MIDL para projetos em C++, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCMidlTool>.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedades de MIDL](../ide/midl-property-pages.md)