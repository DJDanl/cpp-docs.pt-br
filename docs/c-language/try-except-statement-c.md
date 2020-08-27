---
title: Instrução try-except (C)
description: O Microsoft C/C++ implementa o tratamento de exceção estruturado (SEH) usando uma extensão de linguagem de instrução try-Except.
ms.date: 08/24/2020
helpviewer_keywords:
- try-except keyword [C]
- structured exception handling, try-except
- try-catch keyword [C]
- __try keyword [C]
- __except keyword [C]
- __except keyword [C], in try-except
- try-catch keyword [C], try-except keyword [C]
ms.assetid: f76db9d1-fc78-417f-b71f-18e545fc01c3
ms.openlocfilehash: e327150431fef3384f2b98940939444b2e6d96ea
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898718"
---
# <a name="try-except-statement-c"></a>Instrução try-except (C)

**Específico da Microsoft**

A `try-except` instrução é uma extensão da Microsoft para a linguagem C que permite aos aplicativos obter o controle de um programa quando os eventos que normalmente terminam a execução ocorrem. Esses eventos são denominados exceções, e o mecanismo que lida com exceções é chamado de manipulação de exceção estruturada.

As exceções podem ser baseadas em hardware ou software. Mesmo quando os aplicativos não conseguem se recuperar completamente de exceções de hardware ou software, a manipulação de exceção estruturada torna possível registrar e exibir informações de erro. É útil interceptar o estado interno do aplicativo para ajudar a diagnosticar o problema. Em particular, é útil para problemas intermitentes que não são fáceis de reproduzir.

## <a name="syntax"></a>Sintaxe

> *`try-except-statement`*:\
> &emsp;**`__try`** *`compound-statement`* **`__except (`**  *`expression`*  **`)`** *`compound-statement`*

A instrução composta após a **`__try`** cláusula é a *seção protegida*. A instrução composta após a **`__except`** cláusula é o *manipulador de exceção*. O manipulador Especifica um conjunto de ações a serem executadas se uma exceção for gerada durante a execução da seção protegida. A execução procede da seguinte maneira:

1. A seção protegida é executada.

1. Se nenhuma exceção ocorrer durante a execução da seção protegida, a execução continuará na instrução após a **`__except`** cláusula.

1. Se ocorrer uma exceção durante a execução da seção protegida ou, em qualquer rotina, a seção protegida chamar, a **`__except`** expressão será avaliada. O valor retornado determina como a exceção é tratada. Há três valores possíveis:

   - `EXCEPTION_CONTINUE_SEARCH`: A exceção não é reconhecida. Continue pesquisando a pilha para obter um manipulador, primeiro para as instruções de contenção `try-except` , em seguida, para os manipuladores com a próxima precedência mais alta.

   - `EXCEPTION_CONTINUE_EXECUTION`: A exceção é reconhecida, mas ignorada. Continue a execução no ponto onde ocorreu a exceção.

   - `EXCEPTION_EXECUTE_HANDLER` A exceção é reconhecida. Transfira o controle para o manipulador de exceção executando a **`__except`** instrução composta e continue a execução no ponto em que ocorreu a exceção.

Como a **`__except`** expressão é avaliada como uma expressão C, ela é limitada a um único valor, ao operador de expressão condicional ou ao operador de vírgula. Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.

> [!NOTE]
> A manipulação de exceção estruturada funciona com arquivos de código-fonte em C e C++. No entanto, ele não foi projetado especificamente para C++. Para programas Portable C++, a manipulação de exceção do C++ deve ser usada em vez de manipulação de exceção estruturada. Além disso, o mecanismo de tratamento de exceções de C++ é muito mais flexível, pois pode tratar exceções de qualquer tipo. Para obter mais informações, consulte [tratamento de exceção](../cpp/exception-handling-in-visual-cpp.md) na referência da *linguagem C++*.

Cada rotina em um aplicativo pode ter seu próprio manipulador de exceção. A **`__except`** expressão é executada no escopo do **`__try`** corpo. Ele tem acesso a qualquer variável local declarada lá.

A **`__leave`** palavra-chave é válida dentro de um `try-except` bloco de instruções. O efeito de **`__leave`** é saltar para o final do `try-except` bloco. A execução é retomada após o término do manipulador de exceção. Embora uma **`goto`** instrução possa ser usada para atingir o mesmo resultado, uma **`goto`** instrução causa o desenrolamento da pilha. A **`__leave`** instrução é mais eficiente porque não envolve o desenrolamento de pilha.

Sair de uma `try-except` instrução usando a `longjmp` função de tempo de execução é considerado encerramento anormal. Não é legal pular para uma **`__try`** instrução, mas é legal pular de uma. O manipulador de exceção não será chamado se um processo for eliminado no meio da execução de uma `try-except` instrução.

## <a name="example"></a>Exemplo

Aqui está um exemplo de um manipulador de exceção e um manipulador de terminação. Para obter mais informações sobre manipuladores de terminação, consulte [ `try-finally` Statement (C)](../c-language/try-finally-statement-c.md).

```C
.
.
.
puts("hello");
__try {
   puts("in try");
   __try {
      puts("in try");
      RAISE_AN_EXCEPTION();
   } __finally {
      puts("in finally");
   }
} __except( puts("in filter"), EXCEPTION_EXECUTE_HANDLER ) {
   puts("in except");
}
puts("world");
```

Aqui está a saída do exemplo, com comentários adicionados à direita:

```Output
hello
in try              /* fall into try                        */
in try              /* fall into nested try                 */
in filter           /* execute filter; returns 1 so accept  */
in finally          /* unwind nested finally                */
in except           /* transfer control to selected handler */
world               /* flow out of handler                  */
```

**ENCERRAR específico da Microsoft**

## <a name="see-also"></a>Confira também

[`try-except` instrução (C++)](../cpp/try-except-statement.md)
