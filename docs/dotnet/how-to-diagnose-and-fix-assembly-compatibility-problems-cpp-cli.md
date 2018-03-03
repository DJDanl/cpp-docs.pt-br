---
title: 'Como: diagnosticar e corrigir problemas de compatibilidade do Assembly (C + + CLI) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- versioning, diagnosing conflicts
- versioning
- exceptions, diagnosing odd behavior
- compatibility, between assemblies
ms.assetid: 297c71e3-04a8-4d24-a5dc-b04a2c5cc6fb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: a175705bd5d303187a11bf3e7779669a3a30e483
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-diagnose-and-fix-assembly-compatibility-problems-ccli"></a>Como diagnosticar e corrigir problemas de compatibilidade do assembly (C++/CLI)
Este tópico explica o que pode acontecer quando a versão de um assembly referenciado em tempo de compilação não corresponde à versão do assembly referenciado em tempo de execução e como evitar o problema.  
  
 Quando um assembly é compilado, outros assemblies podem ser referenciados com o `#using` sintaxe. Durante a compilação, esses assemblies são acessados pelo compilador. Informações desses assemblies são usadas para tomar decisões de otimização.  
  
 No entanto, se o assembly referenciado é alterado e recompilado, e você não recompilar o assembly de referência que depende dele, os assemblies podem não ser ainda compatível. As decisões de otimização que eram válidas no primeiro podem não estar corretas em relação a nova versão do assembly. Vários erros de tempo de execução poderão ocorrer devido a essas incompatibilidades. Não há nenhuma exceção específica que será produzida em tais casos. A maneira como a falha será relatada em tempo de execução depende da natureza da alteração de código que causou o problema.  
  
 Esses erros não devem ser um problema no seu código de produção final desde que o aplicativo inteiro será recriado para a versão de lançamento do produto. Assemblies que são lançados para o público devem ser marcados com um número de versão oficial, que garante que esses problemas serão evitados. Para obter mais informações, consulte [Controle de versão do assembly](/dotnet/framework/app-domains/assembly-versioning).  
  
### <a name="diagnosing-and-fixing-an-incompatibility-error"></a>Diagnosticar e corrigir um erro de incompatibilidade  
  
1.  Se você encontrar exceções de tempo de execução ou outras condições de erro que ocorrem no código que faz referência a outro conjunto e nenhum outro provocaram identificado, você pode lidar com um assembly desatualizado.  
  
2.  Primeiro, isolar e reproduzir a exceção ou outra condição de erro. Um problema que ocorre devido a uma exceção desatualizada deve ser reproduzido.  
  
3.  Verifique se o carimbo de hora de qualquer assembly referenciado em seu aplicativo.  
  
4.  Se os carimbos de hora de todos os assemblies referenciados são posteriores ao que o carimbo de hora da última compilação do seu aplicativo, seu aplicativo está desatualizado. Nesse caso, recompilar o aplicativo com o assembly mais recente e fazer as alterações de código necessárias.  
  
5.  Execute novamente o aplicativo, execute as etapas que reproduza o problema e verifique se a exceção não ocorrerá.  
  
## <a name="example"></a>Exemplo  
 O programa a seguir ilustra o problema, reduzindo a acessibilidade de um método e tentar acessar esse método em outro assembly sem recompilar. Tente compilar `changeaccess.cpp` primeiro. Este é o assembly referenciado que será alterado. Em seguida, compile `referencing.cpp`. A compilação for bem-sucedida. Agora, reduza a acessibilidade do método chamado. Recompilar `changeaccess.cpp` com o sinalizador `/DCHANGE_ACCESS`. Isso torna o método protegido, em vez de particular, para que mais pode ser chamado legal. Sem recompilar `referencing.exe`, execute novamente o aplicativo. Uma exceção <xref:System.MethodAccessException> resultará.  
  
```  
// changeaccess.cpp  
// compile with: /clr:safe /LD  
// After the initial compilation, add /DCHANGE_ACCESS and rerun  
// referencing.exe to introduce an error at runtime. To correct  
// the problem, recompile referencing.exe  
  
public ref class Test {  
#if defined(CHANGE_ACCESS)  
protected:  
#else  
public:  
#endif  
  
  int access_me() {  
    return 0;  
  }  
  
};  
  
```  
  
```  
// referencing.cpp  
// compile with: /clr:safe   
#using <changeaccess.dll>  
  
// Force the function to be inline, to override the compiler's own  
// algorithm.  
__forceinline  
int CallMethod(Test^ t) {  
  // The call is allowed only if access_me is declared public  
  return t->access_me();  
}  
  
int main() {  
  Test^ t = gcnew Test();  
  try  
  {  
    CallMethod(t);  
    System::Console::WriteLine("No exception.");  
  }  
  catch (System::Exception ^ e)  
  {  
    System::Console::WriteLine("Exception!");  
  }  
  return 0;  
}  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [#using diretiva](../preprocessor/hash-using-directive-cpp.md)   
 [Tipos gerenciados (C++/CLI)](../dotnet/managed-types-cpp-cli.md)