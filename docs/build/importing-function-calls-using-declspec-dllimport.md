---
title: "Importando chamadas de fun&#231;&#227;o usando __declspec(dllimport) | Microsoft Docs"
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
  - "__declspec"
  - "dllimport"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec(dllimport) [C++]"
  - "Atributo dllimport [C++], importações de chamada de função"
  - "chamadas de função [C++], importando"
  - "importando chamadas de função [C++]"
ms.assetid: 6b53c616-0c6d-419a-8e2a-d2fff20510b3
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Importando chamadas de fun&#231;&#227;o usando __declspec(dllimport)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código mostra como usar **\_declspec\(dllimport\)** para importar chamadas de função de uma DLL em um aplicativo.  Suponha que `func1` é uma função que reside em uma DLL se separa do arquivo .exe que contém a função de **main** .  
  
 Sem **\_\_declspec\(dllimport\)**, com esse código:  
  
```  
int main(void)   
{  
   func1();  
}  
```  
  
 o compilador gerencia o código que parece como este:  
  
```  
call func1  
```  
  
 o vinculador e traduz a chamada em algo como:  
  
```  
call 0x4000000         ; The address of 'func1'.  
```  
  
 Se `func1` existir em outro DLL, o vinculador não pode resolver isso diretamente porque o não tem nenhuma forma de saber o que o endereço de `func1` é.  Em ambientes de 16 bits, o vinculador adiciona esse endereço codificado em uma lista no arquivo .exe que o carregador remendaria em tempo de execução pelo endereço correto.  Em ambientes de 32 bits e de 64 bits, o vinculador gerencie um thunk de que souber o endereço.  Em um ambiente de 32 bits o thunk examina a seguinte aparência:  
  
```  
0x40000000:    jmp DWORD PTR __imp_func1  
```  
  
 Aqui `imp_func1` é o endereço para o local de `func1` na tabela de endereço de importação do arquivo .exe.  Todos os endereços são conhecidos isso ao vinculador.  O carregador só precisa atualizar a tabela de endereço de importação do arquivo de .exe no tempo de carregamento para que todos funcione corretamente.  
  
 Em virtude disso, usar **\_\_declspec\(dllimport\)** é melhor porque o vinculador não gerencia um thunk se não for necessário.  Thunks faz o código maior \(em sistemas de RISC, pode ser várias instruções\) e pode degradar o desempenho de cache.  Se você informa o compilador a função está em uma DLL, ele pode gerar uma chamada indireto para você.  
  
 Isso agora esse código:  
  
```  
__declspec(dllimport) void func1(void);  
int main(void)   
{  
   func1();  
}  
```  
  
 gerenciar essa instrução:  
  
```  
call DWORD PTR __imp_func1  
```  
  
 Não há nenhum thunk e nenhuma instrução de `jmp` , assim que o código é menor e mais rapidamente.  
  
 Por outro lado, para chamadas de função dentro de uma DLL, você não deseja ter que usar uma chamada indireto.  Você já souber o endereço de função.  Como o tempo e o espaço são necessários para carregar e armazenar o endereço da função antes que uma chamada indirect, uma chamada direta é sempre mais rápido e menor.  Quiser usar apenas **\_\_declspec\(dllimport\)** ao chamar o DLL funções fora da DLL em si.  Não use **\_\_declspec\(dllimport\)** em funções dentro de uma DLL ao compilar que o DLL.  
  
## Consulte também  
 [Importando para um aplicativo](../build/importing-into-an-application.md)