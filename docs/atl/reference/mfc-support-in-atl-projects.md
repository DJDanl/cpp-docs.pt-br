---
title: Suporte MFC em projetos ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.atl.addmfc
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, MFC support
ms.assetid: f90b4276-cb98-4c11-902c-9ebcfe6f954b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 399f9fcea216adf5480bf38b8aba051c60eed496
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-support-in-atl-projects"></a>Suporte MFC em projetos ATL
Se você selecionar **suporte MFC** no Assistente de projeto de ATL, seu projeto declara o aplicativo como um objeto de aplicativo MFC (classe). O projeto inicializa a biblioteca do MFC e instancia uma classe (classe *NomeDoProjeto*) que é derivado de [CWinApp](../../mfc/reference/cwinapp-class.md).  
  
 Essa opção está disponível para projetos de DLL da ATL nonattributed somente.  
  
```  
class CProjNameApp : public CWinApp  
{  
public:  
 
// Overrides  
    virtual BOOL InitInstance();
virtual int ExitInstance();
DECLARE_MESSAGE_MAP() 
};  
 
BEGIN_MESSAGE_MAP(CProjNameApp, CWinApp)  
END_MESSAGE_MAP()  
 
CProjNameApp theApp;  
 
BOOL CProjNameApp::InitInstance()  
{  
    return CWinApp::InitInstance();

}  
 
int CProjNameApp::ExitInstance()  
{  
    return CWinApp::ExitInstance();

}  
```  
  
 Você pode exibir a classe de objeto do aplicativo e sua `InitInstance` e `ExitInstance` funções no modo de exibição de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)   
 [Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

