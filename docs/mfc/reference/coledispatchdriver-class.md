---
title: "Classe de COleDispatchDriver | Microsoft Docs"
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
  - "COleDispatchDriver"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Clientes de automação, implementando automação"
  - "Classe de COleDispatchDriver"
  - "Interface OLE de distribuição"
ms.assetid: 3ed98daf-cdc7-4374-8a0c-cf695a8d3657
caps.latest.revision: 21
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleDispatchDriver
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa o lado do cliente de automação OLE.  
  
## Sintaxe  
  
```  
class COleDispatchDriver  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDispatchDriver::COleDispatchDriver](../Topic/COleDispatchDriver::COleDispatchDriver.md)|Constrói um objeto de `COleDispatchDriver` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDispatchDriver::AttachDispatch](../Topic/COleDispatchDriver::AttachDispatch.md)|Anexar uma conexão de `IDispatch` ao objeto de `COleDispatchDriver` .|  
|[COleDispatchDriver::CreateDispatch](../Topic/COleDispatchDriver::CreateDispatch.md)|Cria uma conexão de `IDispatch` e anexá\-la ao objeto de `COleDispatchDriver` .|  
|[COleDispatchDriver::DetachDispatch](../Topic/COleDispatchDriver::DetachDispatch.md)|Dispara uma conexão de `IDispatch` , sem liberar\-la.|  
|[COleDispatchDriver::GetProperty](../Topic/COleDispatchDriver::GetProperty.md)|Obtém uma propriedade de automação.|  
|[COleDispatchDriver::InvokeHelper](../Topic/COleDispatchDriver::InvokeHelper.md)|Auxiliar para chamar métodos de automação.|  
|[COleDispatchDriver::ReleaseDispatch](../Topic/COleDispatchDriver::ReleaseDispatch.md)|Libera uma conexão de `IDispatch` .|  
|[COleDispatchDriver::SetProperty](../Topic/COleDispatchDriver::SetProperty.md)|Define uma propriedade de automação.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDispatchDriver::operator \=](../Topic/COleDispatchDriver::operator%20=.md)|Copia o valor da fonte no objeto de `COleDispatchDriver` .|  
|[COleDispatchDriver::operator LPDISPATCH](../Topic/COleDispatchDriver::operator%20LPDISPATCH.md)|Acessa o ponteiro de `IDispatch` subjacente.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleDispatchDriver::m\_bAutoRelease](../Topic/COleDispatchDriver::m_bAutoRelease.md)|Especifica se liberar `IDispatch` durante `ReleaseDispatch` objeto ou a destruição.|  
|[COleDispatchDriver::m\_lpDispatch](../Topic/COleDispatchDriver::m_lpDispatch.md)|Indica o ponteiro para a interface de `IDispatch` anexada a este `COleDispatchDriver`.|  
  
## Comentários  
 `COleDispatchDriver` não tem uma classe base.  
  
 As interfaces VELHOS de distribuição fornecem acesso a métodos e propriedades de um objeto.  As funções de membro de anexo de `COleDispatchDriver` , desanexam, criam, e liberam uma conexão de distribuição de tipo `IDispatch`.  Outras funções de membro usam listas de argumentos variáveis para simplificar chamar **IDispatch::Invoke**.  
  
 Essa classe pode ser usada diretamente, mas é geralmente usada somente as classes criadas pelo assistente de classe adicionar.  Quando você cria novas classes C\+\+ importando uma biblioteca de tipo, as novas classes é derivado de `COleDispatchDriver`.  
  
 Para obter mais informações sobre como usar `COleDispatchDriver`artigos, consulte os seguintes:  
  
-   [Clientes de automação](../../mfc/automation-clients.md)  
  
-   [Servidores de automação](../../mfc/automation-servers.md)  
  
## Hierarquia de herança  
 `COleDispatchDriver`  
  
## Requisitos  
 **Cabeçalho:** afxdisp.h  
  
## Consulte também  
 [Exemplo CALCDRIV MFC](../../top/visual-cpp-samples.md)   
 [Exemplo ACDUAL MFC](../../top/visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)