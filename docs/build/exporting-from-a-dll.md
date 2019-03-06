---
title: Exportando a partir de uma DLL
ms.date: 11/04/2016
helpviewer_keywords:
- exporting DLLs [C++], about exporting from DLLs
- exporting functions [C++], DLLs (exporting from)
- exporting DLLs [C++]
- DLLs [C++], exporting from
- DLL exports [C++]
- functions [C++], exporting
- exports table [C++]
ms.assetid: a08f86c4-5996-460b-ae54-da2b764045f0
ms.openlocfilehash: ac00df5a1bf1bcfaa300e12bb47cf1e6291aa0f1
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57416223"
---
# <a name="exporting-from-a-dll"></a>Exportando a partir de uma DLL

Um arquivo DLL tem um layout muito semelhante a um arquivo .exe, com uma diferença importante — um arquivo DLL contém uma tabela de exportações. A tabela de exportações contém o nome de cada função que a DLL exporta para outros executáveis. Essas funções são os pontos de entrada na DLL; apenas as funções na tabela de exportações podem ser acessadas por outros executáveis. Todas as outras funções na DLL são privadas para a DLL. A tabela de exportações de uma DLL pode ser exibida usando o [DUMPBIN](../build/reference/dumpbin-reference.md) ferramenta com a opção/exportações.

Você pode exportar funções de uma DLL usando dois métodos:

- Criar um arquivo de definição (. def) do módulo e usar o arquivo. def, ao criar a DLL. Use essa abordagem se você quiser [exportar funções de DLL por ordinal em vez de nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).

- Use a palavra-chave **dllexport** na definição da função.

Ao exportar funções com um desses métodos, certifique-se de usar o [stdcall](../cpp/stdcall.md) convenção de chamada.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções de C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções de C para uso em executáveis C ou da linguagem C++](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Funções de exportação de uma DLL por ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md)

- [Determinar qual método de exportação usar](../build/determining-which-exporting-method-to-use.md)

- [Determinar qual método de vinculação usar](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

- [Inicialize um DLL](../build/run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Importando para um aplicativo](../build/importing-into-an-application.md)

- [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)

- [Importações mútuas](../build/mutual-imports.md)

## <a name="see-also"></a>Consulte também

[Importando e exportando](../build/importing-and-exporting.md)
