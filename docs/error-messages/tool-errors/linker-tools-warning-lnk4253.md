---
title: Ferramentas de vinculador LNK4253 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4253
dev_langs:
- C++
helpviewer_keywords:
- LNK4253
ms.assetid: ec7433a9-aa9c-495a-a9f2-075e7bc3e7bc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d26d688825f504cbce8224adc9a5766a555d2fc8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016813"
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