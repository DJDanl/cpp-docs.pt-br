---
title: restringir (C++ AMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- cpu_CPP
- amp_CPP
dev_langs:
- C++
helpviewer_keywords:
- restrict clause (C++ AMP)
ms.assetid: 07d3291f-7edf-456b-8828-283ac8673661
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: abe3bd4f737cfb26a326a1f0d83b731c36e6c7bf
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="restrict-c-amp"></a>restrita (C++ AMP)
O especificador de restrição pode ser aplicado a declarações de função e lambda. Impõe restrições no código na função e no comportamento da função em aplicativos que usam o tempo de execução do C++ Accelerated Massive Parallelism(AMP C++).  
  
> [!NOTE]
>  Para obter informações sobre o `restrict` palavra-chave que é parte do `__declspec` atributos de classe de armazenamento, consulte [restringir](../cpp/restrict.md).  
  
 A cláusula de `restrict` usa os seguintes formas:  
  
|Cláusula|Descrição|  
|------------|-----------------|  
|`restrict(cpu)`|A função pode usar a linguagem C++ completa. Somente outras funções que são declaradas usando as funções restrict(cpu) podem chamar a função.|  
|`restrict(amp)`|A função só pode usar o subconjunto da linguagem C++ que o AMP C++ pode acelerar.|  
|Uma sequência de `restrict(cpu)` e `restrict(amp)`.|A função deve atender às limitações de `restrict(cpu)` e `restrict(amp)`. A função pode ser chamada por funções que são declaradas usando `restrict(cpu)`, `restrict(amp)`, `restrict(cpu, amp)` ou `restrict(amp, cpu)`.<br /><br /> A forma `restrict(A) restrict(B)` pode ser escrita como `restrict(A,B)`.|  
  
## <a name="remarks"></a>Comentários  
 A palavra-chave `restrict` é uma palavra-chave contextual. Os especificadores de restrição `cpu` e `amp` não são palavras reservadas. A lista de especificadores não é extensível. Uma função que não tem uma cláusula `restrict` é igual a uma função que tem a cláusula `restrict(cpu)`.  
  
 Uma função que tem a cláusula `restrict(amp)` tem as seguintes limitações:  
  
-   A função só pode chamar funções que tenham a cláusula `restrict(amp)`.  
  
-   A função deve ser embutível.  
  
-   A função pode declarar somente as variáveis `int`, `unsigned int`, `float` e `double`, e classes e estruturas que contenham apenas esses tipos. `bool` também é permitido, mas também deve ser alinhado com 4 bytes se você usá-lo em um tipo composto.  
  
-   As funções lambda não podem capturar por referência nem capturar os ponteiros.  
  
-   As referências e ponteiros de indireção única só têm suporte como variáveis locais, argumentos de função e tipos de retorno.  
  
-   Os seguintes não são permitidos:  
  
    -   Recursão.  
  
    -   Variáveis declaradas com o [volátil](../cpp/volatile-cpp.md) palavra-chave.  
  
    -   Funções virtuais.  
  
    -   Ponteiros para funções.  
  
    -   Ponteiros para funções de membro.  
  
    -   Ponteiros em estruturas.  
  
    -   Ponteiros para ponteiros.  
  
    -   Instruções `goto`.  
  
    -   Instruções rotuladas.  
  
    -   Instruções `try`, `catch` ou `throw`.  
  
    -   Variáveis globais.  
  
    -   Variáveis estáticas. Use [palavra-chave tile_static](../cpp/tile-static-keyword.md) em vez disso.  
  
    -   Conversões `dynamic_cast`.  
  
    -   O operador `typeid`.  
  
    -   Declarações asm.  
  
    -   Varargs.  
  
 Para obter uma discussão das limitações de função, consulte [restrict(amp) restrições](http://go.microsoft.com/fwlink/p/?LinkId=251089).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar o `restrict(amp)`cláusula.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [C++ AMP (C++ Accelerated Massive Parallelism)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)