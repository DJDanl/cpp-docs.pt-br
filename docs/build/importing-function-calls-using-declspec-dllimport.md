---
title: "Importando chamadas de função usando __declspec(dllimport) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- __declspec
- dllimport
dev_langs: C++
helpviewer_keywords:
- importing function calls [C++]
- dllimport attribute [C++], function call imports
- __declspec(dllimport) keyword [C++]
- function calls [C++], importing
ms.assetid: 6b53c616-0c6d-419a-8e2a-d2fff20510b3
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5553bd5e9999a4737dc258358402eb71269b9c40
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="importing-function-calls-using-declspecdllimport"></a>Importando chamadas de função usando __declspec(dllimport)
O exemplo de código a seguir mostra como usar **_declspec(dllimport)** importar chamadas de função de uma DLL para um aplicativo. Suponha que `func1` é uma função que reside em uma DLL separada do arquivo .exe que contém o **principal** função.  
  
 Sem **__declspec(dllimport)**, considerando este código:  
  
```  
int main(void)   
{  
   func1();  
}  
```  
  
 o compilador gera o código que tem esta aparência:  
  
```  
call func1  
```  
  
 e o vinculador converte a chamada em algo assim:  
  
```  
call 0x4000000         ; The address of 'func1'.  
```  
  
 Se `func1` existe em outra DLL, o vinculador não pode resolver diretamente nesse porque ele não tem como saber qual o endereço de `func1` é. Em ambientes de 16 bits, o vinculador adiciona esse endereço de código para uma lista no arquivo .exe que o carregador seria patch em tempo de execução com o endereço correto. Em ambientes de 32 bits e 64 bits, o vinculador gera uma conversão dos quais ele sabe o endereço. Em um ambiente de 32 bits a conversão se parece com:  
  
```  
0x40000000:    jmp DWORD PTR __imp_func1  
```  
  
 Aqui `imp_func1` é o endereço para o `func1` slot na tabela de endereço de importação do arquivo .exe. Todos os endereços, portanto, são conhecidos para o vinculador. O carregador só precisa atualizar a tabela de endereço de importação do arquivo .exe no tempo de carregamento para que tudo funcione corretamente.  
  
 Portanto, o uso **__declspec(dllimport)** é melhor porque o vinculador não gera uma conversão se não for necessária. Conversões aumentar o código (em sistemas RISC, pode ser várias instruções) e pode prejudicar o desempenho do cache. Se você instrui o compilador que a função está em uma DLL, ele pode gerar uma chamada indireta para você.  
  
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
  
 Não há nenhuma conversão e não `jmp` instrução, portanto o código é menor e mais rápido.  
  
 Por outro lado, para chamadas de função dentro de uma DLL, você não deseja precisa usar uma chamada indireta. Você já sabe o endereço da função. Como o tempo e espaço são necessários para carregar e armazenar o endereço da função antes de uma chamada indireta, uma chamada direta é sempre mais rápido e menor. Você deseja usar **__declspec(dllimport)** ao chamar funções DLL de fora da DLL em si. Não use **__declspec(dllimport)** em funções dentro de uma DLL ao criar essa DLL.  
  
## <a name="see-also"></a>Consulte também  
 [Importando para um aplicativo](../build/importing-into-an-application.md)