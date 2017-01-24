---
title: "Classe de CFixedStringT | Microsoft Docs"
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
  - "CFixedStringT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFixedStringT"
  - "classes compartilhadas, CFixedStringT"
ms.assetid: 6d4171ba-3104-493a-a6cc-d515f4ba9a4b
caps.latest.revision: 17
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFixedStringT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa um objeto de cadeia de caracteres com um tamanho fixo de caracteres.  
  
## Sintaxe  
  
```  
  
      template< class   
      StringType  
      , int   
      t_nChars  
       >    
class CFixedStringT : private CFixedStringMgr, public StringType  
```  
  
#### Parâmetros  
 `StringType`  
 Usado como a classe base para o objeto fixo de cadeia de caracteres e pode ser qualquer tipo de base de `CStringT`.  Alguns exemplos incluem `CString`, `CStringA`, e `CStringW`.  
  
 *t\_nChars*  
 O número de caracteres armazenados em buffer.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFixedStringT::CFixedStringT](../Topic/CFixedStringT::CFixedStringT.md)|O construtor para o objeto de cadeia de caracteres.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFixedStringT::operator \=](../Topic/CFixedStringT::operator%20=.md)|Atribuir um novo valor a um objeto de `CFixedStringT` .|  
  
## Comentários  
 Essa classe é um exemplo de uma classe personalizada de cadeia de caracteres com base em `CStringT`.  Embora bastante semelhantes, as duas classes diferem na implementação.  As principais diferenças entre `CFixedStringT` e `CStringT` são:  
  
-   O buffer inicial de caracteres é atribuído como parte do objeto e tem *t\_nChars*de tamanho.  Isso permite que o objeto de **CFixedString** ocupa uma parte contígua de memória para fins de desempenho.  Em o entanto, se o conteúdo de um objeto de `CFixedStringT` aumentam além *de t\_nChars*, o buffer é atribuído dinamicamente.  
  
-   O buffer de caracteres de um objeto de `CFixedStringT` é sempre o mesmo tamanho \(*t\_nChars*\).  Não há nenhuma restrição no tamanho do buffer para objetos de `CStringT` .  
  
-   O gerenciador de memória para `CFixedStringT` é personalizado para que o compartilhamento de um objeto de [CStringData](../../atl-mfc-shared/reference/cstringdata-class.md) entre dois ou mais objectsis de `CFixedStringT` não permitidos.  Os objetos de`CStringT` não têm essa limitação.  
  
 Para obter mais informações sobre personalização de `CFixedStringT` e de gerenciamento de memória para objetos de cadeia de caracteres em geral, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).  
  
## Hierarquia de herança  
 `IAtlStringMgr`  
  
 `StringType`  
  
 `CFixedStringMgr`  
  
 `CFixedStringT`  
  
## Requisitos  
 **Cabeçalho:** cstringt.h  
  
## Consulte também  
 [Classe de CStringT](../../atl-mfc-shared/reference/cstringt-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)