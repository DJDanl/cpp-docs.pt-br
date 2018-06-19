---
title: Classe CNoRowset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CNoRowset
- ATL::CNoRowset<TAccessor>
- CNoRowset
- ATL.CNoRowset<TAccessor>
- ATL::CNoRowset
dev_langs:
- C++
helpviewer_keywords:
- CNoRowset class
ms.assetid: 55c6c7a4-9e3a-4775-a2dd-c8b333012fa6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 87d005dc19ef286bc4b0da927ecabcd90e6f0235
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33098154"
---
# <a name="cnorowset-class"></a>Classe CNoRowset
Pode ser usado como um argumento de modelo (`TRowset`) para [CCommand](../../data/oledb/ccommand-class.md) ou [CTable](../../data/oledb/ctable-class.md).  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CAccessorBase>  
class CNoRowset  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TAccessor`  
 Uma classe de acessador. O padrão é `CAccessorBase`.  
  
## <a name="remarks"></a>Comentários  
 Use `CNoRowset` como um argumento de modelo se o comando não retornar um conjunto de linhas.  
  
 `CNoRowset` implementa os seguintes métodos de stub, cada um dos quais corresponde a outros métodos de classe de acessador:  
  
-   **BindFinished** -indica quando a associação é concluída (retorna `S_OK`).  
  
-   **Fechar** -versões de linhas e a interface IRowset atual.  
  
-   `GetIID` -Recupera a ID de interface de um ponto de conexão.  
  
-   **GetInterface** -recupera uma interface.  
  
-   `GetInterfacePtr` -Recupera um ponteiro de interface encapsulado.  
  
-   **SetAccessor** -define um ponteiro para o acessador.  
  
-   **SetupOptionalRowsetInterfaces** -configura interfaces opcionais para o conjunto de linhas.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)