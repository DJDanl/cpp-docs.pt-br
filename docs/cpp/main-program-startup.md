---
title: 'main: inicialização do programa'
ms.date: 11/04/2016
f1_keywords:
- vc.main.startup
- _tmain
helpviewer_keywords:
- program startup [C++]
- entry points, program
- wmain function
- _tmain function
- startup code, main function
- main function, program startup
ms.assetid: f9581cd6-93f7-4bcd-99ec-d07c3c107dd4
ms.openlocfilehash: 29e1b77c2e36c66e4e6fc4ec30a73af4d57654a0
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857431"
---
# <a name="main-program-startup"></a>main: inicialização do programa

Uma função especial chamada **Main** é o ponto de partida de execução para todos os C++ programas C e. Se você estiver escrevendo código que adere ao modelo de programação Unicode, poderá usar `wmain`, que é a versão de caractere largo do **principal**.

A função **Main** não é predefinida pelo compilador. Ela deve ser fornecida no texto do programa.

A sintaxe de declaração para **Main** é

```cpp
int main();
```

ou, opcionalmente,

```cpp
int main(int argc, char *argv[], char *envp[]);
```

**Seção específica da Microsoft**

A sintaxe de declaração para `wmain` é a seguinte:

```cpp
int wmain( );
```

ou, opcionalmente,

```cpp
int wmain(int argc, wchar_t *argv[], wchar_t *envp[]);
```

Você também pode usar `_tmain`, que é definido em TCHAR. h. `_tmain` é resolvido para **principal** , a menos que _UNICODE seja definido. Nesse caso, `_tmain` resolve a `wmain`.

Como alternativa, as funções **Main** e `wmain` podem ser declaradas como retornando **void** (nenhum valor de retorno). Se você declarar **Main** ou `wmain` como retornando **void**, não poderá retornar um código de saída para o processo pai ou o sistema operacional usando uma instrução [Return](../cpp/return-statement-in-program-termination-cpp.md) . Para retornar um código de saída quando **Main** ou `wmain` for declarado como **void**, você deverá usar a função [Exit](../cpp/exit-function.md) .

**Fim da seção específica da Microsoft**

Os tipos para `argc` e `argv` são definidos pela linguagem. Os nomes `argc`, `argv` e `envp` são tradicionais, mas não são necessários pelo compilador. Para obter mais informações e um exemplo, consulte [definições de argumento](../cpp/argument-definitions.md).

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Usando wmain em vez main](../cpp/using-wmain-instead-of-main.md)<br/>
[Restrições da função main](../cpp/main-function-restrictions.md)<br/>
[Analisando argumentos de linha de comando C](../cpp/parsing-cpp-command-line-arguments.md)
