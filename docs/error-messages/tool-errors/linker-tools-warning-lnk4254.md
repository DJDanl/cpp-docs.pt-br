---
title: Ferramentas de vinculador LNK4254 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4254
dev_langs:
- C++
helpviewer_keywords:
- LNK4254
ms.assetid: 6f41dfb3-ca21-40d3-bac7-b637e578efa4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f2ef421cbfa87ecab8a27dfa796eaa4eaacf7b70
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46064640"
---
# <a name="linker-tools-warning-lnk4254"></a>Aviso LNK4254 (Ferramentas de Vinculador)

seção 'section1' (deslocamento) mesclados em 'section2' (deslocamento) com diferentes atributos

O conteúdo de uma seção foram mesclado em outro, mas os atributos das duas seções são diferentes. Seu programa pode gerar resultados inesperados. Por exemplo, dados que você queria ser lido apenas podem agora ser em uma seção gravável.

Para resolver LNK4254, modificar ou remover a solicitação de mesclagem.

Ao direcionar x86 máquinas e destinos do Windows CE (ARM, MIPS, suporte a SH4 e Thumb) com o Visual C++, o. Seção de CRT é somente leitura. Se seu código depende do comportamento anterior (. As seções de CRT são leitura/gravação), você pode ver um comportamento inesperado.

Para obter mais informações, consulte

- [/MERGE (combinar seções)](../../build/reference/merge-combine-sections.md)

- [comment (C/C++)](../../preprocessor/comment-c-cpp.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK4254.

```
// LNK4254.cpp
// compile with: /W1 /link /WX
// LNK4254 expected
#pragma comment(linker, "/merge:.data=.text")
int main() {}
```