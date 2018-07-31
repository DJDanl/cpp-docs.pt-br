---
title: Classe CColumnAccessor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CColumnAccessor
- ATL::CColumnAccessor
- ATL.CColumnAccessor
dev_langs:
- C++
helpviewer_keywords:
- CColumnAccessor class
ms.assetid: 6ce1e67f-6a20-490d-9326-c168b43eee7e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4c55b2e10112c38835bb1f230970db56a6f53d4e
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39341056"
---
# <a name="ccolumnaccessor-class"></a>Classe CColumnAccessor
Gera o código injetado de consumidor.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CColumnAccessor : public CAccessorBase  
```  
  
## <a name="remarks"></a>Comentários  
 No código injetado, cada coluna é associada como um acessador separado. Você deve estar ciente de que essa classe é usada no código injetado (por exemplo, você pode encontrá-lo ao depuração), mas normalmente você nunca precisará usá-la ou seus métodos diretamente.  
  
 `CColumnAccessor` implementa os seguintes métodos de stub, cada um dos quais correspondem na funcionalidade para outros métodos de classe de acessador:  
  
-   `CColumnAccessor` O construtor; cria uma instância e inicializa o `CColumnAccessor` objeto.  
  
-   `CreateAccessor` Aloca memória para a coluna de estruturas de associação e inicializa os membros de dados de coluna.  
  
-   `BindColumns` Associa as colunas para acessadores.  
  
-   `SetParameterBuffer` Aloca buffers para parâmetros.  
  
-   `AddParameter` Adiciona uma entrada de parâmetro para as estruturas de entrada de parâmetro.  
  
-   `HasOutputColumns` Determina se o acessador de colunas de saída  
  
-   `HasParameters` Determina se o acessador possui parâmetros.  
  
-   `BindParameters` Associa os parâmetros criados para colunas.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)