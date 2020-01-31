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
ms.openlocfilehash: 0ce6e9193107cbd0d033d99b257e41004b4343a8
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821851"
---
# <a name="implements-structure"></a>Implementa estrutura

Implementa `QueryInterface` e `GetIid` para as interfaces especificadas.

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
A ID da interface inicial. Obrigatório

*I1*<br/>
A primeira ID de interface. (Opcional)

*I2*<br/>
A segunda ID de interface. (Opcional)

*I3*<br/>
A terceira ID de interface. (Opcional)

*I4*<br/>
A quarta ID de interface. (Opcional)

*I5*<br/>
A quinta ID da interface. (Opcional)

*I6*<br/>
A sexta ID da interface. (Opcional)

*I7*<br/>
A sétima ID da interface. (Opcional)

*I8*<br/>
A oitava ID da interface. (Opcional)

*I9*<br/>
A nona ID da interface. (Opcional)

*flags*<br/>
Sinalizadores de configuração para a classe. Uma ou mais enumerações [RuntimeClassType](runtimeclasstype-enumeration.md) especificadas em uma estrutura [RuntimeClassFlags](runtimeclassflags-structure.md) .

## <a name="remarks"></a>Comentários

Deriva da lista de interfaces especificadas e implementa modelos auxiliares para `QueryInterface` e `GetIid`.

Cada parâmetro de interface *i0* por meio de *i9* deve derivar de `IUnknown`, `IInspectable`ou o modelo [ChainInterfaces](chaininterfaces-structure.md) . O parâmetro *flags* determina se o suporte é gerado para `IUnknown` ou `IInspectable`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

| Name        | Descrição                               |
| ----------- | ----------------------------------------- |
| `ClassFlags`| Um sinônimo de `RuntimeClassFlags<WinRt>`. |

### <a name="protected-methods"></a>Métodos protegidos

| Name                                              | Descrição                                                                                                   |
| ------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| [Implements::CanCastTo](#cancastto)               | Obtém um ponteiro para a interface especificada.                                                                    |
| [Implements::CastToUnknown](#casttounknown)       | Obtém um ponteiro para a interface de `IUnknown` subjacente.                                                        |
| [Implements::FillArrayWithIid](#fillarraywithiid) | Insere a ID de interface especificada pelo parâmetro de modelo inicial atual no elemento de matriz especificado. |

### <a name="protected-constants"></a>Constantes protegidas

| Name                              | Descrição                                    |
| --------------------------------- | ---------------------------------------------- |
| [Implementa:: IidCount](#iidcount) | Mantém o número de IDs de interface implementadas. |

## <a name="inheritance-hierarchy"></a>Hierarquia de Herança

`I0`

`ChainInterfaces`

`I0`

`ImplementsBase`

`ImplementsHelper`

`Implements`

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="cancastto"></a>Implements::CanCastTo

Obtém um ponteiro para a interface especificada.

```cpp
__forceinline HRESULT CanCastTo(
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma referência a uma ID de interface.

*ppv*<br/>
Se for bem-sucedido, um ponteiro para a interface especificada por *riid*.

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro, como E_NOINTERFACE.

### <a name="remarks"></a>Comentários

Essa é uma função auxiliar interna que executa uma operação de QueryInterface.

## <a name="casttounknown"></a>Implements::CastToUnknown

Obtém um ponteiro para a interface de `IUnknown` subjacente.

```cpp
__forceinline IUnknown* CastToUnknown();
```

### <a name="return-value"></a>Valor de retorno

Essa operação sempre obtém sucesso e retorna o ponteiro de `IUnknown`.

### <a name="remarks"></a>Comentários

Função auxiliar interna.

## <a name="fillarraywithiid"></a>Implements::FillArrayWithIid

Insere a ID de interface especificada pelo parâmetro de modelo inicial atual no elemento de matriz especificado.

```cpp
__forceinline static void FillArrayWithIid(
   unsigned long &index,
   _In_ IID* iids
);
```

### <a name="parameters"></a>Parâmetros

*index*<br/>
Um índice de base zero que indica o elemento de matriz inicial para esta operação. Quando essa operação for concluída, o *índice* será incrementado em 1.

*iids*<br/>
Uma matriz do tipo IID.

### <a name="remarks"></a>Comentários

Função auxiliar interna.

## <a name="iidcount"></a>Implementa:: IidCount

Mantém o número de IDs de interface implementadas.

```cpp
static const unsigned long IidCount;
```
