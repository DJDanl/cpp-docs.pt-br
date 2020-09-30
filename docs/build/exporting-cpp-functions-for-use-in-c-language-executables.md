---
title: Exportando funções do C++ a serem usadas em executáveis da linguagem C
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C++], C++ functions in C executables
- exporting DLLs [C++], C++ functions in C executables
- exporting functions [C++], C++ functions in C executables
- functions [C++], exporting
ms.assetid: 80b9e982-f52d-4312-a891-f73cc69f3c2b
ms.openlocfilehash: 38b13c1fc9c57354ba8160f6dbe0df6546fe7b5f
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506606"
---
# <a name="exporting-c-functions-for-use-in-c-language-executables"></a>Exportando funções do C++ a serem usadas em executáveis da linguagem C

Se você tiver funções em uma DLL gravadas em C++ que deseja acessar a partir de um módulo C-Language, deverá declarar essas funções com vínculo C em vez de vínculo de C++. A menos que especificado de outra forma, o compilador C++ usa o C++ (também conhecido como decoração de nome) e as convenções de chamada de C++, que podem ser difíceis de chamar de C.

Para especificar o vínculo de C, especifique `extern "C"` para suas declarações de função. Por exemplo:

```
extern "C" __declspec( dllexport ) int MyFunc(long parm1);
```

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando o AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções C para uso em executáveis de linguagem C ou C++](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinação do método de exportação a ser usado](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Nomes decorados](reference/decorated-names.md)

- [Usando extern para especificar a ligação](../cpp/extern-cpp.md)

## <a name="see-also"></a>Consulte também

[Exportando a partir de uma DLL](exporting-from-a-dll.md)
