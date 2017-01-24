---
title: "CNetAddressCtrl Class | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CNetAddressCtrl class"
ms.assetid: cb4c6aca-3f49-4b52-b76c-65f57096155b
caps.latest.revision: 32
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CNetAddressCtrl Class
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CNetAddressCtrl` representa o controle de endereço de rede, que você pode usar para entrada e validar o formato IPv4, IPv6, e de endereços de nome DNS.  
  
## Sintaxe  
  
```  
class CNetAddressCtrl : public CEdit  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CNetAddressCtrl::CNetAddressCtrl](../Topic/CNetAddressCtrl::CNetAddressCtrl.md)|Constrói um objeto de `CNetAddressCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CNetAddressCtrl::Create](../Topic/CNetAddressCtrl::Create.md)|Cria um controle de endereço de rede com os estilos especificados e anexa ao objeto atual de `CNetAddressCtrl` .|  
|[CNetAddressCtrl::CreateEx](../Topic/CNetAddressCtrl::CreateEx.md)|Cria um controle de endereço de rede com os estilos estendidos especificados e anexá\-la ao objeto atual de `CNetAddressCtrl` .|  
|[CNetAddressCtrl::DisplayErrorTip](../Topic/CNetAddressCtrl::DisplayErrorTip.md)|Exibe um balão de dica de erro quando o usuário inserir um endereço de rede sem suporte no controle de endereço de rede atual.|  
|[CNetAddressCtrl::GetAddress](../Topic/CNetAddressCtrl::GetAddress.md)|Recupera uma representação validada e analisada de endereço de rede associado ao controle de endereço de rede atual.|  
|[CNetAddressCtrl::GetAllowType](../Topic/CNetAddressCtrl::GetAllowType.md)|Recupera o tipo de endereço de rede que o controle de endereço de rede atual pode oferecer suporte.|  
|[CNetAddressCtrl::SetAllowType](../Topic/CNetAddressCtrl::SetAllowType.md)|Define o tipo de endereço de rede que o controle de endereço de rede atual pode oferecer suporte.|  
  
## Comentários  
 O controle de endereço de rede verifica que o formato de endereço que o usuário insere está correto.  O controle não se conecta a verdade para o endereço de rede.  O método de [CNetAddressCtrl::SetAllowType](../Topic/CNetAddressCtrl::SetAllowType.md) especifica um ou mais tipos de endereço que o método de [CNetAddressCtrl::GetAddress](../Topic/CNetAddressCtrl::GetAddress.md) pode analisar e verificar.  Um endereço pode ser na forma de um IPv4, um IPv6, ou um endereço chamado para um servidor, uma rede, um host, ou um destino da mensagem de transferência.  Se o formato de endereço está incorreto, você pode usar o método de [CNetAddressCtrl::DisplayErrorTip](../Topic/CNetAddressCtrl::DisplayErrorTip.md) para exibir uma caixa de mensagem de infotip graficamente que aponta para a caixa de texto do controle de endereço de rede e exibe uma mensagem de erro pré\-definida.  
  
 A classe de `CNetAddressCtrl` é derivada da classe de [CEdit](../Topic/CEdit%20Class.md) .  Portanto, o controle de endereço de rede fornece acesso a todas as mensagens do controle de edição do windows.  
  
 A figura a seguir descreve um caixa de diálogo que contém um controle de endereço de rede.  A caixa de texto \(1\) para o controle de endereço de rede contém um endereço inválido de rede.  A mensagem de infotip \(2\) é exibida se o endereço de rede é inválido.  
  
 ![Caixa de diálogo com um controle de endereço de rede e uma InfoDica.](../../mfc/reference/media/cnetaddctrl.png "CNetAddCtrl")  
  
## Exemplo  
 O exemplo de código a seguir é uma parte de uma caixa de diálogo que valida um endereço de rede.  Os manipuladores de eventos para três botões de opção especifica que o endereço de rede pode ser um dos três tipos de endereço.  O usuário insere um endereço na caixa de texto do controle de rede, então pressiona um botão para validar o endereço.  Se o endereço é válido, uma mensagem é exibida com êxito; caso contrário, a mensagem de erro predefinida de infotip é exibida.  
  
 [!code-cpp[NVC_MFC_CNetAddressCtrl_s1#1](../../mfc/reference/codesnippet/CPP/cnetaddressctrl-class_1.cpp)]  
  
## Exemplo  
 O exemplo de código de arquivo de cabeçalho da caixa de diálogo define as variáveis de [NC\_ADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb773345) e de [NET\_ADDRESS\_INFORMATION](http://msdn.microsoft.com/library/windows/desktop/bb773346) que são exigidos pelo método de [CNetAddressCtrl::GetAddress](../Topic/CNetAddressCtrl::GetAddress.md) .  
  
 [!code-cpp[NVC_MFC_CNetAddressCtrl_s1#2](../../mfc/reference/codesnippet/CPP/cnetaddressctrl-class_2.h)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CEdit](../Topic/CEdit%20Class.md)  
  
 `CNetAddressCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
 Essa classe é suportado em [!INCLUDE[windowsver](../Token/windowsver_md.md)] e posteriormente.  
  
 Os requisitos adicionais para essa classe são descritos em [Requisitos de compilação para controles comuns do Windows Vista](../../mfc/build-requirements-for-windows-vista-common-controls.md).  
  
## Consulte também  
 [CNetAddressCtrl Class](../../mfc/reference/cnetaddressctrl-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CEdit](../Topic/CEdit%20Class.md)