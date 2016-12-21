---
title: "Classe de CComPtrBase | Microsoft Docs"
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
  - "ATL.CComPtrBase"
  - "ATL::CComPtrBase<T>"
  - "ATL.CComPtrBase<T>"
  - "ATL::CComPtrBase"
  - "CComPtrBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComPtrBase"
ms.assetid: 6dbe9543-dee8-4a97-b02f-dd3a25f4a1a0
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComPtrBase
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece uma base para as classes espertas ponteiro que usam rotinas de memória baseados em COM.  
  
## Sintaxe  
  
```  
  
      template <  
   class T   
> class CComPtrBase  
```  
  
#### Parâmetros  
 `T`  
 O tipo de objeto para ser referenciado pelo ponteiro inteligente.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPtrBase::~CComPtrBase](../Topic/CComPtrBase::~CComPtrBase.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPtrBase::Advise](../Topic/CComPtrBase::Advise.md)|Chamar esse método para criar uma conexão entre o ponto de conexão de `CComPtrBase` e o coletor do cliente.|  
|[CComPtrBase::Attach](../Topic/CComPtrBase::Attach.md)|Chamar esse método para executar a propriedade de um ponteiro existente.|  
|[CComPtrBase::CoCreateInstance](../Topic/CComPtrBase::CoCreateInstance.md)|Chamar esse método para criar um objeto da classe associada com uma identificação de classe ou um certo ID do programa|  
|[CComPtrBase::CopyTo](../Topic/CComPtrBase::CopyTo.md)|Chamar esse método para copiar o ponteiro de `CComPtrBase` a outra variável de ponteiro.|  
|[CComPtrBase::Detach](../Topic/CComPtrBase::Detach.md)|Chamar este método para liberar a propriedade de um ponteiro.|  
|[CComPtrBase::IsEqualObject](../Topic/CComPtrBase::IsEqualObject.md)|Chamar esse método para verificar se os pontos especificados de **IUnknown** ao mesmo objeto associado com o objeto de `CComPtrBase` .|  
|[CComPtrBase::QueryInterface](../Topic/CComPtrBase::QueryInterface.md)|Chamar este método para retornar um ponteiro para a interface especificada.|  
|[CComPtrBase::Release](../Topic/CComPtrBase::Release.md)|Chamar este método para liberar a interface.|  
|[CComPtrBase::SetSite](../Topic/CComPtrBase::SetSite.md)|Chamar esse método para definir o site do objeto de `CComPtrBase` a **IUnknown** do objeto pai.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPtrBase::operator T\*](../Topic/CComPtrBase::operator%20T*.md)|o operador cast.|  
|[CComPtrBase::operator\!](../Topic/CComPtrBase::operator%20!.md)|NÃO o operador.|  
|[CComPtrBase::operator &](../Topic/CComPtrBase::operator%20&.md)|Operador &.|  
|[CComPtrBase::operator \*](../Topic/CComPtrBase::operator%20*.md)|\* O operador.|  
|[CComPtrBase::operator \<](../Topic/CComPtrBase::operator%20%3C.md)|Símbolo de menor que o operador.|  
|[\=\= De CComPtrBase::operator](../Topic/CComPtrBase::operator%20==.md)|o operador de igualdade.|  
|[CComPtrBase::operator \- \>](../Topic/CComPtrBase::operator%20-%3E.md)|O operador de ponteiro\-à\- membros.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComPtrBase::p](../Topic/CComPtrBase::p.md)|A variável de membro de dados do ponteiro.|  
  
## Comentários  
 Essa classe fornece a base para outros ponteiros inteligentes que usam rotinas de gerenciamento de memória COM, como [CComQIPtr](../../atl/reference/ccomqiptr-class.md) e [CComPtr](../../atl/reference/ccomptr-class.md).  Classes derivadas adicione seus próprios operadores e construtores, mas dependam de métodos fornecidos por `CComPtrBase`.  
  
## Requisitos  
 **Cabeçalho:** atlcomcli.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)