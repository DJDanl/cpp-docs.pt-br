---
title: Descarregando uma DLL carregada com atraso | Microsoft Docs
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
ms.openlocfilehash: 724ee2ac3987c855f5e2102dee35d12785726641
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="unloading-a-delay-loaded-dll"></a>Descarregando uma DLL carregada com atraso
O carregamento de atraso padrão fornecido pelo auxiliar verifica se os descritores de carregamento de atraso tem um ponteiro e uma cópia da tabela de endereço de importação original (IAT) no campo pUnloadIAT. Nesse caso, ele salvará um ponteiro em uma lista para o descritor de atraso de importação. Isso permite que a função auxiliar localizar a DLL por nome para dar suporte ao descarregar essa DLL explicitamente.  
  
 Aqui estão as funções de descarregamento explicitamente uma DLL carregada com atraso e estruturas associadas:  
  
```  
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
  
 A estrutura UnloadInfo é implementada usando uma classe C++ que usa **LocalAlloc** e **LocalFree** implementações como seu operador **novo** e operador  **Excluir** respectivamente. Essas opções são mantidas em uma lista vinculada padrão usando __puiHead como o início da lista.  
  
 Chamar __FUnloadDelayLoadedDLL tentará localizar o nome fornecem na lista de DLLs carregadas (uma correspondência exata é necessária). Se encontrado, a cópia de IAT na pUnloadIAT será copiada na parte superior de IAT em execução para restaurar os ponteiros de conversão, a biblioteca é liberada com **FreeLibrary**, a correspondência **UnloadInfo** registro é desvinculado da a lista excluída e é retornado verdadeiro.  
  
 O argumento para a função __FUnloadDelayLoadedDLL2 diferencia maiusculas de minúsculas. Por exemplo, você deve especificar:  
  
```  
__FUnloadDelayLoadedDLL2("user32.DLL");  
```  
  
 e não:  
  
```  
__FUnloadDelayLoadedDLL2("User32.DLL");.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas sobre a função auxiliar](understanding-the-helper-function.md)