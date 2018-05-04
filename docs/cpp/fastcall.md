---
title: fastcall | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __fastcall_cpp
dev_langs:
- C++
helpviewer_keywords:
- __fastcall keyword [C++]
ms.assetid: bb5b9c8a-dfad-450c-9119-0ac2bc59544f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4d69c97294795ed2f3f0b2d82ec8caa4734fa1f7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="fastcall"></a>__fastcall
**Seção específica da Microsoft**  
  
 A convenção de chamada `__fastcall` especifica se os argumentos para funções devem ser passados em registros, quando possível. Esta convenção de chamada se aplica somente à arquitetura x86. A lista a seguir mostra a implementação dessa convenção de chamada.  
  
|Elemento|Implementação|  
|-------------|--------------------|  
|Ordem de passagem de argumentos|Os dois primeiros argumentos de DWORD ou menores encontrados na lista de argumentos da esquerda para a direita são passados em registros de ECX e de EDX; todos os outros argumentos são passados na pilha da direita para a esquerda.|  
|Responsabilidade de manutenção de pilha|A função de chamada retira os argumentos da pilha.|  
|Convenção de decoração de nome|O sinal arroba (@) antecede os nomes; um sinal de arroba seguido pelo número de bytes (em decimais) na lista de parâmetros é acrescentado como sufixo aos nomes.|  
|Convenção de conversão de maiúsculas/minúsculas|Nenhuma conversão de maiúsculas/minúsculas é realizada.|  
  
> [!NOTE]
>  As versões futuras do compilador podem usar registros diferentes para armazenar parâmetros.  
  
 Usando o [/Gr](../build/reference/gd-gr-gv-gz-calling-convention.md) opção de compilador faz com que cada função no módulo para compilar como `__fastcall` a menos que a função é declarada usando um atributo em conflito, ou o nome da função `main`.  
  
 A palavra-chave `__fastcall` é aceita e ignorada pelos compiladores voltados para arquiteturas ARM e x64; em um chip x64, por convenção, os primeiros quatro argumentos são passados em registros quando possível, e os argumentos adicionais são passados na pilha. Para obter mais informações, consulte [visão geral do x64 convenções de chamada](../build/overview-of-x64-calling-conventions.md). Em um chip ARM, até quatro argumentos inteiros e oito argumentos de ponto flutuante podem ser passados em registros, e os argumentos adicionais são passados na pilha.  
  
 Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição. Dada esta definição de classe:  
  
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
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, a função `DeleteAggrWrapper` recebe argumentos passados em registros:  
  
```cpp  
// Example of the __fastcall keyword  
#define FASTCALL    __fastcall  
  
void FASTCALL DeleteAggrWrapper(void* pWrapper);  
// Example of the __ fastcall keyword on function pointer  
typedef BOOL (__fastcall *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)