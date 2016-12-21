---
title: "CA2AEX Class | Microsoft Docs"
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
  - "ATL::CA2AEX<t_nBufferLength>"
  - "CA2AEX"
  - "ATL.CA2AEX<t_nBufferLength>"
  - "ATLCONV/CA2AEX"
  - "ATL.CA2AEX"
  - "ATL::CA2AEX"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CA2AEX"
ms.assetid: 57dc65df-d9cf-4a84-99d3-6e031dde3664
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CA2AEX Class
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é usada por macros `CA2TEX` e `CT2AEX`de conversão de cadeia de caracteres, e o typedef **CA2A**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
int t_nBufferLength= 128  
>  
class CA2AEX  
```  
  
#### Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão.  o comprimento padrão é 128 bytes.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2AEX::CA2AEX](../Topic/CA2AEX::CA2AEX.md)|o construtor.|  
|[CA2AEX::~CA2AEX](../Topic/CA2AEX::~CA2AEX.md)|O destrutor.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2AEX::operator LPSTR](../Topic/CA2AEX::operator%20LPSTR.md)|Operador de conversão.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2AEX::m\_psz](../Topic/CA2AEX::m_psz.md)|O membro de dados que armazena a cadeia de caracteres de origem.|  
|[CA2AEX::m\_szBuffer](../Topic/CA2AEX::m_szBuffer.md)|o buffer estático, usado para armazenar a cadeia de caracteres convertida.|  
  
## Comentários  
 A menos que a funcionalidade adicional é necessária, use `CA2TEX`, `CT2AEX`, ou **CA2A** em seu próprio código.  
  
 Essa classe contém um buffer estático de tamanho fixo que é usado para armazenar o resultado da conversão.  Se o resultado é muito grande caber no buffer estático, a classe aloca memória usando `malloc`, liberando memória quando o objeto sai do escopo.  Isso garante que, ao invés de macros de conversão de texto disponíveis nas versões anteriores de ATL, essa classe é seguro para usar em loop e que não transbordará a pilha.  
  
 Se a classe tenta atribuir a memória na heap e falhar, chamará `AtlThrow` com um argumento de **E\_OUTOFMEMORY**.  
  
 Por padrão, as classes de conversão de ATL e macros usam a página de código ANSI atual da thread para a conversão.  
  
 Os seguintes macros são baseados em essa classe:  
  
-   `CA2TEX`  
  
-   `CT2AEX`  
  
 O exemplo a seguir typedef é baseado em essa classe:  
  
-   **CA2A**  
  
 Para uma discussão de esses macros de conversão de texto, consulte [Macros de conversão de cadeia de caracteres de ATL e de MFC](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md).  
  
## Exemplo  
 [Macros de conversão de cadeia de caracteres de ATL e de MFC](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md) consulte para um exemplo de como usar esses macros de conversão de cadeia de caracteres.  
  
## Requisitos  
 **Cabeçalho:** atlconv.h  
  
## Consulte também  
 [CA2CAEX Class](../../atl/reference/ca2caex-class.md)   
 [Classe CA2WEX](../../atl/reference/ca2wex-class.md)   
 [CW2AEX Class](../../atl/reference/cw2aex-class.md)   
 [CW2CWEX Class](../../atl/reference/cw2cwex-class.md)   
 [CW2WEX Class](../../atl/reference/cw2wex-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)