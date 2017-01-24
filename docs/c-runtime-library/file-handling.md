---
title: "Manipula&#231;&#227;o de arquivos | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.files"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Arquivos  [C++], tratamento"
  - "Arquivos  [C++], manipulando"
  - "Arquivos  [C++], abertura"
ms.assetid: 48119e2e-e94f-4602-b08b-b72440f731d8
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Manipula&#231;&#227;o de arquivos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use estas rotinas para criar, excluir e manipular arquivos e para definir e verificar as permissões de acesso a arquivos.  
  
 As bibliotecas de tempo de execução do C têm um limite de 512 para o número de arquivos que podem ser abertas a qualquer momento. Tentando abrir mais do que o número máximo de descritores de arquivo ou fluxos de arquivos causa falha do programa. Use [setmaxstdio](../c-runtime-library/reference/setmaxstdio.md) para alterar esse número.  
  
 As seguintes rotinas operam em arquivos designados um descritor de arquivo.  
  
### Rotinas de manipulação de arquivos \(descritor de arquivo\)  
  
|Rotina|Use|Equivalente ao .NET framework|  
|------------|---------|-----------------------------------|  
|[\_chsize](../c-runtime-library/reference/chsize.md),[\_chsize\_s](../c-runtime-library/reference/chsize-s.md)|Alterar o tamanho do arquivo|[System::IO::Stream::SetLength](https://msdn.microsoft.com/en-us/library/system.io.stream.setlength.aspx), [System::IO::FileStream::SetLength](https://msdn.microsoft.com/en-us/library/system.io.filestream.setlength.aspx)|  
|[\_filelength, \_filelengthi64](../c-runtime-library/reference/filelength-filelengthi64.md)|Obter o tamanho de arquivo|[System::IO::Stream::Length](https://msdn.microsoft.com/en-us/library/system.io.stream.length.aspx), [System::IO::FileStream::Length](https://msdn.microsoft.com/en-us/library/system.io.filestream.length.aspx)|  
|[\_fstat, \_fstat32, \_fstat64, \_fstati64, \_fstat32i64, \_fstat64i32](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)|Obter informações de status do arquivo no descritor|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_get\_osfhandle](../c-runtime-library/reference/get-osfhandle.md)|Identificador de arquivo do sistema operacional retorno associado existente descritor de arquivo de tempo de execução do C|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_isatty](../c-runtime-library/reference/isatty.md)|Seleção de dispositivo de caractere|[System::IO::Stream::CanWrite](https://msdn.microsoft.com/en-us/library/system.io.filestream.canwrite.aspx), [System::IO::FileStream::CanWrite](https://msdn.microsoft.com/en-us/library/system.io.stream.canwrite.aspx)|  
|[\_locking](../Topic/_locking.md)|Áreas de bloqueio de arquivo|[System::IO::FileStream::Lock](https://msdn.microsoft.com/en-us/library/system.io.filestream.lock.aspx)|  
|[\_open\_osfhandle](../c-runtime-library/reference/open-osfhandle.md)|Associar o descritor de arquivo de tempo de execução C com o identificador de arquivo do sistema operacional existente|[System::IO::FileStream::Handle](https://msdn.microsoft.com/en-us/library/system.io.filestream.handle.aspx)|  
|[\_setmode](../c-runtime-library/reference/setmode.md)|Definir o modo de tradução de arquivo|[System::IO::BinaryReader classe](https://msdn.microsoft.com/en-us/library/system.io.binaryreader.aspx), [System::IO::TextReader classe](https://msdn.microsoft.com/en-us/library/system.io.textreader.aspx)|  
  
 As seguintes rotinas operam em arquivos especificados por um caminho ou nome de arquivo.  
  
### Rotinas de manipulação de arquivos \(caminho ou nome de arquivo\)  
  
|Rotina|Use|Equivalente ao .NET framework|  
|------------|---------|-----------------------------------|  
|[\_access, \_waccess](../c-runtime-library/reference/access-waccess.md), [\_access\_s, \_waccess\_s](../c-runtime-library/reference/access-s-waccess-s.md)|Verifique a configuração de permissão de arquivo|[Enumeração System::IO::FileAccess](https://msdn.microsoft.com/en-us/library/4z36sx0f.aspx)|  
|[\_chmod, \_wchmod](../c-runtime-library/reference/chmod-wchmod.md)|Alterar configuração de permissão de arquivo|[System::IO::File::SetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.setattributes.aspx), [System::Security::Permissions::FileIOPermission](https://msdn.microsoft.com/en-us/library/system.security.permissions.fileiopermission.aspx)|  
|[\_fullpath, \_wfullpath](../c-runtime-library/reference/fullpath-wfullpath.md)|Expanda um caminho relativo para o nome de caminho absoluto|[System::IO::file:: criar](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)|  
|[\_makepath, \_wmakepath](../c-runtime-library/reference/makepath-wmakepath.md), [\_makepath\_s, \_wmakepath\_s](../c-runtime-library/reference/makepath-s-wmakepath-s.md)|Mesclar componentes de caminho único caminho completo|[System::IO::file:: criar](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)|  
|[mktemp, wmktemp](../c-runtime-library/reference/mktemp-wmktemp.md), [\_mktemp\_s, \_wmktemp\_s](../c-runtime-library/reference/mktemp-s-wmktemp-s.md)|Criar um nome de arquivo exclusivo|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[remove, \_wremove](../c-runtime-library/reference/remove-wremove.md)|Excluir arquivo|[System::IO::file::Delete](https://msdn.microsoft.com/en-us/library/system.io.file.delete.aspx)|  
|[rename, \_wrename](../c-runtime-library/reference/rename-wrename.md)|Renomear arquivo|[System::IO::file::move](https://msdn.microsoft.com/en-us/library/system.io.file.move.aspx)|  
|[splitpath, wsplitpath](../Topic/_splitpath,%20_wsplitpath.md), [\_splitpath\_s, \_wsplitpath\_s](../c-runtime-library/reference/splitpath-s-wsplitpath-s.md)|Analisar o caminho em componentes|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[STAT, stat64, stati64, wstat, wstat64, wstati64](../c-runtime-library/reference/stat-functions.md)|Obter informações de status do arquivo no arquivo nomeado|[System::IO::File::GetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.getattributes.aspx), [System::IO::File::GetCreationTime](https://msdn.microsoft.com/en-us/library/system.io.file.getcreationtime.aspx), [System::IO::File::GetLastAccessTime](https://msdn.microsoft.com/en-us/library/system.io.file.getlastaccesstime.aspx), [System::IO::File::GetLastWriteTime](https://msdn.microsoft.com/en-us/library/system.io.file.getlastwritetime.aspx)|  
|[\_umask](../c-runtime-library/reference/umask.md), [\_umask\_s](../Topic/_umask_s.md)|Definir a máscara de permissão padrão para novos arquivos criados pelo programa|[System::IO::file::SetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.setattributes.aspx)|  
|[\_unlink, \_wunlink](../Topic/_unlink,%20_wunlink.md)|Excluir arquivo|[System::IO::file::Delete](https://msdn.microsoft.com/en-us/library/system.io.file.delete.aspx)|  
  
 As seguintes rotinas abrir arquivos.  
  
### Rotinas de manipulação de arquivos \(Abrir arquivo\)  
  
|Rotina|Use|Equivalente ao .NET framework|  
|------------|---------|-----------------------------------|  
|[fopen, \_wfopen](../c-runtime-library/reference/fopen-wfopen.md), [fopen\_s, \_wfopen\_s](../c-runtime-library/reference/fopen-s-wfopen-s.md)|Abre um arquivo e retorna um ponteiro para o arquivo aberto.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx), <xref:System.IO.FileStream.%23ctor%2A>|  
|[\_fsopen, \_wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)|Abrir um fluxo com o compartilhamento de arquivo e retorna um ponteiro para o arquivo aberto.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx), <xref:System.IO.FileStream.%23ctor%2A>|  
|[\_open, \_wopen](../c-runtime-library/reference/open-wopen.md)|Abre um arquivo e retorna um descritor de arquivo para o arquivo aberto.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx), <xref:System.IO.FileStream.%23ctor%2A>|  
|[\_sopen, \_wsopen](../c-runtime-library/reference/sopen-wsopen.md), [\_sopen\_s, \_wsopen\_s](../c-runtime-library/reference/sopen-s-wsopen-s.md)|Abrir um arquivo com o compartilhamento de arquivo e retorna um descritor de arquivo para o arquivo aberto.||  
|[\_pipe](../c-runtime-library/reference/pipe.md)|Cria um pipe para leitura e gravação.|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[freopen, \_wfreopen](../c-runtime-library/reference/freopen-wfreopen.md), [freopen\_s, \_wfreopen\_s](../c-runtime-library/reference/freopen-s-wfreopen-s.md)|Reatribua um ponteiro de arquivo.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx), <xref:System.IO.FileStream.%23ctor%2A>|  
  
 As funções a seguir fornecem uma maneira de alterar a representação de arquivo entre um `FILE` estrutura, um descritor de arquivo e um identificador de arquivo do Win32.  
  
||||  
|-|-|-|  
|[\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)|Associa um fluxo com um arquivo que foi aberto anteriormente para e\/s baixo nível e retorna um ponteiro para o fluxo aberto.|[System::IO::file::Open](https://msdn.microsoft.com/en-us/library/system.io.filestream.aspx)|  
|[\_fileno](../Topic/_fileno.md)|Obtém o descritor de arquivo associado a um fluxo.|[System::IO::FileStream::Handle](https://msdn.microsoft.com/en-us/library/system.io.filestream.handle.aspx)|  
|[\_get\_osfhandle](../c-runtime-library/reference/get-osfhandle.md)|Identificador de arquivo do sistema operacional retorno associado existente descritor de arquivo de tempo de execução do C|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_open\_osfhandle](../c-runtime-library/reference/open-osfhandle.md)|Associa o descritor de arquivo de tempo de execução C com um identificador de arquivo do sistema operacional existente.|[System::IO::FileStream::Handle](https://msdn.microsoft.com/en-us/library/system.io.filestream.handle.aspx)|  
  
 As seguintes funções do Win32 também abrir arquivos e pipes:  
  
-   [CreateFile](http://msdn.microsoft.com/library/windows/desktop/aa363858.aspx)  
  
-   [CreatePipe](http://msdn.microsoft.com/library/windows/desktop/aa365152.aspx)  
  
-   [CreateNamedPipe](http://msdn.microsoft.com/library/windows/desktop/aa365150.aspx)  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)   
 [Controle de diretório](../c-runtime-library/directory-control.md)   
 [Chamadas do sistema](../Topic/System%20Calls.md)