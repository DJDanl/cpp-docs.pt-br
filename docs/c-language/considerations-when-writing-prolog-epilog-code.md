---
title: "Considera&#231;&#245;es quando escrever c&#243;digo de pr&#243;logo/ep&#237;logo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante __LOCAL_SIZE"
  - "layouts, registro de ativação"
  - "layout de registro de ativação"
  - "stack, layout de registro de ativação"
ms.assetid: 3b8addec-e809-48e4-b1d0-5bad133bd4b8
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Considera&#231;&#245;es quando escrever c&#243;digo de pr&#243;logo/ep&#237;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Antes de escrever suas próprias sequências de código de prólogo e epílogo, é importante entender como o registro de ativação é apresentado.  Também é útil saber como usar a constante predefinida **\_\_LOCAL\_SIZE**.  
  
##  <a name="_clang_c_stack_frame_layout"></a> Layout do registro de ativação C  
 Este exemplo mostra o código padrão do prólogo que pode aparecer em uma função de 32 bits:  
  
```  
push     ebp                 ; Save ebp  
mov      ebp, esp            ; Set stack frame pointer  
sub      esp, localbytes     ; Allocate space for locals  
push     <registers>         ; Save registers  
```  
  
 A variável `localbytes` representa o número de bytes necessários na pilha para as variáveis locais. A variável `registers` é um espaço reservado que representa a lista de registros a serem salvos na pilha.  Depois de enviar os registros, você pode colocar todos os outros dados apropriados na pilha.  O seguinte exemplo é o código do epílogo correspondente:  
  
```  
pop      <registers>         ; Restore registers  
mov      esp, ebp            ; Restore stack pointer  
pop      ebp                 ; Restore ebp  
ret                          ; Return from function  
```  
  
 A pilha sempre vai para baixo \(dos endereços de memória mais altos para os mais baixos\).  O ponteiro de base \(`ebp`\) aponta para o valor enviados por push de `ebp`.  A área de variáveis locais começa em `ebp-2`.  Para acessar variáveis locais, calcule um deslocamento de `ebp` subtraindo o valor apropriado de `ebp`.  
  
##  <a name="_clang_the___local_size_constant"></a> A constante \_\_LOCAL\_SIZE  
 O compilador fornece uma constante, **\_\_LOCAL\_SIZE**, para o uso no bloco embutido do assembler do código do prólogo da função.  Essa constante é usada para alocar espaço para as variáveis locais no quadro da pilha no código personalizado de prólogo.  
  
 O compilador determina o valor de **\_\_LOCAL\_SIZE**.  O valor é o número total de bytes de todas as variáveis locais definidas pelo usuário e variáveis temporárias geradas pelo compilador.  **\_\_LOCAL\_SIZE** pode ser usado apenas como um operando imediato; não pode ser usado em uma expressão.  Você não deve alterar ou redefinir o valor dessa constante.  Por exemplo:  
  
```  
mov      eax, __LOCAL_SIZE           ;Immediate operand--Okay  
mov      eax, [ebp - __LOCAL_SIZE]   ;Error  
```  
  
 O exemplo a seguir mostra uma função naked que contém sequências de prólogo e epílogo personalizadas e usa **\_\_LOCAL\_SIZE** na sequência de prólogo:  
  
```  
__declspec ( naked ) func()  
{  
   int i;  
   int j;  
  
   __asm      /* prolog */  
      {  
      push   ebp  
      mov      ebp, esp  
      sub      esp, __LOCAL_SIZE  
      }  
  
   /* Function body */  
  
   __asm      /* epilog */  
      {  
      mov      esp, ebp  
      pop      ebp  
      ret  
      }  
}     
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Funções Naked](../c-language/naked-functions.md)