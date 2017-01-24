---
title: "Classe CDynamicStringAccessor | Microsoft Docs"
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
  - "CDynamicStringAccessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDynamicStringAccessor"
ms.assetid: 138dc4de-c7c3-478c-863e-431e48249027
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CDynamicStringAccessor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite acessar uma fonte de dados quando você não tem conhecimento do esquema de base de dados \(a estrutura subjacente do base de dados\).  
  
## Sintaxe  
  
```  
  
      template< typename BaseType, DBTYPEENUM OleDbType >  
class CDynamicStringAccessorT : public CDynamicAccessor  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[GetString](../Topic/CDynamicStringAccessor::GetString.md)|Recupera os dados de coluna especificados como uma cadeia de caracteres.|  
|[SetString](../../data/oledb/cdynamicstringaccessor-setstring.md)|Define os dados de coluna especificados como uma cadeia de caracteres.|  
  
## Comentários  
 Quando [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) solicitar dados em formato nativo relatado pelo provedor, `CDynamicStringAccessor` solicita que o modo do provedor todos os dados tiverem acessado do repositório de dados como dados de cadeia de caracteres.  Isso é especialmente útil para as tarefas simples que não exigem o cálculo de valores no repositório de dados, como exibir ou imprimir o conteúdo do repositório de dados.  
  
 O tipo nativo de dados da coluna no repositório de dados não importa; desde que o provedor pode suportar a conversão de dados, fornecerá os dados em formato de cadeia de caracteres.  Se o provedor não oferecer suporte à conversão de tipo de dados nativo para uma cadeia de caracteres \(que não é comum\), a chamada de aplicativo retornará o valor com êxito **DB\_S\_ERRORSOCCURED**, e o status da coluna correspondente para indicar um problema de conversão com **DBSTATUS\_E\_CANTCONVERTVALUE**.  
  
 Use os métodos de `CDynamicStringAccessor` para obter informações de coluna.  Você usa essas informações de coluna para criar dinamicamente em tempo de execução um acessador.  
  
 As informações de coluna é armazenada em um buffer criada e gerenciada por essa classe.  Obtenha dados do buffer usando [GetString](../Topic/CDynamicStringAccessor::GetString.md), ou armazená\-los no buffer usando [SetString](../../data/oledb/cdynamicstringaccessor-setstring.md).  
  
 Para obter uma discussão e exemplos de usar as classes dinâmicas do acessador, consulte [Usando acessadores dinâmicos](../../data/oledb/using-dynamic-accessors.md).  
  
## Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../Topic/CAccessor%20Class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Classe CManualAccessor](../Topic/CManualAccessor%20Class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)   
 [Classe CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)   
 [Classe CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)