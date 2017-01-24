---
title: "Classe de CComUnkArray | Microsoft Docs"
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
  - "ATL.CComUnkArray"
  - "ATL.CComUnkArray<nMaxSize>"
  - "ATL::CComUnkArray<nMaxSize>"
  - "ATL::CComUnkArray"
  - "CComUnkArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComUnkArray"
  - "pontos de conexão [C++], gerenciando"
ms.assetid: 5fd4b378-a7b5-4cc1-8866-8ab72a73639e
caps.latest.revision: 17
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComUnkArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe armazena ponteiros de **IUnknown** , e destina\-se a ser usada como um parâmetro para a classe de modelo de [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md) .  
  
## Sintaxe  
  
```  
template<  
   unsigned int nMaxSize  
>  
class CComUnkArray  
```  
  
#### Parâmetros  
 *nMaxSize*  
 O número máximo de ponteiros de **IUnknown** que podem ser realizada na matriz estático.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComUnkArray::CComUnkArray](../Topic/CComUnkArray::CComUnkArray.md)|Construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComUnkArray::Add](../Topic/CComUnkArray::Add.md)|Chamar este método para adicionar um ponteiro de **IUnknown** na matriz.|  
|[CComUnkArray::begin](../Topic/CComUnkArray::begin.md)|Retorna um ponteiro para o primeiro ponteiro de **IUnknown** na coleção.|  
|[CComUnkArray::end](../Topic/CComUnkArray::end.md)|Retorna um ponteiro para um passado o ponteiro o último de **IUnknown** na coleção.|  
|[CComUnkArray::GetCookie](../Topic/CComUnkArray::GetCookie.md)|Chamar esse método para obter o cookie associada com um determinado ponteiro de **IUnknown** .|  
|[CComUnkArray::GetUnknown](../Topic/CComUnkArray::GetUnknown.md)|Chamar esse método para obter o ponteiro de **IUnknown** associado com um cookie determinada.|  
|[CComUnkArray::Remove](../Topic/CComUnkArray::Remove.md)|Chamar esse método para remover um ponteiro de **IUnknown** da matriz.|  
  
## Comentários  
 **CComUnkArray** contém um número fixo de ponteiros de **IUnknown** , cada uma interface em um ponto de conexão.  **CComUnkArray** pode ser usado como um parâmetro para a classe de modelo de [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md) .  **CComUnkArray\<1\>** é uma especialização do modelo de **CComUnkArray** que é otimizado para um ponto de conexão.  
  
 Os métodos [inicie](../Topic/CComUnkArray::begin.md) e [end](../Topic/CComUnkArray::end.md) de **CComUnkArray** podem ser usados para repetir todos os pontos de conexão \(por exemplo, quando um evento é acionado.\)  
  
 Consulte [Adicionando pontos de conexão a um objeto](../../atl/adding-connection-points-to-an-object.md) para automatizar detalhes na criação de proxies de ponto de conexão.  
  
> [!NOTE]
>  **Observação** A classe [CComDynamicUnkArray](../Topic/CComDynamicUnkArray%20Class.md) é usado pelo assistente de **Adicionar Classe** ao criar um controle que possui pontos de conexão.  Se você desejar especificar manualmente o número de pontos de conexão, altere a referência de **CComDynamicUnkArray** a `CComUnkArray<`*em* `>`*em* , onde é o número de pontos de conexão necessários.  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComDynamicUnkArray](../Topic/CComDynamicUnkArray%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)