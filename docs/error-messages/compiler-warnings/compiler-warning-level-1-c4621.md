---
title: "Aviso do compilador (n&#237;vel 1) C4621 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4621"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4621"
ms.assetid: 40931bd9-cb89-497e-86f0-cec9f016c63c
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4621
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

nenhuma forma de pós\-fixação do operador “ \-\-” encontrado para o tipo “tipo”, com o formato de prefixo  
  
 Não havia nenhum operador diminuição de pós\-fixação definido para o tipo indicado.  O compilador usa o operador do prefixo sobrecarregado.  
  
 Esse aviso pode ser evitado configurando um operador de `--` de pós\-fixação.  Crie uma versão de dois argumentos do operador de `--` conforme mostrado abaixo:  
  
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