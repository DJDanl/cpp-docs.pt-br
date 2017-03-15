---
title: "db_source | Microsoft Docs"
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
  - "vc-attr.db_source"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "db_source attribute"
ms.assetid: 0ec8bbf7-ade2-4899-bf4c-8608b92779bc
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# db_source
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria a conexão com a fonte de dados.  
  
## Sintaxe  
  
```  
  
      [ db_source(   
   db_source,   
   name,   
   hresult   
) ]  
```  
  
#### Parâmetros  
 *db\_source*  
 A seqüência de conexão usada para se conectar à fonte de dados.  Para o formato da seqüência de conexão, consulte  [seqüências de conexão e vínculos de dados](https://msdn.microsoft.com/en-us/library/ms718376.aspx) no Microsoft Data Access Components \(MDAC\) SDK.  
  
 *nome*  \(opcional\)  
 Quando você usa `db_source` em uma classe,  *nome* é uma instância de um objeto de fonte de dados que tem o `db_source` atributo aplicado a ele \(veja exemplo 1\).  Quando você usa `db_source` in\-line em uma implementação do método,  *nome* é uma variável \(local para o método\) que pode ser usada para acessar os dados de origem \(veja exemplo 2\).  Passá\-lo  *nome* para o `source_name` parâmetro do  **db\_command** para associar a um comando de fonte de dados.  
  
 `hresult`\(opcional\)  
 Identifica a variável que receberá o `HRESULT` deste comando de banco de dados.  Se a variável não existir, ele será automaticamente injetado pelo atributo.  
  
## Comentários  
 `db_source`cria um  [CDataSource](../Topic/CDataSource%20Class.md) e um  [CSession](../data/oledb/csession-class.md) objeto, que juntas, representam uma conexão com uma fonte de dados do consumidor de OLE DB.  
  
 Quando você usa `db_source` em uma classe, o `CSession` o objeto se torna um membro da classe.  
  
 Quando você usa `db_source` em um método, o código injetado será executado no escopo do método e o `CSession` objeto é criado como uma variável local.  
  
 `db_source`Adiciona as propriedades da fonte de dados para uma classe ou dentro de um método.  Ele é usado em conjunto com  **db\_command** \(qual toma o `db_source`*nome* parâmetro como seu `source_name` parâmetro\).  
  
 Quando o provedor de atributo do consumidor aplica esse atributo para uma classe, o compilador irá renomear a classe para \_*YourClassName*acessador, onde  *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada  *YourClassName,*  que é derivada de \_*YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.  
  
 Para obter um exemplo desse atributo usado em um aplicativo, consulte os exemplos  [AtlAgent](http://msdn.microsoft.com/pt-br/52bef5da-c1a0-4223-b4e6-9e464b6db409) e  [MultiRead](http://msdn.microsoft.com/pt-br/5a2a915a-77dc-492f-94b2-1b809995dd5e).  
  
## Exemplo  
 Este exemplo chama `db_source` em uma classe para criar uma conexão com a fonte de dados `ds` usando o banco de dados Northwind.  `ds`é um identificador para a fonte de dados, que pode ser usado internamente para o `CMyCommand` classe.  
  
```  
// db_source_1.cpp  
// compile with: /LD  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atldbcli.h>  
  
[  
  db_source(L"my_connection_string", name="ds"),  
  db_command(L"select * from Products")  
]  
class CMyCommand {};  
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