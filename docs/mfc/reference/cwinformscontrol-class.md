---
title: "Classe de CWinFormsControl | Microsoft Docs"
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
  - "CWinFormsControl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWinFormsControl"
  - "MFC [C++], Suporte de formulários do windows"
  - "Formulários do Windows [C++], Suporte MFC"
ms.assetid: 6406dd7b-fb89-4a18-ac3a-c010d6b6289a
caps.latest.revision: 28
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWinFormsControl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade básica para hospedar um controle de formulários do windows.  
  
## Sintaxe  
  
```  
template<class TManagedControl>  
class CWinFormsControl : public CWnd  
```  
  
#### Parâmetros  
 `TManagedControl`  
 Um controle de formulários do windows do .NET Framework a ser exibido no aplicativo MFC.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinFormsControl::CWinFormsControl](../Topic/CWinFormsControl::CWinFormsControl.md)|Constrói um objeto invólucro de controle formulários do windows MFC.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinFormsControl::CreateManagedControl](../Topic/CWinFormsControl::CreateManagedControl.md)|Cria um controle de formulários do windows em um contêiner MFC.|  
|[CWinFormsControl::GetControl](../Topic/CWinFormsControl::GetControl.md)|Recupera um ponteiro para o controle de formulários do windows.|  
|[CWinFormsControl::GetControlHandle](../Topic/CWinFormsControl::GetControlHandle.md)|Recupera um identificador para o controle de formulários do windows.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinFormsControl::operator \- \>](../Topic/CWinFormsControl::operator%20-%3E.md)|Substitui [CWinFormsControl::GetControl](../Topic/CWinFormsControl::GetControl.md) em expressões.|  
|[CWinFormsControl::operator TManagedControl^](../Topic/CWinFormsControl::operator%20TManagedControl%5E.md)|Converter um tipo como um ponteiro para um controle de formulários do windows.|  
  
## Comentários  
 A classe de `CWinFormsControl` fornece a funcionalidade básica para hospedar um controle de formulários do windows.  
  
 Para obter mais informações sobre como usar formulários do windows, consulte [Usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
 Seu código MFC não deve armazenar em cache os identificadores de janela \(geralmente armazenados em `m_hWnd`\).  Propriedades de controles de formulários do windows que exigem algumas Win32 subjacente `Window` ser destruído e recriado usando `DestroyWindow` e `CreateWindow`.  O MFC windows identificadores de implementação os eventos de `Destroy` e de `Create` de controles para atualizar o membro de `m_hWnd` .  
  
> [!NOTE]
>  O MFC windows trabalho de integração somente nos projetos que vinculam dinamicamente com MFC \(que é definido em AFXDLL\).  
  
## Requisitos  
 **Cabeçalho:** afxwinforms.h  
  
## Consulte também  
 [Classe de CWinFormsDialog](../Topic/CWinFormsDialog%20Class.md)   
 [Classe de CWinFormsView](../../mfc/reference/cwinformsview-class.md)