---
title: "Acessadores e conjuntos de linhas | Microsoft Docs"
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
  - "acessadores [C++]"
  - "acessadores [C++], conjuntos de linhas"
  - "conjuntos de linhas de matriz"
  - "conjuntos de linhas em massa"
  - "Classe CAccessorBase"
  - "Classe CAccessorRowset, tipos de acessadores"
  - "Classe CArrayRowset, acessadores"
  - "Classe CBulkRowset, acessadores"
  - "Classe CRowset, acessadores e conjuntos de linhas"
  - "Modelos de consumidor OLE DB, acessadores"
  - "Modelos de consumidor OLE DB, suporte a conjunto de linhas"
  - "conjuntos de linhas [C++], acessando"
  - "conjuntos de linhas [C++], tipos com suporte"
  - "conjuntos de linhas únicos"
ms.assetid: edc9c8b3-1a2d-4c2d-869f-7e058c631042
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acessadores e conjuntos de linhas
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para definir e recuperar dados, os modelos OLE DB usam um acessador e um conjunto de linhas pela classe de [CAccessorRowset](../Topic/CAccessorRowset%20Class.md) .  Esta classe pode tratar vários acessadores de tipos diferentes.  
  
## Tipos de acessador  
 Todos os acessadores derivam de [CAccessorBase](../../data/oledb/caccessorbase-class.md).  `CAccessorBase` fornece o parâmetro e a associação de coluna.  
  
 A figura a seguir mostra os tipos de acessador.  
  
 ![Tipos de acessador](../../data/oledb/media/vcaccessortypes.png "vcAccessorTypes")  
Classes de acessador  
  
-   uso de[CAccessor](../Topic/CAccessor%20Class.md)esse acessador quando você souber a estrutura de origem da base de dados em tempo de design.  `CAccessor` associa estatisticamente um registro base de dados do, que contém o buffer, à fonte de dados.  
  
-   uso de[CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)esse acessador quando você não conhecer a estrutura do base de dados em tempo de design.  `CDynamicAccessor` chama `IColumnsInfo::GetColumnInfo` para obter as informações de coluna de base de dados.  Criar e gerenciar um acessador e o buffer.  
  
-   o uso de[CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)esse acessador tratar comando desconhecido digita.  Quando você prepara os comandos, `CDynamicParameterAccessor` pode obter informações de parâmetro da interface de `ICommandWithParameters` , se o provedor oferecer suporte a `ICommandWithParameters`.  
  
-   [CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md), [CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md), e uso de [CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)essas classes quando você não tenha nenhum conhecimento do esquema de base de dados.  `CDynamicStringAccessorA` recupera dados como cadeias de caracteres ANSI; `CDynamicStringAccessorW` recupera dados como cadeias de caracteres Unicode.  
  
-   [CManualAccessor](../Topic/CManualAccessor%20Class.md) com essa classe, você pode usar qualquer os tipos de dados que você deseja se o provedor pode converter o tipo.  Trata colunas de resultados e parâmetros do comando.  
  
 A tabela a seguir resume o suporte nos tipos de modelo do acessador OLE DB.  
  
|Tipo de acessador|Dynamic|Trata param|Buffer|Vários acessadores|  
|-----------------------|-------------|-----------------|------------|------------------------|  
|`CAccessor`|Não|Sim|Usuário|Sim|  
|`CDynamicAccessor`|Sim|Não|Modelos OLE DB|Não|  
|`CDynamicParameterAccessor`|Sim|Sim|Modelos OLE DB|Não|  
|`CDynamicStringAccessor[A,W]`|Sim|Não|Modelos OLE DB|Não|  
|`CManualAccessor`|Sim|Sim|Usuário|Sim|  
  
## Tipos de conjunto de linhas  
 Os tipos de suporte dos três modelos OLE DB dos conjuntos de linhas \(consulte a figura precedente\): escolha os conjuntos de linhas \(implementados por [CRowset](../Topic/CRowset%20Class.md)\), os conjuntos de linhas em massa \(implementados por [CBulkRowset](../Topic/CBulkRowset%20Class.md)\), e os conjuntos de linhas de matriz \(implementados por [CArrayRowset](../../data/oledb/carrayrowset-class.md)\).  Escolha a busca dos conjuntos de linhas um único identificador de linha `MoveNext` quando é chamado.  Os conjuntos de linhas em massa podem buscar a vários identificadores de linha.  Os conjuntos de linhas da matriz são os conjuntos de linhas que podem ser acessados usando a sintaxe da matriz.  
  
 A figura a seguir mostra os tipos de conjunto de linhas.  
  
 ![De RowsetType](../Image/vcRowsetTypes.gif "vcRowsetTypes")  
Classes do conjunto de linhas  
  
 [Conjuntos de linhas de esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md) não acessa dados no repositório de dados acessa mas sim as informações sobre o armazenamento de dados, chamadas de metadados.  Conjuntos de linhas de esquema são usados normalmente em situações em que a estrutura de base de dados não é conhecida em tempo de compilação e deve ser obtida em tempo de execução.  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)