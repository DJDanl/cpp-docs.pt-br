---
title: safebuffers
ms.date: 11/04/2016
f1_keywords:
- safebuffers_cpp
helpviewer_keywords:
- __declspec keyword (C++), safebuffers
- safebuffers __declspec keyword
ms.assetid: 0b0dce14-4523-44d2-8070-5dd0fdabc618
ms.openlocfilehash: bc4736ce233ce026ecab9ef38ac8379466b5a0bc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365578"
---
# <a name="safebuffers"></a>safebuffers

**Específico da Microsoft**

Diz para o compilador não inserir verificações de segurança de excesso de buffer para uma função.

## <a name="syntax"></a>Sintaxe

```
__declspec( safebuffers )
```

## <a name="remarks"></a>Comentários

A opção **compilador /GS** faz com que o compilador teste para buffer overruns inserindo verificações de segurança na pilha. Os tipos de estruturas de dados elegíveis para verificações de segurança são descritos em [/GS (Buffer Security Check)](../build/reference/gs-buffer-security-check.md). Para obter mais informações sobre a detecção de buffer overrun, consulte [Recursos de segurança no MSVC](https://blogs.msdn.microsoft.com/vcblog/2017/06/28/security-features-in-microsoft-visual-c/).

Uma análise de código manual por especialista ou uma análise externa pode determinar que a função está protegida contra o excesso de buffer. Nesse caso, você pode suprimir verificações de segurança para uma função aplicando a **palavra-chave __declspec (buffers de segurança)** à declaração de função.

> [!CAUTION]
> As verificações de segurança do buffer fornecem a proteção de segurança importante e têm uma influência insignificante no desempenho. Portanto, recomendamos que você não suprime, exceto em casos raros em que o desempenho de uma função for um problema crítico e a função é comprovadamente segura.

## <a name="inline-functions"></a>Funções embutidas

Uma *função primária* pode usar uma palavra-chave de [inforro](inline-functions-cpp.md) para inserir uma cópia de uma *função secundária*. Se a palavra-chave **__declspec (buffers de segurança)** for aplicada a uma função, a detecção de buffer overrun será suprimida para essa função. No entanto, a inlineação afeta a **palavra-chave __declspec (safebuffers)** nas seguintes maneiras.

Suponha que a opção **compilador /GS** seja especificada para ambas as funções, mas a função principal especifica a palavra-chave **__declspec (buffers** de segurança). As estruturas de dados na função secundária a tornam elegível para verificações de segurança, e a função não suprime essas verificações. Nesse caso:

- Especifique a [palavra-chave __forceinline](inline-functions-cpp.md) na função secundária para forçar o compilador a inline essa função, independentemente das otimizações do compilador.

- Como a função secundária é elegível para verificações de segurança, as verificações de segurança também são aplicadas à função principal, embora especifique a palavra-chave **__declspec (buffers de segurança).**

## <a name="example"></a>Exemplo

O código a seguir mostra como usar a **palavra-chave __declspec (buffers de segurança).**

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

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[inline, __inline, \__forceinline](inline-functions-cpp.md)<br/>
[strict_gs_check](../preprocessor/strict-gs-check.md)
