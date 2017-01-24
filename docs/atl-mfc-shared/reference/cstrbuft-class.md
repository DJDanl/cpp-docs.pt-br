---
title: "Classe de CStrBufT | Microsoft Docs"
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
  - "ATL::CStrBufT<TCharType>"
  - "ATL.CStrBufT"
  - "CStrBufT"
  - "ATL::CStrBufT"
  - "ATL.CStrBufT<TCharType>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CStrBufT"
  - "classes compartilhadas, CStrBufT"
  - "cadeias de caracteres [C++], gerenciamento de memória personalizado"
ms.assetid: 6b50fa8f-87e8-4ed4-a229-157ce128710f
caps.latest.revision: 17
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStrBufT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece a limpeza automática de recurso para `GetBuffer` e `ReleaseBuffer` chama um objeto existente de `CStringT` .  
  
## Sintaxe  
  
```  
  
      template<  
   typename TCharType  
>  
class CStrBufT  
```  
  
#### Parâmetros  
 *TCharType*  
 O tipo da classe de caractere de `CStrBufT` .  Pode ser um dos seguintes:  
  
-   `char` \(para cadeias de caracteres ANSI\)  
  
-   `wchar_t` \(para cadeias de caracteres Unicode\)  
  
-   Para**TCHAR** \(ANSI e cadeias de caracteres Unicode\)  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|`PCXSTR`|Um ponteiro para uma cadeia de caracteres constante.|  
|`PXSTR`|Um ponteiro para uma cadeia de caracteres.|  
|`StringType`|O tipo cadeia de caracteres cujo buffer deve ser manipulado por especializações este modelo de classe.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStrBufT::CStrBufT](../Topic/CStrBufT::CStrBufT.md)|O construtor para o objeto de buffer de cadeia de caracteres.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStrBufT::SetLength](../Topic/CStrBufT::SetLength.md)|Defina o tamanho do buffer de caracteres do objeto associado de cadeia de caracteres.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStrBufT::operator PCXSTR](../Topic/CStrBufT::operator%20PCXSTR.md)|Recupera um ponteiro de **const** ao buffer de caracteres do objeto associado de cadeia de caracteres.|  
|[CStrBufT::operator PXSTR](../Topic/CStrBufT::operator%20PXSTR.md)|Recupera um ponteiro para o buffer de caracteres do objeto associado de cadeia de caracteres.|  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStrBufT::AUTO\_LENGTH](../Topic/CStrBufT::AUTO_LENGTH.md)|Determina automaticamente o novo tamanho da cadeia de caracteres na versão.|  
|[CStrBufT::SET\_LENGTH](../Topic/CStrBufT::SET_LENGTH.md)|Defina o tamanho do objeto de cadeia de caracteres em tempo de GetBuffer|  
  
## Comentários  
 Essa classe é usada como uma classe envoltório substituindo chamadas a [GetBuffer](../Topic/CSimpleStringT::GetBuffer.md) e [ReleaseBuffer](../Topic/CSimpleStringT::ReleaseBuffer.md), ou [GetBufferSetLength](../Topic/CSimpleStringT::GetBufferSetLength.md) e `ReleaseBuffer`.  
  
 Projetado principalmente como uma classe auxiliar, `CStrBufT` fornece uma maneira conveniente para trabalhar com que um desenvolvedor o buffer de caracteres de um objeto de cadeia de caracteres sem se preocupar sobre como ou quando chamar `ReleaseBuffer`.  Isso é possível porque o objeto invólucro sai do escopo é claro no caso de uma exceção ou de vários deixando caminhos de código; fazendo com que o destrutor libere o recurso de cadeia de caracteres.  
  
## Requisitos  
 **Cabeçalho:** atlsimpstr.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)