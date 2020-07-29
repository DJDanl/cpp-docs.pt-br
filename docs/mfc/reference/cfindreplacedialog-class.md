---
title: Classe CFindReplaceDialog
ms.date: 11/04/2016
f1_keywords:
- CFindReplaceDialog
- AFXDLGS/CFindReplaceDialog
- AFXDLGS/CFindReplaceDialog::CFindReplaceDialog
- AFXDLGS/CFindReplaceDialog::Create
- AFXDLGS/CFindReplaceDialog::FindNext
- AFXDLGS/CFindReplaceDialog::GetFindString
- AFXDLGS/CFindReplaceDialog::GetNotifier
- AFXDLGS/CFindReplaceDialog::GetReplaceString
- AFXDLGS/CFindReplaceDialog::IsTerminating
- AFXDLGS/CFindReplaceDialog::MatchCase
- AFXDLGS/CFindReplaceDialog::MatchWholeWord
- AFXDLGS/CFindReplaceDialog::ReplaceAll
- AFXDLGS/CFindReplaceDialog::ReplaceCurrent
- AFXDLGS/CFindReplaceDialog::SearchDown
- AFXDLGS/CFindReplaceDialog::m_fr
helpviewer_keywords:
- CFindReplaceDialog [MFC], CFindReplaceDialog
- CFindReplaceDialog [MFC], Create
- CFindReplaceDialog [MFC], FindNext
- CFindReplaceDialog [MFC], GetFindString
- CFindReplaceDialog [MFC], GetNotifier
- CFindReplaceDialog [MFC], GetReplaceString
- CFindReplaceDialog [MFC], IsTerminating
- CFindReplaceDialog [MFC], MatchCase
- CFindReplaceDialog [MFC], MatchWholeWord
- CFindReplaceDialog [MFC], ReplaceAll
- CFindReplaceDialog [MFC], ReplaceCurrent
- CFindReplaceDialog [MFC], SearchDown
- CFindReplaceDialog [MFC], m_fr
ms.assetid: 610f0b5d-b398-4ef6-8c05-e9d6641e50a8
ms.openlocfilehash: 92429bc17301d6615c87de958f38a717528e9544
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212430"
---
# <a name="cfindreplacedialog-class"></a>Classe CFindReplaceDialog

Permite implementar caixas de diálogo de localização/substituição de cadeia de caracteres padrão em seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CFindReplaceDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFindReplaceDialog:: CFindReplaceDialog](#cfindreplacedialog)|Chame essa função para construir um `CFindReplaceDialog` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFindReplaceDialog:: criar](#create)|Cria e exibe uma `CFindReplaceDialog` caixa de diálogo.|
|[CFindReplaceDialog:: LocalizarPróximo](#findnext)|Chame essa função para determinar se o usuário deseja encontrar a próxima ocorrência da cadeia de caracteres de localização.|
|[CFindReplaceDialog:: getlocalizestring](#getfindstring)|Chame essa função para recuperar a cadeia de caracteres de localização atual.|
|[CFindReplaceDialog:: getnotificator](#getnotifier)|Chame essa função para recuperar a `FINDREPLACE` estrutura em seu manipulador de mensagens registradas.|
|[CFindReplaceDialog:: getreplacestring](#getreplacestring)|Chame essa função para recuperar a cadeia de caracteres de substituição atual.|
|[CFindReplaceDialog:: isterminando](#isterminating)|Chame essa função para determinar se a caixa de diálogo está sendo encerrada.|
|[CFindReplaceDialog:: MatchCase](#matchcase)|Chame essa função para determinar se o usuário deseja corresponder exatamente ao caso da cadeia de caracteres de localização.|
|[CFindReplaceDialog:: MatchWholeWord](#matchwholeword)|Chame essa função para determinar se o usuário quer corresponder apenas palavras inteiras.|
|[CFindReplaceDialog:: ReplaceAll](#replaceall)|Chame essa função para determinar se o usuário deseja que todas as ocorrências da cadeia de caracteres sejam substituídas.|
|[CFindReplaceDialog:: ReplaceCurrent](#replacecurrent)|Chame essa função para determinar se o usuário deseja que a palavra atual seja substituída.|
|[CFindReplaceDialog:: SearchDown](#searchdown)|Chame essa função para determinar se o usuário deseja que a pesquisa continue em uma direção para baixo.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFindReplaceDialog:: m_fr](#m_fr)|Uma estrutura usada para personalizar um `CFindReplaceDialog` objeto.|

## <a name="remarks"></a>Comentários

Ao contrário das outras caixas de diálogo comuns do Windows, `CFindReplaceDialog` os objetos são sem janela restrita, permitindo que os usuários interajam com outras janelas enquanto estiverem na tela. Existem dois tipos de `CFindReplaceDialog` objetos: caixas de diálogo Localizar e localizar/substituir caixas de diálogo. Embora as caixas de diálogo permitam que o usuário insira pesquisas e pesquise/substitua cadeias de caracteres, elas não executam nenhuma das funções de pesquisa ou substituição. Você deve adicioná-los ao aplicativo.

Para construir um `CFindReplaceDialog` objeto, use o construtor fornecido (que não tem argumentos). Como essa é uma caixa de diálogo sem janela restrita, aloque o objeto no heap usando o **`new`** operador, em vez de na pilha.

Depois que um `CFindReplaceDialog` objeto tiver sido construído, você deverá chamar a função [criar](#create) membro para criar e exibir a caixa de diálogo.

Use a estrutura [m_fr](#m_fr) para inicializar a caixa de diálogo antes de chamar `Create` . A `m_fr` estrutura é do tipo [FINDREPLACE](/windows/win32/api/commdlg/ns-commdlg-findreplacew). Para obter mais informações sobre essa estrutura, consulte a SDK do Windows.

Para que a janela pai seja notificada de solicitações de localizar/substituir, você deve usar a função [RegisterWindowMessage](/windows/win32/api/winuser/nf-winuser-registerwindowmessagew) do Windows e usar o [ON_REGISTERED_MESSAGE](message-map-macros-mfc.md#on_registered_message) macro de mapeamento de mensagem na janela do quadro que manipula essa mensagem registrada.

Você pode determinar se o usuário optou por encerrar a caixa de diálogo com a `IsTerminating` função de membro.

`CFindReplaceDialog`o se baseia no arquivo de COMMDLG.DLL fornecido com as versões 3,1 e posteriores do Windows.

Para personalizar a caixa de diálogo, derive uma classe de `CFindReplaceDialog` , forneça um modelo de caixa de diálogo personalizado e adicione um mapa de mensagens para processar as mensagens de notificação dos controles estendidos. Todas as mensagens não processadas devem ser passadas para a classe base.

A personalização da função Hook não é necessária.

Para obter mais informações sobre como usar o `CFindReplaceDialog` , consulte [classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

`CFindReplaceDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

## <a name="cfindreplacedialogcfindreplacedialog"></a><a name="cfindreplacedialog"></a>CFindReplaceDialog:: CFindReplaceDialog

Constrói um objeto `CFindReplaceDialog`.

```
CFindReplaceDialog();
```

### <a name="remarks"></a>Comentários

Como o `CFindReplaceDialog` objeto é uma caixa de diálogo sem janela restrita, você deve construí-lo no heap usando o **`new`** operador.

Durante a destruição, a estrutura tenta executar uma **exclusão** no ponteiro para a caixa de diálogo. Se você criou a caixa de diálogo na pilha, o **`this`** ponteiro não existe e o comportamento indefinido pode resultar.

Para obter mais informações sobre a construção de `CFindReplaceDialog` objetos, consulte a visão geral do [CFindReplaceDialog](../../mfc/reference/cfindreplacedialog-class.md) . Use a função de membro [CFindReplaceDialog:: Create](#create) para exibir a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#170](../../mfc/codesnippet/cpp/cfindreplacedialog-class_1.cpp)]

## <a name="cfindreplacedialogcreate"></a><a name="create"></a>CFindReplaceDialog:: criar

Cria e exibe um objeto da caixa de diálogo Localizar ou localizar/substituir, dependendo do valor de `bFindDialogOnly` .

```
virtual BOOL Create(
    BOOL bFindDialogOnly,
    LPCTSTR lpszFindWhat,
    LPCTSTR lpszReplaceWith = NULL,
    DWORD dwFlags = FR_DOWN,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>parâmetros

*bFindDialogOnly*<br/>
Defina esse parâmetro como TRUE para exibir uma caixa de diálogo **Localizar** . Defina-a como FALSE para exibir uma caixa de diálogo **localizar/substituir** .

*lpszFindWhat*<br/>
Ponteiro para a cadeia de caracteres de pesquisa padrão quando a caixa de diálogo é exibida. Se for NULL, a caixa de diálogo não conterá uma cadeia de caracteres de pesquisa padrão.

*lpszReplaceWith*<br/>
Ponteiro para a cadeia de caracteres de substituição padrão quando a caixa de diálogo é exibida. Se for NULL, a caixa de diálogo não conterá uma cadeia de caracteres de substituição padrão.

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas usando o operador OR O valor padrão é FR_DOWN, que especifica que a pesquisa deve continuar em uma direção para baixo. Consulte a estrutura [FINDREPLACE](/windows/win32/api/commdlg/ns-commdlg-findreplacew) na SDK do Windows para obter mais informações sobre esses sinalizadores.

*pParentWnd*<br/>
Um ponteiro para a janela pai ou proprietário da caixa de diálogo. Esta é a janela que receberá a mensagem especial indicando que uma ação localizar/substituir é solicitada. Se for NULL, a janela principal do aplicativo será usada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto da caixa de diálogo foi criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para que a janela pai seja notificada de solicitações de localizar/substituir, você deve usar a função [RegisterWindowMessage](/windows/win32/api/winuser/nf-winuser-registerwindowmessagew) do Windows cujo valor de retorno é um número de mensagem exclusivo para a instância do aplicativo. A janela do quadro deve ter uma entrada de mapa de mensagem que declara a função de retorno de chamada ( `OnFindReplace` no exemplo a seguir) que manipula essa mensagem registrada. O fragmento de código a seguir é um exemplo de como fazer isso para uma classe de janela de quadro chamada `CMyRichEditView` :

[!code-cpp[NVC_MFCDocView#171](../../mfc/codesnippet/cpp/cfindreplacedialog-class_2.h)]

[!code-cpp[NVC_MFCDocView#172](../../mfc/codesnippet/cpp/cfindreplacedialog-class_3.cpp)]

[!code-cpp[NVC_MFCDocView#173](../../mfc/codesnippet/cpp/cfindreplacedialog-class_4.cpp)]

Dentro de sua `OnFindReplace` função, você interpreta as intenções do usuário usando os métodos [CFindReplaceDialog:: FindNext](#findnext) e [CFindReplaceDialog:: istermination](#isterminating) e cria o código para as operações localizar/substituir.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFindReplaceDialog:: CFindReplaceDialog](#cfindreplacedialog).

## <a name="cfindreplacedialogfindnext"></a><a name="findnext"></a>CFindReplaceDialog:: LocalizarPróximo

Chame essa função de sua função de retorno de chamada para determinar se o usuário deseja encontrar a próxima ocorrência da cadeia de caracteres de pesquisa.

```
BOOL FindNext() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário quiser encontrar a próxima ocorrência da cadeia de caracteres de pesquisa; caso contrário, 0.

## <a name="cfindreplacedialoggetfindstring"></a><a name="getfindstring"></a>CFindReplaceDialog:: getlocalizestring

Chame essa função da função de retorno de chamada para recuperar a cadeia de caracteres padrão a ser encontrada.

```
CString GetFindString() const;
```

### <a name="return-value"></a>Valor retornado

A cadeia de caracteres padrão a ser localizada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#69](../../mfc/codesnippet/cpp/cfindreplacedialog-class_5.cpp)]

## <a name="cfindreplacedialoggetnotifier"></a><a name="getnotifier"></a>CFindReplaceDialog:: getnotificator

Chame essa função para recuperar um ponteiro para a caixa de diálogo Localizar atual.

```
static CFindReplaceDialog* PASCAL GetNotifier(LPARAM lParam);
```

### <a name="parameters"></a>parâmetros

*lParam*<br/>
O valor de *lParam* passado para a função de membro da janela do quadro `OnFindReplace` .

### <a name="return-value"></a>Valor retornado

Um ponteiro para a caixa de diálogo atual.

### <a name="remarks"></a>Comentários

Ele deve ser usado em sua função de retorno de chamada para acessar a caixa de diálogo atual, chamar suas funções de membro e acessar a `m_fr` estrutura.

### <a name="example"></a>Exemplo

Consulte [CFindReplaceDialog:: Create](#create) para obter um exemplo de como registrar o manipulador OnFindReplace para receber notificações da caixa de diálogo localizar substituir.

[!code-cpp[NVC_MFCDocView#69](../../mfc/codesnippet/cpp/cfindreplacedialog-class_5.cpp)]

## <a name="cfindreplacedialoggetreplacestring"></a><a name="getreplacestring"></a>CFindReplaceDialog:: getreplacestring

Chame essa função para recuperar a cadeia de caracteres de substituição atual.

```
CString GetReplaceString() const;
```

### <a name="return-value"></a>Valor retornado

A cadeia de caracteres padrão com a qual substituir as cadeias de caracteres encontradas.

### <a name="example"></a>Exemplo

  Confira o exemplo de [CFindReplaceDialog:: Getlocalizestring](#getfindstring).

## <a name="cfindreplacedialogisterminating"></a><a name="isterminating"></a>CFindReplaceDialog:: isterminando

Chame essa função dentro de sua função de retorno de chamada para determinar se o usuário decidiu encerrar a caixa de diálogo.

```
BOOL IsTerminating() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário tiver decidido encerrar a caixa de diálogo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se essa função retornar um valor diferente de zero, você deverá chamar a `DestroyWindow` função de membro da caixa de diálogo atual e definir qualquer variável de ponteiro de caixa de diálogo como NULL. Opcionalmente, você também pode armazenar o texto de localização/substituição que foi inserido pela última vez e usá-lo para inicializar a próxima caixa de diálogo localizar/substituir.

### <a name="example"></a>Exemplo

  Confira o exemplo de [CFindReplaceDialog:: Getlocalizestring](#getfindstring).

## <a name="cfindreplacedialogm_fr"></a><a name="m_fr"></a>CFindReplaceDialog:: m_fr

Usado para personalizar um `CFindReplaceDialog` objeto.

```
FINDREPLACE m_fr;
```

### <a name="remarks"></a>Comentários

`m_fr`é uma estrutura do tipo [FINDREPLACE](/windows/win32/api/commdlg/ns-commdlg-findreplacew). Seus membros armazenam as características do objeto da caixa de diálogo. Depois de construir um `CFindReplaceDialog` objeto, você pode usar `m_fr` para modificar vários valores na caixa de diálogo.

Para obter mais informações sobre essa estrutura, consulte a `FINDREPLACE` estrutura na SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CFindReplaceDialog:: CFindReplaceDialog](#cfindreplacedialog).

## <a name="cfindreplacedialogmatchcase"></a><a name="matchcase"></a>CFindReplaceDialog:: MatchCase

Chame essa função para determinar se o usuário deseja corresponder exatamente ao caso da cadeia de caracteres de localização.

```
BOOL MatchCase() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário quiser encontrar ocorrências da cadeia de caracteres de pesquisa que correspondem exatamente ao caso da cadeia de caracteres de pesquisa; caso contrário, 0.

## <a name="cfindreplacedialogmatchwholeword"></a><a name="matchwholeword"></a>CFindReplaceDialog:: MatchWholeWord

Chame essa função para determinar se o usuário quer corresponder apenas palavras inteiras.

```
BOOL MatchWholeWord() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário quiser corresponder apenas às palavras inteiras da cadeia de caracteres de pesquisa; caso contrário, 0.

## <a name="cfindreplacedialogreplaceall"></a><a name="replaceall"></a>CFindReplaceDialog:: ReplaceAll

Chame essa função para determinar se o usuário deseja que todas as ocorrências da cadeia de caracteres sejam substituídas.

```
BOOL ReplaceAll() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário solicitou que todas as cadeias de caracteres correspondentes à cadeia de substituição sejam substituídas; caso contrário, 0.

## <a name="cfindreplacedialogreplacecurrent"></a><a name="replacecurrent"></a>CFindReplaceDialog:: ReplaceCurrent

Chame essa função para determinar se o usuário deseja que a palavra atual seja substituída.

```
BOOL ReplaceCurrent() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário tiver solicitado que a cadeia de caracteres atualmente selecionada seja substituída pela cadeia de caracteres de substituição; caso contrário, 0.

## <a name="cfindreplacedialogsearchdown"></a><a name="searchdown"></a>CFindReplaceDialog:: SearchDown

Chame essa função para determinar se o usuário deseja que a pesquisa continue em uma direção para baixo.

```
BOOL SearchDown() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o usuário quiser que a pesquisa continue em uma direção para baixo; 0 se o usuário quiser que a pesquisa continue em uma direção para cima.

## <a name="see-also"></a>Confira também

[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
