---
title: Manipulação de arquivos e I-O (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- .NET Framework [C++], file handling
- files [C++], .NET Framework and
- I/O [C++], .NET Framework applications
- .NET Framework [C++], I/O
- files [C++], listing files
- directories [C++], listing files
- monitoring file system events
- FileSystemWatcher class, examples
- examples [C++], monitoring file system changes
- events [C++], monitoring
- file system events [C++]
- files [C++], binary
- binary files, reading in C++
- reading text files
- text files, reading
- files [C++], retrieving information about
- FileInfo class
- binary files, writing in C++
- files [C++], binary
- files [C++], text
- text files, writing in C++
ms.assetid: 3296fd59-a83a-40d4-bd4a-6096cc13101b
ms.openlocfilehash: a1cfdc4239506f22368753d8c37765e550d9b835
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508937"
---
# <a name="file-handling-and-io-ccli"></a>Tratamento de arquivos e E/S (C++/CLI)

Demonstra várias operações de arquivo usando o .NET Framework.

Os tópicos a seguir demonstram o uso de classes definidas no <xref:System.IO> namespace para executar várias operações de arquivo.

## <a name="enumerate-files-in-a-directory"></a><a name="enumerate"></a> Enumerar arquivos em um diretório

O exemplo de código a seguir demonstra como recuperar uma lista dos arquivos em um diretório. Além disso, os subdiretórios são enumerados. O exemplo de código a seguir usa os <xref:System.IO.Directory.GetFiles%2A> <xref:System.IO.Directory.GetFiles%2A> <xref:System.IO.Directory.GetDirectories%2A> métodos e para exibir o conteúdo do diretório C:\Windows.

### <a name="example"></a>Exemplo

```cpp
// enum_files.cpp
// compile with: /clr
using namespace System;
using namespace System::IO;

int main()
{
   String^ folder = "C:\\";
   array<String^>^ dir = Directory::GetDirectories( folder );
   Console::WriteLine("--== Directories inside '{0}' ==--", folder);
   for (int i=0; i<dir->Length; i++)
      Console::WriteLine(dir[i]);

   array<String^>^ file = Directory::GetFiles( folder );
   Console::WriteLine("--== Files inside '{0}' ==--", folder);
   for (int i=0; i<file->Length; i++)
      Console::WriteLine(file[i]);

   return 0;
}
```

## <a name="monitor-file-system-changes"></a><a name="monitor"></a> Monitorar alterações do sistema de arquivos

O exemplo de código a seguir usa <xref:System.IO.FileSystemWatcher> para registrar eventos correspondentes a arquivos que estão sendo criados, alterados, excluídos ou renomeados. Em vez de sondar periodicamente um diretório em busca de alterações nos arquivos, você pode usar a <xref:System.IO.FileSystemWatcher> classe para acionar eventos quando uma alteração é detectada.

### <a name="example"></a>Exemplo

```cpp
// monitor_fs.cpp
// compile with: /clr
#using <system.dll>

using namespace System;
using namespace System::IO;

ref class FSEventHandler
{
public:
    void OnChanged (Object^ source, FileSystemEventArgs^ e)
    {
        Console::WriteLine("File: {0} {1}",
               e->FullPath, e->ChangeType);
    }
    void OnRenamed(Object^ source, RenamedEventArgs^ e)
    {
        Console::WriteLine("File: {0} renamed to {1}",
                e->OldFullPath, e->FullPath);
    }
};

int main()
{
   array<String^>^ args = Environment::GetCommandLineArgs();

   if(args->Length < 2)
   {
      Console::WriteLine("Usage: Watcher.exe <directory>");
      return -1;
   }

   FileSystemWatcher^ fsWatcher = gcnew FileSystemWatcher( );
   fsWatcher->Path = args[1];
   fsWatcher->NotifyFilter = static_cast<NotifyFilters>
              (NotifyFilters::FileName |
               NotifyFilters::Attributes |
               NotifyFilters::LastAccess |
               NotifyFilters::LastWrite |
               NotifyFilters::Security |
               NotifyFilters::Size );

    FSEventHandler^ handler = gcnew FSEventHandler();
    fsWatcher->Changed += gcnew FileSystemEventHandler(
            handler, &FSEventHandler::OnChanged);
    fsWatcher->Created += gcnew FileSystemEventHandler(
            handler, &FSEventHandler::OnChanged);
    fsWatcher->Deleted += gcnew FileSystemEventHandler(
            handler, &FSEventHandler::OnChanged);
    fsWatcher->Renamed += gcnew RenamedEventHandler(
            handler, &FSEventHandler::OnRenamed);

    fsWatcher->EnableRaisingEvents = true;

    Console::WriteLine("Press Enter to quit the sample.");
    Console::ReadLine( );
}
```

## <a name="read-a-binary-file"></a><a name="read_binary"></a> Ler um arquivo binário

O exemplo de código a seguir mostra como ler dados binários de um arquivo, usando duas classes do <xref:System.IO?displayProperty=fullName> namespace: <xref:System.IO.FileStream> e <xref:System.IO.BinaryReader> . <xref:System.IO.FileStream> representa o arquivo real. <xref:System.IO.BinaryReader> fornece uma interface para o fluxo que permite o acesso binário.

O exemplo de código lê um arquivo chamado Data. bin e contém inteiros no formato binário. Para obter informações sobre esse tipo de arquivo, consulte [como: gravar um arquivo binário (C++/CLI)](#write_binary).

### <a name="example"></a>Exemplo

```cpp
// binary_read.cpp
// compile with: /clr
#using<system.dll>
using namespace System;
using namespace System::IO;

int main()
{
   String^ fileName = "data.bin";
   try
   {
      FileStream^ fs = gcnew FileStream(fileName, FileMode::Open);
      BinaryReader^ br = gcnew BinaryReader(fs);

      Console::WriteLine("contents of {0}:", fileName);
      while (br->BaseStream->Position < br->BaseStream->Length)
         Console::WriteLine(br->ReadInt32().ToString());

      fs->Close( );
   }
   catch (Exception^ e)
   {
      if (dynamic_cast<FileNotFoundException^>(e))
         Console::WriteLine("File '{0}' not found", fileName);
      else
         Console::WriteLine("Exception: ({0})", e);
      return -1;
   }
   return 0;
}
```

## <a name="read-a-text-file"></a><a name="read_text"></a> Ler um arquivo de texto

O exemplo de código a seguir demonstra como abrir e ler um arquivo de texto uma linha por vez, usando a <xref:System.IO.StreamReader> classe que é definida no <xref:System.IO?displayProperty=fullName> namespace. Uma instância dessa classe é usada para abrir um arquivo de texto e, em seguida, o <xref:System.IO.StreamReader.ReadLine%2A?displayProperty=fullName> método é usado para recuperar cada linha.

Este exemplo de código lê um arquivo chamado textfile.txt e contém texto. Para obter informações sobre esse tipo de arquivo, consulte [como: gravar um arquivo de texto (C++/CLI)](#write_text).

### <a name="example"></a>Exemplo

```cpp
// text_read.cpp
// compile with: /clr
#using<system.dll>
using namespace System;
using namespace System::IO;

int main()
{
   String^ fileName = "textfile.txt";
   try
   {
      Console::WriteLine("trying to open file {0}...", fileName);
      StreamReader^ din = File::OpenText(fileName);

      String^ str;
      int count = 0;
      while ((str = din->ReadLine()) != nullptr)
      {
         count++;
         Console::WriteLine("line {0}: {1}", count, str );
      }
   }
   catch (Exception^ e)
   {
      if (dynamic_cast<FileNotFoundException^>(e))
         Console::WriteLine("file '{0}' not found", fileName);
      else
         Console::WriteLine("problem reading file '{0}'", fileName);
   }

   return 0;
}
```

## <a name="retrieve-file-information"></a><a name="retrieve"></a> Recuperar informações do arquivo

O exemplo de código a seguir demonstra a <xref:System.IO.FileInfo> classe. Quando você tiver o nome de um arquivo, poderá usar essa classe para recuperar informações sobre o arquivo, como o tamanho do arquivo, o diretório, o nome completo e a data e hora da criação e da última modificação.

Esse código recupera informações de arquivo para Notepad.exe.

### <a name="example"></a>Exemplo

```cpp
// file_info.cpp
// compile with: /clr
using namespace System;
using namespace System::IO;

int main()
{
   array<String^>^ args = Environment::GetCommandLineArgs();
   if (args->Length < 2)
   {
      Console::WriteLine("\nUSAGE : file_info <filename>\n\n");
      return -1;
   }

   FileInfo^ fi = gcnew FileInfo( args[1] );

   Console::WriteLine("file size: {0}", fi->Length );

   Console::Write("File creation date:  ");
   Console::Write(fi->CreationTime.Month.ToString());
   Console::Write(".{0}", fi->CreationTime.Day.ToString());
   Console::WriteLine(".{0}", fi->CreationTime.Year.ToString());

   Console::Write("Last access date:  ");
   Console::Write(fi->LastAccessTime.Month.ToString());
   Console::Write(".{0}", fi->LastAccessTime.Day.ToString());
   Console::WriteLine(".{0}", fi->LastAccessTime.Year.ToString());

   return 0;
}
```

## <a name="write-a-binary-file"></a><a name="write_binary"></a> Gravar um arquivo binário

O exemplo de código a seguir demonstra a gravação de dados binários em um arquivo. Duas classes do <xref:System.IO> namespace são usadas: <xref:System.IO.FileStream> e <xref:System.IO.BinaryWriter> . <xref:System.IO.FileStream> representa o arquivo real, enquanto <xref:System.IO.BinaryWriter> fornece uma interface para o fluxo que permite o acesso binário.

O exemplo de código a seguir grava um arquivo contendo inteiros em formato binário. Esse arquivo pode ser lido com o código em [como: ler um arquivo binário (C++/CLI)](#read_binary).

### <a name="example"></a>Exemplo

```cpp
// binary_write.cpp
// compile with: /clr
#using<system.dll>
using namespace System;
using namespace System::IO;

int main()
{
   array<Int32>^ data = {1, 2, 3, 10000};

   FileStream^ fs = gcnew FileStream("data.bin", FileMode::Create);
   BinaryWriter^ w = gcnew BinaryWriter(fs);

   try
   {
      Console::WriteLine("writing data to file:");
      for (int i=0; i<data->Length; i++)
      {
         Console::WriteLine(data[i]);
         w->Write(data[i]);
      }
   }
   catch (Exception^)
   {
     Console::WriteLine("data could not be written");
     fs->Close();
     return -1;
   }

   fs->Close();
   return 0;
}
```

## <a name="write-a-text-file"></a><a name="write_text"></a> Gravar um arquivo de texto

O exemplo de código a seguir demonstra como criar um arquivo de texto e gravar o texto nele usando a <xref:System.IO.StreamWriter> classe, que é definida no <xref:System.IO> namespace. O <xref:System.IO.StreamWriter> construtor usa o nome do arquivo a ser criado. Se o arquivo existir, ele será substituído (a menos que você passe true como o segundo <xref:System.IO.StringWriter> argumento do Construtor).

O arquivo é então arquivado usando <xref:System.IO.StreamWriter.Write%2A> as <xref:System.IO.TextWriter.WriteLine%2A> funções e.

### <a name="example"></a>Exemplo

```cpp
// text_write.cpp
// compile with: /clr
using namespace System;
using namespace System::IO;

int main()
{
   String^ fileName = "textfile.txt";

   StreamWriter^ sw = gcnew StreamWriter(fileName);
   sw->WriteLine("A text file is born!");
   sw->Write("You can use WriteLine");
   sw->WriteLine("...or just Write");
   sw->WriteLine("and do {0} output too.", "formatted");
   sw->WriteLine("You can also send non-text objects:");
   sw->WriteLine(DateTime::Now);
   sw->Close();
   Console::WriteLine("a new file ('{0}') has been written", fileName);

   return 0;
}
```

## <a name="see-also"></a>Confira também

[Programação .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)<br/>
[Arquivo e e/s de fluxo](/dotnet/standard/io/index)<br/>
[Namespace System.IO](/dotnet/api/system.io)
