---
title: Aviso do compilador (nível 4) C4512
ms.date: 11/04/2016
f1_keywords:
- C4512
helpviewer_keywords:
- C4512
ms.assetid: afb68995-684a-4be5-a73a-38d7a16dc030
ms.openlocfilehash: c09832a4f27bff51cbb5bd847a3123e62c9ee8d5
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991007"
---
# <a name="compiler-warning-level-4-c4512"></a>Aviso do compilador (nível 4) C4512

"classe": não foi possível gerar um operador de atribuição

O compilador não pode gerar um operador de atribuição para uma determinada classe. Nenhum operador de atribuição foi criado.

O fato de um operador de atribuição para a classe de base não estar acessível pela classe derivada, pode fazer causar esse aviso.

Para evitar esse aviso, especifique um operador de atribuição definido pelo usuário para a classe.

O compilador também gerará uma função de operador de atribuição para uma classe que não define uma. Este operador de atribuição é uma cópia de reconhecimento de membro dos membros de dados de um objeto. Como os itens de dados `const` não podem ser modificados após a inicialização, se a classe tiver um item `const`, o operador de atribuição padrão não funcionará. Outra causa do aviso C4512 é uma declaração de um membro de dados não estático do tipo de referência. Se a intenção é criar um tipo não copiado, você também deve evitar a criação de um construtor de cópia padrão.

Você pode resolver o aviso C4512 para o código de uma destas três maneiras:

- Defina explicitamente um operador de atribuição para a classe.

- Remova **const** ou o operador de referência do item de dados na classe.

- Use a instrução #pragma [Warning](../../preprocessor/warning.md) para suprimir o aviso.

## <a name="example"></a>Exemplo

O seguinte exemplo gera C4512.

```cpp
// C4512.cpp
// compile with: /EHsc /W4
// processor: x86

class Base {
private:
   const int a;

public:
   Base(int val = 0) : a(val) {}
   int get_a() { return a; }
};   // C4512 warning

class Base2 {
private:
   const int a;

public:
   Base2(int val = 0) : a(val) {}
   Base2 & operator=( const Base2 & ) { return *this; }
   int get_a() { return a; }
};

// Type designer intends this to be non-copyable because it has a
// reference member
class Base3
{
private:
   char& cr;

public:
   Base3(char& r) : cr(r) {}
   // Uncomment the following line to explicitly disable copying:
   // Base3(const Base3&) = delete;
};   // C4512 warning

int main() {
   Base first;
   Base second;

   // OK
   Base2 first2;
   Base2 second2;

   char c = 'x';
   Base3 first3(c);
   Base3 second3 = first3; // C2280 if no default copy ctor
}
```
