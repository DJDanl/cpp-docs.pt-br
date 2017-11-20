---
title: 'Como: gravar dados no registro do Windows (C + + CLI) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- registry, writing to
- Visual C++, writing to Windows Registry
ms.assetid: 3d40b978-4baa-4779-bfe3-47e2917b757f
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 8bb95ab9a70fd0144256f85d3fae6ccc3c034c1c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-write-data-to-the-windows-registry-ccli"></a>Como gravar dados no Registro do Windows (C++/CLI)
O seguinte exemplo de código usa o <xref:Microsoft.Win32.Registry.CurrentUser> chave para criar uma instância gravável do <xref:Microsoft.Win32.RegistryKey> classe correspondente para o **Software** chave. O <xref:Microsoft.Win32.RegistryKey.CreateSubKey%2A> método é usado para criar uma nova chave e adicionar pares de chave/valor.  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
  
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
  
## <a name="remarks"></a>Comentários  
 Você pode usar o .NET Framework para acessar o registro com o <xref:Microsoft.Win32.Registry> e [RegistryKey](https://msdn.microsoft.com/en-us/library/microsoft.win32.registrykey.aspx) classes, que são definidos no <xref:Microsoft.Win32> namespace. O **registro** classe é um contêiner para instâncias estáticos de <xref:Microsoft.Win32.RegistryKey> classe. Cada instância representa um nó de raiz do registro. As instâncias são <xref:Microsoft.Win32.Registry.ClassesRoot>, <xref:Microsoft.Win32.Registry.CurrentConfig>, <xref:Microsoft.Win32.Registry.CurrentUser>, <xref:Microsoft.Win32.Registry.LocalMachine>, e <xref:Microsoft.Win32.Registry.Users>.  
  
## <a name="see-also"></a>Consulte também  
 [Como: ler dados do registro do Windows (C + + CLI)](../dotnet/how-to-read-data-from-the-windows-registry-cpp-cli.md)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)