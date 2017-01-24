---
title: "Descarregando uma DLL carregada com atraso | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__FUnloadDelayLoadedDLL2"
  - "carregamento atrasado de DLLs, descarregando"
ms.assetid: 6463bc71-020e-4aff-a4ca-90360411c54e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Descarregando uma DLL carregada com atraso
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O auxiliar o fornecido de atraso\- carga verifica se os descritores de atraso\- carga têm um ponteiro e uma cópia da tabela de endereço original \(IAT\) de importação no campo de pUnloadIAT.  Nesse caso, salve um ponteiro em uma lista para o descritor de atraso de importação.  Isso permite que a função auxiliar para localizar por nome a DLL para oferecer suporte ao descarregamento de que o DLL explicitamente.  
  
 Aqui estão as estruturas e as funções associadas para descarregar explicitamente uma DLL atraso\- carregado:  
  
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
  
 A estrutura de UnloadInfo é implementada usando a classe c criando que usa implementações de **LocalAlloc** e de **LocalFree** como o operador **new** e operador **delete** respectivamente.  Essas opções são mantidas em uma lista vinculada padrão usando o \_\_puiHead como o início da lista.  
  
 O \_\_FUnloadDelayLoadedDLL de chamada tentará encontrar o nome que você fornece na lista de DLL carregados \(uma correspondência exata é necessária\).  Se localizada, a cópia de IAT em pUnloadIAT é copiada na parte superior da execução IAT para restaurar os ponteiros de thunk, a biblioteca é lançada com o **FreeLibrary**, o registro de **UnloadInfo** de correspondência unlinked de e é excluído, e TRUE será retornado.  
  
 O argumento para a função \_\_FUnloadDelayLoadedDLL2 diferencia maiúsculas de minúsculas.  Por exemplo, você poderia especificar:  
  
```  
__FUnloadDelayLoadedDLL2("user32.DLL");  
```  
  
 e não:  
  
```  
__FUnloadDelayLoadedDLL2("User32.DLL");.  
```  
  
## Consulte também  
 [Understanding the Helper Function](http://msdn.microsoft.com/pt-br/6279c12c-d908-4967-b0b3-cabfc3e91d3d)