---
title: "restrita (C++ AMP) | Microsoft Docs"
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
  - "cpu_CPP"
  - "amp_CPP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "cláusula restrita (C++ AMP)"
ms.assetid: 07d3291f-7edf-456b-8828-283ac8673661
caps.latest.revision: 22
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# restrita (C++ AMP)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O especificador de restrição pode ser aplicado a declarações de função e lambda.  Impõe restrições no código na função e no comportamento da função em aplicativos que usam o tempo de execução do C\+\+ Accelerated Massive Parallelism\(AMP C\+\+\).  
  
> [!NOTE]
>  Para obter informações sobre a palavra\-chave `restrict` que faz parte dos atributos de classe de armazenamento `__declspec`, consulte [restrict](../cpp/restrict.md).  
  
 A cláusula de `restrict` usa os seguintes formas:  
  
|Cláusula|Descrição|  
|--------------|---------------|  
|`restrict(cpu)`|A função pode usar a linguagem C\+\+ completa.  Somente outras funções que são declaradas usando as funções restrict\(cpu\) podem chamar a função.|  
|`restrict(amp)`|A função só pode usar o subconjunto da linguagem C\+\+ que o AMP C\+\+ pode acelerar.|  
|Uma sequência de `restrict(cpu)` e `restrict(amp)`.|A função deve atender às limitações de `restrict(cpu)` e `restrict(amp)`.  A função pode ser chamada por funções que são declaradas usando `restrict(cpu)`, `restrict(amp)`, `restrict(cpu, amp)` ou `restrict(amp, cpu)`.<br /><br /> A forma `restrict(A) restrict(B)` pode ser escrita como `restrict(A,B)`.|  
  
## Comentários  
 A palavra\-chave `restrict` é uma palavra\-chave contextual.  Os especificadores de restrição `cpu` e `amp` não são palavras reservadas.  A lista de especificadores não é extensível.  Uma função que não tem uma cláusula `restrict` é igual a uma função que tem a cláusula `restrict(cpu)`.  
  
 Uma função que tem a cláusula `restrict(amp)` tem as seguintes limitações:  
  
-   A função só pode chamar funções que tenham a cláusula `restrict(amp)`.  
  
-   A função deve ser embutível.  
  
-   A função pode declarar somente as variáveis `int`, `unsigned int`, `float` e `double`, e classes e estruturas que contenham apenas esses tipos.  `bool` também é permitido, mas também deve ser alinhado com 4 bytes se você usá\-lo em um tipo composto.  
  
-   As funções lambda não podem capturar por referência nem capturar os ponteiros.  
  
-   As referências e ponteiros de indireção única só têm suporte como variáveis locais, argumentos de função e tipos de retorno.  
  
-   Os seguintes não são permitidos:  
  
    -   Recursão.  
  
    -   Variáveis declaradas com a palavra\-chave [volatile](../cpp/volatile-cpp.md).  
  
    -   Funções virtuais.  
  
    -   Ponteiros para funções.  
  
    -   Ponteiros para funções de membro.  
  
    -   Ponteiros em estruturas.  
  
    -   Ponteiros para ponteiros.  
  
    -   Instruções `goto`.  
  
    -   Instruções rotuladas.  
  
    -   Instruções `try`, `catch` ou `throw`.  
  
    -   Variáveis globais.  
  
    -   Variáveis estáticas.  Use [Palavra\-chave tile\_static](../Topic/tile_static%20Keyword.md) em seu lugar.  
  
    -   Conversões `dynamic_cast`.  
  
    -   O operador `typeid`.  
  
    -   Declarações asm.  
  
    -   Varargs.  
  
 Para obter uma descrição das limitações da função, consulte [Restrições de restrict\(amp\)](http://go.microsoft.com/fwlink/p/?LinkId=251089).  
  
## Exemplo  
 O exemplo a seguir mostra como usar a cláusula `restrict(amp)`.  
  
```  
  
void functionAmp() restrict(amp) {}   
void functionNonAmp() {}   
  
void callFunctions() restrict(amp)   
{   
    // int is allowed.  
    int x;  
    // long long int is not allowed in an amp-restricted function. This generates a compiler error.  
    // long long int y;   
  
    // Calling an amp-restricted function is allowed.  
    functionAmp();   
  
    // Calling a non-amp-restricted function is not allowed.  
    // functionNonAmp();   
  
}  
```  
  
## Consulte também  
 [C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)