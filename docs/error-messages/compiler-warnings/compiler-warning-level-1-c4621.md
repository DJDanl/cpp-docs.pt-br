---
title: "Compilador (nível 1) de aviso C4621 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4621
dev_langs: C++
helpviewer_keywords: C4621
ms.assetid: 40931bd9-cb89-497e-86f0-cec9f016c63c
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a4a9252e615ad0fe1ede02e374294e03db38eca4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4621"></a>Compilador C4621 de aviso (nível 1)
nenhuma forma de pós-fixo de 'operator--' encontrado para o tipo 'type', usando forma de prefixo  
  
 Não havia nenhum operador de decremento de sufixo definido para o tipo fornecido. O compilador usado o operador de prefixo sobrecarregados.  
  
 Esse aviso pode ser evitado por meio da definição de um sufixo `--` operador. Criar uma versão de dois argumentos do `--` operador conforme mostrado abaixo:  
  
```  
// C4621.cpp  
// compile with: /W1  
class A  
{  
public:  
   A(int nData) : m_nData(nData)  
   {  
   }  
  
   A operator--()  
   {  
      m_nData -= 1;  
      return *this;  
   }  
  
   // A operator--(int)  
   // {  
   //    A tmp = *this;  
   //    m_nData -= 1;  
   //    return tmp;  
   // }  
  
private:  
   int m_nData;  
};  
  
int main()  
{  
   A a(10);  
   --a;  
   a--;   // C4621  
}  
```