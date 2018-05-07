---
title: Compilador (nível 1) de aviso C4743 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4743
dev_langs:
- C++
helpviewer_keywords:
- C4743
ms.assetid: 2ee76ea3-77f3-4c2f-9a57-0751823c89fd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 84b4d5f3aa465257d7efcf9f95584612214165b6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4743"></a>Compilador C4743 de aviso (nível 1)
'*tipo*'tem um tamanho diferente '*file1*'e'*file2*': *número* e *número* bytes  
  
 Uma variável externa referenciado ou definidos em dois arquivos tem diferentes tipos nesses arquivos, e o compilador determinou que o tamanho da variável no *file1* difere do tamanho da variável no *file2*.  
  
 Há caso importante quando esse aviso pode ser emitido para C++. Se você declarar os mesmos tipos com o mesmo nome em dois arquivos diferentes, se essas declarações contêm funções virtuais, e se as declarações não forem iguais, o compilador pode emitir aviso C4744 para as tabelas de função virtual. O aviso ocorre porque há duas tabelas de função virtual de tamanho diferente para o mesmo tipo e o vinculador deve escolher um para incorporar o executável.  É possível que isso pode resultar em seu programa chamando a função virtual incorreta.  
  
 Para resolver este aviso, use a mesma definição de tipo ou use nomes diferentes para tipos ou variáveis.  
  
## <a name="example"></a>Exemplo  
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
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4743.  
  
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