---
title: Exportando funções do C para uso em executáveis da linguagem C++ ou C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- functions [C], exporting
- functions [C], C or C++ executables and
- __cplusplus macro
- exporting DLLs [C++], C functions in C++ executables
- exporting functions [C++], C functions in C++ executables
ms.assetid: b51d6e5e-37cf-4c1c-b0bf-fcf188c82f00
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 88d9b18620c2e648ab519a59745876569b66ec30
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45708091"
---
# <a name="exporting-c-functions-for-use-in-c-or-c-language-executables"></a>Exportando funções do C a serem usadas em executáveis da linguagem C ou C++

Se você tiver funções em uma DLL escrita em C que você deseja acessar a partir de uma linguagem C ou um módulo de idioma do C++, você deve usar o **cplusplus** macro do pré-processador para determinar qual idioma está sendo compilado e, em seguida, declare esses funções com vínculo a C se sendo usado de um módulo de linguagem C++. Se você usa essa técnica e fornece os arquivos de cabeçalho para a DLL, essas funções podem ser usadas por usuários de C e C++ sem nenhuma alteração.

O código a seguir mostra um arquivo de cabeçalho que pode ser usado por aplicativos de cliente do C e C++:

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

Se você precisa vincular funções C para o executável do C++ e os arquivos de cabeçalho de declaração de função não tem usado a técnica acima, o arquivo de origem do C++, faça o seguinte para impedir que o compilador decorando os nomes de função C:

```cpp
extern "C" {
#include "MyCHeader.h"
}
```

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)

- [Determinar qual método de exportação usar](../build/determining-which-exporting-method-to-use.md)

- [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)

- [Inicialize um DLL](../build/run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Nomes decorados](../build/reference/decorated-names.md)

- [Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)

## <a name="see-also"></a>Consulte também

[Exportando de uma DLL](../build/exporting-from-a-dll.md)