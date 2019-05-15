---
title: Compilador aviso (nível 1) C4743
ms.date: 05/13/2019
f1_keywords:
- C4743
helpviewer_keywords:
- C4743
ms.assetid: 2ee76ea3-77f3-4c2f-9a57-0751823c89fd
ms.openlocfilehash: 53ead0e34b55eca44399cee09f1947a12e1eadd3
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611835"
---
# <a name="compiler-warning-level-1-c4743"></a>Compilador aviso (nível 1) C4743

'*tipo*'tem tamanho diferente '*file1*'e'*arquivo2*': *número* e *número* bytes

Uma variável externa referenciadas ou definidas em dois arquivos tem diferentes tipos nesses arquivos, e o compilador determinou que o tamanho da variável no *file1* difere do tamanho da variável no *arquivo2*.

## <a name="remarks"></a>Comentários

Há um caso importante quando esse aviso pode ser emitido para o C++. Se você declarar os mesmos tipos com o mesmo nome em dois arquivos diferentes, se essas declarações contiverem funções virtuais, e se as declarações não forem iguais, o compilador pode emitir aviso C4744 para as tabelas de função virtual. O aviso ocorre porque há duas tabelas de tamanhos diferentes de função virtual para o mesmo tipo e o vinculador deve escolher uma para incorporar o executável.  É possível que ele pode resultar em seu programa chamando a função virtual errada.

Para resolver este aviso, use a mesma definição de tipo ou usar nomes diferentes para tipos ou variáveis.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4743. Para compilá-lo, coloque os dois arquivos na mesma pasta, em seguida, execute  

```cmd
cl /EHsc /W1 /GL /O2 C4743a.cpp C4743b.cpp
```

```cpp
// C4743a.cpp
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

```cpp
// C4743b.cpp
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
