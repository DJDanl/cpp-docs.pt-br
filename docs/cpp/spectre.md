---
title: spectre
ms.date: 01/23/2018
f1_keywords:
- spectre_cpp
- spectre
- nomitigation
helpviewer_keywords:
- __declspec keyword (C++), spectre
- spectre __declspec keyword
ms.openlocfilehash: 40eee25dec867ae3fce7a6b2d4715f0be81bfe76
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70926363"
---
# <a name="spectre"></a>spectre

**Seção específica da Microsoft**

Instrui o compilador a não inserir instruções de barreira de execução especulativa de Spectre variante 1 para uma função.

## <a name="syntax"></a>Sintaxe

> **__declspec( spectre(nomitigation) )**

## <a name="remarks"></a>Comentários

A opção de compilador [/Qspectre](../build/reference/qspectre.md) faz com que o compilador insira instruções de barreira de execução especulativa. Eles são inseridos onde a análise indica que existe uma vulnerabilidade de segurança de Spectre variante 1. As instruções específicas emitidas dependem do processador. Embora essas instruções devam ter um impacto mínimo sobre o tamanho ou o desempenho do código, pode haver casos em que o código não é afetado pela vulnerabilidade e requer o desempenho máximo.

A análise de especialistas pode determinar que uma função é segura de um Spectre de limites de verificação de falha de desvio da variante 1. Nesse caso, você pode suprimir a geração de código de mitigação dentro de uma função `__declspec(spectre(nomitigation))` aplicando-se à declaração da função.

> [!CAUTION]
> As instruções de barreira de execução especulativa de **/Qspectre** fornecem proteção de segurança importante e apresentam um impacto insignificante sobre o desempenho. Portanto, recomendamos que você não suprime, exceto em casos raros em que o desempenho de uma função for um problema crítico e a função é comprovadamente segura.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar `__declspec(spectre(nomitigation))`o.

```cpp
// compile with: /c /Qspectre
static __declspec(spectre(nomitigation))
int noSpectreIssues() {
    // No Spectre variant 1 vulnerability here
    // ...
    return 0;
}

int main() {
    noSpectreIssues();
    return 0;
}
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[/Qspectre](../build/reference/qspectre.md)
