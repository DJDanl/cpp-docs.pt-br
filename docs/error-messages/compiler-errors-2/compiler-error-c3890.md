---
title: C3890 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3890
dev_langs:
- C++
helpviewer_keywords:
- C3890
ms.assetid: 2f22c2fd-c14e-45e1-b936-b739ffc0b135
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bc1bfbba9cfb8991491bcbb42d2e13c586c7fc26
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33273985"
---
# <a name="compiler-error-c3890"></a>C3890 de erro do compilador
'var': não é possível definir o endereço de um membro de dados literais  
  
 Existe um membro de dados literais no heap coletado como lixo.  Um objeto no heap do coletor de lixo pode ser movido para que pegar o endereço não é útil.  
  
 O exemplo a seguir gera C3890:  
  
```  
// C3890.cpp  
// compile with: /clr  
ref struct Y1 {  
   literal int staticConst = 9;  
};  
  
int main() {  
   int p = &Y1::staticConst;   // C3890  
   int p2 = Y1::staticConst;   // OK  
}  
```