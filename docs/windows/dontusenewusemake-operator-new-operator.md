---
title: 'Operador new de dontusenewusemake:: Operator | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::DontUseNewUseMake::operator new
dev_langs:
- C++
helpviewer_keywords:
- operator new operator
ms.assetid: 6af07a0d-2271-430c-9d9b-5a4223fed049
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 99e82de06f64816521c47c78648108a9ae815279
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46443222"
---
# <a name="dontusenewusemakeoperator-new-operator"></a>DontUseNewUseMake::operator Operador new

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
void* operator new(
   size_t,
   _In_ void* placement
);
```

### <a name="parameters"></a>Parâmetros

*__unnamed0*<br/>
Um parâmetro não nomeado que especifica o número de bytes de memória para alocar.

*placement*<br/>
O tipo a ser alocado.

## <a name="return-value"></a>Valor de retorno

Fornece uma maneira de passar argumentos adicionais se você sobrecarregar o operador **novo**.

## <a name="remarks"></a>Comentários

Sobrecarrega o operador **novos** e impede que ele seja usado no `RuntimeClass`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe DontUseNewUseMake](../windows/dontusenewusemake-class.md)<br/>
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)