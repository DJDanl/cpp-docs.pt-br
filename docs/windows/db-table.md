---
title: "db_table | Microsoft Docs"
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
  - "vc-attr.db_table"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "db_table attribute"
ms.assetid: ff9eb957-4e6d-4175-afcc-fd8ea916cec0
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# db_table
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Abre uma tabela OLE DB.  
  
## Sintaxe  
  
```  
  
      [ db_table(   
   db_table,   
   name,   
   source_name,   
   hresult   
) ]  
```  
  
#### Parâmetros  
 *db\_table*  
 Uma seqüência de caracteres especificando o nome de uma tabela de banco de dados \(por exemplo, "produtos"\).  
  
 *nome*  \(opcional\)  
 O nome do identificador que você usa para trabalhar com a tabela.  Você deve especificar esse parâmetro se desejar retornar mais de uma linha de resultados.  **db\_table** gera uma variável com o especificado  *nome* que pode ser usado para percorrer o conjunto de linhas ou executar várias consultas de ação.  
  
 *source\_name*  \(opcional\)  
 O `CSession` variável ou instância de uma classe que tem o `db_source` atributo aplicado a ele no qual o comando será executado.  Consulte  [db\_source](../windows/db-source.md).  
  
 `hresult`\(opcional\)  
 Identifica a variável que receberá o `HRESULT` deste comando de banco de dados.  Se a variável não existir, ele será automaticamente injetado pelo atributo.  
  
## Comentários  
 **db\_table** cria um  [CTable](../data/oledb/ctable-class.md) objeto, que é usado por um consumidor de OLE DB para abrir uma tabela.  Você pode usar esse atributo apenas no nível de classe; Você não pode usá\-lo inline.  Use  **db\_column** vincular as colunas da tabela a variáveis; Use  **db\_param** delimitar \(define o tipo de parâmetro e, portanto, em\) dos parâmetros.  
  
 Quando o provedor de atributo do consumidor aplica esse atributo para uma classe, o compilador irá renomear a classe para \_*YourClassName*acessador, onde  *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada  *YourClassName,*  que é derivada de \_*YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.  
  
## Exemplo  
 O exemplo a seguir abre a tabela de produtos para uso por `CProducts`.  
  
```  
// db_table.cpp  
// compile with: /LD  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
  
[ db_table(L"dbo.Products") ]  
class CProducts {  
   [ db_column("1") ] LONG m_ProductID;  
};  
```  
  
 Para obter um exemplo desse atributo usado em um aplicativo, consulte os exemplos  [AtlAgent](http://msdn.microsoft.com/pt-br/52bef5da-c1a0-4223-b4e6-9e464b6db409) e  [MultiRead](http://msdn.microsoft.com/pt-br/5a2a915a-77dc-492f-94b2-1b809995dd5e).  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**,`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [OLE DB Consumer Attributes](../windows/ole-db-consumer-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)