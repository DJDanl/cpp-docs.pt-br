---
title: "Como diagnosticar e corrigir problemas de compatibilidade do assembly (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "compatibilidade, entre assemblies"
  - "exceções, diagnosticando comportamento antigo"
  - "controle de versão"
  - "controle de versão, diagnosticando conflitos"
ms.assetid: 297c71e3-04a8-4d24-a5dc-b04a2c5cc6fb
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como diagnosticar e corrigir problemas de compatibilidade do assembly (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico explica o que pode ocorrer quando a versão de um assembly referenciado em tempo de compilação não corresponde à versão do assembly referenciado em tempo de execução, e como evitar o problema.  
  
 Quando um assembly é criado, outros assemblies podem ser referenciados com a sintaxe de `#using` .  Durante a compilação, esses assemblies são acessados pelo compilador.  Informações desses assemblies é usada para tomar decisões de otimização.  
  
 No entanto, se o assembly referenciado é alterado e recompilado, e não recompile o assembly de referência que é dependente nele, os assemblies não podem ainda ser compatível.  As decisões de otimização que eram válidos no início não podem estar corretas no que diz respeito a nova versão do assembly.  Vários erros de tempo de execução podem ocorrer devido a essas incompatibilidades.  Não há nenhuma exceção específica que será gerada nesses casos.  A maneira como a falha será relatada em tempo de execução depende da natureza de alteração de código que causou o problema.  
  
 Esses erros não devem ser um problema no código de produção final como o aplicativo inteiro é recriado para a versão lançada do produto.  Os assemblies que são liberados no utilitário devem ser marcados com um número de versão oficial, que garante que esses problemas sejam evitados.  Para obter mais informações, consulte [Controle de versão de assemblies](../Topic/Assembly%20Versioning.md).  
  
### Diagnosticar e corrigir um erro de incompatibilidade  
  
1.  Se você encontrar exceções em tempo de execução ou outras condições de erro que ocorrem no código que faz referência a outro assembly, e tem a nenhuma outra causa identificada, você pode controlar um assembly expirado.  
  
2.  Primeiro, o isolado e reproduz a exceção ou outra condição de erro.  Um problema que ocorre devido a uma exceção desatualizada deve ser reprodutível.  
  
3.  Verifique o carimbo de data\/hora de todos os assemblies referenciados em seu aplicativo.  
  
4.  Se os carimbos de data\/hora de quaisquer assemblies referenciados serão posterior ao carimbo de data\/hora de criação do último seu aplicativo, então o seu aplicativo estiver expirado.  Se isso ocorrer, recompilar o aplicativo ao assembly o mais recente, e faça as alterações de código necessárias.  
  
5.  Executar novamente o aplicativo, execute as etapas que reproduzem o problema, e verifica se a exceção não ocorra.  
  
## Exemplo  
 O programa seguir ilustra o problema reduzindo a acessibilidade de um método, e tentando acessar esse método em outro assembly sem recompilação.  Tentativa de criar `changeaccess.cpp` primeiro.  Este é o assembly referenciado que mudará.  Em seguida `referencing.cpp`.  A compilação tiver êxito.  Agora, reduza a acessibilidade do método chamado.  Recompilar `changeaccess.cpp` com o sinalizador `/DCHANGE_ACCESS`.  Isso torna o método protegido, em vez de particular, o que pode levar mais tempo ser chamado legalmente.  Sem recompilar `referencing.exe`, execute novamente o aplicativo.  <xref:System.MethodAccessException> ocorrerá uma exceção.  
  
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
  
## Consulte também  
 [Diretiva \#using](../preprocessor/hash-using-directive-cpp.md)   
 [Tipos gerenciados](../Topic/Managed%20Types%20\(C++-CLI\).md)