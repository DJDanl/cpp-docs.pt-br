---
title: 'Como: chamar DLLs nativas de código gerenciado usando PInvoke | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- platform invoke [C++], calling native DLLs
- interop [C++], calling native DLLs
- marshaling [C++], calling native DLLs
- data marshaling [C++], calling native DLLs
ms.assetid: 3273eb4b-38d1-4619-92a6-71bda542be72
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c1e3d9d3d08ef0386a1ab85e0e5b6860f5d504cc
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43681275"
---
# <a name="how-to-call-native-dlls-from-managed-code-using-pinvoke"></a>Como chamar DLLs nativas a partir do código gerenciado usando PInvoke
Funções que são implementadas em DLLs não gerenciadas podem ser chamadas de código gerenciado usando a funcionalidade de invocação de plataforma (P/Invoke). Se o código-fonte para a DLL não estiver disponível, o P/Invoke é a única opção para interoperação. No entanto, ao contrário de outras linguagens .NET, Visual C++ fornece uma alternativa para P/Invoke. Para obter mais informações, consulte [usando Interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo de código a seguir usa o Win32 [GetSystemMetrics](/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) função para recuperar a resolução atual da tela em pixels.  
  
 Para as funções que usam somente tipos intrínsecos como argumentos e valores de retorno, não é necessário nenhum trabalho extra. Outros tipos de dados, como ponteiros de função, matrizes e estruturas, exigem atributos adicionais para garantir que o marshaling de dados apropriados.  
  
 Embora não seja necessário, é uma boa prática fazer membros estáticos de declarações de P/Invoke de uma classe de valor para que eles não existem no namespace global, conforme demonstrado neste exemplo.  
  
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