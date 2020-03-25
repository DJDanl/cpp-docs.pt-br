---
title: safebuffers
ms.date: 11/04/2016
f1_keywords:
- safebuffers_cpp
helpviewer_keywords:
- __declspec keyword (C++), safebuffers
- safebuffers __declspec keyword
ms.assetid: 0b0dce14-4523-44d2-8070-5dd0fdabc618
ms.openlocfilehash: 705d3eca67f87e505a147af4984496d3af43dd53
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178906"
---
# <a name="safebuffers"></a>safebuffers

**Seção específica da Microsoft**

Diz para o compilador não inserir verificações de segurança de excesso de buffer para uma função.

## <a name="syntax"></a>Sintaxe

```
__declspec( safebuffers )
```

## <a name="remarks"></a>Comentários

A opção de compilador **/GS** faz com que o compilador teste as saturações de buffer inserindo verificações de segurança na pilha. Os tipos de estruturas de dados elegíveis para verificações de segurança são descritos em [/GS (verificação de segurança do buffer)](../build/reference/gs-buffer-security-check.md). Para obter mais informações sobre a detecção de estouro de buffer, consulte [recursos de segurança no MSVC](https://blogs.msdn.microsoft.com/vcblog/2017/06/28/security-features-in-microsoft-visual-c/).

Uma análise de código manual por especialista ou uma análise externa pode determinar que a função está protegida contra o excesso de buffer. Nesse caso, você pode suprimir as verificações de segurança de uma função aplicando a palavra-chave **__declspec (safebuffers)** à declaração da função.

> [!CAUTION]
>  As verificações de segurança do buffer fornecem a proteção de segurança importante e têm uma influência insignificante no desempenho. Portanto, recomendamos que você não suprime, exceto em casos raros em que o desempenho de uma função for um problema crítico e a função é comprovadamente segura.

## <a name="inline-functions"></a>Funções embutidas

Uma *função primária* pode usar uma palavra-chave [inline](inline-functions-cpp.md) para inserir uma cópia de uma *função secundária*. Se a palavra-chave **__declspec (safebuffers)** for aplicada a uma função, a detecção de estouro de buffer será suprimida para essa função. No entanto, a inalinhamento afeta a palavra-chave **__declspec (safebuffers)** das seguintes maneiras.

Suponha que a opção de compilador **/GS** seja especificada para ambas as funções, mas a função Primary especifica a palavra-chave **__declspec (safebuffers)** . As estruturas de dados na função secundária a tornam elegível para verificações de segurança, e a função não suprime essas verificações. Nesse caso:

- Especifique a palavra-chave [__forceinline](inline-functions-cpp.md) na função secundária para forçar o compilador a embutir essa função, independentemente das otimizações do compilador.

- Como a função secundária está qualificada para verificações de segurança, as verificações de segurança também são aplicadas à função primária, embora ela especifique a palavra-chave **__declspec (safebuffers)** .

## <a name="example"></a>Exemplo

O código a seguir mostra como usar a palavra-chave **__declspec (safebuffers)** .

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[inline, __inline, \__forceinline](inline-functions-cpp.md)<br/>
[strict_gs_check](../preprocessor/strict-gs-check.md)
