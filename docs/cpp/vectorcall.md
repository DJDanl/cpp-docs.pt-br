---
title: vectorcall | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 1c95ed59-86c6-4857-b4ed-10519193f851
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 54c1473e2341c783ebf73883680d51f161d99163
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="vectorcall"></a>__vectorcall
**Seção específica da Microsoft**  
  
 A convenção de chamada `__vectorcall` especifica se os argumentos para funções devem ser passados em registros, quando possível. `__vectorcall`usa mais registros para argumentos que [fastcall](../cpp/fastcall.md) ou o padrão [convenção de chamada x64](../build/overview-of-x64-calling-conventions.md) usar. A convenção de chamada `__vectorcall` é suportada somente em código nativo nos processadores de x86 e x64 que incluem Streaming SIMD Extensions 2 (SSE2) e superiores. Use `__vectorcall` para agilizar as funções que passam vários argumentos de ponto flutuante ou de vetor SIMD e executar operações que aproveitam os argumentos carregados em registros. A lista a seguir mostra os recursos que são comuns às implementações de x86 e x64 de `__vectorcall`. As diferenças são explicadas posteriormente neste artigo.  
  
|Elemento|Implementação|  
|-------------|--------------------|  
|Convenção de nomes decoração do C|Os nomes de função têm como sufixo dois sinais de arroba (@@) seguidos pelo número de bytes (em decimais) na lista de parâmetros.|  
|Convenção de conversão de maiúsculas/minúsculas|Nenhuma tradução realizada.|  
  
 Usando o [/Gv](../build/reference/gd-gr-gv-gz-calling-convention.md) opção de compilador faz com que cada função no módulo para compilar como `__vectorcall` , a menos que a função é uma função de membro, é declarada com um atributo de convenção de chamada conflitantes, usa um `vararg` variável lista de argumentos, ou tem o nome `main`.  
  
 Você pode transmitir três tipos de argumentos de registro em `__vectorcall` funções: *tipo inteiro* valores, *vector tipo* valores, e *agregação vetor homogênea* (HVA ) valores.  
  
 Um tipo inteiro satisfaz dois requisitos: se encaixa no tamanho nativo de registro do processador, por exemplo, 4 bytes em um computador x86 ou 8 bytes em um computador x64, e pode ser convertido para um número inteiro do comprimento de registro e de volta para o seu formato original sem alterar sua representação de bit. Por exemplo, qualquer tipo que possa ser promovidos para `int` em x (`long long` em x64) — por exemplo, `char` ou `short`— ou que pode ser convertido em `int` (`long long` em x64) e de volta para seu tipo sem alteração original é um tipo inteiro. Os tipos inteiros incluem o ponteiro, a referência e a `struct` ou tipos `union` de 4 bytes (8 bytes em x64) ou menos. Em plataformas x64, a `struct` maior e os tipos de `union` são passados em função da memória atribuída pelo chamador; nas plataformas x86, eles são passados pelo valor na pilha.  
  
 Um tipo vetorial é um tipo de ponto flutuante, por exemplo, `float` ou `double`, ou um vetor de SIMD de tipo, por exemplo, `__m128` ou `__m256`.  
  
 Um tipo de HVA é um tipo composto de até quatro membros de dados que têm tipos vetoriais idênticos. Um tipo de HVA tem o mesmo requisito de alinhamento que o tipo de vetor dos seus membros. Este é um exemplo de uma definição de `struct` do HVA que contém três tipos idênticos de vetor e tem um alinhamento de 32 bytes:  
  
```cpp  
typedef struct {  
   __m256 x;  
   __m256 y;  
   __m256 z;  
} hva3;    // 3 element HVA type on __m256  
  
```  
  
 Declare explicitamente suas funções com a palavra-chave `__vectorcall` em arquivos de cabeçalho para permitir que código compilado separadamente seja vinculado sem erros. As funções devem ser prototipadas para usarem `__vectorcall` e não podem usar uma lista de argumentos de comprimento variável `vararg`.  
  
 Uma função de membro pode ser declarada usando o especificador de `__vectorcall`. O ponteiro `this` oculto é transmitido pelo registro como o primeiro argumento do tipo inteiro.  
  
 Em computadores ARM, `__vectorcall` é aceito e ignorado pelo compilador.  
  
 Para funções de membro de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisa ser especificado na definição fora da linha. Ou seja, para membros de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponde de definição. Dada esta definição de classe:  
  
```cpp  
struct MyClass {  
   void __vectorcall mymethod();  
};  
```  
  
 isto:  
  
```cpp  
void MyClass::mymethod() { return; }  
```  
  
 equivale a isto:  
  
```cpp  
void __vectorcall MyClass::mymethod() { return; }  
```  
  
 O modificador da convenção de chamada `__vectorcall` deve ser especificado quando um ponteiro para uma função `__vectorcall` é criado. O exemplo a seguir cria `typedef` para um ponteiro para uma função `__vectorcall` que usa quatro argumentos `double` e retorna um valor `__m256`:  
  
```cpp  
typedef __m256 (__vectorcall * vcfnptr)(double, double, double, double);  
```  
  
## <a name="vectorcall-convention-on-x64"></a>convenção de __vectorcall em x64  
 A convenção de chamada `__vectorcall` em x64 estende a convenção de chamada padrão de x64 para tirar proveito de registros adicionais. Os argumentos de tipo inteiro e os argumentos de tipo vetorial são mapeados nos registradores com base em sua posição na lista de argumentos. Os argumentos HVA são alocados a registros de vetor não utilizados.  
  
 Quando alguns dos primeiros quatro argumentos na ordem são argumentos de tipo inteiro da esquerda para a direita, eles são passados no registro correspondente a essa posição - RCX, RDX, R8, ou R9. Um ponteiro oculto de `this` é tratado como o primeiro argumento do tipo inteiro. Quando um argumento de HVA em um dos primeiros quatro argumentos não pode ser passado em registros disponíveis, uma referência à memória atribuída ao chamador é passada no registro correspondente do tipo inteiro em vez disso. Os argumentos de tipo inteiro após a quarta posição de parâmetro são passados para a pilha.  
  
 Quando algum dos primeiros seis argumentos na ordem são argumentos de tipo vetor da esquerda para a direita, eles são passados por valor nos registros de vetor SSE 0 a 5, de acordo com a posição do argumento. Os tipos de ponto flutuante e `__m128` são passados em registros MMX e os tipos `__m256` são passados em registros YMM. Isso difere da convenção padrão de chamada do x64, porque os tipos de vetor são passados por valor, não por referência, e registros adicionais são usados. O espaço de pilha de sombra alocado para os argumentos de tipo de vetor é fixo em 8 bytes e o [/homeparams](../build/reference/homeparams-copy-register-parameters-to-stack.md) opção não se aplica. Os argumentos de tipo vetorial na posição de parâmetro sete ou posteriores são passados na pilha em função de memória atribuída pelo chamador.  
  
 Após os registros serem atribuídos para argumentos vetoriais, os membros de dados dos argumentos de HVA são atribuídos em ordem crescente para registros vetoriais não usados de XMM0 a XMM5 (ou YMM0 a YMM5, para os tipos `__m256`), contanto que haja registros suficientes disponíveis para todo o HVA. Se não houver registros disponíveis, o argumento do HVA será passado por referência para a memória alocada pelo chamador. O espaço de sombra de pilha para um argumento de HVA é corrigido em 8 bytes com conteúdo indefinido. Os argumentos HVA são atribuídos a registros da esquerda para a direita na lista de parâmetros e podem estar em qualquer posição. Os argumentos HVA em uma das primeiras quatro posições de argumento que não são atribuídos a registros de vetor são passados por referência no registro de inteiro que corresponda a essa posição. Os argumentos HVA passados por referência após a quarta posição de parâmetro são enviados por push na pilha.  
  
 Os resultados das funções `__vectorcall` são retornados pelo valor em registros quando possível. Os resultados do tipo inteiro, incluindo as estruturas ou uniões de 8 bytes ou menos, são retornadas pelo valor em RAX. Os resultados do tipo vetorial são retornados pelo valor em XMM0 ou em YMM0, dependendo do tamanho. Os resultados HVA têm cada elemento de dados retornado pelo valor em registros XMM0:XMM3 ou YMM0:YMM3, dependendo do tamanho do elemento. Os tipos de resultado que não cabem nos registros correspondentes são retornados por referência à memória alocada pelo chamador.  
  
 A pilha é mantida pelo chamador na implementação x64 de `__vectorcall`. O código de prólogo e epílogo do chamador aloca e limpa a pilha da função chamada. Os argumentos são empurrados na pilha da direita para a esquerda, e o espaço da pilha de sombra é atribuído para os argumentos passados nos registros.  
  
 Exemplos:  
  
```cpp  
// crt_vc64.c  
// Build for amd64 with: cl /arch:AVX /W3 /FAs crt_vc64.c  
// This example creates an annotated assembly listing in  
// crt_vc64.asm.  
  
#include <intrin.h>  
#include <xmmintrin.h>  
  
typedef struct {  
   __m128 array[2];  
} hva2;    // 2 element HVA type on __m128  
  
typedef struct {  
   __m256 array[4];  
} hva4;    // 4 element HVA type on __m256  
  
// Example 1: All vectors  
// Passes a in XMM0, b in XMM1, c in YMM2, d in XMM3, e in YMM4.  
// Return value in XMM0.  
__m128 __vectorcall   
example1(__m128 a, __m128 b, __m256 c, __m128 d, __m256 e) {  
   return d;  
}  
  
// Example 2: Mixed int, float and vector parameters  
// Passes a in RCX, b in XMM1, c in R8, d in XMM3, e in YMM4,   
// f in XMM5, g pushed on stack.   
// Return value in YMM0.  
__m256 __vectorcall   
example2(int a, __m128 b, int c, __m128 d, __m256 e, float f, int g) {  
   return e;  
}  
  
// Example 3: Mixed int and HVA parameters  
// Passes a in RCX, c in R8, d in R9, and e pushed on stack.  
// Passes b by element in [XMM0:XMM1];   
// b's stack shadow area is 8-bytes of undefined value.   
// Return value in XMM0.  
__m128 __vectorcall example3(int a, hva2 b, int c, int d, int e) {  
   return b.array[0];  
}  
  
// Example 4: Discontiguous HVA   
// Passes a in RCX, b in XMM1, d in XMM3, and e is pushed on stack.  
// Passes c by element in [YMM0,YMM2,YMM4,YMM5], discontiguous because  
// vector arguments b and d were allocated first.   
// Shadow area for c is an 8-byte undefined value.  
// Return value in XMM0.  
float __vectorcall example4(int a, float b, hva4 c, __m128 d, int e) {  
   return b;  
}  
  
// Example 5: Multiple HVA arguments  
// Passes a in RCX, c in R8, e pushed on stack.  
// Passes b in [XMM0:XMM1], d in [YMM2:YMM5], each with   
// stack shadow areas of an 8-byte undefined value.  
// Return value in RAX.  
int __vectorcall example5(int a, hva2 b, int c, hva4 d, int e) {  
   return c + e;  
}  
  
// Example 6: HVA argument passed by reference, returned by register  
// Passes a in [XMM0:XMM1], b passed by reference in RDX, c in YMM2,   
// d in [XMM3:XMM4].   
// Register space was insufficient for b, but not for d.  
// Return value in [YMM0:YMM3].  
hva4 __vectorcall example6(hva2 a, hva4 b, __m256 c, hva2 d) {  
   return b;  
}  
  
int __cdecl main( void )  
{  
   hva4 h4;  
   hva2 h2;  
   int i;  
   float f;  
   __m128 a, b, d;  
   __m256 c, e;  
  
   a = b = d = _mm_set1_ps(3.0f);  
   c = e = _mm256_set1_ps(5.0f);  
   h2.array[0] = _mm_set1_ps(6.0f);  
   h4.array[0] = _mm256_set1_ps(7.0f);  
  
   b = example1(a, b, c, d, e);  
   e = example2(1, b, 3, d, e, 6.0f, 7);  
   d = example3(1, h2, 3, 4, 5);  
   f = example4(1, 2.0f, h4, d, 5);  
   i = example5(1, h2, 3, h4, 5);  
   h4 = example6(h2, h4, c, h2);  
}  
  
```  
  
## <a name="vectorcall-convention-on-x86"></a>convenção de __vectorcall em x86  
 A convenção de chamada `__vectorcall` segue a convenção `__fastcall` para argumentos de tipo inteiro de 32 bits e tira proveito dos registros do vetor SSE para o tipo de vetor e os argumentos de HVA.  
  
 Os dois primeiros argumentos de tipo inteiro localizados na lista de parâmetros, da esquerda para a direita, são colocados em ECX e EDX, respectivamente. Um ponteiro oculto `this` é tratado como o primeiro argumento do tipo inteiro, e é passado no ECX. Os primeiros seis argumentos de tipo de vetor são transmitidos por valor pelos registros 0 a 5 do vetor SSE, nos registros de MMX ou YMM, dependendo do tamanho do argumento.  
  
 Os primeiros seis argumentos de tipo de vetor, da esquerda para a direita, são transmitidos por valor nos registros 0 a 5 do vetor SSE. Os tipos de ponto flutuante e `__m128` são passados em registros MMX e os tipos `__m256` são passados em registros YMM. Nenhum espaço de pilha de sombra está alocado para argumentos de tipo de vetor passado pelo registro. Os argumentos de tipo vetorial sete ou posteriores são passados na pilha em referência à memória atribuída pelo chamador. A limitação de erro do compilador [C2719](../error-messages/compiler-errors-2/compiler-error-c2719.md) não é aplicável a estes argumentos.  
  
 Após os registros serem atribuídos para argumentos vetoriais, os membros de dados dos argumentos de HVA são atribuídos em ordem crescente para registros vetoriais não usados de XMM0 a XMM5 (ou YMM0 a YMM5, para os tipos `__m256`), contanto que haja registros suficientes disponíveis para todo o HVA. Se não houver registros disponíveis, o argumento do HVA será passado na pilha por referência para a memória alocada pelo chamador. Nenhum espaço de sombra de pilha para um argumento do HVA está alocado. Os argumentos HVA são atribuídos a registros da esquerda para a direita na lista de parâmetros e podem estar em qualquer posição.  
  
 Os resultados das funções `__vectorcall` são retornados pelo valor em registros quando possível. Os resultados do tipo inteiro, incluindo as estruturas ou uniões de 4 bytes ou menos, são retornadas pelo valor em EAX. As estruturas ou uniões de tipo inteiro de 8 bytes ou menos são retornadas por valor em EDX:EAX. Os resultados do tipo vetorial são retornados pelo valor em XMM0 ou em YMM0, dependendo do tamanho. Os resultados HVA têm cada elemento de dados retornado pelo valor em registros XMM0:XMM3 ou YMM0:YMM3, dependendo do tamanho do elemento. Outros tipos de resultados são retornados em referência à memória atribuída pelo chamador.  
  
 A implementação x86 de `__vectorcall` segue a convenção dos argumentos empurrados na pilha da direita para a esquerda pelo chamador, e a função chamada limpa a pilha imediatamente antes que ele retorna. Apenas os argumentos que não são colocados em registros são empurrados na pilha.  
  
 Exemplos:  
  
```cpp  
// crt_vc86.c  
// Build for x86 with: cl /arch:AVX /W3 /FAs crt_vc86.c  
// This example creates an annotated assembly listing in  
// crt_vc86.asm.  
  
#include <intrin.h>  
#include <xmmintrin.h>  
  
typedef struct {  
   __m128 array[2];  
} hva2;    // 2 element HVA type on __m128  
  
typedef struct {  
   __m256 array[4];  
} hva4;    // 4 element HVA type on __m256  
  
// Example 1: All vectors  
// Passes a in XMM0, b in XMM1, c in YMM2, d in XMM3, e in YMM4.  
// Return value in XMM0.  
__m128 __vectorcall   
example1(__m128 a, __m128 b, __m256 c, __m128 d, __m256 e) {  
   return d;  
}  
  
// Example 2: Mixed int, float and vector parameters  
// Passes a in ECX, b in XMM0, c in EDX, d in XMM1, e in YMM2,   
// f in XMM3, g pushed on stack.   
// Return value in YMM0.  
__m256 __vectorcall   
example2(int a, __m128 b, int c, __m128 d, __m256 e, float f, int g) {  
   return e;  
}  
  
// Example 3: Mixed int and HVA parameters  
// Passes a in ECX, c in EDX, d and e pushed on stack.  
// Passes b by element in [XMM0:XMM1].   
// Return value in XMM0.  
__m128 __vectorcall example3(int a, hva2 b, int c, int d, int e) {  
   return b.array[0];  
}  
  
// Example 4: HVA assigned after vector types  
// Passes a in ECX, b in XMM0, d in XMM1, and e in EDX.  
// Passes c by element in [YMM2:YMM5].   
// Return value in XMM0.  
float __vectorcall example4(int a, float b, hva4 c, __m128 d, int e) {  
   return b;  
}  
  
// Example 5: Multiple HVA arguments  
// Passes a in ECX, c in EDX, e pushed on stack.  
// Passes b in [XMM0:XMM1], d in [YMM2:YMM5].  
// Return value in EAX.  
int __vectorcall example5(int a, hva2 b, int c, hva4 d, int e) {  
   return c + e;  
}  
  
// Example 6: HVA argument passed by reference, returned by register  
// Passes a in [XMM1:XMM2], b passed by reference in ECX, c in YMM0,   
// d in [XMM3:XMM4].   
// Register space was insufficient for b, but not for d.  
// Return value in [YMM0:YMM3].  
hva4 __vectorcall example6(hva2 a, hva4 b, __m256 c, hva2 d) {  
   return b;  
}  
  
int __cdecl main( void )  
{  
   hva4 h4;  
   hva2 h2;  
   int i;  
   float f;  
   __m128 a, b, d;  
   __m256 c, e;  
  
   a = b = d = _mm_set1_ps(3.0f);  
   c = e = _mm256_set1_ps(5.0f);  
   h2.array[0] = _mm_set1_ps(6.0f);  
   h4.array[0] = _mm256_set1_ps(7.0f);  
  
   b = example1(a, b, c, d, e);  
   e = example2(1, b, 3, d, e, 6.0f, 7);  
   d = example3(1, h2, 3, 4, 5);  
   f = example4(1, 2.0f, h4, d, 5);  
   i = example5(1, h2, 3, h4, 5);  
   h4 = example6(h2, h4, c, h2);  
}  
  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)