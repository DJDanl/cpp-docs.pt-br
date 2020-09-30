---
title: Exportando funções do C a serem usadas em executáveis da linguagem C ou C++
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C], exporting
- functions [C], C or C++ executables and
- __cplusplus macro
- exporting DLLs [C++], C functions in C++ executables
- exporting functions [C++], C functions in C++ executables
ms.assetid: b51d6e5e-37cf-4c1c-b0bf-fcf188c82f00
ms.openlocfilehash: 4dcf46e6bdde66a303afc2c4ec94fc8aefdd5e5d
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506648"
---
# <a name="exporting-c-functions-for-use-in-c-or-c-language-executables"></a>Exportando funções do C a serem usadas em executáveis da linguagem C ou C++

Se você tiver funções em uma DLL gravadas em C que deseja acessar a partir de um módulo de linguagem C ou C++, use a macro **__cplusplus** pré-processador para determinar qual idioma está sendo compilado e, em seguida, declare essas funções com vínculo C se estiverem sendo usadas de um módulo de linguagem C++. Se você usar essa técnica e fornecer arquivos de cabeçalho para sua DLL, essas funções poderão ser usadas por usuários C e C++ sem alteração.

O código a seguir mostra um arquivo de cabeçalho que pode ser usado por aplicativos cliente C e C++:

```h
// MyCFuncs.h
#ifdef __cplusplus
extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif

__declspec( dllimport ) void MyCFunc();
__declspec( dllimport ) void AnotherCFunc();

#ifdef __cplusplus
}
#endif
```

Se você precisar vincular funções C ao seu executável C++ e os arquivos de cabeçalho da declaração de função não usaram a técnica acima, no arquivo de origem C++, faça o seguinte para impedir que o compilador decorar os nomes das funções C:

```cpp
extern "C" {
#include "MyCHeader.h"
}
```

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando o AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Determinação do método de exportação a ser usado](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Nomes decorados](reference/decorated-names.md)

- [Usando extern para especificar a ligação](../cpp/extern-cpp.md)

## <a name="see-also"></a>Consulte também

[Exportando a partir de uma DLL](exporting-from-a-dll.md)
