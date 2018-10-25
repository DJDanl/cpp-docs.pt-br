---
title: Classe CNoMultipleResults | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CNoMultipleResults
- ATL.CNoMultipleResults
- ATL::CNoMultipleResults
dev_langs:
- C++
helpviewer_keywords:
- CNoMultipleResults class
ms.assetid: 343e77c4-b319-476e-b592-901ab9b2f34e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6d68daae7bce6ca4c9ffafe7a24c80cff3a5426a
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50059851"
---
# <a name="cnomultipleresults-class"></a>Classe CNoMultipleResults

Usado como um argumento de modelo (*TMultiple*) para [CCommand](../../data/oledb/ccommand-class.md) criar um comando otimizado que lida com um único resultado definido.

## <a name="syntax"></a>Sintaxe

```cpp
class CNoMultipleResults
```

## <a name="remarks"></a>Comentários

Se você quiser um comando para lidar com vários conjuntos de resultados, use [CMultipleResults](../../data/oledb/cmultipleresults-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)