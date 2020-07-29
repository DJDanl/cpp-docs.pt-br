---
title: Instrução try-except (C)
ms.date: 11/04/2016
helpviewer_keywords:
- try-except keyword [C]
- structured exception handling, try-except
- try-catch keyword [C]
- __try keyword [C]
- __except keyword [C]
- __except keyword [C], in try-except
- try-catch keyword [C], try-except keyword [C]
ms.assetid: f76db9d1-fc78-417f-b71f-18e545fc01c3
ms.openlocfilehash: 77b6bea8c7793522f5e1fa47e09a9b4a7e5c0f10
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218774"
---
# <a name="try-except-statement-c"></a>Instrução try-except (C)

**Específico da Microsoft**

A instrução **try-except** é uma extensão da Microsoft para a linguagem C que permite que os aplicativos assumam o controle de um programa quando ocorrerem eventos que normalmente interrompem a execução. Esses eventos são denominados exceções, e o mecanismo que lida com exceções é chamado de manipulação de exceção estruturada.

As exceções podem ser baseadas em hardware ou software. Mesmo quando os aplicativos não podem se recuperar completamente das exceções de hardware ou software, a manipulação de exceção estruturada permite exibir informações de erro e interceptar o estado interno do aplicativo para ajudar a diagnosticar o problema. Isso é especialmente útil para os problemas intermitentes que não podem ser reproduzidos facilmente.

## <a name="syntax"></a>Sintaxe

*try-except-statement*: **__try**  *compound-statement*

*instrução composta de* **__except (***expressão***)**      

A instrução composta após a cláusula `__try` é a seção protegida. A instrução composta após a **`__except`** cláusula é o manipulador de exceção. O manipulador especifica um conjunto de ações a ser executado se uma exceção for gerada durante a execução da seção protegida. A execução procede da seguinte maneira:

1. A seção protegida é executada.

1. Se nenhuma exceção ocorrer durante a execução da seção protegida, a execução continuará na instrução após a **`__except`** cláusula.

1. Se ocorrer uma exceção durante a execução da seção protegida ou em qualquer rotina chamada de seção protegida, a **`__except`** expressão será avaliada e o valor retornado determinará como a exceção será tratada. Há três valores:

   `EXCEPTION_CONTINUE_SEARCH` A exceção não é reconhecida. Continue pesquisando manipuladores na pilha; primeiro os que contêm as instruções **try-except**, depois os que têm a próxima precedência mais alta.

   `EXCEPTION_CONTINUE_EXECUTION` A exceção é reconhecida, mas ignorada. Continue a execução no ponto onde ocorreu a exceção.

   `EXCEPTION_EXECUTE_HANDLER` A exceção é reconhecida. Transfira o controle para o manipulador de exceção executando a **`__except`** instrução composta e continue a execução no ponto em que ocorreu a exceção.

Como a **`__except`** expressão é avaliada como uma expressão C, ela é limitada a um único valor, ao operador de expressão condicional ou ao operador de vírgula. Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.

> [!NOTE]
> A manipulação de exceção estruturada funciona com arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, o mecanismo de tratamento de exceções de C++ é muito mais flexível, pois pode tratar exceções de qualquer tipo.

> [!NOTE]
> Para programas C++, o tratamento de exceção de C++ deve ser usado em vez de manipulação de exceção estruturada. Para obter mais informações, consulte [Tratamento de exceções](../cpp/exception-handling-in-visual-cpp.md) na *Referência da linguagem C++*.

Cada rotina em um aplicativo pode ter seu próprio manipulador de exceção. A **`__except`** expressão é executada no escopo do `__try` corpo. Isso significa que ela tem acesso a todas as variáveis locais declarados lá.

O ** `__leave** keyword is valid within a **try-except** statement block. The effect of **` __leave** é ir para o final do bloco **try-Except** . A execução é retomada após o término do manipulador de exceção. Embora uma **`goto`** instrução possa ser usada para atingir o mesmo resultado, uma **`goto`** instrução causa o desenrolamento da pilha. A instrução **' __leave** é mais eficiente porque não envolve o desenrolamento de pilha.

Sair de uma instrução **try-except** usando a função de tempo de execução `longjmp` é considerado um término anormal. Não é permitido ir para uma instrução `__try`, mas é permitido sair de uma. O manipulador de exceção não será chamado se um processo for interrompido no meio da execução de uma instrução **try-except**.

## <a name="example"></a>Exemplo

O exemplo a seguir é um manipulador de exceções e um manipulador de término. Consulte [A instrução try-finally](../c-language/try-finally-statement-c.md) para obter mais informações sobre manipuladores de término.

```
.
.
.
puts("hello");
__try{
   puts("in try");
   __try{
      puts("in try");
      RAISE_AN_EXCEPTION();
   }__finally{
      puts("in finally");
   }
}__except( puts("in filter"), EXCEPTION_EXECUTE_HANDLER ){
   puts("in except");
}
puts("world");
```

Este é o resultado do exemplo, com o comentário adicionado à direita:

```
hello
in try              /* fall into try                     */
in try              /* fall into nested try                */
in filter           /* execute filter; returns 1 so accept  */
in finally          /* unwind nested finally                */
in except           /* transfer control to selected handler */
world               /* flow out of handler                  */
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Instrução try-Except](../cpp/try-except-statement.md)
