---
title: Ferramentas de vinculador LNK2033 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK2033
dev_langs: C++
helpviewer_keywords: LNK2033
ms.assetid: d61db467-9328-4788-bf54-e2a20537f13f
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 41bba79acaca7a83e4103d7d146831dc60c2c2ca
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-error-lnk2033"></a>Erro das Ferramentas de Vinculador LNK2033
token typeref indefinido (token) para 'type'  
  
 Um tipo não tem uma definição em metadados MSIL.  
  
 LNK2033 pode ocorrer ao compilar com **/CLR: safe** e em que haja somente uma declaração de encaminhamento de um tipo em um módulo MSIL, onde o tipo é referenciado no módulo MSIL.  
  
 O tipo deve ser definido em **/CLR: safe**.  
  
 Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK2033.  
  
```  
// LNK2033.cpp  
// compile with: /clr:safe  
// LNK2033 expected  
ref class A;  
ref class B {};  
  
int main() {  
   A ^ aa = nullptr;  
   B ^ bb = nullptr;   // OK  
};  
```