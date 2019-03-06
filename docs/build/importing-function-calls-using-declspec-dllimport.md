---
title: Importando chamadas de função usando __declspec(dllimport)
ms.date: 11/04/2016
f1_keywords:
- __declspec
- dllimport
helpviewer_keywords:
- importing function calls [C++]
- dllimport attribute [C++], function call imports
- __declspec(dllimport) keyword [C++]
- function calls [C++], importing
ms.assetid: 6b53c616-0c6d-419a-8e2a-d2fff20510b3
ms.openlocfilehash: 055edf4efc066695abb60a09b84cb1b13302af9c
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57423957"
---
# <a name="importing-function-calls-using-declspecdllimport"></a>Importando chamadas de função usando __declspec(dllimport)

O exemplo de código a seguir mostra como usar **_declspec(dllimport)** importar chamadas de função de uma DLL em um aplicativo. Suponha que `func1` é uma função que reside em uma DLL separada do arquivo .exe que contém o **principal** função.

Sem **__declspec(dllimport)**, considerando este código:

```
int main(void)
{
   func1();
}
```

o compilador gera código parecido com este:

```
call func1
```

e o vinculador converte a chamada em algo parecido com isto:

```
call 0x4000000         ; The address of 'func1'.
```

Se `func1` existe em outra DLL, o vinculador não pode resolver diretamente nesse porque ele não tem nenhuma maneira de saber que o endereço de `func1` é. Em ambientes de 16 bits, o vinculador adiciona esse endereço de código para uma lista no arquivo .exe que aplica o patch o carregador de tempo de execução com o endereço correto. Em ambientes de 32 bits e 64 bits, o vinculador gera uma conversão que ele sabe o endereço. Em um ambiente de 32 bits a conversão é semelhante a:

```
0x40000000:    jmp DWORD PTR __imp_func1
```

Aqui `imp_func1` é o endereço para o `func1` slot na tabela de endereço de importação do arquivo .exe. Assim, todos os endereços são conhecidos para o vinculador. O carregador tem apenas atualizar a tabela de endereços de importação do arquivo .exe no tempo de carregamento para que tudo funcione corretamente.

Portanto, o uso **__declspec(dllimport)** é melhor, pois o vinculador não gera uma conversão se não for necessária. Conversões tornar o código maior (em sistemas RISC, pode ser várias instruções) e pode prejudicar o desempenho do seu cache. Se você instrui o compilador que a função está em uma DLL, ele pode gerar uma chamada indireta para você.

Agora este código:

```
__declspec(dllimport) void func1(void);
int main(void)
{
   func1();
}
```

gera esta instrução:

```
call DWORD PTR __imp_func1
```

Não há nenhuma conversão e nenhum `jmp` instrução, portanto, o código é menor e mais rápido.

Por outro lado, para chamadas de função dentro de uma DLL, você não deseja ter que usar uma chamada indireta. Você já sabe o endereço da função. Porque o tempo e espaço são necessários para carregar e armazenar o endereço da função antes de uma chamada indireta, uma chamada direta é sempre mais rápido e menor. Você deseja usar **__declspec(dllimport)** ao chamar funções DLL de fora da própria DLL. Não use **__declspec(dllimport)** em funções dentro de uma DLL ao compilar essa DLL.

## <a name="see-also"></a>Consulte também

[Importando para um aplicativo](../build/importing-into-an-application.md)
