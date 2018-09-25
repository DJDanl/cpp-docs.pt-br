---
title: 'Guia de portabilidade: Spy++ | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: e558f759-3017-48a7-95a9-b5b779d5e51d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 84aded46176c1c286ce5270254a0455dfce39d5d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46427860"
---
# <a name="porting-guide-spy"></a>Guia de portabilidade: Spy++

Este estudo de caso de portabilidade foi projetado para dar a você uma ideia de como é um projeto típico de portabilidade, dos tipos de problemas que você pode encontrar e algumas dicas gerais e truques para resolver problemas de portabilidade. Ele não foi projetado para ser um guia definitivo de portabilidade, uma vez que a experiência de portar um projeto depende muito das especificidades do código.  
  
## <a name="spy"></a>Spy++  
 
O Spy++ é uma ferramenta de diagnóstico de GUI amplamente utilizada para a Área de Trabalho do Windows, que fornece todos os tipos de informações sobre os elementos de interface do usuário na Área de Trabalho do Windows. Ele mostra a hierarquia de janelas completa e fornece acesso aos metadados sobre cada janela e controle. Este aplicativo útil é fornecido com o Visual Studio há muitos anos. Encontramos uma versão antiga dele que foi compilada pela última vez em Visual C++ 6.0 e o portamos para Visual Studio 2015. A experiência do Visual Studio 2017 deve ser quase idêntica.
  
Consideramos este caso como sendo típico para portabilidade de aplicativos da Área de Trabalho do Windows que usam o MFC e a API do Win32, especialmente para projetos antigos que não foram atualizados com cada versão do Visual C++ desde o Visual C++ 6.0.  
  
##  <a name="convert_project_file"></a> Etapa 1. Conversão do arquivo de projeto.  

O arquivo de projeto, dois arquivos .dsw antigos do Visual C++ 6.0, foram convertidos facilmente e sem problemas que exigissem mais atenção. Um projeto é o aplicativo Spy++. O outro é o SpyHk, escrito em C, uma DLL de suporte. Projetos mais complexos podem não ser atualizados tão facilmente, conforme discutido [aqui](../porting/visual-cpp-porting-and-upgrading-guide.md).  
  
Depois de atualizar os dois projetos, nossa solução tinha esta aparência:  
  
![A Solução Spy&#43;&#43;](../porting/media/spyxxsolution.PNG "SpyxxSolution")  
  
Temos dois projetos, um com um grande número de arquivos de C++ e o outro com uma DLL que é escrita em C.  
  
##  <a name="header_file_problems"></a> Etapa 2. Problemas de arquivos de cabeçalho  

Ao compilar um projeto recém-convertido, uma das primeiras coisas que você descobrirá com frequência é que os arquivos de cabeçalho usados por projeto não terão sido encontrados.  
  
Um dos arquivos que não puderam ser encontrados em Spy++ foi verstamp.h. De uma pesquisa na Internet, determinamos se isso é proveniente de um SDK de DAO, uma tecnologia de dados obsoleta. Gostaríamos de saber quais símbolos estavam sendo usados desse arquivo de cabeçalho, para assim ver se esse arquivo era realmente necessário ou se os símbolos foram definidos em outro lugar, de modo que pudéssemos comentar a declaração do arquivo de cabeçalho e recompilar. Acontece que apenas um símbolo é necessário, VER_FILEFLAGSMASK.  
  
```  
1>C:\Program Files (x86)\Windows Kits\8.1\Include\shared\common.ver(212): error RC2104: undefined keyword or key name: VER_FILEFLAGSMASK  
```  
  
A maneira mais fácil de encontrar um símbolo nos arquivos de inclusão disponíveis é usar **Localizar em Arquivos** (**Ctrl**+**Shift**+**F**) e especificar **Diretórios de Inclusão do Visual C++**. Nós o encontramos em ntverp.h. Substituímos a inclusão de verstamp.h por ntverp.h e esse erro desapareceu.  
  
##  <a name="linker_output_settings"></a> Etapa 3. Configuração OutputFile do vinculador  

Projetos mais antigos, às vezes, têm arquivos colocados em locais não convencionais que podem causar problemas após a atualização. Nesse caso, precisamos adicionar `$(SolutionDir)` ao caminho de **Include** nas propriedades do projeto para garantir que o Visual Studio possa encontrar alguns arquivos de cabeçalho colocados nesse local, em vez de em uma das pastas do projeto.  
  
O MSBuild reclama que a propriedade **Link.OutputFile** não corresponde aos valores de **TargetPath** e **TargetName**, emitindo MSB8012.  
  
```Output  
warning MSB8012: TargetPath(...\spyxx\spyxxhk\.\..\Debug\SpyxxHk.dll) does not match the Linker's OutputFile property value (...\spyxx\Debug\SpyHk55.dll). This may cause your project to build incorrectly. To correct this, please make sure that $(OutDir), $(TargetName) and $(TargetExt) property values match the value specified in %(Link.OutputFile).warning MSB8012: TargetName(SpyxxHk) does not match the Linker's OutputFile property value (SpyHk55). This may cause your project to build incorrectly. To correct this, please make sure that $(OutDir), $(TargetName) and $(TargetExt) property values match the value specified in %(Link.OutputFile).  
```  
  
**Link.OutputFile** é a saída de build (por exemplo, EXE, DLL) e normalmente é construído de `$(TargetDir)$(TargetName)$(TargetExt)`, fornecendo o caminho, o nome do arquivo e a extensão. Esse é um erro comum ao migrar projetos da ferramenta de build do Visual C++ antiga (vcbuild.exe) para a nova ferramenta de build (MSBuild.exe). Visto que a alteração da ferramenta de build ocorreu no Visual Studio 2010, você poderá encontrar esse problema sempre que migrar um projeto de versão anterior a 2010 para uma versão 2010 ou posterior. O problema básico é que o assistente de migração de projeto não atualiza o valor de **Link.OutputFile**, pois nem sempre é possível determinar o que seu valor deve ser com base nas outras configurações do projeto. Portanto, você geralmente precisa defini-lo manualmente. Para obter mais detalhes, consulte esta [postagem](http://blogs.msdn.com/b/vcblog/archive/2010/03/02/visual-studio-2010-c-project-upgrade-guide.aspx) no blog do Visual C++.  
  
Nesse caso, a propriedade **Link.OutputFile** no projeto convertido foi definida como .\Debug\Spyxx.exe e .\Release\Spyxx.exe para o projeto Spy++, dependendo da configuração. A melhor opção é simplesmente substituir esses valores codificados por `$(TargetDir)$(TargetName)$(TargetExt)` para **Todas as Configurações**. Se isso não funcionar, você poderá personalizar daí ou então alterar as propriedades na seção **Geral**, em que esses valores são definidos (as propriedades são **Diretório de Saída**, **Nome do Destino** e **Extensão de Destino**. Lembre-se de que se a propriedade que você está exibindo utiliza macros, você pode escolher **Editar** na lista suspensa para exibir uma caixa de diálogo que mostra a cadeia de caracteres final com as substituições de macro feitas. Você pode exibir todas as macros disponíveis e seus valores atuais, escolhendo o botão **Macros**.  
  
##  <a name="updating_winver"></a> Etapa 4. Atualizando a Versão de Destino do Windows  

O próximo erro indica que não há mais suporte para versão WINVER no MFC. WINVER para Windows XP é 0x0501.  
  
```Output  
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxv_w32.h(40): fatal error C1189: #error:  MFC does not support WINVER less than 0x0501.  Please change the definition of WINVER in your project properties or precompiled header.  
```  
  
A Microsoft não dá mais suporte ao Windows XP, portanto, mesmo que seja permitido usá-lo como destino no Visual Studio 2015, você deve eliminar gradativamente o suporte para ele em seus aplicativos e incentivar os usuários a adotar as novas versões do Windows.  
  
Para eliminar o erro, defina WINVER atualizando a configuração **Propriedades do Projeto** para a versão mais antiga do Windows que você deseja usar como destino no momento. Encontre uma tabela de valores para várias versões do Windows [aqui](/windows/desktop/WinProg/using-the-windows-headers).  
  
O arquivo stdafx.h continha algumas dessas definições de macro.  
  
```cpp  
#define WINVER       0x0500  // these defines are set so that we get the  
#define _WIN32_WINNT 0x0500  // maximum set of message/flag definitions,  
#define _WIN32_IE    0x0400  // from both winuser.h and commctrl.h.    
```  
  
Definiremos WINVER para o Windows 7. Mais tarde, será mais fácil ler o código se você usar a macro para o Windows 7 (_WIN32_WINNT_WIN7), em vez do valor em si (0x0601).  
  
```cpp  
#define WINVER _WINNT_WIN32_WIN7 // Minimum targeted Windows version is Windows 7  
```  
  
##  <a name="linker_errors"></a> Etapa 5. Erros de Vinculador  

Com essas alterações, o projeto SpyHk (DLL) é compilado mas produz um erro do vinculador.  
  
```  
LINK : warning LNK4216: Exported entry point _DLLEntryPoint@12  
```  
  
O ponto de entrada para uma DLL não deve ser exportado. O ponto de entrada é destinado apenas para ser chamado pelo carregador de quando a DLL é carregada pela primeira vez na memória, portanto, ele não deve estar na tabela de exportação, a qual é para outros chamadores. Precisamos apenas nos certificar de que ele não tem a diretiva **__declspec(dllexport)** anexada a ele. Em spyxxhk.c, precisamos removê-lo de dois locais, a declaração e a definição de `DLLEntryPoint`. Nunca fez sentido usar esta diretiva, mas versões anteriores do compilador e vinculador não sinalizaram isso como um problema. As versões mais recentes do vinculador dão um aviso.  
  
```cpp  
// deleted __declspec(dllexport)  
BOOL WINAPI DLLEntryPoint(HINSTANCE hinstDLL,DWORD fdwReason, LPVOID lpvReserved);    
```  
  
O projeto C DLL, SpyHK.dll, agora é compilado e vinculado sem erros.  
  
##  <a name="outdated_header_files"></a> Etapa 6. Mais arquivos de cabeçalho desatualizados  
 
Agora começamos a trabalhar no principal projeto executável, Spyxx.  
  
Não foi possível encontrar um par de outros arquivos de inclusão: ctl3d.h e penwin.h. Embora possa ser útil pesquisar na Internet para tentar identificar o que incluiu o cabeçalho, às vezes a informação não é tão útil assim. Descobrimos que ctl3d.h fazia parte do Kit de desenvolvimento do Exchange e dava suporte para um determinado estilo dos controles no Windows 95, enquanto penwin.h está relacionado a Window Pen Computing, uma API obsoleta. Nesse caso, simplesmente comentamos a linha `#include` e lidamos com os símbolos indefinidos como fizemos com verstamp.h. Tudo que se relaciona aos Controles 3D ou Pen Computing foi removido do projeto.  
  
Dado um projeto com muitos erros de compilação que você está eliminando gradualmente, não é realista localizar todos os usos de uma API desatualizada imediatamente após você remover a diretiva `#include`. Nós não o detectamos imediatamente, mas em algum momento posterior encontramos um erro de que WM_DLGBORDER estava indefinido. Ele é, na verdade, apenas um de muitos símbolos indefinidos que vêm de ctl3d.h. Depois de determinarmos que ele se relaciona com uma API desatualizada, removemos todas as referências para ele no código.  
  
##  <a name="updating_iostreams_code"></a> Etapa 7. Atualizando o código antigo de iostreams  
 
O próximo erro é comum com código antigo de C++ que usa iostreams.  
  
mstream.h(40): erro fatal C1083: não é possível abrir o arquivo de inclusão: 'iostream.h': arquivo ou diretório inexistente  
  
O problema é que a biblioteca de iostreams antiga foi removida e substituída. Precisamos substituir os antigos iostreams pelos padrões mais recentes.  
  
```cpp  
#include <iostream.h>  
#include <strstrea.h>  
#include <iomanip.h>    
```  
  
Eis o que a atualização inclui:  
  
```cpp  
#include <iostream>  
#include <sstream>  
#include <iomanip>    
```  
  
Com essa alteração, temos problemas com `ostrstream`, que não é mais usado. A substituição adequada é ostringstream. Tentamos adicionar um **typedef** para `ostrstream` para evitar modificar muito o código, pelo menos inicialmente.  
  
```cpp  
typedef std::basic_ostringstream<TCHAR> ostrstream;    
```  
  
Atualmente, o projeto é compilado usando MBCS (Conjunto de Caracteres Multibyte), então **char** é o tipo de dados de caractere apropriado. No entanto, para permitir uma atualização mais fácil do código para Unicode UTF-16, podemos atualizá-lo para `TCHAR`, que é resolvido como **char** ou **wchar_t**, dependendo de como a propriedade **Conjunto de Caracteres** nas configurações do projeto está definida: MBCS ou Unicode.  
  
Alguns outros trechos de código precisam ser atualizados.  Substituímos a classe base de `ios` por `ios_base` e substituímos ostream por basic_ostream\<T>. Adicionamos duas definições de tipo adicionais e esta seção é compilada.  
  
```cpp  
typedef std::basic_ostream<TCHAR> ostream;  
typedef ios_base ios;    
```  
  
Usar essas typedefs é apenas uma solução temporária. Para uma solução mais permanente, podemos atualizar cada referência à API renomeada ou desatualizada.  
  
Aqui está o próximo erro.  
  
```Output  
error C2039: 'freeze': is not a member of 'std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>>'  
```  
  
O próximo problema é que `basic_stringbuf` não tem um método `freeze`. O método `freeze` é usado para evitar um vazamento de memória no `ostream` antigo. Ele não é necessário agora que estamos usando o novo `ostringstream`. Podemos excluir a chamada para `freeze`.  
  
```cpp  
//rdbuf()->freeze(0);  
```  
  
Os próximos dois erros ocorreram em linhas adjacentes. O primeiro reclama sobre o uso de `ends`, que é o manipulador de E/S da biblioteca de `iostream` antiga que adiciona um terminador nulo a uma cadeia de caracteres. O segundo desses erros explica que a saída do método `str` não pode ser atribuída a um ponteiro não const.  
  
```cpp  
// Null terminate the string in the buffer and  
// get a pointer to it.  
//  
*this << ends;  
LPSTR psz = str();    
```  
  
```Output  
2>mstream.cpp(167): error C2065: 'ends': undeclared identifier2>mstream.cpp(168): error C2440: 'initializing': cannot convert from 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>' to 'LPSTR'  
```  
  
Usando a nova biblioteca de fluxo, `ends` não é necessário porque a cadeia de caracteres sempre é terminada em nulo, portanto, essa linha pode ser removida. No segundo problema, `str()` agora não retorna um ponteiro para a matriz de caracteres para uma cadeia de caracteres; ele retorna o tipo `std::string`. A solução para o segundo problema é alterar o tipo para `LPCSTR` e usar o método `c_str()` para solicitar o ponteiro.  
  
```cpp  
//*this << ends;  
LPCTSTR psz = str().c_str();    
```  
  
Um erro nos confundiu por um tempo ocorreu nesse código.  
  
```cpp  
MOUT << _T(" chUser:'") << chUser  
<< _T("' (") << (INT)(UCHAR)chUser << _T(')');    
```  
  
A macro MOUT é resolvida para \*g_pmout, que é um objeto do tipo `mstream`. A classe `mstream` é derivada da classe de cadeia de caracteres de saída padrão, `std::basic_ostream<TCHAR>.`. No entanto, com _T em torno do literal de cadeia de caracteres, que colocamos em preparação para a conversão para Unicode, a resolução de sobrecarga para o **operador <<** falha com a seguinte mensagem de erro:  
  
```Output  
1>winmsgs.cpp(4612): error C2666: 'mstream::operator <<': 2 overloads have similar conversions
1>  c:\source\spyxx\spyxx\mstream.h(120): note: could be 'mstream &mstream::operator <<(ios &(__cdecl *)(ios &))'
1>  c:\source\spyxx\spyxx\mstream.h(118): note: or       'mstream &mstream::operator <<(ostream &(__cdecl *)(ostream &))'
1>  c:\source\spyxx\spyxx\mstream.h(116): note: or       'mstream &mstream::operator <<(ostrstream &(__cdecl *)(ostrstream &))'
1>  c:\source\spyxx\spyxx\mstream.h(114): note: or       'mstream &mstream::operator <<(mstream &(__cdecl *)(mstream &))'
1>  c:\source\spyxx\spyxx\mstream.h(109): note: or       'mstream &mstream::operator <<(LPTSTR)'
1>  c:\source\spyxx\spyxx\mstream.h(104): note: or       'mstream &mstream::operator <<(TCHAR)'
1>  c:\source\spyxx\spyxx\mstream.h(102): note: or       'mstream &mstream::operator <<(DWORD)'
1>  c:\source\spyxx\spyxx\mstream.h(101): note: or       'mstream &mstream::operator <<(WORD)'
1>  c:\source\spyxx\spyxx\mstream.h(100): note: or       'mstream &mstream::operator <<(BYTE)'
1>  c:\source\spyxx\spyxx\mstream.h(95): note: or       'mstream &mstream::operator <<(long)'
1>  c:\source\spyxx\spyxx\mstream.h(90): note: or       'mstream &mstream::operator <<(unsigned int)'
1>  c:\source\spyxx\spyxx\mstream.h(85): note: or       'mstream &mstream::operator <<(int)'
1>  c:\source\spyxx\spyxx\mstream.h(83): note: or       'mstream &mstream::operator <<(HWND)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(1132): note: or       'CDumpContext &operator <<(CDumpContext &,COleSafeArray &)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(1044): note: or       'CArchive &operator <<(CArchive &,ATL::COleDateTimeSpan)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(1042): note: or       'CDumpContext &operator <<(CDumpContext &,ATL::COleDateTimeSpan)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(1037): note: or       'CArchive &operator <<(CArchive &,ATL::COleDateTime)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(1035): note: or       'CDumpContext &operator <<(CDumpContext &,ATL::COleDateTime)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(1030): note: or       'CArchive &operator <<(CArchive &,COleCurrency)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(1028): note: or       'CDumpContext &operator <<(CDumpContext &,COleCurrency)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(955): note: or       'CArchive &operator <<(CArchive &,ATL::CComBSTR)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(951): note: or       'CArchive &operator <<(CArchive &,COleVariant)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h(949): note: or       'CDumpContext &operator <<(CDumpContext &,COleVariant)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxwin.h(248): note: or       'CArchive &operator <<(CArchive &,const RECT &)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxwin.h(247): note: or       'CArchive &operator <<(CArchive &,POINT)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxwin.h(246): note: or       'CArchive &operator <<(CArchive &,SIZE)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxwin.h(242): note: or       'CDumpContext &operator <<(CDumpContext &,const RECT &)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxwin.h(241): note: or       'CDumpContext &operator <<(CDumpContext &,POINT)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxwin.h(240): note: or       'CDumpContext &operator <<(CDumpContext &,SIZE)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afx.h(1639): note: or       'CArchive &operator <<(CArchive &,const CObject *)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afx.h(1425): note: or       'CArchive &operator <<(CArchive &,ATL::CTime)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afx.h(1423): note: or       'CDumpContext &operator <<(CDumpContext &,ATL::CTime)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afx.h(1418): note: or       'CArchive &operator <<(CArchive &,ATL::CTimeSpan)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afx.h(1416): note: or       'CDumpContext &operator <<(CDumpContext &,ATL::CTimeSpan)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\ostream(694): note: or       'std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &std::operator <<<wchar_t,std::char_traits<wchar_t>>(std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &,const char *)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\ostream(741): note: or       'std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &std::operator <<<wchar_t,std::char_traits<wchar_t>>(std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &,char)'
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\ostream(866): note: or       'std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &std::operator <<<wchar_t,std::char_traits<wchar_t>>(std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &,const _Elem *)'
1>          with
1>          [
1>              _Elem=wchar_t
1>          ]
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\ostream(983): note: or       'std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &std::operator <<<wchar_t,std::char_traits<wchar_t>,wchar_t[10]>(std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &&,const _Ty (&))'
1>          with
1>          [
1>              _Ty=wchar_t [10]
1>          ]
1>  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\ostream(1021): note: or       'std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &std::operator <<<wchar_t,std::char_traits<wchar_t>>(std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &,const std::error_code &)'
1>  winmsgs.cpp(4612): note: while trying to match the argument list '(CMsgStream, const wchar_t [10])'  
```  
  
Há tantas definições de **operador <<** que esse tipo de erro pode ser intimidante. Depois de examinar mais de perto as sobrecargas disponíveis, podemos ver que a maioria delas são irrelevantes e, verificando mais de perto a definição da classe `mstream`, identificamos a função a seguir que achamos que deve ser chamada nesse caso.  
  
```cpp  
mstream& operator<<(LPTSTR psz)  
{  
  return (mstream&)ostrstream::operator<<(psz);  
}    
```  
  
O motivo pelo qual ela não é chamada é que o literal da cadeia de caracteres tem o tipo `const wchar_t[10]` como você pode ver na última linha daquela longa mensagem de erro, então a conversão para um ponteiro não const não é automática. No entanto, esse operador não deve modificar o parâmetro de entrada, portanto, o tipo de parâmetro mais apropriado é `LPCTSTR` (`const char*` ao compilar como MBCS e `const wchar_t*` como Unicode), não `LPTSTR` (`char*` ao compilar como MBCS e `wchar_t*` como Unicode). Realizar essa alteração corrige esse erro.  
  
Esse tipo de conversão foi permitido sob o compilador mais antigo e menos rígido, mas alterações de conformidade mais recentes requerem código mais correto.  
  
##  <a name="stricter_conversions"></a> Etapa 8. As conversões mais restritas do compilador  
 
Também obtemos muitos erros como o seguinte:  
  
```  
error C2440: 'static_cast': cannot convert from 'UINT (__thiscall CHotLinkCtrl::* )(CPoint)' to 'LRESULT (__thiscall CWnd::* )(CPoint)'  
```  
  
O erro ocorre em um mapa de mensagem que é simplesmente uma macro:  
  
```cpp  
BEGIN_MESSAGE_MAP(CFindToolIcon, CWnd)  
// other messages omitted...  
ON_WM_NCHITTEST() // Error occurs on this line.  
END_MESSAGE_MAP()  
```  
  
Indo para a definição deste macro, podemos ver que ele faz referência à função `OnNcHitTest`.  
  
```cpp  
#define ON_WM_NCHITTEST() \  
{ WM_NCHITTEST, 0, 0, 0, AfxSig_l_p, \  
(AFX_PMSG)(AFX_PMSGW) \  
(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(CPoint) > (&ThisClass :: OnNcHitTest)) },  
```  
  
O problema tem a ver com a incompatibilidade no ponteiro para os tipos de função de membro. O problema não é a conversão de `CHotLinkCtrl` como um tipo de classe para `CWnd` como o tipo de classe, já que é essa uma conversão válida de classe derivada para classe base. O problema é o tipo de retorno: UINT vs. LRESULT. LRESULT é resolvido para LONG_PTR, que é um ponteiro de 64 bits ou um ponteiro de 32 bits dependendo do tipo binário de destino, então UINT não é convertido para esse tipo. Isso não é incomum ao atualizar o código escrito antes de 2005, já que o tipo de retorno de vários métodos de mapa de mensagens foram alterados de UINT para LRESULT no Visual Studio 2005 como parte das alterações de compatibilidade de 64 bits. Alteramos o tipo de retorno no código a seguir de UINT para LRESULT:  
  
```cpp  
afx_msg UINT OnNcHitTest(CPoint point);  
```  
  
Após a alteração, temos o seguinte código:  
  
```cpp  
afx_msg LRESULT OnNcHitTest(CPoint point);  
```  
  
Como há cerca de dez ocorrências dessa função, todas em diferentes classes derivadas de CWnd, é útil usar **Ir Para Definição** (teclado: **F12**) e **Ir Para Declaração** (teclado: **Ctrl**+**F12**) quando o cursor está sobre a função no editor para localizar essas ocorrências e navegar para elas da janela de ferramentas **Localizar Símbolo**. **Ir Para Definição** é geralmente o mais útil dos dois. **Ir Para Declaração** localizará declarações que não sejam a declaração de classe definidora, assim como declarações de classe friend ou referências de encaminhamento.  
  
##  <a name="mfc_changes"></a> Etapa 9. Alterações do MFC  
 
O próximo erro também está relacionado a um tipo de declaração alterado e também ocorre em uma macro.  
  
```Output  
error C2440: 'static_cast': cannot convert from 'void (__thiscall CFindWindowDlg::* )(BOOL,HTASK)' to 'void (__thiscall CWnd::* )(BOOL,DWORD)'  
```  
  
O problema é que o segundo parâmetro de `CWnd::OnActivateApp` foi alterado de HTASK para DWORD. Essa alteração ocorreu na versão de 2002 do Visual Studio, Visual Studio .NET.  
  
```cpp  
afx_msg void OnActivateApp(BOOL bActive, HTASK hTask);  
```  
  
Precisamos atualizar as declarações de OnActivateApp em classes derivadas adequadamente, da seguinte maneira:  
  
```cpp  
afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadId);  
```  
  
Neste ponto, somos capazes de compilar o projeto. No entanto, há alguns avisos que precisamos trabalhar para resolver, além de partes opcionais da atualização como a conversão de MBCS em Unicode ou o aprimoramento da segurança usando as funções de CRT Seguro.  
  
##  <a name="compiler_warnings"></a> Etapa 10. Tratando dos avisos do compilador  

Para obter uma lista completa de avisos, você deve executar um **Recompilar Todos** na solução em vez de um build comum para ter certeza de que tudo que anteriormente foi compilado anteriormente será recompilado, já que você obtém apenas os relatórios de aviso do build atual. A outra pergunta é se deseja aceitar o nível de aviso atual ou usar um nível de aviso mais elevado.  Ao realizar portabilidade de muito código, especialmente código antigo, usar um nível de aviso mais elevado pode ser apropriado.  Você também poderá começar com o nível de aviso padrão e, em seguida, aumentar o nível de aviso para obter todos os avisos. Se você usa `/Wall`, recebe alguns avisos nos arquivos de cabeçalho do sistema, então muitas pessoas usam `/W4` para receber a maioria dos avisos no seu código sem receber avisos para os cabeçalhos do sistema. Se desejar que os avisos apareçam como erros, adicione a opção `/WX`. Essas configurações estão na seção **C/C++** da caixa de diálogo **Propriedades do Projeto**.  
  
Um dos métodos na classe `CSpyApp` produz um aviso sobre uma função para a qual não há mais suporte.  
  
```cpp  
void SetDialogBkColor() {CWinApp::SetDialogBkColor(::GetSysColor(COLOR_BTNFACE));}  
```  
  
O aviso é conforme descrito a seguir.  
  
```Output  
warning C4996: 'CWinApp::SetDialogBkColor': CWinApp::SetDialogBkColor is no longer supported. Instead, handle WM_CTLCOLORDLG in your dialog  
```  
  
A mensagem WM_CTLCOLORDLG já foi tratada no código do Spy++, portanto, a única alteração necessária foi excluir todas as referências a `SetDialogBkColor`, que não é mais necessária.  
  
O próximo aviso era muito simples de corrigir, comentando o nome da variável. Recebemos o seguinte aviso:  
  
```Output  
warning C4456: declaration of 'lpszBuffer' hides previous local declaration  
```  
  
O código que produz isso envolve uma macro.  
  
```cpp  
DECODEPARM(CB_GETLBTEXT)  
{  
  P2WPOUT();  
  
  P2LPOUTPTRSTR;  
  P2IFDATA()  
  {  
    PARM(lpszBuffer, PPACK_STRINGORD, ED2);  
      
    INDENT();  
      
    P2IFISORD(lpszBuffer)  
    {  
      P2OUTORD(lpszBuffer);  
    }  
    else  
    {  
      PARM(lpszBuffer, LPTSTR, ED2);  
      P2OUTS(lpszBuffer);  
    }  
  }  
}    
```  
  
O uso intenso de macros como encontrado nesse código tende a tornar o código mais difícil de manter. Nesse caso, as macros incluem as declarações das variáveis. A macro PARM é definida da seguinte maneira:  
  
```cpp  
#define PARM(var, type, src)type var = (type)src  
```  
  
Portanto, a variável `lpszBuffer` é declarada duas vezes na mesma função. Corrigir isso não é tão simples quanto seria se o código não estivesse usando macros (simplesmente remover a segunda declaração de tipo). Como está, temos a opção ruim de ter de decidir se reescrevemos o código de macro como código comum (uma tarefa entediante e possivelmente propensa a erros) ou desabilitamos o aviso.  
  
Nesse caso, optamos por desabilitar o aviso. É possível fazer isso adicionando um pragma da seguinte forma:  
  
```cpp  
#pragma warning(disable : 4456)  
```  
  
Ao desabilitar um aviso, você talvez queira restringir o efeito de desabilitação ao código que produz o aviso, para evitar suprimir o aviso quando ele puder fornecer informações úteis. Adicionamos código para restaurar o aviso logo após a linha que o produz ou melhor ainda, uma vez que esse aviso ocorre em uma macro, use a palavra-chave **__pragma**, que funciona em macros (`#pragma` não funciona em macros).  
  
```cpp  
#define PARM(var, type, src)__pragma(warning(disable : 4456))  \  
type var = (type)src \  
__pragma(warning(default : 4456))    
```  
  
O próximo aviso requer algumas revisões de código. A API do Win32 `GetVersion` (e `GetVersionEx`) foi preterida.  
  
```Output  
warning C4996: 'GetVersion': was declared deprecated  
```  
  
O código a seguir mostra como a versão é obtida.  
  
```cpp  
// check Windows version and set m_bIsWindows9x/m_bIsWindows4x/m_bIsWindows5x flags accordingly.  
DWORD dwWindowsVersion = GetVersion();    
```  
  
Isso é seguido por uma quantidade grande de código, que examina o valor de dwWindowsVersion para determinar se estamos executando no Windows 95 e qual a versão do Windows NT. Como tudo isso está desatualizado, podemos remover o código e lidar com quaisquer eventuais referências a essas variáveis.  
  
O artigo [Alterações de versão do sistema operacional no Windows 8.1 e Windows Server 2012 R2](https://msdn.microsoft.com/library/windows/desktop/dn302074.aspx) explica a situação.  
  
Existem métodos na classe `CSpyApp` que consultam a versão do sistema operacional: `IsWindows9x`, `IsWindows4x` e `IsWindows5x`. Um bom ponto de partida é considerar que as versões do Windows às quais pretendemos dar suporte (Windows 7 e posterior) são todas próximas do Windows NT 5 no que se refere às tecnologias usadas por esse aplicativo mais antigo. Os usos desses métodos eram para lidar com as limitações dos sistemas operacionais mais antigos. Alteramos então esses métodos para retornar TRUE para `IsWindows5x` e FALSE para os outros.  
  
```cpp  
BOOL IsWindows9x() {/*return(m_bIsWindows9x);*/ return FALSE;  }  
BOOL IsWindows4x() {/*return(m_bIsWindows4x);*/ return FALSE;  }  
BOOL IsWindows5x() {/*return(m_bIsWindows5x);*/ return TRUE;  }    
```  
  
Isso fez com que restassem apenas alguns poucos locais em que as variáveis internas foram usadas diretamente. Já que removemos essas variáveis, obtemos alguns erros com os quais precisamos lidar explicitamente.  
  
```Output  
error C2065: 'm_bIsWindows9x': undeclared identifier  
```  
  
```cpp  
void CSpyApp::OnUpdateSpyProcesses(CCmdUI *pCmdUI)  
{  
  pCmdUI->Enable(m_bIsWindows9x || hToolhelp32 != NULL);  
}    
```  
  
Poderíamos substituir isso por uma chamada de método ou simplesmente passar TRUE e remover o caso antigo especial para Windows 9x.  
  
```cpp  
void CSpyApp::OnUpdateSpyProcesses(CCmdUI *pCmdUI)  
{  
  pCmdUI->Enable(TRUE /*!m_bIsWindows9x || hToolhelp32 != NULL*/);  
}    
```  
  
O aviso final no nível padrão (3) tem a ver com um campo de bits.  
  
```Output  
treectl.cpp(1656): warning C4463: overflow; assigning 1 to bit-field that can only hold values from -1 to 0  
```  
  
O código que dispara este é como demonstrado a seguir.  
  
```cpp  
m_bStdMouse = TRUE;  
```  
  
A declaração de `m_bStdMouse` indica que ele é um campo de bits.  
  
```cpp  
class CTreeListBox : public CListBox  
{  
  DECLARE_DYNCREATE(CTreeListBox)  
    
  CTreeListBox();  
    
  private:  
  int ItemFromPoint(const CPoint& point);  
    
  class CTreeCtl* m_pTree;  
  BOOL m_bGotMouseDown : 1;  
  BOOL m_bDeferedDeselection : 1;  
  BOOL m_bStdMouse : 1;    
```  
  
Esse código foi escrito antes que o tipo bool interno tivesse suporte no Visual C++. Nesse código, BOOL era um **typedef** para **int**. O tipo **int** é um tipo **com sinal** e a representação de bits de um **int com sinal** é usar o primeiro bit como um bit de sinal, então um campo de bits do tipo int poderia ser interpretado como a representação de 0 ou -1, o que provavelmente não é o pretendido.  
  
Você não saberia dizer por que estes são campos de bits apenas olhando o código. Manter o tamanho do objeto pequeno era realmente o intuito ou há algum lugar em que o layout binário do objeto é usado? Nós os alteramos para membros BOOL comuns, já que não vimos nenhum motivo para o uso de um campo de bits. Não há garantia de que usar campos de bits para manter o tamanho de um objeto pequeno funcione. Isso depende de como o compilador dispõe o tipo.  
  
Você deve estar se perguntando se usar o **bool** de tipo padrão em tudo seria útil. Muitos dos padrões de código antigos como o tipo BOOL foram inventados para resolver problemas que foram resolvidos posteriormente em C++ padrão, então alterar de BOOL para o tipo **bool** interno é apenas um exemplo de tal alteração que você considera fazer depois que seu código começa a ser executado na nova versão.  
  
Depois que já lidamos com todos os avisos que apareceram no nível padrão (nível 3), alteramos para nível 4 para capturar alguns avisos adicionais. O primeiro a aparecer era assim:  
  
```Output  
warning C4100: 'nTab': unreferenced formal parameter  
```  
  
O código que produziu este aviso era conforme descrito a seguir.  
  
```cpp  
virtual void OnSelectTab(int nTab) {};  
```  
  
Isso parece bastante inofensivo, mas já que nós queríamos uma compilação limpa com `/W4` e `/WX` definidos, simplesmente comentamos o nome da variável, deixando-a comentada para fins de legibilidade.  
  
```cpp  
virtual void OnSelectTab(int /*nTab*/) {};  
```  
  
Outros avisos que recebemos foram úteis para limpeza de código geral. Há um número de conversões implícitas de **int** ou **int sem sinal** para WORD (que é um typedef de **short sem sinal**). Elas envolvem uma possível perda de dados. Adicionamos uma conversão para WORD nesses casos.  
  
Outro aviso de nível 4 que obtivemos para este código foi:  
  
```Output  
warning C4211: nonstandard extension used: redefined extern to static  
```  
  
O problema ocorre quando uma variável é primeiro declarada como **extern** e posteriormente declarada como **static**. O significado desses dois especificadores de classe de armazenamento é mutuamente exclusivo, mas isso é permitido como uma extensão da Microsoft. Se você quisesse que o código fosse portátil para outros compiladores ou se desejasse compilá-lo com `/Za` (compatibilidade com ANSI), alteraria as declarações para ter especificadores de classe de armazenamento correspondentes.  
  
##  <a name="porting_to_unicode"></a> Etapa 11. Portabilidade de MBCS para Unicode

Observe que, no mundo do Windows, quando dizemos Unicode, normalmente queremos dizer UTF-16. Outros sistemas operacionais como o Linux usam UTF-8, mas o Windows geralmente não. A versão MBCS do MFC foi preterida no Visual Studio 2013 e 2015, mas isso não ocorre mais no Visual Studio 2017. Se você estiver usando o Visual Studio 2013 ou 2015, antes de tomar a decisão de transferir o código MBCS para Unicode UTF-16, elimine temporariamente os avisos de que o MBCS foi preterido, para realizar outros trabalhos ou adiar a portabilidade até um momento conveniente. O código atual usa MBCS e para continuar com isso, precisamos instalar a versão ANSI / MBCS do MFC. A biblioteca do MFC, bastante grande, não faz parte da instalação padrão do Visual Studio **Desenvolvimento para desktop com C++**, portanto, deve ser selecionada por meio dos componentes opcionais no instalador. Veja o [Complemento de DLL do MBCS do MFC](../mfc/mfc-mbcs-dll-add-on.md). Depois de baixar isso e reiniciar o Visual Studio, compile e vincule com a versão MBCS do MFC, mas, para se livrar dos avisos sobre o MBCS, se você estiver usando Visual Studio 2013 ou 2015, adicione também NO_WARN_MBCS_MFC_DEPRECATION à lista de macros predefinidas na seção **Pré-processador** das propriedades do projeto ou ao início do arquivo de cabeçalho stdafx.h ou outro arquivo de cabeçalho comum.  
  
Agora temos alguns erros de vinculador.  
  
```Output  
fatal error LNK1181: cannot open input file 'mfc42d.lib'  
```  
  
LNK1181 ocorre porque uma versão desatualizada da biblioteca estática do mfc está incluída na entrada do vinculador. Isso não é mais necessário, uma vez que é possível vincular o MFC dinamicamente; portanto, precisamos apenas remover todas as bibliotecas estáticas do MFC da propriedade **Entrada** na seção **Vinculador** das propriedades do projeto. Este projeto também está usando a opção `/NODEFAULTLIB` e, em vez disso, ele lista todas as dependências de biblioteca.  
  
```  
msvcrtd.lib;msvcirtd.lib;kernel32.lib;user32.lib;gdi32.lib;advapi32.lib;Debug\SpyHk55.lib;%(AdditionalDependencies)  
```  
  
Agora atualizaremos realmente o código antigo de conjunto de MBCS (Conjunto de Caracteres Multibyte) para Unicode. Já que esse é um aplicativo do Windows, intimamente relacionado com a plataforma desktop do Windows, nós o portaremos para o Unicode UTF-16 usado pelo Windows. Se você está escrevendo código de plataforma cruzada ou portabilidade de um aplicativo do Windows para outra plataforma, talvez você deseje considerar portabilidade para UTF-8, que é amplamente usado em outros sistemas operacionais.  
  
Ao realizar a portabilidade para Unicode UTF-16, devemos decidir se ainda queremos a opção para compilar em MBCS ou não.  Se quisermos ter a opção de dar suporte a MBCS, deveremos usar a macro TCHAR como o tipo de caractere, que resolve para **char** ou **wchar_t**, dependendo do que é definido durante a compilação – _MBCS ou _UNICODE. Mudar para TCHAR e as versões de TCHAR de diversas APIs em vez de **wchar_t** e suas APIs associadas significa que você pode voltar a uma versão MBCS do seu código, simplesmente definindo a macro _MBCS no lugar de _UNICODE. Além de TCHAR, existe uma variedade de versões TCHAR de typedefs, macros e funções amplamente utilizados. Por exemplo, LPCTSTR em vez de LPCSTR e assim por diante. No diálogo de propriedades do projeto, em **Propriedades de Configuração**, na seção **Geral**, altere a propriedade **Conjunto de Caracteres** de **Usar Conjunto de Caracteres MBCS** para **Usar Conjunto de Caracteres Unicode**. Essa configuração afeta a macro predefinida durante a compilação. Há uma macro UNICODE e uma macro _UNICODE. A propriedade do projeto afeta ambas consistentemente. Cabeçalhos do Windows usam UNICODE no qual cabeçalhos do Visual C++ como o MFC usam _UNICODE, mas quando um está definido, o outro está sempre definido.  
  
Existe um bom [guia](https://msdn.microsoft.com/library/cc194801.aspx) para portabilidade de MBCS para Unicode UTF-16 usando TCHAR. Escolhemos essa rota. Primeiro, podemos alterar a propriedade **Conjunto de Caracteres** para **Usar Conjunto de Caracteres Unicode** e recompilar o projeto.  
  
Alguns locais no código já estavam usando TCHAR, aparentemente em antecipação à possibilidade de eventualmente dar suporte a Unicode. Alguns não estavam. Procuramos instâncias de CHAR, que é um **typedef** de **char** e substituímos a maioria deles com TCHAR. Além disso, procuramos por `sizeof(CHAR)`. Quando alteramos de CHAR para TCHAT, geralmente precisamos alterar para `sizeof(TCHAR)`, já que isso foi utilizado frequentemente para determinar o número de caracteres em uma cadeia de caracteres. Usar o tipo errado aqui não produz um erro do compilador, portanto, vale a pena prestar um pouco de atenção a este caso.  
  
Esse tipo de erro é muito comum logo após mudar para Unicode.  
  
```Output  
error C2664: 'int wsprintfW(LPWSTR,LPCWSTR,...)': cannot convert argument 1 from 'CHAR [16]' to 'LPWSTR'  
```  
  
Aqui está um exemplo de código que produz isso:  
  
```cpp  
wsprintf(szTmp, "%d.%2.2d.%4.4d", rmj, rmm, rup);  
```  
  
Colocamos _T em torno de cadeia de caracteres literal para remover o erro.  
  
```cpp  
wsprintf(szTmp, _T("%d.%2.2d.%4.4d"), rmj, rmm, rup);  
```  
  
A macro _T tem o efeito de fazer com que um literal de cadeia de caracteres seja compilado como uma cadeia de caracteres **char** ou uma cadeia de caracteres **wchar_t**, dependendo da configuração de MBCS ou UNICODE. Para substituir todas as cadeias de caracteres por _T no Visual Studio, abra primeiro a caixa **Substituição Rápida** (teclado: **Ctrl**+**F**) ou **Substituir nos Arquivos** (teclado: **Ctrl**+**Shift**+**H**), depois escolha a caixa de seleção **Usar Expressões Regulares**. Digite `((\".*?\")|('.+?'))` como o texto de pesquisa e `_T($1)` como o texto de substituição. Se você já tiver a macro _T em torno de algumas cadeias de caracteres este procedimento a adicionará novamente; além disso, ele também poderá encontrar casos em que você não deseja _T, por exemplo quando você usar `#include`, portanto, é melhor usar **Substituir Próximo** em vez de **Substituir Tudo**.  
  
Essa função específica, [wsprintf](/windows/desktop/api/winuser/nf-winuser-wsprintfa), na verdade é definida nos cabeçalhos do Windows e a documentação para ela recomenda que ela não seja usada, devido a um possível estouro de buffer. Nenhum tamanho é fornecido para o buffer `szTmp`, portanto, não há nenhuma maneira para a função verificar se o buffer pode conter todos os dados a serem gravados nele. Consulte a próxima seção sobre portabilidade para o CRT Seguro, na qual podemos resolver outros problemas semelhantes. Nós acabamos por substituí-lo por [_stprintf_s](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md).  
  
Outro erro comum que você verá na conversão para Unicode é este.  
  
```Output  
error C2440: '=': cannot convert from 'char *' to 'TCHAR *'  
```  
  
O código que o gera é o seguinte:  
  
```cpp  
pParentNode->m_szText = new char[strTitle.GetLength() + 1];  
_tcscpy(pParentNode->m_szText, strTitle);  
```  
  
Embora a função `_tcscpy` tenha sido usada, a qual é a função strcpy TCHAR para copiar uma cadeia de caracteres, o buffer alocado era um buffer de **char**. Isso é facilmente alterado para TCHAR.  
  
```cpp  
pParentNode->m_szText = new TCHAR[strTitle.GetLength() + 1];  
_tcscpy(pParentNode->m_szText, strTitle);    
```  
  
Da mesma forma, alteramos LPSTR (ponteiro longo para cadeia de caracteres) e LPCSTR (ponteiro longo para cadeia de caracteres constante) para LPTSTR (ponteiro longo para cadeia de caracteres TCHAR) e LPCTSTR (ponteiro longo para cadeia de caracteres TCHAR constante), respectivamente, quando justificado por um erro do compilador. Optamos por não fazer essas substituições usando pesquisa e substituição global, porque cada situação precisava ser examinada individualmente. Em alguns casos desejamos a versão **char**, por exemplo ao processar certas mensagens do Windows que usam estruturas do Windows que têm o sufixo **A**. Na API do Windows, o sufixo **A** significa ASCII ou ANSI (e também se aplica a MBCS) e o sufixo **W** significa caracteres largos ou Unicode UTF-16. Esse padrão de nomenclatura é usado nos cabeçalhos do Windows, mas também o seguimos no código Spy++ quando precisamos adicionar uma versão Unicode de uma função que já foi definida somente em uma versão MBCS.  
  
Em alguns casos, tínhamos que substituir um tipo para usar uma versão que fosse resolvida corretamente (por exemplo, WNDCLASS em vez de WNDCLASSA).  
  
Em muitos casos foi necessário usar a versão genérica (macro) de uma API Win32 como `GetClassName` (em vez de `GetClassNameA`). Na instrução switch do manipulador de mensagens, algumas mensagens são específicas de MBCS ou Unicode; nesses casos, precisamos alterar o código para chamar explicitamente a versão MBCS, porque substituímos as funções genericamente nomeadas por funções específicas de **A** e **W** e adicionamos uma macro para o nome genérico que resolve para o nome **A** ou **W** correto, com base em UNICODE ter sido definido ou não.  Em muitas partes do código, quando mudamos para definir _UNICODE, a versão W é agora escolhida mesmo quando a versão **A** é a desejada.  
  
Há alguns locais em que ações especiais precisaram ser executadas. Qualquer uso de `WideCharToMultiByte` ou `MultiByteToWideChar` pode exigir uma análise mais detalhada. Aqui está um exemplo em que `WideCharToMultiByte` estava sendo usado.  
  
```cpp  
BOOL C3dDialogTemplate::GetFont(CString& strFace, WORD& nFontSize)  
{  
  ASSERT(m_hTemplate != NULL);  
    
  DLGTEMPLATE* pTemplate = (DLGTEMPLATE*)GlobalLock(m_hTemplate);  
  if ((pTemplate->style & DS_SETFONT) == 0)  
  {  
    GlobalUnlock(m_hTemplate);  
    return FALSE;  
  }  
    
  BYTE* pb = GetFontSizeField(pTemplate);  
  nFontSize = *(WORD*)pb;  
  pb += sizeof (WORD);  
  WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)pb, -1,  
  strFace.GetBufferSetLength(LF_FACESIZE), LF_FACESIZE, NULL, NULL);  
  strFace.ReleaseBuffer();  
  GlobalUnlock(m_hTemplate);  
  return TRUE;  
}    
```  
  
Para resolver isso, precisamos entender que o motivo pelo qual isso foi feito foi copiar uma cadeia de caracteres largos que representa o nome de uma fonte para o buffer interno de um `CString`, `strFace`. Isso exigiu código ligeiramente diferente para cadeias de caracteres `CString` multibyte do que aquele usado para cadeias de caracteres largos `CString`, então adicionamos um `#ifdef` nesse caso.  
  
```cpp  
#ifdef _MBCS  
WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)pb, -1,  
strFace.GetBufferSetLength(LF_FACESIZE), LF_FACESIZE, NULL, NULL);  
strFace.ReleaseBuffer();  
#else  
wcscpy(strFace.GetBufferSetLength(LF_FACESIZE), (LPCWSTR)pb);  
strFace.ReleaseBuffer();  
#endif    
```  
  
É claro que, em vez de `wcscpy`, devemos na verdade usar `wcscpy_s`, a versão mais segura. A próxima seção aborda isso.  
  
Como uma verificação de nosso trabalho, devemos redefinir o **Conjunto de Caracteres** para **Usar Conjunto de Caracteres Multibyte** e assegurar que o código ainda é compilado usando MBCS, bem como Unicode. Obviamente, um teste completo deve ser executado no aplicativo recompilado depois de todas essas alterações.  
  
Em nosso trabalho com essa solução Spy ++, levou aproximadamente dois dias de trabalho para um desenvolvedor de C++ de nível médio converter o código para Unicode. Isso não incluiu o tempo usado para testar novamente.  
  
##  <a name="porting_to_secure_crt"></a> Etapa 12. Portabilidade para usar o CRT Seguro  
 
Portabilidade do código para usar as versões seguras (as versões com o sufixo **_s**) de funções CRT é o próximo tópico. Nesse caso, a estratégia geral é substituir a função pela versão **_s** e em seguida, geralmente, adicionar os parâmetros de tamanho do buffer adicional necessário. Em muitos casos isso é fácil, já que o tamanho é conhecido. Em outros casos, quando o tamanho não estiver imediatamente disponível, será necessário adicionar parâmetros adicionais à função que estiver usando a função CRT ou talvez examinar o uso do buffer de destino e ver quais são os limites de tamanho apropriados.  
  
O Visual C++ fornece um truque para facilitar a obtenção de segurança no código sem adicionar tantos parâmetros de tamanho, que é pelo uso das sobrecargas de modelo. Já que essas sobrecargas são modelos, elas só estão disponíveis ao compilar como C++, não como C. Spyxxhk é um projeto C, portanto, o truque não funcionará ele.  No entanto, Spyxx não é e podemos usar o truque. O truque é adicionar uma linha como esta em um local em que ela será compilada em todos os arquivos de projeto, assim como em stdafx.h:  
  
```cpp  
#define _CRT_SECURE_TEMPLATE_OVERLOADS 1  
```  
  
Quando você define isso, sempre que o buffer é uma matriz e não um ponteiro bruto, seu tamanho é inferido do tipo de matriz e isso é usado como o parâmetro de tamanho, sem que seja necessário fornecê-lo. Que ajuda a reduzir a complexidade de reescrever o código. Você ainda tem que substituir o nome da função pela versão **_s**, mas isso geralmente pode ser feito por uma operação de pesquisa e substituição.  
  
Os valores retornados por algumas funções sofreram alterações. Por exemplo, `_itoa_s` (e `_itow_s` e a macro `_itot_s`) retorna um código de erro (`errno_t`) em vez da cadeia de caracteres. Nesses casos, você precisará mover a chamada para `_itoa_s` para uma linha separada e substituí-lo pelo identificador do buffer.  
  
Alguns dos casos comuns: para `memcpy`, ao mudar para `memcpy_s`, frequentemente adicionamos o tamanho da estrutura para a qual a cópia está sendo realizada. Da mesma forma, para a maioria das cadeias de caracteres e buffers, o tamanho da matriz ou buffer facilmente é determinado da declaração do buffer ou pela localização de onde o buffer foi originalmente alocado. Em algumas situações você precisa determinar qual tamanho de um buffer está realmente disponível e, se essa informação não está disponível no escopo da função que você está modificando, ela deve ser adicionada como um parâmetro adicional e o código de chamada deve ser modificado para fornecer a informação.  
  
Com essas técnicas, levou aproximadamente metade de um dia para converter o código para usar as funções de CRT seguro. Se você optar por não usar as sobrecargas de modelo e adicionar manualmente os parâmetros de tamanho, isso provavelmente levará duas vezes ou três vezes mais tempo.  
  
##  <a name="deprecated_forscope"></a> Etapa 13. /Zc:forScope- foi preterido  
 
Desde o Visual C++ 6.0, o compilador está em conformidade com o padrão atual, que limita o escopo de variáveis declaradas em um loop para o escopo do loop. A opção do compilador [/Zc:forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) (**forçar conformidade para escopo de loop** nas propriedades do projeto) controla se isso é ou não relatado como um erro. Devemos atualizar nosso código para estar em conformidade e adicionar declarações somente fora do loop. Para evitar fazer alterações no código, você pode alterar essa configuração na seção **Linguagem** das propriedades do projeto C++ para `No (/Zc:forScope-)`. No entanto, tenha em mente que `/Zc:forScope-` pode ser removido em uma versão futura do Visual C++, portanto, seu código eventualmente precisará ser alterado para estar em conformidade com o padrão.  
  
Esses problemas são relativamente fáceis de corrigir, mas, dependendo do seu código, eles podem afetar um volume grande de código. Eis aqui um problema comum.  
  
```cpp  
int CPerfTextDataBase::NumStrings(LPCTSTR mszStrings) const  
{  
  for (int n = 0; mszStrings[0] != 0; n++)  
  mszStrings = _tcschr(mszStrings, 0) + 1;  
  return(n);  
}    
```  
  
O código acima gera o erro:  
  
```Output  
'n': undeclared identifier  
```  
  
Isso ocorre porque o compilador preteriu uma opção do compilador que permitia código que não está mais em conformidade com o padrão C++. No padrão, declarar uma variável dentro de um loop restringe seu escopo para o loop, portanto, a prática comum de usar um contador de loops fora do loop requer que a declaração do contador também seja movida para fora do loop, assim como no seguinte código revisado:  
  
```cpp  
int CPerfTextDataBase::NumStrings(LPCTSTR mszStrings) const  
{  
  int n;  
  for (n = 0; mszStrings[0] != 0; n++)  
  mszStrings = _tcschr(mszStrings, 0) + 1;  
  return(n);  
}    
```  
  
## <a name="summary"></a>Resumo  
 
Portabilidade do Spy++ do código Visual C++ 6.0 original para o compilador mais recente levou aproximadamente 20 horas de tempo de codificação ao longo de aproximadamente uma semana. Nós atualizamos diretamente por oito versões do produto, do Visual Studio 6.0 para o Visual Studio 2015. Agora, essa é a abordagem recomendada para todas as atualizações em projetos grandes e pequenos.  
  
## <a name="see-also"></a>Consulte também  

[Portabilidade e atualização: exemplos e estudos de caso](../porting/porting-and-upgrading-examples-and-case-studies.md)<br/>
[Estudo de caso anterior: COM Spy](../porting/porting-guide-com-spy.md)