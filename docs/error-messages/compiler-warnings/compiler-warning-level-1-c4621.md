---
title: "Compilador aviso (nível 1) C4621 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4621
dev_langs:
- C++
helpviewer_keywords:
- C4621
ms.assetid: 40931bd9-cb89-497e-86f0-cec9f016c63c
caps.latest.revision: 6
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a6ffb0ea88a08adf877b0ca14ffdf8531159d8aa
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4621"></a>Compilador C4621 de aviso (nível 1)
nenhuma forma de sufixo de 'operador' – encontrado para o tipo 'type', usando o formato de prefixo  
  
 Não havia nenhum operador de decremento de sufixo definido para o tipo de dado. O compilador usou o operador sobrecarregado de prefixo.  
  
 Esse aviso pode ser evitado definindo um sufixo `--` operador. Criar uma versão de dois argumentos do `--` operador conforme mostrado abaixo:  
  
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
