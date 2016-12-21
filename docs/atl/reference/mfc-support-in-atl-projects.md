---
title: "Suporte para MFC em projetos ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.atl.addmfc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "projetos ATL, Suporte MFC"
ms.assetid: f90b4276-cb98-4c11-902c-9ebcfe6f954b
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte para MFC em projetos ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Se você selecionar **Support MFC** no assistente de projeto de ATL, seu projeto declara o aplicativo como um objeto de aplicativo MFC \(classe\).  O projeto inicializa a biblioteca MFC e cria uma instância de uma classe \(classe\) *ProjName*que é derivada de [CWinApp](../../mfc/reference/cwinapp-class.md).  
  
 Esta opção está disponível para projetos nonattributed DLL de ATL somente.  
  
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
  
 Você pode exibir a classe de objeto do aplicativo e suas funções de `InitInstance` e de `ExitInstance` no modo da classe.  
  
## Consulte também  
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)   
 [Configurações padrão do projeto ATL](../../atl/reference/default-atl-project-configurations.md)