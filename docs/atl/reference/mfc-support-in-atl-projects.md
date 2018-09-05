---
title: Suporte do MFC em projetos ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.atl.addmfc
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, MFC support
ms.assetid: f90b4276-cb98-4c11-902c-9ebcfe6f954b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bb6a3c5bae4d973ba74155ab018ebea69b0e2b93
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43751394"
---
# <a name="mfc-support-in-atl-projects"></a>Suporte do MFC em projetos ATL

Se você selecionar **suporte MFC** na ATL Project Wizard, seu projeto declara o aplicativo como um objeto de aplicativo MFC (classe). O projeto inicializa a biblioteca do MFC e cria uma instância de uma classe (classe *NomeDoProjeto*) que é derivado de [CWinApp](../../mfc/reference/cwinapp-class.md).

Essa opção está disponível para projetos ATL DLL nonattributed apenas.

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

Você pode exibir a classe de objeto de aplicativo e seu `InitInstance` e `ExitInstance` funções no modo de exibição de classe.

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)   
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

