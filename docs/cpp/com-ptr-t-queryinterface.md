---
title: _com_ptr_t::QueryInterface
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::QueryInterface
- _com_ptr_t.QueryInterface
helpviewer_keywords:
- QueryInterface method [C++]
ms.assetid: d03292f1-6b02-40db-9756-8b0837a97319
ms.openlocfilehash: 26dda2dff83ff0adbb7ef05c5e75f64b44138bd8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170665"
---
# <a name="_com_ptr_tqueryinterface"></a>_com_ptr_t::QueryInterface

**Seção específica da Microsoft**

Chama a função de membro **QueryInterface** de `IUnknown` no ponteiro de interface encapsulada.

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

#### <a name="parameters"></a>parâmetros

*IID*<br/>
`IID` de um ponteiro de interface.

*p*<br/>
Ponteiro da interface bruto.

## <a name="remarks"></a>Comentários

Chama `IUnknown::QueryInterface` no ponteiro de interface encapsulado com o `IID` especificado e retorna o ponteiro de interface bruto resultante em *p*. Essa rotina retorna o HRESULT para indicar êxito ou falha.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
