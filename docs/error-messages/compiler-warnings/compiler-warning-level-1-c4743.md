---
title: Compilador aviso (nível 1) C4743
ms.date: 11/04/2016
f1_keywords:
- C4743
helpviewer_keywords:
- C4743
ms.assetid: 2ee76ea3-77f3-4c2f-9a57-0751823c89fd
ms.openlocfilehash: d17fd65f1108aab6e3ce97ec75c0ffb899c06cda
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50441841"
---
# <a name="compiler-warning-level-1-c4743"></a>Compilador aviso (nível 1) C4743

'*tipo*'tem tamanho diferente '*file1*'e'*arquivo2*': *número* e *número* bytes

Uma variável externa referenciadas ou definidas em dois arquivos tem diferentes tipos nesses arquivos, e o compilador determinou que o tamanho da variável no *file1* difere do tamanho da variável no *arquivo2*.

Há casos importantes quando esse aviso pode ser emitido para C++. Se você declarar os mesmos tipos com o mesmo nome em dois arquivos diferentes, se essas declarações contiverem funções virtuais, e se as declarações não forem iguais, o compilador pode emitir aviso C4744 para as tabelas de função virtual. O aviso ocorre porque há duas tabelas de função virtual de tamanho diferente para o mesmo tipo e o vinculador deve escolher uma para incorporar o executável.  É possível que isso pode resultar em seu programa chamando a função virtual errada.

Para resolver este aviso, use a mesma definição de tipo ou usar nomes diferentes para tipos ou variáveis.

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