---
title: Considerações para escrever código de prólogo / epílogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- stack frame layout
- prolog code
- epilog code
- __LOCAL_SIZE constant
- stack, stack frame layout
ms.assetid: c7814de2-bb5c-4f5f-96d0-bcfd2ad3b182
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b581a57db7e66d1547ffd90509c62353d78d478b
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39464105"
---
# <a name="considerations-for-writing-prologepilog-code"></a>Considerações para escrever o código de prólogo/epílogo
 **Seção específica da Microsoft**  
 Antes de escrever suas próprias sequências de código de prólogo e epílogo, é importante entender como o registro de ativação é apresentado. Também é útil saber como usar o `__LOCAL_SIZE` símbolo.  
  
##  <a name="_pluslang_c.2b2b_.stack_frame_layout"></a> Layout de quadro de pilha  
 Este exemplo mostra o código padrão do prólogo que pode aparecer em uma função de 32 bits:  
  
```  
push        ebp                ; Save ebp  
mov         ebp, esp           ; Set stack frame pointer  
sub         esp, localbytes    ; Allocate space for locals  
push        <registers>        ; Save registers  
```  
  
 A variável `localbytes` representa o número de bytes necessários na pilha para as variáveis locais. A variável `<registers>` é um espaço reservado que representa a lista de registros a serem salvos na pilha. Depois de enviar os registros, você pode colocar todos os outros dados apropriados na pilha. O seguinte exemplo é o código do epílogo correspondente:  
  
```  
pop         <registers>   ; Restore registers  
mov         esp, ebp      ; Restore stack pointer  
pop         ebp           ; Restore ebp  
ret                       ; Return from function  
```  
  
 A pilha sempre vai para baixo (dos endereços de memória mais altos para os mais baixos). O ponteiro de base (`ebp`) aponta para o valor enviados por push de `ebp`. A área de locais começa em `ebp-4`. Para acessar variáveis locais, calcule um deslocamento de `ebp` subtraindo o valor apropriado de `ebp`.  
  
##  <a name="_pluslang___local_size"></a> LOCAL_SIZE  
 O compilador fornece um símbolo, `__LOCAL_SIZE`, para uso no bloco embutido do assembler do código de prólogo da função. Esse símbolo é usado para alocar espaço para as variáveis locais no quadro da pilha no código personalizado de prólogo.  
  
 O compilador determina o valor de `__LOCAL_SIZE`. Seu valor é o número total de bytes de todas as variáveis locais definidas pelo usuário e variáveis temporárias geradas pelo compilador. `__LOCAL_SIZE` pode ser usado apenas como um operando imediato; ele não pode ser usado em uma expressão. Você não deve alterar ou redefinir o valor desse símbolo. Por exemplo:  
  
```  
mov        eax, __LOCAL_SIZE           ;Immediate operand--Okay  
mov        eax, [ebp - __LOCAL_SIZE]   ;Error  
```  
  
 O exemplo a seguir de uma função naked que contém personalizado de prólogo e epílogo sequências usa o `__LOCAL_SIZE` símbolo na sequência de prólogo:  
  
```  
// the__local_size_symbol.cpp  
// processor: x86  
__declspec ( naked ) int main() {  
   int i;  
   int j;  
  
   __asm {      /* prolog */  
      push   ebp  
      mov      ebp, esp  
      sub      esp, __LOCAL_SIZE  
      }  
  
   /* Function body */  
   __asm {   /* epilog */  
      mov      esp, ebp  
      pop      ebp  
      ret  
      }  
}  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Chamadas de função naked](../cpp/naked-function-calls.md)