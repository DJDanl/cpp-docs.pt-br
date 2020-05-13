---
title: Importando chamadas de função usando __declspec(dllimport)
description: Como e por que usar __declspec (dllimport) ao chamar dados e funções de DLL.
ms.date: 05/03/2020
helpviewer_keywords:
- importing function calls [C++]
- dllimport attribute [C++], function call imports
- __declspec(dllimport) keyword [C++]
- function calls [C++], importing
ms.assetid: 6b53c616-0c6d-419a-8e2a-d2fff20510b3
ms.openlocfilehash: 515fbdb2824c1eaf41e822adeae1a16d3072eec4
ms.sourcegitcommit: 8a01ae145bc65f5bc90d6e47b4a1bdf47b073ee7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2020
ms.locfileid: "82765715"
---
# <a name="importing-function-calls-using-__declspecdllimport"></a>Importando chamadas de função usando`__declspec(dllimport)`

A anotação de chamadas usando o **`__declspec(dllimport)`** pode torná-las mais rápidas. **`__declspec(dllimport)`** é sempre necessário para acessar dados DLL exportados.

## <a name="import-a-function-from-a-dll"></a>Importar uma função de uma DLL

O exemplo de código a seguir mostra como **`__declspec(dllimport)`** usar o para importar chamadas de função de uma dll para um aplicativo. Suponha que `func1` seja uma função que está em uma DLL separada do arquivo executável que contém a função **Main** .

Sem **`__declspec(dllimport)`**, dado este código:

```C
int main(void)
{
   func1();
}
```

o compilador gera código parecido com este:

```asm
call func1
```

e o vinculador traduz a chamada em algo assim:

```asm
call 0x4000000         ; The address of 'func1'.
```

Se `func1` existir em outra dll, o vinculador não poderá resolver esse endereço diretamente porque não tem como saber qual é o endereço do `func1` . Em ambientes de 32 bits e 64 bits, o vinculador gera uma conversão em um endereço conhecido. Em um ambiente de 32 bits, a conversão é semelhante a:

```asm
0x40000000:    jmp DWORD PTR __imp_func1
```

Aqui `__imp_func1` está o endereço para o `func1` slot na tabela de endereços de importação do arquivo executável. Todos esses endereços são conhecidos pelo vinculador. O carregador só precisa atualizar a tabela de endereços de importação do arquivo executável em tempo de carregamento para que tudo funcione corretamente.

É por isso que **`__declspec(dllimport)`** usar o é melhor: porque o vinculador não gera uma conversão, se não for necessário. As conversões tornam o código maior (em sistemas RISC, podem ser várias instruções) e podem degradar o desempenho do cache. Se você informar ao compilador que a função está em uma DLL, ela poderá gerar uma chamada indireta para você.

Agora, este código:

```C
__declspec(dllimport) void func1(void);
int main(void)
{
   func1();
}
```

gera esta instrução:

```asm
call DWORD PTR __imp_func1
```

Não há conversão e nenhuma `jmp` instrução, portanto, o código é menor e mais rápido. Você também pode obter o mesmo efeito sem **`__declspec(dllimport)`** usar a otimização do programa inteiro. Para obter mais informações, consulte [/GL (otimização de programa inteiro)](reference/gl-whole-program-optimization.md).

Para chamadas de função em uma DLL, você não deseja ter que usar uma chamada indireta. O vinculador já conhece o endereço da função. Ele leva tempo e espaço extra para carregar e armazenar o endereço da função antes de uma chamada indireta. Uma chamada direta é sempre mais rápida e menor. Você só deseja usar **`__declspec(dllimport)`** ao chamar funções de DLL de fora da própria DLL. Não use **`__declspec(dllimport)`** funções do em uma dll ao COMPILAR essa dll.

## <a name="see-also"></a>Confira também

[Importando para um aplicativo](importing-into-an-application.md)
