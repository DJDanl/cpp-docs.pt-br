---
title: Função MakeAndInitialize
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAndInitialize
ms.assetid: 71ceeb12-d2a2-4317-b010-3dcde1b39467
ms.openlocfilehash: 28d9e586a766a131e7ab6280859845810c1d9814
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213792"
---
# <a name="makeandinitialize-function"></a>Função MakeAndInitialize

Inicializa a classe de Windows Runtime especificada. Use essa função para criar uma instância de um componente que é definido no mesmo módulo.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename T,
    typename I,
    typename TArg1,
    typename TArg2,
    typename TArg3,
    typename TArg4,
    typename TArg5,
    typename TArg6,
    typename TArg7,
    typename TArg8,
    typename TArg9>
HRESULT MakeAndInitialize(
    _Outptr_result_nullonfailure_ I** ppvObject,
    TArg1 &&arg1,
    TArg2 &&arg2,
    TArg3 &&arg3,
    TArg4 &&arg4,
    TArg5 &&arg5,
    TArg6 &&arg6,
    TArg7 &&arg7,
    TArg8 &&arg8,
    TArg9 &&arg9) throw()
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe especificada pelo usuário que herda de `WRL::RuntimeClass`.

*TArg1*<br/>
Tipo de argumento 1 que é passado para a classe de tempo de execução especificada.

*TArg2*<br/>
Tipo de argumento 2 que é passado para a classe de tempo de execução especificada.

*TArg3*<br/>
Tipo de argumento 3 que é passado para a classe de tempo de execução especificada.

*TArg4*<br/>
Tipo de argumento 4 que é passado para a classe de tempo de execução especificada.

*TArg5*<br/>
Tipo de argumento 5 que é passado para a classe de tempo de execução especificada.

*TArg6*<br/>
Tipo de argumento 6 que é passado para a classe de tempo de execução especificada.

*TArg7*<br/>
Tipo de argumento 7 que é passado para a classe de tempo de execução especificada.

*TArg8*<br/>
Tipo de argumento 8 que é passado para a classe de tempo de execução especificada.

*TArg9*<br/>
Tipo de argumento 9 que é passado para a classe de tempo de execução especificada.

*arg1*<br/>
Argumento 1 que é passado para a classe de tempo de execução especificada.

*arg2*<br/>
Argumento 2 que é passado para a classe de tempo de execução especificada.

*Arg3*<br/>
Argumento 3 que é passado para a classe de tempo de execução especificada.

*arg4*<br/>
Argumento 4 que é passado para a classe de tempo de execução especificada.

*arg5*<br/>
Argumento 5 que é passado para a classe de tempo de execução especificada.

*arg6*<br/>
Argumento 6 que é passado para a classe de tempo de execução especificada.

*arg7*<br/>
Argumento 7 que é passado para a classe de tempo de execução especificada.

*arg8*<br/>
Argumento 8 que é passado para a classe de tempo de execução especificada.

*arg9*<br/>
Argumento 9 que é passado para a classe de tempo de execução especificada.

## <a name="return-value"></a>Valor retornado

Um valor HRESULT.

## <a name="remarks"></a>Comentários

Consulte [como: criar uma instância de componentes do WRL diretamente](how-to-instantiate-wrl-components-directly.md) para aprender as diferenças entre essa função e [Microsoft:: WRL:: Make](make-function.md)e, por exemplo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL::Details](microsoft-wrl-details-namespace.md)
