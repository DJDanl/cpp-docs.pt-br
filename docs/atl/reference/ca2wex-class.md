---
title: "Classe CA2WEX | Microsoft Docs"
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
  - "ATLCONV/CA2WEX"
  - "ATL.CA2WEX"
  - "ATL.CA2WEX<t_nBufferLength>"
  - "ATL::CA2WEX"
  - "ATL::CA2WEX<t_nBufferLength>"
  - "CA2WEX"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CA2WEX"
ms.assetid: 317d9ffb-e84f-47e8-beda-57e28fb19124
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CA2WEX
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é usada, as macros de conversão de cadeia de caracteres `CA2TEX`, `CA2CTEX`, `CT2WEX`, e `CT2CWEX`, e o typedef **CA2W**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## Sintaxe  
  
```  
  
template<  
int   
t_nBufferLength  
= 128  
>  
class CA2WEX  
  
```  
  
#### Parâmetros  
 `t_nBufferLength`  
 O tamanho do buffer usado no processo de conversão. O comprimento padrão é 128 bytes.  
  
## Membros  
  
### Construtores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2WEX::CA2WEX](../Topic/CA2WEX::CA2WEX.md)|O construtor.|  
|[CA2WEX::~CA2WEX](../Topic/CA2WEX::~CA2WEX.md)|O destruidor.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2WEX::operator LPWSTR](../Topic/CA2WEX::operator%20LPWSTR.md)|Operador de conversão.|  
  
### Membros de dados públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CA2WEX::m\_psz](../Topic/CA2WEX::m_psz.md)|O membro de dados que armazena a cadeia de caracteres de origem.|  
|[CA2WEX::m\_szBuffer](../Topic/CA2WEX::m_szBuffer.md)|O buffer estático, usado para armazenar a cadeia de caracteres convertida.|  
  
## Comentários  
 A menos que a funcionalidade adicional for necessária, use `CA2TEX`, `CA2CTEX`, `CT2WEX`, `CT2CWEX`, ou **CA2W** em seu código.  
  
 Essa classe contém um buffer de tamanho fixo estático que é usado para armazenar o resultado da conversão. Se o resultado for muito grande para caber no buffer estático, a classe aloca memória usando `malloc`, liberando a memória quando o objeto sai do escopo. Isso garante que, diferentemente do texto macros de conversão disponíveis em versões anteriores do ATL, essa classe é seguro usar em loops e que ele não estouram a pilha.  
  
 Se a classe tenta alocar memória no heap e falhar, ele chamará `AtlThrow` com um argumento de **E\_OUTOFMEMORY**.  
  
 Por padrão, as macros e classes de conversão ATL usam página de código ANSI do thread atual para a conversão. Se você quiser substituir esse comportamento para uma conversão específica, especifique a página de código como o segundo parâmetro para o construtor da classe.  
  
 As macros a seguir baseiam\-se em sua classe:  
  
-   `CA2TEX`  
  
-   `CA2CTEX`  
  
-   `CT2WEX`  
  
-   `CT2CWEX`  
  
 Typedef a seguir baseia\-se em sua classe:  
  
-   **CA2W**  
  
 Para uma discussão sobre essas macros de conversão de texto, consulte [Macros de conversão de cadeia de caracteres MFC e ATL](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md).  
  
## Exemplo  
 Consulte [Macros de conversão de cadeia de caracteres MFC e ATL](../Topic/ATL%20and%20MFC%20String%20Conversion%20Macros.md) para obter um exemplo de como usar essas macros de conversão de cadeia de caracteres.  
  
## Requisitos  
 **Cabeçalho:** Atlconv. h  
  
## Consulte também  
 [CA2AEX Class](../../atl/reference/ca2aex-class.md)   
 [CA2CAEX Class](../../atl/reference/ca2caex-class.md)   
 [CW2AEX Class](../../atl/reference/cw2aex-class.md)   
 [CW2CWEX Class](../../atl/reference/cw2cwex-class.md)   
 [CW2WEX Class](../../atl/reference/cw2wex-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)