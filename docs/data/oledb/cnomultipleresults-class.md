---
title: Classe CNoMultipleResults
ms.date: 11/04/2016
f1_keywords:
- CNoMultipleResults
- ATL.CNoMultipleResults
- ATL::CNoMultipleResults
helpviewer_keywords:
- CNoMultipleResults class
ms.assetid: 343e77c4-b319-476e-b592-901ab9b2f34e
ms.openlocfilehash: 59b7b35c350a37f13e1f253bc1430d69521e4fa8
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59026704"
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

[Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)