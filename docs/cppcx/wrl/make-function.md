---
title: Função Make
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Make
helpviewer_keywords:
- Make function
ms.assetid: 66704143-df99-4a95-904d-ed99607e1034
ms.openlocfilehash: 0f2e81e3cd757214805817af2a355a93c1cfd096
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220464"
---
# <a name="make-function"></a>Função Make

Inicializa a classe de Windows Runtime especificada. Use essa função para criar uma instância de um componente que é definido no mesmo módulo.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   typename T,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5,
   typename TArg6,
   typename TArg7,
   typename TArg8,
   typename TArg9
>
ComPtr<T> Make(
   TArg1 &&arg1,
   TArg2 &&arg2,
   TArg3 &&arg3,
   TArg4 &&arg4,
   TArg5 &&arg5,
   TArg6 &&arg6,
   TArg7 &&arg7,
   TArg8 &&arg8,
   TArg9 &&arg9
);
template <
   typename T,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5,
   typename TArg6,
   typename TArg7,
   typename TArg8
>
ComPtr<T> Make(
   TArg1 &&arg1,
   TArg2 &&arg2,
   TArg3 &&arg3,
   TArg4 &&arg4,
   TArg5 &&arg5,
   TArg6 &&arg6,
   TArg7 &&arg7,
   TArg8 &&arg8
);
template <
   typename T,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5,
   typename TArg6,
   typename TArg7
>
ComPtr<T> Make(
   TArg1 &&arg1,
   TArg2 &&arg2,
   TArg3 &&arg3,
   TArg4 &&arg4,
   TArg5 &&arg5,
   TArg6 &&arg6,
   TArg7 &&arg7
);
template <
   typename T,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5,
   typename TArg6
>
ComPtr<T> Make(
   TArg1 &&arg1,
   TArg2 &&arg2,
   TArg3 &&arg3,
   TArg4 &&arg4,
   TArg5 &&arg5,
   TArg6 &&arg6
);
template <
   typename T,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5
>
ComPtr<T> Make(
   TArg1 &&arg1,
   TArg2 &&arg2,
   TArg3 &&arg3,
   TArg4 &&arg4,
   TArg5 &&arg5
);
template <
   typename T,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4
>
ComPtr<T> Make(
   TArg1 &&arg1,
   TArg2 &&arg2,
   TArg3 &&arg3,
   TArg4 &&arg4
);
template <
   typename T,
   typename TArg1,
   typename TArg2,
   typename TArg3
>
ComPtr<T> Make(
   TArg1 &&arg1,
   TArg2 &&arg2,
   TArg3 &&arg3
);
template <
   typename T,
   typename TArg1,
   typename TArg2
>
ComPtr<T> Make(
   TArg1 &&arg1,
   TArg2 &&arg2
);
template <
   typename T,
   typename TArg1
>
ComPtr<T> Make(
   TArg1 &&arg1
);
template <
   typename T
>
ComPtr<T> Make();
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe especificada pelo usuário que herda de `WRL::RuntimeClass` .

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

Um `ComPtr<T>` objeto se for bem-sucedido; caso contrário, **`nullptr`** .

## <a name="remarks"></a>Comentários

Consulte [como: criar uma instância de componentes do WRL diretamente](how-to-instantiate-wrl-components-directly.md) para saber as diferenças entre essa função e [Microsoft:: WRL::D etalhes:: MakeAndInitialize](makeandinitialize-function.md)e para obter um exemplo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL

## <a name="see-also"></a>Confira também

[Namespace Microsoft:: WRL](microsoft-wrl-namespace.md)
