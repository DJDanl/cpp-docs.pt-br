---
title: Aviso LNK4254 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4254
helpviewer_keywords:
- LNK4254
ms.assetid: 6f41dfb3-ca21-40d3-bac7-b637e578efa4
ms.openlocfilehash: 2c68e49d58b0fd6b28607eb0ba78c092441f6f4b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62352483"
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