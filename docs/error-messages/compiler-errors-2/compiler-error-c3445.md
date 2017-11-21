---
title: C3445 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 04/10/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3445
dev_langs: C++
helpviewer_keywords: C3445
ms.assetid: 0d272bfc-136b-4025-a9ba-5e4eea5f8215
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: e880eca87816973d531a2662486dde0ae7c77987
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3445"></a>C3445 de erro do compilador
Copy-list-initialization de '*tipo*' não é possível usar um construtor explícito  
  
Acordo com o ISO C++ 17 padrão, o compilador é necessário considerar um construtor explícito para a resolução de sobrecarga na inicialização da lista de cópia, mas deve gerar um erro se essa sobrecarga é na verdade escolhida.  
  
A partir do Visual Studio de 2017, o compilador encontra erros relacionados a criação do objeto usando uma lista de inicializadores não foram encontrados pelo Visual Studio 2015. Esses erros podem levar a falhas ou comportamento indefinido em tempo de execução.

## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3445.  
  
```cpp  
// C3445.cpp  
struct A
{
    explicit A(int) {} 
    A(double) {}
};

int main()
{
    A a1 = { 1 };     // error C3445: copy-list-initialization of 
                      //     'A' cannot use an explicit constructor
}
```  
  
Para corrigir o erro, use inicialização direta:  
  
```cpp  
// C3445b.cpp  
struct A
{
    explicit A(int) {} 
    A(double) {}
};

int main()
{
    A a1{ 1 };
}  
```  
  