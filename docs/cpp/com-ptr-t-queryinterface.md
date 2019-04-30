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
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399259"
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

*iid*<br/>
`IID` de um ponteiro de interface.

*p*<br/>
Ponteiro da interface bruto.

## <a name="remarks"></a>Comentários

Chamadas `IUnknown::QueryInterface` no ponteiro de interface encapsulado com especificado `IID` e retorna o ponteiro de interface bruto resultante na *p*. Essa rotina retorna o HRESULT para indicar êxito ou falha.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)