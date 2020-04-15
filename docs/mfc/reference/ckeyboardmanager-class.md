---
title: Classe CKeyboardManager
ms.date: 11/04/2016
f1_keywords:
- CKeyboardManager
- AFXKEYBOARDMANAGER/CKeyboardManager
- AFXKEYBOARDMANAGER/CKeyboardManager::CKeyboardManager
- AFXKEYBOARDMANAGER/CKeyboardManager::CleanUp
- AFXKEYBOARDMANAGER/CKeyboardManager::FindDefaultAccelerator
- AFXKEYBOARDMANAGER/CKeyboardManager::IsKeyHandled
- AFXKEYBOARDMANAGER/CKeyboardManager::IsKeyPrintable
- AFXKEYBOARDMANAGER/CKeyboardManager::IsShowAllAccelerators
- AFXKEYBOARDMANAGER/CKeyboardManager::LoadState
- AFXKEYBOARDMANAGER/CKeyboardManager::ResetAll
- AFXKEYBOARDMANAGER/CKeyboardManager::SaveState
- AFXKEYBOARDMANAGER/CKeyboardManager::ShowAllAccelerators
- AFXKEYBOARDMANAGER/CKeyboardManager::TranslateCharToUpper
- AFXKEYBOARDMANAGER/CKeyboardManager::UpdateAccelTable
helpviewer_keywords:
- CKeyboardManager [MFC], CKeyboardManager
- CKeyboardManager [MFC], CleanUp
- CKeyboardManager [MFC], FindDefaultAccelerator
- CKeyboardManager [MFC], IsKeyHandled
- CKeyboardManager [MFC], IsKeyPrintable
- CKeyboardManager [MFC], IsShowAllAccelerators
- CKeyboardManager [MFC], LoadState
- CKeyboardManager [MFC], ResetAll
- CKeyboardManager [MFC], SaveState
- CKeyboardManager [MFC], ShowAllAccelerators
- CKeyboardManager [MFC], TranslateCharToUpper
- CKeyboardManager [MFC], UpdateAccelTable
ms.assetid: 4809ece6-89df-4479-8b53-9bf476ee107b
ms.openlocfilehash: 5d0f544943cc8584960bb2668ee7ce326547e2fa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372324"
---
# <a name="ckeyboardmanager-class"></a>Classe CKeyboardManager

Gerencia tabelas de teclas de atalho para a janela principal da moldura e janelas de quadro de crianças.

## <a name="syntax"></a>Sintaxe

```
class CKeyboardManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|[CKeyboardManager::CKeyboardManager](#ckeyboardmanager)|Constrói um objeto `CKeyboardManager`.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CKeyboardManager::Limpeza](#cleanup)|Limpa as tabelas de teclas de atalho.|
|[CKeyboardManager::FindDefaultAccelerator](#finddefaultaccelerator)|Recupera a tecla de atalho padrão para o comando e a janela especificadas.|
|[CKeyboardManager::IsKeyHandled](#iskeyhandled)|Determina se uma chave é manuseada pela tabela do acelerador.|
|[CKeyboardManager::IsKeyPrintable](#iskeyprintable)|Indica se um caractere é imprimível.|
|[CKeyboardManager::IsShowAllAccelerators](#isshowallaccelerators)|Indica se os menus mostram todas as teclas de atalho para um comando ou apenas a tecla de atalho padrão.|
|[CKeyboardManager::LoadState](#loadstate)|Carrega as tabelas de teclas de atalho do registro do Windows.|
|[CKeyboardManager::ResetAll](#resetall)|Recarrega as tabelas de teclas de atalho do recurso do aplicativo.|
|[CKeyboardManager::SaveState](#savestate)|Salva as tabelas-chave de atalho no registro do Windows.|
|[CKeyboardManager::ShowAllAccelerators](#showallaccelerators)|Especifica se a estrutura exibe todas as teclas de atalho para todos os comandos ou uma única tecla de atalho para cada comando. Este método não afeta comandos que têm apenas uma tecla de atalho associada.|
|[CKeyboardmanager::TranslateChartoupper](#translatechartoupper)|Converte um caractere em seu registro superior.|
|[CKeyboardManager::UpdateAccelTable](#updateacceltable)|Atualiza uma tabela de teclas de atalho com uma nova tabela de teclas de atalho.|

## <a name="remarks"></a>Comentários

Os membros desta classe permitem que você salve e carregue tabelas-chave de atalho para o registro do Windows, use um modelo para atualizar as tabelas-chave de atalho e encontre a chave de atalho padrão para um comando em uma janela de quadro. Além disso, `CKeyboardManager` o objeto permite controlar como as teclas de atalho são exibidas para o usuário.

Você não deve `CKeyboardManager` criar um objeto manualmente. Ele será criado automaticamente pela estrutura de sua aplicação. No entanto, você deve ligar para [CWinAppEx::InitKeyboardManager](../../mfc/reference/cwinappex-class.md#initkeyboardmanager) durante o processo de inicialização do seu aplicativo. Para obter um ponteiro para o gerenciador de teclado para o seu aplicativo, ligue para [CWinAppEx::GetKeyboardManager](../../mfc/reference/cwinappex-class.md#getkeyboardmanager).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CKeyboardManager` recuperar `CWinAppEx` um ponteiro para um objeto de uma classe e como mostrar todas as teclas de atalho associadas aos comandos do menu. Este trecho de código faz parte da [amostra Páginas Personalizadas](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_CustomPages#5](../../mfc/reference/codesnippet/cpp/ckeyboardmanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ckeyboardmanager](../../mfc/reference/ckeyboardmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxkeyboardmanager.h

## <a name="ckeyboardmanagerckeyboardmanager"></a><a name="ckeyboardmanager"></a>CKeyboardManager::CKeyboardManager

Constrói um objeto `CKeyboardManager`.

```
CKeyboardManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você `CKeyboardManager` não precisa criar um diretamente. Por padrão, a estrutura cria uma para você. Para obter um `CKeyboardManager`ponteiro para o , chamar [CWinAppEx::GetKeyboardManager](../../mfc/reference/cwinappex-class.md#getkeyboardmanager). Se você criar um manualmente, você deve inicializá-lo com o método [CWinAppEx::InitKeyboardManager](../../mfc/reference/cwinappex-class.md#initkeyboardmanager).

## <a name="ckeyboardmanagercleanup"></a><a name="cleanup"></a>CKeyboardManager::Limpeza

Libera os `CKeyboardManager` recursos e limpa todos os mapeamentos de teclas de atalho.

```
static void CleanUp();
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre teclas de atalho, consulte [Personalização do teclado e do mouse](../../mfc/keyboard-and-mouse-customization.md).

Você não precisa chamar essa função quando o aplicativo sair porque a estrutura a chama automaticamente durante a saída do aplicativo.

## <a name="ckeyboardmanagerfinddefaultaccelerator"></a><a name="finddefaultaccelerator"></a>CKeyboardManager::FindDefaultAccelerator

Recupera a tecla de atalho padrão para o comando e a janela especificadas.

```
static BOOL FindDefaultAccelerator(
    UINT uiCmd,
    CString& str,
    CFrameWnd* pWndFrame,
    BOOL bIsDefaultFrame);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O id de comando.

*Str*<br/>
[fora] Uma referência `CString` a um objeto.

*pWndFrame*<br/>
[em] Um ponteiro para uma janela de quadro.

*bIsDefaultFrame*<br/>
[em] Especifica se a janela do quadro é a janela padrão do quadro.

### <a name="return-value"></a>Valor retornado

Não zero se o atalho for encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método procura o comando especificado pelo *uiCmd* e recupera a tecla de atalho padrão. Em seguida, o método pega a string associada a esta tecla de atalho e escreve o valor para o parâmetro *str.*

## <a name="ckeyboardmanageriskeyhandled"></a><a name="iskeyhandled"></a>CKeyboardManager::IsKeyHandled

Determina se a chave especificada é tratada pela [Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md).

```
static BOOL __stdcall IsKeyHandled(
    WORD nKey,
    BYTE fVirt,
    CFrameWnd* pWndFrame,
    BOOL bIsDefaultFrame);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*nKey*|[em] A chave para verificar.|
|*fVirt*|[em] Especifica o comportamento da tecla de atalho. Para obter uma lista de valores possíveis, consulte [ACCEL Structure](/windows/win32/api/winuser/ns-winuser-accel).|
|*pWndFrame*|[em] Uma janela de moldura. Este método determina se uma tecla de atalho é tratada neste quadro.|
|*bIsDefaultFrame*|[em] Um parâmetro booleano que indica se *pWndFrame* é a janela padrão do quadro.|

### <a name="return-value"></a>Valor retornado

TRUE se a tecla de atalho for manuseada. FALSO se a chave não for manuseada ou se *pWndFrame* for NULL.

### <a name="remarks"></a>Comentários

Os parâmetros de entrada devem corresponder à entrada na tabela do acelerador tanto para *nKey* quanto *fVirt* para determinar se uma tecla de atalho é manuseada em *pWndFrame*.

## <a name="ckeyboardmanageriskeyprintable"></a><a name="iskeyprintable"></a>CKeyboardManager::IsKeyPrintable

Indica se um caractere é imprimível.

```
static BOOL __stdcall IsKeyPrintable(const UINT nChar);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Nchar*|[em] O caráter que este método verifica.|

### <a name="return-value"></a>Valor retornado

Não zero se o caractere for imprimível, zero se não for.

### <a name="remarks"></a>Comentários

Este método falha se uma chamada para [GetKeyboardState](/windows/win32/api/winuser/nf-winuser-getkeyboardstate) falhar.

## <a name="ckeyboardmanagerisshowallaccelerators"></a><a name="isshowallaccelerators"></a>CKeyboardManager::IsShowAllAccelerators

Indica se os menus mostram todas as teclas de atalho associadas aos comandos do menu ou apenas as teclas de atalho padrão.

```
static BOOL IsShowAllAccelerators();
```

### <a name="return-value"></a>Valor retornado

Não zero se o aplicativo listar todas as teclas de atalho para comandos de menu; 0 se o aplicativo exibir apenas chaves de atalho padrão.

### <a name="remarks"></a>Comentários

O aplicativo lista as teclas de atalho para comandos de menu na barra de menus. Use a função [CKeyboardManager::ShowAllAccelerators](#showallaccelerators) para controlar se o aplicativo lista todas as teclas de atalho ou apenas as teclas de atalho padrão.

## <a name="ckeyboardmanagerloadstate"></a><a name="loadstate"></a>CKeyboardManager::LoadState

Carrega as tabelas de teclas de atalho do registro do Windows.

```
BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    CFrameWnd* pDefaultFrame = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] O caminho `CKeyboardManager` do registro onde os dados são salvos.

*pDefaultFrame*<br/>
[em] Um ponteiro para uma janela de quadro para usar como janela padrão.

### <a name="return-value"></a>Valor retornado

Não zero se o estado foi carregado com sucesso ou 0 de outra forma.

### <a name="remarks"></a>Comentários

Se o parâmetro *lpszProfileName* for NULL, este método `CKeyboardManager` verificará o local de registro padrão para obter dados. O local de registro padrão é especificado pela [Classe CWinAppEx](../../mfc/reference/cwinappex-class.md). Os dados devem ser previamente gravados com o método [CKeyboardManager::SaveState](#savestate).

Se você não especificar uma janela padrão, a janela principal do quadro do aplicativo será usada.

## <a name="ckeyboardmanagerresetall"></a><a name="resetall"></a>CKeyboardManager::ResetAll

Recarrega as tabelas de teclas de atalho do recurso do aplicativo.

```
void ResetAll();
```

### <a name="remarks"></a>Comentários

Esta função limpa os atalhos `CKeyboardManager` armazenados na instância. Em seguida, ele recarregará o estado do gerenciador de teclado a partir do recurso do aplicativo.

## <a name="ckeyboardmanagersavestate"></a><a name="savestate"></a>CKeyboardManager::SaveState

Salva as tabelas-chave de atalho no registro do Windows.

```
BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,
    CFrameWnd* pDefaultFrame = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
[em] O caminho do `CKeyboardManager` registro para salvar o estado.

*pDefaultFrame*<br/>
[em] Um ponteiro para uma janela de quadro que se torna a janela padrão.

### <a name="return-value"></a>Valor retornado

Não zero se o estado do gerenciador de teclado foi salvo com sucesso, ou 0 de outra forma.

### <a name="remarks"></a>Comentários

Se o parâmetro *lpszProfileName* for NULL, `CKeyboardManager` este método gravará o estado para o local padrão especificado pela [Classe CWinAppEx](../../mfc/reference/cwinappex-class.md). Se você especificar um local, você pode carregar os dados mais tarde usando o método [CKeyboardManager::LoadState](#loadstate).

Se você não especificar uma janela padrão, a janela principal do quadro será usada como janela padrão.

## <a name="ckeyboardmanagershowallaccelerators"></a><a name="showallaccelerators"></a>CKeyboardManager::ShowAllAccelerators

Mostra todas as teclas de atalho associadas aos comandos do menu.

```
static void ShowAllAccelerators(
    BOOL bShowAll = TRUE,
    LPCTSTR lpszDelimiter = _afxDefaultAcceleratorDelimiter);
```

### <a name="parameters"></a>Parâmetros

*bShowAll*<br/>
[em] Se TRUE, todas as teclas de atalho serão exibidas. Se FALSO, apenas a primeira tecla de atalho será exibida.

*lpszDelimiter*<br/>
[em] Uma seqüência para inserir entre teclas de atalho. Este delimitador não tem efeito se apenas uma tecla de atalho for exibida.

### <a name="remarks"></a>Comentários

Por padrão, se um comando tiver mais de uma tecla de atalho associada a ele, apenas a primeira tecla de atalho será mostrada. Esta função permite listar todas as teclas de atalho associadas a todos os comandos.

As teclas de atalho serão listadas ao lado do comando na barra de menus. Se todas as teclas de atalho forem exibidas, a seqüência fornecida pelo *lpszDelimiter* separará as teclas de atalho individuais.

## <a name="ckeyboardmanagertranslatechartoupper"></a><a name="translatechartoupper"></a>CKeyboardmanager::TranslateChartoupper

Converte um caractere em seu registro superior.

```
static UINT TranslateCharToUpper(const UINT nChar);
```

### <a name="parameters"></a>Parâmetros

*Nchar*<br/>
[em] O personagem para converter.

### <a name="return-value"></a>Valor retornado

O caractere que é o registro superior do parâmetro de entrada.

## <a name="ckeyboardmanagerupdateacceltable"></a><a name="updateacceltable"></a>CKeyboardManager::UpdateAccelTable

Atualiza uma tabela de teclas de atalho com uma nova tabela de teclas de atalho.

```
BOOL UpdateAccelTable(
    CMultiDocTemplate* pTemplate,
    LPACCEL lpAccel,
    int nSize,
    CFrameWnd* pDefaultFrame = NULL);

BOOL UpdateAccelTable(
    CMultiDocTemplate* pTemplate,
    HACCEL hAccelNew,
    CFrameWnd* pDefaultFrame = NULL);
```

### <a name="parameters"></a>Parâmetros

*pTemplate*<br/>
[em] Um ponteiro para um modelo de documento.

*LpAccel*<br/>
[em] Um ponteiro para a nova tecla de atalho.

*Nsize*<br/>
[em] O tamanho da nova tabela de atalhos.

*pDefaultFrame*<br/>
[em] Um ponteiro para a janela padrão do quadro.

*hAccelNew*<br/>
[em] Uma alça para a nova tabela de atalhos.

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use esta função para substituir a tabela de atalho existente por novas teclas de atalho para vários objetos de janela de quadro. A função recebe um modelo de documento como parâmetro para obter acesso a todos os objetos da janela do quadro conectados ao modelo de documento dado.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe Cwinappex](../../mfc/reference/cwinappex-class.md)<br/>
[CWinAppEx::InitKeyboardManager](../../mfc/reference/cwinappex-class.md#initkeyboardmanager)<br/>
[Personalização de teclado e mouse](../../mfc/keyboard-and-mouse-customization.md)
