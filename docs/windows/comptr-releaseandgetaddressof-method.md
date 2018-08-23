---
title: 'Método comptr:: Releaseandgetaddressof | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::ReleaseAndGetAddressOf
dev_langs:
- C++
helpviewer_keywords:
- ReleaseAndGetAddressOf method
ms.assetid: 3751dcb4-d50e-432c-89e4-e736be34d434
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e3efdce7cde39431a8d6f097aace2ed2f5a66b4d
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42589941"
---
# <a name="comptrreleaseandgetaddressof-method"></a>Método ComPtr::ReleaseAndGetAddressOf

Libera a interface associada a este **ComPtr** e, em seguida, recupera o endereço da [PTR _](../windows/comptr-ptr-data-member.md) membro de dados, que contém um ponteiro para a interface que foi lançado.

## <a name="syntax"></a>Sintaxe

```cpp
T** ReleaseAndGetAddressOf();
```

## <a name="return-value"></a>Valor de retorno

O endereço do [PTR _](../windows/comptr-ptr-data-member.md) membro de dados desta **ComPtr**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe ComPtr](../windows/comptr-class.md)  
[Membro de dados ComPtr::ptr_](../windows/comptr-ptr-data-member.md)