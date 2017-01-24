---
title: "db_accessor | Microsoft Docs"
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
  - "vc-attr.db_accessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "db_accessor attribute"
ms.assetid: ec407a9f-24d7-4822-96d4-7cc6a0301815
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# db_accessor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Grupos de  **db\_column** atributos que participam do `IAccessor`\-com base em ligação.  
  
## Sintaxe  
  
```  
  
      [ db_accessor(   
   num,   
   auto   
) ]  
```  
  
#### Parâmetros  
 *num*  
 Especifica o número de assessor \(um índice inteiro baseado em zero\).  Você deve especificar números de acessador aumentar solicitar, usando números inteiros ou valores definidos.  
  
 *auto*  
 Um valor booleano que especifica se o acessador é automaticamente recuperado \(**TRUE**\) ou não recuperar \(**FALSE**\).  
  
## Comentários  
 **db\_accessor** define o acessador subjacente do OLE DB para subseqüentes  **db\_column** e  **db\_param** atributos dentro da mesma classe ou função.  **db\_accessor** é utilizável no nível do membro e é usado para o grupo  **db\_column** atributos que participam do OLE DB `IAccessor`\-com base em ligação.  Ele é usado em conjunto com um a  **db\_table** ou  **db\_command** atributos.  Chamar esse atributo é semelhante a chamar o  [BEGIN\_ACCESSOR](../data/oledb/begin-accessor.md) e  [END\_ACCESSOR](../Topic/END_ACCESSOR.md) macros.  
  
 **db\_accessor** gera um conjunto de linhas e a vincula para os mapas de acessador correspondente.  Se você chamar  **db\_accessor**, assessor 0 será gerado automaticamente e todas as ligações de coluna serão mapeadas para este bloco de acessador.  
  
 **db\_accessor** ligações de coluna em um ou mais assessores de banco de dados de grupos.  Para uma discussão sobre os cenários em que você precisa usar vários assessores, consulte  [Usando vários assessores em um conjunto de linhas](../Topic/Using%20Multiple%20Accessors%20on%20a%20Rowset.md).  Além disso, consulte "Usuário registro suporte para vários assessores" em  [Registros de usuário](../data/oledb/user-records.md).  
  
 Quando o provedor de atributo do consumidor aplica esse atributo para uma classe, o compilador irá renomear a classe para \_*YourClassName*acessador, onde  *YourClassName* é o nome que você deu a classe e o compilador também criará uma classe chamada  *YourClassName,*  que é derivada de \_*YourClassName*acessador.  No modo de exibição de classe, você verá as duas classes.  
  
## Exemplo  
 O exemplo a seguir usa  **db\_accessor** às colunas de grupo da tabela Orders do banco de dados Northwind em dois acessadores.  O acessador 0 é um acessador automático e assessor 1 não está.  
  
```  
// cpp_attr_ref_db_accessor.cpp  
// compile with: /LD /link /OPT:NOREF  
#define _ATL_ATTRIBUTES  
#include <atlbase.h>  
#include <atldbcli.h>  
  
[ db_command(L"SELECT LastName, FirstName FROM Orders") ]  
class CEmployees {  
public:  
   [ db_accessor(0, TRUE) ];  
   [ db_column("1") ] LONG m_OrderID;  
   [ db_column("2") ] TCHAR m_CustomerID[6];  
   [ db_column("4") ] DBTIMESTAMP m_OrderDate;   
  
   [ db_accessor(1, FALSE) ];  
   [ db_column("8") ] CURRENCY m_Freight;  
};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Blocos de atributo|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [OLE DB Consumer Attributes](../windows/ole-db-consumer-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)