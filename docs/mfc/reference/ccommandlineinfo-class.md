---
title: Classe CCommandLineInfo
ms.date: 11/04/2016
f1_keywords:
- CCommandLineInfo
- AFXWIN/CCommandLineInfo
- AFXWIN/CCommandLineInfo::CCommandLineInfo
- AFXWIN/CCommandLineInfo::ParseParam
- AFXWIN/CCommandLineInfo::m_bRunAutomated
- AFXWIN/CCommandLineInfo::m_bRunEmbedded
- AFXWIN/CCommandLineInfo::m_bShowSplash
- AFXWIN/CCommandLineInfo::m_nShellCommand
- AFXWIN/CCommandLineInfo::m_strDriverName
- AFXWIN/CCommandLineInfo::m_strFileName
- AFXWIN/CCommandLineInfo::m_strPortName
- AFXWIN/CCommandLineInfo::m_strPrinterName
- AFXWIN/CCommandLineInfo::m_strRestartIdentifier
helpviewer_keywords:
- CCommandLineInfo [MFC], CCommandLineInfo
- CCommandLineInfo [MFC], ParseParam
- CCommandLineInfo [MFC], m_bRunAutomated
- CCommandLineInfo [MFC], m_bRunEmbedded
- CCommandLineInfo [MFC], m_bShowSplash
- CCommandLineInfo [MFC], m_nShellCommand
- CCommandLineInfo [MFC], m_strDriverName
- CCommandLineInfo [MFC], m_strFileName
- CCommandLineInfo [MFC], m_strPortName
- CCommandLineInfo [MFC], m_strPrinterName
- CCommandLineInfo [MFC], m_strRestartIdentifier
ms.assetid: 3e313ddb-0a82-4991-87ac-a27feff4668c
ms.openlocfilehash: 0b4d5e5d253f2eb10388a69286d21e2190826eba
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369455"
---
# <a name="ccommandlineinfo-class"></a>Classe CCommandLineInfo

Auxilia no análise da linha de comando na inicialização do aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CCommandLineInfo : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cCommandLineInfo::CCommandLineInfo](#ccommandlineinfo)|Constrói um `CCommandLineInfo` objeto padrão.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCommandLineInfo::ParseParam](#parseparam)|Anular este retorno de chamada para analisar parâmetros individuais.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCommandLineInfo::m_bRunAutomated](#m_brunautomated)|Indica que a `/Automation` opção de linha de comando foi encontrada.|
|[CCommandLineInfo::m_bRunEmbedded](#m_brunembedded)|Indica que a `/Embedding` opção de linha de comando foi encontrada.|
|[CCommandLineInfo::m_bShowSplash](#m_bshowsplash)|Indica se uma tela de respingo deve ser mostrada.|
|[CCommandLineInfo::m_nShellCommand](#m_nshellcommand)|Indica que o comando shell deve ser processado.|
|[cCommandLineInfo::m_strDriverName](#m_strdrivername)|Indica o nome do driver se o comando shell for 'Imprimir para; caso contrário, vazio.|
|[CCommandLineInfo::m_strFileName](#m_strfilename)|Indica o nome do arquivo a ser aberto ou impresso; vazio se o comando shell é Novo ou DDE.|
|[cCommandLineInfo::m_strPortName](#m_strportname)|Indica o nome da porta se o comando shell for 'Imprimir para; caso contrário, vazio.|
|[cCommandLineInfo::m_strPrinterName](#m_strprintername)|Indica o nome da impressora se o comando shell for Imprimir para; caso contrário, vazio.|
|[cCommandLineInfo::m_strRestartIdentifier](#m_strrestartidentifier)|Indica o identificador de reinicialização exclusivo para o gerenciador de reinicialização se o gerenciador de reinicialização reiniciar o aplicativo.|

## <a name="remarks"></a>Comentários

Um aplicativo MFC normalmente criará uma instância local desta classe na função [InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) de seu objeto de aplicativo. Esse objeto é então passado para [CWinApp::ParseCommandLine](../../mfc/reference/cwinapp-class.md#parsecommandline), que chama `CCommandLineInfo` repetidamente [ParseParam](#parseparam) para preencher o objeto. Em `CCommandLineInfo` seguida, o objeto é passado para [CWinApp::ProcessShellCommand](../../mfc/reference/cwinapp-class.md#processshellcommand) para lidar com os argumentos e sinalizadores da linha de comando.

Você pode usar este objeto para encapsular as seguintes opções e parâmetros de linha de comando:

|Argumento de linha de comando|Comando executado|
|----------------------------|----------------------|
|*app*|Novo arquivo.|
|*nome* de arquivo aplicativo|Abra o arquivo.|
|*nome* `/p` de arquivo aplicativo|Imprimir arquivo para impressora padrão.|
|*aplicativo* `/pt` filename impressora porta de driver|Imprimir arquivo para a impressora especificada.|
|*app* `/dde`|Inicie e aguarde o comando DDE.|
|*app* `/Automation`|Inicie como um servidor de automação OLE.|
|*app* `/Embedding`|Iniciar para editar um item OLE incorporado.|
|*app* `/Register`<br /><br /> *app* `/Regserver`|Informa o aplicativo para realizar quaisquer tarefas de registro.|
|*app* `/Unregister`<br /><br /> *app* `/Unregserver`|Informa o aplicativo para executar quaisquer tarefas de não registro.|

Obtenha uma nova `CCommandLineInfo` classe para lidar com outras bandeiras e valores de parâmetros. Anular [parseParam](#parseparam) para lidar com as novas bandeiras.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CCommandLineInfo`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="ccommandlineinfoccommandlineinfo"></a><a name="ccommandlineinfo"></a>cCommandLineInfo::CCommandLineInfo

Este construtor cria `CCommandLineInfo` um objeto com valores padrão.

```
CCommandLineInfo();
```

### <a name="remarks"></a>Comentários

O padrão é mostrar a `m_bShowSplash=TRUE`tela de respingo ( ) e `m_nShellCommand`executar o comando Novo no menu Arquivo **(=NewFile**).

A estrutura do aplicativo chama [o ParseParam](#parseparam) para preencher os membros de dados deste objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#54](../../mfc/codesnippet/cpp/ccommandlineinfo-class_1.cpp)]

## <a name="ccommandlineinfom_brunautomated"></a><a name="m_brunautomated"></a>CCommandLineInfo::m_bRunAutomated

Indica que `/Automation` a bandeira foi encontrada na linha de comando.

```
BOOL m_bRunAutomated;
```

### <a name="remarks"></a>Comentários

Se TRUE, isso significa iniciar como um servidor de automação OLE.

## <a name="ccommandlineinfom_brunembedded"></a><a name="m_brunembedded"></a>CCommandLineInfo::m_bRunEmbedded

Indica que `/Embedding` a bandeira foi encontrada na linha de comando.

```
BOOL m_bRunEmbedded;
```

### <a name="remarks"></a>Comentários

Se TRUE, isso significa iniciar para editar um item OLE incorporado.

## <a name="ccommandlineinfom_bshowsplash"></a><a name="m_bshowsplash"></a>CCommandLineInfo::m_bShowSplash

Indica que a tela de respingo deve ser exibida.

```
BOOL m_bShowSplash;
```

### <a name="remarks"></a>Comentários

Se TRUE, isso significa que a tela de respingo para este aplicativo deve ser exibida durante a inicialização. A implementação padrão do [ParseParam](#parseparam) define [m_nShellCommand](#m_nshellcommand) esse membro `CCommandLineInfo::FileNew`de dados como TRUE se m_nShellCommand for igual a .

## <a name="ccommandlineinfom_nshellcommand"></a><a name="m_nshellcommand"></a>CCommandLineInfo::m_nShellCommand

Indica o comando shell para esta instância da aplicação.

```
m_nShellCommand;
```

### <a name="remarks"></a>Comentários

O tipo para este membro de dados é o seguinte `CCommandLineInfo` tipo enumerado, que é definido na classe.

```
enum {
    FileNew,
    FileOpen,
    FilePrint,
    FilePrintTo,
    FileDDE,
    AppRegister,
    AppUnregister,
    RestartByRestartManager,
    FileNothing = -1
    };
```

Para obter uma breve descrição desses valores, consulte a lista a seguir.

- `CCommandLineInfo::FileNew`Indica que nenhum nome de arquivo foi encontrado na linha de comando.

- `CCommandLineInfo::FileOpen`Indica que um nome de arquivo foi encontrado na linha de comando e `/p` `/pt`que `/dde`nenhuma das seguintes bandeiras foram encontradas na linha de comando: , .

- `CCommandLineInfo::FilePrint`Indica que `/p` a bandeira foi encontrada na linha de comando.

- `CCommandLineInfo::FilePrintTo`Indica que `/pt` a bandeira foi encontrada na linha de comando.

- `CCommandLineInfo::FileDDE`Indica que `/dde` a bandeira foi encontrada na linha de comando.

- `CCommandLineInfo::AppRegister`Indica que `/Register` `/Regserver` a bandeira ou foi encontrada na linha de comando e o aplicativo foi solicitado a registrar.

- `CCommandLineInfo::AppUnregister`Indica que `/Unregister` `/Unregserver` o aplicativo foi solicitado a cancelar o registro.

- `CCommandLineInfo::RestartByRestartManager`Indica que o aplicativo foi reiniciado pelo gerenciador de reinicialização.

- `CCommandLineInfo::FileNothing`Desativa a exibição de uma nova janela de criançaS MDI na inicialização. Pelo design, os aplicativos MDI gerados pelo Assistente de Aplicativo exibem uma nova janela filho na inicialização. Para desativar esse recurso, um `CCommandLineInfo::FileNothing` aplicativo pode usar como o comando shell quando ele chama [ProcessShellCommand](../../mfc/reference/cwinapp-class.md#processshellcommand). `ProcessShellCommand`é chamado `InitInstance( )` pela `CWinApp` de todas as classes derivadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#55](../../mfc/codesnippet/cpp/ccommandlineinfo-class_2.cpp)]

## <a name="ccommandlineinfom_strdrivername"></a><a name="m_strdrivername"></a>cCommandLineInfo::m_strDriverName

Armazena o valor do terceiro parâmetro não-bandeira na linha de comando.

```
CString m_strDriverName;
```

### <a name="remarks"></a>Comentários

Este parâmetro é tipicamente o nome do driver da impressora para um comando Imprimir para shell. A implementação padrão do [ParseParam](#parseparam) define `/pt` esse membro de dados somente se o sinalizador foi encontrado na linha de comando.

## <a name="ccommandlineinfom_strfilename"></a><a name="m_strfilename"></a>CCommandLineInfo::m_strFileName

Armazena o valor do primeiro parâmetro não-bandeira na linha de comando.

```
CString m_strFileName;
```

### <a name="remarks"></a>Comentários

Este parâmetro é tipicamente o nome do arquivo a ser aberto.

## <a name="ccommandlineinfom_strportname"></a><a name="m_strportname"></a>cCommandLineInfo::m_strPortName

Armazena o valor do quarto parâmetro não-bandeira na linha de comando.

```
CString m_strPortName;
```

### <a name="remarks"></a>Comentários

Este parâmetro é tipicamente o nome da porta da impressora para um comando Imprimir para shell. A implementação padrão do [ParseParam](#parseparam) define `/pt` esse membro de dados somente se o sinalizador foi encontrado na linha de comando.

## <a name="ccommandlineinfom_strprintername"></a><a name="m_strprintername"></a>cCommandLineInfo::m_strPrinterName

Armazena o valor do segundo parâmetro não-bandeira na linha de comando.

```
CString m_strPrinterName;
```

### <a name="remarks"></a>Comentários

Este parâmetro é tipicamente o nome da impressora para um comando Imprimir para shell. A implementação padrão do [ParseParam](#parseparam) define `/pt` esse membro de dados somente se o sinalizador foi encontrado na linha de comando.

## <a name="ccommandlineinfom_strrestartidentifier"></a><a name="m_strrestartidentifier"></a>cCommandLineInfo::m_strRestartIdentifier

O identificador de reinicialização exclusivo na linha de comando.

```
CString m_strRestartIdentifier;
```

### <a name="remarks"></a>Comentários

O identificador de reinicialização é único para cada instância do aplicativo.

Se o gerenciador de reinicialização sair do aplicativo e estiver configurado para reiniciá-lo, o gerenciador de reinicialização executará o aplicativo a partir da linha de comando com o identificador de reinicialização como parâmetro opcional. Quando o gerenciador de reinicialização usa o identificador de reinicialização, o aplicativo pode reabrir os documentos abertos anteriormente e recuperar arquivos salvos automaticamente.

## <a name="ccommandlineinfoparseparam"></a><a name="parseparam"></a>CCommandLineInfo::ParseParam

O framework chama essa função para analisar/interpretar parâmetros individuais da linha de comando. A segunda versão difere da primeira apenas em projetos Unicode.

```
virtual void ParseParam(
    const char* pszParam,
    BOOL bFlag,
    BOOL bLast);

virtual void ParseParam(
    const TCHAR* pszParam,
    BOOL bFlag,
    BOOL bLast);
```

### <a name="parameters"></a>Parâmetros

*pszParam*<br/>
O parâmetro ou bandeira.

*bFlag*<br/>
Indica se *pszParam* é um parâmetro ou uma bandeira.

*Explosão*<br/>
Indica se este é o último parâmetro ou bandeira na linha de comando.

### <a name="remarks"></a>Comentários

[CWinApp::ParseCommandLine](../../mfc/reference/cwinapp-class.md#parsecommandline) `ParseParam` chamadas uma vez para cada parâmetro ou bandeira na linha de comando, passando o argumento para *pszParam*. Se o primeiro caractere do parâmetro **-** é um **/**' ou um ' ', então ele é removido e *bFlag* é definido como TRUE. Ao analisar o parâmetro final, *bLast* é definido como TRUE.

A implementação padrão desta função reconhece `/p` `/pt`as `/dde` `/Automation`seguintes `/Embedding`bandeiras: , , , e , como mostrado na tabela a seguir:

|Argumento de linha de comando|Comando executado|
|----------------------------|----------------------|
|*app*|Novo arquivo.|
|*nome* de arquivo aplicativo|Abra o arquivo.|
|*nome* `/p` de arquivo aplicativo|Imprimir arquivo para impressora padrão.|
|*aplicativo* `/pt` filename impressora porta de driver|Imprimir arquivo para a impressora especificada.|
|*app* `/dde`|Inicie e aguarde o comando DDE.|
|*app* `/Automation`|Inicie como um servidor de automação OLE.|
|*app* `/Embedding`|Iniciar para editar um item OLE incorporado.|
|*app* `/Register`<br /><br /> *app* `/Regserver`|Informa o aplicativo para realizar quaisquer tarefas de registro.|
|*app* `/Unregister`<br /><br /> *app* `/Unregserver`|Informa o aplicativo para executar quaisquer tarefas de não registro.|

Essas informações são armazenadas em [m_bRunAutomated,](#m_brunautomated) [m_bRunEmbedded](#m_brunembedded)e [m_nShellCommand.](#m_nshellcommand) As bandeiras são marcadas **/** por um '' ou hífen ' **-** para a frente.

A implementação padrão coloca o primeiro parâmetro não-sinalizado em [m_strFileName](#m_strfilename). No caso da `/pt` bandeira, a implementação padrão coloca os parâmetros de segundo, terceiro e quarto não-bandeira em [m_strPrinterName,](#m_strprintername) [m_strDriverName](#m_strdrivername)e [m_strPortName,](#m_strportname)respectivamente.

A implementação padrão também define [m_bShowSplash](#m_bshowsplash) para TRUE apenas no caso de um novo arquivo. No caso de um novo arquivo, o usuário tomou medidas envolvendo o próprio aplicativo. Em qualquer outro caso, incluindo a abertura de arquivos existentes usando o shell, a ação do usuário envolve o arquivo diretamente. Em um ponto de vista centrado em documentos, a tela de respingo não precisa anunciar a inicialização do aplicativo.

Anular esta função em sua classe derivada para lidar com outros valores de bandeira e parâmetro.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CWinApp::ParseCommandLine](../../mfc/reference/cwinapp-class.md#parsecommandline)<br/>
[CWinApp::ProcessShellCommand](../../mfc/reference/cwinapp-class.md#processshellcommand)
