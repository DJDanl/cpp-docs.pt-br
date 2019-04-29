---
title: Aviso LNK4253 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4253
helpviewer_keywords:
- LNK4253
ms.assetid: ec7433a9-aa9c-495a-a9f2-075e7bc3e7bc
ms.openlocfilehash: d2fd7238a3f57b11b91813bd40b66cb3e9f47202
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62352510"
---
# <a name="linker-tools-warning-lnk4253"></a>Aviso LNK4253 (Ferramentas de Vinculador)

seção 'section1' não mesclada dentro de 'section2'; já mesclada dentro de 'Remoções3'

O vinculador detectou vários, solicitações de mesclagem conflitante. O vinculador irá ignorar uma das solicitações.

Um **/MERGE** opção ou diretiva é encontrada e o `from` seção já foram mesclada em uma seção diferente devido a um anteriores **/MERGE** opção ou diretiva (ou devido a uma mesclagem implícita de o vinculador).

Para resolver LNK4253, remova uma das solicitações de mesclagem.

Ao direcionar x86 máquinas e destinos do Windows CE (ARM, MIPS, suporte a SH4 e Thumb) com o Visual C++, o. Seção de CRT agora é somente leitura. Se seu código depende do comportamento anterior (. As seções de CRT são leitura/gravação), você pode ver um comportamento inesperado.

Para obter mais informações, consulte

- [/MERGE (combinar seções)](../../build/reference/merge-combine-sections.md)

- [comment (C/C++)](../../preprocessor/comment-c-cpp.md)

## <a name="example"></a>Exemplo

No exemplo a seguir, o vinculador é instruído para mesclar o `.rdata` seção duas vezes, mas em diferentes seções. O exemplo a seguir gera LNK4253.

```
// LNK4253.cpp
// compile with: /W1 /link /merge:.rdata=text2
// LNK4253 expected
#pragma comment(linker, "/merge:.rdata=.text")
int main() {}
```