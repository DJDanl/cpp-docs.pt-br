---
title: Descarregando uma DLL carregada com atraso
ms.date: 11/04/2016
helpviewer_keywords:
- __FUnloadDelayLoadedDLL2
- delayed loading of DLLs, unloading
ms.assetid: 6463bc71-020e-4aff-a4ca-90360411c54e
ms.openlocfilehash: 1895bf12cb195ef7b4555d400badf112d377547b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211912"
---
# <a name="unloading-a-delay-loaded-dll"></a>Descarregando uma DLL carregada com atraso

O auxiliar de carregamento de atraso fornecido por padrão verifica se os descritores de carga de atraso têm um ponteiro e uma cópia da tabela de endereços de importação original (IAT) no campo pUnloadIAT. Nesse caso, ele salvará um ponteiro em uma lista para o descritor de atraso de importação. Isso permite que a função auxiliar localize a DLL pelo nome para dar suporte ao descarregamento de DLL explicitamente.

Aqui estão as estruturas e funções associadas para descarregar explicitamente uma DLL carregada com atraso:

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

A estrutura UnloadInfo é implementada usando uma classe C++ que usa implementações **LocalAlloc** e **LocalFree** como operador e operador, **`new`** **`delete`** respectivamente. Essas opções são mantidas em uma lista vinculada padrão usando __puiHead como o cabeçalho da lista.

Chamar __FUnloadDelayLoadedDLL tentará localizar o nome fornecido na lista de DLLs carregadas (é necessária uma correspondência exata). Se for encontrado, a cópia do IAT em pUnloadIAT será copiada sobre a parte superior do IAT em execução para restaurar os ponteiros de conversão, a biblioteca será liberada com **FreeLibrary**, o registro **UnloadInfo** correspondente será desvinculado da lista e excluído e true será retornado.

O argumento para a função __FUnloadDelayLoadedDLL2 diferencia maiúsculas de minúsculas. Por exemplo, você deve especificar:

```cpp
__FUnloadDelayLoadedDLL2("user32.DLL");
```

e não:

```cpp
__FUnloadDelayLoadedDLL2("User32.DLL");.
```

## <a name="see-also"></a>Confira também

[Compreendendo a função auxiliar](understanding-the-helper-function.md)
