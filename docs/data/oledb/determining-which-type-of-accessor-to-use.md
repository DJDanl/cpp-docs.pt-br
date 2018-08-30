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
ms.openlocfilehash: ef3da102cd01fa970fa50d687f6cfea57ac64325
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43199745"
---
# <a name="determining-which-type-of-accessor-to-use"></a>Determinando qual tipo de acessador a ser usado
Você pode determinar os tipos de dados em um conjunto de linhas em tempo de compilação ou tempo de execução.  
  
 Se você precisar determinar tipos de dados em tempo de compilação, use um acessador estática (como `CAccessor`). Você pode determinar os tipos de dados manualmente ou usando o ATL OLE DB Assistente de consumidor.  
  
 Se você precisar determinar os tipos de dados em tempo de execução, use dinâmico (`CDynamicAccessor` ou seus filhos) ou o acessador manual (`CManualAccessor`). Nesses casos, você pode chamar `GetColumnInfo` no conjunto de linhas para retornar as informações de associação de coluna da qual você pode determinar os tipos.  
  
 A tabela a seguir lista os tipos dos acessadores fornecidos nos modelos do consumidor. Cada acessador tem vantagens e desvantagens. Dependendo da sua situação, um tipo de acessador deve atender às suas necessidades.  
  
|Classe de acessador|Associação|Parâmetro|Comentário|  
|--------------------|-------------|---------------|-------------|  
|`CAccessor`|Crie um registro de usuário com macros COLUMN_ENTRY. As macros de associar um membro de dados no registro para o acessador. Quando o conjunto de linhas é criado, as colunas não podem ser desligadas.|Sim, usando uma entrada de macro PARAM_MAP. Uma vez associado, parâmetros não podem ser desligados.|Acessador mais rápido devido à pequena quantidade de código.|  
|`CDynamicAccessor`|Automático.|Nº|É útil se você não souber o tipo de dados em um conjunto de linhas.|  
|`CDynamicParameterAccessor`|Automático, mas pode ser [substituído](../../data/oledb/overriding-a-dynamic-accessor.md).|Sim, se o provedor oferece suporte a `ICommandWithParameters`. Os parâmetros associados automaticamente.|Mais lento do que `CDynamicAccessor` , mas útil para chamar procedimentos armazenados genéricos.|  
|`CDynamicStringAccessor[A,W]`|Automático.|Nº|Recupera os dados acessados do armazenamento de dados como dados de cadeia de caracteres.|  
|`CManualAccessor`|Manual usando `AddBindEntry`.|Manualmente usando `AddParameterEntry`.|Muito rápido; parâmetros e colunas associadas a apenas uma vez. Você determinar o tipo de dados a serem usados. (Consulte [DBVIEWER](https://msdn.microsoft.com/07620f99-c347-4d09-9ebc-2459e8049832) exemplo para obter um exemplo.) Requer mais código que `CDynamicAccessor` ou `CAccessor`. É mais semelhante a chamar diretamente o banco de dados OLE.|  
|`CXMLAccessor`|Automático.|Nº|Recupera os dados acessados do armazenamento de dados como dados de cadeia de caracteres e formatos de dados marcados como XML.|  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)