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
ms.openlocfilehash: dffefb74faf6836b9f2fc81a7800dc34084657cf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33093903"
---
# <a name="caccessor-class"></a>Classe CAccessor
Representa um dos tipos de acessador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template <class T>  
class CAccessor : public CAccessorBase, public T  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe de registro de usuário.  
  
## <a name="remarks"></a>Comentários  
 Ele é usado quando um registro é estaticamente vinculado a uma fonte de dados. O registro contém o buffer. Esta classe dá suporte a vários acessadores em um conjunto de linhas.  
  
 Use este tipo de acessador quando você conhece a estrutura e o tipo do banco de dados.  
  
 Se seu acessador contém campos que apontam para a memória (como um `BSTR` ou interface) que deve ser liberado, chame a função de membro [caccessorrowset:: Freerecordmemory](../../data/oledb/caccessorrowset-freerecordmemory.md) antes do próximo registro é lido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)