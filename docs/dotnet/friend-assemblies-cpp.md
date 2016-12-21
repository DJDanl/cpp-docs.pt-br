---
title: "Assemblies amig&#225;veis (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
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
  - "assemblies amigáveis, Visual C++"
ms.assetid: 8d55fee0-b7c2-4fbe-a23b-dfe424dc71cd
caps.latest.revision: 27
caps.handback.revision: 27
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assemblies amig&#225;veis (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Durante o tempo de execução aplicável, o recurso de linguagem assembly *de amigo* torna os tipos que estão no escopo do namespace ou no escopo global em um componente do assembly acessíveis para um ou mais assemblies de cliente ou .netmodules.  
  
## Todos os Tempos de Execução  
 **Comentários**  
  
 \(Esse recurso de idioma não tem suporte em todo o tempo de execução.\)  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Comentários**  
  
 \(Esse recurso de idioma não tem suporte em [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].\)  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Comentários**  
  
#### Para fazer tipos no namespace definir o escopo ou no escopo global em um componente do assembly acessível a um assembly do cliente ou a um .netmodule  
  
1.  No componente, especifique um atributo <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute>do assembly, e passe o nome do assembly cliente ou de .netmodule que acessarão tipos no escopo do namespace ou no escopo global no componente.  Você pode especificar vários assemblies do cliente ou o .netmodules especificando atributos adicionais.  
  
2.  No assembly cliente ou no .netmodule, quando você referenciar o assembly componente usando `#using`, o atributo de `as_friend` .  Se você especifica o atributo de `as_friend` para um assembly que não especifica `InternalsVisibleToAttribute`, uma exceção em tempo de execução será gerada se você tentar acessar um tipo no escopo do namespace ou no escopo global no componente.  
  
 Um erro de compilação ocorrerá se o assembly que contém o atributo de <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> não tiver um nome forte mas o cliente que o assembly que usa o atributo de `as_friend` faz.  
  
 Embora os tipos no namespace definir o escopo e o escopo global pode ser conhecido a um assembly do cliente ou a um .netmodule, a acessibilidade do membro ainda é aplicado.  Por exemplo, você não pode acessar um membro particular.  
  
 O acesso a qualquer em um assembly deve ser explicitamente concedido.  Por exemplo, o assembly que C não tem acesso a todos os tipos no assembly Para se o assembly C referencia o assembly B e o assembly B tem acesso a todos os tipos no assembly Para.  
  
 Para obter informações sobre como especificar a acessibilidade de tipos fora de um assembly, consulte [Visibilidade de tipo](../Topic/Type%20Visibility.md).  
  
 Para obter informações sobre como a sinal\- que é, como atribuir um nome forte do assembly que é criado usando o compilador do Visual C\+\+, consulte [Assemblies de nome forte \(assinatura de assembly\)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).  
  
 Como uma alternativa para usar assemblies recurso de amigo, você pode usar <xref:System.Security.Permissions.StrongNameIdentityPermission> para restringir o acesso aos tipos individuais.  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 O exemplo de código define um componente que especifica um assembly cliente que tenha acesso aos tipos no componente.  
  
```  
// friend_assemblies.cpp  
// compile by using: /clr /LD  
using namespace System::Runtime::CompilerServices;  
using namespace System;  
// an assembly attribute, not bound to a type  
[assembly:InternalsVisibleTo("friend_assemblies_2")];  
  
ref class Class1 {  
public:  
   void Test_Public() {  
      Console::WriteLine("Class1::Test_Public");  
   }  
};  
```  
  
 O exemplo de código a seguir acessa um privado no componente.  
  
```  
// friend_assemblies_2.cpp  
// compile by using: /clr  
#using "friend_assemblies.dll" as_friend  
  
int main() {  
   Class1 ^ a = gcnew Class1;  
   a->Test_Public();  
}  
```  
  
 **Saída**  
  
 `Class1::Test_Public`  
  
 O exemplo de código seguinte define um componente mas não especifica um assembly cliente que tenha acesso aos tipos no componente.  
  
 Observe que o componente está vinculado usando **\/opt:noref**.  Isso assegura que os tipos particulares emissão nos metadados do componente, que não é necessário quando o atributo de `InternalsVisibleTo` estiver presente.  Para obter mais informações, consulte [\/OPT \(Otimizações\)](../build/reference/opt-optimizations.md).  
  
```  
// friend_assemblies_3.cpp  
// compile by using: /clr /LD /link /opt:noref  
using namespace System;  
  
ref class Class1 {  
public:  
   void Test_Public() {  
      Console::WriteLine("Class1::Test_Public");  
   }  
};  
```  
  
 O exemplo de código define um cliente que as tentativas para acessar um privado digitação em um componente que não de acesso a seus tipos privados.  Devido ao comportamento de tempo de execução, se você quiser capturar a exceção, você deve tentar acessar um privado em uma função auxiliar.  
  
```  
// friend_assemblies_4.cpp  
// compile by using: /clr  
#using "friend_assemblies_3.dll" as_friend  
using namespace System;  
  
void Test() {  
   Class1 ^ a = gcnew Class1;  
}  
  
int main() {  
   // to catch this kind of exception, use a helper function  
   try {  
      Test();     
   }  
   catch(MethodAccessException ^ e) {  
      Console::WriteLine("caught an exception");  
   }  
}  
```  
  
 **Saída**  
  
 `caught an exception`  
  
 O próximo exemplo de código mostra como criar um componente de nome forte que especifica um assembly cliente que tenha acesso aos tipos no componente.  
  
```  
// friend_assemblies_5.cpp  
// compile by using: /clr /LD /link /keyfile:friend_assemblies.snk  
using namespace System::Runtime::CompilerServices;  
using namespace System;  
// an assembly attribute, not bound to a type  
  
[assembly:InternalsVisibleTo("friend_assemblies_6, PublicKey=00240000048000009400000006020000002400005253413100040000010001000bf45d77fd991f3bff0ef51af48a12d35699e04616f27ba561195a69ebd3449c345389dc9603d65be8cd1987bc7ea48bdda35ac7d57d3d82c666b7fc1a5b79836d139ef0ac8c4e715434211660f481612771a9f7059b9b742c3d8af00e01716ed4b872e6f1be0e94863eb5745224f0deaba5b137624d7049b6f2d87fba639fc5")];  
  
private ref class Class1 {  
public:  
   void Test_Public() {  
      Console::WriteLine("Class1::Test_Public");  
   }  
};  
```  
  
 Observe que o componente deve especificar a chave pública.  Nós sugerimos que você execute os seguintes comandos em sequência em um prompt de comando para criar um par de chaves e obter a chave pública:  
  
 **sn \-d friend\_assemblies.snk**  
  
 **sn \-k friend\_assemblies.snk**  
  
 **sn \-i friend\_assemblies.snk friend\_assemblies.snk**  
  
 **sn \-pc friend\_assemblies.snk key.publickey**  
  
 **sn \-tp key.publickey**  
  
 O exemplo de código a seguir acessa um privado no componente de nome forte.  
  
```  
// friend_assemblies_6.cpp  
// compile by using: /clr /link /keyfile:friend_assemblies.snk  
#using "friend_assemblies_5.dll" as_friend  
  
int main() {  
   Class1 ^ a = gcnew Class1;  
   a->Test_Public();  
}  
```  
  
 **Saída**  
  
 `Class1::Test_Public`  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)