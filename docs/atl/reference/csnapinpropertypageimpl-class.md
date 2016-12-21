---
title: "Classe de CSnapInPropertyPageImpl | Microsoft Docs"
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
  - "CSnapInPropertyPageImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSnapInPropertyPageImpl"
  - "páginas de propriedades, ATL"
  - "snap-ins"
  - "snap-ins, páginas de propriedades"
ms.assetid: 75bdce5a-985e-4166-bd44-493132e023c4
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSnapInPropertyPageImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para implementar um objeto da página de propriedades do snap\-in.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
CSnapInPropertyPageImpl : public CDialogImplBase  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSnapInPropertyPageImpl::CSnapInPropertyPageImpl](../Topic/CSnapInPropertyPageImpl::CSnapInPropertyPageImpl.md)|Construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSnapInPropertyPageImpl::CancelToClose](../Topic/CSnapInPropertyPageImpl::CancelToClose.md)|Alterar o status de botões de **OK** e de **Cancelar** .|  
|[CSnapInPropertyPageImpl::Create](../Topic/CSnapInPropertyPageImpl::Create.md)|Inicializa um objeto criado de `CSnapInPropertyPageImpl` .|  
|[CSnapInPropertyPageImpl::OnApply](../Topic/CSnapInPropertyPageImpl::OnApply.md)|Chamado pela estrutura quando o usuário clica no botão de **Aplicar agora** ao usar um folha de propriedades de uma tipo.|  
|[CSnapInPropertyPageImpl::OnHelp](../Topic/CSnapInPropertyPageImpl::OnHelp.md)|Chamado pela estrutura quando o usuário clica no botão de **Ajuda** ao usar um folha de propriedades de uma tipo.|  
|[CSnapInPropertyPageImpl::OnKillActive](../Topic/CSnapInPropertyPageImpl::OnKillActive.md)|Chamado pela estrutura quando a página atual for não ativa.|  
|[CSnapInPropertyPageImpl::OnQueryCancel](../Topic/CSnapInPropertyPageImpl::OnQueryCancel.md)|Chamado pela estrutura quando o usuário clica no botão de **Cancelar** e antes de cancelamento ocorrer.|  
|[CSnapInPropertyPageImpl::OnReset](../Topic/CSnapInPropertyPageImpl::OnReset.md)|Chamado pela estrutura quando o usuário clica no botão de **Redefinir** ao usar um folha de propriedades de uma tipo.|  
|[CSnapInPropertyPageImpl::OnSetActive](../Topic/CSnapInPropertyPageImpl::OnSetActive.md)|Chamado pela estrutura quando a página atual se tornar ativa.|  
|[CSnapInPropertyPageImpl::OnWizardBack](../Topic/CSnapInPropertyPageImpl::OnWizardBack.md)|Chamado pela estrutura quando o usuário clica no botão de**Voltar** ao usar um folha de propriedades de uma tipo.|  
|[CSnapInPropertyPageImpl::OnWizardFinish](../Topic/CSnapInPropertyPageImpl::OnWizardFinish.md)|Chamado pela estrutura quando o usuário clica no botão de **Concluir** ao usar um folha de propriedades de uma tipo.|  
|[CSnapInPropertyPageImpl::OnWizardNext](../Topic/CSnapInPropertyPageImpl::OnWizardNext.md)|Chamado pela estrutura quando o usuário clica no botão de `Next` ao usar um folha de propriedades de uma tipo.|  
|[CSnapInPropertyPageImpl::QuerySiblings](../Topic/CSnapInPropertyPageImpl::QuerySiblings.md)|Encaminha a mensagem atual para todas as páginas de folha de propriedades.|  
|[CSnapInPropertyPageImpl::SetModified](../Topic/CSnapInPropertyPageImpl::SetModified.md)|Chame para ativar ou desativar o botão de **Aplicar agora** .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSnapInPropertyPageImpl::m\_psp](../Topic/CSnapInPropertyPageImpl::m_psp.md)|A estrutura de **PROPSHEETPAGE** do windows usada pelo objeto de `CSnapInPropertyPageImpl` .|  
  
## Comentários  
 `CSnapInPropertyPageImpl` fornece uma implementação básica para um objeto da página de propriedades do snap\-in.  Os recursos básicos de uma página de propriedades do snap\-in são implementados usando várias interfaces e mapeiam diferentes tipos.  
  
## Hierarquia de herança  
 `CDialogImplBase`  
  
 `CSnapInPropertyPageImpl`  
  
## Requisitos  
 **Cabeçalho:** atlsnap.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)