---
title: "Paralelização automática e vetorização automática | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: ec71583a-287b-4599-8767-1d255e080fe3
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7f84f891a12da90efbe68371d077e2d41b111ea0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="auto-parallelization-and-auto-vectorization"></a>Paralelização automática e vetorização automática
Paralelizador automático e Vetorizador automático são projetados para fornecer ganhos de desempenho automático para loops em seu código.  
  
## <a name="auto-parallelizer"></a>Paralelizador automático  
 O [/Qpar](../build/reference/qpar-auto-parallelizer.md) habilita a opção de compilador *paralelização* de loops em seu código. Quando você especificar esse sinalizador sem alterar seu código existente, o compilador avalia o código para localizar loops que podem se beneficiar de paralelização. Porque ele pode encontrar loops que não faz muito trabalho e, portanto, não se beneficiar de paralelização, e porque cada paralelização desnecessária pode engender a geração de um pool de threads, sincronização adicional ou outro processamento que seria tendem a velocidade desempenho em vez de melhorá-lo, o compilador é conservador nos selecionando os loops que ele parallelizes. Por exemplo, considere o exemplo a seguir em que o limite superior do loop não é conhecido em tempo de compilação:  
  
```cpp  
void loop_test(int u) {  
   for (int i=0; i<u; ++i)  
      A[i] = B[i] * C[i];  
}  
```  
  
 Porque `u` poderia ser um valor pequeno, o compilador não paralelizar automaticamente esse loop. No entanto, talvez ainda seja ele paralelizado porque você sabe que `u` sempre será grande. Para habilitar a paralelização automática, especifique [#pragma loop(hint_parallel(n))](../preprocessor/loop.md), onde `n` é o número de threads em paralelo em. No exemplo a seguir, o compilador tenta colocar o loop em paralelo entre 8 threads.  
  
```cpp  
void loop_test(int u) {  
#pragma loop(hint_parallel(8))  
   for (int i=0; i<u; ++i)  
      A[i] = B[i] * C[i];  
}  
```  
  
 Assim como acontece com todos os [diretivas pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md), a sintaxe alternativa pragma `__pragma(loop(hint_parallel(n)))` também tem suporte.  
  
 Há alguns loops em que o compilador não pode paralelizar mesmo se você quiser. Veja um exemplo:  
  
```cpp  
#pragma loop(hint_parallel(8))  
for (int i=0; i<upper_bound(); ++i)  
    A[i] = B[i] * C[i];  
```  
  
 A função `upper_bound()` pode ser alterado toda vez que ele é chamado. Como o limite superior não pode ser conhecido, o compilador pode emitir uma mensagem de diagnóstico que explica por que ele não é possível paralelizar esse loop. O exemplo a seguir demonstra um loop que pode ser colocadas em paralelo, um loop que não pode ser colocado em paralelo, o compilador sintaxe no prompt de comando e a saída do compilador para cada opção de linha de comando:  
  
```cpp  
int A[1000];  
void test() {  
#pragma loop(hint_parallel(0))  
    for (int i=0; i<1000; ++i) {  
        A[i] = A[i] + 1;  
    }  
  
    for (int i=1000; i<2000; ++i) {  
        A[i] = A[i] + 1;  
    }  
}  
  
```  
  
 A compilação usando este comando:  
  
 **Cl d:\myproject\mylooptest.cpp /O2 /Qpar /Qpar-relatório: 1**  
  
 produz este resultado:  
  
 **---Analisar a função: void test(void) cdecl**   
 **d:\myproject\mytest.cpp(4): loop paralelizado**  
  
 A compilação usando este comando:  
  
 **Cl d:\myproject\mylooptest.cpp /O2 /Qpar /Qpar-relatório: 2**  
  
 produz este resultado:  
  
 **---Analisar a função: void test(void) cdecl**   
 **d:\myproject\mytest.cpp(4): loop paralelizado**   
 **d:\myproject\mytest.cpp(4): loop não paralelizado devido ao motivo '1008'**  
  
 Observe a diferença na saída entre os dois diferentes [/Qpar-report (nível de emissão de relatórios do Paralelizador automático)](../build/reference/qpar-report-auto-parallelizer-reporting-level.md) opções. **/Qpar-relatório: 1** gera mensagens de paralelizador apenas de loops que são colocados em paralelo com êxito. **/Qpar-relatório: 2** gera mensagens de paralelizador para ambos os parallelizations loop com e sem êxito.  
  
 Para obter mais informações sobre códigos de motivo e mensagens, consulte [mensagens do Vetorizador e Paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).  
  
## <a name="auto-vectorizer"></a>Vetorizador automático  
 O Vetorizador automático analisa loops em seu código e usa os registros de vetor e as instruções no computador de destino para executá-los, se ele não pode. Isso pode melhorar o desempenho do seu código. As instruções SSE2, AVX e AVX2 em processadores Intel ou AMD ou as instruções de NEON em processadores ARM, tem como alvo o compilador de acordo com o [/arch](../build/reference/arch-minimum-cpu-architecture.md) alternar.  
  
 O Vetorizador automático pode gerar instruções diferentes do especificado pelo **/arch** alternar. Essas instruções são protegidas por uma verificação de tempo de execução para certificar-se de que código ainda seja executado corretamente. Por exemplo, quando você compila **/arch: SSE2**, SSE4.2 instruções podem ser emitidas. Uma verificação de tempo de execução verifica se SSE4.2 está disponível no processador de destino e salta para uma versão não SSE4.2 do loop, se o processador não dá suporte a essas instruções.  
  
 Por padrão, o Vetorizador automático está habilitado. Se você deseja comparar o desempenho do seu código em vetorização, você pode usar [#pragma loop(no_vector)](../preprocessor/loop.md) para desabilitar vetorização de qualquer dado loop.  
  
```  
  
      #pragma loop(no_vector)  
for (int i = 0; i < 1000; ++i)  
   A[i] = B[i] + C[i];  
  
```  
  
 Assim como acontece com todos os [diretivas pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md), a sintaxe alternativa pragma `__pragma(loop(no_vector))` também tem suporte.  
  
 Como com Paralelizador automático, você pode especificar o [/Qvec-report (nível de emissão de relatórios do Vetorizador automático)](../build/reference/qvec-report-auto-vectorizer-reporting-level.md) a opção de linha de comando para relatar o êxito vetorizado loops apenas —**/Qvec-relatório: 1**— ou com êxito e sem êxito vetorizado loops —**/Qvec-relatório: 2**).  
  
 Para obter mais informações sobre códigos de motivo e mensagens, consulte [mensagens do Vetorizador e Paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).  
  
 Para obter um exemplo mostrando como o vetorizador funciona na prática, consulte [projeto Austin parte 2 de 6: Curling de página](http://blogs.msdn.com/b/vcblog/archive/2012/09/27/10348494.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [loop](../preprocessor/loop.md)   
 [Programação paralela em código nativo](http://go.microsoft.com/fwlink/?linkid=263662)   
 [/Qpar (Paralelizador automático)](../build/reference/qpar-auto-parallelizer.md)   
 [/Qpar-Report (nível de Paralelizador automático relatórios)](../build/reference/qpar-report-auto-parallelizer-reporting-level.md)   
 [/Qvec-Report (nível de Vetorizador automático relatórios)](../build/reference/qvec-report-auto-vectorizer-reporting-level.md)   
 [Mensagens do vetorizador e do paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md)