---
title: Definindo procedimentos armazenados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- stored procedures, syntax
- OLE DB, stored procedures
- stored procedures, defining
- stored procedures, OLE DB
ms.assetid: 54949b81-3275-4dd9-96e4-3eda1ed755f2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1e03a5ae2e7c75d905216a6be92630376484d047
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33101296"
---
# <a name="defining-stored-procedures"></a>Definindo procedimentos armazenados
Antes de chamar um procedimento armazenado, você deve primeiro definir, usando o [DEFINE_COMMAND](../../data/oledb/define-command.md) macro. Quando você define o comando, denota parâmetros com um ponto de interrogação (?) como o marcador de parâmetro:  
  
```  
DEFINE_COMMAND(CMySProcAccessor, _T("{INSERT {name, phone} into shippers  (?,?)}")  
```  
  
 Observe que a sintaxe (o uso de chaves e assim por diante) usada nos exemplos de código neste tópico é específica ao SQL Server. A sintaxe que você use os procedimentos armazenados pode variar de acordo com o provedor que você usa.  
  
 Em seguida, no mapa de parâmetro, especifique os parâmetros que você usou no comando, listando os parâmetros na ordem em que eles ocorrem no comando:  
  
```  
BEGIN_PARAM_MAP(CMySProcAccessor)  
   SET_PARAM_TYPE(DBPARAMIO_INPUT)  
   COLUMN_ENTRY(1, m_Name)   // name corresponds to first '?' param  
   SET_PARAM_TYPE(DBPARAMIO_INPUT)  
   COLUMN_ENTRY(2, m_Phone)  // phone corresponds to second '?' param  
END_PARAM_MAP()  
```  
  
 O exemplo anterior define um procedimento armazenado quando ele passa. Normalmente, para reutilização eficiente de código, um banco de dados contém um conjunto de procedimentos armazenados predefinidos com nomes como "Vendas por ano" ou "dt_adduserobject". Você pode exibir suas definições usando o SQL Server Enterprise Manager. Chamá-los da seguinte maneira (o posicionamento do '?' depende de parâmetros na interface do procedimento armazenado):  
  
```  
DEFINE_COMMAND(CMySProcAccessor, _T("{CALL \"Sales by Year\" (?,?) }")  
DEFINE_COMMAND(CMySProcAccessor, _T("{CALL dbo.dt_adduserobject (?,?) }")  
```  
  
 Em seguida, declara a classe de comando:  
  
```  
class CMySProc : public CCommand<CAccessor<CMySProcAccessor>>  
```  
  
 Finalmente, chame o procedimento armazenado `OpenRowset` da seguinte maneira:  
  
```  
CSession m_session;  

HRESULT OpenRowset()  
{  
   return CCommand<CAccessor<CMySProcAccessor>>::Open(m_session);  
}  
```  
  
 Observe também que você pode definir um procedimento armazenado usando o atributo de banco de dados [db_command](../../windows/db-command.md) da seguinte maneira:  
  
```  
db_command("{ ? = CALL dbo.dt_adduserobject }")  
```  
  
## <a name="see-also"></a>Consulte também  
 [Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)