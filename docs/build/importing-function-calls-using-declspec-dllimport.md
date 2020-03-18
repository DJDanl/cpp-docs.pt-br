---
title: Importando chamadas de função usando __declspec(dllimport)
ms.date: 11/04/2016
helpviewer_keywords:
- importing function calls [C++]
- dllimport attribute [C++], function call imports
- __declspec(dllimport) keyword [C++]
- function calls [C++], importing
ms.assetid: 6b53c616-0c6d-419a-8e2a-d2fff20510b3
ms.openlocfilehash: 1743cbba8c3046ef844f16be8e78d43c61f62606
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79442511"
---
# <a name="importing-function-calls-using-__declspecdllimport"></a>Importando chamadas de função usando __declspec(dllimport)

O exemplo de código a seguir mostra como usar **_declspec (dllimport)** para importar chamadas de função de uma dll para um aplicativo. Suponha que `func1` é uma função que reside em uma DLL separada do arquivo. exe que contém a função **Main** .

Sem **__declspec (dllimport)** , dado este código:

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

e o vinculador traduz a chamada em algo assim:

```
call 0x4000000         ; The address of 'func1'.
```

Se `func1` existir em outra DLL, o vinculador não poderá resolver isso diretamente porque não tem como saber qual é o endereço do `func1`. Em ambientes de 16 bits, o vinculador adiciona esse endereço de código a uma lista no arquivo. exe que o carregador corrigiria em tempo de execução com o endereço correto. Em ambientes de 32 bits e 64 bits, o vinculador gera uma conversão da qual ele sabe o endereço. Em um ambiente de 32 bits, a conversão é semelhante a:

```
0x40000000:    jmp DWORD PTR __imp_func1
```

Aqui `imp_func1` é o endereço do slot de `func1` na tabela de endereços de importação do arquivo. exe. Assim, todos os endereços são conhecidos pelo vinculador. O carregador só precisa atualizar a tabela de endereços de importação do arquivo. exe no tempo de carregamento para que tudo funcione corretamente.

Portanto, o uso de **__declspec (dllimport)** é melhor porque o vinculador não gera uma conversão, se não for necessário. As conversões tornam o código maior (em sistemas RISC, podem ser várias instruções) e podem degradar o desempenho do cache. Se você informar ao compilador que a função está em uma DLL, ela poderá gerar uma chamada indireta para você.

Agora, este código:

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

Não há nenhuma conversão e nenhuma instrução de `jmp`, portanto, o código é menor e mais rápido.

Por outro lado, para chamadas de função dentro de uma DLL, você não deseja ter que usar uma chamada indireta. Você já conhece o endereço de uma função. Como o tempo e o espaço são necessários para carregar e armazenar o endereço da função antes de uma chamada indireta, uma chamada direta é sempre mais rápida e menor. Você só deseja usar **__declspec (dllimport)** ao chamar funções de DLL de fora da própria DLL. Não use **__declspec (dllimport)** em funções dentro de uma dll ao COMPILAR essa dll.

## <a name="see-also"></a>Consulte também

[Importando para um aplicativo](importing-into-an-application.md)
