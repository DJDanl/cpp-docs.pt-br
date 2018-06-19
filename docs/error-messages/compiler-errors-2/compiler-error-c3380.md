---
title: C3380 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3380
dev_langs:
- C++
helpviewer_keywords:
- C3380
ms.assetid: 86f1f4ec-4ad8-4a1a-9b6c-2d9b6129df6b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 315031946f9a89f53097e4c2371286fba213f698
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33252442"
---
# <a name="compiler-error-c3380"></a>C3380 de erro do compilador
'class': acesso de assembly inválido especificador - apenas 'public' ou 'private' é permitidas  
  
 Quando aplicado a uma classe gerenciada ou estrutura, o [pública](../../cpp/public-cpp.md) e [privada](../../cpp/private-cpp.md) palavras-chave que indicam se a classe será exposta por meio de metadados do assembly. Somente `public` ou `private` pode ser aplicado a uma classe em um programa compilado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 O `ref` e `value` palavras-chave, quando usado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md), indicar que uma classe é gerenciada (consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md)).  
  
 O exemplo a seguir gera C3380:  
  
```  
// C3380_2.cpp  
// compile with: /clr  
protected ref class A {   // C3380  
// try the following line instead  
// ref class A {  
public:  
   static int i = 9;  
};  
  
int main() {  
   A^ myA = gcnew A;  
   System::Console::WriteLine(myA->i);  
}  
```  
