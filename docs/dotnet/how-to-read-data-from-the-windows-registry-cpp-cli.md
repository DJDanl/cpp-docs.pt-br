---
title: "Como ler dados a partir do Registro do Windows (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "registro, lendo"
  - "Visual C++, lendo a partir do Registro do Windows"
ms.assetid: aebf52c0-acc7-40e2-adbc-d34e0a1e467e
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como ler dados a partir do Registro do Windows (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código usa a chave de <xref:Microsoft.Win32.Registry.CurrentUser> para ler dados do Registro do Windows.  Primeiro, a subchaves são enumeradas usando o método de <xref:Microsoft.Win32.RegistryKey.GetSubKeyNames%2A> e a subchave de identidades é aberta em usando o método de <xref:Microsoft.Win32.RegistryKey.OpenSubKey%2A> .  Como as chaves raiz, cada subchave é representada pela classe de <xref:Microsoft.Win32.RegistryKey> .  Finalmente, o novo objeto de <xref:Microsoft.Win32.RegistryKey> é usada para enumerar os pares de chave\/valor.  
  
## Exemplo  
  
### Código  
  
```  
// registry_read.cpp  
// compile with: /clr  
using namespace System;  
using namespace Microsoft::Win32;  
  
int main( )  
{  
   array<String^>^ key = Registry::CurrentUser->GetSubKeyNames( );  
  
   Console::WriteLine("Subkeys within CurrentUser root key:");  
   for (int i=0; i<key->Length; i++)  
   {  
      Console::WriteLine("   {0}", key[i]);  
   }  
  
   Console::WriteLine("Opening subkey 'Identities'...");  
   RegistryKey^ rk = nullptr;  
   rk = Registry::CurrentUser->OpenSubKey("Identities");  
   if (rk==nullptr)  
   {  
      Console::WriteLine("Registry key not found - aborting");  
      return -1;  
   }  
  
   Console::WriteLine("Key/value pairs within 'Identities' key:");  
   array<String^>^ name = rk->GetValueNames( );  
   for (int i=0; i<name->Length; i++)  
   {  
      String^ value = rk->GetValue(name[i])->ToString();  
      Console::WriteLine("   {0} = {1}", name[i], value);  
   }  
  
   return 0;  
}  
```  
  
## Comentários  
 A classe de <xref:Microsoft.Win32.Registry> é meramente um contêiner para instâncias estáticos de <xref:Microsoft.Win32.RegistryKey>.  Cada instância de representar um nó de Registro raiz.  As instâncias são <xref:Microsoft.Win32.Registry.ClassesRoot>, <xref:Microsoft.Win32.Registry.CurrentConfig>, <xref:Microsoft.Win32.Registry.CurrentUser>, <xref:Microsoft.Win32.Registry.LocalMachine>, e <xref:Microsoft.Win32.Registry.Users>.  
  
 Além de ser estáticos, os objetos dentro da classe de <xref:Microsoft.Win32.Registry> são somente leitura.  Além disso, as instâncias de <xref:Microsoft.Win32.RegistryKey> classificação que são criadas para acessar o conteúdo do Registro são somente leitura também.  Para obter um exemplo de como substituir esse comportamento, consulte [Como gravar dados no Registro do Windows](../dotnet/how-to-write-data-to-the-windows-registry-cpp-cli.md).  
  
 Há dois objetos adicionais na classe de <xref:Microsoft.Win32.Registry> : <xref:Microsoft.Win32.Registry.DynData> e <xref:Microsoft.Win32.Registry.PerformanceData>.  Ambas forem instâncias de classe de <xref:Microsoft.Win32.RegistryKey> .  O objeto de <xref:Microsoft.Win32.Registry.DynData> contém informações de Registro dinâmico, que só tem suporte no Windows 98 e no Windows Me.  O objeto de <xref:Microsoft.Win32.Registry.PerformanceData> pode ser usado para acessar informações do contador de desempenho de aplicativos que usam o sistema de monitoramento de desempenho do windows.  O nó de <xref:Microsoft.Win32.Registry.PerformanceData> representa informações que realmente não é armazenada no Registro e não pode ser exibida em virtude disso usando Regedit.exe.  
  
## Consulte também  
 [Como gravar dados no Registro do Windows](../dotnet/how-to-write-data-to-the-windows-registry-cpp-cli.md)   
 [Operações do Windows](../dotnet/windows-operations-cpp-cli.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)