---
title: Construtores de cópia e operadores de atribuição de cópia (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- = operator [C++], copying objects
- assignment statements [C++], copying objects
- assignment operators [C++], for copying objects
- objects [C++], copying
- initializing objects, by copying objects
- copying objects
- assigning values to copy objects
ms.assetid: a94fe1f9-0289-4fb9-8633-77c654002c0d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 24f9e4e5b3d157f23c18d46f2857b29e6960e82e
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405750"
---
# <a name="copy-constructors-and-copy-assignment-operators-c"></a>Operadores de construtores de cópia e de atribuição de cópia (C++)
> [!NOTE]
>  A partir do c++11, dois tipos de atribuição têm suporte no idioma: *copiar atribuição* e *atribuição de movimentação*. Neste artigo "atribuição" significa a atribuição de cópia, a menos que explicitamente indicado em contrário. Para obter informações sobre atribuição de movimentação, consulte [construtores Move e operadores de atribuição Move (C++)](http://msdn.microsoft.com/1442de5f-37a5-42a1-83a6-ec9cfe0414db).  
>   
>  Tanto a operação de atribuição como a operação de inicialização fazem com que os objetos sejam copiados.  
  
-   **Atribuição**: quando o valor do objeto é atribuído a outro objeto, o primeiro objeto é copiado para o segundo objeto. Portanto,  
  
    ```cpp  
    Point a, b;  
    ...  
    a = b;  
    ```  
  
     faz com que o valor de `b` seja copiado para `a`.  
  
-   **Inicialização**: a inicialização ocorre quando um novo objeto for declarado, quando os argumentos são passados para funções por valor, ou quando valores são retornados de funções por valor.  
  
 Você pode definir a semântica de “cópia” para objetos do tipo classe. Por exemplo, pense neste código:  
  
```cpp  
TextFile a, b;  
a.Open( "FILE1.DAT" );  
b.Open( "FILE2.DAT" );  
b = a;  
```  
  
 O código anterior poderia significar “copiar o conteúdo de FILE1.DAT para FILE2.DAT” ou “ignore FILE2.DAT e faça de `b` um segundo manipulador para FILE1.DAT”. Você deve anexar a semântica de cópia apropriada a cada classe, da seguinte maneira.  
  
-   Usando o operador de atribuição **operador =** junto com uma referência ao tipo de classe como o tipo de retorno e o parâmetro que é passado por **const** referência — por exemplo `ClassName& operator=(const ClassName& x);`.  
  
-   Usando o construtor de cópia.   
  
 Se você não declarar um construtor de cópia, o compilador gera um construtor de cópia por membros para você.  Se você não declarar um operador de atribuição de cópia, o compilador gera um operador de atribuição de cópia por membros para você. A declaração de um construtor de cópia não suprime o operador de atribuição de cópia gerado pelo compilador, e vice-versa. Se você implementar um deles, recomendamos que você também implemente o outro para que o significado do código seja claro.  
   
 O construtor de cópia usa um argumento do tipo * classe-nome ***&**, onde *nome da classe* é o nome da classe para o qual o construtor é definido. Por exemplo:  
  
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
>  Torne o tipo de argumento do construtor de cópia *classe const-nome * * * &** sempre que possível. Isso evita que o construtor de cópia altere acidentalmente o objeto que está copiando. Ele também permite a cópia dos **const** objetos.  
  
## <a name="compiler-generated-copy-constructors"></a>Construtores de cópia gerado pelo compilador  
 Construtores de cópia gerado pelo compilador, como construtores de cópia definido pelo usuário, tem um único argumento do tipo "referência a *nome da classe*." Uma exceção é quando todas as classes base e membro tem construtores de cópia declarados como usuários de um único argumento do tipo **const** * classe-nome ***&**. Nesse caso, o argumento do construtor de cópia gerado pelo compilador também estiver **const**.  
  
 Quando o tipo de argumento para o construtor de cópia não é **const**, a inicialização copiando um **const** objeto gera um erro. O inverso não é verdadeiro: se o argumento for **const**, você pode inicializar copiando um objeto que não seja **const**.  
  
 Operadores de atribuição gerado pelo compilador seguem o mesmo padrão em relação a **const.** Eles usam um único argumento do tipo *classe-nome * * * &**, a menos que os operadores de atribuição em todas as classes base e membro usam argumentos de tipo **const** *nome de classe &.* Nesse caso, a classe gerada pelo leva de operador de atribuição uma **const** argumento.  
  
> [!NOTE]
>  Quando classes básicas virtuais são inicializadas por construtores de cópia, geradas pelo compilador ou definidas pelo usuário, elas são inicializadas somente uma vez: no ponto em que são construídas.  
  
 As implicações são semelhantes às do construtor de cópia. Quando o tipo de argumento não é **const**, a atribuição de uma **const** objeto gera um erro. O inverso não é verdadeiro: se um **const** valor é atribuído a um valor que não seja **const**, a atribuição será bem-sucedida.  
  
 Para obter mais informações sobre operadores de atribuição sobrecarregados, consulte [atribuição](../cpp/assignment.md).  