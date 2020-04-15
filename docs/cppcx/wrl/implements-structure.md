---
title: Implementa estrutura
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Implements
- implements/Microsoft::WRL::Implements::CanCastTo
- implements/Microsoft::WRL::Implements::CastToUnknown
- implements/Microsoft::WRL::Implements::FillArrayWithIid
- implements/Microsoft::WRL::Implements::IidCount
helpviewer_keywords:
- Microsoft::WRL::Implements structure
- Microsoft::WRL::Implements::CanCastTo method
- Microsoft::WRL::Implements::CastToUnknown method
- Microsoft::WRL::Implements::FillArrayWithIid method
- Microsoft::WRL::Implements::IidCount method
ms.assetid: 29b13e90-34d4-4a0b-babd-5187c9eb0c36
ms.openlocfilehash: 223f37d7cabbd0b8cd238582773c05d7b9eaabf6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371405"
---
# <a name="implements-structure"></a>Implementa estrutura

Implementa `QueryInterface` `GetIid` e para as interfaces especificadas.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename I0,
    typename I1 = Details::Nil,
    typename I2 = Details::Nil,
    typename I3 = Details::Nil,
    typename I4 = Details::Nil,
    typename I5 = Details::Nil,
    typename I6 = Details::Nil,
    typename I7 = Details::Nil,
    typename I8 = Details::Nil,
    typename I9 = Details::Nil
>
struct __declspec(novtable) Implements :
    Details::ImplementsHelper<
        RuntimeClassFlags<WinRt>,
        typename Details::InterfaceListHelper<
            I0, I1, I2, I3, I4, I5, I6, I7, I8, I9
        >::TypeT
    >,
    Details::ImplementsBase;

template <
    int flags,
    typename I0,
    typename I1,
    typename I2,
    typename I3,
    typename I4,
    typename I5,
    typename I6,
    typename I7,
    typename I8
>
struct __declspec(novtable) Implements<
        RuntimeClassFlags<flags>,
        I0, I1, I2, I3, I4, I5, I6, I7, I8> :
    Details::ImplementsHelper<
        RuntimeClassFlags<flags>,
        typename Details::InterfaceListHelper<
            I0, I1, I2, I3, I4, I5, I6, I7, I8
        >::TypeT
    >,
    Details::ImplementsBase;
```

### <a name="parameters"></a>Parâmetros

*I0*<br/>
O zeroth interface ID. (Obrigatório)

*I1*<br/>
O primeiro ID de interface. (Opcional)

*I2*<br/>
O segundo ID de interface. (Opcional)

*I3*<br/>
O terceiro ID de interface. (Opcional)

*I4*<br/>
O quarto ID de interface. (Opcional)

*I5*<br/>
A quinta interface ID. (Opcional)

*I6*<br/>
A sexta interface id. (Opcional)

*I7*<br/>
A sétima interface ID. (Opcional)

*I8*<br/>
O oitavo id de interface. (Opcional)

*I9*<br/>
A nona interface. (Opcional)

*Sinalizadores*<br/>
Sinalizadores de configuração para a classe. Uma ou mais enumerações [RuntimeClassType](runtimeclasstype-enumeration.md) especificadas em uma estrutura [RuntimeClassFlags.](runtimeclassflags-structure.md)

## <a name="remarks"></a>Comentários

Deriva da lista de interfaces especificadas e implementa `QueryInterface` `GetIid`modelos auxiliares para e .

Cada parâmetro de interface *I0* a `IUnknown` *I9* deve derivar de qualquer um , `IInspectable`ou do modelo [ChainInterfaces.](chaininterfaces-structure.md) O parâmetro *bandeiras* determina se `IUnknown` o `IInspectable`suporte é gerado para ou .

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

| Nome        | Descrição                               |
| ----------- | ----------------------------------------- |
| `ClassFlags`| Um sinônimo de `RuntimeClassFlags<WinRt>`. |

### <a name="protected-methods"></a>Métodos Protegidos

| Nome                                              | Descrição                                                                                                   |
| ------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| [Implementos::CanCastTo](#cancastto)               | Obtém um ponteiro para a interface especificada.                                                                    |
| [Implementos::CastToUnknown](#casttounknown)       | Obtém um ponteiro `IUnknown` para a interface subjacente.                                                        |
| [Implementos::FillArrayWithIid](#fillarraywithiid) | Insere o ID de interface especificado pelo parâmetro atual do modelo zeroth no elemento de matriz especificado. |

### <a name="protected-constants"></a>Constantes protegidas

| Nome                              | Descrição                                    |
| --------------------------------- | ---------------------------------------------- |
| [Implementos::IidCount](#iidcount) | Detém o número de IDs de interface implementados. |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`I0`

`ChainInterfaces`

`I0`

`ImplementsBase`

`ImplementsHelper`

`Implements`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL

## <a name="implementscancastto"></a><a name="cancastto"></a>Implementos::CanCastTo

Obtém um ponteiro para a interface especificada.

```cpp
__forceinline HRESULT CanCastTo(
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma referência a um ID de interface.

*Ppv*<br/>
Se for bem sucedido, um ponteiro para a interface especificado por *riid*.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro, como E_NOINTERFACE.

### <a name="remarks"></a>Comentários

Esta é uma função auxiliar interna que executa uma operação QueryInterface.

## <a name="implementscasttounknown"></a><a name="casttounknown"></a>Implementos::CastToUnknown

Obtém um ponteiro `IUnknown` para a interface subjacente.

```cpp
__forceinline IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor retornado

Esta operação sempre tem `IUnknown` sucesso e retorna o ponteiro.

### <a name="remarks"></a>Comentários

Função auxiliar interna.

## <a name="implementsfillarraywithiid"></a><a name="fillarraywithiid"></a>Implementos::FillArrayWithIid

Insere o ID de interface especificado pelo parâmetro atual do modelo zeroth no elemento de matriz especificado.

```cpp
__forceinline static void FillArrayWithIid(
   unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Um índice baseado em zero que indica o elemento de matriz inicial para esta operação. Quando esta operação é concluída, *o índice* é incrementado em 1.

*Iids*<br/>
Uma matriz de IID tipo.

### <a name="remarks"></a>Comentários

Função auxiliar interna.

## <a name="implementsiidcount"></a><a name="iidcount"></a>Implementos::IidCount

Detém o número de IDs de interface implementados.

```cpp
static const unsigned long IidCount;
```
