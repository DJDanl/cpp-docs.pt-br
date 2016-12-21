---
title: "Definindo procedimentos armazenados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "OLE DB, procedimentos armazenados"
  - "procedimentos armazenados, definindo"
  - "procedimentos armazenados, OLE DB"
  - "procedimentos armazenados, sintaxe"
ms.assetid: 54949b81-3275-4dd9-96e4-3eda1ed755f2
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo procedimentos armazenados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Antes de chamar um procedimento armazenado, primeiro você deve defini\-lo, usando a macro de [DEFINE\_COMMAND](../../data/oledb/define-command.md) .  Quando você define o comando, denote parâmetros com um ponto de interrogação \(?\) como o marcador de parâmetro:  
  
```  
DEFINE_COMMAND(CMySProcAccessor, _T("{INSERT {name, phone} into shippers  (?,?)}")  
```  
  
 Observe que a sintaxe \(o uso de chaves e assim por diante\) usada nos exemplos de código neste tópico é pertinente ao SQL Server.  A sintaxe que você usa em seus procedimentos armazenados podem variar de acordo com o provedor que você usa.  
  
 Em seguida, no mapa do parâmetro, especifique os parâmetros que você usou no comando, listando os parâmetros na ordem correta do comando:  
  
```  
BEGIN_PARAM_MAP(CMySProcAccessor)  
   SET_PARAM_TYPE(DBPARAMIO_INPUT)  
   COLUMN_ENTRY(1, m_Name)   // name corresponds to first '?' param  
   SET_PARAM_TYPE(DBPARAMIO_INPUT)  
   COLUMN_ENTRY(2, m_Phone)  // phone corresponds to second '?' param  
END_PARAM_MAP()  
```  
  
 O exemplo anterior define um procedimento armazenado desde que vai.  Normalmente, para reutilização eficiente de código, um base de dados contém um conjunto de procedimentos armazenados predefinidos com nomes como “vendas do ano” ou “por dt\_adduserobject”. Você pode exibir suas definições usando o gerenciador do SQL Server Enterprise.  Você chamar os seguintes \(a colocação de “?” os parâmetros dependem da interface de procedimento armazenado\):  
  
```  
DEFINE_COMMAND(CMySProcAccessor, _T("{CALL \"Sales by Year\" (?,?) }")  
DEFINE_COMMAND(CMySProcAccessor, _T("{CALL dbo.dt_adduserobject (?,?) }")  
```  
  
 Em seguida, declara a classe de comando:  
  
```  
class CMySProc : public CCommand<CAccessor<CMySProcAccessor> >  
```  
  
 Finalmente, chame o procedimento armazenado em `OpenRowset` como segue:  
  
```  
CSession m_session;  
HRESULT OpenRowset()  
{  
   return CCommand<CAccessor<CMySProcAccessor> >::Open(m_session);  
}  
```  
  
 Observe também que você pode definir um procedimento armazenado usando o atributo [db\_command](../../windows/db-command.md) de base de dados da seguinte maneira:  
  
```  
db_command("{ ? = CALL dbo.dt_adduserobject }")  
```  
  
## Consulte também  
 [Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)