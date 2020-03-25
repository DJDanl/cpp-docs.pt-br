---
title: appdomain
ms.date: 11/04/2016
f1_keywords:
- appdomain_cpp
helpviewer_keywords:
- appdomain __declspec keyword
- __declspec keyword [C++], appdomain
ms.assetid: 29d843cb-cb6b-4d1b-a48d-d928a877234d
ms.openlocfilehash: 7ac74e8774204b316712a15975f7af3fb8835a9e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181480"
---
# <a name="appdomain"></a>appdomain

Especifica que cada domínio de seu aplicativo gerenciado deve ter sua própria cópia de uma variável global específica ou variável de membro estático. Consulte [domínios de aplicativo e C++ Visual](../dotnet/application-domains-and-visual-cpp.md) para obter mais informações.

Cada domínio de aplicativo tem sua própria cópia de uma variável per-appdomain. Um construtor de uma variável appdomain é executado quando um assembly é carregado em um domínio de aplicativo, e o destruidor é executado quando o domínio de aplicativo é descarregado.

Se você quiser que todos os domínios de aplicativo em um processo no Common Language Runtime compartilhem uma variável global, use o modificador `__declspec(process)`. `__declspec(process)` está em vigor por padrão em [/CLR](../build/reference/clr-common-language-runtime-compilation.md). As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

`__declspec(appdomain)` só é válida quando uma das opções do compilador **/CLR** é usada. Somente uma variável global, uma variável de membro estática ou uma variável local estática pode ser marcada com `__declspec(appdomain)`. É um erro aplicar `__declspec(appdomain)` a membros estáticos de tipos gerenciados porque eles sempre têm esse comportamento.

O uso de `__declspec(appdomain)` é semelhante ao uso [do armazenamento local de threads (TLS)](../parallel/thread-local-storage-tls.md). Os threads têm seu próprio armazenamento, assim como os domínios de aplicativo. Usar `__declspec(appdomain)` garante que a variável global tenha seu próprio armazenamento em cada domínio de aplicativo criado para esse aplicativo.

Há limitações para misturar o uso de por processo e por variáveis de AppDomain; consulte [processo](../cpp/process.md) para obter mais informações.

Por exemplo, na inicialização do programa, todas as variáveis per-process são inicializadas, depois todas as variáveis per-appdomain são inicializadas. Portanto, quando uma variável per-process está sendo inicializada, ela não pode depender do valor de qualquer variável de domínio per-appdomain. Não é uma boa prática combinar o uso (a atribuição) de variáveis per-appdomain e per-process.

Para obter informações sobre como chamar uma função em um domínio de aplicativo específico, consulte [Call_in_appdomain função](../dotnet/call-in-appdomain-function.md).

## <a name="example"></a>Exemplo

```cpp
// declspec_appdomain.cpp
// compile with: /clr
#include <stdio.h>
using namespace System;

class CGlobal {
public:
   CGlobal(bool bProcess) {
      Counter = 10;
      m_bProcess = bProcess;
      Console::WriteLine("__declspec({0}) CGlobal::CGlobal constructor", m_bProcess ? (String^)"process" : (String^)"appdomain");
   }

   ~CGlobal() {
      Console::WriteLine("__declspec({0}) CGlobal::~CGlobal destructor", m_bProcess ? (String^)"process" : (String^)"appdomain");
   }

   int Counter;

private:
   bool m_bProcess;
};

__declspec(process) CGlobal process_global = CGlobal(true);
__declspec(appdomain) CGlobal appdomain_global = CGlobal(false);

value class Functions {
public:
   static void change() {
      ++appdomain_global.Counter;
   }

   static void display() {
      Console::WriteLine("process_global value in appdomain '{0}': {1}",
         AppDomain::CurrentDomain->FriendlyName,
         process_global.Counter);

      Console::WriteLine("appdomain_global value in appdomain '{0}': {1}",
         AppDomain::CurrentDomain->FriendlyName,
         appdomain_global.Counter);
   }
};

int main() {
   AppDomain^ defaultDomain = AppDomain::CurrentDomain;
   AppDomain^ domain = AppDomain::CreateDomain("Domain 1");
   AppDomain^ domain2 = AppDomain::CreateDomain("Domain 2");
   CrossAppDomainDelegate^ changeDelegate = gcnew CrossAppDomainDelegate(&Functions::change);
   CrossAppDomainDelegate^ displayDelegate = gcnew CrossAppDomainDelegate(&Functions::display);

   // Print the initial values of appdomain_global in all appdomains.
   Console::WriteLine("Initial value");
   defaultDomain->DoCallBack(displayDelegate);
   domain->DoCallBack(displayDelegate);
   domain2->DoCallBack(displayDelegate);

   // Changing the value of appdomain_global in the domain and domain2
   // appdomain_global value in "default" appdomain remain unchanged
   process_global.Counter = 20;
   domain->DoCallBack(changeDelegate);
   domain2->DoCallBack(changeDelegate);
   domain2->DoCallBack(changeDelegate);

   // Print values again
   Console::WriteLine("Changed value");
   defaultDomain->DoCallBack(displayDelegate);
   domain->DoCallBack(displayDelegate);
   domain2->DoCallBack(displayDelegate);

   AppDomain::Unload(domain);
   AppDomain::Unload(domain2);
}
```

```Output
__declspec(process) CGlobal::CGlobal constructor
__declspec(appdomain) CGlobal::CGlobal constructor
Initial value
process_global value in appdomain 'declspec_appdomain.exe': 10
appdomain_global value in appdomain 'declspec_appdomain.exe': 10
__declspec(appdomain) CGlobal::CGlobal constructor
process_global value in appdomain 'Domain 1': 10
appdomain_global value in appdomain 'Domain 1': 10
__declspec(appdomain) CGlobal::CGlobal constructor
process_global value in appdomain 'Domain 2': 10
appdomain_global value in appdomain 'Domain 2': 10
Changed value
process_global value in appdomain 'declspec_appdomain.exe': 20
appdomain_global value in appdomain 'declspec_appdomain.exe': 10
process_global value in appdomain 'Domain 1': 20
appdomain_global value in appdomain 'Domain 1': 11
process_global value in appdomain 'Domain 2': 20
appdomain_global value in appdomain 'Domain 2': 12
__declspec(appdomain) CGlobal::~CGlobal destructor
__declspec(appdomain) CGlobal::~CGlobal destructor
__declspec(appdomain) CGlobal::~CGlobal destructor
__declspec(process) CGlobal::~CGlobal destructor
```

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
