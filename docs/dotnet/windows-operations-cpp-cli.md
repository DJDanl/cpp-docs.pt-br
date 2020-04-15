---
title: Operações do Windows (C++/CLI)
ms.date: 11/04/2016
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
ms.openlocfilehash: 99fce804ad30e01bdbaa99b1636a5238ff535f8b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371768"
---
# <a name="windows-operations-ccli"></a>Operações do Windows (C++/CLI)

Demonstra várias tarefas específicas do Windows usando o Windows SDK.

Os tópicos a seguir demonstram várias operações do Windows realizadas com o Windows SDK usando o Visual C++.

## <a name="determine-if-shutdown-has-started"></a><a name="determine_shutdown"></a>Determine se o desligamento foi iniciado

O exemplo de código a seguir demonstra como determinar se o aplicativo ou o .NET Framework está terminando no momento. Isso é útil para acessar elementos estáticos no Quadro .NET porque, durante o desligamento, esses construtos são finalizados pelo sistema e não podem ser usados de forma confiável. Ao verificar <xref:System.Environment.HasShutdownStarted%2A> a propriedade primeiro, você pode evitar possíveis falhas ao não acessar esses elementos.

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

## <a name="determine-the-user-interactive-state"></a><a name="determine_user"></a>Determine o Estado Interativo do Usuário

O exemplo de código a seguir demonstra como determinar se o código está sendo executado em um contexto interativo do usuário. Se <xref:System.Environment.UserInteractive%2A> for falso, então o código está sendo executado como um processo de serviço ou de dentro de um aplicativo da Web, nesse caso você não deve tentar interagir com o usuário.

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

## <a name="read-data-from-the-windows-registry"></a><a name="read_registry"></a>Leia dados do Registro do Windows

O exemplo de <xref:Microsoft.Win32.Registry.CurrentUser> código a seguir usa a chave para ler dados do registro do Windows. Primeiro, as subchaves são enumeradas usando o <xref:Microsoft.Win32.RegistryKey.GetSubKeyNames%2A> método e, <xref:Microsoft.Win32.RegistryKey.OpenSubKey%2A> em seguida, a subchave Identidades é aberta usando o método. Como as teclas de raiz, <xref:Microsoft.Win32.RegistryKey> cada subchave é representada pela classe. Finalmente, o <xref:Microsoft.Win32.RegistryKey> novo objeto é usado para enumerar os pares de chave/valor.

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

A <xref:Microsoft.Win32.Registry> classe é apenas um <xref:Microsoft.Win32.RegistryKey>recipiente para instâncias estáticas de . Cada instância representa um nó de registro raiz. As instâncias <xref:Microsoft.Win32.Registry.CurrentConfig> <xref:Microsoft.Win32.Registry.CurrentUser>são, <xref:Microsoft.Win32.Registry.LocalMachine> <xref:Microsoft.Win32.Registry.ClassesRoot> <xref:Microsoft.Win32.Registry.Users>e .

Além de serem estáticos, <xref:Microsoft.Win32.Registry> os objetos dentro da classe são somente leitura. Além disso, as <xref:Microsoft.Win32.RegistryKey> instâncias da classe criada para acessar o conteúdo dos objetos de registro também são leituras. Para um exemplo de como substituir esse comportamento, consulte [Como: Escrever dados para o Registro do Windows (C++/CLI)](../dotnet/how-to-write-data-to-the-windows-registry-cpp-cli.md).

Há dois objetos <xref:Microsoft.Win32.Registry> adicionais <xref:Microsoft.Win32.Registry.DynData> <xref:Microsoft.Win32.Registry.PerformanceData>na classe: e . Ambos são exemplos <xref:Microsoft.Win32.RegistryKey> da classe. O <xref:Microsoft.Win32.Registry.DynData> objeto contém informações de registro dinâmico, que só são suportadas no Windows 98 e no Windows Me. O <xref:Microsoft.Win32.Registry.PerformanceData> objeto pode ser usado para acessar informações de contador de desempenho para aplicativos que usam o Sistema de Monitoramento de Desempenho do Windows. O <xref:Microsoft.Win32.Registry.PerformanceData> nó representa informações que não são realmente armazenadas no registro e, portanto, não podem ser visualizadas usando Regedit.exe.

## <a name="read-windows-performance-counters"></a><a name="read_performance"></a>Leia contadores de desempenho do Windows

Alguns aplicativos e subsistemas Windows expõem dados de desempenho através do sistema de desempenho do Windows. Esses contadores podem ser acessados usando as <xref:System.Diagnostics.PerformanceCounterCategory> classes e, <xref:System.Diagnostics.PerformanceCounter> que residem no <xref:System.Diagnostics?displayProperty=fullName> namespace.

O exemplo de código a seguir usa essas classes para recuperar e exibir um contador atualizado pelo Windows para indicar a porcentagem de tempo que o processador está ocupado.

> [!NOTE]
> Esse exemplo exige privilégios administrativos para ser executado no Windows Vista.

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

## <a name="retrieve-text-from-the-clipboard"></a><a name="retrieve_text"></a>Recuperar texto da área de transferência

O exemplo de <xref:System.Windows.Forms.Clipboard.GetDataObject%2A> código a seguir usa <xref:System.Windows.Forms.IDataObject> a função membro para retornar um ponteiro à interface. Esta interface pode então ser consultada para o formato dos dados e usada para recuperar os dados reais.

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

## <a name="retrieve-the-current-username"></a><a name="retrieve_current"></a>Recuperar o nome de usuário atual

O exemplo de código a seguir demonstra a recuperação do nome de usuário atual (o nome do usuário logado no Windows). O nome é <xref:System.Environment.UserName%2A> armazenado na seqüência, que é definida no <xref:System.Environment> namespace.

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

## <a name="retrieve-the-net-framework-version"></a><a name="retrieve_dotnet"></a>Recuperar a versão framework .NET

O exemplo de código a seguir demonstra como determinar a versão <xref:System.Environment.Version%2A> do .NET Framework <xref:System.Version> atualmente instalado com a propriedade, que é um ponteiro para um objeto que contém as informações da versão.

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

## <a name="retrieve-the-local-machine-name"></a><a name="retrieve_local"></a>Recupere o nome da máquina local

O exemplo de código a seguir demonstra a recuperação do nome da máquina local (o nome do computador como ele aparece em uma rede). Você pode conseguir isso <xref:System.Environment.MachineName%2A> recebendo a string, que é definida no <xref:System.Environment> namespace.

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

## <a name="retrieve-the-windows-version"></a><a name="retrieve_version"></a>Recuperar a versão do Windows

O exemplo de código a seguir demonstra como recuperar as informações da plataforma e da versão do sistema operacional atual. Essas informações são <xref:System.Environment.OSVersion%2A?displayProperty=fullName> armazenadas na propriedade e consistem em uma enumeração que <xref:System.Environment.Version%2A> descreve a versão do Windows em termos gerais e um objeto que contém a compilação exata do sistema operacional.

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

## <a name="retrieve-time-elapsed-since-startup"></a><a name="retrieve_time"></a>Recuperar o tempo decorrido desde a inicialização

O exemplo de código a seguir demonstra como determinar a contagem de carrapatos ou o número de milissegundos que se passaram desde que o Windows foi iniciado. Esse valor é <xref:System.Environment.TickCount%2A?displayProperty=fullName> armazenado no membro e, por ser um valor de 32 bits, redefine-se para zero aproximadamente a cada 24,9 dias.

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

## <a name="store-text-in-the-clipboard"></a><a name="store_text"></a>Armazenar texto na área de transferência

O exemplo de <xref:System.Windows.Forms.Clipboard> código a <xref:System.Windows.Forms> seguir usa o objeto definido no namespace para armazenar uma seqüência de strings. Este objeto fornece duas <xref:System.Windows.Forms.Clipboard.SetDataObject%2A> funções de membros: e <xref:System.Windows.Forms.Clipboard.GetDataObject%2A>. Os dados são armazenados na Área de <xref:System.Object> <xref:System.Windows.Forms.Clipboard.SetDataObject%2A>Transferência enviando qualquer objeto derivado de .

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

## <a name="write-data-to-the-windows-registry"></a><a name="write_data"></a>Escrever dados para o Registro do Windows

O exemplo de <xref:Microsoft.Win32.Registry.CurrentUser> código a seguir usa a <xref:Microsoft.Win32.RegistryKey> chave para criar uma instância gravável da classe correspondente à chave **Software.** O <xref:Microsoft.Win32.RegistryKey.CreateSubKey%2A> método é então usado para criar uma nova chave e adicionar aos pares de chave/valor.

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

Você pode usar o Quadro .NET <xref:Microsoft.Win32.Registry> para <xref:Microsoft.Win32.RegistryKey> acessar o registro com <xref:Microsoft.Win32> as classes e classes, que são definidas no namespace. A classe **Registro** é um recipiente <xref:Microsoft.Win32.RegistryKey> para instâncias estáticas da classe. Cada instância representa um nó de registro raiz. As instâncias <xref:Microsoft.Win32.Registry.CurrentConfig> <xref:Microsoft.Win32.Registry.CurrentUser>são, <xref:Microsoft.Win32.Registry.LocalMachine> <xref:Microsoft.Win32.Registry.ClassesRoot> <xref:Microsoft.Win32.Registry.Users>e .

## <a name="related-sections"></a>Seções relacionadas

<xref:System.Environment>

## <a name="see-also"></a>Confira também

[.NET Programação com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)
