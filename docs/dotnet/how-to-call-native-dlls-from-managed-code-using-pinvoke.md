---
title: "Como: chamar DLLs nativas a partir do código gerenciado usando PInvoke | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords:
- platform invoke [C++], calling native DLLs
- interop [C++], calling native DLLs
- marshaling [C++], calling native DLLs
- data marshaling [C++], calling native DLLs
ms.assetid: 3273eb4b-38d1-4619-92a6-71bda542be72
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 5d22f493a582b6ef09615f94c7b321a7cc535e5b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-call-native-dlls-from-managed-code-using-pinvoke"></a>Como chamar DLLs nativas a partir do código gerenciado usando PInvoke
Funções que são implementadas em DLLs não gerenciados podem ser chamadas de código gerenciado usando a funcionalidade de invocação de plataforma (P/Invoke). Se o código-fonte para a DLL não estiver disponível, o P/Invoke é a única opção para interoperar. No entanto, ao contrário de outras linguagens .NET, o Visual C++ fornece uma alternativa para P/Invoke. Para obter mais informações, consulte [usando Interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo de código a seguir usa o Win32 [GetSystemMetrics](http://msdn.microsoft.com/library/windows/desktop/ms724385) função para recuperar a resolução atual da tela em pixels.  
  
 Para funções que usam somente tipos intrínsecos como argumentos e valores de retorno, nenhum trabalho adicional é necessário. Outros tipos de dados, como ponteiros de função, matrizes e estruturas, exigem atributos adicionais para garantir a realização de marshaling de dados apropriados.  
  
 Embora não seja necessário, é uma boa prática fazer membros estáticos de declarações de P/Invoke de uma classe de valor para que eles não existem no namespace global, conforme demonstrado no exemplo.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)