---
title: Aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- warning_CPP
- vc-pragma.warning
dev_langs:
- C++
helpviewer_keywords:
- pragmas, warning
- push pragma warning
- pop warning pragma
- warning pragma
ms.assetid: 8e9a0dec-e223-4657-b21d-5417ebe29cc8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4b739a3f72416b6ab58cbdba45a496e10fef4424
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="warning-pragma"></a>Pragma de aviso
Permite a modificação seletiva do comportamento de mensagens de aviso do compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
#pragma warning(   
    warning-specifier : warning-number-list [; warning-specifier : warning-number-list...] )  
#pragma warning( push[ ,n ] )  
#pragma warning( pop )  
```  
  
## <a name="remarks"></a>Comentários  
Os seguintes parâmetros de especificador de aviso estão disponíveis.  
  
|especificador de aviso|Significado|  
|------------------------|-------------|  
|`1, 2, 3, 4`|Aplique o nível fornecido aos avisos especificados. Isso também ativa um aviso especificado que é desativado por padrão.|  
|`default`|Redefina o comportamento de aviso para seu valor padrão. Isso também ativa um aviso especificado que é desativado por padrão. O aviso será gerado em seu nível padrão e documentado.<br /><br /> Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../preprocessor/compiler-warnings-that-are-off-by-default.md).|  
|`disable`|Não emita a mensagem de aviso especificada.|  
|`error`|Relate os avisos especificados como erros.|  
|`once`|Exiba as mensagens especificadas somente uma vez.|  
|`suppress`|Empurra o estado atual do pragma na pilha, desabilita o aviso especificado para a próxima linha e depois exibe a pilha de aviso para que o estado de pragma seja redefinido.|  
  
 A seguinte instrução de código mostra que um parâmetro `warning-number-list` pode conter vários números de aviso e que vários parâmetros `warning-specifier` podem ser especificados na mesma política de pragma.  
  
```cpp  
#pragma warning( disable : 4507 34; once : 4385; error : 164 )  
```  
  
 Essa funcionalidade é equivalente ao código a seguir.  
  
```cpp  
// Disable warning messages 4507 and 4034.  
#pragma warning( disable : 4507 34 )  
  
// Issue warning 4385 only once.  
#pragma warning( once : 4385 )  
  
// Report warning 4164 as an error.  
#pragma warning( error : 164 )  
```  
  
 O compilador adiciona 4000 a todos os números de aviso que estejam entre 0 e 999.  
  
 Para os números de aviso no intervalo de 4700 a 4999, que são os associados à geração de códigos, o estado do aviso em vigor quando o compilador encontra a chave aberta de uma função ficará em vigor pelo restante da função. Usar o pragma de `warning` na função para alterar o estado de um aviso que tem um número maior que 4699 só entrará em vigor depois do término da função. O exemplo a seguir mostra a colocação correta de pragmas de `warning` para desabilitar uma mensagem de aviso de geração de código e, depois, para restaurá-la.  
  
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
  
 Em um corpo de função, a configuração mais recente do pragma de `warning` será aplicada à função inteira.  
  
## <a name="push-and-pop"></a>Enviar por push e mostrar  
 O `warning` pragma também oferece suporte a sintaxe a seguir, onde `n` representa um nível de aviso (de 1 a 4).  
  
 `#pragma warning( push [ , n ] )`  
  
 `#pragma warning( pop )`  
   
 O pragma `warning( push )` armazena o estado de aviso atual para cada aviso. O pragma `warning( push, n )` armazena o estado atual de cada aviso e define o nível de aviso global como `n`.  
  
 O pragma `warning( pop )` pops o último estado de aviso inserido na pilha. Todas as modificações feitas no estado de aviso entre `push` e `pop` serão desfeitas. Considere este exemplo:  
  
```cpp  
#pragma warning( push )  
#pragma warning( disable : 4705 )  
#pragma warning( disable : 4706 )  
#pragma warning( disable : 4707 )  
// Some code  
#pragma warning( pop )   
```  
  
 No final desse código, `pop` restaura o estado de todos os avisos (inclui 4705, 4706, 4707) e o que era no início do código.  
  
 Quando você grava arquivos de cabeçalho, pode usar `push` e `pop` para garantir que as alterações de estado de aviso feitas por um usuário não impeçam que os cabeçalhos sejam compilados corretamente. Use `push` no início do cabeçalho e `pop` no final. Por exemplo, se você tiver um cabeçalho não compilado de forma limpa no nível de aviso 4, o código a seguir alteraria o nível de aviso para 3 e restauraria o nível de aviso original no final do cabeçalho.  
  
```cpp  
#pragma warning( push, 3 )  
// Declarations/definitions  
#pragma warning( pop )   
```  
  
 Para obter mais informações sobre o compilador opções que ajudam você suprimir avisos, consulte [/FI](../build/reference/fi-name-forced-include-file.md) e [/w](../build/reference/compiler-option-warning-level.md).  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)