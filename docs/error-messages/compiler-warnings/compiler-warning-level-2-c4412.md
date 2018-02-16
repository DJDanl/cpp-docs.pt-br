---
title: "Compilador (nível 2) do aviso C4412 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4412
dev_langs:
- C++
helpviewer_keywords:
- C4412
ms.assetid: f28dc531-1a98-497b-a366-0a13e1bc81c7
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 41ecffdd760374ce5b96039e81a467572f977bcd
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="compiler-warning-level-2-c4412"></a>Compilador C4412 de aviso (nível 2)
'function': assinatura de função contém tipo 'type'; Objetos C++ são seguros para passar entre código puro e código misto ou nativo.  
  
 O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015. Se você tiver código que precisa ser "pura", é recomendável que você a porta para c#.  
  
 O compilador detectou uma situação potencialmente não segura que pode resultar em um erro em tempo de execução: é feita uma chamada de um **/clr: pure** compiland para uma função que foi importada por meio de dllimport e a assinatura de função contém um tipo não seguro . Um tipo é seguro se ele contém uma função de membro ou tem um membro de dados que é um tipo não seguro ou uma inversão de controle para um tipo não seguro.  
  
 Isso não é seguro por causa da diferença no padrão convenções entre código puro e nativo de chamada (ou misto gerenciado e nativo). Ao importar (via `dllimport`) uma função em um **/clr: puro** compiland, certifique-se de que as declarações de cada tipo de assinatura são idênticas na compiland que exporta a função (sendo especialmente cuidado diferenças no implícita convenções de chamada).  
  
 Uma função membro virtual é especialmente propensa a gerar resultados inesperados.  No entanto, até mesmo uma função não virtual deve ser testada para garantir que você obtenha os resultados corretos. Se você tiver certeza de que você está obtendo os resultados corretos, você pode ignorar este aviso.  
  
  
 C4412 está desativado por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) e [dllexport, dllimport](../../cpp/dllexport-dllimport.md) para obter mais informações.  
  
 Para resolver este aviso, remova todas as funções do tipo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4412.  
  
```  
// C4412.cpp  
// compile with: /c /W2 /clr:pure  
#pragma warning (default : 4412)  
  
struct Unsafe {  
   virtual void __cdecl Test();  
};  
  
struct Safe {  
   int i;  
};  
  
__declspec(dllimport) Unsafe * __cdecl func();  
__declspec(dllimport) Safe * __cdecl func2();  
  
int main() {  
   Unsafe *pUnsafe = func();   // C4412  
   // pUnsafe->Test();  
  
   Safe *pSafe = func2();   // OK  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir é um arquivo de cabeçalho que declara dois tipos. O `Unsafe` tipo é seguro porque ela tem uma função de membro.  
  
```  
// C4412.h  
struct Unsafe {  
   // will be __clrcall if #included in pure compilation  
   // defaults to __cdecl in native or mixed mode compilation  
   virtual void Test(int * pi);  
  
   // try the following line instead  
   // virtual void __cdecl Test(int * pi);  
};  
  
struct Safe {  
   int i;  
};  
```  
  
## <a name="example"></a>Exemplo  
 Este exemplo exporta as funções com os tipos definidos no arquivo de cabeçalho.  
  
```  
// C4412_2.cpp  
// compile with: /LD  
#include "C4412.h"  
  
void Unsafe::Test(int * pi) {  
   *pi++;  
}  
  
__declspec(dllexport) Unsafe * __cdecl func() { return new Unsafe; }  
__declspec(dllexport) Safe * __cdecl func2() { return new Safe; }  
```  
  
## <a name="example"></a>Exemplo  
 O padrão de convenção de chamada um **/clr: pure** compilação é diferente de uma compilação nativa.  Quando C4412.h é incluído, `Test` padrão é `__clrcall`. Se você compilar e executar este programa (não use **/c**), o programa lançará uma exceção.  
  
 O exemplo a seguir gera C4412.  
  
```  
// C4412_3.cpp  
// compile with: /W2 /clr:pure /c /link C4412_2.lib  
#pragma warning (default : 4412)  
#include "C4412.h"  
  
__declspec(dllimport) Unsafe * __cdecl func();  
__declspec(dllimport) Safe * __cdecl func2();  
  
int main() {  
   int n = 7;  
   Unsafe *pUnsafe = func();   // C4412  
   pUnsafe->Test(&n);  
  
   Safe *pSafe = func2();   // OK  
}  
```