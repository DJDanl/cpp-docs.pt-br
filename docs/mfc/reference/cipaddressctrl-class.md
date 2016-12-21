---
title: "Classe de CIPAddressCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CIPAddressCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CIPAddressCtrl"
  - "controles comuns, Internet Explorer 4.0"
  - "Caixa de edição de internet address"
  - "Controles comuns do Internet Explorer 4.0"
  - "A caixa address de protocolo de Internet"
  - "Controle de endereço IP"
ms.assetid: 9764d2f4-cb14-4ba8-b799-7f57a55a47c6
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CIPAddressCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle comum de endereço IP do windows.  
  
## Sintaxe  
  
```  
class CIPAddressCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CIPAddressCtrl::CIPAddressCtrl](../Topic/CIPAddressCtrl::CIPAddressCtrl.md)|Constrói um objeto de `CIPAddressCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CIPAddressCtrl::ClearAddress](../Topic/CIPAddressCtrl::ClearAddress.md)|Limpa o conteúdo do controle de endereço IP.|  
|[CIPAddressCtrl::Create](../Topic/CIPAddressCtrl::Create.md)|Cria um controle de endereço IP e anexá\-la a um objeto de `CIPAddressCtrl` .|  
|[CIPAddressCtrl::CreateEx](../Topic/CIPAddressCtrl::CreateEx.md)|Cria um controle de endereço IP através de estilos estendidos o windows especificados e anexá\-la a um objeto de `CIPAddressCtrl` .|  
|[CIPAddressCtrl::GetAddress](../Topic/CIPAddressCtrl::GetAddress.md)|Recupera os valores de endereço para todos os quatro campos no controle de endereço IP.|  
|[CIPAddressCtrl::IsBlank](../Topic/CIPAddressCtrl::IsBlank.md)|Determina se todos os campos no controle de endereço IP estão vazios.|  
|[CIPAddressCtrl::SetAddress](../Topic/CIPAddressCtrl::SetAddress.md)|Defina os valores de endereço para todos os quatro campos no controle de endereço IP.|  
|[CIPAddressCtrl::SetFieldFocus](../Topic/CIPAddressCtrl::SetFieldFocus.md)|Defina o foco do teclado ao campo especificado no controle de endereço IP.|  
|[CIPAddressCtrl::SetFieldRange](../Topic/CIPAddressCtrl::SetFieldRange.md)|Define o intervalo no campo especificado no controle de endereço IP.|  
  
## Comentários  
 Um controle de endereço IP, um controle semelhante a um controle de edição, permite que você insira e manipular um formato numérico no endereço IP de \(IP\).  
  
 Este controle \(e portanto a classe de `CIPAddressCtrl` \) estão disponíveis somente para programas que executam no Microsoft Internet Explorer 4,0 e posterior.  Também estarão disponíveis nas versões futuras do windows e Windows NT.  
  
 Para obter informações mais gerais sobre o controle de endereço IP, consulte [Controles de endereço IP](http://msdn.microsoft.com/library/windows/desktop/bb761372) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CIPAddressCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)