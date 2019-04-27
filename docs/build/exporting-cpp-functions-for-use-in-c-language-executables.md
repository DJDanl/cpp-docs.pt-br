---
title: Exportando funções do C++ a serem usadas em executáveis da linguagem C
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C++], C++ functions in C executables
- exporting DLLs [C++], C++ functions in C executables
- exporting functions [C++], C++ functions in C executables
- functions [C++], exporting
ms.assetid: 80b9e982-f52d-4312-a891-f73cc69f3c2b
ms.openlocfilehash: a694b77e3730ab82ec1698076cc66729ff115cdc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62195228"
---
# <a name="exporting-c-functions-for-use-in-c-language-executables"></a>Exportando funções do C++ a serem usadas em executáveis da linguagem C

Se você tiver funções em uma DLL escrita em C++ que você deseja acessar a partir de um módulo de linguagem C, você deve declarar essas funções com vínculo a C em vez de vinculação C++. Salvo indicação em contrário, o compilador C++ usa C++ (também conhecido como a decoração de nome) de nomenclatura de tipo seguro e C++ convenções de chamada, que podem ser difícil de chamada do C.

Para especificar o vínculo a C, especifique `extern "C"` para suas declarações de função. Por exemplo:

```
extern "C" __declspec( dllexport ) int MyFunc(long parm1);
```

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando dllexport](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções de C para uso em executáveis C ou da linguagem C++](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicialize um DLL](run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Nomes decorados](reference/decorated-names.md)

- [Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)

## <a name="see-also"></a>Consulte também

[Exportando de uma DLL](exporting-from-a-dll.md)
