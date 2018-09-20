---
title: Classe CFindReplaceDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7948b755e65b3a64c57f2fd99cf4eefa68cb3cb9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46432367"
---
# <a name="cfindreplacedialog-class"></a>Classe CFindReplaceDialog

Permite que você implemente caixas de diálogo Localizar/Substituir de cadeia de caracteres padrão em seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CFindReplaceDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFindReplaceDialog::CFindReplaceDialog](#cfindreplacedialog)|Chame essa função para construir um `CFindReplaceDialog` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFindReplaceDialog::Create](#create)|Cria e exibe um `CFindReplaceDialog` caixa de diálogo.|
|[CFindReplaceDialog::FindNext](#findnext)|Chame essa função para determinar se o usuário deseja localizar a próxima ocorrência da cadeia de caracteres de localização.|
|[CFindReplaceDialog::GetFindString](#getfindstring)|Chame essa função para recuperar a cadeia de caracteres de localização atual.|
|[CFindReplaceDialog::GetNotifier](#getnotifier)|Chame essa função para recuperar o `FINDREPLACE` estrutura em seu manipulador de mensagem registrados.|
|[CFindReplaceDialog::GetReplaceString](#getreplacestring)|Chame essa função para recuperar a cadeia de caracteres de substituição atual.|
|[CFindReplaceDialog::IsTerminating](#isterminating)|Chame essa função para determinar se a caixa de diálogo está sendo encerrado.|
|[CFindReplaceDialog::MatchCase](#matchcase)|Chame essa função para determinar se o usuário deseja corresponder o caso de cadeia de caracteres a localizar exatamente.|
|[CFindReplaceDialog::MatchWholeWord](#matchwholeword)|Chame essa função para determinar se o usuário deseja corresponder a somente palavras inteiras.|
|[CFindReplaceDialog::ReplaceAll](#replaceall)|Chame essa função para determinar se o usuário deseja todas as ocorrências da cadeia de caracteres a ser substituído.|
|[CFindReplaceDialog::ReplaceCurrent](#replacecurrent)|Chame essa função para determinar se o usuário deseja que a palavra atual a ser substituído.|
|[CFindReplaceDialog::SearchDown](#searchdown)|Chame essa função para determinar se o usuário deseja que a pesquisa para continuar em uma direção para baixo.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFindReplaceDialog::m_fr](#m_fr)|Uma estrutura usada para personalizar um `CFindReplaceDialog` objeto.|

## <a name="remarks"></a>Comentários

Ao contrário de outras Windows caixas de diálogo comuns, `CFindReplaceDialog` objetos são sem janela restrita, permitindo que os usuários interajam com outras janelas enquanto eles estão na tela. Há dois tipos de `CFindReplaceDialog` objetos: localizar caixas de diálogo e caixas de diálogo Localizar/Substituir. Embora as caixas de diálogo permitir que o usuário pesquisa inserido e cadeias de caracteres de busca e troca, eles não executam qualquer uma da pesquisa ou substituição de funções. Você deve adicioná-los ao aplicativo.

Para construir um `CFindReplaceDialog` de objeto, use o construtor fornecido (que não tem argumentos). Como essa é uma caixa de diálogo sem janela restrita, alocar o objeto no heap usando a **novo** operador, em vez de na pilha.

Uma vez um `CFindReplaceDialog` objeto foi construído, você deve chamar o [criar](#create) função de membro para criar e exibir a caixa de diálogo.

Use o [m_fr](#m_fr) estrutura para inicializar a caixa de diálogo antes de chamar `Create`. O `m_fr` estrutura é do tipo [FINDREPLACE](/windows/desktop/api/commdlg/ns-commdlg-tagfindreplacea). Para obter mais informações sobre essa estrutura, consulte o SDK do Windows.

Para a janela pai a ser notificado de localizar/substituir solicitações, você deve usar o Windows [RegisterWindowMessage](https://msdn.microsoft.com/library/windows/desktop/ms644947) funcionar e usar o [ON_REGISTERED_MESSAGE](message-map-macros-mfc.md#on_registered_message) macro de mapa de mensagem em seu quadro janela que manipula essa mensagem registrada.

Você pode determinar se o usuário optou por encerrar a caixa de diálogo com o `IsTerminating` função de membro.

`CFindReplaceDialog` depende do COMMDLG. Arquivo DLL que acompanha o Windows versões 3.1 e posteriores.

Para personalizar a caixa de diálogo, derive uma classe de `CFindReplaceDialog`, forneça um modelo de caixa de diálogo personalizada e adicionar um mapa de mensagem para processar as mensagens de notificação de controles estendidos. Quaisquer mensagens não processadas devem ser passadas para a classe base.

Personalizando a função de gancho não é necessária.

Para obter mais informações sobre como usar `CFindReplaceDialog`, consulte [Classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

`CFindReplaceDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdlgs. h

##  <a name="cfindreplacedialog"></a>  CFindReplaceDialog::CFindReplaceDialog

Constrói um objeto `CFindReplaceDialog`.

```
CFindReplaceDialog();
```

### <a name="remarks"></a>Comentários

Porque o `CFindReplaceDialog` objeto é uma caixa de diálogo sem janela restrita, construí-o no heap usando a **nova** operador.

Durante a destruição, o framework tenta executar uma **excluir este** no ponteiro para a caixa de diálogo. Se você tiver criado a caixa de diálogo na pilha, o **isso** ponteiro não existir e poderá ocorrer um comportamento indefinido.

Para obter mais informações sobre a construção de `CFindReplaceDialog` objetos, consulte a [CFindReplaceDialog](../../mfc/reference/cfindreplacedialog-class.md) visão geral. Use o [CFindReplaceDialog::Create](#create) a função de membro para exibir a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#170](../../mfc/codesnippet/cpp/cfindreplacedialog-class_1.cpp)]

##  <a name="create"></a>  CFindReplaceDialog::Create

Cria e exibe um localizar ou localizar/substituir caixa de diálogo caixa objeto, dependendo do valor de `bFindDialogOnly`.

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
Definir esse parâmetro como TRUE para exibir uma **localizar** caixa de diálogo. Defina-o como FALSE para exibir uma **localizar/substituir** caixa de diálogo.

*lpszFindWhat*<br/>
Ponteiro para a cadeia de pesquisa padrão quando a caixa de diálogo é exibida. Se for NULL, a caixa de diálogo não contém uma cadeia de caracteres de pesquisa padrão.

*lpszReplaceWith*<br/>
Ponteiro para a cadeia de caracteres de substituição de padrão quando a caixa de diálogo é exibida. Se for NULL, a caixa de diálogo não contém uma cadeia de caracteres de substituição padrão.

*dwFlags*<br/>
Um ou mais sinalizadores que você pode usar para personalizar as configurações da caixa de diálogo, combinadas com o operador OR bit a bit. O valor padrão é FR_DOWN, que especifica que a pesquisa deve continuar em uma direção para baixo. Consulte a [FINDREPLACE](/windows/desktop/api/commdlg/ns-commdlg-tagfindreplacea) estrutura no SDK do Windows para obter mais informações sobre esses sinalizadores.

*pParentWnd*<br/>
Um ponteiro para a janela do pai ou proprietária da caixa de diálogo. Esta é a janela que receberá a mensagem especial que indica que uma ação de localizar/substituir é solicitada. Se for NULL, a janela principal do aplicativo é usada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto de caixa de diálogo foi criado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para a janela pai a ser notificado de localizar/substituir solicitações, você deve usar o Windows [RegisterWindowMessage](https://msdn.microsoft.com/library/windows/desktop/ms644947) função cujo valor de retorno é um número de mensagem exclusivo a instância do aplicativo. A janela do quadro deve ter uma entrada de mapa de mensagem que declara a função de retorno de chamada ( `OnFindReplace` no exemplo a seguir) que manipula essa mensagem registrada. O fragmento de código a seguir está um exemplo de como fazer isso para uma classe de janela de quadro chamada `CMyRichEditView`:

[!code-cpp[NVC_MFCDocView#171](../../mfc/codesnippet/cpp/cfindreplacedialog-class_2.h)]

[!code-cpp[NVC_MFCDocView#172](../../mfc/codesnippet/cpp/cfindreplacedialog-class_3.cpp)]

[!code-cpp[NVC_MFCDocView#173](../../mfc/codesnippet/cpp/cfindreplacedialog-class_4.cpp)]

Dentro de seu `OnFindReplace` função, interpretar as intenções do usuário usando o [CFindReplaceDialog::FindNext](#findnext) e [CFindReplaceDialog::IsTerminating](#isterminating) métodos e você criar o código para as operações de localizar/substituir.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFindReplaceDialog::CFindReplaceDialog](#cfindreplacedialog).

##  <a name="findnext"></a>  CFindReplaceDialog::FindNext

Chame essa função de sua função de retorno de chamada para determinar se o usuário deseja localizar a próxima ocorrência da cadeia de caracteres de pesquisa.

```
BOOL FindNext() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário deseja localizar a próxima ocorrência da cadeia de caracteres de pesquisa; Caso contrário, 0.

##  <a name="getfindstring"></a>  CFindReplaceDialog::GetFindString

Chame essa função de sua função de retorno de chamada para recuperar a cadeia de caracteres padrão para localizar.

```
CString GetFindString() const;
```

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres padrão para localizar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#69](../../mfc/codesnippet/cpp/cfindreplacedialog-class_5.cpp)]

##  <a name="getnotifier"></a>  CFindReplaceDialog::GetNotifier

Chame essa função para recuperar um ponteiro para a caixa de diálogo Localizar Substituir atual.

```
static CFindReplaceDialog* PASCAL GetNotifier(LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*lParam*<br/>
O *lparam* valor passado para a janela do quadro `OnFindReplace` função de membro.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a caixa de diálogo atual.

### <a name="remarks"></a>Comentários

Ele deve ser usado dentro de sua função de retorno de chamada para acessar a caixa de diálogo atual, chame seu membro funções e acesso a `m_fr` estrutura.

### <a name="example"></a>Exemplo

Ver [CFindReplaceDialog::Create](#create) para obter um exemplo de como registrar o manipulador OnFindReplace para receber notificações de caixa de diálogo Localizar Substituir.

[!code-cpp[NVC_MFCDocView#69](../../mfc/codesnippet/cpp/cfindreplacedialog-class_5.cpp)]

##  <a name="getreplacestring"></a>  CFindReplaceDialog::GetReplaceString

Chame essa função para recuperar a cadeia de caracteres de substituição atual.

```
CString GetReplaceString() const;
```

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres de padrão com o qual substituir cadeias de caracteres encontradas.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFindReplaceDialog::GetFindString](#getfindstring).

##  <a name="isterminating"></a>  CFindReplaceDialog::IsTerminating

Chame essa função dentro de sua função de retorno de chamada para determinar se o usuário optou por encerrar a caixa de diálogo.

```
BOOL IsTerminating() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário optou por encerrar a caixa de diálogo; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se essa função retorna não zero, você deve chamar o `DestroyWindow` a função de membro da caixa de diálogo atual caixa e defina a variável de ponteiro de qualquer caixa de diálogo como nulo. Opcionalmente, você também pode armazenar o texto de localizar/substituir inserido pela última vez e usá-lo para inicializar a caixa de diálogo Localizar/Substituir próximo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFindReplaceDialog::GetFindString](#getfindstring).

##  <a name="m_fr"></a>  CFindReplaceDialog::m_fr

Usado para personalizar um `CFindReplaceDialog` objeto.

```
FINDREPLACE m_fr;
```

### <a name="remarks"></a>Comentários

`m_fr` é uma estrutura do tipo [FINDREPLACE](/windows/desktop/api/commdlg/ns-commdlg-tagfindreplacea). Seus membros armazenam as características do objeto de caixa de diálogo. Depois de criar uma `CFindReplaceDialog` objeto, você pode usar `m_fr` modificar vários valores na caixa de diálogo.

Para obter mais informações sobre essa estrutura, consulte o `FINDREPLACE` estrutura no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CFindReplaceDialog::CFindReplaceDialog](#cfindreplacedialog).

##  <a name="matchcase"></a>  CFindReplaceDialog::MatchCase

Chame essa função para determinar se o usuário deseja corresponder o caso de cadeia de caracteres a localizar exatamente.

```
BOOL MatchCase() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário desejar localizar ocorrências da cadeia de caracteres de pesquisa que correspondem exatamente o caso da cadeia de caracteres de pesquisa; Caso contrário, 0.

##  <a name="matchwholeword"></a>  CFindReplaceDialog::MatchWholeWord

Chame essa função para determinar se o usuário deseja corresponder a somente palavras inteiras.

```
BOOL MatchWholeWord() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário deseja corresponder a apenas as palavras inteiras da cadeia de caracteres de pesquisa; Caso contrário, 0.

##  <a name="replaceall"></a>  CFindReplaceDialog::ReplaceAll

Chame essa função para determinar se o usuário deseja todas as ocorrências da cadeia de caracteres a ser substituído.

```
BOOL ReplaceAll() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário solicitou que todas as cadeias de caracteres de correspondência de cadeia de caracteres de substituição seja substituído; Caso contrário, 0.

##  <a name="replacecurrent"></a>  CFindReplaceDialog::ReplaceCurrent

Chame essa função para determinar se o usuário deseja que a palavra atual a ser substituído.

```
BOOL ReplaceCurrent() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário solicitou que a cadeia de caracteres atualmente selecionada substituirá a cadeia de caracteres de substituição; Caso contrário, 0.

##  <a name="searchdown"></a>  CFindReplaceDialog::SearchDown

Chame essa função para determinar se o usuário deseja que a pesquisa para continuar em uma direção para baixo.

```
BOOL SearchDown() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o usuário deseja que a pesquisa para continuar em uma direção para baixo; 0 se o usuário deseja que a pesquisa para continuar em uma direção para cima.

## <a name="see-also"></a>Consulte também

[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
