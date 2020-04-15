---
title: Estrutura RuntimeClassBaseT
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::RuntimeClassBaseT
- implements/Microsoft::WRL::Details::RuntimeClassBaseT::AsIID
- implements/Microsoft::WRL::Details::RuntimeClassBaseT::GetImplementedIIDS
helpviewer_keywords:
- Microsoft::WRL::Details::RuntimeClassBaseT structure
- Microsoft::WRL::Details::RuntimeClassBaseT::AsIID method
- Microsoft::WRL::Details::RuntimeClassBaseT::GetImplementedIIDS method
ms.assetid: a62775fb-3359-4f45-9ff1-c07fa8da464b
ms.openlocfilehash: 06a9f73e00d541b0e5bcbe20c57befe4a67c5132
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375727"
---
# <a name="runtimeclassbaset-structure"></a>Estrutura RuntimeClassBaseT

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template <unsigned int RuntimeClassTypeT>
friend struct Details::RuntimeClassBaseT;
```

### <a name="parameters"></a>Parâmetros

*RuntimeClassTypeT*<br/>
Um campo de bandeiras que especifica um ou mais enumeradores [RuntimeClassType.](runtimeclasstype-enumeration.md)

## <a name="remarks"></a>Comentários

Fornece métodos auxiliares para `QueryInterface` operações e obtenção de IDs de interface.

## <a name="members"></a>Membros

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                         | Descrição
------------------------------------------------------------ | -----------------------------------------------------------------------------
[Tempo de execuçãoClassBaseT::AsIID](#asiid)                           | Recupera um ponteiro para o ID de interface especificado.
[Tempo de execuçãoClassBaseT::GetImplementedIIDS](#getimplementediids) | Recupera um conjunto de IDs de interface que são implementados por um tipo especificado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`RuntimeClassBaseT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="runtimeclassbasetasiid"></a><a name="asiid"></a>Tempo de execuçãoClassBaseT::AsIID

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
__forceinline static HRESULT AsIID(
   _In_ T* implements,
   REFIID riid,
   _Deref_out_ void **ppvObject
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Um tipo que implementa o ID de interface especificado por *parâmetro riid*.

*Implementa*<br/>
Uma variável do tipo especificado pelo parâmetro de modelo *T*.

*riid*<br/>
O ID de interface para recuperar.

*Ppvobject*<br/>
Se esta operação for bem sucedida, um ponteiro-para-um-ponteiro para a interface especificado por *riid*parâmetro .

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve o erro.

### <a name="remarks"></a>Comentários

Recupera um ponteiro para o ID de interface especificado.

## <a name="runtimeclassbasetgetimplementediids"></a><a name="getimplementediids"></a>Tempo de execuçãoClassBaseT::GetImplementedIIDS

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
template<typename T>
__forceinline static HRESULT GetImplementedIIDS(
   _In_ T* implements,
   _Out_ ULONG *iidCount,
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids
);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de *parâmetro dos implementos.*

*Implementa*<br/>
Ponteiro para o tipo especificado pelo parâmetro *T*.

*IidCount*<br/>
O número máximo de IDs de interface para recuperar.

*Iids*<br/>
Se esta operação for concluída com sucesso, uma matriz de IDs de interface implementado *satisfaz*o tipo T .

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve o erro.

### <a name="remarks"></a>Comentários

Recupera um conjunto de IDs de interface que são implementados por um tipo especificado.
