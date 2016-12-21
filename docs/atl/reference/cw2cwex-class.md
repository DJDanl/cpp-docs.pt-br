---
title: "CW2CWEX Class | Microsoft Docs"
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
  - "CW2CWEX"
  - "ATL::CW2CWEX"
  - "ATL.CW2CWEX"
  - "ATL.CW2CWEX<t_nBufferLength>"
  - "ATL::CW2CWEX<t_nBufferLength>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CW2CWEX"
ms.assetid: d654b22b-05a6-410f-a0ec-9a2cbbb4cca7
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CW2CWEX Class
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é usada por macros `CW2CTEX` e `CT2CWEX`de conversão de cadeia de caracteres, e o typedef `CW2W`.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
int t_nBufferLength= 128  
>  
class CW2CWEX  
```  
  
#### Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão.  o comprimento padrão é 128 bytes.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CW2CWEX::CW2CWEX](../Topic/CW2CWEX::CW2CWEX.md)|o construtor.|  
|[CW2CWEX::~CW2CWEX](../Topic/CW2CWEX::~CW2CWEX.md)|O destrutor.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CW2CWEX::operator LPCWSTR](../Topic/CW2CWEX::operator%20LPCWSTR.md)|Operador de conversão.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CW2CWEX::m\_psz](../Topic/CW2CWEX::m_psz.md)|O membro de dados que armazena a cadeia de caracteres de origem.|  
  
## Comentários  
 A menos que a funcionalidade adicional é necessária, use `CW2CTEX`, `CT2CWEX`, ou `CW2W` no seu código.  
  
 Essa classe é seguro para usar em loop e não transbordará a pilha.  Por padrão, as classes de conversão de ATL e macros usam a página de código ANSI atual da thread para a conversão.  
  
 Os seguintes macros são baseados em essa classe:  
  
-   `CW2CTEX`  
  
-   `CT2CWEX`  
  
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
 [CW2WEX Class](../../atl/reference/cw2wex-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)