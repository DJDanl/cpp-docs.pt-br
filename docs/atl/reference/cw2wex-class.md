---
title: "CW2WEX Class | Microsoft Docs"
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
  - "CW2WEX"
  - "ATL.CW2WEX<t_nBufferLength>"
  - "ATL::CW2WEX"
  - "ATL.CW2WEX"
  - "ATL::CW2WEX<t_nBufferLength>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CW2WEX"
ms.assetid: 46262e56-e0d2-41fe-855b-0b67ecc8fcd7
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CW2WEX Class
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é usada por macros `CW2TEX` e `CT2WEX`de conversão de cadeia de caracteres, e o typedef `CW2W`.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
int t_nBufferLength= 128  
>  
class CW2WEX  
```  
  
#### Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão.  o comprimento padrão é 128 bytes.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CW2WEX::CW2WEX](../Topic/CW2WEX::CW2WEX.md)|o construtor.|  
|[CW2WEX::~CW2WEX](../Topic/CW2WEX::~CW2WEX.md)|O destrutor.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CW2WEX::operator LPWSTR](../Topic/CW2WEX::operator%20LPWSTR.md)|Operador de conversão.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CW2WEX::m\_psz](../Topic/CW2WEX::m_psz.md)|O membro de dados que armazena a cadeia de caracteres de origem.|  
|[CW2WEX::m\_szBuffer](../Topic/CW2WEX::m_szBuffer.md)|o buffer estático, usado para armazenar a cadeia de caracteres convertida.|  
  
## Comentários  
 A menos que a funcionalidade adicional é necessária, use `CW2TEX`, `CT2WEX`, ou `CW2W` no seu código.  
  
 Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão.  Se o resultado é muito grande caber no buffer estático, a classe aloca memória usando `malloc`, liberando memória quando o objeto sai do escopo.  Isso garante que, ao invés de macros de conversão de texto disponíveis nas versões anteriores de ATL, essa classe é seguro para usar em loop e que não transbordará a pilha.  
  
 Se a classe tenta atribuir a memória na heap e falhar, chamará `AtlThrow` com um argumento de **E\_OUTOFMEMORY**.  
  
 Por padrão, as classes de conversão de ATL e macros usam a página de código ANSI atual da thread para a conversão.  
  
 Os seguintes macros são baseados em essa classe:  
  
-   `CW2TEX`  
  
-   `CT2WEX`  
  
 O exemplo a seguir typedef é baseado em essa classe:  
  
-   `CW2W`  
  
 Para uma discussão de esses macros de conversão de texto, consulte [Macros de conversão de cadeia de caracteres de ATL e de MFC](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md).  
  
## Exemplo  
 [Macros de conversão de cadeia de caracteres de ATL e de MFC](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md) consulte para um exemplo de como usar esses macros de conversão de cadeia de caracteres.  
  
## Requisitos  
 **Cabeçalho:** atlconv.h  
  
## Consulte também  
 [CA2AEX Class](../../atl/reference/ca2aex-class.md)   
 [CA2CAEX Class](../../atl/reference/ca2caex-class.md)   
 [Classe CA2WEX](../../atl/reference/ca2wex-class.md)   
 [CW2AEX Class](../../atl/reference/cw2aex-class.md)   
 [CW2CWEX Class](../../atl/reference/cw2cwex-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)