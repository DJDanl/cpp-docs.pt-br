---
title: db_param | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- vc-attr.db_param
dev_langs:
- C++
helpviewer_keywords:
- db_param attribute
ms.assetid: a28315f5-4722-459e-92ef-32e83c0b205a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b5224c406f6e10cd4ef9f0ed64fbdbd7c5cc8e62
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dbparam"></a>db_param
Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `ordinal`  
 O número da coluna (**DBCOLUMNINFO** ordinal) correspondente a um campo no conjunto de linhas para o qual associar dados.  
  
 *paramtype* (opcional)  
 O tipo a ser definido para o parâmetro. Provedores oferecem suporte apenas tipos de e/s parâmetros que são suportados pela fonte de dados subjacente. O tipo é uma combinação de um ou mais **DBPARAMIOENUM** valores:  
  
-   **DBPARAMIO_INPUT** um parâmetro de entrada.  
  
-   **DBPARAMIO_OUTPUT** um parâmetro de saída.  
  
-   **DBPARAMIO_NOTPARAM** o acessador não tem parâmetros. Configuração **eParamIO** para esse valor na linha acessadores lembra ao usuário que parâmetros são ignorados.  
  
 *DbType* (opcional)  
 OLE DB [indicador de tipo](https://msdn.microsoft.com/en-us/library/ms711251.aspx) para a entrada da coluna.  
  
 *precisão* (opcional)  
 A precisão a ser usado para a entrada da coluna. Para obter detalhes, consulte a descrição do **bPrecision** elemento o [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)  
  
 *escala* (opcional)  
 A escala a ser usado para a entrada da coluna. Para obter detalhes, consulte a descrição do **bScale** elemento o [estrutura DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)  
  
 *status* (opcional)  
 Uma variável de membro usada para manter o status dessa coluna. O status indica se o valor da coluna é um valor de dados ou algum outro valor, como **nulo**. Para obter os valores possíveis, consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx) no *referência do programador de DB OLE*.  
  
 *comprimento* (opcional)  
 Uma variável de membro usada para manter o tamanho da coluna em bytes.  
  
## <a name="remarks"></a>Comentários  
 **db_param** define os parâmetros que você pode usar comandos; portanto você usá-lo com **db_command**. Por exemplo, você pode usar **db_param** para associar parâmetros em consultas SQL ou procedimentos armazenados. Parâmetros em um procedimento armazenado são indicados pelos pontos de interrogação (?), e você deve associar os membros de dados na ordem em que os parâmetros aparecem.  
  
 **db_param** delimita os dados de membro que podem participar de OLE DB `ICommandWithParameters`-com base em associação. Ele define o tipo de parâmetro (entrada ou saída), tipo de OLE DB, precisão, escala, status e comprimento para o parâmetro especificado. Esse atributo insere as macros de consumidor OLE DB BEGIN_PARAM_MAP... END_PARAM_MAP. Cada membro que você marca com o **db_param** atributo ocupará uma entrada no mapa na forma de um COLUMN_ENTRY.  
  
 **db_param** é usada em conjunto com o o [db_table](../windows/db-table.md) ou [db_command](../windows/db-command.md) atributos.  
  
 Quando o provedor de atributo do consumidor aplica esse atributo a uma classe, o compilador irá renomear a classe \_ *YourClassName*acessador, onde *YourClassName* é o nome atribuído a classe e o compilador também criará uma classe chamada *YourClassName*, que é derivado de \_ *YourClassName*acessador.  No modo de exibição de classe, você verá as classes.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria uma classe de comando com base no procedimento SalesbyYear armazenado no banco de dados Northwind. Associa o primeiro parâmetro no procedimento armazenado com o `m_RETURN_VALUE` variável e define como um parâmetro de saída. Associa os dois últimos parâmetros (entrados) com `m_Beginning_Date` e `m_Ending_Date`.  
  
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
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, `struct`, membro, o método, o local|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de consumidor do OLE DB](../windows/ole-db-consumer-attributes.md)   
