---
title: "Classe CDynamicParameterAccessor | Microsoft Docs"
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
  - "ATL.CDynamicParameterAccessor"
  - "ATL::CDynamicParameterAccessor"
  - "CDynamicParameterAccessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDynamicParameterAccessor"
ms.assetid: 5f22626e-e80d-491f-8b3b-cedc50331960
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CDynamicParameterAccessor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Semelhante ao [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) mas obtém informações de parâmetro a ser definido chamando o [ICommandWithParameters](https://msdn.microsoft.com/en-us/library/ms712937.aspx) interface.  
  
## Sintaxe  
  
```  
class CDynamicParameterAccessor : public CDynamicAccessor  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-cdynamicparameteraccessor.md)|O construtor.|  
|[GetParam](../Topic/CDynamicParameterAccessor::GetParam.md)|Recupera os dados de parâmetro do buffer.|  
|[GetParamCount](../../data/oledb/cdynamicparameteraccessor-getparamcount.md)|Recupera o número de parâmetros no acessador.|  
|[GetParamIO](../../data/oledb/cdynamicparameteraccessor-getparamio.md)|Determina se o parâmetro especificado é um parâmetro de entrada ou saído.|  
|[GetParamLength](../Topic/CDynamicParameterAccessor::GetParamLength.md)|Recupera o comprimento do parâmetro especificado armazenado no buffer.|  
|[GetParamName](../../data/oledb/cdynamicparameteraccessor-getparamname.md)|Recupera o nome de um parâmetro especificado.|  
|[GetParamStatus](../../data/oledb/cdynamicparameteraccessor-getparamstatus.md)|Recupera o status do parâmetro especificado armazenado no buffer.|  
|[GetParamString](../../data/oledb/cdynamicparameteraccessor-getparamstring.md)|Recupera os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.|  
|[GetParamType](../../data/oledb/cdynamicparameteraccessor-getparamtype.md)|Recupera o tipo de dados de um parâmetro especificado.|  
|[SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md)|Define o buffer usando os dados de parâmetro.|  
|[SetParamLength](../../data/oledb/cdynamicparameteraccessor-setparamlength.md)|Define o comprimento do parâmetro especificado armazenado no buffer.|  
|[SetParamStatus](../../data/oledb/cdynamicparameteraccessor-setparamstatus.md)|Define o status do parâmetro especificado armazenado no buffer.|  
|[SetParamString](../../data/oledb/cdynamicparameteraccessor-setparamstring.md)|Define os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.|  
  
## Comentários  
 O provedor deve oferecer suporte `ICommandWithParameters` para o consumidor usar essa classe.  
  
 As informações de parâmetro são armazenadas em um buffer criadas e gerenciadas por essa classe. Obter dados de parâmetro de buffer usando [GetParam](../Topic/CDynamicParameterAccessor::GetParam.md) e [GetParamType](../../data/oledb/cdynamicparameteraccessor-getparamtype.md).  
  
 Para obter um exemplo demonstram como usar essa classe para executar um procedimento armazenado do SQL Server e obter os valores de parâmetro de saída, consulte o artigo Q058860, "como: executar um procedimento armazenado usando CDynamicParameterAccessor." Artigos da Base de Conhecimento estão disponíveis na documentação da biblioteca MSDN Visual Studio ou no [http:\/\/support.microsoft.com\/](http://support.microsoft.com).  
  
## Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../Topic/CAccessor%20Class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CManualAccessor](../Topic/CManualAccessor%20Class.md)