---
title: Compilações de lançamento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- debugging [C++], release builds
- release builds
- debug builds, converting to release build
ms.assetid: fa9a78fa-f4b5-4722-baf4-aec655c4ff0f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f3ae18c5e2dcdb735880509fd158dac4ccaa1462
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="release-builds"></a>Builds de lançamento
Uma compilação de versão usa otimizações. Ao usar otimizações para criar uma compilação de versão, o compilador não produzirá informações simbólicas de depuração. Chama a ausência de informações de depuração simbólicas, juntamente com o fato de que o código não é gerado para rastreamento e ASSERT, significa que o tamanho do seu arquivo executável é reduzido e, portanto, será mais rápida.  
  
 Esta seção apresenta informações sobre por que e quando você deseja alterar de uma compilação de depuração para um build de versão. Ele também aborda alguns dos problemas que você pode encontrar ao alterar de debug para um build de versão:  
  
-   [Criando uma compilação de versão](../../build/reference/how-to-create-a-release-build.md)  
  
-   [Problemas comuns durante a criação de um build de versão](../../build/reference/common-problems-when-creating-a-release-build.md)  
  
-   [Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)  
  
    -   [Examinando instruções ASSERT](../../build/reference/using-verify-instead-of-assert.md)  
  
    -   [Usando a compilação de depuração para verificação de substituição de memória](../../build/reference/using-the-debug-build-to-check-for-memory-overwrite.md)  
  
    -   [Depurando uma compilação de versão](../../build/reference/how-to-debug-a-release-build.md)  
  
    -   [Verificando se há substituições de memória](../../build/reference/checking-for-memory-overwrites.md)  
  
## <a name="see-also"></a>Consulte também  
 [Compilando projetos do C++ no Visual Studio](../../ide/building-cpp-projects-in-visual-studio.md)   
 [Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)