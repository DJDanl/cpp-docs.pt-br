---
title: Classe CNoAccessor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::CNoAccessor
- CNoAccessor
- ATL.CNoAccessor
dev_langs:
- C++
helpviewer_keywords:
- CNoAccessor class
ms.assetid: eb669ae5-0a56-49a3-9646-c4ae6239da31
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3110d20330d42fcb0816873ff3e8a25d1f8436ea
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33097348"
---
# <a name="cnoaccessor-class"></a>Classe CNoAccessor
Pode ser usado como um argumento de modelo (`TAccessor`) para classes de modelo, como `CCommand` e `CTable`, que exigem um argumento de classe de acessador.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CNoAccessor  
```  
  
## <a name="remarks"></a>Comentários  
 Use `CNoAccessor` como um argumento de modelo quando você não deseja que a classe para dar suporte a parâmetros ou colunas de saída.  
  
 `CNoAccessor` implementa os seguintes métodos de stub, cada um dos quais corresponde a outros métodos de classe de acessador:  
  
-   **BindColumns** -associa as colunas para os acessadores.  
  
-   `BindParameters` -Associa os parâmetros criados para colunas.  
  
-   **Associar** -cria associações.  
  
-   **Fechar** -fecha o acessador.  
  
-   `ReleaseAccessors` -Libera os acessadores criados pela classe.  
  
-   `FreeRecordMemory` -Libera quaisquer colunas no registro atual que precisam ser liberados.  
  
-   `GetColumnInfo` -Obtém informações de coluna do conjunto de linhas aberto.  
  
-   `GetNumAccessors` -Recupera o número de acessadores criado pela classe.  
  
-   `IsAutoAccessor` -Retorna true se os dados são recuperados automaticamente para o acessador durante uma operação de movimentação.  
  
-   `GetHAccessor` -Recupera o identificador do acessador de um acessador especificado.  
  
-   `GetBuffer` -Recupera o ponteiro para o buffer de indicador.  
  
-   **NoBindOnNullRowset** -impede que a associação de dados em conjuntos de linhas vazios.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)