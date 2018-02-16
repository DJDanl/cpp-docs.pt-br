---
title: 'Como: marshaling de estruturas usando PInvoke | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs:
- C++
helpviewer_keywords:
- data marshaling [C++], structures
- platform invoke [C++], structures
- interop [C++], structures
- marshaling [C++], structures
ms.assetid: 35997e6f-9251-4af3-8c6e-0712d64d6a5d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 2ebda5f17b94fa28a5eb5222ccc991119ec4f81a
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="how-to-marshal-structures-using-pinvoke"></a>Como realizar marshaling de estruturas usando PInvoke
Este documento explica como nativas funções que aceitam cadeias de caracteres de estilo C podem ser chamadas de funções gerenciadas que fornecem uma instância de <xref:System.String> usando P/Invoke. Embora, recomendamos que você use os recursos de interoperabilidade C++ em vez de P/Invoke porque P/Invoke fornece relatórios, pouco de erros de tempo de compilação não é fortemente tipado e poderá ser tediosa implementar, se a API não gerenciada é empacotada como uma DLL e o código-fonte não é disponível, P/Invoke é a única opção. Caso contrário, consulte os seguintes documentos:  
  
-   [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)  
  
-   [Como realizar marshaling de estruturas usando PInvoke](../dotnet/how-to-marshal-structures-using-pinvoke.md)  
  
 Por padrão, as estruturas nativas e gerenciadas são dispostas diferente na memória, êxito passar estruturas através dos limites gerenciados/requer etapas adicionais para preservar a integridade dos dados.  
  
 Este documento explica as etapas necessárias para definir equivalentes gerenciados de estruturas nativas e como as estruturas resultantes podem ser passadas para funções não gerenciadas. Este documento assume que simples estruturas — aqueles que não contêm cadeias de caracteres ou ponteiros — são usados. Para obter informações sobre a interoperabilidade não blittable, consulte [usando Interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md). P/Invoke não podem ter tipos blittable não como um valor de retorno. Tipos blittable tem a mesma representação em código gerenciado e não gerenciado. Para obter mais informações, consulte [Blittable e tipos Blittable não](http://msdn.microsoft.com/Library/d03b050e-2916-49a0-99ba-f19316e5c1b3).  
  
 Marshaling simples, estruturas de blittable através dos limites gerenciados/primeiro requer que gerenciado versões de cada estrutura nativo seja definida. Essas estruturas podem ter qualquer nome válido; Não há nenhuma relação entre a versão nativa e gerenciada de duas estruturas diferente de seu layout de dados. Portanto, é vital que a versão gerenciada contém campos que são do mesmo tamanho e na mesma ordem que a versão nativa. (Não há nenhum mecanismo para garantir que as versões gerenciadas e nativas da estrutura são equivalentes, para que incompatibilidades não ficará visível até que o tempo de execução. É responsabilidade do programador para garantir que as duas estruturas tenham o mesmo layout de dados.)  
  
 Como os membros de estruturas gerenciados são reorganizados, às vezes, por motivos de desempenho, é necessário usar o <xref:System.Runtime.InteropServices.StructLayoutAttribute> atributo para indicar que a estrutura são apresentados em sequência. Também é uma boa ideia para definir explicitamente a estrutura de configuração para ser o mesmo usado pela estrutura nativo de remessa. (Embora, por padrão, o Visual C++ usa uma estrutura de 8 bytes de empacotamento para os dois código gerenciado.)  
  
1.  Em seguida, use <xref:System.Runtime.InteropServices.DllImportAttribute> para declarar os pontos de entrada que correspondem a todas as funções não gerenciadas que aceitam a estrutura, mas usar a versão gerenciada da estrutura de assinaturas de função, que é uma questão se você usar o mesmo nome para as duas versões das estrutura.  
  
2.  Agora o código gerenciado pode passar a versão gerenciada da estrutura de para as funções não gerenciadas como se estivessem realmente gerenciadas funções. Essas estruturas podem ser passadas por valor ou por referência, conforme demonstrado no exemplo a seguir.  
  
## <a name="example"></a>Exemplo  
 O código a seguir consiste em uma não gerenciado e um módulo gerenciado. O módulo não gerenciado é uma DLL que define uma estrutura chamada local e uma função chamada GetDistance que aceita as duas instâncias da estrutura de local. O segundo módulo é um aplicativo gerenciado de linha de comando que importa a função GetDistance, mas define em termos de um equivalente gerenciado da estrutura de local, MLocation. Na prática, o mesmo nome provavelmente seria usado para ambas as versões de estrutura. No entanto, um nome diferente é usado aqui para demonstrar que o protótipo de DllImport está definido em termos de versão gerenciada.  
  
 Observe que nenhuma parte da DLL é exposto para o código gerenciado usando o tradicional # diretiva include. Na verdade, a DLL é acessada no tempo de execução, para que problemas com funções importados com DllImport não ser detectados em tempo de compilação.  
  
```  
// TraditionalDll3.cpp  
// compile with: /LD /EHsc  
#include <iostream>  
#include <stdio.h>  
#include <math.h>  
  
#define TRADITIONALDLL_EXPORTS  
#ifdef TRADITIONALDLL_EXPORTS  
   #define TRADITIONALDLL_API __declspec(dllexport)  
#else  
   #define TRADITIONALDLL_API __declspec(dllimport)  
#endif  
  
#pragma pack(push, 8)  
struct Location {  
   int x;  
   int y;  
};  
#pragma pack(pop)  
  
extern "C" {  
   TRADITIONALDLL_API double GetDistance(Location, Location);  
   TRADITIONALDLL_API void InitLocation(Location*);  
}  
  
double GetDistance(Location loc1, Location loc2) {  
   printf_s("[unmanaged] loc1(%d,%d)", loc1.x, loc1.y);  
   printf_s(" loc2(%d,%d)\n", loc2.x, loc2.y);  
  
   double h = loc1.x - loc2.x;  
   double v = loc1.y = loc2.y;  
   double dist = sqrt( pow(h,2) + pow(v,2) );  
  
   return dist;  
}  
  
void InitLocation(Location* lp) {  
   printf_s("[unmanaged] Initializing location...\n");  
   lp->x = 50;  
   lp->y = 50;  
}  
```  
  
## <a name="example"></a>Exemplo  
  
```  
// MarshalStruct_pi.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
[StructLayout(LayoutKind::Sequential, Pack=8)]  
value struct MLocation {  
   int x;  
   int y;  
};  
  
value struct TraditionalDLL {  
   [DllImport("TraditionalDLL3.dll")]  
   static public double GetDistance(MLocation, MLocation);  
   [DllImport("TraditionalDLL3.dll")]  
   static public double InitLocation(MLocation*);  
};  
  
int main() {  
   MLocation loc1;  
   loc1.x = 0;  
   loc1.y = 0;  
  
   MLocation loc2;  
   loc2.x = 100;  
   loc2.y = 100;  
  
   double dist = TraditionalDLL::GetDistance(loc1, loc2);  
   Console::WriteLine("[managed] distance = {0}", dist);  
  
   MLocation loc3;  
   TraditionalDLL::InitLocation(&loc3);  
   Console::WriteLine("[managed] x={0} y={1}", loc3.x, loc3.y);  
}  
```  
  
```Output  
[unmanaged] loc1(0,0) loc2(100,100)  
[managed] distance = 141.42135623731  
[unmanaged] Initializing location...  
[managed] x=50 y=50  
```  
  
## <a name="see-also"></a>Consulte também  
 [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)