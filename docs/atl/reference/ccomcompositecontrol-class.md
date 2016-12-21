---
title: "Classe de CComCompositeControl | Microsoft Docs"
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
  - "CComCompositeControl"
  - "ATL::CComCompositeControl"
  - "ATL.CComCompositeControl<T>"
  - "ATL.CComCompositeControl"
  - "ATL::CComCompositeControl<T>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComCompositeControl"
  - "controles de composição, Classe de CComCompositeControl"
ms.assetid: 1304b931-27e8-4fbc-be8e-bb226ad887fb
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComCompositeControl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece os métodos necessários para implementar um controle composto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template <  
class T   
>  
class CComCompositeControl :  
public CComControl< T, CAxDialogImpl< T > >  
```  
  
#### Parâmetros  
 `T`  
 Seus derivados da classe, [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como quaisquer outras interfaces você deseja oferecer suporte para o controle composto.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCompositeControl::CComCompositeControl](../Topic/CComCompositeControl::CComCompositeControl.md)|o construtor.|  
|[CComCompositeControl::~CComCompositeControl](../Topic/CComCompositeControl::~CComCompositeControl.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCompositeControl::AdviseSinkMap](../Topic/CComCompositeControl::AdviseSinkMap.md)|Chamar esse método para recomendar ou unadvise todos os controles hospedados pelo controle composto.|  
|[CComCompositeControl::CalcExtent](../Topic/CComCompositeControl::CalcExtent.md)|Chamar esse método para calcular o tamanho em unidades de **HIMETRIC** de recurso da caixa de diálogo usado para hospedar o controle composto.|  
|[CComCompositeControl::Create](../Topic/CComCompositeControl::Create.md)|Este método é chamado para criar a janela do controle para o controle composto.|  
|[CComCompositeControl::CreateControlWindow](../Topic/CComCompositeControl::CreateControlWindow.md)|Chamar esse método para criar a janela de controle e para recomendar qualquer controle hospedado.|  
|[CComCompositeControl::SetBackgroundColorFromAmbient](../Topic/CComCompositeControl::SetBackgroundColorFromAmbient.md)|Chamar esse método para definir a cor do plano de fundo do controle composto usando a cor do plano de fundo do contêiner.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCompositeControl::m\_hbrBackground](../Topic/CComCompositeControl::m_hbrBackground.md)|O pincel em segundo plano.|  
|[CComCompositeControl::m\_hWndFocus](../Topic/CComCompositeControl::m_hWndFocus.md)|O identificador de janela que atualmente tem o foco.|  
  
## Comentários  
 Classes derivadas herdam da classe `CComCompositeControl` a funcionalidade de um controle composto ActiveX.  Os controles ActiveX derivados de `CComCompositeControl` são hospedados por uma caixa de diálogo padrão.  Esses tipos de controles são chamados controles compostos como podem hospedar outros controles \(controles nativos do windows e controles ActiveX.\)  
  
 `CComCompositeControl` identifica o recurso da caixa de diálogo para usar na criação um controle composto de um membro de dados enumerados na classe filho.  O membro IDD de essa classe filho é definida como a identificação do recurso de recurso da caixa de diálogo que será usado como a janela do controle.  O exemplo a seguir é um exemplo de membro de dados que a classe derivada de `CComCompositeControl` deve conter para identificar o recurso da caixa de diálogo para ser usado na janela do controle:  
  
 [!code-cpp[NVC_ATL_COM#13](../../atl/codesnippet/CPP/ccomcompositecontrol-class_1.h)]  
  
> [!NOTE]
>  Os controles são sempre controles compostos da janela, embora eles podem conter controles sem janelas.  
  
 Um controle implementado por `CComCompositeControl`\- a classe derivada tem o comportamento do uso de opção interno.  Quando o controle recebe o foco sendo listado em um aplicativo que contém, em sucessão pressione a tecla TAB fará com que o foco a ser alternado através dos controles contidos de qualquer controle composto, então fora do controle composto e sobre para o próximo item na ordem de tabulação o recipiente.  Ordem de tabulação de controles hospedados é determinado pelo recurso da caixa de diálogo e determina a ordem em que o catálogo ocorrerá.  
  
> [!NOTE]
>  Aceleradores para que funcionem corretamente com `CComCompositeControl`, é necessário carregar uma tabela de aceleração como o controle é criado, passa a alça e o número de aceleradores de novo em [IOleControlImpl::GetControlInfo](../Topic/IOleControlImpl::GetControlInfo.md)for, e finalmente a tabela quando o controle é liberado.  
  
## Exemplo  
 [!code-cpp[NVC_ATL_COM#14](../../atl/codesnippet/CPP/ccomcompositecontrol-class_2.h)]  
  
## Hierarquia de herança  
 `WinBase`  
  
 [CComControlBase](../Topic/CComControlBase%20Class.md)  
  
 [CComControl](../../atl/reference/ccomcontrol-class.md)  
  
 `CComCompositeControl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Fundamentos do controle composto](../Topic/ATL%20Composite%20Control%20Fundamentals.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)