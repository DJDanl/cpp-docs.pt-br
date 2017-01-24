---
title: "__fastcall | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__fastcall"
  - "__fastcall_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __fastcall [C++]"
ms.assetid: bb5b9c8a-dfad-450c-9119-0ac2bc59544f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __fastcall
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A convenção de chamada `__fastcall` especifica se os argumentos para funções devem ser passados em registros, quando possível.  Esta convenção de chamada se aplica somente à arquitetura x86.  A lista a seguir mostra a implementação dessa convenção de chamada.  
  
|Elemento|Implementação|  
|--------------|-------------------|  
|Ordem de passagem de argumentos|Os dois primeiros argumentos de DWORD ou menores encontrados na lista de argumentos da esquerda para a direita são passados em registros de ECX e de EDX; todos os outros argumentos são passados na pilha da direita para a esquerda.|  
|Responsabilidade de manutenção de pilha|A função de chamada retira os argumentos da pilha.|  
|Convenção de decoração de nome|O sinal arroba \(@\) antecede os nomes; um sinal de arroba seguido pelo número de bytes \(em decimais\) na lista de parâmetros é acrescentado como sufixo aos nomes.|  
|Convenção de conversão de maiúsculas e minúsculas|Nenhuma conversão de maiúsculas\/minúsculas é realizada.|  
  
> [!NOTE]
>  As versões futuras do compilador podem usar registros diferentes para armazenar parâmetros.  
  
 O uso da opção de compilador [\/Gr](../build/reference/gd-gr-gv-gz-calling-convention.md) faz com que cada função no módulo seja compilada como `__fastcall` a menos que a função seja declarada usando um atributo conflitante ou o nome da função seja `main`.  
  
 A palavra\-chave `__fastcall` é aceita e ignorada pelos compiladores voltados para arquiteturas ARM e x64; em um chip x64, por convenção, os primeiros quatro argumentos são passados em registros quando possível, e os argumentos adicionais são passados na pilha.  Para obter mais informações, consulte [Visão geral de convenções de chamada de x64](../build/overview-of-x64-calling-conventions.md).  Em um chip ARM, até quatro argumentos inteiros e oito argumentos de ponto flutuante podem ser passados em registros, e os argumentos adicionais são passados na pilha.  
  
 Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisa ser especificado na definição fora da linha.  Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição.  Dada esta definição de classe:  
  
```cpp  
struct CMyClass {  
   void __fastcall mymethod();  
};  
```  
  
 isto:  
  
```cpp  
void CMyClass::mymethod() { return; }  
```  
  
 equivale a isto:  
  
```cpp  
void __fastcall CMyClass::mymethod() { return; }  
```  
  
## Exemplo  
 No exemplo a seguir, a função `DeleteAggrWrapper` recebe argumentos passados em registros:  
  
```c  
// Example of the __fastcall keyword  
#define FASTCALL    __fastcall  
  
void FASTCALL DeleteAggrWrapper(void* pWrapper);  
// Example of the __ fastcall keyword on function pointer  
typedef BOOL (__fastcall *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);  
```  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../Topic/Argument%20Passing%20and%20Naming%20Conventions.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)