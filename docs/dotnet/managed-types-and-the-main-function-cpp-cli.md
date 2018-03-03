---
title: "Tipos gerenciados e a função principal (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- main function, in managed applications
- managed code, main() function
ms.assetid: 9d0e9620-58c4-4dac-a0e1-ffeb95f80fa5
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 706cd8b15dffb1cde4fc5bbc399789b2aafd6ddf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="managed-types-and-the-main-function-ccli"></a>Tipos gerenciados e a função principal (C++/CLI)
Ao escrever um aplicativo usando **/clr**, os argumentos do **Main** função não pode ser de um tipo gerenciado.  
  
 Um exemplo de uma assinatura apropriada é:  
  
```  
// managed_types_and_main.cpp  
// compile with: /clr  
int main(int, char*[], char*[]) {}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Tipos gerenciados (C++/CLI)](../dotnet/managed-types-cpp-cli.md)