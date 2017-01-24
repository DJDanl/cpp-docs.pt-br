---
title: "Como chamar DLLs nativas a partir do c&#243;digo gerenciado usando PInvoke | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "realização de marshaling em dados [C++], chamando DLLs nativas"
  - "interoperabilidade [C++], chamando DLLs nativas"
  - "realização de marshaling [C++], chamando DLLs nativas"
  - "invocação de plataforma [C++], chamando DLLs nativas"
ms.assetid: 3273eb4b-38d1-4619-92a6-71bda542be72
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como chamar DLLs nativas a partir do c&#243;digo gerenciado usando PInvoke
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções que são implementadas na DLL não gerenciado podem ser chamadas de código gerenciado usando a funcionalidade de invocação de plataforma \(P\/Invoke\).  Se o código\-fonte do DLL não estiver disponível, P\/Invoke é a única opção para interoperar.  No entanto, diferentemente de outras linguagens .NET, Visual C\+\+ fornece uma alternativa a P\/Invoke.  Para obter mais informações, consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
## Exemplo  
 O exemplo de código usa a função do Win32 [GetSystemMetrics](http://msdn.microsoft.com/library/windows/desktop/ms724385) para recuperar a resolução atual da tela em pixels.  
  
 Para as funções que usam somente tipos intrínsecos como argumentos e valores de retorno, nenhum trabalho adicional é necessário.  Outros tipos de dados, como ponteiros da função, matrizes, e estruturas, requerem atributos adicionais garantir o marshaling de dados apropriada.  
  
 Embora não se exija, uma boa prática fazer a declarações de P\/Invoke membros estáticos de um valor de classificação para que não existem no namespace global, conforme mostrado neste exemplo.  
  
```  
// pinvoke_basic.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
value class Win32 {  
public:  
   [DllImport("User32.dll")]  
   static int GetSystemMetrics(int);  
  
   enum class SystemMetricIndex {  
      // Same values as those defined in winuser.h.  
      SM_CXSCREEN = 0,  
      SM_CYSCREEN = 1  
   };  
};  
  
int main() {  
   int hRes = Win32::GetSystemMetrics( safe_cast<int>(Win32::SystemMetricIndex::SM_CXSCREEN) );  
   int vRes = Win32::GetSystemMetrics( safe_cast<int>(Win32::SystemMetricIndex::SM_CYSCREEN) );  
   Console::WriteLine("screen resolution: {0},{1}", hRes, vRes);  
}  
```  
  
## Consulte também  
 [Usando PInvoke explícito em C\+\+ \(atributo DllImport\)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)