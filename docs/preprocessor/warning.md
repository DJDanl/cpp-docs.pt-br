---
title: "warning | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "warning_CPP"
  - "vc-pragma.warning"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragma de aviso pop"
  - "pragmas, warning"
  - "aviso de pragma push"
  - "pragma de aviso"
ms.assetid: 8e9a0dec-e223-4657-b21d-5417ebe29cc8
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# warning
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Permite a modificação seletiva do comportamento de mensagens de aviso do compilador.  
  
## Sintaxe  
  
```  
  
      #pragma warning(   
      warning-specifier  
       :   
      warning-number-list [; warning-specifier : warning-number-list...] )  
#pragma warning( push[ ,n ] )  
#pragma warning( pop )  
```  
  
## Comentários  
 Os seguintes parâmetros de especificador de aviso estão disponíveis.  
  
|especificador de aviso|Significado|  
|----------------------------|-----------------|  
|`1, 2, 3, 4`|Aplique o nível fornecido aos avisos especificados.  Isso também ativa um aviso especificado que é desativado por padrão.|  
|`default`|Redefina o comportamento de aviso para seu valor padrão.  Isso também ativa um aviso especificado que é desativado por padrão.  O aviso será gerado em seu nível padrão e documentado.<br /><br /> Para obter mais informações, consulte [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md).|  
|`disable`|Não emita a mensagem de aviso especificada.|  
|`error`|Relate os avisos especificados como erros.|  
|`once`|Exiba as mensagens especificadas somente uma vez.|  
|`suppress`|Empurra o estado atual do pragma na pilha, desabilita o aviso especificado para a próxima linha e depois exibe a pilha de aviso para que o estado de pragma seja redefinido.|  
  
 A seguinte instrução de código mostra que um parâmetro `warning-number-list` pode conter vários números de aviso e que vários parâmetros `warning-specifier` podem ser especificados na mesma política de pragma.  
  
```  
#pragma warning( disable : 4507 34; once : 4385; error : 164 )  
```  
  
 Essa funcionalidade é equivalente ao código a seguir.  
  
```  
// Disable warning messages 4507 and 4034.  
#pragma warning( disable : 4507 34 )  
  
// Issue warning 4385 only once.  
#pragma warning( once : 4385 )  
  
// Report warning 4164 as an error.  
#pragma warning( error : 164 )  
```  
  
 O compilador adiciona 4000 a todos os números de aviso que estejam entre 0 e 999.  
  
 Para os números de aviso no intervalo de 4700 a 4999, que são os associados à geração de códigos, o estado do aviso em vigor quando o compilador encontra a chave aberta de uma função ficará em vigor pelo restante da função.  Usar o pragma de `warning` na função para alterar o estado de um aviso que tem um número maior que 4699 só entrará em vigor depois do término da função.  O exemplo a seguir mostra a colocação correta de pragmas de `warning` para desabilitar uma mensagem de aviso de geração de código e, depois, para restaurá\-la.  
  
```  
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
  
## Enviar por push e mostrar  
 O pragma de `warning` também oferece suporte à sintaxe a seguir.  
  
 `#pragma warning(` `push` \[ `,``n` \] `)`  
  
 `#pragma warning(` `pop )`  
  
 Onde `n` representa um nível de aviso \(de 1 a 4\).  
  
 O pragma de `warning( push )` armazena o estado atual de aviso de cada aviso.  O pragma de `warning( push,` `n``)` armazena o estado atual de cada aviso e define o nível de aviso global para `n`.  
  
 O pragma de `warning( pop )` mostra o último estado de aviso enviado por push para a pilha.  Todas as modificações feitas no estado de aviso entre `push` e `pop` serão desfeitas.  Considere este exemplo:  
  
```  
#pragma warning( push )  
#pragma warning( disable : 4705 )  
#pragma warning( disable : 4706 )  
#pragma warning( disable : 4707 )  
// Some code  
#pragma warning( pop )   
```  
  
 No final desse código, `pop` restaura o estado de todos os avisos \(inclui 4705, 4706, 4707\) e o que era no início do código.  
  
 Quando você grava arquivos de cabeçalho, pode usar `push` e `pop` para garantir que as alterações de estado de aviso feitas por um usuário não impeçam que os cabeçalhos sejam compilados corretamente.  Use `push` no início do cabeçalho e `pop` no final.  Por exemplo, se você tiver um cabeçalho não compilado de forma limpa no nível de aviso 4, o código a seguir alteraria o nível de aviso para 3 e restauraria o nível de aviso original no final do cabeçalho.  
  
```  
#pragma warning( push, 3 )  
// Declarations/definitions  
#pragma warning( pop )   
```  
  
 Para obter mais informações sobre as opções do compilador que ajudam a suprimir avisos, consulte [\/FI](../Topic/-FI%20\(Name%20Forced%20Include%20File\).md) e [\/w](../build/reference/compiler-option-warning-level.md).  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)