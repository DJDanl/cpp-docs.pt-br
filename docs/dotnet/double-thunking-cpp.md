---
title: Conversão dupla (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- double thunks
- interop [C++], double thunking
- mixed assemblies [C++], double thunking
- /clr compiler option [C++], double thunking
- interoperability [C++], double thunking
ms.assetid: a85090b2-dc3c-498a-b40c-340db229dd6f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 47d5bbbecc8e1b9743c543a503df1a0afa0dc0ae
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="double-thunking-c"></a>Conversão dupla (C++)
Conversão dupla refere-se a perda de desempenho que você pode experimentar quando uma chamada de função em chamadas um contexto gerenciado um Visual C++ gerenciado função e onde a execução de programa chama o ponto de entrada nativo da função para chamar a função gerenciada. Este tópico discute onde ocorre a conversão dupla e como evitá-lo para melhorar o desempenho.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, ao compilar com **/clr**, a definição de uma função gerenciada faz com que o compilador gere um ponto de entrada gerenciado e um ponto de entrada nativo. Isso permite que a função gerenciada a ser chamado de sites de chamada gerenciado e nativo. No entanto, quando existe um ponto de entrada nativo, ele pode ser o ponto de entrada para todas as chamadas para a função. Se uma função de chamada for gerenciada, o ponto de entrada nativo chamará o ponto de entrada gerenciado. Na verdade, duas chamadas são necessários para invocar a função (portanto, duplos conversão). Por exemplo, funções virtuais sempre são chamadas por meio de um ponto de entrada nativo.  
  
 Uma resolução é informar ao compilador para não gerar um ponto de entrada nativo para uma função gerenciada, que a função apenas ser chamada em um contexto de gerenciado usando o [clrcall](../cpp/clrcall.md) convenção de chamada.  
  
 Da mesma forma, se você exportar ([dllexport, dllimport](../cpp/dllexport-dllimport.md)) uma função gerenciada, um ponto de entrada nativo é gerado e qualquer função que importa e chama a função será chamada através do ponto de entrada nativo. Para evitar dupla nessa situação, não use semântica de importação/exportação nativo; simplesmente referencie os metadados por meio de `#using` (consulte [#using diretiva](../preprocessor/hash-using-directive-cpp.md)).  
  
 O compilador foi atualizado para reduzir dupla desnecessários. Por exemplo, qualquer função com um tipo gerenciado na assinatura (incluindo o tipo de retorno) implicitamente será marcada como `__clrcall`. Para obter mais informações sobre a eliminação de conversão dupla, consulte [ http://msdn.microsoft.com/msdnmag/issues/05/01/COptimizations/default.aspx ](http://msdn.microsoft.com/msdnmag/issues/05/01/COptimizations/default.aspx).  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo a seguir demonstra dupla. Quando compilado nativo (sem **/clr**), a chamada à função virtual em `main` gera uma chamada para `T`do construtor de cópia e uma chamada para o destruidor. Comportamento semelhante é obtido quando a função virtual é declarada com **/clr** e `__clrcall`. No entanto, quando compilado apenas com **/clr**, a chamada de função gera uma chamada para o construtor de cópia, mas há outra chamada para o construtor de cópia devido à conversão de nativo para gerenciado.  
  
### <a name="code"></a>Código  
  
```  
// double_thunking.cpp  
// compile with: /clr  
#include <stdio.h>  
struct T {  
   T() {  
      puts(__FUNCSIG__);  
   }  
  
   T(const T&) {  
      puts(__FUNCSIG__);  
   }  
  
   ~T() {  
      puts(__FUNCSIG__);  
   }  
  
   T& operator=(const T&) {  
      puts(__FUNCSIG__);  
      return *this;  
   }  
};  
  
struct S {  
   virtual void /* __clrcall */ f(T t) {};  
} s;  
  
int main() {  
   S* pS = &s;  
   T t;  
  
   printf("calling struct S\n");  
   pS->f(t);  
   printf("after calling struct S\n");  
}  
```  
  
### <a name="sample-output"></a>Saída de Exemplo  
  
```  
__thiscall T::T(void)  
calling struct S  
__thiscall T::T(const struct T &)  
__thiscall T::T(const struct T &)  
__thiscall T::~T(void)  
__thiscall T::~T(void)  
after calling struct S  
__thiscall T::~T(void)  
```  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo anterior demonstrou a existência de dupla. Este exemplo mostra o efeito. O `for` loop chama a função virtual e o tempo de execução de relatórios do programa. O tempo mais lento é relatado quando o programa é compilado com **/clr**. Os tempos mais rápidos são relatados ao compilar sem **/clr** ou se a função virtual for declarada com `__clrcall`.  
  
### <a name="code"></a>Código  
  
```  
// double_thunking_2.cpp  
// compile with: /clr  
#include <time.h>  
#include <stdio.h>   
  
#pragma unmanaged  
struct T {  
   T() {}  
   T(const T&) {}  
   ~T() {}  
   T& operator=(const T&) { return *this; }  
};  
  
struct S {  
   virtual void /* __clrcall */ f(T t) {};  
} s;  
  
int main() {  
   S* pS = &s;  
   T t;  
   clock_t start, finish;  
   double  duration;  
   start = clock();  
  
   for ( int i = 0 ; i < 1000000 ; i++ )  
      pS->f(t);  
  
   finish = clock();  
   duration = (double)(finish - start) / (CLOCKS_PER_SEC);  
   printf( "%2.1f seconds\n", duration );  
   printf("after calling struct S\n");  
}  
```  
  
### <a name="sample-output"></a>Saída de Exemplo  
  
```  
4.2 seconds  
after calling struct S  
```  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)