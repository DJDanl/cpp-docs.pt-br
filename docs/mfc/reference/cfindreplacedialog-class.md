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
ms.openlocfilehash: 7a12d0520d070d74afd9fa91e828970d14c82700
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373856"
---
# <a name="cfindreplacedialog-class"></a>Classe CFindReplaceDialog

Permite implementar caixas de diálogo padrão de seqüência de string Find/Replace em seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CFindReplaceDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CfindReplaceDiálogo::CFindReplaceDiálogo](#cfindreplacedialog)|Chame esta função `CFindReplaceDialog` para construir um objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFindReplaceDiálogo::Criar](#create)|Cria e `CFindReplaceDialog` exibe uma caixa de diálogo.|
|[CFindReplaceDialog::FindNext](#findnext)|Ligue para esta função para determinar se o usuário quer encontrar a próxima ocorrência da seqüência de achados.|
|[CFindReplaceDialog::getFindString](#getfindstring)|Chame esta função para recuperar a cadeia de encontrar atual.|
|[CFindReplaceDiálogo::GetNotifier](#getnotifier)|Ligue para esta `FINDREPLACE` função para recuperar a estrutura no manipulador de mensagens registrado.|
|[Diálogo de cfindreplace::getReplacestring](#getreplacestring)|Chame esta função para recuperar a seqüência de substituição atual.|
|[CFindreplaceDialog::Isterminating](#isterminating)|Ligue para esta função para determinar se a caixa de diálogo está terminando.|
|[CFindReplaceDialog::MatchCase](#matchcase)|Ligue para esta função para determinar se o usuário deseja corresponder exatamente ao caso da seqüência de achados.|
|[CfindReplaceDialog::MatchWholeword](#matchwholeword)|Ligue para esta função para determinar se o usuário deseja corresponder apenas a palavras inteiras.|
|[CFindReplaceDiálogo::SubstituirAll](#replaceall)|Chame esta função para determinar se o usuário deseja que todas as ocorrências da string sejam substituídas.|
|[CFindReplaceDiálogo::SubstituirCorrente](#replacecurrent)|Chame esta função para determinar se o usuário quer que a palavra atual seja substituída.|
|[CFindReplaceDiálogo::SearchDown](#searchdown)|Ligue para esta função para determinar se o usuário quer que a pesquisa prossiga em uma direção descendente.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFindReplaceDiálogo::m_fr](#m_fr)|Uma estrutura usada `CFindReplaceDialog` para personalizar um objeto.|

## <a name="remarks"></a>Comentários

Ao contrário das outras `CFindReplaceDialog` caixas de diálogo comuns do Windows, os objetos são modelados, permitindo que os usuários interajam com outras janelas enquanto estão na tela. Existem dois `CFindReplaceDialog` tipos de objetos: Encontrar caixas de diálogo e encontrar/substituir caixas de diálogo. Embora as caixas de diálogo permitam ao usuário inserir seqüências de pesquisa e pesquisa/substituição, elas não executam nenhuma das funções de busca ou substituição. Você deve adicioná-los à aplicação.

Para construir `CFindReplaceDialog` um objeto, use o construtor fornecido (que não tem argumentos). Uma vez que esta é uma caixa de diálogo modeless, aloque o objeto no heap usando o **novo** operador, em vez de na pilha.

Uma `CFindReplaceDialog` vez que um objeto tenha sido construído, você deve chamar a função [Criar](#create) membro para criar e exibir a caixa de diálogo.

Use a estrutura [m_fr](#m_fr) para inicializar `Create`a caixa de diálogo antes de ligar . A `m_fr` estrutura é do tipo [FINDREPLACE](/windows/win32/api/commdlg/ns-commdlg-findreplacew). Para obter mais informações sobre esta estrutura, consulte o Windows SDK.

Para que a janela pai seja notificada sobre as solicitações de encontrar/substituir, você deve usar a função Windows [RegisterWindowMessage](/windows/win32/api/winuser/nf-winuser-registerwindowmessagew) e usar a macro [ON_REGISTERED_MESSAGE](message-map-macros-mfc.md#on_registered_message) mapa de mensagem na janela do quadro que lida com esta mensagem registrada.

Você pode determinar se o usuário decidiu `IsTerminating` encerrar a caixa de diálogo com a função membro.

`CFindReplaceDialog`conta com o COMMDLG. Arquivo DLL que é fornecido com as versões 3.1 do Windows e posteriores.

Para personalizar a caixa de `CFindReplaceDialog`diálogo, obtenha uma classe, forneça um modelo de diálogo personalizado e adicione um mapa de mensagem para processar as mensagens de notificação dos controles estendidos. Quaisquer mensagens não processadas devem ser passadas para a classe base.

Personalizar a função do gancho não é necessário.

Para obter mais `CFindReplaceDialog`informações sobre como usar, consulte [Classes de Diálogo Comuns](../../mfc/common-dialog-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

`CFindReplaceDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs.h

## <a name="cfindreplacedialogcfindreplacedialog"></a><a name="cfindreplacedialog"></a>CfindReplaceDiálogo::CFindReplaceDiálogo

Constrói um objeto `CFindReplaceDialog`.

```
CFindReplaceDialog();
```

### <a name="remarks"></a>Comentários

Como `CFindReplaceDialog` o objeto é uma caixa de diálogo modeless, você deve construí-lo no heap usando o **novo** operador.

Durante a destruição, o framework tenta executar uma **exclusão disso** no ponteiro para a caixa de diálogo. Se você criou a caixa de diálogo na pilha, o **ponteiro não** existe e o comportamento indefinido pode resultar.

Para obter mais informações `CFindReplaceDialog` sobre a construção de objetos, consulte a visão geral do [CFindReplaceDialog.](../../mfc/reference/cfindreplacedialog-class.md) Use a [função CFindReplaceDialog::Criar](#create) membro para exibir a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#170](../../mfc/codesnippet/cpp/cfindreplacedialog-class_1.cpp)]

## <a name="cfindreplacedialogcreate"></a><a name="create"></a>CFindReplaceDiálogo::Criar

Cria e exibe um objeto de caixa de diálogo Encontrar `bFindDialogOnly`ou Encontrar/Substituir, dependendo do valor de .

```
virtual BOOL Create(
    BOOL bFindDialogOnly,
    LPCTSTR lpszFindWhat,
    LPCTSTR lpszReplaceWith = NULL,
    DWORD dwFlags = FR_DOWN,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*bFindDialogOnly*<br/>
Defina este parâmetro como TRUE para exibir uma caixa de diálogo **Encontrar.** Defina-o como FALSO para exibir uma caixa de diálogo **Encontrar/Substituir.**

*lpszFindWhat*<br/>
Ponteiro para a seqüência de pesquisa padrão quando a caixa de diálogo é exibida. Se NULA, a caixa de diálogo não contém uma seqüência de pesquisa padrão.

*lpszReplaceWith*<br/>
Ponteiro para a seqüência de substituição padrão quando a caixa de diálogo aparecer. Se NULA, a caixa de diálogo não contém uma seqüência de substituição padrão.

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas usando o operador bitwise OR. O valor padrão é FR_DOWN, que especifica que a pesquisa deve prosseguir em uma direção descendente. Consulte a estrutura [FINDREPLACE](/windows/win32/api/commdlg/ns-commdlg-findreplacew) no Windows SDK para obter mais informações sobre esses sinalizadores.

*Pparentwnd*<br/>
Um ponteiro para a janela pai ou proprietário da caixa de diálogo. Esta é a janela que receberá a mensagem especial indicando que uma ação de encontrar/substituir é solicitada. Se NULA, a janela principal do aplicativo é usada.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto da caixa de diálogo foi criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para que a janela pai seja notificada sobre as solicitações de encontrar/substituir, você deve usar a função Windows [RegisterWindowMessage](/windows/win32/api/winuser/nf-winuser-registerwindowmessagew) cujo valor de retorno é um número de mensagem exclusivo para a instância do aplicativo. A janela do quadro deve ter uma entrada de `OnFindReplace` mapa de mensagem que declare a função de retorno de chamada (no exemplo a seguir) que lida com esta mensagem registrada. O fragmento de código a seguir é um exemplo `CMyRichEditView`de como fazer isso para uma classe de janela de quadro chamada :

[!code-cpp[NVC_MFCDocView#171](../../mfc/codesnippet/cpp/cfindreplacedialog-class_2.h)]

[!code-cpp[NVC_MFCDocView#172](../../mfc/codesnippet/cpp/cfindreplacedialog-class_3.cpp)]

[!code-cpp[NVC_MFCDocView#173](../../mfc/codesnippet/cpp/cfindreplacedialog-class_4.cpp)]

Dentro `OnFindReplace` de sua função, você interpreta as intenções do usuário usando o [CFindReplaceDialog::FindNext](#findnext) e [CFindReplaceDiálogo::Métodos de nomeação](#isterminating) e você cria o código para as operações de encontrar/substituir.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFindReplaceDialog::CFindReplaceDialog](#cfindreplacedialog).

## <a name="cfindreplacedialogfindnext"></a><a name="findnext"></a>CFindReplaceDialog::FindNext

Ligue para esta função de retorno de chamada para determinar se o usuário deseja encontrar a próxima ocorrência da seqüência de pesquisa.

```
BOOL FindNext() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário quiser encontrar a próxima ocorrência da seqüência de pesquisa; caso contrário, 0.

## <a name="cfindreplacedialoggetfindstring"></a><a name="getfindstring"></a>CFindReplaceDialog::getFindString

Chame esta função de chamada de volta para recuperar a seqüência padrão a ser encontrar.

```
CString GetFindString() const;
```

### <a name="return-value"></a>Valor retornado

A seqüência padrão a ser encontrar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#69](../../mfc/codesnippet/cpp/cfindreplacedialog-class_5.cpp)]

## <a name="cfindreplacedialoggetnotifier"></a><a name="getnotifier"></a>CFindReplaceDiálogo::GetNotifier

Chame esta função para recuperar um ponteiro para a caixa de diálogo Encontrar substituir atual.

```
static CFindReplaceDialog* PASCAL GetNotifier(LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*lParam*<br/>
O valor *de lparam* passou `OnFindReplace` para a função de membro da janela do quadro.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a caixa de diálogo atual.

### <a name="remarks"></a>Comentários

Ele deve ser usado dentro de sua função de retorno de chamada para `m_fr` acessar a caixa de diálogo atual, chamar suas funções de membro e acessar a estrutura.

### <a name="example"></a>Exemplo

Consulte [CFindReplaceDialog::Crie](#create) um exemplo de como registrar o manipulador OnFindReplace para receber notificações da caixa de diálogo Encontrar substituir.

[!code-cpp[NVC_MFCDocView#69](../../mfc/codesnippet/cpp/cfindreplacedialog-class_5.cpp)]

## <a name="cfindreplacedialoggetreplacestring"></a><a name="getreplacestring"></a>Diálogo de cfindreplace::getReplacestring

Chame esta função para recuperar a seqüência de substituição atual.

```
CString GetReplaceString() const;
```

### <a name="return-value"></a>Valor retornado

A seqüência padrão com a qual substituir as strings encontradas.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFindReplaceDialog::GetFindString](#getfindstring).

## <a name="cfindreplacedialogisterminating"></a><a name="isterminating"></a>CFindreplaceDialog::Isterminating

Chame esta função dentro de sua função de retorno de chamada para determinar se o usuário decidiu encerrar a caixa de diálogo.

```
BOOL IsTerminating() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário decidiu encerrar a caixa de diálogo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se esta função retornar não zero, você deve chamar a `DestroyWindow` função membro da caixa de diálogo atual e definir qualquer variável ponteiro da caixa de diálogo para NULL. Opcionalmente, você também pode armazenar o texto de encontrar/substituir por último inserido e usá-lo para inicializar a próxima caixa de diálogo encontrar/substituir.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFindReplaceDialog::GetFindString](#getfindstring).

## <a name="cfindreplacedialogm_fr"></a><a name="m_fr"></a>CFindReplaceDiálogo::m_fr

Usado para `CFindReplaceDialog` personalizar um objeto.

```
FINDREPLACE m_fr;
```

### <a name="remarks"></a>Comentários

`m_fr`é uma estrutura do tipo [FINDREPLACE](/windows/win32/api/commdlg/ns-commdlg-findreplacew). Seus membros armazenam as características do objeto caixa de diálogo. Depois de `CFindReplaceDialog` construir um objeto, você pode usar `m_fr` para modificar vários valores na caixa de diálogo.

Para obter mais informações sobre `FINDREPLACE` esta estrutura, consulte a estrutura no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFindReplaceDialog::CFindReplaceDialog](#cfindreplacedialog).

## <a name="cfindreplacedialogmatchcase"></a><a name="matchcase"></a>CFindReplaceDialog::MatchCase

Ligue para esta função para determinar se o usuário deseja corresponder exatamente ao caso da seqüência de achados.

```
BOOL MatchCase() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário quiser encontrar ocorrências da seqüência de pesquisa que correspondam exatamente ao caso da seqüência de pesquisa; caso contrário, 0.

## <a name="cfindreplacedialogmatchwholeword"></a><a name="matchwholeword"></a>CfindReplaceDialog::MatchWholeword

Ligue para esta função para determinar se o usuário deseja corresponder apenas a palavras inteiras.

```
BOOL MatchWholeWord() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário quiser corresponder apenas às palavras inteiras da seqüência de pesquisa; caso contrário, 0.

## <a name="cfindreplacedialogreplaceall"></a><a name="replaceall"></a>CFindReplaceDiálogo::SubstituirAll

Chame esta função para determinar se o usuário deseja que todas as ocorrências da string sejam substituídas.

```
BOOL ReplaceAll() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário tiver solicitado que todas as strings correspondentes à seqüência de substituição sejam substituídas; caso contrário, 0.

## <a name="cfindreplacedialogreplacecurrent"></a><a name="replacecurrent"></a>CFindReplaceDiálogo::SubstituirCorrente

Chame esta função para determinar se o usuário quer que a palavra atual seja substituída.

```
BOOL ReplaceCurrent() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário tiver solicitado que a seqüência de string selecionada seja substituída pela seqüência de substituição; caso contrário, 0.

## <a name="cfindreplacedialogsearchdown"></a><a name="searchdown"></a>CFindReplaceDiálogo::SearchDown

Ligue para esta função para determinar se o usuário quer que a pesquisa prossiga em uma direção descendente.

```
BOOL SearchDown() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o usuário quiser que a pesquisa prossiga em uma direção descendente; 0 se o usuário quiser que a pesquisa prossiga em uma direção ascendente.

## <a name="see-also"></a>Confira também

[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
