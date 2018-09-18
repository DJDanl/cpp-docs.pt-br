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
ms.openlocfilehash: b1843b6279cb7c86762cc6d975a2a7e67d3d278d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46055631"
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
  
- `CColumnAccessor` O construtor; cria uma instância e inicializa o `CColumnAccessor` objeto.  
  
- `CreateAccessor` Aloca memória para a coluna de estruturas de associação e inicializa os membros de dados de coluna.  
  
- `BindColumns` Associa as colunas para acessadores.  
  
- `SetParameterBuffer` Aloca buffers para parâmetros.  
  
- `AddParameter` Adiciona uma entrada de parâmetro para as estruturas de entrada de parâmetro.  
  
- `HasOutputColumns` Determina se o acessador de colunas de saída  
  
- `HasParameters` Determina se o acessador possui parâmetros.  
  
- `BindParameters` Associa os parâmetros criados para colunas.  
  
## <a name="requirements"></a>Requisitos  

**Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)