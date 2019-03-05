---
title: Suporte do MFC em projetos ATL
ms.date: 11/04/2016
f1_keywords:
- vc.atl.addmfc
helpviewer_keywords:
- ATL projects, MFC support
ms.assetid: f90b4276-cb98-4c11-902c-9ebcfe6f954b
ms.openlocfilehash: 0aece6805f1de987b0164f405e50b99fd706fef4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57297301"
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

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)<br/>
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)
