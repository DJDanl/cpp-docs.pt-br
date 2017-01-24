---
title: "Classe CXMLAccessor | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL::CXMLAccessor"
  - "CXMLAccessor"
  - "ATL.CXMLAccessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CXMLAccessor"
ms.assetid: c88c082c-ec2f-4351-8947-a330b15e448a
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CXMLAccessor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que você acesse fontes de dados como dados de cadeia de caracteres quando você não tem conhecimento do esquema do repositório de dados \(estrutura subjacente\).  
  
## Sintaxe  
  
```  
class CXMLAccessor : public CDynamicStringAccessorW  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[GetXMLColumnData](../Topic/CXMLAccessor::GetXMLColumnData.md)|Recupera as informações da coluna.|  
|[GetXMLRowData](../Topic/CXMLAccessor::GetXMLRowData.md)|Recupera todo o conteúdo de uma tabela por linhas.|  
  
## Comentários  
 No entanto, `CXMLAccessor` difere de `CDynamicStringAccessorW` que converte todos os dados acessados no repositório de dados marcados como dados \(\) em formato XML.  Isso é especialmente útil para saída nas páginas da Web XML reconhecimento de instância.  Os nomes da marca XML serão os nomes de coluna do repositório de dados do mais próximo possível.  
  
 Use os métodos de `CDynamicAccessor` para obter informações de coluna.  Você usa essas informações de coluna para criar dinamicamente em tempo de execução um acessador.  
  
 As informações de coluna é armazenada em um buffer criada e gerenciada por essa classe.  Obtenha informações de coluna usando [GetXMLColumnData](../Topic/CXMLAccessor::GetXMLColumnData.md) ou obtenha dados de coluna por linhas que usam [GetXMLRowData](../Topic/CXMLAccessor::GetXMLRowData.md).  
  
## Exemplo  
 [!code-cpp[NVC_OLEDB_Consumer#14](../../data/oledb/codesnippet/CPP/cxmlaccessor-class_1.cpp)]  
  
## Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../Topic/CAccessor%20Class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)   
 [Classe CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)   
 [Classe CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)   
 [Classe CManualAccessor](../Topic/CManualAccessor%20Class.md)