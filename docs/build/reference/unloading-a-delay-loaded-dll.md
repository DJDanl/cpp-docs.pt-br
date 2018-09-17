---
title: Descarregando uma DLL carregadas com atraso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- __FUnloadDelayLoadedDLL2
- delayed loading of DLLs, unloading
ms.assetid: 6463bc71-020e-4aff-a4ca-90360411c54e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fa7b9652c37b6c4e841a798dae3cfeb69779b5ff
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45719921"
---
# <a name="unloading-a-delay-loaded-dll"></a>Descarregando uma DLL carregada com atraso

O carregamento de atraso padrão fornecida pelo auxiliar verifica se os descritores de carregamento de atraso tem um ponteiro e uma cópia da tabela de endereço de importação original (IAT) no campo pUnloadIAT. Nesse caso, ele salvará um ponteiro em uma lista ao descritor de atraso de importação. Isso permite que a função auxiliar localizar a DLL por nome para dar suporte ao descarregamento essa DLL explicitamente.

Aqui estão as funções para descarregando de maneira explícita uma DLL carregadas com atraso e estruturas associadas:

```cpp
//
// Unload support from delayimp.h
//

// routine definition; takes a pointer to a name to unload

ExternC
BOOL WINAPI
__FUnloadDelayLoadedDLL2(LPCSTR szDll);

// structure definitions for the list of unload records
typedef struct UnloadInfo * PUnloadInfo;
typedef struct UnloadInfo {
    PUnloadInfo     puiNext;
    PCImgDelayDescr pidd;
    } UnloadInfo;

// from delayhlp.cpp
// the default delay load helper places the unloadinfo records in the
// list headed by the following pointer.
ExternC
PUnloadInfo __puiHead;
```

A estrutura UnloadInfo é implementada usando uma classe C++ que usa **LocalAlloc** e **LocalFree** implementações como seu operador **nova** e o operador  **Excluir** , respectivamente. Essas opções são mantidas em uma lista vinculada padrão usando __puiHead como o cabeçalho da lista.

Chamar __FUnloadDelayLoadedDLL tentará localizar o nome fornecem na lista de DLLs carregadas (uma correspondência exata é necessária). Se encontrado, a cópia da IAT na pUnloadIAT será copiada na parte superior da IAT em execução para restaurar os ponteiros de conversão, a biblioteca é liberada com **FreeLibrary**, a correspondência **UnloadInfo** registro é desvinculado de a lista e excluídos e TRUE será retornado.

O argumento para a função __FUnloadDelayLoadedDLL2 diferencia maiusculas de minúsculas. Por exemplo, você especificaria:

```cpp
__FUnloadDelayLoadedDLL2("user32.DLL");
```

e não:

```cpp
__FUnloadDelayLoadedDLL2("User32.DLL");.
```

## <a name="see-also"></a>Consulte também

[Noções básicas sobre a função auxiliar](understanding-the-helper-function.md)