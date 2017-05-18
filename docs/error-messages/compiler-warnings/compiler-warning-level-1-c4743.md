---
title: "Compilador aviso (nível 1) C4743 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4743
dev_langs:
- C++
helpviewer_keywords:
- C4743
ms.assetid: 2ee76ea3-77f3-4c2f-9a57-0751823c89fd
caps.latest.revision: 11
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c4c1d0872f74aa4dc56497f02ce0338027a8d14f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4743"></a>Compilador C4743 de aviso (nível 1)
'*tipo*'tem tamanho diferente '*file1*'e'*file2*': *número* e *número* bytes  
  
 Uma variável externa referenciado ou definido em dois arquivos tem diferentes tipos nesses arquivos, e o compilador determinou que o tamanho da variável no *file1* difere do tamanho da variável no *file2*.  
  
 Há importante caso em que esse aviso pode ser emitido para C++. Se você declarar os mesmos tipos com o mesmo nome em dois arquivos diferentes, se essas declarações conter funções virtuais, e se as declarações não são iguais, o compilador pode emitir aviso C4744 para as tabelas de função virtual. O aviso ocorre porque há duas tabelas de função virtual de tamanho diferente para o mesmo tipo e vinculador deve escolher uma para incorporar o executável.  É possível que isso pode resultar em seu programa chamando a função virtual errada.  
  
 Para resolver esse aviso, use a mesma definição de tipo ou usar nomes diferentes para os tipos ou variáveis.  
  
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
