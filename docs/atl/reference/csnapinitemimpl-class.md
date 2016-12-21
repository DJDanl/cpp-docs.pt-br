---
title: "Classe de CSnapInItemImpl | Microsoft Docs"
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
  - "CSnapInItemImpl"
  - "ATL.CSnapInItemImpl"
  - "ATL::CSnapInItemImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSnapInItemImpl"
  - "snap-ins"
  - "snap-ins, Suporte de para ATL"
  - "snap-ins, itens de dados"
ms.assetid: 52caefbd-9eae-49b0-add2-d55524271aa7
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSnapInItemImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para implementar um objeto do snap\-in.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template <  
class T,  
BOOL bIsExtension= FALSE  
>  
class ATL_NO_VTABLE CSnapInItemImpl :  
public CSnapInItem  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `CSnapInItemImpl`.  
  
 *bIsExtension*  
 **Verdadeiro** se o objeto é uma extensão do snap\-in; se não **Falso**.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSnapInItemImpl::CSnapInItemImpl](../Topic/CSnapInItemImpl::CSnapInItemImpl.md)|Construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSnapInItemImpl::AddMenuItems](../Topic/CSnapInItemImpl::AddMenuItems.md)|Adiciona itens de menu para um menu de contexto.|  
|[CSnapInItemImpl::Command](../Topic/CSnapInItemImpl::Command.md)|Chamado pelo console quando um item de menu personalizado está selecionado.|  
|[CSnapInItemImpl::CreatePropertyPages](../Topic/CSnapInItemImpl::CreatePropertyPages.md)|Adicionar páginas a folha de propriedades do snap\-in.|  
|[CSnapInItemImpl::FillData](../Topic/CSnapInItemImpl::FillData.md)|Informações das cópias no objeto do snap\-in em um fluxo especificado.|  
|[CSnapInItemImpl::GetResultPaneInfo](../Topic/CSnapInItemImpl::GetResultPaneInfo.md)|Recupera a estrutura de **RESULTDATAITEM** do snap\-in.|  
|[CSnapInItemImpl::GetResultViewType](../Topic/CSnapInItemImpl::GetResultViewType.md)|Determina o tipo de exibição usado pelo painel de resultados.|  
|[CSnapInItemImpl::GetScopePaneInfo](../Topic/CSnapInItemImpl::GetScopePaneInfo.md)|Recupera a estrutura de **SCOPEDATAITEM** do snap\-in.|  
|[CSnapInItemImpl::Notify](../Topic/CSnapInItemImpl::Notify.md)|Chamado pelo console para notificar o snap\-in das ações executadas pelo usuário.|  
|[CSnapInItemImpl::QueryPagesFor](../Topic/CSnapInItemImpl::QueryPagesFor.md)|Chamado para ver se o nó do snap\-in suporta páginas de propriedades.|  
|[CSnapInItemImpl::SetMenuInsertionFlags](../Topic/CSnapInItemImpl::SetMenuInsertionFlags.md)|Altera os sinalizadores de inserção de um objeto do snap\-in.|  
|[CSnapInItemImpl::SetToolbarButtonInfo](../Topic/CSnapInItemImpl::SetToolbarButtonInfo.md)|Define informações do botão da barra de ferramentas especificado.|  
|[CSnapInItemImpl::UpdateMenuState](../Topic/CSnapInItemImpl::UpdateMenuState.md)|Atualiza o estado de um item de menu de contexto.|  
|[CSnapInItemImpl::UpdateToolbarButton](../Topic/CSnapInItemImpl::UpdateToolbarButton.md)|Atualiza o estado do botão da barra de ferramentas especificado.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSnapInItemImpl::m\_bstrDisplayName](../Topic/CSnapInItemImpl::m_bstrDisplayName.md)|O nome do objeto do snap\-in.|  
|[CSnapInItemImpl::m\_resultDataItem](../Topic/CSnapInItemImpl::m_resultDataItem.md)|A estrutura de **RESULTDATAITEM** do windows usada pelo objeto de `CSnapInItemImpl` .|  
|[CSnapInItemImpl::m\_scopeDataItem](../Topic/CSnapInItemImpl::m_scopeDataItem.md)|A estrutura de **SCOPEDATAITEM** do windows usada pelo objeto de `CSnapInItemImpl` .|  
  
## Comentários  
 `CSnapInItemImpl` fornece uma implementação básica para um objeto do snap\-in, como adicionar itens de menu e barras de ferramentas, e encaminhando comandos para o nó de encaixe para o manipulador apropriado para a função.  Esses recursos são implementados usando várias interfaces e mapeiam diferentes tipos.  As notificações padrão das alças de implementação enviadas para o nó objeto determinando a correta instância da classe derivada e então encaminhando a mensagem à instância correta.  
  
## Hierarquia de herança  
 `CSnapInItem`  
  
 `CSnapInItemImpl`  
  
## Requisitos  
 **Cabeçalho:** atlsnap.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)