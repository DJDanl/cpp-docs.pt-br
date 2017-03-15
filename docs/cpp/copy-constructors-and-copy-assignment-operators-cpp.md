---
title: "Operadores de construtores de c&#243;pia e de atribui&#231;&#227;o de c&#243;pia (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador =, copiando objetos"
  - "atribuindo valores a objetos de cópia"
  - "operadores de atribuição, para cópia de objetos"
  - "instruções de atribuição, copiando objetos"
  - "copiando objetos"
  - "inicializando objetos, por cópia de objetos"
  - "objetos [C++], copiando"
ms.assetid: a94fe1f9-0289-4fb9-8633-77c654002c0d
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores de construtores de c&#243;pia e de atribui&#231;&#227;o de c&#243;pia (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Começando no C\+\+ 11, dois tipos de atribuição têm suporte no idioma: *Copiar atribuição* e *Mover atribuição*.  Neste artigo "atribuição" significa a atribuição de cópia, a menos que explicitamente indicado em contrário.  Para obter informações sobre atribuição de movimentação, consulte [Mover construtores e operadores de atribuição Move \(C\+\+\)](http://msdn.microsoft.com/pt-br/1442de5f-37a5-42a1-83a6-ec9cfe0414db).  
>   
>  Tanto a operação de atribuição como a operação de inicialização fazem com que os objetos sejam copiados.  
  
-   **Atribuição**: quando o valor do objeto é atribuído a outro objeto, o primeiro objeto é copiado para o segundo objeto.  Portanto,  
  
    ```cpp  
    Point a, b;  
    ...  
    a = b;  
    ```  
  
     faz com que o valor de `b` seja copiado para `a`.  
  
-   **Inicialização**: a inicialização ocorre quando um novo objeto é declarado, quando os argumentos são passados para funções por valor, ou quando os valores são retornados das funções por valor.  
  
 Você pode definir a semântica de “cópia” para objetos do tipo classe.  Por exemplo, pense neste código:  
  
```cpp  
TextFile a, b;  
a.Open( "FILE1.DAT" );  
b.Open( "FILE2.DAT" );  
b = a;  
```  
  
 O código anterior poderia significar “copiar o conteúdo de FILE1.DAT para FILE2.DAT” ou “ignore FILE2.DAT e faça de `b` um segundo manipulador para FILE1.DAT”. Você deve anexar a semântica de cópia apropriada a cada classe, da seguinte maneira.  
  
-   Usando o operador de atribuição `operator=` junto com uma referência à tipo de classe como o tipo de retorno e o parâmetro passado pela referência `const` – por exemplo, `ClassName& operator=(const ClassName& x);`.  
  
-   Usando o construtor de cópia.  Para obter mais informações sobre o construtor de cópia, consulte [Regras para declarar construtores](../misc/rules-for-declaring-constructors.md).  
  
 Se você não declarar um construtor de cópia, o compilador gera um construtor de cópia de membros para você.  Se você não declarar um operador de atribuição de cópia, o compilador gera um operador de atribuição de cópia de membros para você. A declaração de um construtor de cópia não suprime o operador de atribuição de cópia gerado pelo compilador, e vice\-versa.  Se você implementar um deles, recomendamos que você também implemente o outro para que o significado do código seja claro.  
  
 Atribuição por membros é abordada em mais detalhes em [\(NOTINBUILD\) Memberwise Assignment and Initialization](http://msdn.microsoft.com/pt-br/94048213-8b49-4416-8069-b1b7a6f271f9).  
  
 O construtor de cópia usa um argumento do tipo *nome da classe***&**, onde *nome da classe* é o nome da classe para a qual o construtor é definido.  Por exemplo:  
  
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
>  Verifique o tipo de argumento do construtor de cópia *nome de classe const***&** sempre que possível.  Isso evita que o construtor de cópia altere acidentalmente o objeto que está copiando.  Ele também permite a cópia dos objetos **const**.  
  
## Construtores de cópia gerado pelo compilador  
 Construtores de cópia gerados pelo compilador, como construtores de cópia definidos pelo usuário, têm um único argumento do tipo "referência a *class\-name*." Uma exceção é quando todas as classes base e membro tem construtores de cópia declarados como usuários de um único argumento do tipo **const** *nome da classe***&**.  Nesse caso, o argumento do construtor de cópia gerado pelo compilador também é **const**.  
  
 Quando o tipo de argumento para o construtor de cópia não é **const**, a inicialização por meio da cópia de um objeto **const** gera um erro.  O inverso não é verdadeiro: se o argumento é **const**, você pode inicializar copiando um objeto que não seja **const**.  
  
 Operadores de atribuição gerado pelo compilador seguem o mesmo padrão em relação ao **Const.** Eles usam um único argumento do tipo *nome da classe***&** a menos que os operadores de atribuição em todas as classes base e membros usem argumentos do tipo **const** *nome de classe &.* Nesse caso, o operador de atribuição gerado da classe usa um argumento **const**.  
  
> [!NOTE]
>  Quando classes básicas virtuais são inicializadas por construtores de cópia, geradas pelo compilador ou definidas pelo usuário, elas são inicializadas somente uma vez: no ponto em que são construídas.  
  
 As implicações são semelhantes às do construtor de cópia.  Quando o tipo de argumento não é **const**, a atribuição de um objeto **const** gera um erro.  O inverso não é verdadeiro: se um valor **const** for atribuído a um valor que não seja **const**, a atribuição será bem\-sucedida.  
  
 Para obter mais informações sobre operadores de atribuição sobrecarregados, consulte [Atribuição](../cpp/assignment.md).  
  
## Consulte também  
 [Funções de membro especiais](../misc/special-member-functions-cpp.md)