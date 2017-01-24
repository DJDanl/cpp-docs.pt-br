---
title: "Par&#226;metros de sa&#237;da | Microsoft Docs"
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
  - "procedimentos armazenados, chamando"
  - "procedimentos armazenados, parâmetros"
  - "chamadas de procedimento"
  - "chamadas de procedimento, procedimentos armazenados"
ms.assetid: 4f7c2700-1c2d-42f3-8c9f-7e83962b2442
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Par&#226;metros de sa&#237;da
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chamar um procedimento armazenado é semelhante a chamar um comando SQL. A principal diferença é que procedimentos armazenados usam parâmetros de saída \(ou "outparameters"\) e valores de retorno.  
  
 O seguinte procedimento armazenado, o primeiro '? 'é o valor de retorno \(telefone\) e o segundo'?' é um parâmetro de entrada \(nome\):  
  
```  
DEFINE_COMMAND(CMySProcAccessor, _T("{ ? = SELECT phone FROM shippers WHERE name = ? }")  
```  
  
 Especifique os parâmetros in e out no mapa de parâmetro:  
  
```  
BEGIN_PARAM_MAP(CMySProcAccessor)  
   SET_PARAM_TYPE(DBPARAMIO_OUTPUT)  
   COLUMN_ENTRY(1, m_Phone)   // Phone is the return value  
   SET_PARAM_TYPE(DBPARAMIO_INPUT)  
   COLUMN_ENTRY(2, m_Name)   // Name is the input parameter  
END_PARAM_MAP()  
```  
  
 Seu aplicativo deve tratar a saída retornada de procedimentos armazenados. Provedores OLE DB diferentes retornam parâmetros de saída e valores de retorno em momentos diferentes durante o processamento de resultados. Por exemplo, o Microsoft OLE DB provider for SQL Server \(SQLOLEDB\) não fornecer parâmetros de saída e retornar códigos até depois que o consumidor tiver recuperado ou cancelado os conjuntos de resultados retornados pelo procedimento armazenado. A saída é retornada no último pacote TDS do servidor.  
  
## Contagem de linhas  
 Se você usar os modelos do consumidor de banco de dados OLE para executar um procedimento armazenado que tem outparameters, a contagem de linhas não é definida até que você feche o conjunto de linhas.  
  
 Por exemplo, considere um procedimento armazenado com um conjunto de linhas e um outparameter:  
  
```  
create procedure sp_test  
   @_rowcount integer output  
as  
   select top 50 * from test  
   @_rowcount = @@rowcount  
return 0  
```  
  
 O outparameter @\_rowcount informa quantas linhas foram realmente retornadas da tabela de teste. No entanto, esse procedimento armazenado limita o número de linhas a um máximo de 50. Por exemplo, se houver 100 linhas no teste, o número de linhas seria 50 \(porque esse código recupera apenas as primeiras 50 linhas\). Se houver apenas 30 linhas na tabela, o número de linhas seria 30. Você deve chamar **Fechar** ou **CloseAll** para preencher o outparameter antes de buscar o seu valor.  
  
## Consulte também  
 [Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)