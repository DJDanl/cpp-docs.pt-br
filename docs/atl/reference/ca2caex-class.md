---
title: "CA2CAEX Class | Microsoft Docs"
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
  - "ATL.CA2CAEX"
  - "ATL.CA2CAEX<t_nBufferLength>"
  - "ATLCONV/CA2CAEX"
  - "ATL::CA2CAEX<t_nBufferLength>"
  - "ATL::CA2CAEX"
  - "CA2CAEX"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CA2CAEX"
ms.assetid: 388e7c1d-a144-474c-a182-b15f69a74bd8
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CA2CAEX Class
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é usada por macros `CA2CTEX` e `CT2CAEX`de conversão de cadeia de caracteres, e o typedef **CA2CA**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
int t_nBufferLength= 128  
>  
class CA2CAEX  
```  
  
#### Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão.  o comprimento padrão é 128 bytes.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2CAEX::CA2CAEX](../Topic/CA2CAEX::CA2CAEX.md)|o construtor.|  
|[CA2CAEX::~CA2CAEX](../Topic/CA2CAEX::~CA2CAEX.md)|O destrutor.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2CAEX::operator LPCSTR](../Topic/CA2CAEX::operator%20LPCSTR.md)|Operador de conversão.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2CAEX::m\_psz](../Topic/CA2CAEX::m_psz.md)|O membro de dados que armazena a cadeia de caracteres de origem.|  
  
## Comentários  
 A menos que a funcionalidade adicional é necessária, use `CA2CTEX`, `CT2CAEX`, ou **CA2CA** em seu próprio código.  
  
 Essa classe é seguro para usar em loop e não transbordará a pilha.  Por padrão, as classes de conversão de ATL e macros usarão a página de código ANSI atual da thread para a conversão.  
  
 Os seguintes macros são baseados em essa classe:  
  
-   `CA2CTEX`  
  
-   `CT2CAEX`  
  
 O exemplo a seguir typedef é baseado em essa classe:  
  
-   **CA2CA**  
  
 Para uma discussão de esses macros de conversão de texto, consulte [Macros de conversão de cadeia de caracteres de ATL e de MFC](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md).  
  
## Exemplo  
 [Macros de conversão de cadeia de caracteres de ATL e de MFC](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md) consulte para um exemplo de como usar esses macros de conversão de cadeia de caracteres.  
  
## Requisitos  
 **Cabeçalho:** atlconv.h  
  
## Consulte também  
 [CA2AEX Class](../../atl/reference/ca2aex-class.md)   
 [Classe CA2WEX](../../atl/reference/ca2wex-class.md)   
 [CW2AEX Class](../../atl/reference/cw2aex-class.md)   
 [CW2CWEX Class](../../atl/reference/cw2cwex-class.md)   
 [CW2WEX Class](../../atl/reference/cw2wex-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)