---
title: Builds de versão do C++ - Visual Studio
ms.date: 12/10/2018
helpviewer_keywords:
- debugging [C++], release builds
- release builds
- debug builds, converting to release build
ms.assetid: fa9a78fa-f4b5-4722-baf4-aec655c4ff0f
ms.openlocfilehash: cf11e63354502be000ba5f7259d9e36dfa774060
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315060"
---
# <a name="release-builds"></a>Builds de lançamento

Um build de versão usa otimizações. Quando você usa otimizações para criar um build de versão, o compilador não produzirá informações de depuração simbólicas. A ausência de informações de depuração simbólicas, além do fato de que o código não é gerado para o rastreamento e ASSERT chama, significa que o tamanho do seu arquivo executável é reduzido e, portanto, será mais rápida.

## <a name="in-this-section"></a>Nesta seção

[Problemas comuns durante a criação de um build de versão](common-problems-when-creating-a-release-build.md)<br/>
[Corrigindo problemas do build de versão](fixing-release-build-problems.md)<br/>
[Usando VERIFY em vez de ASSERT](using-verify-instead-of-assert.md)<br/>
[Usando o build de depuração para verificar se há substituição de memória](using-the-debug-build-to-check-for-memory-overwrite.md)<br/>
[Como: depurar um build da versão](how-to-debug-a-release-build.md)<br/>
[Verificando se há substituições de memória](checking-for-memory-overwrites.md)<br/>
[Otimizando seu código](optimizing-your-code.md)<br/>

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](reference/c-cpp-building-reference.md)