---
title: 'Método ftmbase:: Releasemarshaldata | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase::ReleaseMarshalData
dev_langs:
- C++
helpviewer_keywords:
- ReleaseMarshalData method
ms.assetid: a94f9940-183a-4fde-8504-d223f346a0a9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c2d4bccbcd9f3c3b13fa8be0ccc7afa493751cd9
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42593533"
---
# <a name="ftmbasereleasemarshaldata-method"></a>Método FtmBase::ReleaseMarshalData

Destrói um pacote de dados com marshaling.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHODIMP ReleaseMarshalData(
   __in IStream *pStm
) override;
```

### <a name="parameters"></a>Parâmetros

*pStm*  
Ponteiro para um fluxo que contém o pacote de dados a ser destruído.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ftm.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe FtmBase](../windows/ftmbase-class.md)