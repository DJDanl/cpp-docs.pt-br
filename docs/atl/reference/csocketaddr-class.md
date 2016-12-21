---
title: "Classe de CSocketAddr | Microsoft Docs"
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
  - "CSocketAddr"
  - "ATL.CSocketAddr"
  - "ATL::CSocketAddr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSocketAddr"
ms.assetid: 2fb2d8a7-899e-4a36-a342-cc9f4fcdd68c
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSocketAddr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para converter nomes de host endereços host, dando suporte ao IPv4 e formatos de IPV6.  
  
## Sintaxe  
  
```  
  
class CSocketAddr  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSocketAddr::CSocketAddr](../Topic/CSocketAddr::CSocketAddr.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSocketAddr::FindAddr](../Topic/CSocketAddr::FindAddr.md)|Chamar esse método para converter o nome de host fornecido para o endereço do host.|  
|[CSocketAddr::FindINET4Addr](../Topic/CSocketAddr::FindINET4Addr.md)|Chamar esse método para converter o nome de host IPv4 para o endereço do host.|  
|[CSocketAddr::FindINET6Addr](../Topic/CSocketAddr::FindINET6Addr.md)|Chamar esse método para converter o nome de host IPv6 para o endereço do host.|  
|[CSocketAddr::GetAddrInfo](../Topic/CSocketAddr::GetAddrInfo.md)|Chamar este método para retornar um ponteiro para um elemento específico na lista de **addrinfo** .|  
|[CSocketAddr::GetAddrInfoList](../Topic/CSocketAddr::GetAddrInfoList.md)|Chamar este método para retornar um ponteiro à lista de **addrinfo** .|  
  
## Comentários  
 Essa classe fornece uma versão de IP abordagem desconhecido para analisar endereços de rede para uso com wrappers das funções da API e de soquete da do windows nas bibliotecas.  
  
 Os membros da classe que são usados para analisar endereços de rede usando a função [getaddrinfo](http://msdn.microsoft.com/library/windows/desktop/ms738520)da API do Win32.  
  
 Esta classe suporta ambos os endereços de rede IPv4 andIPv6.  
  
## Requisitos  
 **Cabeçalho:** atlsocket.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)