---
title: safebuffers
ms.date: 11/04/2016
f1_keywords:
- safebuffers_cpp
helpviewer_keywords:
- __declspec keyword (C++), safebuffers
- safebuffers __declspec keyword
ms.assetid: 0b0dce14-4523-44d2-8070-5dd0fdabc618
ms.openlocfilehash: 473a838a48ed6523ce78d0bc8128dd83636c81d6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62267357"
---
# <a name="safebuffers"></a>safebuffers

**Seção específica da Microsoft**

Diz para o compilador não inserir verificações de segurança de excesso de buffer para uma função.

## <a name="syntax"></a>Sintaxe

```
__declspec( safebuffers )
```

## <a name="remarks"></a>Comentários

O **/GS** opção de compilador faz o compilador teste excesso de buffer inserindo verificações de segurança na pilha. Os tipos de estruturas de dados que são elegíveis para verificações de segurança são descritos em [/GS (Buffer Security Check)](../build/reference/gs-buffer-security-check.md). Para obter mais informações sobre a detecção de estouro de buffer, consulte [recursos de segurança no MSVC](https://blogs.msdn.microsoft.com/vcblog/2017/06/28/security-features-in-microsoft-visual-c/).

Uma análise de código manual por especialista ou uma análise externa pode determinar que a função está protegida contra o excesso de buffer. Nesse caso, você pode suprimir as verificações de segurança para uma função aplicando o **__declspec(safebuffers)** palavra-chave para a declaração da função.

> [!CAUTION]
>  As verificações de segurança do buffer fornecem a proteção de segurança importante e têm uma influência insignificante no desempenho. Portanto, recomendamos que você não suprime, exceto em casos raros em que o desempenho de uma função for um problema crítico e a função é comprovadamente segura.

## <a name="inline-functions"></a>Funções embutidas

Um *a função principal* pode usar um [inlining](inline-functions-cpp.md) palavra-chave para inserir uma cópia de um *função secundária*. Se o **__declspec(safebuffers)** palavra-chave é aplicado a uma função, a detecção de estouro de buffer será suprimida para essa função. No entanto, inlining afeta a **__declspec(safebuffers)** palavra-chave das seguintes maneiras.

Suponha que o **/GS** opção de compilador é especificada para ambas as funções, mas a função primária Especifica a **__declspec(safebuffers)** palavra-chave. As estruturas de dados na função secundária a tornam elegível para verificações de segurança, e a função não suprime essas verificações. Nesse caso:

- Especifique o [forceinline](inline-functions-cpp.md) palavra-chave na função secundária para forçar o compilador a embutir essa função independentemente das otimizações do compilador.

- Como a função secundária é elegível para verificações de segurança, verificações de segurança também são aplicadas à função primária, mesmo que ele especifica o **__declspec(safebuffers)** palavra-chave.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o **__declspec(safebuffers)** palavra-chave.

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

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[inline, __inline, \__forceinline](inline-functions-cpp.md)<br/>
[strict_gs_check](../preprocessor/strict-gs-check.md)