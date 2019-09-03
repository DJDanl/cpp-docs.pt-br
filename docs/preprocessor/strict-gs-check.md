---
title: Pragma strict_gs_check
ms.date: 08/29/2019
f1_keywords:
- strict_gs_check
- strict_gs_check_CPP
helpviewer_keywords:
- strict_gs_check pragma
ms.assetid: decfec81-c916-42e0-a07f-8cc26df6a7ce
ms.openlocfilehash: 0b66e87f2280c923d05103fccfcbbc8d32daf3fd
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216588"
---
# <a name="strict_gs_check-pragma"></a>Pragma strict_gs_check

Este pragma fornece verificação de segurança aprimorada.

## <a name="syntax"></a>Sintaxe

> **#pragma strict_gs_check (** [ **Push,** ] { **on** | **off** } **)** \
> **#pragma strict_gs_check (pop)**

## <a name="remarks"></a>Comentários

Ele instrui o compilador a inserir um cookie aleatório na pilha de função para ajudar a detectar algumas categorias de saturação de buffer baseada em fila. Por padrão, a `/GS` opção de compilador (verificação de segurança do buffer) não insere um cookie para todas as funções. Para obter mais informações, consulte [/GS (verificação de segurança do buffer)](../build/reference/gs-buffer-security-check.md).

Compile usando `/GS` para habilitar o **strict_gs_check**.

Use este pragma em módulos de código que são expostos a dados potencialmente nocivos. **strict_gs_check** é um pragma agressivo e é aplicado a funções que podem não precisar dessa defesa, mas é otimizado para minimizar seu efeito sobre o desempenho do aplicativo resultante.

Mesmo ao usar esse pragma, o ideal é escrever um código seguro. Ou seja, certifique-se de que seu código não tenha saturações de buffer. **strict_gs_check** pode proteger seu aplicativo contra estouros de buffer que permanecem em seu código.

## <a name="example"></a>Exemplo

Neste exemplo, uma saturação de buffer ocorre quando copiamos uma matriz para uma matriz local. Quando você compila esse código com `/GS`, nenhum cookie é inserido na pilha, porque o tipo de dados de matriz é um ponteiro. Adicionar o pragma **strict_gs_check** força o cookie de pilha na pilha de funções.

```cpp
// pragma_strict_gs_check.cpp
// compile with: /c

#pragma strict_gs_check(on)

void ** ReverseArray(void **pData,
                     size_t cData)
{
    // *** This buffer is subject to being overrun!! ***
    void *pReversed[20];

    // Reverse the array into a temporary buffer
    for (size_t j = 0, i = cData; i ; --i, ++j)
        // *** Possible buffer overrun!! ***
            pReversed[j] = pData[i];

    // Copy temporary buffer back into input/output buffer
    for (size_t i = 0; i < cData ; ++i)
        pData[i] = pReversed[i];

    return pData;
}
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)\
[/GS (verificação de segurança do buffer)](../build/reference/gs-buffer-security-check.md)
