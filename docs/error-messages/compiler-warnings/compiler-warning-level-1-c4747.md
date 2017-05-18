---
title: "Compilador aviso (nível 1) C4747 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4747
dev_langs:
- C++
helpviewer_keywords:
- C4747
ms.assetid: af37befd-ba1f-4bdc-96e1-a953f7a2ad9c
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7ecbfe8e2ace06cb6e667d77d315f544ce0b451c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4747"></a>Compilador C4747 de aviso (nível 1)
Chamando gerenciado 'entrypoint': código gerenciado não pode ser executado sob bloqueio do carregador, incluindo o ponto de entrada DLL e acessadas a partir do ponto de entrada da DLL de chamadas  
  
 O compilador encontrar um ponto de entrada (provável) DLL compilado para MSIL.  Devido a possíveis problemas com o carregamento de uma DLL cujo ponto de entrada foi compilado para MSIL, são altamente desaconselhável compilação de uma função de ponto de entrada da DLL para MSIL.  
  
 Para obter mais informações, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md) e [erro das ferramentas de vinculador LNK1306](../../error-messages/tool-errors/linker-tools-error-lnk1306.md).  
  
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
