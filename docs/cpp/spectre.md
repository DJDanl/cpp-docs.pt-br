---
title: spectre | Microsoft Docs
ms.custom: ''
ms.date: 1/23/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- spectre_cpp
- spectre
- nomitigation
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword (C++), spectre
- spectre __declspec keyword
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3d919a810ed93e40218476369ef9981da59b89bb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46114612"
---
# <a name="spectre"></a>spectre

**Seção específica da Microsoft**

Informa o compilador não inserir instruções de barreira de execução especulativa Spectre variante 1 para uma função.

## <a name="syntax"></a>Sintaxe

> **__declspec( spectre(nomitigation) )**

## <a name="remarks"></a>Comentários

O [/Qspectre](../build/reference/qspectre.md) opção de compilador faz com que o compilador a inserir instruções de barreira de execução especulativa onde análise indica que há uma vulnerabilidade de segurança de variante 1 do Spectre. As instruções específicas emitidas dependem do processador. E essas instruções devem ter um impacto mínimo sobre o tamanho do código ou desempenho, pode haver casos em que seu código não é afetado pela vulnerabilidade e exige que o desempenho máximo.

Análise de um especialista pode determinar que uma função está protegida contra um defeito de bypass de seleção do Spectre variante 1 dos limites. Nesse caso, você pode suprimir a geração de código de mitigação dentro de uma função aplicando `__declspec(spectre(nomitigation))` à declaração da função.

> [!CAUTION]
> O **/Qspectre** instruções de barreira de execução especulativa fornecer proteção de segurança importante e ter uma influência insignificante no desempenho. Portanto, recomendamos que você não suprime, exceto em casos raros em que o desempenho de uma função for um problema crítico e a função é comprovadamente segura.

## <a name="example"></a>Exemplo

O código a seguir mostra como usar `__declspec(spectre(nomitigation))`.

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
