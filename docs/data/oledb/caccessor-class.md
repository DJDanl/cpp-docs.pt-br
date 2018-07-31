---
title: Classe CAccessor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CAccessor<T>
- ATL::CAccessor
- CAccessor
- ATL::CAccessor<T>
- ATL.CAccessor
dev_langs:
- C++
helpviewer_keywords:
- CAccessor class
ms.assetid: b2ba959f-a686-46f3-8837-176248aef748
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9e7f722d4d1759bdec7a23bb15076b38de000eb6
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39337411"
---
# <a name="caccessor-class"></a>Classe CAccessor
Representa um dos tipos de acessador.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
template <class T>  
class CAccessor : public CAccessorBase, public T  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 A classe de registro de usuário.  
  
## <a name="remarks"></a>Comentários  
 Ele é usado quando um registro é estaticamente vinculado a uma fonte de dados. O registro contém o buffer. Esta classe dá suporte a vários acessadores em um conjunto de linhas.  
  
 Use esse tipo de acessador quando você souber a estrutura e o tipo do banco de dados.  
  
 Se seu acessador contém campos que apontam para a memória (como uma `BSTR` ou a interface) que deve ser liberado, chame a função de membro [caccessorrowset:: Freerecordmemory](../../data/oledb/caccessorrowset-freerecordmemory.md) antes que o próximo registro é lido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)