---
title: 'Como: ler dados do registro do Windows (C + + CLI) | Microsoft Docs'
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
- Visual C++, reading from Windows Registry
- registry, reading
ms.assetid: aebf52c0-acc7-40e2-adbc-d34e0a1e467e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: dfb654ba2cce069086713322624e947e14bc26f4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-read-data-from-the-windows-registry-ccli"></a>Como ler dados a partir do Registro do Windows (C++/CLI)
O seguinte exemplo de código usa o <xref:Microsoft.Win32.Registry.CurrentUser> chave para ler dados de registro do Windows. Primeiro, as subchaves são enumeradas usando o <xref:Microsoft.Win32.RegistryKey.GetSubKeyNames%2A> método e, em seguida, a subchave de identidades é aberto usando o <xref:Microsoft.Win32.RegistryKey.OpenSubKey%2A> método. Como as chaves de raiz, cada subchave é representado pela <xref:Microsoft.Win32.RegistryKey> classe. Por fim, o novo <xref:Microsoft.Win32.RegistryKey> objeto é usado para enumerar os pares chave/valor.  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
  
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
  
## <a name="remarks"></a>Comentários  
 O <xref:Microsoft.Win32.Registry> classe é simplesmente um contêiner para instâncias estáticos do <xref:Microsoft.Win32.RegistryKey>. Cada instância representa um nó de raiz do registro. As instâncias são <xref:Microsoft.Win32.Registry.ClassesRoot>, <xref:Microsoft.Win32.Registry.CurrentConfig>, <xref:Microsoft.Win32.Registry.CurrentUser>, <xref:Microsoft.Win32.Registry.LocalMachine>, e <xref:Microsoft.Win32.Registry.Users>.  
  
 Além de ser estático, os objetos dentro de <xref:Microsoft.Win32.Registry> classe são somente leitura. Além disso, instâncias da <xref:Microsoft.Win32.RegistryKey> objetos de classe que são criadas para acessar o conteúdo do registro também são somente leitura. Para obter um exemplo de como substituir esse comportamento, consulte [como: gravar dados no registro do Windows (C + + CLI)](../dotnet/how-to-write-data-to-the-windows-registry-cpp-cli.md).  
  
 Há dois objetos adicionais no <xref:Microsoft.Win32.Registry> classe: <xref:Microsoft.Win32.Registry.DynData> e <xref:Microsoft.Win32.Registry.PerformanceData>. Ambos são instâncias da <xref:Microsoft.Win32.RegistryKey> classe. O <xref:Microsoft.Win32.Registry.DynData> objeto contém informações de registro dinâmico, que só são suportadas no Windows 98 e Windows Me. O <xref:Microsoft.Win32.Registry.PerformanceData> objeto pode ser usado para acessar informações do contador de desempenho para aplicativos que usam o sistema de monitoramento de desempenho do Windows. O <xref:Microsoft.Win32.Registry.PerformanceData> nó representa informações que, na verdade, não são armazenadas no registro e, portanto, não podem ser exibidas usando Regedit.exe.  
  
## <a name="see-also"></a>Consulte também  
 [Como: gravar dados no registro do Windows (C + + CLI)](../dotnet/how-to-write-data-to-the-windows-registry-cpp-cli.md)   
 [Operações do Windows (C + + CLI)](../dotnet/windows-operations-cpp-cli.md)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)