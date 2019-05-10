---
title: Suporte de vinculador para DLLs carregadas com atraso
ms.date: 11/04/2016
helpviewer_keywords:
- delayed loading of DLLs, linker support
ms.assetid: b2d7e449-2809-42b1-9c90-2c0ca5e31a14
ms.openlocfilehash: 384ea563853906a76e2c9993cbcedb3b15c354f2
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65217597"
---
# <a name="linker-support-for-delay-loaded-dlls"></a>Suporte de vinculador para DLLs carregadas com atraso

O vinculador MSVC agora dá suporte o carregamento atrasado de DLLs. Isso libera você da necessidade de usar as funções do SDK do Windows **LoadLibrary** e **GetProcAddress** para implementar a DLL de carregamento com atraso.

Antes do Visual C++ 6.0, a única maneira de carregar uma DLL em tempo de execução era usando **LoadLibrary** e **GetProcAddress**; o sistema operacional carrega a DLL quando o arquivo executável ou DLL usando ele foi carregado.

Começando com o Visual C++ 6.0, quando estiver vinculando implicitamente com uma DLL, o vinculador fornece opções para atrasar a carregam a DLL até que o programa chama uma função nessa DLL.

Um aplicativo pode atrasar a carregar uma DLL usando o [/DELAYLOAD (importação de carga com atraso)](delayload-delay-load-import.md) opção de vinculador com uma função auxiliar (implementação padrão fornecida pelo Visual C++). A função auxiliar carregará a DLL em tempo de execução chamando **LoadLibrary** e **GetProcAddress** para você.

Você deve considerar o atraso ao carregar uma DLL se:

- Seu programa não pode chamar uma função na DLL.

- Uma função na DLL não pode ser chamada até o final do execução do programa.

O carregamento atrasado de uma DLL pode ser especificado durante a compilação de um. EXE ou. Projeto de DLL. A. Projeto DLL que retarda o carregamento de uma ou mais DLLs não deve se chamar um ponto de entrada carregadas com atraso na Dllmain.

Os tópicos a seguir descrevem as DLLs de carregamento com atraso:

- [Especificando DLLs para carregamento com atraso](specifying-dlls-to-delay-load.md)

- [Descarregando de maneira explícita uma DLL carregada com atraso](explicitly-unloading-a-delay-loaded-dll.md)

- [Carregando todas as importações para uma DLL carregada com atraso](loading-all-imports-for-a-delay-loaded-dll.md)

- [Associando importações](binding-imports.md)

- [Tratamento de erro e notificação](error-handling-and-notification.md)

- [Despejando importações carregadas com atraso](dumping-delay-loaded-imports.md)

- [Restrições para o carregamento de DLLs com atraso](constraints-of-delay-loading-dlls.md)

- [Noções básicas sobre a função auxiliar](understanding-the-helper-function.md)

- [Desenvolvendo sua própria função auxiliar](developing-your-own-helper-function.md)

## <a name="see-also"></a>Consulte também

[Criar DLLs de C/C++ no Visual Studio](../dlls-in-visual-cpp.md)<br/>
[Referência de vinculador MSVC](linking.md)
