---
title: safebuffers
ms.date: 11/04/2016
f1_keywords:
- safebuffers_cpp
helpviewer_keywords:
- __declspec keyword (C++), safebuffers
- safebuffers __declspec keyword
ms.assetid: 0b0dce14-4523-44d2-8070-5dd0fdabc618
ms.openlocfilehash: 456e84cfba40a4219f44fe1549272621f79d09a2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213236"
---
# <a name="safebuffers"></a>safebuffers

**Específico da Microsoft**

Diz para o compilador não inserir verificações de segurança de excesso de buffer para uma função.

## <a name="syntax"></a>Sintaxe

```
__declspec( safebuffers )
```

## <a name="remarks"></a>Comentários

A opção de compilador **/GS** faz com que o compilador teste as saturações de buffer inserindo verificações de segurança na pilha. Os tipos de estruturas de dados elegíveis para verificações de segurança são descritos em [/GS (verificação de segurança do buffer)](../build/reference/gs-buffer-security-check.md). Para obter mais informações sobre a detecção de estouro de buffer, consulte [recursos de segurança no MSVC](https://devblogs.microsoft.com/cppblog/security-features-in-microsoft-visual-c/).

Uma análise de código manual por especialista ou uma análise externa pode determinar que a função está protegida contra o excesso de buffer. Nesse caso, você pode suprimir as verificações de segurança de uma função aplicando a **`__declspec(safebuffers)`** palavra-chave à declaração da função.

> [!CAUTION]
> As verificações de segurança do buffer fornecem a proteção de segurança importante e têm uma influência insignificante no desempenho. Portanto, recomendamos que você não suprime, exceto em casos raros em que o desempenho de uma função for um problema crítico e a função é comprovadamente segura.

## <a name="inline-functions"></a>Funções embutidas

Uma *função primária* pode usar uma palavra-chave [inline](inline-functions-cpp.md) para inserir uma cópia de uma *função secundária*. Se a **`__declspec(safebuffers)`** palavra-chave for aplicada a uma função, a detecção de estouro de buffer será suprimida para essa função. No entanto, a inlinhação afeta a **`__declspec(safebuffers)`** palavra-chave das seguintes maneiras.

Suponha que a opção de compilador **/GS** seja especificada para ambas as funções, mas a função Primary especifica a **`__declspec(safebuffers)`** palavra-chave. As estruturas de dados na função secundária a tornam elegível para verificações de segurança, e a função não suprime essas verificações. Nesse caso:

- Especifique a palavra-chave [__forceinline](inline-functions-cpp.md) na função secundária para forçar o compilador a embutir essa função, independentemente das otimizações do compilador.

- Como a função secundária está qualificada para verificações de segurança, as verificações de segurança também são aplicadas à função primária, embora ela especifique a **`__declspec(safebuffers)`** palavra-chave.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar a **`__declspec(safebuffers)`** palavra-chave.

```cpp
// compile with: /c /GS
typedef struct {
    int x[20];
} BUFFER;
static int checkBuffers() {
    BUFFER cb;
    // Use the buffer...
    return 0;
};
static __declspec(safebuffers)
    int noCheckBuffers() {
    BUFFER ncb;
    // Use the buffer...
    return 0;
}
int wmain() {
    checkBuffers();
    noCheckBuffers();
    return 0;
}
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[inline, __inline, \_ _forceinline](inline-functions-cpp.md)<br/>
[strict_gs_check](../preprocessor/strict-gs-check.md)
