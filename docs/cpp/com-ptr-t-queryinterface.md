---
title: _com_ptr_t::QueryInterface
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::QueryInterface
- _com_ptr_t.QueryInterface
helpviewer_keywords:
- QueryInterface method [C++]
ms.assetid: d03292f1-6b02-40db-9756-8b0837a97319
ms.openlocfilehash: 42953c92e4cf31b5ccd02dd51811fc1fdeedbcaf
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50543826"
---
# <a name="comptrtqueryinterface"></a>_com_ptr_t::QueryInterface

**Seção específica da Microsoft**

Chamadas a **QueryInterface** função de membro de `IUnknown` no ponteiro de interface encapsulado.

## <a name="syntax"></a>Sintaxe

```
template<typename _InterfaceType> HRESULT QueryInterface (
   const IID& iid,
   _InterfaceType*& p
) throw ( );
template<typename _InterfaceType> HRESULT QueryInterface (
   const IID& iid,
   _InterfaceType** p
) throw( );
```

#### <a name="parameters"></a>Parâmetros

*IID*<br/>
`IID` de um ponteiro de interface.

*p*<br/>
Ponteiro da interface bruto.

## <a name="remarks"></a>Comentários

Chamadas `IUnknown::QueryInterface` no ponteiro de interface encapsulado com especificado `IID` e retorna o ponteiro de interface bruto resultante na *p*. Essa rotina retorna o HRESULT para indicar êxito ou falha.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)