---
title: "Paraleliza&#231;&#227;o autom&#225;tica e vetoriza&#231;&#227;o autom&#225;tica | Microsoft Docs"
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
ms.assetid: ec71583a-287b-4599-8767-1d255e080fe3
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Paraleliza&#231;&#227;o autom&#225;tica e vetoriza&#231;&#227;o autom&#225;tica
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Autoparalelizador e Autovetorizador foram projetados para fornecer ganhos de desempenho automática de loops em seu código.  
  
## Autoparalelizador  
 O [\/Qpar](../Topic/-Qpar%20\(Auto-Parallelizer\).md) permite a opção de compilador *a paralelização automática* de loops em seu código.  Quando você especifica esse sinalizador sem modificar o código existente, o compilador avalia o código para localizar a loops que podem se beneficiar de paralelização.  Como talvez descubra loops que não fazem muito trabalho e, portanto, não se beneficiar da paralelização, e cada paralelização desnecessária pode engender a geração de um pool de threads, sincronização extra ou outro processamento tentarão reduzir o desempenho em vez de melhorá\-lo, o compilador é conservadora ao selecionar os loops que ele processa.  Por exemplo, considere o exemplo a seguir em que o limite superior do loop não é conhecido em tempo de compilação:  
  
```cpp  
  
void loop_test(int u) {  
   for (int i=0; i<u; ++i)  
      A[i] = B[i] * C[i];  
}  
```  
  
 Como `u` pode ser um valor pequeno, o compilador não automaticamente paralelização desse loop.  No entanto, ainda convém ele paralelizado porque você sabe que `u` sempre será grande.  Para habilitar a paralelização automática, especifique [\#pragma loop\(hint\_parallel\(n\)\)](../preprocessor/loop.md), onde `n` é o número de threads em paralelo em.  No exemplo a seguir, o compilador tenta colocar o loop em paralelo em threads de 8.  
  
```cpp  
  
void loop_test(int u) {  
#pragma loop(hint_parallel(8))  
   for (int i=0; i<u; ++i)  
      A[i] = B[i] * C[i];  
}  
```  
  
 Com todas as [diretivas pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md), a sintaxe alternativa pragma `__pragma(loop(hint_parallel(n)))` também tem suporte.  
  
 Há alguns loops que o compilador não pode paralelizar mesmo que você deseja.  Veja um exemplo:  
  
```cpp  
  
#pragma loop(hint_parallel(8))  
for (int i=0; i<upper_bound(); ++i)  
    A[i] = B[i] * C[i];  
```  
  
 A função `upper_bound()` pode ser alterado toda vez que ele é chamado.  Porque o limite superior não pode ser conhecido, o compilador pode emitir uma mensagem de diagnóstico que explica por que ele seria possível colocar esse loop.  O exemplo a seguir demonstra um loop que pode ser colocado em paralelo, um loop que não pode ser colocado em paralelo, a sintaxe do compilador para usar no prompt de comando e a saída do compilador para cada opção de linha de comando:  
  
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
  
 Compilar usando este comando:  
  
 **cl d:\\myproject\\mylooptest.cpp \/O2 \/Qpar \/Qpar\-report:1**  
  
 produz esta saída:  
  
 **\-\-\- Analyzing function: void \_\_cdecl test\(void\)**   
  **d:\\myproject\\mytest.cpp\(4\) : loop parallelized**  
  
 Compilar usando este comando:  
  
 **cl d:\\myproject\\mylooptest.cpp \/O2 \/Qpar \/Qpar\-report:2**  
  
 produz esta saída:  
  
 **\-\-\- Analyzing function: void \_\_cdecl test\(void\)**   
  **d:\\myproject\\mytest.cpp\(4\) : loop parallelized**   
  **d:\\myproject\\mytest.cpp\(4\) : loop not parallelized due to reason '1008'**  
  
 Observe a diferença na saída entre os dois diferentes [\/Qpar\-report \(nível de relatórios do paralelizador automático\)](../build/reference/qpar-report-auto-parallelizer-reporting-level.md) opções.  **\/Qpar\-report:1** gera mensagens paralelizador apenas loops com êxito são colocados em paralelo.  **\/Qpar\-report:2** gera mensagens paralelizador para ambos os parallelizations loop bem\-sucedidas e malsucedidas.  
  
 Para obter mais informações sobre códigos de motivo e mensagens, consulte [Mensagens do vetorizador e do paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).  
  
## Vetorizador automático  
 O Autovetorizador analisa loops em seu código e usa os registros de vetor e instruções no computador de destino para executá\-los, se for possível.  Isso pode melhorar o desempenho do seu código.  O compilador tem como alvo as instruções SSE2, AVX e AVX2 em processadores Intel ou AMD ou as instruções de NEON em processadores ARM, de acordo com o [\/arch](../build/reference/arch-minimum-cpu-architecture.md) alternar.  
  
 O Autovetorizador pode gerar diferentes instruções que o especificado pelo **\/arch** Alternar.  Essas instruções são protegidas por uma verificação de tempo de execução para certificar\-se de que código ainda seja executado corretamente.  Por exemplo, quando você compila **\/arch:SSE2**, instruções SSE 4.2 podem ser emitidas.  Uma verificação em runtime verifica se o SSE 4.2 está disponível no processador de destino e vai para uma versão não SSE 4.2 do loop se o processador não oferece suporte a essas instruções.  
  
 Por padrão, o Vetorizador automático está habilitado.  Se você deseja comparar o desempenho do seu código em vetorização, você poderá usar [\#pragma loop\(no\_vector\)](../preprocessor/loop.md) para desabilitar a vetorização do loop qualquer determinado.  
  
```  
  
#pragma loop(no_vector)  
for (int i = 0; i < 1000; ++i)  
   A[i] = B[i] + C[i];  
  
```  
  
 Com todas as [diretivas pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md), a sintaxe alternativa pragma `__pragma(loop(no_vector))` também tem suporte.  
  
 Como com o Autoparalelizador, você pode especificar o [\/Qvec\-report \(nível de relatórios do vetorizador automático\)](../build/reference/qvec-report-auto-vectorizer-reporting-level.md) a opção de linha de comando para relatar qualquer um com êxito vetorizado apenas loops —**\/Qvec\-report:1**— ou ambos com êxito e sem êxito vetorizado loops —**\/Qvec\-report:2**\).  
  
 Para obter mais informações sobre códigos de motivo e mensagens, consulte [Mensagens do vetorizador e do paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).  
  
 Para obter um exemplo mostrando como o vetorizador funciona na prática, consulte [Project Austin parte 2 de 6: página Curling](http://blogs.msdn.com/b/vcblog/archive/2012/09/27/10348494.aspx)  
  
## Consulte também  
 [loop](../preprocessor/loop.md)   
 [programação paralela em código nativo](http://go.microsoft.com/fwlink/?LinkId=263662)   
 [\/Qpar \(paralelizador automático\)](../Topic/-Qpar%20\(Auto-Parallelizer\).md)   
 [\/Qpar\-report \(nível de relatórios do paralelizador automático\)](../build/reference/qpar-report-auto-parallelizer-reporting-level.md)   
 [\/Qvec\-report \(nível de relatórios do vetorizador automático\)](../build/reference/qvec-report-auto-vectorizer-reporting-level.md)   
 [Mensagens do vetorizador e do paralelizador](../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md)