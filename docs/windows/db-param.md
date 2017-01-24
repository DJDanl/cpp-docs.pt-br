---
title: "db_param | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.db_param"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "db_param attribute"
ms.assetid: a28315f5-4722-459e-92ef-32e83c0b205a
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# db_param
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Associa a variável de membro especificada com um parâmetro de entrada ou de saída e delimita a variável.  
  
## Sintaxe  
  
```  
  
      [ db_param(   
   ordinal,   
   paramtype="DBPARAMIO_INPUT",   
   dbtype,   
   precision,   
   scale,   
   status,   
   length  
) ]  
```  
  
#### Parâmetros  
 `ordinal`  
 O número da coluna \(**DBCOLUMNINFO** ordinal\) correspondente a um campo no conjunto de linhas ao qual vincular a dados.  
  
 *paramtype*  \(opcional\)  
 O tipo a ser definido para o parâmetro.  Provedores aceitam somente tipos de i\/O parâmetro que são suportados pela fonte de dados subjacente.  O tipo é uma combinação de um ou mais  **DBPARAMIOENUM** valores:  
  
-   **DBPARAMIO\_INPUT** um parâmetro de entrada.  
  
-   **DBPARAMIO\_OUTPUT** um parâmetro de saída.  
  
-   **DBPARAMIO\_NOTPARAM** o acessador não tem parâmetros.  Definindo  **eParamIO** para esse valor na linha acessadores lembra o usuário que os parâmetros são ignorados.  
  
 *DbType*  \(opcional\)  
 Um OLE DB  [Indicador do tipo](https://msdn.microsoft.com/en-us/library/ms711251.aspx) para a entrada de coluna.  
  
 *Precision*  \(opcional\)  
 A precisão a ser usado para a entrada de coluna.  Para obter detalhes, consulte a descrição do  **bPrecision** elemento da  [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)  
  
 *escala*  \(opcional\)  
 A escala a ser usado para a entrada de coluna.  Para obter detalhes, consulte a descrição do  **bScale** elemento da  [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)  
  
 *status*  \(opcional\)  
 Uma variável de membro usada para manter o status desta coluna.  O status indica se o valor da coluna é um valor de dados ou algum outro valor, como  **Nulo**.  Para obter valores possíveis, consulte  [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx) na  *referência OLE DB Programmer*.  
  
 *comprimento de*  \(opcional\)  
 Uma variável de membro usada para manter o tamanho da coluna em bytes.  
  
## Comentários  
 **db\_param** define os parâmetros que você usa comandos; portanto você usá\-lo com  **db\_command**.  Por exemplo, você pode usar  **db\_param** a ligação dos parâmetros no SQL consultas ou procedimentos armazenados.  Parâmetros em um procedimento armazenado são indicados por pontos de interrogação \(?\), e você deve vincular os membros de dados na ordem em que os parâmetros são exibidos.  
  
 **db\_param** delimita os dados de membros que podem participar do OLE DB `ICommandWithParameters`\-com base em ligação.  Ele define o tipo de parâmetro \(entrada ou saída\), o tipo de banco de dados OLE, precisão, escala, status e comprimento para o parâmetro especificado.  Este atributo insere as macros do consumidor de OLE DB BEGIN\_PARAM\_MAP...  END\_PARAM\_MAP.  Cada membro que você marcou com o  **db\_param** atributo ocupará uma entrada no mapa na forma de um COLUMN\_ENTRY.  
  
 **db\_param** é usado em conjunto com um a  [db\_table](../windows/db-table.md) ou  [db\_command](../windows/db-command.md) atributos.  
  
 Quando o provedor de atributo do consumidor aplica esse atributo para uma classe, o compilador irá renomear a classe para \_*YourClassName*acessador, onde  *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada  *YourClassName,*  que é derivada de \_*YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.  
  
## Exemplo  
 O exemplo a seguir cria uma classe de comando com base no procedimento SalesbyYear armazenado no banco de dados Northwind.  Ele associa o primeiro parâmetro no procedimento armazenado com o `m_RETURN_VALUE` variável e a define como um parâmetro de saída.  Ele associa os dois últimos parâmetros \(input\) com `m_Beginning_Date` e `m_Ending_Date`.  
  
 O exemplo a seguir associa o `nOutput` variável com um parâmetro de saída.  
  
```  
// db_param.cpp  
// compile with: /LD  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
  
[ db_source(L"my_connection_string"),   
  db_command(L"{ ? = CALL dbo.\"Sales by Year\"(?,?) }")   
]  
struct CSalesbyYear {  
   DBSTATUS m_dwShippedDateStatus;  
   DBSTATUS m_dwOrderIDStatus;  
   DBSTATUS m_dwSubtotalStatus;  
   DBSTATUS m_dwYearStatus;  
  
   DBLENGTH m_dwShippedDateLength;  
   DBLENGTH m_dwOrderIDLength;  
   DBLENGTH m_dwSubtotalLength;  
   DBLENGTH m_dwYearLength;  
  
   // Bind columns  
   [ db_column("1", status="m_dwShippedDateStatus", length="m_dwShippedDateLength") ] DBTIMESTAMP m_ShippedDate;  
   [ db_column("2", status="m_dwOrderIDStatus", length="m_dwOrderIDLength") ] LONG m_OrderID;  
   [ db_column("3", status="m_dwSubtotalStatus", length="m_dwSubtotalLength") ] CURRENCY m_Subtotal;  
   [ db_column("4", status="m_dwYearStatus", length="m_dwYearLength") ] TCHAR m_Year[31];  
  
   // Bind parameters  
   [ db_param("1", paramtype="DBPARAMIO_OUTPUT") ] LONG m_RETURN_VALUE;  
   [ db_param("2", paramtype="DBPARAMIO_INPUT") ] DBTIMESTAMP m_Beginning_Date;  
   [ db_param("3", paramtype="DBPARAMIO_INPUT") ] DBTIMESTAMP m_Ending_Date;  
};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**, `struct`, membro, método, local|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [OLE DB Consumer Attributes](../windows/ole-db-consumer-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)