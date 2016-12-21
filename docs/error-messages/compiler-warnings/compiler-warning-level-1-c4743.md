---
title: "Aviso C4743 (compilador) (n&#237;vel 1) | Microsoft Docs"
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
  - "C4743"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4743"
ms.assetid: 2ee76ea3-77f3-4c2f-9a57-0751823c89fd
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso C4743 (compilador) (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'*type*' tem o tamanho diferente em '*file1*' e em '*file2*': *number* e bytes de *number*  
  
 Uma variável externo referenciado ou definida em arquivos tem dois tipos diferentes nesses arquivos, e o compilador determinados que o tamanho da variável em *file1* difere do tamanho da variável em *file2*.  
  
 Há casos importantes quando esse aviso pode ser emitido para C\+\+.  Se você declara os mesmos tipos com o mesmo nome em dois arquivos diferentes, se essas declarações contêm funções virtuais, e se as instruções não são as mesmas, o compilador pode emitir C4744 de aviso para as tabelas de funções virtuais.  O aviso ocorre porque há dois diferentes fez dimensionar tabelas de funções virtuais para o mesmo tipo, e o vinculador deve escolher um deless para inserir no executável.  É possível que isso poderá resultar em seu programa que chama a função virtual errada.  
  
 Para resolver esse aviso, para usar a mesma definição de tipo ou para usar nomes diferentes para os tipos ou variáveis.  
  
## Exemplo  
 Este exemplo contém uma definição do tipo.  
  
```  
// C4743a.cpp  
// compile with: /c  
class C {  
public:  
    virtual void f1(void);  
    virtual void f2(void);  
    virtual void f3(void);  
};  
  
void C::f1(void) {}  
void C::f2(void) {}  
void C::f3(void) {}  
C q;  
```  
  
## Exemplo  
 O exemplo a seguir produz C4743.  
  
```  
// C4743b.cpp  
// compile with: C4743a.cpp /W1 /GL /O2  
// C4743 expected  
class C {  
public:  
    virtual void f1(void);  
    virtual void f2(void);  
    virtual void f3(void);  
    virtual void f4(void);  
    virtual void f5(void);  
};  
  
void C::f4(void) {}  
void C::f5(void) {}  
C x;  
  
int main() {}   
```