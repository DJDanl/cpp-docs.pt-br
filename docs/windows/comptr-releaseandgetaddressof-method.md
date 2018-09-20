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
ms.openlocfilehash: 7f4aee13808fd55c42319aab90c13af7922ed9d2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46394823"
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

[Classe ComPtr](../windows/comptr-class.md)<br/>
[Membro de dados ComPtr::ptr_](../windows/comptr-ptr-data-member.md)