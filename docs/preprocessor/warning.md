---
title: Pragma warning
ms.date: 08/29/2019
f1_keywords:
- warning_CPP
- vc-pragma.warning
helpviewer_keywords:
- pragmas, warning
- push pragma warning
- pop warning pragma
- warning pragma
ms.assetid: 8e9a0dec-e223-4657-b21d-5417ebe29cc8
ms.openlocfilehash: 9a79f0c4a9eed6b62e42f056f9d1994b44b57297
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216464"
---
# <a name="warning-pragma"></a>Pragma warning

Permite a modificação seletiva do comportamento de mensagens de aviso do compilador.

## <a name="syntax"></a>Sintaxe

> **aviso de #pragma (** \
> &nbsp;&nbsp;&nbsp;&nbsp;*especificador de aviso* **:** *aviso-lista de números*\
> &nbsp;&nbsp;&nbsp;&nbsp;[ **;** *especificador de aviso* **:** *aviso-número-lista* ...] **)** \
> **aviso de #pragma (Push** [ **,** *n* ] **)** \
> **aviso de #pragma (pop)**

## <a name="remarks"></a>Comentários

Os seguintes parâmetros de especificador de aviso estão disponíveis.

|especificador de aviso|Significado|
|------------------------|-------------|
|*1, 2, 3, 4*|Aplique o nível fornecido aos avisos especificados. Também ativa um aviso especificado que está desativado por padrão.|
|*default*|Redefina o comportamento de aviso para seu valor padrão. Também ativa um aviso especificado que está desativado por padrão. O aviso será gerado em seu nível padrão e documentado.<br /><br /> Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../preprocessor/compiler-warnings-that-are-off-by-default.md).|
|*disable*|Não emita as mensagens de aviso especificadas.|
|*error*|Relate os avisos especificados como erros.|
|*uma vez*|Exiba as mensagens especificadas somente uma vez.|
|*eliminação*|Empurra o estado atual do pragma na pilha, desabilita o aviso especificado para a próxima linha e depois exibe a pilha de aviso para que o estado de pragma seja redefinido.|

A seguinte instrução de código mostra que um parâmetro `warning-number-list` pode conter vários números de aviso e que vários parâmetros `warning-specifier` podem ser especificados na mesma política de pragma.

```cpp
#pragma warning( disable : 4507 34; once : 4385; error : 164 )
```

Essa diretiva é funcionalmente equivalente ao seguinte código:

```cpp
// Disable warning messages 4507 and 4034.
#pragma warning( disable : 4507 34 )

// Issue warning 4385 only once.
#pragma warning( once : 4385 )

// Report warning 4164 as an error.
#pragma warning( error : 164 )
```

O compilador adiciona 4000 a todos os números de aviso que estejam entre 0 e 999.

Para os números de aviso no intervalo de 4700 a 4999, que são os associados à geração de códigos, o estado do aviso em vigor quando o compilador encontra a chave aberta de uma função ficará em vigor pelo restante da função. O uso do pragma de **aviso** na função para alterar o estado de um número de aviso maior que 4699 só entra em vigor após o final da função. O exemplo a seguir mostra o posicionamento correto dos pragmas de **aviso** para desabilitar uma mensagem de aviso de geração de código e, em seguida, restaurá-la.

```cpp
// pragma_warning.cpp
// compile with: /W1
#pragma warning(disable:4700)
void Test() {
   int x;
   int y = x;   // no C4700 here
   #pragma warning(default:4700)   // C4700 enabled after Test ends
}

int main() {
   int x;
   int y = x;   // C4700
}
```

Observe que, em um corpo de função, a última configuração do pragma de **aviso** estará em vigor para a função inteira.

## <a name="push-and-pop"></a>Enviar por push e mostrar

O pragma de **aviso** também dá suporte à seguinte sintaxe, em que *n* representa um nível de aviso (de 1 a 4).

`#pragma warning( push [ , n ] )`

`#pragma warning( pop )`

O pragma `warning( push )` armazena o estado de aviso atual para cada aviso. O pragma `warning( push, n )` armazena o estado atual para cada aviso e define o nível de aviso global como *n*.

O pragma `warning( pop )` exibe o último estado de aviso enviado por push para a pilha. As alterações feitas no estado de aviso entre *Push* e *pop* são desfeitas. Considere este exemplo:

```cpp
#pragma warning( push )
#pragma warning( disable : 4705 )
#pragma warning( disable : 4706 )
#pragma warning( disable : 4707 )
// Some code
#pragma warning( pop )
```

No final desse código, o *pop* restaura o estado de cada aviso (inclui 4705, 4706 e 4707) para o que ele estava no início do código.

Ao gravar arquivos de cabeçalho, você pode usar *Push* e *pop* para garantir que as alterações de estado de aviso feitas por um usuário não impeçam que os cabeçalhos sejam compilados corretamente. Use *Push* no início do cabeçalho e *pop* no final. Por exemplo, se você tiver um cabeçalho que não seja compilado corretamente no nível de aviso 4, o código a seguir alterará o nível de aviso para 3 e, em seguida, restaurará o nível de aviso original no final do cabeçalho.

```cpp
#pragma warning( push, 3 )
// Declarations/definitions
#pragma warning( pop )
```

Para obter mais informações sobre opções de compilador que ajudam a suprimir avisos, consulte [/Fi](../build/reference/fi-name-forced-include-file.md) e [/w](../build/reference/compiler-option-warning-level.md).

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
