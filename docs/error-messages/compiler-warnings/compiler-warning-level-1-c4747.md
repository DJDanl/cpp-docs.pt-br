---
title: "Compilador (nível 1) de aviso C4747 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4747
dev_langs: C++
helpviewer_keywords: C4747
ms.assetid: af37befd-ba1f-4bdc-96e1-a953f7a2ad9c
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 094576ec19582b640ba0d4c57dfa34593177a267
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4747"></a>Compilador C4747 de aviso (nível 1)
Chamar 'entrypoint' gerenciado: código gerenciado não pode ser executado sob bloqueio do carregador, incluindo o ponto de entrada DLL e chamadas acessadas do ponto de entrada DLL  
  
 O compilador encontrar um ponto de entrada DLL (provável) compilado para MSIL.  Devido a possíveis problemas com o carregamento de uma DLL cujo ponto de entrada foi compilado para MSIL, são altamente desaconselhável compilação de uma função de ponto de entrada DLL para MSIL.  
  
 Para obter mais informações, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md) e [LNK1306 de erro de ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-error-lnk1306.md).  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Não compilar o módulo com **/clr**.  
  
2.  Marcar a função de ponto de entrada com `#pragma unmanaged`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4747.  
  
```  
// C4747.cpp  
// compile with: /clr /c /W1  
// C4747 expected  
#include <windows.h>  
  
// Uncomment the following line to resolve.  
// #pragma unmanaged  
  
BOOL WINAPI DllMain(HANDLE hInstance, ULONG Command, LPVOID Reserved) {  
   return TRUE;  
};  
```