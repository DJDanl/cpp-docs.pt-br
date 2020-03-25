---
title: Erro das Ferramentas de Vinculador LNK2011
ms.date: 11/04/2016
f1_keywords:
- LNK2011
helpviewer_keywords:
- LNK2011
ms.assetid: 04991ef5-49d5-46c7-8eee-a9d1d3fc541e
ms.openlocfilehash: e08f068099af68375523eae0f0cc4d63960f3261
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194805"
---
# <a name="linker-tools-error-lnk2011"></a>Erro das Ferramentas de Vinculador LNK2011

objeto pré-compilado não vinculado; a imagem pode não ser executada

Se você usar cabeçalhos pré-compilados, o LINK exigirá que todos os arquivos de objeto criados com cabeçalhos pré-compilados devam ser vinculados. Se você tiver um arquivo de origem que usa para gerar um cabeçalho pré-compilado para uso com outros arquivos de origem, agora você deve incluir o arquivo de objeto criado junto com o cabeçalho pré-compilado.

Por exemplo, se você compilar um arquivo chamado STUB. cpp para criar um cabeçalho pré-compilado para uso com outros arquivos de origem, será necessário vincular com STUB. obj ou você receberá esse erro. Nas linhas de comando a seguir, a linha um é usada para criar um cabeçalho pré-compilado, COMMON. pch, que é usado com PROG1. cpp e PROG2. cpp nas linhas dois e três. O arquivo STUB. cpp contém apenas `#include` linhas (as mesmas linhas de `#include` como em PROG1. cpp e PROG2. cpp) e é usado somente para gerar cabeçalhos pré-compilados. Na última linha, STUB. obj deve ser vinculado para evitar LNK2011.

```
cl /c /Yccommon.h stub.cpp
cl /c /Yucommon.h prog1.cpp
cl /c /Yucommon.h prog2.cpp
link /out:prog.exe stub.obj prog1.obj prog2.obj
```
