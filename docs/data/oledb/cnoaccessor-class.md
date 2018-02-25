---
title: Classe CNoAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 02d577350a4a4221a2dcf9a8a3364de9ea4ce44e
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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