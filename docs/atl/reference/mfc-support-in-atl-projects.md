---
title: Suporte a MFC em projetos do ATL | Documentos do Microsoft
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
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 483027e47c17ccd0c38dc6e96d903be1032f77fb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="mfc-support-in-atl-projects"></a>Suporte a MFC em projetos do ATL
Se você selecionar **suporte MFC** na ATL Project Wizard, seu projeto declara o aplicativo como um objeto de aplicativo MFC (classe). O projeto inicializa a biblioteca MFC e instancia uma classe (classe *NomeDoProjeto*) que é derivada de [CWinApp](../../mfc/reference/cwinapp-class.md).  
  
 Essa opção está disponível para projetos ATL DLL nonattributed somente.  
  
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
  
 Você pode exibir a classe de objeto de aplicativo e sua `InitInstance` e `ExitInstance` funções no modo de exibição de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)   
 [Configurações de projeto padrão ATL](../../atl/reference/default-atl-project-configurations.md)


