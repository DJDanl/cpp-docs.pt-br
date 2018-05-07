---
title: Ferramentas de vinculador LNK2033 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2033
dev_langs:
- C++
helpviewer_keywords:
- LNK2033
ms.assetid: d61db467-9328-4788-bf54-e2a20537f13f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d03e8d2e0502d6e3664bff05c75fffb4f4ebd5da
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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