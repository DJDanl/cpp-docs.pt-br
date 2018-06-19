---
title: Compilador (níveis 2 e 4) de aviso C4200 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4200
dev_langs:
- C++
helpviewer_keywords:
- C4200
ms.assetid: e44d6073-937f-42b7-acc1-65e802b475c6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6ffc789c3c4da5caf50f0657e17ddabe40a5773c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33294944"
---
# <a name="compiler-warning-levels-2-and-4-c4200"></a>Compilador C4200 de aviso (níveis 2 e 4)
extensão não padrão usada: matriz de tamanho zero na estrutura/união  
  
 Indica que uma estrutura ou união contém uma matriz de tamanho zero.  
  
 A declaração de uma matriz de tamanho zero é uma extensão da Microsoft. Isso causa um aviso de nível 2 quando um arquivo C++ é compilado e um aviso de nível 4 quando um arquivo C é compilado. A compilação do C++ também fornece esse aviso: "Não é possível gerar operador construtor de cópia ou de atribuição de cópia quando UDT tiver uma matriz de tamanho zero." Este exemplo gera um aviso C4200:  
  
```cpp  
// C4200.cpp  
// compile by using: cl /W4 c4200.cpp  
struct A {  
    int a[0];  // C4200  
};  
int main() {  
}  
```  
  
 Essa extensão não padrão geralmente é usada para código da interface com estruturas de dados externos que têm um comprimento variável. Se esse cenário se aplicar ao seu código, você pode desabilitar o aviso:  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// C4200b.cpp  
// compile by using: cl /W4 c4200a.cpp  
#pragma warning(disable : 4200)  
struct A {  
    int a[0];  
};  
int main() {  
}  
```