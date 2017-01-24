---
title: "Como gravar dados no Registro do Windows (C++/CLI) | Microsoft Docs"
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
  - "registro, gravando em"
  - "Visual C++, gravando no Registro do Windows"
ms.assetid: 3d40b978-4baa-4779-bfe3-47e2917b757f
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como gravar dados no Registro do Windows (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código usa a chave de <xref:Microsoft.Win32.Registry.CurrentUser> para criar uma instância gravável da classe de <xref:Microsoft.Win32.RegistryKey> que corresponde à chave de **Software** .  O método de <xref:Microsoft.Win32.RegistryKey.CreateSubKey%2A> é usado para criar uma nova chave e adicioná\-la aos pares de chave\/valor.  
  
## Exemplo  
  
### Código  
  
```  
// registry_write.cpp  
// compile with: /clr  
using namespace System;  
using namespace Microsoft::Win32;  
  
int main()  
{  
   // The second OpenSubKey argument indicates that  
   // the subkey should be writable.   
   RegistryKey^ rk;  
   rk  = Registry::CurrentUser->OpenSubKey("Software", true);  
   if (!rk)  
   {  
      Console::WriteLine("Failed to open CurrentUser/Software key");  
      return -1;  
   }  
  
   RegistryKey^ nk = rk->CreateSubKey("NewRegKey");  
   if (!nk)  
   {  
      Console::WriteLine("Failed to create 'NewRegKey'");  
      return -1;  
   }  
  
   String^ newValue = "NewValue";  
   try  
   {  
      nk->SetValue("NewKey", newValue);  
      nk->SetValue("NewKey2", 44);  
   }  
   catch (Exception^)  
   {  
      Console::WriteLine("Failed to set new values in 'NewRegKey'");  
      return -1;  
   }  
  
   Console::WriteLine("New key created.");  
   Console::Write("Use REGEDIT.EXE to verify ");  
   Console::WriteLine("'CURRENTUSER/Software/NewRegKey'\n");  
   return 0;  
}  
```  
  
## Comentários  
 Você pode usar o.NET Framework para acessar o Registro com as classes de <xref:Microsoft.Win32.Registry> e de [RegistryKey](https://msdn.microsoft.com/en-us/library/microsoft.win32.registrykey.aspx) , que ambas são definidas no namespace de <xref:Microsoft.Win32> .  A classe de **Registro** é um contêiner para instâncias estáticos da classe de <xref:Microsoft.Win32.RegistryKey> .  Cada instância de representar um nó de Registro raiz.  As instâncias são <xref:Microsoft.Win32.Registry.ClassesRoot>, <xref:Microsoft.Win32.Registry.CurrentConfig>, <xref:Microsoft.Win32.Registry.CurrentUser>, <xref:Microsoft.Win32.Registry.LocalMachine>, e <xref:Microsoft.Win32.Registry.Users>.  
  
## Consulte também  
 [Como ler dados a partir do Registro do Windows](../dotnet/how-to-read-data-from-the-windows-registry-cpp-cli.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)