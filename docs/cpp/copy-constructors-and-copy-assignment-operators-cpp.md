---
title: "Construtores de cópia e operadores de atribuição de cópia (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- = operator [C++], copying objects
- assignment statements [C++], copying objects
- assignment operators [C++], for copying objects
- objects [C++], copying
- initializing objects, by copying objects
- copying objects
- assigning values to copy objects
ms.assetid: a94fe1f9-0289-4fb9-8633-77c654002c0d
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1f2ebf51f28912c3cb798acc1ff4aa377c1bebb5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="copy-constructors-and-copy-assignment-operators-c"></a>Operadores de construtores de cópia e de atribuição de cópia (C++)
> [!NOTE]
>  A partir do C++ 11, dois tipos de atribuição têm suporte no idioma: *copiar atribuição* e *mover atribuição*. Neste artigo "atribuição" significa a atribuição de cópia, a menos que explicitamente indicado em contrário. Para obter informações sobre atribuição de movimentação, consulte [construtores mover e mova operadores de atribuição (C++)](http://msdn.microsoft.com/en-us/1442de5f-37a5-42a1-83a6-ec9cfe0414db).  
>   
>  Tanto a operação de atribuição como a operação de inicialização fazem com que os objetos sejam copiados.  
  
-   **Atribuição**: quando valor de um objeto é atribuído a outro objeto, o primeiro objeto é copiado para o segundo objeto. Portanto,  
  
    ```cpp  
    Point a, b;  
    ...  
    a = b;  
    ```  
  
     faz com que o valor de `b` seja copiado para `a`.  
  
-   **Inicialização**: a inicialização ocorre quando um novo objeto for declarado, argumentos são passados para funções por valor, ou quando valores são retornados pelas funções de por valor.  
  
 Você pode definir a semântica de “cópia” para objetos do tipo classe. Por exemplo, pense neste código:  
  
```cpp  
TextFile a, b;  
a.Open( "FILE1.DAT" );  
b.Open( "FILE2.DAT" );  
b = a;  
```  
  
 O código anterior poderia significar “copiar o conteúdo de FILE1.DAT para FILE2.DAT” ou “ignore FILE2.DAT e faça de `b` um segundo manipulador para FILE1.DAT”. Você deve anexar a semântica de cópia apropriada a cada classe, da seguinte maneira.  
  
-   Usando o operador de atribuição `operator=` junto com uma referência à tipo de classe como o tipo de retorno e o parâmetro passado pela referência `const` – por exemplo, `ClassName& operator=(const ClassName& x);`.  
  
-   Usando o construtor de cópia.   
  
 Se você não declarar um construtor de cópia, o compilador gera um construtor de cópia member-wise para você.  Se você não declarar um operador de atribuição de cópia, o compilador gerará um operador de atribuição de cópia member-wise para você. A declaração de um construtor de cópia não suprime o operador de atribuição de cópia gerado pelo compilador, e vice-versa. Se você implementar um deles, recomendamos que você também implemente o outro para que o significado do código seja claro.  
   
 O construtor de cópia recebe um argumento de tipo *nome de classe***&**, onde *nome de classe* é o nome da classe para a qual o construtor é definido. Por exemplo:  
  
```cpp  
// spec1_copying_class_objects.cpp  
class Window  
{  
public:  
    Window( const Window& ); // Declare copy constructor.  
    // ...  
};  
  
int main()  
{  
}  
```  
  
> [!NOTE]
>  Verifique o tipo de argumento do construtor de cópia *nome de classe const*  **&**  sempre que possível. Isso evita que o construtor de cópia altere acidentalmente o objeto que está copiando. Ele também permite que a cópia de **const** objetos.  
  
## <a name="compiler-generated-copy-constructors"></a>Construtores de cópia gerado pelo compilador  
 Construtores de cópia gerada pelo compilador, como construtores de cópia definido pelo usuário, ter um único argumento do tipo "referência a *nome da classe*." Uma exceção é quando todas as classes base e membro tem construtores de cópia declarados como colocar um único argumento de tipo **const** *nome de classe***&**. Nesse caso, o argumento do construtor de cópia gerada pelo compilador também é **const**.  
  
 Quando o tipo de argumento para o construtor de cópia não é **const**, inicialização copiando um **const** objeto gera um erro. O oposto não é possível: se o argumento for **const**, você pode inicializar copiando um objeto que não seja **const**.  
  
 Operadores de atribuição gerado pelo compilador seguem o mesmo padrão em relação ao **const.** Eles entram em um único argumento de tipo *nome de classe*  **&**  , a menos que os operadores de atribuição em todas as classes base e membro usam argumentos de tipo **const** *nome de classe &.* Nesse caso, a classe gerada do leva de operador de atribuição um **const** argumento.  
  
> [!NOTE]
>  Quando classes básicas virtuais são inicializadas por construtores de cópia, geradas pelo compilador ou definidas pelo usuário, elas são inicializadas somente uma vez: no ponto em que são construídas.  
  
 As implicações são semelhantes às do construtor de cópia. Quando o tipo de argumento não é **const**, atribuição de um **const** objeto gera um erro. O oposto não é possível: se um **const** valor é atribuído a um valor que não seja **const**, a atribuição será bem-sucedida.  
  
 Para obter mais informações sobre operadores de atribuição sobrecarregado, consulte [atribuição](../cpp/assignment.md).  
  
