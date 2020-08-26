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
ms.openlocfilehash: e67bbb18b6a87edfaa4bc4c410ec28eb613ed51d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841487"
---
# <a name="ckeyboardmanager-class"></a>Classe CKeyboardManager

Gerencia tabelas de teclas de atalho para a janela de quadro principal e janelas de quadro filho.

## <a name="syntax"></a>Sintaxe

```
class CKeyboardManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|-|-|
|[CKeyboardManager::CKeyboardManager](#ckeyboardmanager)|Constrói um objeto `CKeyboardManager`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CKeyboardManager:: CleanUp](#cleanup)|Limpa as tabelas de teclas de atalho.|
|[CKeyboardManager::FindDefaultAccelerator](#finddefaultaccelerator)|Recupera a tecla de atalho padrão para o comando e a janela especificados.|
|[CKeyboardManager::IsKeyHandled](#iskeyhandled)|Determina se uma chave é manipulada pela tabela do acelerador.|
|[CKeyboardManager::IsKeyPrintable](#iskeyprintable)|Indica se um caractere é imprimível.|
|[CKeyboardManager::IsShowAllAccelerators](#isshowallaccelerators)|Indica se os menus mostram todas as teclas de atalho para um comando ou apenas a tecla de atalho padrão.|
|[CKeyboardManager:: LoadState](#loadstate)|Carrega as tabelas de teclas de atalho do registro do Windows.|
|[CKeyboardManager::ResetAll](#resetall)|Recarrega as tabelas de teclas de atalho do recurso de aplicativo.|
|[CKeyboardManager:: SaveState](#savestate)|Salva as tabelas de teclas de atalho no registro do Windows.|
|[CKeyboardManager::ShowAllAccelerators](#showallaccelerators)|Especifica se a estrutura exibe todas as teclas de atalho para todos os comandos ou uma única tecla de atalho para cada comando. Esse método não afeta os comandos que têm apenas uma tecla de atalho associada.|
|[CKeyboardManager::TranslateCharToUpper](#translatechartoupper)|Converte um caractere em seu registro superior.|
|[CKeyboardManager::UpdateAccelTable](#updateacceltable)|Atualiza uma tabela de teclas de atalho com uma nova tabela de teclas de atalho.|

## <a name="remarks"></a>Comentários

Os membros dessa classe permitem salvar e carregar tabelas de teclas de atalho no registro do Windows, usar um modelo para atualizar as tabelas de chave de corte curto e localizar a tecla de atalho padrão para um comando em uma janela do quadro. Além disso, o `CKeyboardManager` objeto permite que você controle como as teclas de atalho são exibidas para o usuário.

Você não deve criar um `CKeyboardManager` objeto manualmente. Ele será criado automaticamente pela estrutura do seu aplicativo. No entanto, você deve chamar [CWinAppEx:: InitKeyboardManager](../../mfc/reference/cwinappex-class.md#initkeyboardmanager) durante o processo de inicialização do seu aplicativo. Para obter um ponteiro para o Gerenciador de teclado para seu aplicativo, chame [CWinAppEx:: GetKeyboardManager](../../mfc/reference/cwinappex-class.md#getkeyboardmanager).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como recuperar um ponteiro para um `CKeyboardManager` objeto de uma `CWinAppEx` classe e como mostrar todas as teclas de atalho associadas a comandos de menu. Este trecho de código faz parte do [exemplo de páginas personalizadas](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_CustomPages#5](../../mfc/reference/codesnippet/cpp/ckeyboardmanager-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxkeyboardmanager. h

## <a name="ckeyboardmanagerckeyboardmanager"></a><a name="ckeyboardmanager"></a> CKeyboardManager::CKeyboardManager

Constrói um objeto `CKeyboardManager`.

```
CKeyboardManager();
```

### <a name="remarks"></a>Comentários

Na maioria dos casos, você não precisa criar um `CKeyboardManager` diretamente. Por padrão, a estrutura cria uma para você. Para obter um ponteiro para `CKeyboardManager` , chame [CWinAppEx:: GetKeyboardManager](../../mfc/reference/cwinappex-class.md#getkeyboardmanager). Se você criar uma manualmente, deverá inicializá-la com o método [CWinAppEx:: InitKeyboardManager](../../mfc/reference/cwinappex-class.md#initkeyboardmanager).

## <a name="ckeyboardmanagercleanup"></a><a name="cleanup"></a> CKeyboardManager:: CleanUp

Libera os `CKeyboardManager` recursos e limpa todos os mapeamentos de tecla de atalho.

```
static void CleanUp();
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre teclas de atalho, consulte [personalização de teclado e mouse](../../mfc/keyboard-and-mouse-customization.md).

Você não precisa chamar essa função quando o aplicativo é encerrado porque a estrutura a chama automaticamente durante a saída do aplicativo.

## <a name="ckeyboardmanagerfinddefaultaccelerator"></a><a name="finddefaultaccelerator"></a> CKeyboardManager::FindDefaultAccelerator

Recupera a tecla de atalho padrão para o comando e a janela especificados.

```
static BOOL FindDefaultAccelerator(
    UINT uiCmd,
    CString& str,
    CFrameWnd* pWndFrame,
    BOOL bIsDefaultFrame);
```

### <a name="parameters"></a>parâmetros

*uiCmd*<br/>
no A ID do comando.

*Str*<br/>
fora Uma referência a um `CString` objeto.

*pWndFrame*<br/>
no Um ponteiro para uma janela de quadro.

*bIsDefaultFrame*<br/>
no Especifica se a janela do quadro é a janela de quadro padrão.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o atalho for encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método pesquisa o comando especificado por *uiCmd* e recupera a tecla de atalho padrão. Em seguida, o método usa a cadeia de caracteres associada a essa tecla de atalho e grava o valor no parâmetro *Str* .

## <a name="ckeyboardmanageriskeyhandled"></a><a name="iskeyhandled"></a> CKeyboardManager::IsKeyHandled

Determina se a chave especificada é manipulada pela [Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md).

```
static BOOL __stdcall IsKeyHandled(
    WORD nKey,
    BYTE fVirt,
    CFrameWnd* pWndFrame,
    BOOL bIsDefaultFrame);
```

### <a name="parameters"></a>parâmetros

*nKey*\
no A chave a ser verificada.

*fVirt*\
no Especifica o comportamento da tecla de atalho. Para obter uma lista de valores possíveis, consulte [estrutura da aceleração extra](/windows/win32/api/winuser/ns-winuser-accel).

*pWndFrame*\
no Uma janela do quadro. Esse método determina se uma tecla de atalho é manipulada neste quadro.

*bIsDefaultFrame*\
no Um parâmetro booliano que indica se *pWndFrame* é a janela de quadro padrão.

### <a name="return-value"></a>Valor Retornado

TRUE se a tecla de atalho for manipulada. FALSE se a chave não for manipulada ou se *pWndFrame* for nulo.

### <a name="remarks"></a>Comentários

Os parâmetros de entrada devem corresponder à entrada na tabela do acelerador para *nKey* e *fVirt* para determinar se uma tecla de atalho é manipulada em *pWndFrame*.

## <a name="ckeyboardmanageriskeyprintable"></a><a name="iskeyprintable"></a> CKeyboardManager::IsKeyPrintable

Indica se um caractere é imprimível.

```
static BOOL __stdcall IsKeyPrintable(const UINT nChar);
```

### <a name="parameters"></a>parâmetros

*nChar*\
no O caractere que esse método verifica.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o caractere for imprimível, zero se não for.

### <a name="remarks"></a>Comentários

Esse método falhará se uma chamada para [GetKeyboardState](/windows/win32/api/winuser/nf-winuser-getkeyboardstate) falhar.

## <a name="ckeyboardmanagerisshowallaccelerators"></a><a name="isshowallaccelerators"></a> CKeyboardManager::IsShowAllAccelerators

Indica se os menus mostram todas as teclas de atalho associadas a comandos de menu ou apenas as teclas de atalho padrão.

```
static BOOL IsShowAllAccelerators();
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o aplicativo listar todas as teclas de atalho para comandos de menu; 0 se o aplicativo exibir apenas as teclas de atalho padrão.

### <a name="remarks"></a>Comentários

O aplicativo lista as teclas de atalho para comandos de menu na barra de menus. Use a função [CKeyboardManager:: ShowAllAccelerators](#showallaccelerators) para controlar se o aplicativo listará todas as teclas de atalho ou apenas as teclas de atalho padrão.

## <a name="ckeyboardmanagerloadstate"></a><a name="loadstate"></a> CKeyboardManager:: LoadState

Carrega as tabelas de teclas de atalho do registro do Windows.

```
BOOL LoadState(
    LPCTSTR lpszProfileName = NULL,
    CFrameWnd* pDefaultFrame = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszProfileName*<br/>
no O caminho do registro em que os `CKeyboardManager` dados são salvos.

*pDefaultFrame*<br/>
no Um ponteiro para uma janela de quadro a ser usado como a janela padrão.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o estado foi carregado com êxito ou 0 caso contrário.

### <a name="remarks"></a>Comentários

Se o parâmetro *lpszProfileName* for NULL, esse método verificará o local do registro padrão em busca de `CKeyboardManager` dados. O local do registro padrão é especificado pela [classe CWinAppEx](../../mfc/reference/cwinappex-class.md). Os dados devem ser gravados anteriormente com o método [CKeyboardManager:: SaveState](#savestate).

Se você não especificar uma janela padrão, a janela do quadro principal do seu aplicativo será usada.

## <a name="ckeyboardmanagerresetall"></a><a name="resetall"></a> CKeyboardManager::ResetAll

Recarrega as tabelas de teclas de atalho do recurso de aplicativo.

```cpp
void ResetAll();
```

### <a name="remarks"></a>Comentários

Essa função limpa os atalhos armazenados na `CKeyboardManager` instância. Em seguida, ele recarregará o estado do Gerenciador de teclado do recurso de aplicativo.

## <a name="ckeyboardmanagersavestate"></a><a name="savestate"></a> CKeyboardManager:: SaveState

Salva as tabelas de teclas de atalho no registro do Windows.

```
BOOL SaveState(
    LPCTSTR lpszProfileName = NULL,
    CFrameWnd* pDefaultFrame = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszProfileName*<br/>
no O caminho do registro para salvar o `CKeyboardManager` estado.

*pDefaultFrame*<br/>
no Um ponteiro para uma janela de quadro que se torna a janela padrão.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o estado do Gerenciador de teclado foi salvo com êxito ou 0 caso contrário.

### <a name="remarks"></a>Comentários

Se o parâmetro *lpszProfileName* for NULL, esse método gravará o `CKeyboardManager` estado no local padrão especificado pela [classe CWinAppEx](../../mfc/reference/cwinappex-class.md). Se você especificar um local, poderá carregar os dados mais tarde usando o método [CKeyboardManager:: LoadState](#loadstate).

Se você não especificar uma janela padrão, a janela do quadro principal será usada como a janela padrão.

## <a name="ckeyboardmanagershowallaccelerators"></a><a name="showallaccelerators"></a> CKeyboardManager::ShowAllAccelerators

Mostra todas as teclas de atalho associadas a comandos de menu.

```
static void ShowAllAccelerators(
    BOOL bShowAll = TRUE,
    LPCTSTR lpszDelimiter = _afxDefaultAcceleratorDelimiter);
```

### <a name="parameters"></a>parâmetros

*bShowAll*<br/>
no Se for TRUE, todas as teclas de atalho serão exibidas. Se for FALSE, somente a primeira tecla de atalho será exibida.

*lpszDelimiter*<br/>
no Uma cadeia de caracteres a ser inserida entre as teclas de atalho. Esse delimitador não terá efeito se apenas uma tecla de atalho for exibida.

### <a name="remarks"></a>Comentários

Por padrão, se um comando tiver mais de uma tecla de atalho associada a ela, somente a primeira tecla de atalho será mostrada. Essa função permite listar todas as teclas de atalho associadas a todos os comandos.

As teclas de atalho serão listadas ao lado do comando na barra de menus. Se todas as teclas de atalho forem exibidas, a cadeia de caracteres fornecida pelo *lpszDelimiter* irá separar as teclas de atalho individuais.

## <a name="ckeyboardmanagertranslatechartoupper"></a><a name="translatechartoupper"></a> CKeyboardManager::TranslateCharToUpper

Converte um caractere em seu registro superior.

```
static UINT TranslateCharToUpper(const UINT nChar);
```

### <a name="parameters"></a>parâmetros

*nChar*<br/>
no O caractere a ser convertido.

### <a name="return-value"></a>Valor Retornado

O caractere que é o registro superior do parâmetro de entrada.

## <a name="ckeyboardmanagerupdateacceltable"></a><a name="updateacceltable"></a> CKeyboardManager::UpdateAccelTable

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

### <a name="parameters"></a>parâmetros

*pTemplate*<br/>
no Um ponteiro para um modelo de documento.

*lpAccel*<br/>
no Um ponteiro para a nova tecla de atalho.

*nSize*<br/>
no O tamanho da nova tabela de atalho.

*pDefaultFrame*<br/>
no Um ponteiro para a janela do quadro padrão.

*hAccelNew*<br/>
no Um identificador para a nova tabela de atalho.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o método for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use essa função para substituir a tabela de atalho existente por novas teclas de atalho para vários objetos de janela de quadro. A função recebe um modelo de documento como um parâmetro para obter acesso a todos os objetos de janela de quadro conectados ao modelo de documento específico.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)<br/>
[CWinAppEx::InitKeyboardManager](../../mfc/reference/cwinappex-class.md#initkeyboardmanager)<br/>
[Personalização de teclado e mouse](../../mfc/keyboard-and-mouse-customization.md)
