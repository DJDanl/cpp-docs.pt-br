---
title: "Registros de usu&#225;rio | Microsoft Docs"
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
  - "COLUMN_ENTRY_MAP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "acessadores [C++], conjuntos de linhas"
  - "acessadores [C++], estático"
  - "Macro BEGIN_ACCESSOR, exemplo"
  - "Macro BEGIN_ACCESSOR_MAP"
  - "Classe CAccessor, exemplo"
  - "Macro COLUMN_ENTRY"
  - "Macro COLUMN_ENTRY_MAP"
  - "Modelos de consumidor OLE DB, registros de usuário"
  - "conjuntos de linhas [C++], acessadores"
  - "registros de usuário, Modelos de consumidor OLE DB"
ms.assetid: 2de9e5eb-53ce-42b1-80fa-57d46600a80c
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registros de usu&#225;rio
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para usar um acessador estáticos \(isto é, um acessador derivado de **CAccessor\)**, o consumidor deve ter um registro de usuário.  O registro de usuário é a classe de criando c que contém elementos de dados para tratar a entrada ou a saída.  O assistente do consumidor de ATL OLE DB gerencie um registro de usuário para o consumidor.  Você pode adicionar métodos ao registro do usuário para tarefas opcionais como de manipulação.  
  
 O código a seguir mostra um registro de exemplo que trata comandos.  No registro do usuário, `BEGIN_COLUMN_MAP` representa um conjunto de linhas de dados passado ao consumidor do provedor.  `BEGIN_PARAM_MAP` representa um conjunto de parâmetros do comando.  Este exemplo usa uma classe de [CCommand](../../data/oledb/ccommand-class.md) para tratar os parâmetros de comando.  Os membros de dados nas entradas do mapa representam deslocamentos em um bloco contínuo de memória para cada instância da classe.  Macros de `COLUMN_ENTRY` correspondem a macros de `PROVIDER_COLUMN_ENTRY` no lado do provedor.  
  
 Para obter mais informações sobre macros de **COLUMN\_MAP** e de **PARAM\_MAP** , consulte [Macros para modelos do consumidor OLE DB](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md).  
  
```  
class CArtists  
{  
public:  
// Data Elements  
   CHAR m_szFirstName[20];  
   CHAR m_szLastName[30];  
   short m_nAge;  
  
// Column binding map  
BEGIN_COLUMN_MAP(CArtists)  
   COLUMN_ENTRY(1, m_szFirstName)  
   COLUMN_ENTRY(2, m_szLastName)  
   COLUMN_ENTRY(3, m_nAge)  
END_COLUMN_MAP()  
  
// Parameter binding map  
BEGIN_PARAM_MAP(CArtists)  
   COLUMN_ENTRY(1, m_nAge)  
END_PARAM_MAP()  
};  
```  
  
## Registros de usuário \- gerados  
 Se você usar o assistente do consumidor de ATL OLE DB para gerar um consumidor, você tem a opção de usar modelos OLE DB ou atributos OLE DB.  O código gerado é diferente em cada caso.  Para obter mais informações sobre esse código, consulte [Classes \- gerados do consumidor](../../data/oledb/consumer-wizard-generated-classes.md).  
  
## Suporte do registro do usuário para vários acessadores  
 Para uma descrição detalhada dos cenários em que você precisa usar vários acessadores, consulte [Usando vários acessadores em um conjunto de linhas](../Topic/Using%20Multiple%20Accessors%20on%20a%20Rowset.md).  
  
 O exemplo a seguir mostra o registro de usuário alterado para vários acessadores de suporte para o conjunto de linhas.  Em vez de `BEGIN_COLUMN_MAP` e de `END_COLUMN_MAP`, use [BEGIN\_ACCESSOR\_MAP](../../data/oledb/begin-accessor-map.md) e [BEGIN\_ACCESSOR](../../data/oledb/begin-accessor.md) para cada acessador.  A macro de `BEGIN_ACCESSOR` especifica o número de acessador \(deslocamento de zero\) e se o acessador é um autoaccessor.  Chame `GetData` de Autoaccessors para recuperar dados automaticamente em uma chamada para [MoveNext](../../data/oledb/crowset-movenext.md).  Os acessadores Nonautomatic exigem que você recuperar explicitamente os dados.  Use um acessador nonautomatic se você estiver associando a um grande campo de dados \(como uma imagem de bitmap\) que você não queira recuperar para cada registro.  
  
```  
class CMultiArtists  
{  
public:  
// Data Elements  
   CHAR m_szFirstName[20];  
   CHAR m_szLastName[30];  
   short m_nAge;  
  
// Column binding map  
BEGIN_ACCESSOR_MAP(CMultiArtists, 2)  
   BEGIN_ACCESSOR(0, true)    // true specifies an auto accessor  
    COLUMN_ENTRY(1, m_szFirstName)  
    COLUMN_ENTRY(2, m_szLastName)  
   END_ACCESSOR()  
   BEGIN_ACCESSOR(1, false)   // false specifies a manual accessor  
    COLUMN_ENTRY(3, m_nAge)  
   END_ACCESSOR()  
END_ACCESSOR_MAP()  
};  
```  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)