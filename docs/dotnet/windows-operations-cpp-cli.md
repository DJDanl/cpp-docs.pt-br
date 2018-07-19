---
title: Operações do Windows (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows [C++], Windows-specific tasks
- .NET Framework [C++], Windows operations
- Visual C++, Windows operations
- Windows operations [C++]
- .NET Framework, shutdown
- shutdown
- termination
- applications [C++], shutdown
- Visual C++, user interactive state
- user interactive state
- Visual C++, reading from Windows Registry
- registry, reading
- performance counters
- performance counters, reading Windows performance counters
- performance monitoring, Windows performance counters
- performance, counters
- counters, reading Windows performance counters
- performance
- performance monitoring
- text, retrieving from Clipboard
- Clipboard, retrieving text
- current user names
- user names, retrieving
- UserName string
- .NET Framework, version
- Version property, retrieving .NET Framework version
- computer name, retrieving
- machine name, retrieving
- computer name
- Windows [C++], version
- Windows [C++], retrieving version using Visual C++
- time, elapsed since startup
- counters, elapsed time
- startup, time elapsed since
- tick counts
- startup
- text, storing in Clipboard
- Clipboard, storing text
- registry, writing to
- Visual C++, writing to Windows Registry
ms.assetid: b9a75cb4-0589-4d5b-92cb-5e8be42b4ac0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 7a303e80b58207e555dbd9067982ee1e2c506bb3
ms.sourcegitcommit: 27be37ae07ee7b657a54d23ed34438220d977fdc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/18/2018
ms.locfileid: "39110015"
---
# <a name="windows-operations-ccli"></a>Operações do Windows (C++/CLI)
Demonstra várias tarefas específicas do Windows usando o [!INCLUDE[winsdklong](../dotnet/includes/winsdklong_md.md)].  
  
 Os tópicos a seguir demonstram várias operações do Windows executadas com o [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)] usando o Visual C++.  

## <a name="determine_shutdown"></a> Determinar se o desligamento foi iniciado
O exemplo de código a seguir demonstra como determinar se o aplicativo ou o .NET Framework no momento está terminando. Isso é útil para acessar elementos estáticos no .NET Framework porque, durante o desligamento, essas construções são finalizadas pelo sistema e não podem ser usadas de forma confiável. Verificando o <xref:System.Environment.HasShutdownStarted%2A> propriedade primeiro, você pode evitar possíveis falhas não acessando esses elementos.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// check_shutdown.cpp  
// compile with: /clr  
using namespace System;  
int main()   
{  
   if (Environment::HasShutdownStarted)  
      Console::WriteLine("Shutting down.");  
   else  
      Console::WriteLine("Not shutting down.");  
   return 0;  
}  
```  

## <a name="determine_user"></a> Determinar o estado interativo do usuário
O exemplo de código a seguir demonstra como determinar se o código está sendo executado em um contexto interativo do usuário. Se <xref:System.Environment.UserInteractive%2A> for false, o código está sendo executado como um processo de serviço ou de dentro de um aplicativo Web, caso em que você não deve tentar interagir com o usuário.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// user_interactive.cpp  
// compile with: /clr  
using namespace System;  
  
int main()   
{  
   if ( Environment::UserInteractive )  
      Console::WriteLine("User interactive");  
   else  
      Console::WriteLine("Noninteractive");  
   return 0;  
}  
```  

## <a name="read_registry"></a> Ler dados de registro do Windows
O seguinte exemplo de código usa o <xref:Microsoft.Win32.Registry.CurrentUser> chave para ler dados de registro do Windows. Em primeiro lugar, as subchaves são enumeradas usando a <xref:Microsoft.Win32.RegistryKey.GetSubKeyNames%2A> método e, em seguida, a subchave de identidades é aberto usando o <xref:Microsoft.Win32.RegistryKey.OpenSubKey%2A> método. Como as chaves de raiz, cada subchave é representado pelo <xref:Microsoft.Win32.RegistryKey> classe. Por fim, o novo <xref:Microsoft.Win32.RegistryKey> objeto é usado para enumerar os pares chave/valor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
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
  
### <a name="remarks"></a>Comentários  
 O <xref:Microsoft.Win32.Registry> classe é meramente um contêiner para instâncias estáticas de <xref:Microsoft.Win32.RegistryKey>. Cada instância representa um nó raiz do registro. As instâncias estiverem <xref:Microsoft.Win32.Registry.ClassesRoot>, <xref:Microsoft.Win32.Registry.CurrentConfig>, <xref:Microsoft.Win32.Registry.CurrentUser>, <xref:Microsoft.Win32.Registry.LocalMachine>, e <xref:Microsoft.Win32.Registry.Users>.  
  
 Além do que está sendo estático, os objetos dentro de <xref:Microsoft.Win32.Registry> classe são somente leitura. Além disso, instâncias da <xref:Microsoft.Win32.RegistryKey> objetos de classe são criadas para acessar o conteúdo do registro também são somente leitura. Para obter um exemplo de como substituir esse comportamento, consulte [como: gravar dados no registro do Windows (C + + / CLI)](../dotnet/how-to-write-data-to-the-windows-registry-cpp-cli.md).  
  
 Há dois objetos adicionais no <xref:Microsoft.Win32.Registry> classe: <xref:Microsoft.Win32.Registry.DynData> e <xref:Microsoft.Win32.Registry.PerformanceData>. Ambos são instâncias do <xref:Microsoft.Win32.RegistryKey> classe. O <xref:Microsoft.Win32.Registry.DynData> objeto contém informações de registro dinâmico, que só são suportadas no Windows 98 e Windows Me. O <xref:Microsoft.Win32.Registry.PerformanceData> objeto pode ser usado para acessar informações do contador de desempenho para aplicativos que usam o sistema de monitoramento de desempenho do Windows. O <xref:Microsoft.Win32.Registry.PerformanceData> nó representa informações que não é realmente armazenadas no registro e, portanto, não podem ser exibidas usando Regedit.exe.  

## <a name="read_performance"></a> Ler contadores de desempenho do Windows
Alguns aplicativos e os subsistemas do Windows expõem dados de desempenho por meio do sistema de desempenho do Windows. Esses contadores podem ser acessados usando o <xref:System.Diagnostics.PerformanceCounterCategory> e <xref:System.Diagnostics.PerformanceCounter> classes, que residem no <xref:System.Diagnostics?displayProperty=fullName> namespace.  
  
 O exemplo de código a seguir usa essas classes para recuperar e exibir um contador que é atualizado pelo Windows para indicar a porcentagem de tempo que o processador está ocupado.  
  
> [!NOTE]
>  Esse exemplo exige privilégios administrativos para ser executado no Windows Vista.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// processor_timer.cpp  
// compile with: /clr  
#using <system.dll>  
  
using namespace System;  
using namespace System::Threading;  
using namespace System::Diagnostics;  
using namespace System::Timers;  
  
ref struct TimerObject  
{  
public:  
   static String^ m_instanceName;  
   static PerformanceCounter^ m_theCounter;  
  
public:  
   static void OnTimer(Object^ source, ElapsedEventArgs^ e)  
   {  
      try   
      {  
         Console::WriteLine("CPU time used: {0,6} ",  
          m_theCounter->NextValue( ).ToString("f"));  
      }   
      catch(Exception^ e)  
      {  
         if (dynamic_cast<InvalidOperationException^>(e))  
         {  
            Console::WriteLine("Instance '{0}' does not exist",  
                  m_instanceName);  
            return;  
         }  
         else  
         {  
            Console::WriteLine("Unknown exception... ('q' to quit)");  
            return;  
         }  
      }  
   }  
};  
  
int main()  
{  
   String^ objectName = "Processor";  
   String^ counterName = "% Processor Time";  
   String^ instanceName = "_Total";  
  
   try  
   {  
      if ( !PerformanceCounterCategory::Exists(objectName) )  
      {  
         Console::WriteLine("Object {0} does not exist", objectName);  
         return -1;  
      }  
   }  
   catch (UnauthorizedAccessException ^ex)  
   {  
      Console::WriteLine("You are not authorized to access this information.");  
      Console::Write("If you are using Windows Vista, run the application with ");  
      Console::WriteLine("administrative privileges.");  
      Console::WriteLine(ex->Message);  
      return -1;  
   }  
  
   if ( !PerformanceCounterCategory::CounterExists(  
          counterName, objectName) )  
   {  
      Console::WriteLine("Counter {0} does not exist", counterName);  
      return -1;  
   }  
  
   TimerObject::m_instanceName = instanceName;  
   TimerObject::m_theCounter = gcnew PerformanceCounter(  
          objectName, counterName, instanceName);  
  
   System::Timers::Timer^ aTimer = gcnew System::Timers::Timer();  
   aTimer->Elapsed += gcnew ElapsedEventHandler(&TimerObject::OnTimer);  
   aTimer->Interval = 1000;  
   aTimer->Enabled = true;  
   aTimer->AutoReset = true;  
  
   Console::WriteLine("reporting CPU usage for the next 10 seconds");  
   Thread::Sleep(10000);  
   return 0;  
}  
```  

## <a name="retrieve_text"></a> Recuperar o texto da área de transferência
O seguinte exemplo de código usa o <xref:System.Windows.Forms.Clipboard.GetDataObject%2A> função de membro para retornar um ponteiro para o <xref:System.Windows.Forms.IDataObject> interface. Essa interface pode ser consultada para o formato dos dados e usada para recuperar os dados reais.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// read_clipboard.cpp  
// compile with: /clr  
#using <system.dll>  
#using <system.Drawing.dll>  
#using <system.windows.forms.dll>  
  
using namespace System;  
using namespace System::Windows::Forms;  
  
[STAThread] int main( )  
{  
   IDataObject^ data = Clipboard::GetDataObject( );  
  
   if (data)  
   {  
      if (data->GetDataPresent(DataFormats::Text))   
      {  
         String^ text = static_cast<String^>  
           (data->GetData(DataFormats::Text));  
         Console::WriteLine(text);   
      }  
      else  
         Console::WriteLine("Nontext data is in the Clipboard.");  
   }  
   else   
   {  
      Console::WriteLine("No data was found in the Clipboard.");  
   }  
  
   return 0;  
}  
```  

## <a name="retrieve_current"></a> Recuperar o nome de usuário atual
O exemplo de código a seguir demonstra a recuperação do nome do usuário atual (o nome do usuário conectado no Windows). O nome é armazenado na <xref:System.Environment.UserName%2A> cadeia de caracteres, que é definida no <xref:System.Environment> namespace.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// username.cpp  
// compile with: /clr  
using namespace System;  
  
int main()   
{  
   Console::WriteLine("\nCurrent user: {0}", Environment::UserName);  
   return 0;  
}  
```  

## <a name="retrieve_dotnet"></a> Recuperar a versão do .NET Framework
O exemplo de código a seguir demonstra como determinar a versão do .NET Framework instalada no momento com o <xref:System.Environment.Version%2A> propriedade, que é um ponteiro para um <xref:System.Version> objeto que contém as informações de versão.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// dotnet_ver.cpp  
// compile with: /clr  
using namespace System;  
int main()   
{  
   Version^ version = Environment::Version;  
   if (version)  
   {  
      int build = version->Build;  
      int major = version->Major;  
      int minor = version->Minor;  
      int revision = Environment::Version->Revision;  
      Console::Write(".NET Framework version: ");  
      Console::WriteLine("{0}.{1}.{2}.{3}",   
            build, major, minor, revision);  
   }  
   return 0;  
}  
```  

## <a name="retrieve_local"></a> Recuperar o nome do computador Local 
O exemplo de código a seguir demonstra a recuperação do nome do computador local (o nome do computador conforme ele aparece em uma rede). Você pode fazer isso obtendo o <xref:System.Environment.MachineName%2A> cadeia de caracteres, que é definida no <xref:System.Environment> namespace.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// machine_name.cpp  
// compile with: /clr  
using namespace System;  
  
int main()   
{  
   Console::WriteLine("\nMachineName: {0}", Environment::MachineName);  
   return 0;  
}  
```  

## <a name="retrieve_version"></a> Recuperar a versão do Windows
O exemplo de código a seguir demonstra como recuperar as informações de plataforma e versão do sistema operacional atual. Essas informações são armazenadas do <xref:System.Environment.OSVersion%2A?displayProperty=fullName> propriedade e consiste em uma enumeração que descreve a versão do Windows em termos gerais e um <xref:System.Environment.Version%2A> objeto que contém o build exato do sistema operacional.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// os_ver.cpp  
// compile with: /clr  
using namespace System;  
  
int main()   
{  
   OperatingSystem^ osv = Environment::OSVersion;  
   PlatformID id = osv->Platform;  
   Console::Write("Operating system: ");  
  
   if (id == PlatformID::Win32NT)  
      Console::WriteLine("Win32NT");  
   else if (id == PlatformID::Win32S)  
      Console::WriteLine("Win32S");  
   else if (id == PlatformID::Win32Windows)  
      Console::WriteLine("Win32Windows");  
   else  
      Console::WriteLine("WinCE");  
  
   Version^ version = osv->Version;  
   if (version)  
   {  
      int build = version->Build;  
      int major = version->Major;  
      int minor = version->Minor;  
      int revision = Environment::Version->Revision;  
      Console::Write("OS Version: ");  
      Console::WriteLine("{0}.{1}.{2}.{3}",   
                   build, major, minor, revision);  
   }  
  
   return 0;  
}  
```  

## <a name="retrieve_time"></a> Recuperar tempo decorrido desde a inicialização
O exemplo de código a seguir demonstra como determinar a contagem em escala, ou o número de milissegundos decorridos desde o Windows foi iniciado. Esse valor é armazenado no <xref:System.Environment.TickCount%2A?displayProperty=fullName> membro e, como ele é um valor de 32 bits, redefine para zero aproximadamente a cada 24.9 dias.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// startup_time.cpp  
// compile with: /clr  
using namespace System;  
  
int main( )   
{  
   Int32 tc = Environment::TickCount;  
   Int32 seconds = tc / 1000;  
   Int32 minutes = seconds / 60;  
   float hours = static_cast<float>(minutes) / 60;  
   float days = hours / 24;  
  
   Console::WriteLine("Milliseconds since startup: {0}", tc);  
   Console::WriteLine("Seconds since startup: {0}", seconds);  
   Console::WriteLine("Minutes since startup: {0}", minutes);  
   Console::WriteLine("Hours since startup: {0}", hours);  
   Console::WriteLine("Days since startup: {0}", days);  
  
   return 0;  
}  
```  

## <a name="store_text"></a> Store texto na área de transferência
O seguinte exemplo de código usa o <xref:System.Windows.Forms.Clipboard> objeto definido no <xref:System.Windows.Forms> namespace para armazenar uma cadeia de caracteres. Esse objeto fornece duas funções de membro: <xref:System.Windows.Forms.Clipboard.SetDataObject%2A> e <xref:System.Windows.Forms.Clipboard.GetDataObject%2A>. Dados são armazenados na área de transferência por meio do envio de qualquer objeto derivado <xref:System.Object> para <xref:System.Windows.Forms.Clipboard.SetDataObject%2A>.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// store_clipboard.cpp  
// compile with: /clr  
#using <System.dll>  
#using <System.Drawing.dll>  
#using <System.Windows.Forms.dll>  
  
using namespace System;  
using namespace System::Windows::Forms;  
  
[STAThread] int main()  
{  
   String^ str = "This text is copied into the Clipboard.";  
  
   // Use 'true' as the second argument if  
   // the data is to remain in the clipboard  
   // after the program terminates.  
   Clipboard::SetDataObject(str, true);  
  
   Console::WriteLine("Added text to the Clipboard.");  
  
   return 0;  
}  
```  

## <a name="write_data"></a> Gravar dados no registro do Windows
O seguinte exemplo de código usa o <xref:Microsoft.Win32.Registry.CurrentUser> tecla para criar uma instância gravável dos <xref:Microsoft.Win32.RegistryKey> classe correspondente a **Software** chave. O <xref:Microsoft.Win32.RegistryKey.CreateSubKey%2A> método, em seguida, é usado para criar uma nova chave e adicionar pares de chave/valor.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
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
  
### <a name="remarks"></a>Comentários  
 Você pode usar o .NET Framework para acessar o registro com o <xref:Microsoft.Win32.Registry> e [RegistryKey](https://msdn.microsoft.com/en-us/library/microsoft.win32.registrykey.aspx) classes, que são ambos definidos no <xref:Microsoft.Win32> namespace. O **registro** classe é um contêiner para instâncias estáticas do <xref:Microsoft.Win32.RegistryKey> classe. Cada instância representa um nó raiz do registro. As instâncias estiverem <xref:Microsoft.Win32.Registry.ClassesRoot>, <xref:Microsoft.Win32.Registry.CurrentConfig>, <xref:Microsoft.Win32.Registry.CurrentUser>, <xref:Microsoft.Win32.Registry.LocalMachine>, e <xref:Microsoft.Win32.Registry.Users>.  

## <a name="related-sections"></a>Seções relacionadas  
 <xref:System.Environment>  
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)

 [Introdução ao monitoramento de desempenho](http://msdn.microsoft.com/en-us/d40f10b9-e2b7-4ec8-a9b3-706929e5bf35) 