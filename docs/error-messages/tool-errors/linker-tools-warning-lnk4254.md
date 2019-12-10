---
title: Aviso LNK4254 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4254
helpviewer_keywords:
- LNK4254
ms.assetid: 6f41dfb3-ca21-40d3-bac7-b637e578efa4
ms.openlocfilehash: 8431bd2d89fd5df5cf076ad006ab04006f552c4c
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988067"
---
# <a name="linker-tools-warning-lnk4254"></a>Aviso LNK4254 (Ferramentas de Vinculador)

seção ' section1 ' (deslocamento) mesclado em ' section2 ' (deslocamento) com atributos diferentes

O conteúdo de uma seção foi mesclado em outro, mas os atributos das duas seções são diferentes. Seu programa pode fornecer resultados inesperados. Por exemplo, os dados que você queria ser somente leitura podem agora estar em uma seção gravável.

Para resolver o LNK4254, modifique ou remova a solicitação de mesclagem.

Ao direcionar computadores x86 e destinos de Windows CE (ARM, MIPS, SH4 e Thumb) com C++Visual, o. A seção CRT é somente leitura. Se seu código depende do comportamento anterior (. As seções CRT são de leitura/gravação), você pode ver um comportamento inesperado.

Para obter mais informações, consulte

- [/MERGE (combinar seções)](../../build/reference/merge-combine-sections.md)

- [comment (C/C++)](../../preprocessor/comment-c-cpp.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK4254.

```cpp
// LNK4254.cpp
// compile with: /W1 /link /WX
// LNK4254 expected
#pragma comment(linker, "/merge:.data=.text")
int main() {}
```
