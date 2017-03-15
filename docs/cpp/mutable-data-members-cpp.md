---
title: "Membros de dados mut&#225;veis (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "mutable_cpp"
  - "mutable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave mutable [C++]"
ms.assetid: ebe89746-3d36-43a8-8d69-f426af23f551
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Membros de dados mut&#225;veis (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa palavra\-chave só pode ser aplicada aos membros de dados não estáticas e não constantes de uma classe.  Se um membro de dados for declarado como `mutable`, então é válido atribuir um valor a este membro de dados de uma função membro **const**.  
  
## Sintaxe  
  
```  
  
mutable member-variable-declaration;  
```  
  
## Comentários  
 Por exemplo, o código a seguir será compilado sem erros porque `m_accessCount` foi declarado como `mutable` e, consequentemente, pode ser alterado por `GetFlag`, mesmo que `GetFlag` seja uma função de membro constante.  
  
```  
// mutable.cpp  
class X  
{  
public:  
   bool GetFlag() const  
   {  
      m_accessCount++;  
      return m_flag;  
   }  
private:  
   bool m_flag;  
   mutable int m_accessCount;  
};  
  
int main()  
{  
}  
```  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)