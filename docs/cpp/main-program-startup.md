---
title: 'principal: Inicialização do programa'
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
ms.openlocfilehash: 358ae8ec88281bab741393b1196ee2a1e615e896
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345045"
---
# <a name="main-program-startup"></a>principal: Inicialização do programa

Uma função especial denominada **principal** é o ponto inicial de execução para todos os programas em C e C++. Se você estiver escrevendo código que obedeça ao modelo de programação Unicode, você pode usar `wmain`, que é a versão de caractere largo de **principal**.

O **principal** função não é predefinida pelo compilador. Ela deve ser fornecida no texto do programa.

A sintaxe de declaração para **principal** é

```cpp
int main();
```

ou, opcionalmente,

```cpp
int main(int argc, char *argv[], char *envp[]);
```

## <a name="microsoft-specific"></a>Específico da Microsoft

A sintaxe de declaração para `wmain` é a seguinte:

```cpp
int wmain( );
```

ou, opcionalmente,

```cpp
int wmain(int argc, wchar_t *argv[], wchar_t *envp[]);
```

Você também pode usar `_tmain`, que é definido em TCHAR. h. `_tmain` Resolve **principal** , a menos que Unicode estiver definido. Nesse caso, `_tmain` resolve a `wmain`.

Como alternativa, o **principal** e `wmain` funções podem ser declaradas como retornando **void** (nenhum valor de retorno). Se você declarar **principal** ou `wmain` como de retorno **void**, você não pode retornar um código de saída para o processo pai ou o sistema operacional usando um [retornar](../cpp/return-statement-in-program-termination-cpp.md) instrução. Para retornar uma código de saída quando **principal** ou `wmain` é declarado como **void**, você deve usar o [sair](../cpp/exit-function.md) função.

**Fim da seção específica da Microsoft**

Os tipos para `argc` e `argv` são definidos pela linguagem. Os nomes `argc`, `argv` e `envp` são tradicionais, mas não são necessários pelo compilador. Para obter mais informações e um exemplo, consulte [definições de argumento](../cpp/argument-definitions.md).

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Usando wmain em vez main](../cpp/using-wmain-instead-of-main.md)<br/>
[Restrições da função main](../cpp/main-function-restrictions.md)<br/>
[Analisando argumentos de linha de comando C](../cpp/parsing-cpp-command-line-arguments.md)
