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
ms.openlocfilehash: 6bdf5b86724ae07aa073a9feb1cc4d5723bc6e6b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62196736"
---
# <a name="exporting-from-a-dll"></a>Exportando a partir de uma DLL

Um arquivo DLL tem um layout muito semelhante a um arquivo. exe, com uma diferença importante — um arquivo DLL contém uma tabela Exports. A tabela Exports contém o nome de cada função que a DLL exporta para outros executáveis. Essas funções são os pontos de entrada na DLL; somente as funções na tabela Exports podem ser acessadas por outros executáveis. Todas as outras funções na DLL são privadas para a DLL. A tabela Exports de uma DLL pode ser exibida usando a ferramenta [DUMPBIN](reference/dumpbin-reference.md) com a opção/EXPORTS.

Você pode exportar funções de uma DLL usando dois métodos:

- Crie um arquivo de definição de módulo (. def) e use o arquivo. def ao compilar a DLL. Use essa abordagem se você quiser [Exportar funções de sua DLL por ordinal em vez de por nome](exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).

- Use a palavra-chave **__declspec (dllexport)** na definição da função.

Ao exportar funções com qualquer método, certifique-se de usar a Convenção de chamada [__stdcall](../cpp/stdcall.md) .

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando o AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções C++ para uso em executáveis de linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções C para uso em executáveis de linguagem C ou C++](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Exportar funções de uma DLL por ordinal em vez de por nome](exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

- [Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Importando para um aplicativo](importing-into-an-application.md)

- [Importação e exportação de funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

## <a name="see-also"></a>Confira também

[Importando e exportando](importing-and-exporting.md)
