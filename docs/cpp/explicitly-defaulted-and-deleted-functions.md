---
title: Assume o padrão e excluir funções explicitamente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 5a588478-fda2-4b3f-a279-db3967f5e07e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1f8558a2fac4995d89d0745917e6e1be5ad99d56
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="explicitly-defaulted-and-deleted-functions"></a>Funções explicitamente usadas como padrão e excluídas
No C++11, as funções usadas como padrão e excluídas proporcionam controle explícito sobre se as funções de membro especial serão geradas automaticamente. As funções excluídas também oferecem uma linguagem simples para impedir que promoções de tipos problemáticos ocorram em argumentos para funções de todos os tipos — funções de membro especial, funções de membro normal e funções de não membro — que, de outra forma, causariam uma chamada de função indesejada.  
  
## <a name="benefits-of-explicitly-defaulted-and-deleted-functions"></a>Benefícios das funções explicitamente usadas como padrão e excluídas  
 No C++, o compilador gera automaticamente o construtor padrão, o construtor de cópia, o operador de atribuição de cópia e o destruidor para um tipo se ele não declarar os próprios. Essas funções são conhecidas como o *funções de membro especiais*, e eles são o que fazer tipos simples definidos pelo usuário em C++ se comportam de forma que estruturas em C. Ou seja, você pode criar, copiar e destruí-las sem qualquer esforço adicional de codificação. O C++11 traz a semântica de movimentação para a linguagem e adiciona o construtor de movimentação e o operador de atribuição de movimentação à lista de funções de membro especial que o compilador pode gerar automaticamente.  
  
 Isso é conveniente para tipos simples, mas os tipos complexos geralmente definem, por conta própria, uma ou mais das funções de membro especial, e isso pode impedir que outras funções de membro especial sejam geradas automaticamente. Na prática:  
  
-   Se qualquer construtor for declarado explicitamente, nenhum construtor padrão será gerado automaticamente.  
  
-   Se um destruidor virtual for declarado explicitamente, nenhum destruidor padrão será gerado automaticamente.  
  
-   Se um construtor de movimentação ou um operador de atribuição de movimentação for declarado explicitamente:  
  
    -   Nenhum construtor de cópia será gerado automaticamente.  
  
    -   Nenhum operador de atribuição de cópia será gerado automaticamente.  
  
-   Se um construtor de cópia, um operador de atribuição de cópia, um construtor de movimentação, um operador de atribuição de movimentação ou um destruidor for declarado explicitamente:  
  
    -   Nenhum construtor de movimentação será gerado automaticamente.  
  
    -   Nenhum operador de atribuição de movimentação será gerado automaticamente.  
  
> [!NOTE]
>  Além disso, o padrão C++11 especifica as seguintes regras adicionais:  
>   
>  -   Se um construtor de cópia ou um destruidor for declarado explicitamente, a geração automática do operador de atribuição de cópia será preterida.  
> -   Se um operador de atribuição de cópia ou um destruidor for declarado explicitamente, a geração automática do construtor de cópia será preterida.  
>   
>  Nos dois casos, o Visual Studio continua a gerar as funções necessárias de forma automática e implícita, e não emite um aviso.  
  
 As consequências dessas regras também podem vazar para as hierarquias de objetos. Por exemplo, se por algum motivo uma classe base não tiver um construtor padrão que possa ser chamado de uma classe derivada - ou seja, um construtor `public` ou `protected` que não use parâmetros -, uma classe derivada dela não poderá automaticamente gerar seu próprio construtor padrão.  
  
 Essas regras podem complicar a implementação do que deveria ser tipos simples definidos pelo usuário e expressões comuns de C++; por exemplo, podem tornar um tipo definido pelo usuário não copiável declarando o construtor de cópia e o operador de atribuição de cópia de forma privada, sem defini-los.  
  
```  
struct noncopyable  
{  
  noncopyable() {};  
  
private:  
  noncopyable(const noncopyable&);  
  noncopyable& operator=(const noncopyable&);  
};  
```  
  
 Antes do C++11, esse trecho de código era a forma idiomática de tipos não copiáveis. No entanto, existem vários problemas:  
  
-   O construtor de cópia precisa ser declarado de forma privada para ocultá-lo. Porém, como ele é declarado, a geração automática do construtor padrão é impedida. Você terá que definir o construtor padrão explicitamente se quiser um, mesmo que ele não faça nada.  
  
-   Mesmo se o construtor padrão definido explicitamente não fizer nada, será considerado não trivial pelo compilador. É menos eficiente do que um construtor padrão gerado automaticamente e impede que `noncopyable` seja um tipo POD verdadeiro.  
  
-   Mesmo que o construtor de cópia e o operador de atribuição de cópia estejam ocultos do código externo, as funções de membro e os amigos de `noncopyable` ainda poderão vê-los e chamá-los. Se eles forem declarados. mas não definidos, chamá-los causará um erro de vinculador.  
  
-   Embora essa seja uma expressão aceita de modo geral, a intenção não fica clara, a menos que você compreenda todas as regras para a geração automática das funções de membro especial.  
  
 No C++11, a expressão não copiável pode ser implementada de maneira mais simples.  
  
```  
struct noncopyable  
{  
  noncopyable() =default;  
  noncopyable(const noncopyable&) =delete;  
  noncopyable& operator=(const noncopyable&) =delete;  
};  
```  
  
 Observe como os problemas com a expressão pré-C++11 são resolvidos:  
  
-   A geração do construtor padrão ainda é impedida por meio da declaração do construtor de cópia, mas você pode trazê-lo de volta ao usá-lo como padrão explicitamente.  
  
-   As funções de membro especial explicitamente usadas como padrão ainda são consideradas triviais; portanto, não há penalidade de desempenho, e `noncopyable` não é impedido de ser um tipo POD verdadeiro.  
  
-   O construtor de cópia e o operador de atribuição de cópia são públicos, mas são excluídos. É um erro em tempo de compilação definir ou chamar uma função excluída.  
  
-   A intenção é clara para qualquer pessoa que compreenda `=default` e `=delete`. Você não precisa compreender as regras para a geração automática de funções de membro especial.  
  
 Existem expressões semelhantes para criar tipos definidos pelo usuário que não podem ser movidos, que só podem ser alocados dinamicamente ou que não podem ser alocados dinamicamente. Cada uma dessas expressões tem implementações pré-C++11 que sofrem problemas semelhantes, e que são resolvidas de forma semelhante no C++11 pela implementação delas em termos de funções de membro especial usadas como padrão e excluídas.  
  
## <a name="explicitly-defaulted-functions"></a>Funções explicitamente usadas como padrão  
 Você pode usar como padrão qualquer uma das funções de membro especial: para declarar explicitamente que a função de membro especial usa a implementação padrão, para definir a função de membro especial com um qualificador de acesso não público ou para declarar novamente uma função de membro especial cuja geração automática foi impedida por outras circunstâncias.  
  
 Para usar uma função de membro especial como padrão, você a declara, como neste exemplo:  
  
```  
struct widget  
{  
  widget()=default;  
  
  inline widget& operator=(const widget&);  
};  
  
inline widget& widget::operator=(const widget&) =default;  
```  
  
 Observe que é possível usar uma função de membro especial como padrão fora do corpo de uma classe, desde que ela possa ser usada em linha.  
  
 Por causa dos benefícios de desempenho das funções de membro especial triviais, recomendamos que você prefira as funções de membro especial geradas automaticamente aos corpos de função vazios quando quiser o comportamento padrão. Você pode fazer isso usando a função de membro especial como padrão explicitamente, ou não a declarando (e também não declarando outras funções de membro especial que a impediriam de ser gerada automaticamente).  
  
## <a name="deleted-functions"></a>Funções excluídas  
 Você pode excluir funções de membro especial, assim como funções de membro normal e funções de não membro, para impedir que elas sejam definidas ou chamadas. A exclusão de funções de membro especial oferece uma forma mais limpa de impedir que o compilador gere funções de membro especial indesejadas. A função deve ser excluída ao ser declarada; não pode ser excluída posteriormente, da maneira como uma função pode ser declarada e depois usada como padrão mais tarde.  
  
```  
struct widget  
{  
  // deleted operator new prevents widget from being dynamically allocated.  
  void* operator new(std::size_t) = delete;  
};  
```  
  
 A exclusão de uma função de membro normal ou de funções de não membro impede que promoções de tipos problemáticos façam com que uma função não intencional seja chamada. Isso funciona porque as funções excluídas ainda participam da resolução de sobrecarga e fornecem uma correspondência melhor do que a função que poderia ser chamada após a promoção dos tipos. A chamada de função é resolvida para a função mais específica, mas excluída, e causa um erro do compilador.  
  
```  
// deleted overload prevents call through type promotion of float to double from succeeding.  
void call_with_true_double_only(float) =delete;  
void call_with_true_double_only(double param) { return; }  
```  
  
 No exemplo acima, observe que chamar `call_with_true_double_only` usando um argumento `float` provocaria um erro do compilador, mas isso não aconteceria ao chamar `call_with_true_double_only` usando um argumento `int`; no caso do `int`, o argumento será promovido de `int` para `double` e chamará com êxito a versão `double` da função, mesmo que isso não seja o que se pretendia. Para garantir que qualquer chamada para essa função usando um argumento que não seja double provoque um erro do compilador, você pode declarar uma versão template da função que é excluída.  
  
```  
template < typename T >  
void call_with_true_double_only(T) =delete; //prevent call through type promotion of any T to double from succeeding.  
  
void call_with_true_double_only(double param) { return; } // also define for const double, double&, etc. as needed.  
  
```