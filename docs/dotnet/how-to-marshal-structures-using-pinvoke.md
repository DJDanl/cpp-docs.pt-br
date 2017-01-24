---
title: "Como realizar marshaling de estruturas usando PInvoke | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "realização de marshaling em dados [C++], estruturas"
  - "interoperabilidade [C++], estruturas"
  - "realização de marshaling [C++], estruturas"
  - "invocação de plataforma [C++], estruturas"
ms.assetid: 35997e6f-9251-4af3-8c6e-0712d64d6a5d
caps.latest.revision: 30
caps.handback.revision: 28
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de estruturas usando PInvoke
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este documento explica como as funções nativos que aceitam cadeias de caracteres de C \- estilo podem ser chamadas de funções gerenciadas que fornecem uma instância de <xref:System.String> usando P\/Invoke.  Embora recomendemos as que você use os recursos do C\+\+ Interoperabilidade em vez de P\/Invoke como P\/Invoke fornece vez relatório de erros de tempo de compilação, não é do tipo seguro, e pode ser fastidioso de implementá\-los, se a API não gerenciado é empacotado como uma DLL e o código\-fonte não estiverem disponíveis, P\/Invoke é a única opção.  Se não, consulte os seguintes documentos:  
  
-   [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)  
  
-   [How to: Marshal Structures Using PInvoke](../dotnet/how-to-marshal-structures-using-pinvoke.md)  
  
 Por padrão, o modo nativo e as estruturas gerenciados são apresentados diferentemente na memória, passando tão com êxito estruturas por limite gerenciados e não gerenciados requer etapas adicionais preservar a integridade de dados.  
  
 Este documento explica as etapas necessárias para definir equivalentes gerenciados de estruturas nativos e como as estruturas resultantes poderão ser passadas para funções não gerenciado.  Este documento assume que as estruturas simples — aquelas que não contêm cadeias de caracteres ou ponteiros — são usadas.  Para obter informações sobre a interoperabilidade non\-blittable, consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  P\/Invoke não pode ter tipos non\-blittable como um valor de retorno.  Os tipos blittables têm a mesma representação de gerenciado e em código não gerenciado.  Para obter mais informações, consulte [Tipos blittable e não blittable](../Topic/Blittable%20and%20Non-Blittable%20Types.md).  
  
 Marshaling estruturas simples, blittable por limite gerenciados e não gerenciados primeiro requer que as versões gerenciados de cada estrutura nativo estão definidas.  Essas estruturas podem ter qualquer nome válido; não há nenhuma relação entre o modo nativo e a versão gerenciado das duas estruturas diferentes de seu layout de dados.  Consequentemente, é vital que a versão gerenciado contém os campos que têm o mesmo tamanho e na mesma ordem que a versão nativo. \(Não há nenhum mecanismo para garantir que as versões gerenciados e nativos da estrutura sejam equivalentes, portanto incompatibilidades não será aparente até o tempo de execução.  É responsabilidade do programador assegurar que as duas estruturas tenham o mesmo layout de dados\).  
  
 Como os membros de estruturas gerenciados são reorganizados às vezes para fins de desempenho, é necessário usar o atributo de <xref:System.Runtime.InteropServices.StructLayoutAttribute> para indicar que a estrutura é apresentada em sequência.  Também é uma boa ideia definir explicitamente as caixas da estrutura que define para ser o mesmo que foi usado pela estrutura nativo. \(Embora por padrão, o Visual C\+\+ usa um estojo da estrutura de 8 bytes para ambos código gerenciado.\)  
  
1.  Em seguida, use <xref:System.Runtime.InteropServices.DllImportAttribute> declarar os pontos de entrada que correspondem a todas as funções gerenciado que não aceitarem a estrutura, mas usa a versão gerenciado de estrutura em assinaturas da função, que é um ponto central se você usar o mesmo nome para ambas as versões da estrutura.  
  
2.  Agora o código gerenciado pode passar a versão gerenciado da estrutura para as funções não gerenciados como se são realmente funções gerenciadas.  Essas estruturas podem ser passadas pelo valor ou por referência, como demonstrado no exemplo a seguir.  
  
## Exemplo  
 O código a seguir consiste em um módulo não gerenciado e gerenciado.  O módulo não gerenciado é uma DLL que define uma estrutura chamada Local e uma função chamada GetDistance que aceita duas instâncias da estrutura do local.  O segundo módulo é um aplicativo gerenciado de linha de comando que importa a função de GetDistance por fim, mas em termos de um equivalente gerenciado da estrutura de local, MLocation.  O mesmo nome será usado na prática provavelmente para ambas as versões da estrutura; no entanto, um nome diferente seja usado aqui para demonstrar que o protótipo de DllImport é definido em termos de versão gerenciado.  
  
 O módulo gerenciado é compilado com \/clr, mas trabalho de \/clr:pure também.  
  
 Observe que nenhuma parte da DLL está exposta ao código gerenciado usando a diretiva tradicional de \#include.  De fato, a DLL é acessado em tempo de execução, apenas assim que os problemas com as funções com DllImport importadas não serão detectados em tempo de compilação.  
  
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
  
## Exemplo  
  
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
  
  **loc1 \[\] não gerenciado \(0,0\) loc2 \(100.100\)**  
**distância gerenciado \[\] \= 141,42135623731**  
**\[\] não gerenciados inicializando o local…**  
**x\=50 gerenciado \[\] y\=50**   
## Consulte também  
 [Usando PInvoke explícito em C\+\+ \(atributo DllImport\)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)