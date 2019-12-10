---
title: Aviso LNK4253 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4253
helpviewer_keywords:
- LNK4253
ms.assetid: ec7433a9-aa9c-495a-a9f2-075e7bc3e7bc
ms.openlocfilehash: c3f45880571e5c06f76d5f063ff993e2f6b2be9b
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988091"
---
# <a name="linker-tools-warning-lnk4253"></a>Aviso LNK4253 (Ferramentas de Vinculador)

a seção ' section1 ' não foi mesclada em ' section2 '; Já mesclado em ' section3 '

O vinculador detectou várias solicitações de mesclagem conflitantes. O vinculador irá ignorar uma das solicitações.

Uma opção ou diretiva **/Merge** é encontrada e a seção `from` já foi mesclada em uma seção diferente devido a uma opção **/Merge** ou diretiva anterior (ou devido a uma mesclagem implícita do vinculador).

Para resolver o LNK4253, remova uma das solicitações de mesclagem.

Ao direcionar computadores x86 e destinos de Windows CE (ARM, MIPS, SH4 e Thumb) com C++Visual, o. A seção CRT agora é somente leitura. Se seu código depende do comportamento anterior (. As seções CRT são de leitura/gravação), você pode ver um comportamento inesperado.

Para obter mais informações, consulte

- [/MERGE (combinar seções)](../../build/reference/merge-combine-sections.md)

- [comment (C/C++)](../../preprocessor/comment-c-cpp.md)

## <a name="example"></a>Exemplo

No exemplo a seguir, o vinculador é instruído a Mesclar a seção `.rdata` duas vezes, mas em seções diferentes. O exemplo a seguir gera LNK4253.

```cpp
// LNK4253.cpp
// compile with: /W1 /link /merge:.rdata=text2
// LNK4253 expected
#pragma comment(linker, "/merge:.rdata=.text")
int main() {}
```
