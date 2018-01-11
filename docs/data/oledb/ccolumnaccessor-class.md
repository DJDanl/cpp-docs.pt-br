---
title: Classe CColumnAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CColumnAccessor
- ATL::CColumnAccessor
- ATL.CColumnAccessor
dev_langs: C++
helpviewer_keywords: CColumnAccessor class
ms.assetid: 6ce1e67f-6a20-490d-9326-c168b43eee7e
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 55c77a53cb6e6c4a103c509aa3d527803d91af3f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccolumnaccessor-class"></a>Classe CColumnAccessor
Gera código injetado consumidor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CColumnAccessor : public CAccessorBase  
```  
  
## <a name="remarks"></a>Comentários  
 No código injetado, cada coluna é associada como um acessador separado. Você deve estar ciente de que essa classe é usada no código injetado (por exemplo, você pode encontrá-lo durante a depuração), mas normalmente não é necessário usar ele ou seus métodos diretamente.  
  
 `CColumnAccessor`implementa os seguintes métodos de stub, cada um dos quais correspondem na funcionalidade de outros métodos de classe de acessador:  
  
-   `CColumnAccessor`O construtor; cria e inicializa o `CColumnAccessor` objeto.  
  
-   `CreateAccessor`Aloca memória para a coluna de estruturas de associação e inicializa os membros de dados de coluna.  
  
-   **BindColumns** associa as colunas para os acessadores.  
  
-   **SetParameterBuffer** aloca buffers para parâmetros.  
  
-   `AddParameter`Adiciona uma entrada de parâmetro para as estruturas de entrada de parâmetro.  
  
-   **HasOutputColumns** determina se o acessador de colunas de saída  
  
-   **HasParameters** determina se o acessador possui parâmetros.  
  
-   `BindParameters`Associa os parâmetros criados para colunas.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)