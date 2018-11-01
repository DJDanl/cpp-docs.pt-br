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
ms.openlocfilehash: 60c0ae66234d5fb3be61d9249cf61ee77dff41ad
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50481465"
---
# <a name="ccommandlineinfo-class"></a>Classe CCommandLineInfo

Auxílios em análise da linha de comando na inicialização do aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CCommandLineInfo : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCommandLineInfo::CCommandLineInfo](#ccommandlineinfo)|Constrói um padrão `CCommandLineInfo` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCommandLineInfo::ParseParam](#parseparam)|Substitua esse retorno de chamada para analisar os parâmetros individuais.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCommandLineInfo::m_bRunAutomated](#m_brunautomated)|Indica a linha de comando `/Automation` opção foi encontrada.|
|[CCommandLineInfo::m_bRunEmbedded](#m_brunembedded)|Indica a linha de comando `/Embedding` opção foi encontrada.|
|[CCommandLineInfo::m_bShowSplash](#m_bshowsplash)|Indica se uma tela inicial deve ser mostrada.|
|[CCommandLineInfo::m_nShellCommand](#m_nshellcommand)|Indica o shell de comando para ser processado.|
|[CCommandLineInfo::m_strDriverName](#m_strdrivername)|Indica o driver nome se o comando do shell é imprimir para; Caso contrário, vazio.|
|[CCommandLineInfo::m_strFileName](#m_strfilename)|Indica o nome do arquivo deve ser aberto ou impresso; vazio se o comando do shell é novo ou do DDE.|
|[CCommandLineInfo::m_strPortName](#m_strportname)|Indica a porta nome se o comando do shell é imprimir para; Caso contrário, vazio.|
|[CCommandLineInfo::m_strPrinterName](#m_strprintername)|Indica a impressora nome se o comando do shell é imprimir para; Caso contrário, vazio.|
|[CCommandLineInfo::m_strRestartIdentifier](#m_strrestartidentifier)|Indica o identificador exclusivo de reinicialização para o Gerenciador de reinicialização, se o Gerenciador de reinicialização reiniciou o aplicativo.|

## <a name="remarks"></a>Comentários

Um aplicativo MFC normalmente criará uma instância local desta classe na [InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) função do seu objeto de aplicativo. Esse objeto é então passado para [CWinApp::ParseCommandLine](../../mfc/reference/cwinapp-class.md#parsecommandline), que chama repetidamente [ParseParam](#parseparam) para preencher o `CCommandLineInfo` objeto. O `CCommandLineInfo` objeto é então passado para [CWinApp::ProcessShellCommand](../../mfc/reference/cwinapp-class.md#processshellcommand) para lidar com os sinalizadores e argumentos de linha de comando.

Você pode usar esse objeto para encapsular os parâmetros e opções de linha de comando a seguir:

|Argumento de linha de comando|Comando executado|
|----------------------------|----------------------|
|*app*|Novo arquivo.|
|*aplicativo* filename|Abrir o arquivo.|
|*aplicativo* `/p` nome de arquivo|Arquivo de impressão para a impressora padrão.|
|*aplicativo* `/pt` porta de driver de impressora do nome de arquivo|Arquivo de impressão para a impressora especificada.|
|*Aplicativo* `/dde`|Inicie e await comando DDE.|
|*Aplicativo* `/Automation`|Inicie-o como um servidor de automação OLE.|
|*Aplicativo* `/Embedding`|Inicie para editar um item OLE inserido.|
|*Aplicativo* `/Register`<br /><br /> *Aplicativo* `/Regserver`|Informa o aplicativo para executar quaisquer tarefas de registro.|
|*Aplicativo* `/Unregister`<br /><br /> *Aplicativo* `/Unregserver`|Informa o aplicativo para executar quaisquer tarefas de cancelamento de registro.|

Derive uma nova classe de `CCommandLineInfo` para lidar com outros sinalizadores e valores de parâmetro. Substituir [ParseParam](#parseparam) para lidar com os sinalizadores de novo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CCommandLineInfo`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="ccommandlineinfo"></a>  CCommandLineInfo::CCommandLineInfo

Este construtor cria um `CCommandLineInfo` objeto com valores padrão.

```
CCommandLineInfo();
```

### <a name="remarks"></a>Comentários

O padrão é mostrar a tela inicial ( `m_bShowSplash=TRUE`) e para executar o comando novo no menu Arquivo ( `m_nShellCommand` **= NewFile**).

A estrutura do aplicativo chama [ParseParam](#parseparam) para preencher os membros de dados deste objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#54](../../mfc/codesnippet/cpp/ccommandlineinfo-class_1.cpp)]

##  <a name="m_brunautomated"></a>  CCommandLineInfo::m_bRunAutomated

Indica que o `/Automation` sinalizador foi encontrado na linha de comando.

```
BOOL m_bRunAutomated;
```

### <a name="remarks"></a>Comentários

Se for TRUE, isso significa iniciar como um servidor de automação OLE.

##  <a name="m_brunembedded"></a>  CCommandLineInfo::m_bRunEmbedded

Indica que o `/Embedding` sinalizador foi encontrado na linha de comando.

```
BOOL m_bRunEmbedded;
```

### <a name="remarks"></a>Comentários

Se for TRUE, isso significa iniciar para a edição de um item OLE inserido.

##  <a name="m_bshowsplash"></a>  CCommandLineInfo::m_bShowSplash

Indica que a tela inicial deve ser exibida.

```
BOOL m_bShowSplash;
```

### <a name="remarks"></a>Comentários

Se for TRUE, isso significa que a tela inicial para esse aplicativo deve ser exibida durante a inicialização. A implementação padrão de [ParseParam](#parseparam) define este membro de dados como TRUE se [m_nShellCommand](#m_nshellcommand) é igual a `CCommandLineInfo::FileNew`.

##  <a name="m_nshellcommand"></a>  CCommandLineInfo::m_nShellCommand

Indica que o comando do shell para esta instância do aplicativo.

```
m_nShellCommand;
```

### <a name="remarks"></a>Comentários

O tipo para este membro de dados é o seguinte tipo enumerado, que é definido no `CCommandLineInfo` classe.

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

- `CCommandLineInfo::FileNew` Indica que nenhum nome de arquivo foi encontrado na linha de comando.

- `CCommandLineInfo::FileOpen` Indica que um nome de arquivo foi encontrado na linha de comando e que nenhum dos sinalizadores a seguir foram encontrados na linha de comando: `/p`, `/pt`, `/dde`.

- `CCommandLineInfo::FilePrint` Indica que o `/p` sinalizador foi encontrado na linha de comando.

- `CCommandLineInfo::FilePrintTo` Indica que o `/pt` sinalizador foi encontrado na linha de comando.

- `CCommandLineInfo::FileDDE` Indica que o `/dde` sinalizador foi encontrado na linha de comando.

- `CCommandLineInfo::AppRegister` Indica que o `/Register` ou `/Regserver` sinalizador foi encontrado na linha de comando e o aplicativo foi solicitado a registrar.

- `CCommandLineInfo::AppUnregister` Indica que o `/Unregister` ou `/Unregserver` foi solicitado para cancelar o registro.

- `CCommandLineInfo::RestartByRestartManager` Indica que o aplicativo foi reiniciado pelo Gerenciador de reinicialização.

- `CCommandLineInfo::FileNothing` Desativa a exibição de uma nova janela filho da MDI na inicialização. Por design, os aplicativos gerados pelo Assistente de aplicativo MDI exibem uma nova janela filho na inicialização. Para desativar esse recurso, um aplicativo pode usar `CCommandLineInfo::FileNothing` como o comando do shell quando ele chama [ProcessShellCommand](../../mfc/reference/cwinapp-class.md#processshellcommand). `ProcessShellCommand` é chamado pelo `InitInstance( )` de todos os `CWinApp` classes derivadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#55](../../mfc/codesnippet/cpp/ccommandlineinfo-class_2.cpp)]

##  <a name="m_strdrivername"></a>  CCommandLineInfo::m_strDriverName

Armazena o valor do terceiro parâmetro não sinalizador na linha de comando.

```
CString m_strDriverName;
```

### <a name="remarks"></a>Comentários

Normalmente, esse parâmetro é o nome do driver da impressora para um comando de shell imprimir para. A implementação padrão de [ParseParam](#parseparam) define esse se apenas de membro de dados a `/pt` sinalizador foi encontrado na linha de comando.

##  <a name="m_strfilename"></a>  CCommandLineInfo::m_strFileName

Armazena o valor do primeiro parâmetro não sinalizador na linha de comando.

```
CString m_strFileName;
```

### <a name="remarks"></a>Comentários

Normalmente, esse parâmetro é o nome do arquivo a ser aberto.

##  <a name="m_strportname"></a>  CCommandLineInfo::m_strPortName

Armazena o valor do quarto parâmetro não sinalizador na linha de comando.

```
CString m_strPortName;
```

### <a name="remarks"></a>Comentários

Normalmente, esse parâmetro é o nome da porta da impressora para um comando de shell imprimir para. A implementação padrão de [ParseParam](#parseparam) define esse se apenas de membro de dados a `/pt` sinalizador foi encontrado na linha de comando.

##  <a name="m_strprintername"></a>  CCommandLineInfo::m_strPrinterName

Armazena o valor do segundo parâmetro não sinalizador na linha de comando.

```
CString m_strPrinterName;
```

### <a name="remarks"></a>Comentários

Normalmente, esse parâmetro é o nome da impressora para um comando de shell imprimir para. A implementação padrão de [ParseParam](#parseparam) define esse se apenas de membro de dados a `/pt` sinalizador foi encontrado na linha de comando.

##  <a name="m_strrestartidentifier"></a>  CCommandLineInfo::m_strRestartIdentifier

O exclusivo reinicie o identificador de linha de comando.

```
CString m_strRestartIdentifier;
```

### <a name="remarks"></a>Comentários

O identificador de reinicialização é exclusivo para cada instância do aplicativo.

Se o Gerenciador de reinicialização sai do aplicativo e é configurado para reiniciá-lo, o Gerenciador de reinicialização executa o aplicativo de linha de comando com o identificador de reinicialização como um parâmetro opcional. Quando o Gerenciador de reinicialização usa o identificador de reinicialização, o aplicativo pode reabrir documentos anteriormente abertos e recuperar arquivos salva automaticamente.

##  <a name="parseparam"></a>  CCommandLineInfo::ParseParam

O framework chama essa função para análise/interpretar parâmetros individuais na linha de comando. A segunda versão difere do primeiro apenas nos projetos do Unicode.

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
O parâmetro ou o sinalizador.

*bFlag*<br/>
Indica se *pszParam* é um parâmetro ou um sinalizador.

*Bombardeio de*<br/>
Indica se este é o último parâmetro ou sinalizador na linha de comando.

### <a name="remarks"></a>Comentários

[CWinApp::ParseCommandLine](../../mfc/reference/cwinapp-class.md#parsecommandline) chamadas `ParseParam` uma vez para cada parâmetro ou o sinalizador na linha de comando, passando o argumento *pszParam*. Se o primeiro caractere do parâmetro é um ' **-**'ou' **/**', em seguida, ele é removido e *bFlag* é definida como TRUE. Ao analisar o parâmetro final, *bLast* é definida como TRUE.

A implementação padrão dessa função reconhece os seguintes sinalizadores: `/p`, `/pt`, `/dde`, `/Automation`, e `/Embedding`, conforme mostrado na tabela a seguir:

|Argumento de linha de comando|Comando executado|
|----------------------------|----------------------|
|*app*|Novo arquivo.|
|*aplicativo* filename|Abrir o arquivo.|
|*aplicativo* `/p` nome de arquivo|Arquivo de impressão para a impressora padrão.|
|*aplicativo* `/pt` porta de driver de impressora do nome de arquivo|Arquivo de impressão para a impressora especificada.|
|*Aplicativo* `/dde`|Inicie e await comando DDE.|
|*Aplicativo* `/Automation`|Inicie-o como um servidor de automação OLE.|
|*Aplicativo* `/Embedding`|Inicie para editar um item OLE inserido.|
|*Aplicativo* `/Register`<br /><br /> *Aplicativo* `/Regserver`|Informa o aplicativo para executar quaisquer tarefas de registro.|
|*Aplicativo* `/Unregister`<br /><br /> *Aplicativo* `/Unregserver`|Informa o aplicativo para executar quaisquer tarefas de cancelamento de registro.|

Essas informações são armazenadas no [m_bRunAutomated](#m_brunautomated), [m_bRunEmbedded](#m_brunembedded), e [m_nShellCommand](#m_nshellcommand). Sinalizadores são marcados por qualquer um, uma barra ' **/**'ou hífen' **-**'.

A implementação padrão coloca o primeiro parâmetro não sinalizador em [m_strFileName](#m_strfilename). No caso do `/pt` sinalizador, a implementação padrão coloca o segundo, terceiro e quarto parâmetros não sinalizador em [m_strPrinterName](#m_strprintername), [m_strDriverName](#m_strdrivername), e [m _ strPortName](#m_strportname), respectivamente.

A implementação padrão também define [m_bShowSplash](#m_bshowsplash) como TRUE somente no caso de um novo arquivo. No caso de um novo arquivo, o usuário agiu envolvendo o aplicativo em si. Em qualquer outro caso, incluindo a abertura de arquivos existentes usando o shell, a ação do usuário envolve o arquivo diretamente. Em um ponto de vista centrado em documentos, a tela inicial não precisa anunciar o aplicativo sendo inicializado.

Substitua essa função em sua classe derivada para lidar com outros valores de parâmetro e o sinalizador.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CWinApp::ParseCommandLine](../../mfc/reference/cwinapp-class.md#parsecommandline)<br/>
[CWinApp::ProcessShellCommand](../../mfc/reference/cwinapp-class.md#processshellcommand)

