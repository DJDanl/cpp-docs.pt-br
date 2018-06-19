---
title: Determinando qual tipo de acessador a ser usado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- rowsets [C++], data types
- accessors [C++], types
ms.assetid: 22483dd2-f4e0-4dcb-8e4d-cd43a9c1a3db
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 89a55127b8f7e5e0e7d338a9e7ba4f85e8c568d2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33104003"
---
# <a name="determining-which-type-of-accessor-to-use"></a>Determinando qual tipo de acessador a ser usado
Você pode determinar os tipos de dados em um conjunto de linhas em tempo de compilação ou em tempo de execução.  
  
 Se você precisar determinar os tipos de dados em tempo de compilação, use um acessador estático (como `CAccessor`). Você pode determinar os tipos de dados manualmente ou usando o Assistente de ATL OLE DB consumidor.  
  
 Se você precisar determinar os tipos de dados em tempo de execução, use um dinâmico (`CDynamicAccessor` ou seus filhos) ou o acessador manual (`CManualAccessor`). Nesses casos, você pode chamar `GetColumnInfo` no conjunto de linhas para retornar as informações de associação de coluna, que você pode determinar tipos.  
  
 A tabela a seguir lista os tipos de acessadores fornecidos nos modelos de consumidor. Cada acessador tem vantagens e desvantagens. Dependendo da sua situação, um tipo de acessador deve atender às suas necessidades.  
  
|Classe de acessador|Associação|Parâmetro|Comentário|  
|--------------------|-------------|---------------|-------------|  
|`CAccessor`|Criar um registro de usuário com `COLUMN_ENTRY` macros. As macros associar um membro de dados no registro para o acessador. Quando o conjunto de linhas é criado, as colunas não podem ser desligadas.|Sim, usando um **PARAM_MAP** entrada de macro. Uma vez associado, parâmetros não podem ser desligados.|Acessador mais rápido devido a quantidade pequena de código.|  
|`CDynamicAccessor`|Automático.|Nº|Útil se você não souber o tipo de dados em um conjunto de linhas.|  
|`CDynamicParameterAccessor`|Automático, mas pode ser [substituído](../../data/oledb/overriding-a-dynamic-accessor.md).|Sim, se o provedor oferece suporte a `ICommandWithParameters`. Os parâmetros são associados automaticamente.|Mais lento do que `CDynamicAccessor` mas útil para chamar procedimentos armazenados genéricos.|  
|**CDynamicStringAccessor[A,W]**|Automático.|Nº|Recupera os dados acessados a partir do repositório de dados como dados de cadeia de caracteres.|  
|`CManualAccessor`|Usando manual `AddBindEntry`.|Manualmente usando `AddParameterEntry`.|Muito rápido; parâmetros e colunas associadas apenas uma vez. Determinar o tipo de dados para usar. (Consulte [DBVIEWER](http://msdn.microsoft.com/en-us/07620f99-c347-4d09-9ebc-2459e8049832) de exemplo para obter um exemplo.) Requer mais código que `CDynamicAccessor` ou `CAccessor`. É mais semelhante a chamar o OLE DB diretamente.|  
|`CXMLAccessor`|Automático.|Nº|Recupera os dados acessados a partir do repositório de dados como dados de cadeia de caracteres e formatos de dados marcados como XML.|  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)