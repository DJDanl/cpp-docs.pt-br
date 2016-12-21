---
title: "Classe de CComControl | Microsoft Docs"
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
  - "CComControl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "propriedades de ambiente"
  - "Classe de CComControl"
  - "Classe de CComControlBase, Classe de CComControl"
  - "sinalizadores de controle"
  - "controles [ATL], controle funções auxiliares"
  - "controles [ATL], propriedades"
  - "propriedades pré-definidas, ATL"
ms.assetid: 55368c27-bd16-45a7-b701-edb36157c8e8
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComControl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para criar e gerenciar controles de ATL.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template <  
class T,  
class WinBase= CWindowImpl< T>   
>  
class ATL_NO_VTABLE CComControl :  
public CComControlBase, public WinBase;  
```  
  
#### Parâmetros  
 `T`  
 a classe que implementa o controle.  
  
 *WinBase*  
 A classe base que implementa funções na janela.  Opções a [CWindowImpl](../Topic/CWindowImpl%20Class.md).  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComControl::CComControl](../Topic/CComControl::CComControl.md)|Construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComControl::ControlQueryInterface](../Topic/CComControl::ControlQueryInterface.md)|Recupera um ponteiro para a interface solicitada.|  
|[CComControl::CreateControlWindow](../Topic/CComControl::CreateControlWindow.md)|Cria uma janela para o controle.|  
|[CComControl::FireOnChanged](../Topic/CComControl::FireOnChanged.md)|Notifica o coletor de contêiner que uma propriedade do controle for alterado.|  
|[CComControl::FireOnRequestEdit](../Topic/CComControl::FireOnRequestEdit.md)|Notifica o coletor de contêiner que uma propriedade do controle é o ponto de alterar e que o objeto é perguntando para o coletor como proceder.|  
|[CComControl::MessageBox](../Topic/CComControl::MessageBox.md)|Chamar esse método para criar, exibir, e operar uma caixa de mensagem.|  
  
## Comentários  
 `CComControl` é um conjunto de funções úteis auxiliares de controle e de membros essenciais de dados para controles de ATL.  Quando você cria um controle padrão ou um controle DHTML usando o assistente de controle de ATL, o assistente derivado automaticamente sua classe de `CComControl`.  `CComControl` derivado a maioria dos métodos de [CComControlBase](../Topic/CComControlBase%20Class.md).  
  
 Para obter mais informações sobre como criar um controle, consulte [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md).  Para obter mais informações sobre o assistente de projeto de ATL, consulte o artigo [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md).  
  
 Para uma demonstração de membros dos métodos e de dados de `CComControl` , consulte o exemplo de [CIRC](../../top/visual-cpp-samples.md) .  
  
## Hierarquia de herança  
 `WinBase`  
  
 [CComControlBase](../Topic/CComControlBase%20Class.md)  
  
 `CComControl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de CWindowImpl](../Topic/CWindowImpl%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CComControlBase](../Topic/CComControlBase%20Class.md)   
 [Classe de CComCompositeControl](../../atl/reference/ccomcompositecontrol-class.md)