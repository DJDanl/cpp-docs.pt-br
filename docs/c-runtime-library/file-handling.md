---
title: "Manipulação de arquivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.files
dev_langs:
- C++
helpviewer_keywords:
- files [C++], handling
- files [C++], opening
- files [C++], manipulating
ms.assetid: 48119e2e-e94f-4602-b08b-b72440f731d8
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 28ee6adcd86814d5804e0d9d34dd27a3c6d22f71

---
# <a name="file-handling"></a>Manipulação de arquivos
Use estas rotinas para criar, excluir e manipular arquivos e para definir e verificar as permissões de acesso a arquivos.  
  
 As bibliotecas de tempo de execução C têm um limite de 512 para o número de arquivos que podem ser abertos a qualquer momento. Tentar abrir mais do que o número máximo de descritores de arquivos ou fluxos de arquivos causa uma falha do programa. Use [_setmaxstdio](../c-runtime-library/reference/setmaxstdio.md) para alterar esse número.  
  
 As seguintes rotinas operam em arquivos designados por um descritor de arquivo.  
  
### <a name="file-handling-routines-file-descriptor"></a>Rotinas de manipulação de arquivos (descritor de arquivo)  
  
|Rotina|Uso|Equivalente ao .NET Framework|  
|-------------|---------|-------------------------------|  
|[_chsize](../c-runtime-library/reference/chsize.md),[_chsize_s](../c-runtime-library/reference/chsize-s.md)|Alterar o tamanho do arquivo|[System::IO::Stream::SetLength](https://msdn.microsoft.com/en-us/library/system.io.stream.setlength.aspx), [System::IO::FileStream::SetLength](https://msdn.microsoft.com/en-us/library/system.io.filestream.setlength.aspx)|  
|[_filelength, _filelengthi64](../c-runtime-library/reference/filelength-filelengthi64.md)|Obter tamanho de arquivo|[System::IO::Stream::Length](https://msdn.microsoft.com/en-us/library/system.io.stream.length.aspx), [System::IO::FileStream::Length](https://msdn.microsoft.com/en-us/library/system.io.filestream.length.aspx)|  
|[_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](../c-runtime-library/reference/fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)|Obter informações de status do arquivo no descritor|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_get_osfhandle](../c-runtime-library/reference/get-osfhandle.md)|Retornar identificador de arquivo do sistema operacional associado ao descritor de arquivo de tempo de execução C existente|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_isatty](../c-runtime-library/reference/isatty.md)|Verificar o dispositivo de caracteres|[System::IO::Stream::CanWrite](https://msdn.microsoft.com/en-us/library/system.io.filestream.canwrite.aspx), [System::IO::FileStream::CanWrite](https://msdn.microsoft.com/en-us/library/system.io.stream.canwrite.aspx)|  
|[_locking](../c-runtime-library/reference/locking.md)|Bloquear áreas do arquivo|[System::IO::FileStream::Lock](https://msdn.microsoft.com/en-us/library/system.io.filestream.lock.aspx)|  
|[_open_osfhandle](../c-runtime-library/reference/open-osfhandle.md)|Associar o descritor de arquivo de tempo de execução C com o identificador de arquivo do sistema operacional existente|[System::IO::FileStream::Handle](https://msdn.microsoft.com/en-us/library/system.io.filestream.handle.aspx)|  
|[_setmode](../c-runtime-library/reference/setmode.md)|Definir o modo de conversão do arquivo|[Classe System::IO::BinaryReader](https://msdn.microsoft.com/en-us/library/system.io.binaryreader.aspx), [Classe System::IO::TextReader](https://msdn.microsoft.com/en-us/library/system.io.textreader.aspx)|  
  
 As seguintes rotinas operam em arquivos especificados por um caminho ou nome de arquivo.  
  
### <a name="file-handling-routines-path-or-filename"></a>Rotinas de manipulação de arquivos (caminho ou nome de arquivo)  
  
|Rotina|Uso|Equivalente ao .NET Framework|  
|-------------|---------|-------------------------------|  
|[_access, _waccess](../c-runtime-library/reference/access-waccess.md), [_access_s, _waccess_s](../c-runtime-library/reference/access-s-waccess-s.md)|Verificar configuração de permissão de arquivo|[Enumeração System::IO::FileAccess](https://msdn.microsoft.com/en-us/library/4z36sx0f.aspx)|  
|[_chmod, _wchmod](../c-runtime-library/reference/chmod-wchmod.md)|Alterar configuração de permissão de arquivo|[System::IO::File::SetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.setattributes.aspx), [System::Security::Permissions::FileIOPermission](https://msdn.microsoft.com/en-us/library/system.security.permissions.fileiopermission.aspx)|  
|[_fullpath, _wfullpath](../c-runtime-library/reference/fullpath-wfullpath.md)|Expandir um caminho relativo para o nome de caminho absoluto|[System::IO::File::Create](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)|  
|[_makepath, _wmakepath](../c-runtime-library/reference/makepath-wmakepath.md), [_makepath_s, _wmakepath_s](../c-runtime-library/reference/makepath-s-wmakepath-s.md)|Mesclar componentes de caminho em caminho completo único|[System::IO::File::Create](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)|  
|[_mktemp, _wmktemp](../c-runtime-library/reference/mktemp-wmktemp.md), [_mktemp_s, _wmktemp_s](../c-runtime-library/reference/mktemp-s-wmktemp-s.md)|Criar nome de arquivo exclusivo|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[remove, _wremove](../c-runtime-library/reference/remove-wremove.md)|Excluir arquivo|[System::IO::File::Delete](https://msdn.microsoft.com/en-us/library/system.io.file.delete.aspx)|  
|[rename, _wrename](../c-runtime-library/reference/rename-wrename.md)|Renomear arquivo|[System::IO::File::Move](https://msdn.microsoft.com/en-us/library/system.io.file.move.aspx)|  
|[_splitpath, _wsplitpath](../c-runtime-library/reference/splitpath-wsplitpath.md), [_splitpath_s, _wsplitpath_s](../c-runtime-library/reference/splitpath-s-wsplitpath-s.md)|Analisar caminho em componentes|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_stat, _stat64, _stati64, _wstat, _wstat64, _wstati64](../c-runtime-library/reference/stat-functions.md)|Obter informações de status do arquivo no arquivo nomeado|[System::IO::File::GetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.getattributes.aspx), [System::IO::File::GetCreationTime](https://msdn.microsoft.com/en-us/library/system.io.file.getcreationtime.aspx), [System::IO::File::GetLastAccessTime](https://msdn.microsoft.com/en-us/library/system.io.file.getlastaccesstime.aspx), [System::IO::File::GetLastWriteTime](https://msdn.microsoft.com/en-us/library/system.io.file.getlastwritetime.aspx)|  
|[_umask](../c-runtime-library/reference/umask.md), [_umask_s](../c-runtime-library/reference/umask-s.md)|Definir a máscara de permissão padrão para novos arquivos criados pelo programa|[System::IO::File::SetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.setattributes.aspx)|  
|[_unlink, _wunlink](../c-runtime-library/reference/unlink-wunlink.md)|Excluir arquivo|[System::IO::File::Delete](https://msdn.microsoft.com/en-us/library/system.io.file.delete.aspx)|  
  
 As seguintes rotinas abrem arquivos.  
  
### <a name="file-handling-routines-open-file"></a>Rotinas de manipulação de arquivos (abrir arquivo)  
  
|Rotina|Uso|Equivalente ao .NET Framework|  
|-------------|---------|-------------------------------|  
|[fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md), [fopen_s, _wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md)|Abre um arquivo e retorna um ponteiro para o arquivo aberto.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx), <xref:System.IO.FileStream.%23ctor%2A>|  
|[_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)|Abre um fluxo com o compartilhamento de arquivo e retorna um ponteiro para o arquivo aberto.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx), <xref:System.IO.FileStream.%23ctor%2A>|  
|[_open, _wopen](../c-runtime-library/reference/open-wopen.md)|Abre um arquivo e retorna um descritor de arquivo para o arquivo aberto.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx), <xref:System.IO.FileStream.%23ctor%2A>|  
|[_sopen, _wsopen](../c-runtime-library/reference/sopen-wsopen.md), [_sopen_s, _wsopen_s](../c-runtime-library/reference/sopen-s-wsopen-s.md)|Abre um arquivo com o compartilhamento de arquivo e retorna um descritor de arquivo para o arquivo aberto.||  
|[_pipe](../c-runtime-library/reference/pipe.md)|Cria um pipe para leitura e gravação.|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[freopen, _wfreopen](../c-runtime-library/reference/freopen-wfreopen.md), [freopen_s, _wfreopen_s](../c-runtime-library/reference/freopen-s-wfreopen-s.md)|Reatribuir um ponteiro de arquivo.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx), <xref:System.IO.FileStream.%23ctor%2A>|  
  
 As funções a seguir fornecem uma maneira de alterar a representação de arquivo entre uma estrutura `FILE`, um descritor de arquivo e um identificador de arquivo do Win32.  
  
||||  
|-|-|-|  
|[_fdopen, _wfdopen](../c-runtime-library/reference/fdopen-wfdopen.md)|Associa um fluxo com um arquivo que foi aberto anteriormente para E/S de nível inferior e retorna um ponteiro para o fluxo aberto.|[System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.filestream.aspx)|  
|[_fileno](../c-runtime-library/reference/fileno.md)|Obtém o descritor de arquivo associado a um fluxo.|[System::IO::FileStream::Handle](https://msdn.microsoft.com/en-us/library/system.io.filestream.handle.aspx)|  
|[_get_osfhandle](../c-runtime-library/reference/get-osfhandle.md)|Retornar identificador de arquivo do sistema operacional associado ao descritor de arquivo de tempo de execução C existente|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).|  
|[_open_osfhandle](../c-runtime-library/reference/open-osfhandle.md)|Associa o descritor de arquivo de tempo de execução C com um identificador de arquivo do sistema operacional existente.|[System::IO::FileStream::Handle](https://msdn.microsoft.com/en-us/library/system.io.filestream.handle.aspx)|  
  
 As seguintes funções do Win32 também abrem arquivos e pipes:  
  
-   [CreateFile](http://msdn.microsoft.com/library/windows/desktop/aa363858.aspx)  
  
-   [CreatePipe](http://msdn.microsoft.com/library/windows/desktop/aa365152.aspx)  
  
-   [CreateNamedPipe](http://msdn.microsoft.com/library/windows/desktop/aa365150.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)   
 [Controle de diretório](../c-runtime-library/directory-control.md)   
 [Chamadas do sistema](../c-runtime-library/system-calls.md)


<!--HONumber=Feb17_HO4-->


