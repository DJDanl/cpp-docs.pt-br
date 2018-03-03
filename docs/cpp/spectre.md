---
title: spectre | Microsoft Docs
ms.custom: 
ms.date: 1/23/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
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
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b515d25d4818cf8b6213a37f3fe78df4f3882a69
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="spectre"></a>spectre

**Seção específica da Microsoft**

Informa ao compilador para não inserir instruções de barreira de execução especulativa Spectre variante 1 para uma função.

## <a name="syntax"></a>Sintaxe

> **__declspec( spectre(nomitigation) )**  

## <a name="remarks"></a>Comentários

O [/Qspectre](../build/reference/qspectre.md) opção de compilador faz com que o compilador para inserir instruções de barreira de execução especulativa onde análise indica que existe uma vulnerabilidade de segurança Spectre variante 1. As instruções específicas emitidas dependem do processador. Enquanto essas instruções devem ter um impacto mínimo sobre o tamanho do código ou desempenho, pode haver casos em que seu código não é afetado pela vulnerabilidade e requer que o desempenho máximo.

Análise de um especialista pode determinar que uma função é segura de um defeito de bypass Spectre variante 1 limites seleção. Nesse caso, você pode suprimir a geração de código de atenuação dentro de uma função aplicando `__declspec(spectre(nomitigation))` para a declaração da função.

> [!CAUTION]
> O **/Qspectre** instruções de barreira de execução especulativa fornecer proteção de segurança importantes e ter um efeito mínimo sobre o desempenho. Portanto, recomendamos que você não suprime, exceto em casos raros em que o desempenho de uma função for um problema crítico e a função é comprovadamente segura.

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

[__declspec](../cpp/declspec.md)  
[Palavras-chave](../cpp/keywords-cpp.md)  
[/Qspectre](../build/reference/qspectre.md)  
