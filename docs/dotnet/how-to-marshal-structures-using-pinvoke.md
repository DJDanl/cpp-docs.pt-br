---
title: Como realizar marshaling de estruturas usando PInvoke
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- data marshaling [C++], structures
- platform invoke [C++], structures
- interop [C++], structures
- marshaling [C++], structures
ms.assetid: 35997e6f-9251-4af3-8c6e-0712d64d6a5d
ms.openlocfilehash: fe5d2cf4804baea286827e9d5e270c10cd587b30
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988447"
---
# <a name="how-to-marshal-structures-using-pinvoke"></a>Como realizar marshaling de estruturas usando PInvoke

Este documento explica como as funções nativas que aceitam structs de estilo C podem ser chamadas de funções gerenciadas usando P/Invoke. Embora seja recomendável usar os C++ recursos de interoperabilidade em vez de p/Invoke porque p/invoke fornece pouco relatório de erros de tempo de compilação, não é de tipo seguro e pode ser entediante de implementar, se a API não gerenciada for empacotada como uma dll e o código-fonte não estiver disponível, P/Invoke será a única opção. Caso contrário, consulte os seguintes documentos:

- [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)

- [Como realizar marshaling de cadeias de caracteres usando PInvoke](../dotnet/how-to-marshal-strings-using-pinvoke.md)

Por padrão, estruturas nativas e gerenciadas são dispostas de forma diferente na memória, portanto, passar as estruturas com êxito pelo limite gerenciado/não gerenciado requer etapas adicionais para preservar a integridade dos dados.

Este documento explica as etapas necessárias para definir equivalentes gerenciados de estruturas nativas e como as estruturas resultantes podem ser passadas para funções não gerenciadas. Este documento pressupõe que estruturas simples, que não contêm cadeias de caracteres ou ponteiros, são usadas. Para obter informações sobre a interoperabilidade não blittable, [consulte C++ usando a interoperabilidade (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md). P/Invoke não pode ter tipos não blittable como um valor de retorno. Os tipos blittable têm a mesma representação em código gerenciado e não gerenciado. Para obter mais informações, consulte [tipos blittable e non-blittable](/dotnet/framework/interop/blittable-and-non-blittable-types).

O marshaling de estruturas simples e blittable no limite gerenciado/não gerenciado primeiro exige que as versões gerenciadas de cada estrutura nativa sejam definidas. Essas estruturas podem ter qualquer nome legal; Não há nenhuma relação entre a versão nativa e a gerenciada das duas estruturas além de seu layout de dados. Portanto, é vital que a versão gerenciada contenha campos que tenham o mesmo tamanho e na mesma ordem que a versão nativa. (Não há nenhum mecanismo para garantir que as versões gerenciadas e nativas da estrutura sejam equivalentes, portanto, as incompatibilidades não ficarão aparentes até o tempo de execução. É responsabilidade do programador garantir que as duas estruturas tenham o mesmo layout de dados.)

Como os membros de estruturas gerenciadas, às vezes, são reorganizados para fins de desempenho, é necessário usar o atributo <xref:System.Runtime.InteropServices.StructLayoutAttribute> para indicar que a estrutura é disposta em sequência. Também é uma boa ideia definir explicitamente a configuração de empacotamento de estrutura como a mesma usada pela estrutura nativa. (Embora por padrão, o C++ visual usa uma embalagem de estrutura de 8 bytes para o código gerenciado.)

1. Em seguida, use <xref:System.Runtime.InteropServices.DllImportAttribute> para declarar pontos de entrada que correspondam a quaisquer funções não gerenciadas que aceitem a estrutura, mas use a versão gerenciada da estrutura nas assinaturas de função, que é um ponto de sentido se você usar o mesmo nome para ambas as versões da estrutura.

1. Agora, o código gerenciado pode passar a versão gerenciada da estrutura para as funções não gerenciadas, como se fossem realmente funções gerenciadas. Essas estruturas podem ser passadas por valor ou por referência, conforme demonstrado no exemplo a seguir.

## <a name="example"></a>Exemplo

O código a seguir consiste em um módulo não gerenciado e um gerenciado. O módulo não gerenciado é uma DLL que define uma estrutura chamada local e uma função chamada GetDistance que aceita duas instâncias da estrutura de local. O segundo módulo é um aplicativo de linha de comando gerenciado que importa a função GetDistance, mas a define em termos de um equivalente gerenciado da estrutura de local, MLocation. Na prática, o mesmo nome provavelmente seria usado para ambas as versões da estrutura; no entanto, um nome diferente é usado aqui para demonstrar que o protótipo DllImport é definido em termos da versão gerenciada.

Observe que nenhuma parte da DLL é exposta ao código gerenciado usando a diretiva de #include tradicional. Na verdade, a DLL é acessada somente em tempo de execução, de modo que os problemas com funções importadas com DllImport não serão detectados no momento da compilação.

```cpp
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

```cpp
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
