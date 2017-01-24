---
title: "Determinando qual tipo de acessador a ser usado | Microsoft Docs"
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
  - "acessadores [C++], tipos"
  - "conjuntos de linhas [C++], tipos de dados"
ms.assetid: 22483dd2-f4e0-4dcb-8e4d-cd43a9c1a3db
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Determinando qual tipo de acessador a ser usado
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode determinar tipos de dados em um conjunto de linhas em tempo de compilação ou em tempo de execução.  
  
 Se precisar determinar em tempo de compilação tipos de dados, use um acessador estático \(como `CAccessor`\).  Você pode determinar os tipos de dados manualmente ou por meio do assistente do consumidor de ATL OLE DB.  
  
 Se precisar determinar em tempo de execução os tipos de dados, use um acessador dinâmico \(`CDynamicAccessor` ou seus filhos\) ou manual \(`CManualAccessor`\).  Nesses casos, você pode chamar `GetColumnInfo` no conjunto de linhas para retornar informações de associação de coluna, que você pode determinar tipos.  
  
 A tabela a seguir lista os tipos de acessadores fornecidos nos modelos de consumidor.  Cada acessador tem vantagens e desvantagens.  Dependendo de sua situação, um tipo de acessador deve atender às suas necessidades.  
  
|A classe do acessador|Associação|Parâmetro|Comment|  
|---------------------------|----------------|---------------|-------------|  
|`CAccessor`|Crie um registro de usuário com macros de `COLUMN_ENTRY` .  Macros associam um membro de dados nesse registro no acessador.  Quando o conjunto de linhas é criado, as colunas não podem ser não associadas.|Sim, usando uma entrada de macro de **PARAM\_MAP** .  Uma vez que os parâmetros associados, não podem ser associados.|O acessador o mais rápido devido à quantidade pequena de código.|  
|`CDynamicAccessor`|Automático.|Não.|Útil se você não souber o tipo de dados em um conjunto de linhas.|  
|`CDynamicParameterAccessor`|O automático, mas pode ser [preterido](../../data/oledb/overriding-a-dynamic-accessor.md).|Sim, se o provedor oferecer suporte a `ICommandWithParameters`.  Parâmetros associados automaticamente.|Mais lento do que `CDynamicAccessor` mas útil para chamar procedimentos armazenados genéricas.|  
|**\[CDynamicStringAccessorTE O, W\]**|Automático.|Não.|Recupera os dados acessados no repositório de dados como dados de cadeia de caracteres.|  
|`CManualAccessor`|`AddBindEntry`de utilização manual.|Manualmente usando `AddParameterEntry`.|Muito rapidamente; os parâmetros e as colunas associadas apenas uma vez.  Você determina o tipo de dados a ser utilizada. \(Consulte o exemplo de [DBVIEWER](http://msdn.microsoft.com/pt-br/07620f99-c347-4d09-9ebc-2459e8049832) para obter um exemplo.\) Requer mais códigos do que `CDynamicAccessor` ou `CAccessor`.  É mais como chamar OLE DB diretamente.|  
|`CXMLAccessor`|Automático.|Não.|Recupera os dados acessados no repositório de dados como dados e formatos de cadeia de caracteres ele dados marcados como XML.|  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)